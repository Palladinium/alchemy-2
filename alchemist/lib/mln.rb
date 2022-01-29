# frozen_string_literal: true

require_relative 'logic'
require_relative 'util'
require_relative 'grammars'

module Alchemist
  module MLN
    class MLNRule
      attr_reader :formula, :weight

      def self.weighted(formula, weight)
        MLNRule.new(formula, weight)
      end

      def self.strong(formula)
        MLNRule.new(formula, Float::INFINITY)
      end

      def strong?
        @weight == Float::INFINITY
      end

      def initialize(formula, weight)
        @formula = formula
        @weight = weight
      end

      def emit
        f = formula.to_formula
        if strong?
          "#{f}."
        elsif !weight
          f
        else
          "#{weight} #{f}"
        end
      end

      def eql?(other)
        self.class.eql?(other.class) &&
          weight.eql?(other.weight) &&
          formula.eql?(other.formula)
      end

      def ==(other)
        self.class == other.class &&
          weight == other.weight &&
          formula == other.formula
      end

      def hash
        weight.hash ^
          formula.hash
      end
    end

    class MLNRuleDecl
      attr_reader :formula, :weight

      def self.weighted(formula, weight)
        MLNRuleDecl.new(formula, weight)
      end

      def self.strong(formula)
        MLNRuleDecl.new(formula, Float::INFINITY)
      end

      def strong?
        @weight == Float::INFINITY
      end

      def initialize(formula, weight)
        @formula = formula
        @weight = weight
      end

      def compile(predicates:, **_other_keys)
        MLNRule.new(formula.compile(predicates: predicates), weight)
      end
    end

    class MLNFile
      attr_reader :statements

      def initialize
        @statements = []
      end

      def prepend(statement)
        statements.prepend(statement)
        self
      end

      def compile(**_other_keys)
        MLN.new(statements)
      end
    end

    class MLN
      attr_reader :rules, :types, :predicates, :sol_maps

      extend Util::Parsable
      include Util::ParsableTests

      def initialize(types:, predicates:, rules:, sol_maps: nil)
        @types = types
        @types = @types.each_with_object({}) { |t, h| h[t.name] = t } unless @types.is_a?(Hash)

        @predicates = predicates

        @predicates = @predicates.each_with_object({}) { |p, h| h[p.name] = p } unless @predicates.is_a?(Hash)
        @rules = rules
        @sol_maps = sol_maps
      end

      def sol_mapped?
        !sol_maps.nil?
      end

      def self.compile(statements)
        statements = statements.clone

        types = statements.consume { |s| s.is_a?(Logic::TypeDecl) }
                          .map(&:compile)
                          .each_with_object({}) { |t, h| h[t.name] = t }

        predicates = statements.consume { |s| s.is_a?(Logic::PredicateDecl) }
                               .map { |p| p.compile(types: types) }
                               .each_with_object({}) { |p, h| h[p.name] = p }

        rules = statements.consume { |s| s.is_a?(MLNRuleDecl) }
                          .map { |r| r.compile(predicates: predicates) }

        unless statements.empty?
          raise "#{statements.length} unrecognized statements: #{statements.map(&:to_s).join("\n")}"
        end

        MLN.new(types: types, predicates: predicates, rules: rules)
      end

      def self.parse(input)
        compile(parse_lines(Grammars::MLNStatementParser.new, input, &:value).reject(&:nil?))
      end

      # TODO: What the heck am I doing here?
      def sol2fol
        # Predicates where any argument is another predicate
        sol_type = types[Logic::SOL_TYPE]
        return self if !sol_type || types.key?(Logic::FOL_SOL_TYPE)

        sol_predicates = predicates.values.select { |pred| pred.args.any? { |a| a.type == sol_type } }
        fol_predicates = predicates.values - sol_predicates

        sol_grounding_map = fol_predicates.each_with_object({}) do |pred, h|
          groundings = pred.args.map { |arg| arg.type.values.values }.products

          h[pred] = groundings.each_with_object({}) do |g, hh|
            args_s = g.map { |a| "__#{a.name}" }.join
            hh[g] = Logic::ConstantDecl.new("#{pred.name}#{args_s}")
          end
        end

        new_sol_type = Logic::Type.compile(
          name: Logic::FOL_SOL_TYPE,
          values: sol_grounding_map.values.flat_map(&:values)
        )

        # Expand SOL predicates into versions with both grounded and ungrounded predicates
        sol_predicate_map = sol_predicates.each_with_object({}) do |pred, h|
          pred_groundings = pred.args.map do |arg|
            if arg.type == sol_type
              [nil] + fol_predicates
            else
              [nil]
            end
          end.products

          h[pred] = pred_groundings.each_with_object({}) do |grounding, hh|
            grounding_suffix = pred.args.zip(grounding)
                                   .select { |arg, _| arg.type == sol_type }
                                   .map { |_, g| "__#{g&.name || 'nil'}" }
                                   .join

            name = "#{pred.name}#{grounding_suffix}"

            args = pred.args.zip(grounding).flat_map do |arg, g|
              if arg.type == sol_type
                if g
                  g.args
                else
                  Logic::Arg.new(new_sol_type, arg.blocking?)
                end
              else
                [arg]
              end
            end

            hh[grounding] = Logic::Predicate.new(name, args)
          end
        end

        sol_maps = MLNSOLMaps.new(
          predicate_map: sol_predicate_map,
          grounding_map: sol_grounding_map
        )

        new_types = types.values - [sol_type] + [new_sol_type]
        new_predicates = fol_predicates + sol_predicate_map.values.flat_map(&:values)
        mapped_rules = rules.map do |r|
          MLNRule.new(
            r.formula.transform_atoms { |atom| atom.sol2fol(sol_maps) },
            r.weight
          )
        end

        predicate_mapping_rules = sol_predicate_map.flat_map do |pred, h|
          nil_pred = h[[nil] * pred.args.length]

          h.reject { |_, p| p == nil_pred }
           .flat_map do |pred_grounding, new_pred|
            groundings = pred_grounding.map do |g|
              if g
                g.args.map { |a| a.type.values.values }.products
              else
                [nil]
              end
            end.products

            groundings.flat_map do |grounding|
              MLNRule.strong(
                Logic::IFF.new(
                  Logic::Atom.new(
                    nil_pred,
                    pred_grounding.zip(grounding, pred.args).each_with_index.map do |(p, g, arg), i|
                      if g
                        c = sol_grounding_map.dig(p, g)
                        raise 'Inconsistent lookup tables' unless c

                        c
                      else
                        Logic::Variable.new("var__#{i}", arg.type)
                      end
                    end
                  ),
                  Logic::Atom.new(
                    new_pred,
                    grounding.zip(pred.args).each_with_index.flat_map do |(g, arg), i|
                      g || [Logic::Variable.new("var__#{i}", arg.type)]
                    end
                  )
                )
              )
            end
          end
        end

        new_rules = mapped_rules + predicate_mapping_rules

        MLN.new(
          types: new_types,
          predicates: new_predicates,
          rules: new_rules,
          sol_maps: sol_maps
        )
      end

      class MLNSOLMaps
        attr_reader :predicate_map, :predicate_map_inv, :grounding_map, :grounding_map_inv

        def initialize(predicate_map:, grounding_map:)
          @predicate_map = predicate_map
          @predicate_map_inv = predicate_map.each_with_object({}) do |(pred, groundings), h|
            groundings.each do |grounding, new_pred|
              h[new_pred] = [pred, grounding]
            end
          end

          @grounding_map = grounding_map
          @grounding_map_inv = grounding_map.each_with_object({}) do |(pred, groundings), h|
            groundings.each do |grounding, const|
              h[const] = [pred, grounding]
            end
          end
        end
      end

      def merge(other)
        raise 'Cannot merge sol-mapped MLNs' if sol_maps || other.sol_maps

        MLN.new(
          types: types.merge(other.types),
          predicates: predicates.merge(other.predicates),
          rules: rules + other.rules
        )
      end

      def emit
        [types.values, predicates.values, rules].flatten.map(&:emit).reject(&:nil?).join("\n")
      end

      def eql?(other)
        self.class.eql?(other.class) &&
          types.eql?(other.types) &&
          predicates.eql?(other.predicates) &&
          rules.eql?(other.rules)
      end

      def ==(other)
        self.class == other.class &&
          types == other.types &&
          predicates == other.predicates &&
          rules == other.rules
      end

      def hash
        types.hash ^
          predicates.hash ^
          rules.hash
      end
    end

    class Query
      extend Util::Parsable
      attr_reader :atoms

      def initialize(atoms)
        @atoms = atoms
      end

      def self.parse_opt(opt)
        new(Grammars::QueryParser.new.parse(opt, root: :opt).value)
      end

      def self.parse(input)
        new(parse_lines(Grammars::QueryParser.new, input, root: :element, &:value).reject(&:nil?))
      end

      def compile(mln)
        Query.new(
          atoms.map do |a|
            case a
            when Logic::AtomDecl
              a.compile(predicates: mln.predicates)
            when String
              pred = mln.predicates[a] || raise("Invalid predicate '#{a}'")
              Logic::Atom.new(
                pred,
                pred.args.each_with_index.map { |arg, i| Logic::Variable.new("var__#{i}", arg.type) }
              )
            else
              raise "Invalid query atom '#{a}'"
            end
          end
        )
      end

      def sol2fol(mln)
        Query.new(atoms.flat_map { |a| a.sol2fol_all(mln.sol_maps) })
      end

      def emit
        atoms.map(&:to_formula).join("\n")
      end

      def emit_opt
        atoms.map(&:to_formula).join(',')
      end
    end

    class Result
      extend Util::Parsable
      attr_reader :atoms

      def initialize(atoms)
        @atoms = atoms
      end

      def self.parse(input)
        new(parse_lines(Grammars::ResultParser.new, input, &:value).reject(&:nil?).to_h)
      end

      def compile(mln)
        Result.new(atoms.transform_keys { |a| a.compile(predicates: mln.predicates) })
      end

      def fol2sol(mln)
        Result.new(
          atoms
            .reject { |k, _| mln.sol_maps.predicate_map_inv[k]&.dig(1)&.any?(&:nil?) }
            .transform_keys { |a| a.fol2sol(mln.sol_maps) }
        )
      end

      def emit
        atoms.map do |k, v|
          f = k.to_formula
          v_s = if v
                  " #{v}"
                else
                  ''
                end

          "#{f}#{v_s}"
        end.join("\n")
      end
    end
  end
end

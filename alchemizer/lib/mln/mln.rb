# frozen_string_literal: true

require_relative '../logic'
require_relative '../util'
require_relative '../errors'
require_relative '../grammars'
require_relative 'result'
require_relative 'mln_rule_decl'
require_relative 'mln_rule'
require_relative 'mln_file'
require_relative 'mln_sol_maps'

module Alchemizer
  module MLN
    class MLN
      attr_reader :rules, :types, :predicates, :sol_maps

      extend Parsable
      include ParsableTests

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

      def self.parse(input)
        MLNFile.parse(input).compile
      end

      # TODO: What the heck am I doing here?
      def sol2fol
        # Predicates where any argument is another predicate
        sol_type = types[Logic::SOL_TYPE]
        return self if !sol_type || types.key?(Logic::FOL_SOL_TYPE)

        sol_predicates = predicates.values.select { |pred| pred.args.any? { |a| a.type == sol_type } }
        fol_predicates = predicates.values - sol_predicates

        sol_grounding_map = fol_predicates.each_with_object({}) do |pred, h|
          groundings = pred.args.map { |arg| arg.type.each_value.to_a }.products

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
                g.args.map { |a| a.type.each_value.to_a }.products
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
                        raise AlchemizerError, 'Inconsistent lookup tables' unless c

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

      def infer(evidence:, query:, log_dir: nil)
        infer_path = File.join(ALCHEMY_DIR, 'bin', 'infer')

        raise TypeError, "Expected #{DB.class}, got #{evidence.class}" unless evidence.is_a?(DB)
        raise TypeError, "Expected #{Query.class}, got #{query.class}" unless query.is_a?(Query)
        raise AlchemizerError, 'Mismatching evidence MLN' unless evidence.mln == self
        raise AlchemizerError, 'Mismatching query MLN' unless query.mln == self

        Alchemizer.chdir_tmp(log_dir) do |dir|
          fol_mln = sol2fol
          fol_mln_path = File.join(dir, 'input.mln')
          File.write(fol_mln_path, fol_mln.emit)

          fol_evidence = evidence.sol2fol
          fol_evidence_path = File.join(dir, 'input.db')
          File.write(fol_evidence_path, fol_evidence.emit)

          fol_query = query.sol2fol(fol_mln)
          fol_query_path = File.join(dir, 'query.db')
          File.write(fol_query_path, fol_query.emit)

          fol_result_path = File.join(dir, 'out.result')

          args = [
            infer_path,
            '-i', fol_mln_path,
            '-e', fol_evidence_path,
            '-f', fol_query_path,
            '-r', fol_result_path
          ]

          stdout_path = File.join(dir, 'alchemy.out')
          stderr_path = File.join(dir, 'alchemy.err')

          Open3.popen3(*args) do |stdin, stdout_io, stderr_io, wait_thr|
            stdin.close

            status = wait_thr.value

            stdout_s = stdout_io.read
            stderr_s = stderr_io.read

            File.write(stdout_path, stdout_s)
            File.write(stderr_path, stderr_s)

            raise AlchemyError, "Alchemy command failed with status #{status.exitstatus}" unless status.success?

            raise AlchemyError, 'Alchemy has encountered errors' if /ERROR/.match?(stdout_s)
          end

          fol_result = Result.parse_file(fol_result_path)
          fol_result.compile(fol_mln).fol2sol(fol_mln)
        end
      end

      def merge(other)
        raise AlchemizerError, 'Cannot merge sol-mapped MLNs' if sol_maps || other.sol_maps

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
  end
end

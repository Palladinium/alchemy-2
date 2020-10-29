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

      def compile(predicates:, **other_keys)
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

      def compile(**other_keys)
        MLN.new(statements)
      end
    end

    class MLN
      attr_reader :rules, :types, :predicates, :sol_predicate_map
      extend Util::Parsable
      include Util::ParsableTests

      def initialize(types:, predicates:, rules:, sol_predicate_map: {})
        @types = types
        @types = @types.each_with_object({}) { |t, h| h[t.name] = t } unless @types.is_a?(Hash)

        @predicates = predicates

        @predicates = @predicates.each_with_object({}) { |p, h| h[p.name] = p } unless @predicates.is_a?(Hash)
        @rules = rules
        @sol_predicate_map = sol_predicate_map
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

        raise "#{statements.length} unrecognized statements: #{statements.map(&:to_s).join("\n")}" unless statements.empty?

        MLN.new(types: types, predicates: predicates, rules: rules)
      end

      def self.parse(input)
        statements = []

        parser = Grammars::MLNStatementParser.new
        parser.consume_all_input = false

        loop do
          input.strip!
          break if input.empty?
          match = parser.parse(input)
          raise parser.failure_reason unless match
          value = match.value
          statements << value if value
          input = input[parser.index..]
        end

        MLN.compile(statements)
      end

      def sol2fol
        # Predicates where any argument is another predicate
        sol_type = types[Logic::SOL_TYPE]
        return self if !sol_type || types.key?(Logic::FOL_SOL_TYPE)

        sol_predicates = predicates.values.select { |pred| pred.args.any? { |a| a.type == sol_type } }
        fol_predicates = predicates.values - sol_predicates


        sol_grounding_map = fol_predicates.each_with_object({}) { |pred, h|
          groundings = pred.args.map { |arg| arg.type.values.values }.products

          h[pred] = groundings.each_with_object({}) { |g, hh|
            args_s = g.map { |a| "__#{a.name}" }.join
            hh[g] = Logic::ConstantDecl.new("#{pred.name}#{args_s}")
          }
        }

        new_sol_type = Logic::Type.compile(
          name: Logic::FOL_SOL_TYPE,
          values: sol_grounding_map.values.flat_map(&:values)
        )

        # Expand SOL predicates into versions with both grounded and ungrounded predicates
        sol_predicate_map = sol_predicates.each_with_object({}) { |pred, h|
          pred_groundings = pred.args.map { |arg|
            if arg.type == sol_type
              [nil] + fol_predicates
            else
              [nil]
            end
          }.products

          h[pred] = pred_groundings.each_with_object({}) { |grounding, hh|
            grounding_suffix = pred.args.zip(grounding)
                                 .select { |arg, _| arg.type == sol_type }
                                 .map { |_, g| "__#{g&.name || 'nil'}" }
                                 .join

            name = "#{pred.name}#{grounding_suffix}"

            args = pred.args.zip(grounding).flat_map { |arg, g|
              if arg.type == sol_type
                if g
                  g.args
                else
                  Logic::Arg.new(new_sol_type, arg.blocking?)
                end
              else
                [arg]
              end
            }

            hh[grounding] = Logic::Predicate.new(name, args)
          }
        }

        new_types = types.values - [sol_type] + [new_sol_type]
        new_predicates = fol_predicates + sol_predicate_map.values.flat_map(&:values)
        mapped_rules = rules.map { |r|
          MLNRule.new(
            r.formula.transform_atoms { |atom| atom.sol2fol(sol_predicate_map) },
            r.weight,
          )
        }

        predicate_mapping_rules = sol_predicate_map.flat_map { |pred, h|
          nil_pred = h[[nil] * pred.args.length]

          h
            .reject { |pred_grounding, _| pred_grounding.all?(&:nil?) }
            .flat_map { |pred_grounding, new_pred|

            pred_grounding.map { |g|
              if g
                g.args.map { |a| a.type.values.values }.products
              else
                [nil]
              end
            }.products.flat_map { |grounding|
              MLNRule.strong(
                Logic::IFF.new(
                  Logic::Atom.new(
                    nil_pred,
                    pred_grounding.zip(grounding, pred.args).each_with_index.map { |(p, g, arg), i|
                      if g
                        sol_grounding_map.dig(p, g) || raise('Inconsistent lookup tables')
                      else
                        Logic::Variable.new("var_#{i}", arg.type)
                      end
                    }
                  ),
                  Logic::Atom.new(
                    new_pred,
                    grounding.zip(pred.args).each_with_index.flat_map { |(g, arg), i|
                      g || [Logic::Variable.new("var_#{i}", arg.type)]
                    }
                  ),
                )
              )
            }
          }
        }

        new_rules = mapped_rules + predicate_mapping_rules

        MLN.new(
          types: new_types,
          predicates: new_predicates,
          rules: new_rules,
          sol_predicate_map: sol_predicate_map,
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

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
      attr_reader :rules, :types, :predicates
      extend Util::Parsable
      include Util::ParsableTests

      def initialize(statements)
        statements = statements.clone

        @types = statements.consume { |s| s.is_a?(Logic::TypeDecl) }
                   .map(&:compile)
                   .each_with_object({}) { |t, h| h[t.name] = t }

        @predicates = statements.consume { |s| s.is_a?(Logic::PredicateDecl) }
                        .map { |p| p.compile(types: @types) }
                        .each_with_object({}) { |p, h| h[p.name] = p }

        @rules = statements.consume { |s| s.is_a?(MLNRuleDecl) }
                   .map { |r| r.compile(predicates: @predicates) }

        raise "#{statements.length} unrecognized statements: #{statements.map(&:to_s).join("\n")}" unless statements.empty?
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

        MLN.new(statements)
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

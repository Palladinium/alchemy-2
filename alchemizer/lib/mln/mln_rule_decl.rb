# frozen_string_literal: true

require_relative 'mln_rule'

module Alchemizer
  module MLN
    class MLNRuleDecl
      attr_reader :formula, :weight

      extend Parsable

      def self.weighted(formula, weight)
        new(formula, weight)
      end

      def self.strong(formula)
        new(formula, Float::INFINITY)
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

      def self.parse(input)
        run_parser(Grammars::MLNParser.new, input, root: :mln_rule).value
      end
    end
  end
end

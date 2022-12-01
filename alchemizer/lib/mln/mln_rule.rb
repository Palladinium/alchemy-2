# frozen_string_literal: true

require_relative 'mln_rule_decl'

module Alchemizer
  module MLN
    class MLNRule
      attr_reader :formula, :weight

      extend Parsable

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

      def flatten_quantifiers
        formula.flatten_quantifiers.map { |f| self.class.new(f, weight) }
      end

      def conver_cnf
        clauses = formula.convert_cnf
        clauses.map { |f| self.class.new(f, Float(weight) / Float(clauses.length)) }
      end

      def fold_constants
        MLNRule.new(formula.fold_constants, weight)
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
  end
end

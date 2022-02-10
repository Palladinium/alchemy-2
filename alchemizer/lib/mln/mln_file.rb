# frozen_string_literal: true

require_relative 'mln'
require_relative '../util'

module Alchemizer
  module MLN
    class MLNFile
      attr_reader :statements

      extend Parsable

      def initialize(statements = [])
        @statements = statements
      end

      def prepend(statement)
        statements.prepend(statement)
        self
      end

      def <<(statement)
        @statements << statement
      end

      def self.parse(input)
        new(run_parser(Grammars::MLNParser.new, input).value)
      end

      def merge(other)
        self.class.new(statements + other.statements)
      end

      def compile
        to_parse = statements.clone

        types = to_parse.consume { |s| s.is_a?(Logic::TypeDecl) }
                        .map(&:compile)
                        .each_with_object({}) { |t, h| h[t.name] = t }

        predicates = to_parse.consume { |s| s.is_a?(Logic::PredicateDecl) }
                             .map { |p| p.compile(types: types) }
                             .each_with_object({}) { |p, h| h[p.name] = p }

        rules = to_parse.consume { |s| s.is_a?(MLNRuleDecl) }
                        .map { |r| r.compile(predicates: predicates) }

        unless to_parse.empty?
          raise AlchemizerError, "#{to_parse.length} unrecognized statements: #{to_parse.map(&:to_s).join("\n")}"
        end

        MLN.new(types: types, predicates: predicates, rules: rules)
      end
    end
  end
end

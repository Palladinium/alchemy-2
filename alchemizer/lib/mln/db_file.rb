# frozen_string_literal: true

require_relative '../util'
require_relative '../errors'
require_relative '../grammars'
require_relative 'db'

module Alchemizer
  module MLN
    class DBFile
      attr_reader :statements

      extend Parsable

      def initialize(statements = {})
        @statements = statements
      end

      def self.parse(input)
        statements = run_parser(Grammars::DBParser.new, input).value.each_with_object({}) do |(atom, atom_value), h|
          raise AlchemizerError, "Invalid atom #{atom}" unless atom.is_a?(Logic::AtomDecl)
          raise AlchemizerError, "Invalid atom value #{atom_value}" unless [nil, true, false].include?(atom_value)
          raise AlchemizerError, "Multiple instances of atom '#{atom.to_formula}' in db" if h.key?(atom)

          h[atom] = atom_value
        end

        new(statements)
      end

      def compile(mln)
        compiled_statements = statements.transform_keys { |a| a.compile(predicates: mln.predicates) }

        l1 = statements.length
        l2 = compiled_statements.length

        unless l1 == l2
          raise AlchemizerError, "Statements length changed from #{l1} to #{l2} - there may be a hash collision"
        end

        DB.new(compiled_statements, mln: mln)
      end
    end
  end
end

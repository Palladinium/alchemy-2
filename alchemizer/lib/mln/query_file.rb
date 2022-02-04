# frozen_string_literal: true

require_relative '../errors'
require_relative '../grammars'
require_relative '../logic'
require_relative '../util'
require_relative 'query'

module Alchemizer
  module MLN
    class QueryFile
      extend Parsable
      attr_reader :atoms

      def initialize(atoms = [])
        @atoms = atoms
      end

      def <<(atom)
        @atoms << atom
      end

      def self.parse_opt(opt)
        new(run_parser(Grammars::QueryParser.new, opt, root: :opt).value)
      end

      def self.parse(input)
        new(run_parser(Grammars::QueryParser.new, input, root: :query_file).value)
      end

      def compile(mln)
        compiled_atoms = atoms.map do |a|
          case a
          when Logic::AtomDecl
            a.compile(predicates: mln.predicates)
          when String
            pred = mln.predicates[a] || raise(AlchemizerError, "Invalid predicate '#{a}'")
            Logic::Atom.new(
              pred,
              pred.args.each_with_index.map { |arg, i| Logic::Variable.new("var__#{i}", arg.type) }
            )
          else
            raise AlchemizerError, "Invalid query atom '#{a}'"
          end
        end

        Query.new(compiled_atoms, mln)
      end

      def emit
        atoms.map(&:to_formula).join("\n")
      end

      def emit_opt
        atoms.map(&:to_formula).join(',')
      end
    end
  end
end

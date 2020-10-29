require_relative 'util'
require_relative 'logic'

module Alchemist
  module DB
    class DB
      attr_reader :statements, :mln
      extend Util::Parsable
      include Util::ParsableTests

      def initialize(statements, mln:)
        @mln = mln
        @statements = statements
      end

      def self.compile(statements, mln:)
        compiled_statements = statements.transform_keys { |a| a.compile(predicates: mln.predicates) }

        unless compiled_statements.length == statements.length
          raise "statements length changed from #{statements.length} to #{compiled_statements.length} - there may be a hash collision"
        end

        DB.new(compiled_statements, mln: mln)
      end

      def self.parse(input, mln:)
        statements = {}

        parser = Grammars::DBStatementParser.new
        parser.consume_all_input = false

        loop do
          input.strip!

          break if input.empty?

          match = parser.parse(input)
          raise parser.failure_reason unless match

          value = match.value

          if value
            atom, atom_value = value
            raise "Invalid atom #{atom}" unless atom.is_a?(Logic::AtomDecl)
            raise "Invalid atom value #{atom_value}" unless atom_value.is_a?(TrueClass) || atom_value.is_a?(FalseClass)
            raise "Multiple instances of atom '#{atom.to_formula}' in db" if statements.key?(atom)
            statements[atom] = atom_value
          end

          input = input[parser.index..]
        end

        DB.compile(statements, mln: mln)
      end

      def emit
        statements.map { |atom, atom_value|
          f = atom.to_formula
          if atom_value
            f
          else
            "!#{f}"
          end
        }.join("\n")
      end

      def sol2fol
        return self unless statements.each_key.any? { |s| s.args.any? { |a| a.type == Logic::SOL_TYPE } }

        new_mln = mln.sol2fol
        sol_predicate_map = new_mln.sol_predicate_map
        new_statements = statements.transform_keys { |atom| atom.sol2fol(sol_predicate_map) }

        DB.new(
          new_statements,
          mln: new_mln,
        )
      end

      def eql?(other)
        self.class.eql?(other.class) &&
          statements.eql?(other.statements)
      end

      def ==(other)
        self.class == other.class &&
          statements == other.statements
      end

      def hash
        statements.hash
      end
    end
  end
end

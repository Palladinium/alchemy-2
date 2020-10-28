require_relative 'util'
require_relative 'logic'

module Alchemist
  module DB
    class DB
      attr_reader :statements
      extend Util::Parsable
      include Util::ParsableTests

      def initialize(statements, mln:)
        @statements = statements.transform_keys { |a| a.compile(predicates: mln.predicates) }
        unless @statements.length == statements.length
          raise "statements length changed from #{statements.length} to #{@statements.length} - there may be a hash collision"
        end
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

        DB.new(statements, mln: mln)
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

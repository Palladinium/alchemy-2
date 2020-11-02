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
        self.compile(
          self.parse_lines(
            Grammars::DBStatementParser.new,
            input,
            &:value
          ).reject(&:nil?).each_with_object({}) { |(atom, atom_value), h|
            raise "Invalid atom #{atom}" unless atom.is_a?(Logic::AtomDecl)
            raise "Invalid atom value #{atom_value}" unless atom_value.is_a?(TrueClass) || atom_value.is_a?(FalseClass)
            raise "Multiple instances of atom '#{atom.to_formula}' in db" if h.key?(atom)

            h[atom] = atom_value
          },
          mln: mln
        )
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
        new_statements = statements.transform_keys { |atom| atom.sol2fol(new_mln.sol_maps) }

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

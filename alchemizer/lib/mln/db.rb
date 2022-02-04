# frozen_string_literal: true

require_relative '../util'
require_relative '../errors'
require_relative '../logic'
require_relative 'db_file'

module Alchemizer
  module MLN
    class DB
      attr_reader :statements, :mln

      extend Parsable
      include ParsableTests

      def initialize(statements, mln:)
        @mln = mln
        @statements = statements
      end

      def self.parse(input, mln:)
        DBFile.parse(input).compile(mln)
      end

      def emit
        statements.map do |atom, atom_value|
          f = atom.to_formula

          case atom_value
          when true
            f
          when false
            "!#{f}"
          when nil
            "?#{f}"
          else
            raise AlchemizerError, "Invalid atom value #{atom_value}"
          end
        end.join("\n")
      end

      def sol2fol
        return self unless statements.each_key.any? { |s| s.args.any? { |a| a.type == Logic::SOL_TYPE } }

        new_mln = mln.sol2fol
        new_statements = statements.transform_keys { |atom| atom.sol2fol(new_mln.sol_maps) }

        DB.new(
          new_statements,
          mln: new_mln
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

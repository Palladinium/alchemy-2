# frozen_string_literal: true

require_relative '../errors'
require_relative '../grammars'
require_relative '../logic'
require_relative '../util'
require_relative 'query_file'

module Alchemizer
  module MLN
    class Query
      extend Parsable
      attr_reader :atoms, :mln

      def initialize(atoms, mln)
        @atoms = atoms
        @mln = mln
      end

      def self.parse_opt(opt, mln:)
        QueryFile.parse_opt(opt).compile(mln)
      end

      def self.parse(input, mln:)
        QueryFile.parse(input).compile(mln)
      end

      def sol2fol(mln)
        return self if mln.sol_maps.nil?

        Query.new(atoms.flat_map { |a| a.sol2fol_all(mln.sol_maps) }, mln: mln)
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

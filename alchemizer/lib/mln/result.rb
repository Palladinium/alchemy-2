# frozen_string_literal: true

require_relative '../errors'
require_relative '../grammars'
require_relative '../util'

module Alchemizer
  module MLN
    class Result
      extend Parsable
      attr_reader :atoms

      def initialize(atoms)
        @atoms = atoms
      end

      def self.parse(input)
        new(run_parser(Grammars::ResultParser.new, input).value.to_h)
      end

      def compile(mln)
        Result.new(atoms.transform_keys { |a| a.compile(predicates: mln.predicates) })
      end

      def fol2sol(mln)
        return self if mln.sol_maps.nil?

        Result.new(
          atoms
            .reject { |k, _| mln.sol_maps.predicate_map_inv[k]&.dig(1)&.any?(&:nil?) }
            .transform_keys { |a| a.fol2sol(mln.sol_maps) }
        )
      end

      def emit
        atoms.map do |k, v|
          f = k.to_formula
          v_s = if v
                  " #{v}"
                else
                  ''
                end

          "#{f}#{v_s}"
        end.join("\n")
      end
    end
  end
end

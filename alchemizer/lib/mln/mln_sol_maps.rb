# frozen_string_literal: true

require_relative 'mln'
require_relative '../errors'

module Alchemizer
  module MLN
    class MLNSOLMaps
      attr_reader :predicate_map, :predicate_map_inv, :grounding_map, :grounding_map_inv

      def initialize(predicate_map:, grounding_map:)
        @predicate_map = predicate_map
        @predicate_map_inv = predicate_map.each_with_object({}) do |(pred, groundings), h|
          groundings.each do |grounding, new_pred|
            h[new_pred] = [pred, grounding]
          end
        end

        @grounding_map = grounding_map
        @grounding_map_inv = grounding_map.each_with_object({}) do |(pred, groundings), h|
          groundings.each do |grounding, const|
            h[const] = [pred, grounding]
          end
        end
      end
    end

    def merge(other)
      raise AlchemizerError, 'Cannot merge sol-mapped MLNs' if sol_maps || other.sol_maps

      MLN.new(
        types: types.merge(other.types),
        predicates: predicates.merge(other.predicates),
        rules: rules + other.rules
      )
    end

    def emit
      [types.values, predicates.values, rules].flatten.map(&:emit).reject(&:nil?).join("\n")
    end

    def eql?(other)
      self.class.eql?(other.class) &&
        types.eql?(other.types) &&
        predicates.eql?(other.predicates) &&
        rules.eql?(other.rules)
    end

    def ==(other)
      self.class == other.class &&
        types == other.types &&
        predicates == other.predicates &&
        rules == other.rules
    end

    def hash
      types.hash ^
        predicates.hash ^
        rules.hash
    end
  end
end

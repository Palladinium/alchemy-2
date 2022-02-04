# frozen_string_literal: true

require_relative 'util'
require_relative 'grammars'

module Alchemizer
  module MLN
    extend Parsable

    def self.parse_statement(input)
      run_parser(Grammars::MLNParser.new, input, root: :statement).value
    end
  end
end

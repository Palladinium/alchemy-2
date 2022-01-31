# frozen_string_literal: true

require 'polyglot'
require 'treetop'

require_relative 'constants'
require_relative 'logic'
require_relative 'mln'

module Alchemizer
  module Grammars
    GRAMMARS_DIR = File.join(ALCHEMIZER_DIR, 'lib', 'grammars', 'treetop')

    Treetop.load(File.join(GRAMMARS_DIR, 'common.tt'))
    Treetop.load(File.join(GRAMMARS_DIR, 'logic.tt'))
    Treetop.load(File.join(GRAMMARS_DIR, 'mln.tt'))
    Treetop.load(File.join(GRAMMARS_DIR, 'db.tt'))
    Treetop.load(File.join(GRAMMARS_DIR, 'query.tt'))
    Treetop.load(File.join(GRAMMARS_DIR, 'result.tt'))
  end
end

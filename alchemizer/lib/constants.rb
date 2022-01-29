# frozen_string_literal: true

module Alchemizer
  ALCHEMIZER_DIR = File.expand_path('..', File.dirname(__FILE__)).freeze
  ALCHEMY_DIR = File.expand_path('..', ALCHEMIZER_DIR).freeze
  TUTORIAL_DIR = File.join(ALCHEMY_DIR, 'tutorial').freeze

  TEST_MLNS_RELATIVE = {
    'basics/binomial.mln' => [],
    'basics/multinomial.mln' => ['dice/biased-die.db'],
    'bayes-net/alarm-conj.mln' => [],
    'bayes-net/alarm.mln' => [],
    'sol/sol.mln' => ['sol/sol.db']
  }.freeze

  TEST_MLNS = TEST_MLNS_RELATIVE.each_with_object({}) do |(path, dbs), h|
    h[File.join(TUTORIAL_DIR, 'tutorial-mlns', path)] = dbs.map do |db_path|
      File.join(TUTORIAL_DIR, 'tutorial-data', db_path)
    end
  end.freeze
end

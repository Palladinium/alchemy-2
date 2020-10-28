require 'citrus'

module Alchemist
  ALCHEMIST_DIR = File.expand_path('..', File.dirname(__FILE__)).freeze
  ALCHEMY_DIR = File.expand_path('..', ALCHEMIST_DIR).freeze
  TUTORIAL_DIR = File.join(ALCHEMY_DIR, 'tutorial').freeze

  TEST_MLNS = {
    'basics/binomial.mln' => [],
    'basics/multinomial.mln' => ['dice/biased-die.db'],
    'bayes-net/alarm-conj.mln' => [],
    'bayes-net/alarm.mln' => [],
    'sol/sol.mln' => ['sol/sol.db'],
  }.transform_keys { |path|
    File.join(TUTORIAL_DIR, 'tutorial-mlns', path)
  }.transform_values { |dbs|
    dbs.map { |path| File.join(TUTORIAL_DIR, 'tutorial-data', path) }
  }.freeze
end

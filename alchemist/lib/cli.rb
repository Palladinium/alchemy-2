require 'thor'

require_relative 'alchemist'
require_relative 'mln'
require_relative 'db'

module Alchemist
  class CLI < Thor
    desc 'test', 'Test the grammars'
    def test
      puts "Testing #{TEST_MLNS.length} files"

      TEST_MLNS.each do |mln_path, db_paths|
        puts mln_path
        mln = MLN::MLN.parse_file(mln_path)
        mln.test_equivalence

        db_paths.each do |db_path|
          puts "  #{db_path}"
          db = DB::DB.parse_file(db_path, mln: mln)
          db.test_equivalence(mln: mln)
        end
      end
    end
  end
end

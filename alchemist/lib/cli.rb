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
        start_line(mln_path)
        mln = MLN::MLN.parse_file(mln_path)
        mln.test_equivalence
        tick

        mln_fol = mln.sol2fol
        mln_fol.test_equivalence
        tick
        end_line

        db_paths.each do |db_path|
          start_line(db_path, 1)
          db = DB::DB.parse_file(db_path, mln: mln)
          db.test_equivalence(mln: mln)
          tick

          db_fol = db.sol2fol
          db_fol.test_equivalence(mln: db_fol.mln)
          tick

          end_line
        end
      end
    end

    desc 'sol2fol', 'Flatten (possibly) SOL MLN and DBs to FOL'
    option :mln, type: :string, required: true
    option :db, type: :string
    option :mln_out, type: :string, required: true
    option :db_out, type: :string
    def sol2fol
      mln = MLN::MLN.parse_file(options[:mln])
      mln_fol = mln.sol2fol
      File.write(options[:mln_out], mln_fol.emit)

      if options[:db]
        db = DB::DB.parse_file(options[:db], mln: mln)
        db_fol = db.sol2fol
        File.write(options[:db_out], db_fol.emit)
      end
    end

    no_commands do
      def start_line(text, indent=0)
        putflush("#{' ' * 2 * indent}#{text}")
      end

      def tick
        putflush(" \u2713")
      end

      def end_line
        puts
      end

      def putflush(text)
        $stdout.write(text)
        $stdout.flush
      end
    end
  end
end

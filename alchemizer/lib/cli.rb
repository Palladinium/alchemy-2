# frozen_string_literal: true

require 'thor'
require 'shellwords'

require_relative 'constants'
require_relative 'mln'
require_relative 'mln/mln'
require_relative 'mln/db'
require_relative 'util'
require_relative 'commands'

module Alchemizer
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
          db = MLN::DB.parse_file(db_path, mln: mln)
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

      return unless options[:db]

      db = DB::DB.parse_file(options[:db], mln: mln)
      db_fol = db.sol2fol
      File.write(options[:db_out], db_fol.emit)
    end

    desc 'infer', "Call alchemy's infer tool"
    option :opts, type: :string, desc: 'Options to pass verbatim to Alchemy. Prefix with a space to avoid Thor errors'
    option :inputs, aliases: %i[i], type: :string, required: true, desc: 'Comma-separated input .mln files.'
    option :evidence,
           aliases: %i[e],
           type: :string,
           required: true,
           desc: 'Comma-separated .db files containing known ground atoms (evidence), including function definitions'
    option :result,
           aliases: %i[r],
           type: :string, required: true, desc: 'The probability estimates are written to this file.'
    option :query,
           aliases: %i[q],
           type: :string,
           desc: <<-DESC
             Query atoms (comma-separated with no space)  ,e.g., cancer,smokes(x),friends(Stan,x).
             Query atoms are always open world.
           DESC
    option :query_file,
           aliases: %i[f],
           type: :string,
           desc: 'A .db file containing ground query atoms, which are are always open world.'
    def infer
      Alchemise.infer(
        inputs: options[:inputs].split(',').map { |path| File.expand_path(path, Dir.pwd) },
        evidence: options[:evidence].split(',').map { |path| File.expand_path(path, Dir.pwd) },
        result: File.expand_path(options[:result], Dir.pwd),
        query: options[:query],
        query_file: options[:query_file],
        opts: options[:opts]&.shellsplit
      )
    end

    no_commands do
      def start_line(text, indent = 0)
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

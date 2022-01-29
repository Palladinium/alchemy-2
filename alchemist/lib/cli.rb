# frozen_string_literal: true

require 'thor'
require 'shellwords'

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

      return unless options[:db]

      db = DB::DB.parse_file(options[:db], mln: mln)
      db_fol = db.sol2fol
      File.write(options[:db_out], db_fol.emit)
    end

    desc 'infer', "Call alchemy's infer tool"
    option :opts, type: :string, desc: 'Options to pass verbatim to Alchemy. Prefix with a space to avoid Thor errors'
    option :i, type: :string, required: true, desc: 'Comma-separated input .mln files.'
    option :e,
           type: :string,
           required: true,
           desc: 'Comma-separated .db files containing known ground atoms (evidence), including function definitions'
    option :r, type: :string, required: true, desc: 'The probability estimates are written to this file.'
    option :q,
           type: :string,
           desc: <<-DESC
             Query atoms (comma-separated with no space)  ,e.g., cancer,smokes(x),friends(Stan,x).
             Query atoms are always open world.
           DESC
    option :f, type: :string, desc: 'A .db file containing ground query atoms, which are are always open world.'
    def infer
      infer_path = File.join(ALCHEMY_DIR, 'bin', 'infer')

      opts = options[:opts]&.shellsplit || []

      sol_mln_paths = options[:i].split(',').map { |path| File.expand_path(path, Dir.pwd) }
      sol_db_paths = options[:e].split(',').map { |path| File.expand_path(path, Dir.pwd) }
      sol_result_path = File.expand_path(options[:r], Dir.pwd)

      sol_query_opt = options[:q] && MLN::Query.parse_opt(options[:q])
      sol_query_file = options[:f] && MLN::Query.parse_file(options[:f])

      chdir_tmp do |tmpdir|
        puts "Using tmpdir #{tmpdir}"

        fol_mln_paths = sol_mln_paths.each_with_index.map do |path, i|
          sol_mln = MLN::MLN.parse_file(path)
          fol_mln = sol_mln.sol2fol
          filename = File.join(tmpdir, "input_#{i}.mln")
          File.write(filename, fol_mln.emit)
          filename
        end

        merged_sol_mln = sol_mln_paths
                         .map { |path| MLN::MLN.parse_file(path) }
                         .reduce(&:merge)
        merged_fol_mln = merged_sol_mln.sol2fol

        fol_db_paths = sol_db_paths.each_with_index.map do |path, i|
          sol_db = DB::DB.parse_file(path, mln: merged_sol_mln)
          fol_db = sol_db.sol2fol
          filename = File.join(tmpdir, "input_#{i}.db")
          File.write(filename, fol_db.emit)
          filename
        end

        fol_result_path = File.join(tmpdir, 'out.result')

        args = [
          infer_path,
          '-i', fol_mln_paths.join(','),
          '-e', fol_db_paths.join(','),
          '-r', fol_result_path
        ]

        if sol_query_opt
          fol_query_opt = sol_query_opt
                          .compile(merged_sol_mln)
                          .sol2fol(merged_fol_mln)
                          .emit_opt

          args += ['-q', fol_query_opt]
        end

        if sol_query_file
          fol_query_file_path = File.join(tmpdir, 'query.txt')

          fol_query_file_contents = sol_query_file
                                    .compile(merged_sol_mln)
                                    .sol2fol(merged_fol_mln)
                                    .emit

          File.write(fol_query_file_path, fol_query_file_contents)
          args += ['-f', fol_query_file_path]
        end

        args += opts

        puts "Running command #{args}"

        pid = spawn(*args)
        _pid, status = Process.wait2(pid)

        raise "Alchemy command failed with status #{status.exitstatus}" unless status.success?

        fol_result = MLN::Result.parse_file(fol_result_path)
        sol_result = fol_result.compile(merged_fol_mln).fol2sol(merged_fol_mln)

        File.write(sol_result_path, sol_result.emit)
      end
    end

    no_commands do
      def chdir_tmp
        tmpdir = Dir.mktmpdir('alchemist')
        Dir.chdir(tmpdir) do
          yield tmpdir
        end
      end

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

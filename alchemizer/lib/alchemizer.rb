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

  def self.infer(inputs:, evidence:, result:, query: nil, query_file: nil, opts: [])
    infer_path = File.join(ALCHEMY_DIR, 'bin', 'infer')

    sol_mln_paths = inputs
    sol_db_paths = evidence
    sol_result_path = result

    sol_query_opt = query
    sol_query_file = query_file

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
end

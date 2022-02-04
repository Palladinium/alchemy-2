# frozen_string_literal: true

require_relative 'errors'

class Array
  def consume(&block)
    consumed = select(&block)
    reject!(&block)
    consumed
  end

  def products
    if empty?
      [[]]
    else
      self[0].product(*self[1..])
    end
  end
end

module Enumerable
  def each_var_slice(sizes)
    it = self

    if block_given?
      sizes.each do |n|
        slice = it.take(n)
        it = it.drop(n)
        yield slice
      end
    else
      sizes.map do |n|
        slice = it.take(n)
        it = it.drop(n)
        slice
      end
    end
  end
end

module Alchemizer
  module Parsable
    def parse_file(filename, *args, **kwargs)
      parse(File.read(filename), *args, **kwargs)
    end

    def run_parser(parser, input, **opts)
      match = parser.parse(input, consume_all_input: true, **opts)
      raise AlchemizerError, parser.failure_reason unless match

      match
    end

    def parse_lines(parser, input, **opts)
      output = []

      loop do
        input.strip!
        break if input.empty?

        match = parser.parse(input, consume_all_input: false, **opts)
        raise AlchemizerError, parser.failure_reason unless match

        out = yield match
        output << out

        input = input[parser.index..]
      end

      output
    end
  end

  module ParsableTests
    def test_equivalence(*args, **kwargs)
      out = emit
      obj2 = self.class.parse(out, *args, **kwargs)
      out2 = obj2.emit

      raise AlchemizerError, 'Parsing value equivalence error' unless self == obj2
      raise AlchemizerError, 'Parsing output equivalence error' unless out == out2
    end
  end

  def self.chdir_tmp(dir = nil)
    FileUtils.mkdir_p(dir) if dir

    tmpdir = dir || Dir.mktmpdir('alchemizer')

    ret = Dir.chdir(tmpdir) do
      yield tmpdir
    end

    FileUtils.remove_entry(tmpdir) unless dir

    ret
  rescue StandardError
    puts "Preserving temporary directory due to error: #{tmpdir}" unless dir
    raise
  end
end

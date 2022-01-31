# frozen_string_literal: true

require 'pry'

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
      out2 = obj_2.emit

      raise AlchemizerError, 'Parsing equivalence error' unless self == obj2 && out == out2
    end
  end

  def self.chdir_tmp
    tmpdir = Dir.mktmpdir('alchemizer')

    Dir.chdir(tmpdir) do
      yield tmpdir
    end

    FileUtils.remove_entry(tmpdir)
  rescue StandardError
    puts "Preserving temporary directory due to error: #{tmpdir}"
    raise
  end

  def self.start_line(text, indent = 0)
    putflush("#{' ' * 2 * indent}#{text}")
  end

  def self.tick
    putflush(" \u2713")
  end

  def self.end_line
    puts
  end

  def self.putflush(text)
    $stdout.write(text)
    $stdout.flush
  end
end

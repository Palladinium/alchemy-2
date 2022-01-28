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
  def each_var_slice(ns)
    it = self

    if block_given?
      ns.each do |n|
        slice = it.take(n)
        it = it.drop(n)
        yield slice
      end
    else
      ns.map { |n|
        slice = it.take(n)
        it = it.drop(n)
        slice
      }
    end
  end
end

module Alchemist
  module Util
    module Parsable
      def parse_file(filename, *args, **kwargs)
        self.parse(File.read(filename), *args, **kwargs)
      end

      def parse_lines(parser, input, **opts)
        output = []

        loop do
          input.strip!
          break if input.empty?
          match = parser.parse(input, consume_all_input: false, **opts)
          raise parser.failure_reason unless match

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
        obj_2 = self.class.parse(out, *args, **kwargs)
        out_2 = obj_2.emit

        unless self == obj_2
          raise 'Parsing equivalence error'
          binding.pry
        end

        unless out == out_2
          raise 'Parsing equivalence error'
          binding.pry
        end
      end
    end
  end
end

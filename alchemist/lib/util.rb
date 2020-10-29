require 'pry'

class Array
  def consume(&block)
    consumed = select(&block)
    reject!(&block)
    consumed
  end

  def products
    self[0].product(*self[1..])
  end
end

module Alchemist
  module Util
    module Parsable
      def parse_file(filename, *args, **kwargs)
        self.parse(File.read(filename), *args, **kwargs)
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

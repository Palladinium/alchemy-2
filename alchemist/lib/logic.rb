module Alchemist
  module Logic
    SOL_TYPE = "$"

    module Formula
      def atoms
        each_atom.to_a
      end

      def hash
        to_formula.hash
      end

      def ==(other)
        to_formula == other.to_formula
      end

      def eql?(other)
        to_formula.eql?(other.to_formula)
      end
    end

    module Priority
      def wrap_priority(s, outer_priority)
        if outer_priority && priority < outer_priority
          "(#{s})"
        else
          s
        end
      end
    end

    class UnaryOperator
      include Priority, Formula
      attr_reader :arg

      def initialize(arg)
        @arg = arg
      end

      def args
        [arg]
      end

      def to_formula(outer_priority: nil)
        arg_s = arg.to_formula(outer_priority: priority)
        wrap_priority("#{op}#{arg_s}", outer_priority)
      end

      def each_atom(&block)
        arg.each_atom(&block)
      end

      def compile(predicates:, **other_keys)
        self.class.new(arg.compile(predicates: predicates))
      end
    end

    module InfixOperator
      include Priority, Formula

      def to_formula(outer_priority: nil)
        args_s = args.map { |arg| arg.to_formula(outer_priority: priority) }.join(" #{op} ")
        wrap_priority(args_s, outer_priority)
      end
    end

    class NAryOperator
      include InfixOperator
      attr_reader :args

      def initialize(*args)
        @args = args.flat_map { |arg|
          if arg.is_a?(self.class)
            arg.args
          else
            [arg]
          end
        }
      end

      def each_atom(&block)
        if block
          args.each do |arg|
            arg.each_atom(&block)
          end
        else
          args.flat_map { |arg| arg.each_atom }
        end
      end

      def compile(predicates:, **other_keys)
        self.class.new(*args.map { |arg| arg.compile(predicates: predicates) })
      end
    end

    class BinaryOperator
      include InfixOperator
      attr_reader :lhs, :rhs

      def initialize(lhs, rhs)
        @lhs = lhs
        @rhs = rhs
      end

      def args
        [lhs, rhs]
      end

      def each_atom(&block)
        if block
          lhs.each_atom(&block)
          rhs.each_atom(&block)
        else
          args.flat_map { |arg| arg.each_atom }
        end
      end

      def compile(predicates:, **other_keys)
        self.class.new(*args.map { |arg| arg.compile(predicates: predicates) })
      end
    end

    class QualifiedOperator
      include Priority, Formula
      attr_reader :vars, :arg

      def initialize(vars, arg)
        if vars.empty?
          raise ArgumentError, "Invalid qualified operator #{op} with 0 vars"
        end

        while arg.class == self.class
          vars += arg.vars
          arg = arg.arg
        end

        @vars = vars
        @arg = arg
      end

      def to_formula(outer_priority: nil)
        vars_s = vars.map(&:to_formula).join(',')
        arg_s = arg.to_formula(outer_priority: priority)
        s = "#{op}(#{vars_s}) #{arg_s}"
        wrap_priority(s, outer_priority)
      end
    end

    class Not < UnaryOperator
      def op
        '!'
      end

      def priority
        6
      end
    end

    class And < NAryOperator
      def op
        '^'
      end

      def priority
        5
      end
    end

    class Or < NAryOperator
      def op
        'v'
      end

      def priority
        4
      end
    end

    class Implies < BinaryOperator
      def op
        '=>'
      end

      def priority
        3
      end
    end

    class IFF < BinaryOperator
      def op
        '<=>'
      end

      def priority
        2
      end
    end

    class Exists < QualifiedOperator
      def op
        'exists'
      end

      def priority
        1
      end
    end

    class Forall < QualifiedOperator
      def op
        'forall'
      end

      def priority
        1
      end
    end

    class TypeDecl
      attr_reader :name, :values

      def initialize(name, values)
        @name = name
        @values = values
      end

      def compile
        Type.compile(name: name, values: values)
      end
    end

    class Type
      attr_reader :name, :values

      def locked?
        @locked
      end

      # Rename new to compile to make it clear it's not a trivial constructor
      def self.compile(name:, values:, **other_keys)
        Type.new(name,
                 values.each_with_object({}) { |v, h| h[v.name] = Constant.new(v.name, self) },
                 locked: true)
      end

      def resolve(value_name)
        raise "Undefined constant '#{value_name}' for declared type '#{name}'" if !values[value_name] && locked?
        values[value_name] ||= Constant.new(value_name, self)
      end

      def emit
        if locked?
          values_s = values.values.map(&:to_formula).join(',')
          "#{name} = { #{values_s} }"
        else
          nil
        end
      end

      def eql?(other)
        self.class.eql?(other.class) &&
          name.eql?(other.name) &&
          values.eql?(other.values)
      end

      def ==(other)
        self.class == other.class &&
          name == other.name &&
          values == other.values
      end

      def hash
        name.hash ^
          values.hash
      end

      private

      def initialize(name, values, locked:)
        @name = name
        @values = values
        @locked = locked
      end
    end

    class PredicateDecl
      attr_reader :name, :args

      def initialize(name, args)
        @name = name
        @args = args
      end

      def compile(types:, **other_keys)
        Predicate.new(name, args.map { |arg| arg.compile(types: types) })
      end
    end

    class Predicate
      include Formula
      attr_reader :name, :args

      def initialize(name, args)
        @name = name
        @args = args
      end

      def to_formula(**other_keys)
        name
      end

      def emit
        args_s = if args.empty?
                   ''
                 else
                   in_args_s = args.map(&:emit).join(',')
                   "(#{in_args_s})"
                 end

        "#{name}#{args_s}"
      end
    end

    class ArgDecl
      attr_reader :type

      def blocking?
        @blocking
      end

      def initialize(type, blocking)
        @type = type
        @blocking = blocking
      end

      def compile(types:, **other_keys)
        Arg.new(
          types[type] ||= Type.new(type, {}, locked: false),
          blocking?,
        )
      end
    end

    class Arg
      attr_reader :type

      def blocking
        @blocking
      end

      def initialize(type, blocking)
        @type = type
        @blocking = blocking
      end

      def emit
        t = type.name
        if blocking
          "#{t}!"
        else
          t
        end
      end

      def eql?(other)
        self.class.eql?(other.class) &&
          type.eql?(other.type)
      end

      def ==(other)
        self.class == other.class &&
          type == other.type
      end

      def hash
        type.hash
      end
    end

    class AtomDecl
      include Formula
      attr_reader :predicate, :args

      def initialize(predicate, args)
        @predicate = predicate
        @args = args
      end

      def compile(predicates:, **other_keys)
        new_predicate = predicates[predicate] || raise("Undefined predicate #{predicate}")
        Atom.new(
          new_predicate,
          args.zip(new_predicate.args).map { |arg, arg_decl| arg.compile(predicates: predicates, type: arg_decl.type) }
        )
      end

      def to_formula(**other_keys)
        args_s = if args.empty?
                   ''
                 else
                   in_args_s = args.map { |a| a.to_formula(**other_keys) }.join(',')
                   "(#{in_args_s})"
                 end

        "#{predicate}#{args_s}"
      end

      def each_atom(&block)
        if block
          yield self
        else
          [self]
        end
      end

    end

    class Atom
      include Formula
      attr_reader :predicate, :args

      def initialize(predicate, args)
        @predicate = predicate
        @args = args
      end

      def type
        SOL_TYPE
      end

      def to_formula(**other_keys)
        predicate_s = predicate.to_formula(**other_keys)

        args_s = if args.empty?
                   ''
                 else
                   in_args_s = args.map { |a|
                     f = a.to_formula(**other_keys)
                     if a.is_a?(Atom)
                       "$#{f}"
                     else
                       f
                     end
                   }.join(',')
                   "(#{in_args_s})"
                 end

        "#{predicate_s}#{args_s}"
      end

      def each_atom(&block)
        if block
          yield self
        else
          [self]
        end
      end
    end

    class VariableDecl
      include Formula
      attr_reader :name

      def initialize(name)
        raise "Invalid constant name: #{name}" unless name[0] =~ /[a-z]/
        @name = name
      end

      def compile(type:, **other_keys)
        Variable.new(name, type)
      end

      def to_formula(**other_keys)
        name
      end
    end

    class Variable
      include Formula
      attr_reader :name, :type

      def initialize(name, type)
        @name = name
        @type = type
      end

      def to_formula(**other_keys)
        name
      end
    end

    class ConstantDecl
      include Formula
      attr_reader :name

      def initialize(name)
        unless name.is_a?(Integer) || (name.is_a?(String) && !name.empty? && name[0] =~ /[A-Z0-1]/)
          raise "Invalid constant name: '#{name}'"
        end

        @name = name
      end

      def compile(type:, **other_keys)
        type.resolve(name)
      end

      def to_formula(**other_keys)
        name
      end
    end

    class Constant
      include Formula
      attr_reader :name, :type

      def initialize(name, type)
        @name = name
        @type = type
      end

      def to_formula(**other_keys)
        name
      end
    end
  end
end

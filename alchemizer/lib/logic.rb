# frozen_string_literal: true

module Alchemizer
  module Logic
    SOL_TYPE = '$'
    FOL_SOL_TYPE = 'sol__'

    module Formula
      def atoms
        each_atom.to_a
      end

      def hash
        to_formula.hash
      end

      def ==(other)
        other.respond_to?(:to_formula) &&
          to_formula == other.to_formula
      end

      def eql?(other)
        other.respond_to?(:to_formula) &&
          to_formula.eql?(other.to_formula)
      end
    end

    module Priority
      def wrap_priority(str, outer_priority)
        if outer_priority && priority < outer_priority
          "(#{str})"
        else
          str
        end
      end
    end

    class UnaryOperator
      include Formula
      include Priority
      attr_reader :arg

      def initialize(arg)
        @arg = arg.freeze
        freeze
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

      def transform_atoms(&block)
        self.class.new(arg.transform_atoms(&block))
      end

      def compile(predicates:, **_other_keys)
        self.class.new(arg.compile(predicates: predicates))
      end
    end

    module InfixOperator
      include Formula
      include Priority

      def to_formula(outer_priority: nil)
        args_s = args.map { |arg| arg.to_formula(outer_priority: priority) }.join(" #{op} ")
        wrap_priority(args_s, outer_priority)
      end
    end

    class NAryOperator
      include InfixOperator
      attr_reader :args

      def initialize(*args)
        @args = args.flat_map do |arg|
          if arg.is_a?(self.class)
            arg.args
          else
            [arg]
          end
        end.freeze
        freeze
      end

      def each_atom(&block)
        if block
          args.each do |arg|
            arg.each_atom(&block)
          end
        else
          args.flat_map(&:each_atom)
        end
      end

      def transform_atoms(&block)
        self.class.new(*args.map { |arg| arg.transform_atoms(&block) })
      end

      def compile(predicates:, **other_keys)
        self.class.new(*args.map { |arg| arg.compile(predicates: predicates, **other_keys) })
      end
    end

    class BinaryOperator
      include InfixOperator
      attr_reader :lhs, :rhs

      def initialize(lhs, rhs)
        @lhs = lhs.freeze
        @rhs = rhs.freeze
        freeze
      end

      def args
        [lhs, rhs]
      end

      def each_atom(&block)
        if block
          lhs.each_atom(&block)
          rhs.each_atom(&block)
        else
          args.flat_map(&:each_atom)
        end
      end

      def transform_atoms(&block)
        self.class.new(*args.map { |arg| arg.transform_atoms(&block) })
      end

      def compile(predicates:, **other_keys)
        self.class.new(*args.map { |arg| arg.compile(predicates: predicates, **other_keys) })
      end
    end

    class QualifiedOperator
      include Formula
      include Priority
      attr_reader :vars, :arg

      def initialize(vars, arg)
        raise ArgumentError, "Invalid qualified operator #{op} with 0 vars" if vars.empty?

        while arg.instance_of?(self.class)
          vars += arg.vars
          arg = arg.arg
        end

        @vars = vars.freeze
        @arg = arg.freeze
        freeze
      end

      def transform_atoms(&block)
        self.class.new(vars, arg.transform_atoms(&block))
      end

      def each_atom(&block)
        arg.each_atom(&block)
      end

      def to_formula(outer_priority: nil)
        vars_s = vars.map(&:to_formula).join(',')
        arg_s = arg.to_formula(outer_priority: priority)
        s = "#{op} #{vars_s} #{arg_s}"
        wrap_priority(s, outer_priority)
      end

      def compile(predicates:, **_other_keys)
        compiled_arg = arg.compile(predicates: predicates)

        compiled_vars = vars.map do |var|
          matching_args = compiled_arg.each_atom.flat_map(&:args).select do |arg|
            case arg
            when Variable
              arg.name == var.name
            else
              false
            end
          end

          types = matching_args.map(&:type).uniq
          type = case types.length
                 when 0
                   raise AlchemizerError, "No matching use found for #{var.name} in #{to_formula}"
                 when 1
                   types[0]
                 else
                   raise AlchemizerError, "Multiple matching uses with different types found for #{var}: #{types}"
                 end

          var.compile(type: type)
        end

        self.class.new(compiled_vars, compiled_arg)
      end
    end

    class Plus < NAryOperator
      def op
        '+'
      end

      def priority
        7
      end
    end

    class Minus < NAryOperator
      def op
        '-'
      end

      def priority
        7
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

    class ForAll < QualifiedOperator
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
        @name = name.freeze
        @values = values.freeze
        freeze
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
      def self.compile(name:, values:, **_other_keys)
        Type.new(name,
                 values,
                 locked: true)
      end

      def resolve(value_name)
        case values
        when Hash
          if !values[value_name] && locked?
            raise AlchemizerError, "Undefined constant '#{value_name}' for declared type '#{name}'"
          end

          values[value_name] ||= Constant.new(value_name, self)
        when Range
          unless values.include?(value_name.to_i)
            raise AlchemizerError, "Constant #{value_name} is out of range for declared type '#{name}' #{values}"
          end

          Constant.new(value_name.to_i, self)
        else
          raise AlchemizerError, "Invalid type values: #{values}"
        end
      end

      def emit
        return unless locked?

        case values
        when Hash
          values_s = values.values.map(&:to_formula).join(', ')
          "#{name} = { #{values_s} }"
        when Range
          "#{name} = { #{values.begin}, ..., #{values.end} }"
        else
          raise AlchemizerError, "Invalid type values: #{values}"
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

      def each_value
        case values
        when Hash
          values.values
        when Range
          values.map { |v| Constant.new(v, self) }
        else
          raise AlchemizerError, "Invalid type values: #{values}"
        end
      end

      private

      def initialize(name, values, locked:)
        @name = name.freeze
        @values = case values
                  when Array
                    values.each_with_object({}) { |v, h| h[v.name] = Constant.new(v.name, self) }
                  when Range
                    values
                  else
                    raise AlchemizerError, "Invalid type values: #{values}"
                  end
        @locked = locked

        return unless locked

        values.freeze
        freeze
      end
    end

    class PredicateDecl
      attr_reader :name, :args

      def initialize(name, args)
        @name = name.freeze
        @args = args.freeze
        freeze
      end

      def compile(types:, **_other_keys)
        Predicate.new(name, args.map { |arg| arg.compile(types: types) })
      end
    end

    class Predicate
      include Formula
      attr_reader :name, :args

      def initialize(name, args)
        @name = name.freeze
        @args = args.freeze
        freeze
      end

      def to_formula(**_other_keys)
        name
      end

      def emit
        args_s = args.map(&:emit).join(',')
        "#{name}(#{args_s})"
      end
    end

    class ArgDecl
      attr_reader :type

      def blocking?
        @blocking
      end

      def initialize(type, blocking)
        @type = type.freeze
        @blocking = blocking.freeze
        freeze
      end

      def compile(types:, **_other_keys)
        compiled_type = if type == SOL_TYPE
                          types[type] ||= Type.new(type, [], locked: false)
                        else
                          types[type] || raise(AlchemizerError, "Unknown type #{type}")
                          #types[type] ||= Type.new(type, [], locked: false),
                        end
        Arg.new(compiled_type, blocking?)
      end
    end

    class Arg
      attr_reader :type

      def blocking?
        @blocking
      end

      def initialize(type, blocking)
        @type = type.freeze
        @blocking = blocking.freeze
        freeze
      end

      def emit
        t = type.name
        if blocking?
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
        @predicate = predicate.freeze
        @args = args.freeze
        freeze
      end

      def compile(predicates:, **_other_keys)
        new_predicate = predicates[predicate] || raise(AlchemizerError, "Undefined predicate #{predicate}")

        expected = new_predicate.args.length
        actual = args.length

        unless actual == expected
          raise AlchemizerError,
                "Mismatching number of arguments for predicate #{predicate}: expected #{expected}, got #{actual}"
        end

        Atom.new(
          new_predicate,
          args.zip(new_predicate.args).map { |arg, arg_decl| arg.compile(predicates: predicates, type: arg_decl.type) }
        )
      end

      def to_formula(**other_keys)
        args_s = args.map { |a| a.to_formula(**other_keys) }.join(', ')
        "#{predicate}(#{args_s})"
      end

      def each_atom(&block)
        if block
          yield self
        else
          [self]
        end
      end

      def transform_atoms
        yield self
      end
    end

    class Atom
      include Formula
      attr_reader :predicate, :args

      def initialize(predicate, args)
        @predicate = predicate.freeze
        @args = args.freeze
        freeze
      end

      def type
        SOL_TYPE
      end

      def to_formula(**other_keys)
        predicate_s = predicate.to_formula(**other_keys)

        args_s = args.map do |a|
          f = a.to_formula(**other_keys)
          if a.is_a?(Atom)
            "$#{f}"
          else
            f
          end
        end.join(',')

        "#{predicate_s}(#{args_s})"
      end

      def each_atom(&block)
        if block
          yield self
        else
          [self]
        end
      end

      def transform_atoms
        yield self
      end

      def sol2fol(sol_maps)
        expanded = sol_maps.predicate_map[predicate]
        return self unless expanded

        grounding = args.map do |arg|
          arg.predicate if arg.is_a?(Atom)
        end

        Atom.new(
          expanded[grounding],
          args.flat_map do |arg|
            if arg.is_a?(Atom)
              arg.args
            else
              [arg]
            end
          end
        )
      end

      def sol2fol_all(sol_maps)
        expanded = sol_maps.predicate_map[predicate]
        return [self] unless expanded

        upper_grounding = args.map do |arg|
          arg.predicate if arg.is_a?(Atom)
        end

        expanded
          .select { |grounding, _| upper_grounding.zip(grounding).all? { |u, g| u.nil? || u == g } }
          .map do |grounding, fol_pred|
          Atom.new(
            fol_pred,
            args.zip(grounding).flat_map do |arg, g|
              if g
                case arg
                when Atom
                  arg.args
                when Variable # this grounding is tighter than self's
                  g.args.each_with_index.map { |parg, i| Variable.new("#{arg.name}__#{i}", parg.type) }
                else
                  raise AlchemizerError, 'Unreachable code'
                end
              else
                [arg]
              end
            end
          )
        end
      end

      def fol2sol(sol_maps)
        original = sol_maps.predicate_map_inv[predicate]
        return self unless original

        pred, grounding = original

        ns = grounding.map do |g|
          if g
            g&.args&.length
          else
            1
          end
        end

        Atom.new(
          pred,
          args.each_var_slice(ns).zip(grounding).map do |args, g|
            if g
              Atom.new(g, args)
            else
              arg = args[0]
              if arg.type.name == FOL_SOL_TYPE
                pred, grounding = sol_maps.grounding_map_inv[arg] ||
                  raise(AlchemizerError, "Couldn't map back constant #{arg} to SOL")
                Atom.new(pred, grounding)
              else
                arg
              end
            end
          end
        )
      end
    end

    class VariableDecl
      include Formula
      attr_reader :name

      def initialize(name)
        raise AlchemizerError, "Invalid variable name: #{name}" unless name[0] =~ /[a-z]/

        @name = name.freeze
        freeze
      end

      def compile(type:, **_other_keys)
        Variable.new(name, type)
      end

      def to_formula(**_other_keys)
        name
      end
    end

    class Variable
      include Formula
      attr_reader :name, :type

      def initialize(name, type)
        @name = name.freeze
        @type = type.freeze
        freeze
      end

      def to_formula(**_other_keys)
        name
      end
    end

    class ConstantDecl
      include Formula
      attr_reader :name

      def initialize(name)
        unless name.is_a?(Integer) || (name.is_a?(String) && !name.empty? && name[0] =~ /[A-Z0-1]/)
          raise AlchemizerError, "Invalid constant name: '#{name}'"
        end

        @name = name.freeze
        freeze
      end

      def compile(type:, **_other_keys)
        type.resolve(name)
      end

      def to_formula(**_other_keys)
        name
      end
    end

    class Constant
      include Formula
      attr_reader :name, :type

      def initialize(name, type)
        raise ArgumentError, "type is not a Type: #{type}" unless type.is_a?(Type)

        @name = name.freeze
        @type = type # Do not freeze the type as we are being added to it
        freeze
      end

      def to_formula(**_other_keys)
        name
      end
    end
  end
end

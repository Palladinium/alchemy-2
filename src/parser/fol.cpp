/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 67 "../src/parser/fol.y"

#define YYSTYPE int
#define YYDEBUG 1

#line 63 "fol.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ZZ_NUM = 258,                  /* ZZ_NUM  */
    ZZ_DOTDOTDOT = 259,            /* ZZ_DOTDOTDOT  */
    ZZ_STRING = 260,               /* ZZ_STRING  */
    ZZ_INCLUDE = 261,              /* ZZ_INCLUDE  */
    ZZ_PREDICATE = 262,            /* ZZ_PREDICATE  */
    ZZ_FUNCTION = 263,             /* ZZ_FUNCTION  */
    ZZ_CONSTANT = 264,             /* ZZ_CONSTANT  */
    ZZ_VARIABLE = 265,             /* ZZ_VARIABLE  */
    ZZ_TYPE = 266,                 /* ZZ_TYPE  */
    ZZ_FORALL = 267,               /* ZZ_FORALL  */
    ZZ_EXIST = 268,                /* ZZ_EXIST  */
    ZZ_EQUIV = 269,                /* ZZ_EQUIV  */
    ZZ_IMPLY = 270                 /* ZZ_IMPLY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ZZ_NUM = 3,                     /* ZZ_NUM  */
  YYSYMBOL_ZZ_DOTDOTDOT = 4,               /* ZZ_DOTDOTDOT  */
  YYSYMBOL_ZZ_STRING = 5,                  /* ZZ_STRING  */
  YYSYMBOL_ZZ_INCLUDE = 6,                 /* ZZ_INCLUDE  */
  YYSYMBOL_ZZ_PREDICATE = 7,               /* ZZ_PREDICATE  */
  YYSYMBOL_ZZ_FUNCTION = 8,                /* ZZ_FUNCTION  */
  YYSYMBOL_ZZ_CONSTANT = 9,                /* ZZ_CONSTANT  */
  YYSYMBOL_ZZ_VARIABLE = 10,               /* ZZ_VARIABLE  */
  YYSYMBOL_ZZ_TYPE = 11,                   /* ZZ_TYPE  */
  YYSYMBOL_12_ = 12,                       /* '-'  */
  YYSYMBOL_13_ = 13,                       /* '+'  */
  YYSYMBOL_ZZ_FORALL = 14,                 /* ZZ_FORALL  */
  YYSYMBOL_ZZ_EXIST = 15,                  /* ZZ_EXIST  */
  YYSYMBOL_ZZ_EQUIV = 16,                  /* ZZ_EQUIV  */
  YYSYMBOL_ZZ_IMPLY = 17,                  /* ZZ_IMPLY  */
  YYSYMBOL_18_v_ = 18,                     /* 'v'  */
  YYSYMBOL_19_ = 19,                       /* '^'  */
  YYSYMBOL_20_ = 20,                       /* '!'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_23_ = 23,                       /* '%'  */
  YYSYMBOL_24_n_ = 24,                     /* '\n'  */
  YYSYMBOL_25_ = 25,                       /* '@'  */
  YYSYMBOL_26_ = 26,                       /* '.'  */
  YYSYMBOL_27_r_ = 27,                     /* '\r'  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '?'  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_input = 41,                     /* input  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_continuous_part = 46,           /* continuous_part  */
  YYSYMBOL_47_5 = 47,                      /* $@5  */
  YYSYMBOL_at = 48,                        /* at  */
  YYSYMBOL_fullstop = 49,                  /* fullstop  */
  YYSYMBOL_newline = 50,                   /* newline  */
  YYSYMBOL_optnewline = 51,                /* optnewline  */
  YYSYMBOL_include = 52,                   /* include  */
  YYSYMBOL_nnewline = 53,                  /* nnewline  */
  YYSYMBOL_type_declaration = 54,          /* type_declaration  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_is_variable_type = 56,          /* is_variable_type  */
  YYSYMBOL_constant_declarations = 57,     /* constant_declarations  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_variable_or_string_or_constant = 59, /* variable_or_string_or_constant  */
  YYSYMBOL_constant_sep = 60,              /* constant_sep  */
  YYSYMBOL_numeric_type_declaration = 61,  /* numeric_type_declaration  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_numeric_types = 65,             /* numeric_types  */
  YYSYMBOL_single_numeric_types = 66,      /* single_numeric_types  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_single_numeric_type = 68,       /* single_numeric_type  */
  YYSYMBOL_predicate_declaration = 69,     /* predicate_declaration  */
  YYSYMBOL_70_12 = 70,                     /* $@12  */
  YYSYMBOL_71_13 = 71,                     /* $@13  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_function_declaration = 73,      /* function_declaration  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_75_16 = 75,                     /* $@16  */
  YYSYMBOL_76_17 = 76,                     /* $@17  */
  YYSYMBOL_function_return_type = 77,      /* function_return_type  */
  YYSYMBOL_types = 78,                     /* types  */
  YYSYMBOL_79_18 = 79,                     /* $@18  */
  YYSYMBOL_80_19 = 80,                     /* $@19  */
  YYSYMBOL_type_code = 81,                 /* type_code  */
  YYSYMBOL_82_20 = 82,                     /* $@20  */
  YYSYMBOL_variable_code = 83,             /* variable_code  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_exist_unique = 85,              /* exist_unique  */
  YYSYMBOL_pd_not_qs = 86,                 /* pd_not_qs  */
  YYSYMBOL_predicate_definition = 87,      /* predicate_definition  */
  YYSYMBOL_88_22 = 88,                     /* $@22  */
  YYSYMBOL_nothing_or_constants = 89,      /* nothing_or_constants  */
  YYSYMBOL_90_23 = 90,                     /* $@23  */
  YYSYMBOL_91_24 = 91,                     /* $@24  */
  YYSYMBOL_real_value = 92,                /* real_value  */
  YYSYMBOL_function_definition = 93,       /* function_definition  */
  YYSYMBOL_94_25 = 94,                     /* $@25  */
  YYSYMBOL_95_26 = 95,                     /* $@26  */
  YYSYMBOL_96_27 = 96,                     /* $@27  */
  YYSYMBOL_constants_in_groundings = 97,   /* constants_in_groundings  */
  YYSYMBOL_is_constant_string_num_variable = 98, /* is_constant_string_num_variable  */
  YYSYMBOL_function_return_constant = 99,  /* function_return_constant  */
  YYSYMBOL_weight = 100,                   /* weight  */
  YYSYMBOL_101_28 = 101,                   /* $@28  */
  YYSYMBOL_weight_fullstop = 102,          /* weight_fullstop  */
  YYSYMBOL_utility = 103,                  /* utility  */
  YYSYMBOL_104_29 = 104,                   /* $@29  */
  YYSYMBOL_sentence = 105,                 /* sentence  */
  YYSYMBOL_106_30 = 106,                   /* $@30  */
  YYSYMBOL_107_31 = 107,                   /* $@31  */
  YYSYMBOL_108_32 = 108,                   /* $@32  */
  YYSYMBOL_109_33 = 109,                   /* $@33  */
  YYSYMBOL_110_34 = 110,                   /* $@34  */
  YYSYMBOL_111_35 = 111,                   /* $@35  */
  YYSYMBOL_112_36 = 112,                   /* $@36  */
  YYSYMBOL_113_37 = 113,                   /* $@37  */
  YYSYMBOL_114_38 = 114,                   /* $@38  */
  YYSYMBOL_115_39 = 115,                   /* $@39  */
  YYSYMBOL_116_40 = 116,                   /* $@40  */
  YYSYMBOL_quantifier = 117,               /* quantifier  */
  YYSYMBOL_variables = 118,                /* variables  */
  YYSYMBOL_119_41 = 119,                   /* $@41  */
  YYSYMBOL_120_42 = 120,                   /* $@42  */
  YYSYMBOL_quant_variable = 121,           /* quant_variable  */
  YYSYMBOL_atomic_sentence = 122,          /* atomic_sentence  */
  YYSYMBOL_123_43 = 123,                   /* $@43  */
  YYSYMBOL_124_44 = 124,                   /* $@44  */
  YYSYMBOL_125_45 = 125,                   /* $@45  */
  YYSYMBOL_nothing_or_terms = 126,         /* nothing_or_terms  */
  YYSYMBOL_127_46 = 127,                   /* $@46  */
  YYSYMBOL_internal_predicate_sign = 128,  /* internal_predicate_sign  */
  YYSYMBOL_asterisk = 129,                 /* asterisk  */
  YYSYMBOL_terms = 130,                    /* terms  */
  YYSYMBOL_131_47 = 131,                   /* $@47  */
  YYSYMBOL_term = 132,                     /* term  */
  YYSYMBOL_function_term = 133,            /* function_term  */
  YYSYMBOL_134_48 = 134,                   /* $@48  */
  YYSYMBOL_135_49 = 135,                   /* $@49  */
  YYSYMBOL_136_50 = 136,                   /* $@50  */
  YYSYMBOL_internal_function_sign = 137,   /* internal_function_sign  */
  YYSYMBOL_numeric_term = 138,             /* numeric_term  */
  YYSYMBOL_139_51 = 139,                   /* $@51  */
  YYSYMBOL_140_52 = 140,                   /* $@52  */
  YYSYMBOL_gaussian_shorthand = 141,       /* gaussian_shorthand  */
  YYSYMBOL_142_53 = 142,                   /* $@53  */
  YYSYMBOL_143_54 = 143,                   /* $@54  */
  YYSYMBOL_144_55 = 144,                   /* $@55  */
  YYSYMBOL_145_56 = 145,                   /* $@56  */
  YYSYMBOL_146_57 = 146,                   /* $@57  */
  YYSYMBOL_147_58 = 147,                   /* $@58  */
  YYSYMBOL_148_59 = 148,                   /* $@59  */
  YYSYMBOL_149_60 = 149,                   /* $@60  */
  YYSYMBOL_150_61 = 150                    /* $@61  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;


/* Unqualified %code blocks.  */
#line 104 "../src/parser/fol.y"
 //bisonopencode
#include "fol.h"
#include "follex.cpp"

  // 0: no output; 1,2: increasing order of verbosity
int folDbg = 0;
//int folDbg = 1;
//int folDbg = 2;

#line 310 "fol.cpp"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 16
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,     2,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,     2,     2,    23,     2,     2,
      32,    33,    21,    13,    31,    12,    26,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,     2,
      39,    28,    38,    34,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    14,    15,    16,
      17
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   121,   132,   133,   134,   135,   136,   137,
     138,   140,   142,   146,   151,   155,   162,   145,   210,   214,
     213,   230,   231,   234,   237,   247,   249,   252,   255,   257,
     263,   323,   325,   336,   334,   354,   367,   382,   387,   386,
     398,   398,   398,   403,   406,   408,   415,   421,   432,   438,
     453,   430,   464,   489,   500,   498,   507,   510,   535,   547,
     548,   534,   562,   599,   622,   647,   598,   676,   676,   682,
     681,   686,   685,   688,   689,   694,   693,   706,   705,   722,
     724,   741,   744,   750,   762,   761,   812,   820,   826,   819,
     835,   843,   851,   857,   902,   849,   947,   955,   965,   966,
     972,   981,   989,   998,  1010,  1019,  1034,  1038,  1037,  1048,
    1051,  1059,  1063,  1062,  1082,  1081,  1100,  1099,  1114,  1114,
    1118,  1117,  1130,  1129,  1142,  1141,  1153,  1152,  1164,  1166,
    1172,  1164,  1183,  1182,  1198,  1206,  1219,  1221,  1219,  1228,
    1232,  1259,  1258,  1291,  1310,  1291,  1476,  1496,  1495,  1663,
    1677,  1691,  1708,  1725,  1738,  1761,  1763,  1780,  1778,  1789,
    1817,  1827,  1839,  1854,  1860,  1871,  2068,  2104,  2067,  2188,
    2187,  2272,  2281,  2290,  2299,  2308,  2320,  2319,  2336,  2335,
    2350,  2355,  2385,  2354,  2404,  2410,  2416,  2446,  2452,  2463,
    2469,  2403
};
#endif

#define YYPACT_NINF (-205)
#define YYTABLE_NINF (-156)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -205,    11,  -205,   -20,    29,     5,    68,  -205,  -205,  -205,
      79,    56,  -205,  -205,    75,    63,    75,    75,    75,  -205,
    -205,   128,    64,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,    94,  -205,    81,  -205,    95,  -205,  -205,
    -205,   118,  -205,  -205,  -205,  -205,   107,   119,  -205,  -205,
    -205,   157,  -205,    19,  -205,  -205,  -205,  -205,   133,   154,
    -205,   164,   141,  -205,  -205,   143,  -205,  -205,   172,    35,
    -205,  -205,  -205,   110,  -205,  -205,   156,   156,   167,   145,
    -205,  -205,  -205,  -205,    98,     6,    30,   134,   147,   149,
    -205,   158,  -205,   150,    19,  -205,  -205,  -205,   173,   175,
    -205,    35,    35,    35,  -205,  -205,  -205,  -205,  -205,   160,
    -205,  -205,   122,   176,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,    46,  -205,  -205,   163,  -205,   137,  -205,    87,  -205,
    -205,  -205,    70,    23,   129,   129,   129,   129,    16,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,   178,    72,  -205,  -205,
     179,  -205,   134,   134,  -205,  -205,  -205,  -205,  -205,    65,
    -205,  -205,  -205,  -205,  -205,    35,    35,    35,    35,  -205,
    -205,  -205,  -205,  -205,  -205,    75,   159,  -205,  -205,  -205,
     162,  -205,  -205,  -205,  -205,   165,   166,  -205,  -205,   168,
    -205,  -205,   182,  -205,   192,  -205,   105,  -205,   170,   169,
     171,  -205,    39,   151,   177,  -205,   168,   174,    16,    16,
    -205,  -205,  -205,  -205,  -205,   122,   122,  -205,  -205,    35,
     180,  -205,  -205,  -205,   194,  -205,  -205,   181,  -205,   183,
     161,   122,    41,    85,   122,   132,  -205,  -205,   200,  -205,
     197,  -205,  -205,   130,   100,   135,   195,  -205,   204,  -205,
    -205,  -205,  -205,  -205,  -205,   168,   122,   196,   100,  -205,
     207,  -205,   184,  -205,   193,  -205,   210,  -205
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,    62,    36,    25,    21,    26,
     106,    81,     4,     5,     0,     0,     0,     0,     0,    63,
       3,     0,     0,   107,    14,   104,   103,   102,   105,    82,
      22,    83,    12,     0,    11,     0,     6,     0,     7,     8,
       9,     0,    31,    32,    30,    59,   109,   111,    84,    10,
      92,    33,    64,     0,   110,   108,   112,    15,    86,     0,
      37,     0,     0,    77,    75,    60,    73,    74,     0,   118,
      87,    85,    93,    43,    49,    65,    79,    79,    69,     0,
     113,   132,   116,   114,    18,   143,     0,     0,     0,     0,
      34,    44,    38,     0,     0,    80,    78,    76,     0,     0,
      61,   118,   118,   118,   122,   120,   124,   126,    19,    23,
     156,   119,     0,     0,   134,   135,   129,   100,    99,    98,
     101,    43,    96,    94,    46,    47,     0,    50,     0,    70,
      72,   133,     0,     0,    27,    27,    27,    27,     0,    24,
      16,   162,   161,   166,   160,   163,     0,     0,   165,   141,
       0,    88,     0,     0,    45,    41,    42,    40,    39,     0,
      66,   117,   115,    28,    29,   118,   118,   118,   118,   181,
     184,   178,   176,    20,   180,     0,     0,   164,   172,   171,
       0,   173,   174,   175,   153,   149,   150,   144,   169,   146,
     140,   130,     0,   139,    91,    97,    43,    57,     0,     0,
      53,    56,   123,   121,   125,   127,   146,     0,     0,     0,
      17,   167,   154,   151,   152,     0,     0,   147,   142,   118,
       0,    90,    89,    95,     0,    51,    54,     0,   185,     0,
       0,     0,   145,   170,     0,   131,   137,    52,     0,   182,
       0,   179,   177,     0,   159,     0,     0,    55,     0,   186,
     157,   168,   148,   138,   183,   146,     0,     0,   158,   187,
       0,   188,     0,   189,     0,   190,     0,   191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
     -11,    22,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
     142,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   -24,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   124,  -205,
    -205,   121,  -205,   123,  -205,   144,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,    67,    71,  -205,
    -205,  -205,  -205,  -205,  -205,   -93,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   -22,  -205,
    -205,    33,  -205,  -205,  -205,  -205,  -204,  -205,  -205,  -205,
      -8,  -205,  -111,  -205,  -205,  -205,  -205,  -205,   -37,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    10,    47,    69,   175,   109,   138,    11,   140,
      12,   165,    13,    44,    14,    60,    15,    73,   126,   158,
     152,    16,    61,    93,   159,   199,   200,   238,   201,    17,
      22,    53,    79,    18,    41,    62,    94,    19,    65,    98,
      99,    66,    77,    67,    76,    96,    33,    49,    58,    71,
      87,   194,   222,    34,    59,    88,   153,   121,   122,    35,
      24,    46,    55,    57,    68,    84,   103,   102,    85,   135,
     134,   136,   137,    86,   150,   219,   101,   116,   191,   192,
     246,   193,   111,   189,   112,   215,   218,   234,   187,   113,
     243,   256,   244,   148,   176,   231,   216,   188,   173,   209,
     208,   174,   206,   248,   207,   240,   255,   260,   262,   264,
     266
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, parse error.  */
static const yytype_int16 yytable[] =
{
      32,   147,   227,    36,    20,    38,    39,    40,   131,   132,
     133,     2,     3,  -155,   -13,   -68,   -13,     4,   -13,   -13,
     -13,     5,     6,   169,   -13,   -13,   -13,   110,   170,    63,
      64,   -13,   -13,   -35,    21,     7,     8,   -58,     9,   104,
     105,   106,   107,   -13,   114,   115,   -13,   -13,   171,  -128,
    -128,   257,   172,   178,   179,    81,   105,   106,   107,    25,
     162,    26,   181,   182,   183,    27,    28,    82,   197,   198,
      89,    83,   202,   203,   204,   205,    29,    91,   -67,   151,
       7,    30,    23,     9,   178,   179,   104,   105,   106,   107,
      31,    37,   180,   181,   182,   183,    45,   178,   179,     7,
     184,    48,     9,   161,   232,   233,   181,   182,   183,    50,
     185,   186,   178,   179,   104,   105,   106,   107,    78,   108,
     160,   181,   182,   183,    51,   141,   235,   142,    52,    89,
     143,   144,   145,    54,    89,   146,    91,   117,   223,   118,
      90,    91,   155,   119,   120,   258,   156,   157,   104,   105,
     106,   107,    42,   163,    56,    43,   164,   166,   167,   168,
     -48,   250,    72,   251,   210,    70,   250,    74,   252,   106,
     107,   229,   230,    75,    78,    80,    95,   -71,   100,   123,
     124,   127,   125,   149,    64,    63,   139,   154,   177,   190,
     212,   211,   190,   213,   214,   221,   107,   237,   242,   225,
     217,   224,   226,   197,   249,   190,   228,   254,   259,   239,
     261,   236,   265,   267,   247,    92,   241,   263,   128,   129,
     196,    97,   130,   195,   253,   220,   245
};

static const yytype_int16 yycheck[] =
{
      11,   112,   206,    14,    24,    16,    17,    18,   101,   102,
     103,     0,     1,     7,     3,    10,     5,     6,     7,     8,
       9,    10,    11,     7,    13,    14,    15,    21,    12,    10,
      11,    20,    21,    28,     5,    24,    25,    32,    27,    16,
      17,    18,    19,    32,    14,    15,    35,    36,    32,    14,
      15,   255,    36,    12,    13,    20,    17,    18,    19,     3,
      37,     5,    21,    22,    23,     9,    10,    32,     3,     4,
      24,    36,   165,   166,   167,   168,    20,    31,    10,    33,
      24,    25,     3,    27,    12,    13,    16,    17,    18,    19,
      34,    28,    20,    21,    22,    23,    32,    12,    13,    24,
      28,     7,    27,    33,   215,   216,    21,    22,    23,    28,
      38,    39,    12,    13,    16,    17,    18,    19,    31,    21,
      33,    21,    22,    23,    29,     3,   219,     5,    10,    24,
       8,     9,    10,    26,    24,    13,    31,     3,    33,     5,
      30,    31,     5,     9,    10,   256,     9,    10,    16,    17,
      18,    19,    24,    24,    35,    27,    27,   135,   136,   137,
       3,    31,     8,    33,   175,    32,    31,     3,    33,    18,
      19,   208,   209,    32,    31,     3,    20,    10,    33,    32,
      31,    31,    24,     7,    11,    10,    26,    24,    10,    10,
      28,    32,    10,    28,    28,     3,    19,     3,    37,    30,
      32,    31,    31,     3,     7,    10,    32,     3,    12,    28,
       3,    31,    19,     3,   238,    73,    33,    33,    94,    98,
     153,    77,    99,   152,   246,   192,   234
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,     0,     1,     6,    10,    11,    24,    25,    27,
      42,    48,    50,    52,    54,    56,    61,    69,    73,    77,
      24,     5,    70,     3,   100,     3,     5,     9,    10,    20,
      25,    34,    50,    86,    93,    99,    50,    28,    50,    50,
      50,    74,    24,    27,    53,    32,   101,    43,     7,    87,
      28,    29,    10,    71,    26,   102,    35,   103,    88,    94,
      55,    62,    75,    10,    11,    78,    81,    83,   104,    44,
      32,    89,     8,    57,     3,    32,    84,    82,    31,    72,
       3,    20,    32,    36,   105,   108,   113,    90,    95,    24,
      30,    31,    60,    63,    76,    20,    85,    85,    79,    80,
      33,   116,   107,   106,    16,    17,    18,    19,    21,    46,
      21,   122,   124,   129,    14,    15,   117,     3,     5,     9,
      10,    97,    98,    32,    31,    24,    58,    31,    78,    81,
      83,   105,   105,   105,   110,   109,   111,   112,    47,    26,
      49,     3,     5,     8,     9,    10,    13,   132,   133,     7,
     114,    33,    60,    96,    24,     5,     9,    10,    59,    64,
      33,    33,    37,    24,    27,    51,    51,    51,    51,     7,
      12,    32,    36,   138,   141,    45,   134,    10,    12,    13,
      20,    21,    22,    23,    28,    38,    39,   128,   137,   123,
      10,   118,   119,   121,    91,    98,    97,     3,     4,    65,
      66,    68,   105,   105,   105,   105,   142,   144,   140,   139,
      50,    32,    28,    28,    28,   125,   136,    32,   126,   115,
     121,     3,    92,    33,    31,    30,    31,   126,    32,   138,
     138,   135,   132,   132,   127,   105,    31,     3,    67,    28,
     145,    33,    37,   130,   132,   130,   120,    68,   143,     7,
      31,    33,    33,   118,     3,   146,   131,   126,   132,    12,
     147,     3,   148,    33,   149,    19,   150,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    43,    44,    45,    41,    46,    47,
      46,    48,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    53,    53,    55,    54,    56,    56,    57,    58,    57,
      59,    59,    59,    60,    60,    60,    60,    60,    62,    63,
      64,    61,    65,    65,    67,    66,    66,    68,    70,    71,
      72,    69,    69,    74,    75,    76,    73,    77,    77,    79,
      78,    80,    78,    78,    78,    82,    81,    84,    83,    85,
      85,    86,    86,    86,    88,    87,    89,    90,    91,    89,
      92,    92,    94,    95,    96,    93,    97,    97,    98,    98,
      98,    98,    99,    99,    99,    99,   100,   101,   100,   102,
     102,   103,   104,   103,   106,   105,   107,   105,   108,   105,
     109,   105,   110,   105,   111,   105,   112,   105,   113,   114,
     115,   105,   116,   105,   117,   117,   119,   120,   118,   118,
     121,   123,   122,   124,   125,   122,   126,   127,   126,   128,
     128,   128,   128,   128,   128,   129,   129,   131,   130,   130,
     132,   132,   132,   132,   132,   132,   134,   135,   133,   136,
     133,   137,   137,   137,   137,   137,   139,   138,   140,   138,
     138,   142,   143,   141,   144,   145,   146,   147,   148,   149,
     150,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     3,     3,     3,     3,
       4,     3,     3,     0,     0,     0,     0,    11,     0,     0,
       3,     1,     2,     0,     1,     1,     1,     0,     1,     1,
       3,     1,     1,     0,     6,     1,     1,     0,     0,     4,
       1,     1,     1,     0,     1,     3,     2,     2,     0,     0,
       0,    10,     3,     1,     0,     4,     1,     1,     0,     0,
       0,     7,     1,     0,     0,     0,     8,     1,     1,     0,
       4,     0,     4,     1,     1,     0,     3,     0,     3,     0,
       1,     0,     1,     1,     0,     3,     0,     0,     0,     6,
       1,     0,     0,     0,     0,     9,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     3,     0,
       1,     0,     0,     3,     0,     4,     0,     4,     0,     2,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     0,
       0,     6,     0,     3,     1,     1,     0,     0,     5,     1,
       1,     0,     4,     0,     0,     5,     0,     0,     4,     1,
       1,     2,     2,     1,     2,     0,     1,     0,     4,     1,
       1,     1,     1,     1,     2,     1,     0,     0,     6,     0,
       4,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       1,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,    16
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    15,     0,
       0,     0,     0,     0,     0,     0,    17,    19,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    25,
      27,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    13,     0,   106,     0,    86,     0,   136,     0,    91,
       0,   145,     0,   170,     0,   170,     0,   170,     0,   170,
       0,   170,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   136,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ZZ_NUM",
  "ZZ_DOTDOTDOT", "ZZ_STRING", "ZZ_INCLUDE", "ZZ_PREDICATE", "ZZ_FUNCTION",
  "ZZ_CONSTANT", "ZZ_VARIABLE", "ZZ_TYPE", "'-'", "'+'", "ZZ_FORALL",
  "ZZ_EXIST", "ZZ_EQUIV", "ZZ_IMPLY", "'v'", "'^'", "'!'", "'*'", "'/'",
  "'%'", "'\\n'", "'@'", "'.'", "'\\r'", "'='", "'{'", "'}'", "','", "'('",
  "')'", "'?'", "':'", "'['", "']'", "'>'", "'<'", "$accept", "input",
  "$@1", "$@2", "$@3", "$@4", "continuous_part", "$@5", "at", "fullstop",
  "newline", "optnewline", "include", "nnewline", "type_declaration",
  "$@6", "is_variable_type", "constant_declarations", "$@7",
  "variable_or_string_or_constant", "constant_sep",
  "numeric_type_declaration", "$@8", "$@9", "$@10", "numeric_types",
  "single_numeric_types", "$@11", "single_numeric_type",
  "predicate_declaration", "$@12", "$@13", "$@14", "function_declaration",
  "$@15", "$@16", "$@17", "function_return_type", "types", "$@18", "$@19",
  "type_code", "$@20", "variable_code", "$@21", "exist_unique",
  "pd_not_qs", "predicate_definition", "$@22", "nothing_or_constants",
  "$@23", "$@24", "real_value", "function_definition", "$@25", "$@26",
  "$@27", "constants_in_groundings", "is_constant_string_num_variable",
  "function_return_constant", "weight", "$@28", "weight_fullstop",
  "utility", "$@29", "sentence", "$@30", "$@31", "$@32", "$@33", "$@34",
  "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "quantifier",
  "variables", "$@41", "$@42", "quant_variable", "atomic_sentence", "$@43",
  "$@44", "$@45", "nothing_or_terms", "$@46", "internal_predicate_sign",
  "asterisk", "terms", "$@47", "term", "function_term", "$@48", "$@49",
  "$@50", "internal_function_sign", "numeric_term", "$@51", "$@52",
  "gaussian_shorthand", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58",
  "$@59", "$@60", "$@61", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("parse error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* input: %empty  */
#line 119 "../src/parser/fol.y"
  { if (folDbg >= 2) printf("input: empty\n"); }
#line 1523 "fol.cpp"
    break;

  case 3: /* input: input error '\n'  */
#line 122 "../src/parser/fol.y"
  {
    yyerrok; // tell Bison not to suppress any errors
    const char* tok;
    while (true)
    {
      tok = zztokenList.removeLast();
      if (strcmp(tok,"\n")==0) { delete tok; break; }
      delete tok;
    }
  }
#line 1538 "fol.cpp"
    break;

  case 13: /* $@1: %empty  */
#line 146 "../src/parser/fol.y"
  {
    if (folDbg >= 2) printf("input: weight\n");
    zzreset();
  }
#line 1547 "fol.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 151 "../src/parser/fol.y"
  {
    if (folDbg >= 2) printf("input: utility\n");
  }
#line 1555 "fol.cpp"
    break;

  case 15: /* $@3: %empty  */
#line 155 "../src/parser/fol.y"
  {
    if (folDbg >= 2) printf("input: sentence\n");
      // the states should be reset because a parse error may have occurred
  }
#line 1564 "fol.cpp"
    break;

  case 16: /* $@4: %empty  */
#line 162 "../src/parser/fol.y"
  {
    ListObj* formula;
    zzassert(zzoldNewVarList.size()==0,"expected zzoldNewVarList.size()==0");
    zzassert(zzformulaListObjs.size()==1,"expected zzformulaListObjs.size()=1");
    formula = zzformulaListObjs.top(); zzformulaListObjs.pop();

    zzdetermineEqPredTypes(formula);//set the any unknown type of '=' predicates
    zzeqPredList.clear();
    zzdetermineIntPredTypes(formula);//set the any unknown type of internal predicates
    zzintPredList.clear();
    zzdetermineIntFuncTypes(formula);//set the any unknown type of internal functions
    zzintFuncList.clear();
    zzsetPlusVarTypeId();// set typeIds of variables with pluses before them
    zzcheckVarNameToIdMap();

    if (zzhasFullStop && zzwt != NULL)
    {
      zzerr("A weight must not be specified for a formula that is "
            "terminated with a period (i.e. the formula is hard).");
      delete zzwt; zzwt = NULL;
    }

      // at this point we are sure we are dealing with a formula

      //if there are errors, we can keep this formula for further processing
    if (zznumErrors == 0)
    {
        //defer converting the formula to CNF until we have read all the
        //.db files and are sure that we know all the constants to ground
        //formula's clauses
      ZZFormulaInfo* epfi
        = new ZZFormulaInfo(formula, zzformulaStr, zzfdnumPreds, zzwt,
                            zzdefaultWt, zzdomain, zzmln, zzvarNameToIdMap,
                            zzplusVarMap, zznumAsterisk,
                            zzhasFullStop, zzreadHardClauseWts,
                            zzmustHaveWtOrFullStop, zzinIndivisible,
                            zzisHybrid, zzcontPred, zzmean,
                            zzhasWeightFullStop, zzutil);
      zzformulaInfos.append(epfi);
    }

    if (zzwt) { delete zzwt; zzwt = NULL; }
    if (zzutil) { delete zzutil; zzutil = NULL; }
  }
#line 1613 "fol.cpp"
    break;

  case 19: /* $@5: %empty  */
#line 214 "../src/parser/fol.y"
  {
    // Indicator
    if (folDbg >= 2) printf("sentence: indicator function\n");
    zzconsumeToken(zztokenList,"*");
    if (folDbg >= 1) printf("* ");
    zzisHybrid = true;
    zzformulaStr.append(" * ");
  }
#line 1626 "fol.cpp"
    break;

  case 20: /* continuous_part: '*' $@5 numeric_term  */
#line 223 "../src/parser/fol.y"
  {
    // Real-valued
    if (folDbg >= 2) printf("sentence: numeric term\n");
  }
#line 1635 "fol.cpp"
    break;

  case 21: /* at: '@'  */
#line 230 "../src/parser/fol.y"
         { zzconsumeToken(zztokenList,"@"); }
#line 1641 "fol.cpp"
    break;

  case 22: /* at: at '@'  */
#line 231 "../src/parser/fol.y"
         { zzconsumeToken(zztokenList,"@"); }
#line 1647 "fol.cpp"
    break;

  case 24: /* fullstop: '.'  */
#line 238 "../src/parser/fol.y"
{
  if (folDbg >= 1) printf(".\n"); zzconsumeToken(zztokenList,".");
  zzassert(!zzhasFullStop, "expecting no full stop");
  zzhasFullStop = true;
  zzformulaStr.append(".");
}
#line 1658 "fol.cpp"
    break;

  case 25: /* newline: '\n'  */
#line 247 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\n\n"); zzconsumeToken(zztokenList,"\n"); }
#line 1664 "fol.cpp"
    break;

  case 26: /* newline: '\r'  */
#line 249 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\r\n"); zzconsumeToken(zztokenList,"\r"); }
#line 1670 "fol.cpp"
    break;

  case 28: /* optnewline: '\n'  */
#line 255 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\n\n"); zzconsumeToken(zztokenList,"\n"); }
#line 1676 "fol.cpp"
    break;

  case 29: /* optnewline: '\r'  */
#line 257 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\r\n"); zzconsumeToken(zztokenList,"\r"); }
#line 1682 "fol.cpp"
    break;

  case 30: /* include: ZZ_INCLUDE ZZ_STRING nnewline  */
#line 264 "../src/parser/fol.y"
{
  const char* inc = zztokenList.removeLast();
  const char* str = zztokenList.removeLast();
  const char* nl = zztokenList.removeLast();
  zzassert(strcmp(inc,"#include")==0,"expecting #include keyword");

  if (folDbg >= 1) printf("#include %s ", str);

  string s(str);
  if (s.length() == 0)
  {
    zzerr("empty string used with #include");
    delete [] inc;
    delete [] str;
    delete [] nl;
    break;
  }

  zzassert(s.at(0) == '"' && s.at(s.length()-1) == '"', "no enclosing \"");
  s = s.substr(1, s.length()-2);
  int len = s.length();

  // if it is a .cpp file, then we are dealing with linked-in functions and predicates
  if (s.at(len-4)=='.' && s.at(len-3)=='c' && s.at(len-2)=='p' &&
    s.at(len-1)=='p')
  {
    zzcompileFunctions(str);
    zzusingLinkedPredicates = true;
    zzusingLinkedFunctions = true;
    break;
  }

  FILE* newin = fopen(s.c_str(), "r" );
  if (newin)
  {
    zzinStack.push(ZZFileState(yyin, string(zzinFileName), zznumCharRead,
                               zzline, zzcolumn));
    ungetc('\n', newin); // pretend that file begins with a newline
    zzline = 1;
    zzcolumn = -1;
    zzline--;
    zzinFileName = str;
    yyrestart(newin);
    zznumCharRead = 0;

      // if it is a .db file containing ground predicates
    if ((s.at(len-3)=='.' && s.at(len-2)=='d' && s.at(len-1)=='b'))
      zzparseGroundPred = true;
  }
  else
    zzerr("Failed to open file %s.", str);

  delete [] inc;
  delete [] str;
  delete [] nl;
}
#line 1743 "fol.cpp"
    break;

  case 31: /* nnewline: '\n'  */
#line 323 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\n\n"); }
#line 1749 "fol.cpp"
    break;

  case 32: /* nnewline: '\r'  */
#line 325 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("\\r\n"); }
#line 1755 "fol.cpp"
    break;

  case 33: /* $@6: %empty  */
#line 336 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,"=");
  zzconsumeToken(zztokenList,"{");
  if (folDbg >= 1) printf("= { ");
  if (folDbg >= 2) printf("type_declarations: constant_declarations\n");
}
#line 1766 "fol.cpp"
    break;

  case 34: /* type_declaration: is_variable_type '=' '{' $@6 constant_declarations '}'  */
#line 344 "../src/parser/fol.y"
{
  if (folDbg >= 1) printf("} ");
  zzconsumeToken(zztokenList, "}");
  delete [] zztypeName;
  zztypeName = NULL;
}
#line 1777 "fol.cpp"
    break;

  case 35: /* is_variable_type: ZZ_VARIABLE  */
#line 355 "../src/parser/fol.y"
{
  const char* idf = zztokenList.removeLast();
  if (folDbg >= 1) printf("type t_%s ", idf);
  zzassert(!zzdomain->isType(idf), "expecting type to be undefined");
  int id = zzaddTypeToDomain(zzdomain, idf);
  zzassert(id >= 0,"expecting id >= 0");
  zzassert(zztypeName==NULL,"expecting zztypeName==NULL");
  zztypeName = new char[strlen(idf)+1];
  strcpy(zztypeName, idf);
  delete [] idf;
}
#line 1793 "fol.cpp"
    break;

  case 36: /* is_variable_type: ZZ_TYPE  */
#line 368 "../src/parser/fol.y"
{
  const char* idf = zztokenList.removeLast();
  if (folDbg >= 1) printf("type t_%s ", idf);
  zzassert(zzdomain->isType(idf),"expecting type to be defined");
  //zzwarn("Type %s has been declared before.",idf);
  zzassert(zztypeName==NULL,"expecting zztypeName==NULL");
  zztypeName = new char[strlen(idf)+1];
  strcpy(zztypeName, idf);
  delete [] idf;
}
#line 1808 "fol.cpp"
    break;

  case 38: /* $@7: %empty  */
#line 387 "../src/parser/fol.y"
  { if (folDbg >= 2) printf("constant_declarations: ZZ_VARIABLE\n"); }
#line 1814 "fol.cpp"
    break;

  case 39: /* constant_declarations: constant_declarations constant_sep $@7 variable_or_string_or_constant  */
#line 389 "../src/parser/fol.y"
  {
    const char* vsc = zztokenList.removeLast();
    if (folDbg >= 1) printf("cd_%s ", vsc);
    zzaddConstantToDomain(vsc, zztypeName);
    delete [] vsc;
  }
#line 1825 "fol.cpp"
    break;

  case 44: /* constant_sep: ','  */
#line 406 "../src/parser/fol.y"
       { zzconsumeToken(zztokenList, ","); }
#line 1831 "fol.cpp"
    break;

  case 45: /* constant_sep: '\n' ',' '\n'  */
#line 409 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"\n");
    zzconsumeToken(zztokenList,",");
    zzconsumeToken(zztokenList,"\n");
  }
#line 1841 "fol.cpp"
    break;

  case 46: /* constant_sep: '\n' ','  */
#line 416 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"\n");
    zzconsumeToken(zztokenList,",");
  }
#line 1850 "fol.cpp"
    break;

  case 47: /* constant_sep: ',' '\n'  */
#line 422 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,",");
    zzconsumeToken(zztokenList,"\n");
  }
#line 1859 "fol.cpp"
    break;

  case 48: /* $@8: %empty  */
#line 432 "../src/parser/fol.y"
{
  if (folDbg >= 2) printf("numeric_type_declarations: \n");
  zzconsumeToken(zztokenList,"=");
  zzconsumeToken(zztokenList,"{");
}
#line 1869 "fol.cpp"
    break;

  case 49: /* $@9: %empty  */
#line 438 "../src/parser/fol.y"
{
  const char* numStr = zztokenList.removeLast();
  if (folDbg >= 1) printf(" %s ", numStr);

  double d = atof(numStr);
  zzinitialNumDeclaration = int(d);
  if (d != zzinitialNumDeclaration) zzerr("constant %s must be an integer", numStr);

  char constStr[100];
  zzcreateIntConstant(constStr, zztypeName, zzinitialNumDeclaration);
  zzaddConstantToDomain(constStr, zztypeName);

  delete [] numStr;
}
#line 1888 "fol.cpp"
    break;

  case 50: /* $@10: %empty  */
#line 453 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList, ",");
}
#line 1896 "fol.cpp"
    break;

  case 51: /* numeric_type_declaration: is_variable_type '=' '{' $@8 ZZ_NUM $@9 ',' $@10 numeric_types '}'  */
#line 458 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList, "}");
}
#line 1904 "fol.cpp"
    break;

  case 52: /* numeric_types: ZZ_DOTDOTDOT ',' ZZ_NUM  */
#line 465 "../src/parser/fol.y"
{
  //const char* numStr1 = zztokenList.removeLast();
  zzconsumeToken(zztokenList, "...");
  zzconsumeToken(zztokenList, ",");
  const char* numStr2 = zztokenList.removeLast();
  if (folDbg >= 1) printf("= ... , %s } ", numStr2);

  double d2 = atof(numStr2);
  int i2 = int(d2);
  if (d2 != i2) zzerr("constant %s must be an integer", numStr2);
  if (zzinitialNumDeclaration > i2)
    zzerr("first constant cannot be larger than last constant %s", numStr2);

  for (int i = zzinitialNumDeclaration + 1; i <= i2; i++)
  {
    char constStr[100];
    zzcreateIntConstant(constStr, zztypeName, i);
    zzaddConstantToDomain(constStr, zztypeName);
  }

  delete [] numStr2; delete [] zztypeName;
  zztypeName = NULL;
}
#line 1932 "fol.cpp"
    break;

  case 53: /* numeric_types: single_numeric_types  */
#line 490 "../src/parser/fol.y"
{
  delete [] zztypeName;
  zztypeName = NULL;
}
#line 1941 "fol.cpp"
    break;

  case 54: /* $@11: %empty  */
#line 500 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, ",");
    if (folDbg >= 1) printf(", ");
    if (folDbg >= 2) printf("single_numeric_types: single_numeric_type\n");
  }
#line 1951 "fol.cpp"
    break;

  case 57: /* single_numeric_type: ZZ_NUM  */
#line 511 "../src/parser/fol.y"
{
  const char* numStr = zztokenList.removeLast();
  if (folDbg >= 1) printf(" %s ", numStr);

  double d = atof(numStr);
  int i = int(d);
  if (d != i) zzerr("constant %s must be an integer", numStr);

  char constStr[100];
  zzcreateIntConstant(constStr, zztypeName, i);
  zzaddConstantToDomain(constStr, zztypeName);

  delete [] numStr;
}
#line 1970 "fol.cpp"
    break;

  case 58: /* $@12: %empty  */
#line 535 "../src/parser/fol.y"
{
  const char* predName = zztokenList.removeLast();

  if (folDbg >= 1) printf("ZZ_PREDICATE pc_%s ", predName);
    //predicate has not been declared a function
  zzassert(zzdomain->getFunctionId(predName) < 0,
           "not expecting pred name to be declared as a function name");
  zzassert(zzpredTemplate==NULL,"expecting zzpredTemplate==NULL");
  zzpredTemplate = new PredicateTemplate();
  zzpredTemplate->setName(predName);
  delete [] predName;
}
#line 1987 "fol.cpp"
    break;

  case 59: /* $@13: %empty  */
#line 547 "../src/parser/fol.y"
       { if (folDbg >= 1) printf("( "); zzconsumeToken(zztokenList,"("); }
#line 1993 "fol.cpp"
    break;

  case 60: /* $@14: %empty  */
#line 548 "../src/parser/fol.y"
       { if (folDbg >= 2) printf("predicate_declaration: types\n"); }
#line 1999 "fol.cpp"
    break;

  case 61: /* predicate_declaration: ZZ_VARIABLE $@12 '(' $@13 types $@14 ')'  */
#line 550 "../src/parser/fol.y"
{
  if (folDbg >= 1) printf(") ");

  zzconsumeToken(zztokenList,")");

  zzassert(zzpredTemplate, "not expecting zzpredTemplate==NULL");
  int id = zzdomain->addPredicateTemplate(zzpredTemplate);
  zzassert(id >= 0, "expecting pred template id >= 0");
  zzpredTemplate->setId(id);
  zzpredTemplate = NULL;
}
#line 2015 "fol.cpp"
    break;

  case 62: /* predicate_declaration: ZZ_VARIABLE  */
#line 563 "../src/parser/fol.y"
{
  const char* predName = zztokenList.removeLast();

  if (folDbg >= 1) printf("ZZ_PREDICATE pc_%s ", predName);
    //predicate has not been declared a function
  zzassert(zzdomain->getFunctionId(predName) < 0,
           "not expecting pred name to be declared as a function name");
  zzassert(zzpredTemplate==NULL,"expecting zzpredTemplate==NULL");
  zzpredTemplate = new PredicateTemplate();
  zzpredTemplate->setName(predName);
  delete [] predName;

  // Declare this predicate to have type "AlchemyPropositionalType"
  const char* varName = Domain::PROPOSITIONAL_TYPE;
  if (folDbg >= 1) printf("t_%s ", varName);
  if (!zzdomain->isType(varName))
  {
    int id = zzaddTypeToDomain(zzdomain, varName);
    zzassert(id >= 0, "expecting var id >= 0");
  }
  zzaddType(varName, zzpredTemplate, NULL, false, zzdomain);

  zzassert(zzpredTemplate, "not expecting zzpredTemplate==NULL");
  int templateId = zzdomain->addPredicateTemplate(zzpredTemplate);
  zzassert(templateId >= 0, "expecting pred template id >= 0");
  zzpredTemplate->setId(templateId);
  zzpredTemplate = NULL;
}
#line 2048 "fol.cpp"
    break;

  case 63: /* $@15: %empty  */
#line 599 "../src/parser/fol.y"
{
  const char* retTypeName = zztokenList.removeLast();
  if (folDbg >= 1) printf("ZZ_FUNCTION t_%s ", retTypeName);
  if (folDbg >= 2) printf("function_declaration: ZZ_VARIABLE\n");

  if (!zzdomain->isType(retTypeName))
  {
    int id = zzaddTypeToDomain(zzdomain, retTypeName);
    zzassert(id >= 0, "expecting retTypeName's id >= 0");
  }

  zzassert(zzfuncTemplate==NULL, "expecting zzfuncTemplate==NULL");
  zzfuncTemplate = new FunctionTemplate();
  zzfuncTemplate->setRetTypeName(retTypeName,zzdomain);

  // We are creating a new predicate as well
  zzassert(zzpredTemplate==NULL,"expecting zzpredTemplate==NULL");
  zzpredTemplate = new PredicateTemplate();
  zzaddType(retTypeName, zzpredTemplate, NULL, false, zzdomain);

  delete [] retTypeName;
}
#line 2075 "fol.cpp"
    break;

  case 64: /* $@16: %empty  */
#line 622 "../src/parser/fol.y"
{
  const char* funcName = zztokenList.removeLast();

  if (folDbg >= 1) printf("fc_%s ", funcName);
  zzassert(zzdomain->getPredicateId(funcName) < 0,
           "not expecting func name to be declared as pred name");
  zzfuncTemplate->setName(funcName);

  // Predicate name is PredicateTemplate::ZZ_RETURN_PREFIX + function name
  char* predName;
  predName = (char *)malloc((strlen(PredicateTemplate::ZZ_RETURN_PREFIX) +
                strlen(funcName) + 1)*sizeof(char));
  strcpy(predName, PredicateTemplate::ZZ_RETURN_PREFIX);
  strcat(predName, funcName);

  // Check that predicate has not been declared a function
  zzassert(zzdomain->getFunctionId(predName) < 0,
           "not expecting pred name to be declared as a function name");
  zzassert(zzpredTemplate,"expecting zzpredTemplate!=NULL");
  zzpredTemplate->setName(predName);

  free(predName);
  delete [] funcName;
}
#line 2104 "fol.cpp"
    break;

  case 65: /* $@17: %empty  */
#line 647 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,"(");
  if (folDbg >= 1) printf("( ");
  if (folDbg >= 2) printf("function_declaration: types\n");
}
#line 2114 "fol.cpp"
    break;

  case 66: /* function_declaration: function_return_type $@15 ZZ_VARIABLE $@16 '(' $@17 types ')'  */
#line 653 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,")");
  if (folDbg >= 1) printf(") ");
  zzassert(zzfuncTemplate, "expecting zzfuncTemplate != NULL");
  int id = zzdomain->addFunctionTemplate(zzfuncTemplate);
  zzassert(id >= 0, "expecting function template's id >= 0");
  zzfuncTemplate->setId(id);
  zzfuncTemplate = NULL;

  zzassert(zzpredTemplate, "not expecting zzpredTemplate==NULL");
  // Predicate could already be there
  if (!zzdomain->isPredicate(zzpredTemplate->getName()))
  {
    int predId = zzdomain->addPredicateTemplate(zzpredTemplate);
    zzassert(predId >= 0, "expecting pred template id >= 0");
    zzpredTemplate->setId(predId);
  }
  zzpredTemplate = NULL;

}
#line 2139 "fol.cpp"
    break;

  case 69: /* $@18: %empty  */
#line 682 "../src/parser/fol.y"
  { if (folDbg >= 1) printf(", "); zzconsumeToken(zztokenList,","); }
#line 2145 "fol.cpp"
    break;

  case 71: /* $@19: %empty  */
#line 686 "../src/parser/fol.y"
  { if (folDbg >= 1) printf(", "); zzconsumeToken(zztokenList,","); }
#line 2151 "fol.cpp"
    break;

  case 75: /* $@20: %empty  */
#line 694 "../src/parser/fol.y"
{
  const char* ttype = zztokenList.removeLast();
  if (folDbg >= 1) printf("t_%s ", ttype);
  zzaddType(ttype, zzpredTemplate, NULL, false, zzdomain);
  // If we are in a function definition, then add the type to the function too
  if (zzfuncTemplate)
  zzaddType(ttype, NULL, zzfuncTemplate, false, zzdomain);
  delete [] ttype;
}
#line 2165 "fol.cpp"
    break;

  case 77: /* $@21: %empty  */
#line 706 "../src/parser/fol.y"
{
  const char* varName = zztokenList.removeLast();
  if (folDbg >= 1) printf("t_%s ", varName);
  zzassert(!zzdomain->isType(varName), "expecting varName to be not a type");
  int id = zzaddTypeToDomain(zzdomain, varName);
  zzassert(id >= 0, "expecting var id >= 0");
  zzaddType(varName, zzpredTemplate, NULL, false, zzdomain);
  // If we are in a function definition, then add the type to the function too
  if (zzfuncTemplate)
  zzaddType(varName, NULL, zzfuncTemplate, false, zzdomain);
  delete [] varName;
}
#line 2182 "fol.cpp"
    break;

  case 79: /* exist_unique: %empty  */
#line 722 "../src/parser/fol.y"
  {
  }
#line 2189 "fol.cpp"
    break;

  case 80: /* exist_unique: '!'  */
#line 725 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "!");
    if (folDbg >= 1) printf("! ");
    if (zzfuncTemplate)
      zzerr("'!' cannot be used in a function declaration.");
    zzassert(zzpredTemplate, "'!' used outside a predicate declaration.");

    int termIdx = zzpredTemplate->getNumTerms()-1;
    zzpredTemplate->addUniqueVarIndex(termIdx);
  }
#line 2204 "fol.cpp"
    break;

  case 81: /* pd_not_qs: %empty  */
#line 741 "../src/parser/fol.y"
  {
    zztrueFalseUnknown = 't';
  }
#line 2212 "fol.cpp"
    break;

  case 82: /* pd_not_qs: '!'  */
#line 745 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"!");
    if (folDbg >= 1) printf("! ");
    zztrueFalseUnknown = 'f';
  }
#line 2222 "fol.cpp"
    break;

  case 83: /* pd_not_qs: '?'  */
#line 751 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"?");
    if (folDbg >= 1) printf("? ");
    zztrueFalseUnknown = 'u';
  }
#line 2232 "fol.cpp"
    break;

  case 84: /* $@22: %empty  */
#line 762 "../src/parser/fol.y"
{
  const char* predName = zztokenList.removeLast();
  if (folDbg >= 1) printf("pd_%s ", predName);

  zzcreatePred(zzpred, predName);
  if (zztrueFalseUnknown == 't')      zzpred->setTruthValue(TRUE);
  else if (zztrueFalseUnknown == 'f') zzpred->setTruthValue(FALSE);
  else if (zztrueFalseUnknown == 'u') zzpred->setTruthValue(UNKNOWN);
  else { zzassert(false, "expecting t,f,u"); }

  delete [] predName;
}
#line 2249 "fol.cpp"
    break;

  case 85: /* predicate_definition: ZZ_PREDICATE $@22 nothing_or_constants  */
#line 775 "../src/parser/fol.y"
{
  zzcheckPredNumTerm(zzpred);
  int predId = zzpred->getId();
  hash_map<int,PredicateHashArray*>::iterator it;
  if ((it=zzpredIdToGndPredMap.find(predId)) == zzpredIdToGndPredMap.end())
    zzpredIdToGndPredMap[predId] = new PredicateHashArray;

  if (zzrealValue != NULL)
    zzpred->setRealValue(*zzrealValue);

  PredicateHashArray* pha = zzpredIdToGndPredMap[predId];
  if (pha->append(zzpred) < 0)
  {
    int a = pha->find(zzpred);
    zzassert(a >= 0, "expecting ground predicate to be found");
    string origTvStr = (*pha)[a]->getTruthValueAsStr();
    (*pha)[a]->setTruthValue(zzpred->getTruthValue());
    string newTvStr = (*pha)[a]->getTruthValueAsStr();

    if (zzwarnDuplicates)
    {
      ostringstream oss;
      oss << "Duplicate ground predicate "; zzpred->print(oss, zzdomain);
      oss << " found. ";
      if (origTvStr.compare(newTvStr) != 0)
        oss << "Changed its truthValue from " << origTvStr << " to " <<newTvStr
            << endl;
      zzwarn(oss.str().c_str());
    }
    delete zzpred;
  }
  zzpred = NULL;
}
#line 2287 "fol.cpp"
    break;

  case 86: /* nothing_or_constants: %empty  */
#line 812 "../src/parser/fol.y"
{
  // Add the one constant for propositional case
  const char* constName = Domain::PROPOSITIONAL_CONSTANT;
  if (folDbg >= 1) printf("cg_%s ", constName);
  zzaddConstantToPredFunc(constName);
}
#line 2298 "fol.cpp"
    break;

  case 87: /* $@23: %empty  */
#line 820 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,"(");
  if (folDbg >= 1) printf("( ");
  if (folDbg >= 2) printf("predicate_definition: constants_in_groundings\n");
}
#line 2308 "fol.cpp"
    break;

  case 88: /* $@24: %empty  */
#line 826 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,")");
  if (folDbg >= 1) printf(")\n");
}
#line 2317 "fol.cpp"
    break;

  case 90: /* real_value: ZZ_NUM  */
#line 836 "../src/parser/fol.y"
{
  const char* value = zztokenList.removeLast();
  if (folDbg >= 1) printf("rv_%f ", atof(value));
  if (zzrealValue) delete zzrealValue;
  zzrealValue = new double(atof(value));
  delete [] value;
}
#line 2329 "fol.cpp"
    break;

  case 92: /* $@25: %empty  */
#line 851 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,"=");
  if (folDbg >= 1) printf("= ");
  if (folDbg >= 2) printf("function_definition: constants_in_groundings\n");
}
#line 2339 "fol.cpp"
    break;

  case 93: /* $@26: %empty  */
#line 857 "../src/parser/fol.y"
{
  // Predicate name is PredicateTemplate::ZZ_RETURN_PREFIX + function name
  const char* funcName = zztokenList.removeLast();
  char* predName;
  predName = (char *)malloc((strlen(PredicateTemplate::ZZ_RETURN_PREFIX) +
                strlen(funcName) + 1)*sizeof(char));
  strcpy(predName, PredicateTemplate::ZZ_RETURN_PREFIX);
  strcat(predName, funcName);

  if (folDbg >= 1) printf("pd_%s ", predName);

  zzcreatePred(zzpred, predName);
  zzpred->setTruthValue(TRUE);

  char constName[100];
  char* constString;
  if (zztmpReturnNum)
  {
    zzcreateAndCheckNumConstant(zztmpReturnConstant, zzfunc, zzpred, zzdomain, constName);
    if (constName == NULL)
    {
      constString = (char *)malloc((strlen(zztmpReturnConstant) + 1)*sizeof(char));
      strcpy(constString, zztmpReturnConstant);
    } else
    {
    constString = (char *)malloc((strlen(constName) + 1)*sizeof(char));
      strcpy(constString, constName);
    }
  }
  else
  {
    constString = (char *)malloc((strlen(zztmpReturnConstant) + 1)*sizeof(char));
    strcpy(constString, zztmpReturnConstant);
  }

  //Add return constant parsed earlier
  zzaddConstantToPredFunc(constString);

  zztmpReturnNum = false;
  free(zztmpReturnConstant);
  delete [] funcName;
  free(predName);
  free(constString);
}
#line 2388 "fol.cpp"
    break;

  case 94: /* $@27: %empty  */
#line 902 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,"(");
  if (folDbg >= 1) printf("( ");
  if (folDbg >= 2) printf("function_definition: constants_in_groundings\n");
}
#line 2398 "fol.cpp"
    break;

  case 95: /* function_definition: function_return_constant '=' $@25 ZZ_FUNCTION $@26 '(' $@27 constants_in_groundings ')'  */
#line 908 "../src/parser/fol.y"
{
  zzconsumeToken(zztokenList,")");
  if (folDbg >= 1) printf(")\n");

  zzcheckPredNumTerm(zzpred);
  int predId = zzpred->getId();
  hash_map<int,PredicateHashArray*>::iterator it;
  if ((it=zzpredIdToGndPredMap.find(predId)) == zzpredIdToGndPredMap.end())
    zzpredIdToGndPredMap[predId] = new PredicateHashArray;

  PredicateHashArray* pha = zzpredIdToGndPredMap[predId];
  if (pha->append(zzpred) < 0)
  {
    int a = pha->find(zzpred);
    zzassert(a >= 0, "expecting ground predicate to be found");
    string origTvStr = (*pha)[a]->getTruthValueAsStr();
    (*pha)[a]->setTruthValue(zzpred->getTruthValue());
    string newTvStr = (*pha)[a]->getTruthValueAsStr();

    if (zzwarnDuplicates)
    {
      ostringstream oss;
      oss << "Duplicate ground predicate "; zzpred->print(oss, zzdomain);
      oss << " found. ";
      if (origTvStr.compare(newTvStr) != 0)
        oss << "Changed its truthValue from " << origTvStr << " to " <<newTvStr
            << endl;
      zzwarn(oss.str().c_str());
    }
    //delete zzpred;
  }

  // Insert FALSE for all other return values

  zzpred = NULL;
}
#line 2439 "fol.cpp"
    break;

  case 96: /* constants_in_groundings: is_constant_string_num_variable  */
#line 948 "../src/parser/fol.y"
  {
    const char* constName = zztokenList.removeLast();
    if (folDbg >= 1) printf("cg_%s ", constName);
    zzaddConstantToPredFunc(constName);
    delete [] constName;
  }
#line 2450 "fol.cpp"
    break;

  case 97: /* constants_in_groundings: constants_in_groundings constant_sep is_constant_string_num_variable  */
#line 956 "../src/parser/fol.y"
  {
    const char* constName = zztokenList.removeLast();
    if (folDbg >= 1) printf("cg_%s ", constName);
    zzaddConstantToPredFunc(constName);
    delete [] constName;
  }
#line 2461 "fol.cpp"
    break;

  case 99: /* is_constant_string_num_variable: ZZ_STRING  */
#line 967 "../src/parser/fol.y"
  {
    if (zzconstantMustBeDeclared)
      zzerr("Constant %s must be declared before it is used.",
            zztokenList.back());
  }
#line 2471 "fol.cpp"
    break;

  case 100: /* is_constant_string_num_variable: ZZ_NUM  */
#line 973 "../src/parser/fol.y"
  {
    const char* intStr = zztokenList.removeLast();
    char constName[100];
    zzcreateAndCheckNumConstant(intStr, zzfunc, zzpred, zzdomain, constName);
    if (constName == NULL) zztokenList.addLast(intStr);
    else                   zztokenList.addLast(constName);
    delete [] intStr;
  }
#line 2484 "fol.cpp"
    break;

  case 101: /* is_constant_string_num_variable: ZZ_VARIABLE  */
#line 982 "../src/parser/fol.y"
  {
    if (zzconstantMustBeDeclared)
      zzerr("Constant %s must be declared before it is used",
            zztokenList.back());
  }
#line 2494 "fol.cpp"
    break;

  case 102: /* function_return_constant: ZZ_CONSTANT  */
#line 990 "../src/parser/fol.y"
  {
    const char* tmp = zztokenList.removeLast();
  zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    strcpy(zztmpReturnConstant, tmp);
    zztmpReturnNum = false;
    delete []tmp;
    if (folDbg >= 1) printf("ic_%s ", zztmpReturnConstant);
  }
#line 2507 "fol.cpp"
    break;

  case 103: /* function_return_constant: ZZ_STRING  */
#line 999 "../src/parser/fol.y"
  {
    if (zzconstantMustBeDeclared)
      zzerr("Constant %s must be declared before it is used.",
            zztokenList.back());
    const char* tmp = zztokenList.removeLast();
  zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    strcpy(zztmpReturnConstant, tmp);
    zztmpReturnNum = false;
    delete []tmp;
    if (folDbg >= 1) printf("ic_%s ", zztmpReturnConstant);
  }
#line 2523 "fol.cpp"
    break;

  case 104: /* function_return_constant: ZZ_NUM  */
#line 1011 "../src/parser/fol.y"
  {
    const char* tmp = zztokenList.removeLast();
    zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    strcpy(zztmpReturnConstant, tmp);
    zztmpReturnNum = true;
    delete []tmp;
    if (folDbg >= 1) printf("icnum_%s ", zztmpReturnConstant);
  }
#line 2536 "fol.cpp"
    break;

  case 105: /* function_return_constant: ZZ_VARIABLE  */
#line 1020 "../src/parser/fol.y"
  {
    if (zzconstantMustBeDeclared)
      zzerr("Constant %s must be declared before it is used",
            zztokenList.back());
    const char* tmp = zztokenList.removeLast();
  zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    strcpy(zztmpReturnConstant, tmp);
    zztmpReturnNum = false;
    delete []tmp;
    if (folDbg >= 1) printf("ic_%s ", zztmpReturnConstant);
  }
#line 2552 "fol.cpp"
    break;

  case 107: /* $@28: %empty  */
#line 1038 "../src/parser/fol.y"
  {
    const char* wt = zztokenList.removeLast();
    if (folDbg >= 1) printf("n_%f ", atof(wt));
    if (zzwt) delete zzwt;
    zzwt = new double(atof(wt));
    delete [] wt;
  }
#line 2564 "fol.cpp"
    break;

  case 110: /* weight_fullstop: '.'  */
#line 1052 "../src/parser/fol.y"
{
  if (folDbg >= 1) printf("."); zzconsumeToken(zztokenList,".");
  zzassert(!zzhasWeightFullStop, "expecting no full stop");
  zzhasWeightFullStop = true;
  zzformulaStr.append(".");
}
#line 2575 "fol.cpp"
    break;

  case 112: /* $@29: %empty  */
#line 1063 "../src/parser/fol.y"
{
  if (folDbg >= 1) printf(":"); zzconsumeToken(zztokenList,":");
//  zzassert(!zzhasUtility, "expecting no utility");
//  zzhasUtility = true;
  zzformulaStr.append(":");
}
#line 2586 "fol.cpp"
    break;

  case 113: /* utility: ':' $@29 ZZ_NUM  */
#line 1070 "../src/parser/fol.y"
  {
    const char* util = zztokenList.removeLast();
    if (folDbg >= 1) printf("n_%f ", atof(util));
    if (zzutil) delete zzutil;
    zzutil = new double(atof(util));
    delete [] util;
  }
#line 2598 "fol.cpp"
    break;

  case 114: /* $@30: %empty  */
#line 1082 "../src/parser/fol.y"
  {
      // Square Brackets
    zzconsumeToken(zztokenList,"[");
    if (folDbg >= 1) printf("[ ");
    if (folDbg >= 2) printf("sentence: '[' sentence\n");
    zzformulaStr.append("[");
    zzinIndivisible = true;
  }
#line 2611 "fol.cpp"
    break;

  case 115: /* sentence: '[' $@30 sentence ']'  */
#line 1092 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"]");
    if (folDbg >= 1) printf("] ");
    zzformulaStr.append("]");
    //zzinIndivisible = false;
  }
#line 2622 "fol.cpp"
    break;

  case 116: /* $@31: %empty  */
#line 1100 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"(");
    if (folDbg >= 1) printf("( ");
    if (folDbg >= 2) printf("sentence: '(' sentence\n");
    zzformulaStr.append("(");
  }
#line 2633 "fol.cpp"
    break;

  case 117: /* sentence: '(' $@31 sentence ')'  */
#line 1108 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,")");
    if (folDbg >= 1) printf(") ");
    zzformulaStr.append(")");
  }
#line 2643 "fol.cpp"
    break;

  case 118: /* $@32: %empty  */
#line 1114 "../src/parser/fol.y"
  { if (folDbg >= 2) printf("sentence: atomic_sentence\n"); }
#line 2649 "fol.cpp"
    break;

  case 120: /* $@33: %empty  */
#line 1118 "../src/parser/fol.y"
  {
    const char* imp = zztokenList.removeLast();
    if (folDbg >= 1) printf("=> ");
    zzformulaStr.append(" => ");
    delete [] imp;
  }
#line 2660 "fol.cpp"
    break;

  case 121: /* sentence: sentence ZZ_IMPLY $@33 optnewline sentence  */
#line 1126 "../src/parser/fol.y"
  { zzcreateListObjFromTopTwo(zzformulaListObjs, "=>"); }
#line 2666 "fol.cpp"
    break;

  case 122: /* $@34: %empty  */
#line 1130 "../src/parser/fol.y"
  {
    const char* eq = zztokenList.removeLast();
    if (folDbg >= 1) printf("<=> ");
    zzformulaStr.append(" <=> ");
    delete [] eq;
  }
#line 2677 "fol.cpp"
    break;

  case 123: /* sentence: sentence ZZ_EQUIV $@34 optnewline sentence  */
#line 1138 "../src/parser/fol.y"
  { zzcreateListObjFromTopTwo(zzformulaListObjs, "<=>"); }
#line 2683 "fol.cpp"
    break;

  case 124: /* $@35: %empty  */
#line 1142 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"v");
    if (folDbg >= 1) printf("v ");
    zzformulaStr.append(" v ");
  }
#line 2693 "fol.cpp"
    break;

  case 125: /* sentence: sentence 'v' $@35 optnewline sentence  */
#line 1149 "../src/parser/fol.y"
  { zzcreateListObjFromTopTwo(zzformulaListObjs, "v"); }
#line 2699 "fol.cpp"
    break;

  case 126: /* $@36: %empty  */
#line 1153 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"^");
    if (folDbg >= 1) printf("^ ");
    zzformulaStr.append(" ^ ");
  }
#line 2709 "fol.cpp"
    break;

  case 127: /* sentence: sentence '^' $@36 optnewline sentence  */
#line 1160 "../src/parser/fol.y"
  { zzcreateListObjFromTopTwo(zzformulaListObjs, "^"); }
#line 2715 "fol.cpp"
    break;

  case 128: /* $@37: %empty  */
#line 1164 "../src/parser/fol.y"
  { if (folDbg >= 2) printf("sentence: quantifier\n"); }
#line 2721 "fol.cpp"
    break;

  case 129: /* $@38: %empty  */
#line 1166 "../src/parser/fol.y"
  {
    if (folDbg >= 2) printf("sentence: variables\n");
    zzformulaListObjs.push(new ListObj);
    pair<StringToStringMap*,int> pr(new StringToStringMap,zzscopeCounter++);
    zzoldNewVarList.push_front(pr);
  }
#line 2732 "fol.cpp"
    break;

  case 130: /* $@39: %empty  */
#line 1172 "../src/parser/fol.y"
              { if (folDbg >= 2) printf("sentence: sentence\n"); }
#line 2738 "fol.cpp"
    break;

  case 131: /* sentence: $@37 quantifier $@38 variables $@39 sentence  */
#line 1174 "../src/parser/fol.y"
  {
    zzcreateListObjFromTopThree(zzformulaListObjs);
    pair<StringToStringMap*, int> pr = zzoldNewVarList.front();
    zzoldNewVarList.pop_front();
    delete pr.first;
  }
#line 2749 "fol.cpp"
    break;

  case 132: /* $@40: %empty  */
#line 1183 "../src/parser/fol.y"
  {
    zzassert(!zzisNegated,"expecting !zzisNegated");
    zzisNegated = true;

    zzconsumeToken(zztokenList,"!");
    if (folDbg >= 1) printf("! ");
    if (folDbg >= 2) printf("sentence: sentence\n");
    zzformulaStr.append("!");
  }
#line 2763 "fol.cpp"
    break;

  case 133: /* sentence: '!' $@40 sentence  */
#line 1193 "../src/parser/fol.y"
  { zzcreateListObjFromTop(zzformulaListObjs, "!"); }
#line 2769 "fol.cpp"
    break;

  case 134: /* quantifier: ZZ_FORALL  */
#line 1199 "../src/parser/fol.y"
  {
    const char* fa = zztokenList.removeLast();
    if (folDbg >= 1) printf("FORALL ");
    zzformulaListObjs.push(new ListObj("FORALL"));
    zzformulaStr.append("FORALL ");
    delete [] fa;
  }
#line 2781 "fol.cpp"
    break;

  case 135: /* quantifier: ZZ_EXIST  */
#line 1207 "../src/parser/fol.y"
  {
    const char* ex = zztokenList.removeLast();
    if (folDbg >= 1) printf("EXIST ");
    zzformulaListObjs.push(new ListObj("EXIST"));
    zzformulaStr.append("EXIST ");
    delete [] ex;
  }
#line 2793 "fol.cpp"
    break;

  case 136: /* $@41: %empty  */
#line 1219 "../src/parser/fol.y"
  { if (folDbg >= 2) printf("variables: variables\n"); }
#line 2799 "fol.cpp"
    break;

  case 137: /* $@42: %empty  */
#line 1221 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,",");
    if (folDbg >= 1) printf(", ");
    zzformulaStr.append(",");
  }
#line 2809 "fol.cpp"
    break;

  case 139: /* variables: quant_variable  */
#line 1228 "../src/parser/fol.y"
                  { zzformulaStr.append(" "); }
#line 2815 "fol.cpp"
    break;

  case 140: /* quant_variable: ZZ_VARIABLE  */
#line 1233 "../src/parser/fol.y"
{
  const char* varName = zztokenList.removeLast();
  if (folDbg >= 1) printf("v_%s ", varName);

  //if (isupper(varName[0]))
  if (zzisConstant(varName))
  {
    zzerr("Variable %s must be begin with a lowercase character.", varName);
    ((char*)varName)[0] = tolower(varName[0]);
  }

  int scopeNum = zzoldNewVarList.front().second;
  string newVarName = zzappend(varName,scopeNum);

  StringToStringMap* oldNewVarMap = zzoldNewVarList.front().first;
  (*oldNewVarMap)[varName]=newVarName;
  zzvarNameToIdMap[newVarName] = ZZVarIdType(--zzvarCounter, zzanyTypeId);
  zzformulaListObjs.top()->append(newVarName.c_str());
  zzformulaStr.append(varName); //use the old var name in the orig string
  delete [] varName;
}
#line 2841 "fol.cpp"
    break;

  case 141: /* $@43: %empty  */
#line 1259 "../src/parser/fol.y"
  {
    const char* predName = zztokenList.removeLast();
    if (folDbg >= 1) printf("p_%s ", predName);

    zzfdnumPreds++;
    ListObj* predlo = new ListObj;

  if (PredicateTemplate::isInternalPredicateTemplateName(predName))
  {
    //zzinfixPredName is misused here to store internal pred. name
    zzinfixPredName = (char *)malloc((strlen(predName)
                        + 1)*sizeof(char));
    strcpy(zzinfixPredName, predName);
    const PredicateTemplate* t = zzdomain->getEmptyPredicateTemplate();
      zzassert(zzpred == NULL,"expecting zzpred==NULL");
      zzpred = new Predicate(t);
      predlo->append(PredicateTemplate::EMPTY_NAME);
  }
  else
  {
      zzcreatePred(zzpred, predName);
      predlo->append(predName);
  }

    zzformulaStr.append(predName);
    if(zzisNegated)  { zzpred->setSense(false); zzisNegated = false; }
    zzpredFuncListObjs.push(predlo);
    delete [] predName;
  }
#line 2875 "fol.cpp"
    break;

  case 143: /* $@44: %empty  */
#line 1291 "../src/parser/fol.y"
  {
    ++zzfdnumPreds;
    //zzfdisEqualPred = true;
    //const PredicateTemplate* t = zzdomain->getEqualPredicateTemplate();
    const PredicateTemplate* t = zzdomain->getEmptyPredicateTemplate();

    zzassert(zzpred == NULL, "expecting zzpred==NULL");
    zzpred = new Predicate(t);

    ListObj* predlo = new ListObj;
    //predlo->append(PredicateTemplate::EQUAL_NAME);
    predlo->append(PredicateTemplate::EMPTY_NAME);
    zzpredFuncListObjs.push(predlo);
    if (zzisNegated)  { zzpred->setSense(false); zzisNegated = false; }

    if (folDbg >= 2) printf("atomic_sentence (left): term\n");
  }
#line 2897 "fol.cpp"
    break;

  case 144: /* $@45: %empty  */
#line 1310 "../src/parser/fol.y"
  {
    ListObj* predlo = zzpredFuncListObjs.top();
    predlo->replace(PredicateTemplate::EMPTY_NAME, zzinfixPredName);

      // If type known from LHS, then set the pred types accordingly
    int lTypeId = zzgetTypeId(zzpred->getTerm(0), (*predlo)[1]->getStr());
    if (lTypeId > 0)
    {
      if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
      {
        zzsetEqPredTypeName(lTypeId);
      }
      else
    {
      zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
    }
    }
  }
#line 2920 "fol.cpp"
    break;

  case 145: /* atomic_sentence: $@44 term internal_predicate_sign $@45 term  */
#line 1329 "../src/parser/fol.y"
  {
    ListObj* predlo = zzpredFuncListObjs.top();
    //predlo->replace(PredicateTemplate::EMPTY_NAME, zzinfixPredName);

  // types are possibly unknown
  // If '=' predicate then types are possibly unknown
  //if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0) {
      int lTypeId = zzgetTypeId(zzpred->getTerm(0), (*predlo)[1]->getStr());
      int rTypeId = zzgetTypeId(zzpred->getTerm(1), (*predlo)[2]->getStr());

      if (lTypeId > 0 && rTypeId > 0) //if both types are known
      {
        if (lTypeId != rTypeId)
          zzerr("The types on the left and right of '=' must match.");
        if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
        {
        zzsetEqPredTypeName(lTypeId);
      }
      else
      {
        zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
      }
      }
      else  // if only one type is known
      if ( (lTypeId<=0 && rTypeId>0) || (lTypeId>0 && rTypeId<=0) )
      {
        int knownTypeId = (lTypeId>0) ? lTypeId : rTypeId;
        if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
        {
          zzsetEqPredTypeName(knownTypeId);
        }
        else
      {
        zzsetInternalPredTypeName(zzinfixPredName, knownTypeId);
      }
        const char* lvarName = (*predlo)[1]->getStr();
        const char* rvarName = (*predlo)[2]->getStr();
        const char* unknownVarName = (lTypeId>0) ?  rvarName : lvarName;
        zzvarNameToIdMap[unknownVarName].typeId_ = knownTypeId;
      }
      else // if both types are unknown
      {
          //both sides must be variables
        const char* lvarName = (*predlo)[1]->getStr();
        const char* rvarName = (*predlo)[2]->getStr();
        lTypeId = zzgetVarTypeId(lvarName);
        rTypeId = zzgetVarTypeId(rvarName);

        if (lTypeId > 0 && rTypeId > 0) //if both types are known
        {
          if (lTypeId != rTypeId)
            zzerr("The types of %s and %s on the left and right of "
                   "'=' must match.", lvarName, rvarName);
          if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
          {
            zzsetEqPredTypeName(lTypeId);
          }
          else
        {
          zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
        }
        }
        else  // if only one type is known
        if ( (lTypeId <= 0 && rTypeId > 0) || (lTypeId > 0 && rTypeId <= 0) )
        {
          int knownTypeId = (lTypeId > 0) ? lTypeId : rTypeId;
          if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME) == 0)
          {
            zzsetEqPredTypeName(knownTypeId);
          }
          else
        {
          zzsetInternalPredTypeName(zzinfixPredName, knownTypeId);
        }
          const char* unknowVarName = (lTypeId>0) ?  rvarName : lvarName;
          zzvarNameToIdMap[unknowVarName].typeId_ = knownTypeId;
        }
        else
        {
      if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
          {
            string unknownEqName = zzappend(PredicateTemplate::EQUAL_NAME,
                                          zzeqTypeCounter++);
            zzeqPredList.push_back(ZZUnknownEqPredInfo(unknownEqName,lvarName,
                                                       rvarName));
            predlo->replace(PredicateTemplate::EQUAL_NAME, unknownEqName.c_str());
          }
          else
          {
            string unknownIntPredName =
              zzappendWithUnderscore(zzinfixPredName, zzintPredTypeCounter++);
            zzintPredList.push_back(ZZUnknownIntPredInfo(unknownIntPredName, lvarName,
                                                         rvarName));
            predlo->replace(zzinfixPredName, unknownIntPredName.c_str());
          }
        }
      }
  //}
  //else // Infix predicate other than '='
  //{
    //Only left term could be unknown
    //const char* leftTerm = (*predlo)[1]->getStr();
  //}

    zzassert(zzpredFuncListObjs.size()==1,
             "expecting zzpredFuncListObjs.size()==1");
    ListObj* topPredlo = zzpredFuncListObjs.top();
    zzpredFuncListObjs.pop();
    zzformulaListObjs.push(topPredlo);
      // This allows for the '!=' operator
    if (zzisNegated)
    {
      zzcreateListObjFromTop(zzformulaListObjs, "!");
      zzisNegated = false;
    }

  delete zzpred;
  zzpred = NULL;

  // If we have replaced a function inside the predicate
  // then we have to add the conjunction
  while (!zzfuncConjStack.empty())
  {
    // create the second part of the conjunction
    //zzformulaStr.append(" ^ ");

      ListObj* topPredlo = zzfuncConjStack.top();
    zzfuncConjStack.pop();
      //zzformulaListObjs.push(topPredlo);
    //zzcreateListObjFromTopTwo(zzformulaListObjs, "^");
    zzformulaListObjs.push(topPredlo);
    zzcreateListObjFromTopTwo(zzformulaListObjs, "v");
  } //while (!zzfuncConjStack.empty())

  if (!zzfuncConjStr.empty())
  {
    zzformulaStr.append(zzfuncConjStr);
    zzfuncConjStr.clear();
  }
  zzfunc = NULL;
  free(zzinfixPredName);
    zzinfixPredName = NULL;
  }
#line 3068 "fol.cpp"
    break;

  case 146: /* nothing_or_terms: %empty  */
#line 1476 "../src/parser/fol.y"
  {
  // Add the one constant for propositional case
    const char* constName = Domain::PROPOSITIONAL_CONSTANT;
    if (folDbg >= 1) printf("c2_%s ", constName);
    zztermIsConstant(constName, constName, false);

    zzcheckPredNumTerm(zzpred);
    delete zzpred;
    zzpred = NULL;
    if (!zzisHybrid)
    {
      zzassert(zzpredFuncListObjs.size()==1,
               "expecting zzpredFuncListObjs.size()==1");
      ListObj* predlo = zzpredFuncListObjs.top();
      zzpredFuncListObjs.pop();
      zzformulaListObjs.push(predlo);
    }
  }
#line 3091 "fol.cpp"
    break;

  case 147: /* $@46: %empty  */
#line 1496 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "(");
    if (folDbg >= 1) printf("( ");
    if (folDbg >= 2) printf("atomic_sentence: terms\n");
    zzformulaStr.append("(");
    //if (zzisHybrid) zzcontinuousStr.append("(");
  }
#line 3103 "fol.cpp"
    break;

  case 148: /* nothing_or_terms: '(' $@46 terms ')'  */
#line 1505 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, ")");
    if (folDbg >= 1) printf(") ");

    //If an internal pred., then need to determine type
    //zzinfixPredName is misused here to store internal pred. name
  if (zzinfixPredName)
  {
    ListObj* predlo = zzpredFuncListObjs.top();
      predlo->replace(PredicateTemplate::EMPTY_NAME, zzinfixPredName);
    // types are possibly unknown
    // If '=' predicate then types are possibly unknown
    //if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0) {
      int lTypeId = zzgetTypeId(zzpred->getTerm(0), (*predlo)[1]->getStr());
      int rTypeId = zzgetTypeId(zzpred->getTerm(1), (*predlo)[2]->getStr());

      if (lTypeId > 0 && rTypeId > 0) //if both types are known
      {
        if (lTypeId != rTypeId)
          zzerr("The types on the left and right of '=' must match.");
        if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
        {
        zzsetEqPredTypeName(lTypeId);
      }
      else
      {
        zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
      }
      }
      else  // if only one type is known
      if ( (lTypeId<=0 && rTypeId>0) || (lTypeId>0 && rTypeId<=0) )
      {
        int knownTypeId = (lTypeId>0) ? lTypeId : rTypeId;
        if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
        {
          zzsetEqPredTypeName(knownTypeId);
        }
        else
      {
        zzsetInternalPredTypeName(zzinfixPredName, knownTypeId);
      }
        const char* lvarName = (*predlo)[1]->getStr();
        const char* rvarName = (*predlo)[2]->getStr();
        const char* unknownVarName = (lTypeId>0) ?  rvarName : lvarName;
        zzvarNameToIdMap[unknownVarName].typeId_ = knownTypeId;
      }
      else // if both types are unknown
      {
          //both sides must be variables
        const char* lvarName = (*predlo)[1]->getStr();
        const char* rvarName = (*predlo)[2]->getStr();
        lTypeId = zzgetVarTypeId(lvarName);
        rTypeId = zzgetVarTypeId(rvarName);

        if (lTypeId > 0 && rTypeId > 0) //if both types are known
        {
          if (lTypeId != rTypeId)
            zzerr("The types of %s and %s on the left and right of "
                   "'=' must match.", lvarName, rvarName);
          if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
          {
            zzsetEqPredTypeName(lTypeId);
          }
          else
        {
          zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
        }
        }
        else  // if only one type is known
        if ( (lTypeId<=0 && rTypeId>0) || (lTypeId>0 && rTypeId<=0) )
        {
          int knownTypeId = (lTypeId>0) ? lTypeId : rTypeId;
          if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
          {
            zzsetEqPredTypeName(knownTypeId);
          }
          else
        {
          zzsetInternalPredTypeName(zzinfixPredName, knownTypeId);
        }
          const char* unknowVarName = (lTypeId>0) ?  rvarName : lvarName;
          zzvarNameToIdMap[unknowVarName].typeId_ = knownTypeId;
        }
        else
        {
      if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
          {
            string unknownEqName = zzappend(PredicateTemplate::EQUAL_NAME,
                                          zzeqTypeCounter++);
            zzeqPredList.push_back(ZZUnknownEqPredInfo(unknownEqName,lvarName,
                                                       rvarName));
            predlo->replace(PredicateTemplate::EQUAL_NAME, unknownEqName.c_str());
          }
          else
          {
            string unknownIntPredName =
              zzappendWithUnderscore(zzinfixPredName, zzintPredTypeCounter++);
            zzintPredList.push_back(ZZUnknownIntPredInfo(unknownIntPredName, lvarName,
                                                         rvarName));
            predlo->replace(zzinfixPredName, unknownIntPredName.c_str());
          }
        }
      }
    free(zzinfixPredName);
      zzinfixPredName = NULL;
  }

    zzcheckPredNumTerm(zzpred);
    delete zzpred;
    zzpred = NULL;

    if (!zzisHybrid)
    {
      zzassert(zzpredFuncListObjs.size()==1,
               "expecting zzpredFuncListObjs.size()==1");
      ListObj* predlo = zzpredFuncListObjs.top();
      zzpredFuncListObjs.pop();

      if (zzisAsterisk)
      {
        zzisAsterisk = false;
        ListObj* lo = new ListObj;
        lo->append("*"); lo->append(predlo);
        zzformulaListObjs.push(lo);
      }
      else
        zzformulaListObjs.push(predlo);
  }
  else
  {

  }
    zzformulaStr.append(")");

  // If we have replaced a function inside the predicate
  // then we have to add the conjunction
  while (!zzfuncConjStack.empty())
  {
    // create the second part of the conjunction
    //zzformulaStr.append(" ^ ");
      ListObj* topPredlo = zzfuncConjStack.top();
      zzfuncConjStack.pop();
      //zzformulaListObjs.push(topPredlo);
      //zzcreateListObjFromTopTwo(zzformulaListObjs, "^");
      zzformulaListObjs.push(topPredlo);
      zzcreateListObjFromTopTwo(zzformulaListObjs, "v");
  } //while (!zzfuncConjStack.empty())

  if (!zzfuncConjStr.empty())
  {
      zzformulaStr.append(zzfuncConjStr);
      zzfuncConjStr.clear();
  }
  zzfunc = NULL;
  }
#line 3263 "fol.cpp"
    break;

  case 149: /* internal_predicate_sign: '>'  */
#line 1664 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, ">");
    if (folDbg >= 1) printf("> ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append(" > ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::GT_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::GT_NAME);
    //zzcreateInternalPredTemplate(zzinfixPredName);
    //const PredicateTemplate* t = zzdomain->getPredicateTemplate(zzinfixPredName);
  //zzpred->setTemplate((PredicateTemplate*)t);
  }
#line 3280 "fol.cpp"
    break;

  case 150: /* internal_predicate_sign: '<'  */
#line 1678 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "<");
    if (folDbg >= 1) printf("< ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append(" < ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::LT_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::LT_NAME);
    //zzcreateInternalPredTemplate(zzinfixPredName);
    //const PredicateTemplate* t = zzdomain->getPredicateTemplate(zzinfixPredName);
  //zzpred->setTemplate((PredicateTemplate*)t);
  }
#line 3297 "fol.cpp"
    break;

  case 151: /* internal_predicate_sign: '>' '='  */
#line 1692 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, ">");
    if (folDbg >= 1) printf(">");
    zzformulaStr.append(" >");
    zzconsumeToken(zztokenList, "=");
    if (folDbg >= 1) printf("= ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append("= ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::GTEQ_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::GTEQ_NAME);
    //zzcreateInternalPredTemplate(zzinfixPredName);
  //const PredicateTemplate* t = zzdomain->getPredicateTemplate(zzinfixPredName);
  //zzpred->setTemplate((PredicateTemplate*)t);
  }
#line 3317 "fol.cpp"
    break;

  case 152: /* internal_predicate_sign: '<' '='  */
#line 1709 "../src/parser/fol.y"
  {
  zzconsumeToken(zztokenList, "<");
    if (folDbg >= 1) printf("<");
    zzformulaStr.append(" <");
    zzconsumeToken(zztokenList, "=");
    if (folDbg >= 1) printf("= ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append("= ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::LTEQ_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::LTEQ_NAME);
    //zzcreateInternalPredTemplate(zzinfixPredName);
    //const PredicateTemplate* t = zzdomain->getPredicateTemplate(zzinfixPredName);
  //zzpred->setTemplate((PredicateTemplate*)t);
  }
#line 3337 "fol.cpp"
    break;

  case 153: /* internal_predicate_sign: '='  */
#line 1726 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "=");
    if (folDbg >= 1) printf("= ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append(" = ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::EQUAL_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::EQUAL_NAME);
    const PredicateTemplate* t = zzdomain->getEqualPredicateTemplate();
  zzpred->setTemplate((PredicateTemplate*)t);
  }
#line 3353 "fol.cpp"
    break;

  case 154: /* internal_predicate_sign: '!' '='  */
#line 1739 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "!");
    zzconsumeToken(zztokenList, "=");
    if (folDbg >= 1) printf("!= ");
    if (folDbg >= 2) printf("atomic_sentence (right): term\n");
    zzformulaStr.append(" != ");
    zzinfixPredName = (char *)malloc((strlen(PredicateTemplate::EQUAL_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixPredName, PredicateTemplate::EQUAL_NAME);
    const PredicateTemplate* t = zzdomain->getEqualPredicateTemplate();
  zzpred->setTemplate((PredicateTemplate*)t);
    // Theoretically, we could have "!(a1 != a2)" which would be "a1 = a2"
    if (zzpred->getSense())
    {
      zzpred->setSense(false);
      zzisNegated = true;
    }
    else { zzpred->setSense(true); }
  }
#line 3377 "fol.cpp"
    break;

  case 156: /* asterisk: '*'  */
#line 1764 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "*");
    if (folDbg >= 1) printf("* ");
    if (zzisNegated) zzerr("'!' and '*' cannot be used at the same time");
    zznumAsterisk++;
    zzassert(!zzisAsterisk,"expecting !zzisAsterisk");
    zzisAsterisk = true;
    zzformulaStr.append("*");
  }
#line 3391 "fol.cpp"
    break;

  case 157: /* $@47: %empty  */
#line 1780 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, ",");
    if (folDbg >= 1) printf(", ");
    if (folDbg >= 2) printf("terms: term\n");
    // While parsing function, we do not want to append anything to the formula
    if (zzfunc == NULL) zzformulaStr.append(",");
  }
#line 3403 "fol.cpp"
    break;

  case 159: /* terms: term  */
#line 1790 "../src/parser/fol.y"
  {
    // After the first term in an internal pred., check if we can determine type
    if (zzpred && zzpred->isEmptyPred() &&
      zzpred->getNumTerms() == 1 && zzinfixPredName)
    {
      ListObj* predlo = zzpredFuncListObjs.top();
      predlo->replace(PredicateTemplate::EMPTY_NAME, zzinfixPredName);

        // If type known from term, then set the pred types accordingly
    int lTypeId = zzgetTypeId(zzpred->getTerm(0), (*predlo)[1]->getStr());
      if (lTypeId>0)
      {
        if (strcmp(zzinfixPredName, PredicateTemplate::EQUAL_NAME)==0)
        {
          zzsetEqPredTypeName(lTypeId);
        }
        else
      {
        zzsetInternalPredTypeName(zzinfixPredName, lTypeId);
      }
      }
    }
  }
#line 3431 "fol.cpp"
    break;

  case 160: /* term: ZZ_CONSTANT  */
#line 1818 "../src/parser/fol.y"
  {
    const char* constName = zztokenList.removeLast();
    if (folDbg >= 1) printf("c2_%s ", constName);
    zztermIsConstant(constName, constName, true);
    if (zzfunc) zzfdfuncConstants.append(string(constName));
    else        zzfdconstName = constName;
    delete [] constName;
  }
#line 3444 "fol.cpp"
    break;

  case 161: /* term: ZZ_STRING  */
#line 1828 "../src/parser/fol.y"
  {
    const char* constName = zztokenList.removeLast();
    if (folDbg >= 1) printf("c2_%s ", constName);
      if (zzconstantMustBeDeclared)
        zzerr("Constant %s must be declared before it is used", constName);
    zztermIsConstant(constName, constName, true);
    if (zzfunc) zzfdfuncConstants.append(string(constName));
    else        zzfdconstName = constName;
    delete [] constName;
  }
#line 3459 "fol.cpp"
    break;

  case 162: /* term: ZZ_NUM  */
#line 1840 "../src/parser/fol.y"
  {
    const char* intStr = zztokenList.removeLast();
    if (folDbg >= 1) printf("c3_%s ", intStr);

    char constName[100];
    zzcreateAndCheckNumConstant(intStr, zzfunc, zzpred, zzdomain, constName);
    if (constName == NULL) { break; delete [] intStr; }

    zztermIsConstant(constName, intStr, true);
    if (zzfunc) zzfdfuncConstants.append(string(constName));
    else        zzfdconstName = constName;
    delete [] intStr;
  }
#line 3477 "fol.cpp"
    break;

  case 163: /* term: ZZ_VARIABLE  */
#line 1855 "../src/parser/fol.y"
  {
    zztermIsVariable(folDbg);
    if (zzisPlus) zzisPlus = false;
  }
#line 3486 "fol.cpp"
    break;

  case 164: /* term: '+' ZZ_VARIABLE  */
#line 1861 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "+");
    if (folDbg >= 1) printf("+ ");
    zzassert(!zzisPlus,"expecting !zzisPlus");
    zzisPlus = true;
    zzformulaStr.append("+");
    zztermIsVariable(folDbg);
    if (zzisPlus) zzisPlus = false;
  }
#line 3500 "fol.cpp"
    break;

  case 165: /* term: function_term  */
#line 1872 "../src/parser/fol.y"
  {
    zzassert(zzfunc != NULL,"expecting zzfunc != NULL");
    zzcheckFuncNumTerm(zzfunc);
    zzassert(zzpred != NULL, "expecting zzpred != NULL");

      // replace function

    // Append Term funcVar<zzfuncVarCounter> to predicate where
      // function appears and set flag to add conjunction

      // 1. Make new variable
    char* varName;
    string newVarName;

      // Check if function mapping already occurs in formula
    ZZFuncToFuncVarMap::iterator mit;
    if ((mit = zzfuncToFuncVarMap.find(zzfunc)) != zzfuncToFuncVarMap.end())
    {
      newVarName = (*mit).second;
      varName = (char *)malloc((strlen(newVarName.c_str()) + 1) * sizeof(char));
      strcpy(varName, newVarName.c_str());
    }
    else
    {
      char funcVarCounterString[10];
      int funcVarCounterLength =
        sprintf(funcVarCounterString, "%d", zzfuncVarCounter);
      varName = (char *)malloc((strlen(ZZ_FUNCVAR_PREFIX) +
                  funcVarCounterLength + 1)*sizeof(char));
      strcpy(varName, ZZ_FUNCVAR_PREFIX);
      strcat(varName, funcVarCounterString);
      ++zzfdnumVars;
      ++zzfuncVarCounter;
      newVarName = zzgetNewVarName(varName);

      Function* func = new Function(*zzfunc);
      zzfuncToFuncVarMap[func] = newVarName;
    }

    bool rightNumTerms = true;
    bool rightType = true;
    int exp, unexp;

      // 2. Create new predicate
      // Predicate name is PredicateTemplate::ZZ_RETURN_PREFIX + function name
  char* predName;
  predName = (char *)malloc((strlen(PredicateTemplate::ZZ_RETURN_PREFIX) +
                     strlen(zzfunc->getName()) + 1)*sizeof(char));
  strcpy(predName, PredicateTemplate::ZZ_RETURN_PREFIX);
  strcat(predName, zzfunc->getName());

  // Only insert predicate declaration, if not yet declared
  if (zzdomain->getPredicateId(predName) < 0)
  {
      zzassert(zzpredTemplate==NULL,"expecting zzpredTemplate==NULL");
      zzpredTemplate = new PredicateTemplate();
      zzpredTemplate->setName(predName);

      // Register the types
      // First parameter is the return type
    const char* ttype = zzfunc->getRetTypeName();
    zzaddType(ttype, zzpredTemplate, NULL, false, zzdomain);

    // Register the parameter types
    for (int i = 0; i < zzfunc->getNumTerms(); i++)
    {
    const char* ttype = zzfunc->getTermTypeAsStr(i);
    zzaddType(ttype, zzpredTemplate, NULL, false, zzdomain);
    }

    zzassert(zzpredTemplate, "not expecting zzpredTemplate==NULL");
    int id = zzdomain->addPredicateTemplate(zzpredTemplate);
    zzassert(id >= 0, "expecting pred template id >= 0");
    zzpredTemplate->setId(id);
    zzpredTemplate = NULL;
  }

  Predicate* prevPred = zzpred;
  zzpred = NULL;
    zzfdnumPreds++;
  zzcreatePred(zzpred, predName);

    ListObj* predlo = new ListObj;
    predlo->append(predName);

  // Put predicate list object in stack to be used in conjunction later
    zzfuncConjStack.push(predlo);
    //zzfuncConjStr.append(" ^ ");
    zzfuncConjStr.append(" v !");
    zzfuncConjStr.append(predName);
  zzfuncConjStr.append("(");
    zzputVariableInPred(varName, folDbg);
    zzfuncConjStack.top()->append(varName);
    zzfuncConjStr.append(varName);

  // Information about the terms is in zzfunc
  for (int i = 0; i < zzfunc->getNumTerms(); i++)
  {
    zzfuncConjStr.append(", ");
    Term* term = new Term(*zzfunc->getTerm(i));
    zzpred->appendTerm(term);

    const char* name;
    if (term->getType() == Term::VARIABLE)
    {
    name = (*zzpredFuncListObjs.top())[i+1]->getStr();
    }
    else if (term->getType() == Term::CONSTANT)
    {
    name = zzdomain->getConstantName(term->getId());
    }
    zzpredFuncListObjs.top()->append(name);
    zzfuncConjStack.top()->append(name);
    zzfuncConjStr.append(name);
  }
  zzfuncConjStr.append(")");
    zzcreateListObjFromTop(zzfuncConjStack, "!");

    // 4. Append new variable to function in stack or to predicate
    if (!zzfuncStack.empty())
    {
      Function* prevFunc = zzfuncStack.top();
    zzfuncStack.pop();

      // check that we have not exceeded the number of terms
      if ((unexp = prevFunc->getNumTerms()) ==
          (exp = prevFunc->getTemplate()->getNumTerms()))
      {
        rightNumTerms = false;
        zzerr("Wrong number of terms for function %s. "
              "Expected %d but given %d", prevFunc->getName(), exp, unexp+1);
      }

      int varId = -1;
      if (rightNumTerms)
      {
        // check that the variable is of the right type
      int typeId = prevFunc->getTermTypeAsInt(prevFunc->getNumTerms());
        rightType = zzcheckRightTypeAndGetVarId(typeId, newVarName.c_str(),
                                              varId);
      }

      if (rightNumTerms && rightType)
      {
      prevFunc->appendTerm(new Term(varId, (void*)prevFunc, false));
      zzpredFuncListObjs.pop();
      zzpredFuncListObjs.top()->append(newVarName.c_str());
      }

      zzfunc = prevFunc;
    }
  else // function stack is empty, so append to predicate
    {
      // check that we have not exceeded the number of terms
      if ((unexp = prevPred->getNumTerms()) ==
          (exp = prevPred->getTemplate()->getNumTerms()))
      {
        rightNumTerms = false;
        zzerr("Wrong number of terms for predicate %s. "
              "Expected %d but given %d", prevPred->getName(), exp, unexp+1);
      }

      int varId = -1;
      if (rightNumTerms)
      {
          // check that the variable is of the right type
        int typeId = prevPred->getTermTypeAsInt(prevPred->getNumTerms());
        rightType = zzcheckRightTypeAndGetVarId(typeId, newVarName.c_str(),
                              varId);
      }

    if (rightNumTerms && rightType)
    {
    prevPred->appendTerm(new Term(varId, (void*)prevPred, true));

      // Pop the function from the stack
      zzoldFuncLo = zzpredFuncListObjs.top();
      zzpredFuncListObjs.pop();
      zzpredFuncListObjs.top()->append(newVarName.c_str());
      zzformulaStr.append(varName);
      }
    zzfunc = NULL;

    }
    free(varName);
  free(predName);
  //zzformulaStr.append(")");

    delete zzpred;
  zzpred = prevPred;
  }
#line 3696 "fol.cpp"
    break;

  case 166: /* $@48: %empty  */
#line 2068 "../src/parser/fol.y"
  {
    const char* funcName = zztokenList.removeLast();
    if (folDbg >= 1) printf("f_%s ", funcName);
    if (zzfunc != NULL) { zzfuncStack.push(zzfunc); zzfunc = NULL; }
    ++zzfdnumFuncs;
    zzfdfuncName = funcName;

    ListObj* funclo = new ListObj;

    // Check if internal function
  if (FunctionTemplate::isInternalFunctionTemplateName(funcName))
  {
    zzinfixFuncName = (char *)malloc((strlen(funcName)
                        + 1)*sizeof(char));
    strcpy(zzinfixFuncName, funcName);
    const FunctionTemplate* t;
    if (FunctionTemplate::isInternalFunctionUnaryTemplateName(funcName))
      t = zzdomain->getEmptyFunctionUnaryTemplate();
    else
      t = zzdomain->getEmptyFunctionBinaryTemplate();
      zzassert(zzfunc == NULL,"expecting zzfunc==NULL");
      zzfunc = new Function(t);
      funclo->append(FunctionTemplate::EMPTY_FTEMPLATE_NAME);
  }
  else
  {
    zzcreateFunc(zzfunc, funcName);
    funclo->append(funcName);
  }

    zzpredFuncListObjs.push(funclo);
    //zzformulaStr.append(funcName);

    delete [] funcName;
  }
#line 3736 "fol.cpp"
    break;

  case 167: /* $@49: %empty  */
#line 2104 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "(");
    if (folDbg >= 1) printf("( ");
    if (folDbg >= 2) printf("term: terms\n");
  }
#line 3746 "fol.cpp"
    break;

  case 168: /* function_term: ZZ_FUNCTION $@48 '(' $@49 terms ')'  */
#line 2110 "../src/parser/fol.y"
  {
      //If an internal func., then need to determine type
  if (zzinfixFuncName)
  {
    ListObj* funclo = zzpredFuncListObjs.top();
      funclo->replace(FunctionTemplate::EMPTY_FTEMPLATE_NAME, zzinfixFuncName);
    const FunctionTemplate* t =
      zzgetGenericInternalFunctionTemplate(zzinfixFuncName);
    // If in a pred. (not LHS of infix pred.), then we know the return type
    if (zzpred)
    {
      ((FunctionTemplate*)t)->setRetTypeId(
        zzpred->getTermTypeAsInt(zzpred->getNumTerms()), zzdomain);
      }
    zzfunc->setTemplate((FunctionTemplate*)t);

    // types are possibly unknown
    bool unknownTypes = false;

    // First element is return type
    Array<int> typeIds(zzfunc->getNumTerms() + 1);
    typeIds.append(zzfunc->getRetTypeId());
    if (typeIds[0] <= 0) unknownTypes = true;

    // Then term types
    for (int i = 1; i <= zzfunc->getNumTerms(); i++)
    {
      typeIds.append(zzgetTypeId(zzfunc->getTerm(i-1), (*funclo)[i]->getStr()));
      if (typeIds[i] <= 0) unknownTypes = true;
    }

    // If all types are known
    if (!unknownTypes)
    {
      zzsetInternalFuncTypeName(zzinfixFuncName, typeIds);
    }
      else // Not all types are known, delay processing
      {
        Array<string> varNames(typeIds.size());

        char* varName;
      char funcVarCounterString[10];
      int funcVarCounterLength =
          sprintf(funcVarCounterString, "%d", zzfuncVarCounter);
      varName = (char *)malloc((strlen(ZZ_FUNCVAR_PREFIX) +
                    funcVarCounterLength + 1)*sizeof(char));
      strcpy(varName, ZZ_FUNCVAR_PREFIX);
    strcat(varName, funcVarCounterString);
      string newVarName = zzgetNewVarName(varName);

        varNames.append(newVarName);

        for (int i = 1; i < typeIds.size(); i++)
          varNames[i] = (*funclo)[i]->getStr();

    // Predicate name is PredicateTemplate::ZZ_RETURN_PREFIX + function name
    char* predName;
    predName = (char *)malloc((strlen(PredicateTemplate::ZZ_RETURN_PREFIX) +
                     strlen(zzfunc->getName()) + 1)*sizeof(char));
    strcpy(predName, PredicateTemplate::ZZ_RETURN_PREFIX);
    strcat(predName, zzinfixFuncName);

        string unknownIntFuncName =
              zzappendWithUnderscore(predName, zzintFuncTypeCounter++);
        zzintFuncList.push_back(ZZUnknownIntFuncInfo(unknownIntFuncName, varNames));
        //funclo->replace(zzinfixFuncName, unknownIntFuncName.c_str());
    free(predName);
    free(varName);
      }
    free(zzinfixFuncName);
      zzinfixFuncName = NULL;
  }

    zzconsumeToken(zztokenList, ")");
    if (folDbg >= 1) printf(") ");
  }
#line 3827 "fol.cpp"
    break;

  case 169: /* $@50: %empty  */
#line 2188 "../src/parser/fol.y"
  {
      // Create a function corresponding to the infix sign
    if (zzfunc != NULL) { zzfuncStack.push(zzfunc); zzfunc = NULL; }
    ++zzfdnumFuncs;
    zzfdfuncName = zzinfixFuncName;
  const FunctionTemplate* t =
      zzgetGenericInternalFunctionTemplate(zzinfixFuncName);
    zzfunc = new Function(t);
    // If in a pred. (not LHS of infix pred.), then we know the return type
      // It's the type of the previous variable (getNumTerms() - 1)
  if (zzpred)
      ((FunctionTemplate*)t)->setRetTypeId(
        zzpred->getTermTypeAsInt(zzpred->getNumTerms() - 1), zzdomain);

    ListObj* funclo = new ListObj;
    funclo->append(zzfdfuncName.c_str());
    zzpredFuncListObjs.push(funclo);

      // The first term was added to the previous pred / func
      // So this needs to be switched to the infix function
    moveTermToInfixFunction();
  }
#line 3854 "fol.cpp"
    break;

  case 170: /* function_term: term internal_function_sign $@50 term  */
#line 2211 "../src/parser/fol.y"
  {
    ListObj* funclo = zzpredFuncListObjs.top();

    // types are possibly unknown
    bool unknownTypes = false;

      // First element is return type
    Array<int> typeIds(zzfunc->getNumTerms() + 1);
    typeIds.append(zzfunc->getRetTypeId());
    if (typeIds[0] <= 0) unknownTypes = true;

      // Then term types
  for (int i = 1; i <= zzfunc->getNumTerms(); i++)
  {
      typeIds.append(zzgetTypeId(zzfunc->getTerm(i-1), (*funclo)[i]->getStr()));
      if (typeIds[i] <= 0) unknownTypes = true;
  }

    // If all types are known
  if (!unknownTypes)
  {
    zzsetInternalFuncTypeName(zzinfixFuncName, typeIds);
  }
    else // Not all types are known, delay processing
    {
      Array<string> varNames(typeIds.size());

      char* varName;
      char funcVarCounterString[10];
      int funcVarCounterLength =
          sprintf(funcVarCounterString, "%d", zzfuncVarCounter);
      varName = (char *)malloc((strlen(ZZ_FUNCVAR_PREFIX) +
                  funcVarCounterLength + 1)*sizeof(char));
      strcpy(varName, ZZ_FUNCVAR_PREFIX);
    strcat(varName, funcVarCounterString);
    string newVarName = zzgetNewVarName(varName);

      varNames.append(newVarName);

      for (int i = 1; i < typeIds.size(); i++)
        varNames[i] = (*funclo)[i]->getStr();
    // Predicate name is PredicateTemplate::ZZ_RETURN_PREFIX + function name
      char* predName;
      predName = (char *)malloc((strlen(PredicateTemplate::ZZ_RETURN_PREFIX) +
                         strlen(zzfunc->getName()) + 1)*sizeof(char));
      strcpy(predName, PredicateTemplate::ZZ_RETURN_PREFIX);
      strcat(predName, zzinfixFuncName);

      string unknownIntFuncName =
        zzappendWithUnderscore(predName, zzintFuncTypeCounter++);
      zzintFuncList.push_back(ZZUnknownIntFuncInfo(unknownIntFuncName, varNames));
        //funclo->replace(zzinfixFuncName, unknownIntFuncName.c_str());
      free(predName);
      free(varName);
    }
    free(zzinfixFuncName);
    zzinfixFuncName = NULL;
  }
#line 3917 "fol.cpp"
    break;

  case 171: /* internal_function_sign: '+'  */
#line 2273 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "+");
    if (folDbg >= 1) printf("+ ");
    zzinfixFuncName = (char *)malloc((strlen(PredicateTemplate::PLUS_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixFuncName, PredicateTemplate::PLUS_NAME);
  }
#line 3929 "fol.cpp"
    break;

  case 172: /* internal_function_sign: '-'  */
#line 2282 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "-");
    if (folDbg >= 1) printf("- ");
    zzinfixFuncName = (char *)malloc((strlen(PredicateTemplate::MINUS_NAME)
                                      + 1)*sizeof(char));
    strcpy(zzinfixFuncName, PredicateTemplate::MINUS_NAME);
  }
#line 3941 "fol.cpp"
    break;

  case 173: /* internal_function_sign: '*'  */
#line 2291 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "*");
    if (folDbg >= 1) printf("* ");
    zzinfixFuncName = (char *)malloc((strlen(PredicateTemplate::TIMES_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixFuncName, PredicateTemplate::TIMES_NAME);
  }
#line 3953 "fol.cpp"
    break;

  case 174: /* internal_function_sign: '/'  */
#line 2300 "../src/parser/fol.y"
  {
  zzconsumeToken(zztokenList, "/");
    if (folDbg >= 1) printf("/ ");
    zzinfixFuncName = (char *)malloc((strlen(PredicateTemplate::DIVIDEDBY_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixFuncName, PredicateTemplate::DIVIDEDBY_NAME);
  }
#line 3965 "fol.cpp"
    break;

  case 175: /* internal_function_sign: '%'  */
#line 2309 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList, "%");
    if (folDbg >= 1) printf("%% ");
    zzinfixFuncName = (char *)malloc((strlen(PredicateTemplate::MOD_NAME)
                      + 1)*sizeof(char));
    strcpy(zzinfixFuncName, PredicateTemplate::MOD_NAME);
  }
#line 3977 "fol.cpp"
    break;

  case 176: /* $@51: %empty  */
#line 2320 "../src/parser/fol.y"
  {
      // Square Brackets
    zzconsumeToken(zztokenList,"[");
    if (folDbg >= 1) printf("[ ");
    if (folDbg >= 2) printf("numeric_term: '[' numeric_term\n");
    zzformulaStr.append("[");
  }
#line 3989 "fol.cpp"
    break;

  case 177: /* numeric_term: '[' $@51 numeric_term ']'  */
#line 2329 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"]");
    if (folDbg >= 1) printf("] ");
    zzformulaStr.append("]");
  }
#line 3999 "fol.cpp"
    break;

  case 178: /* $@52: %empty  */
#line 2336 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"(");
    if (folDbg >= 1) printf("( ");
    if (folDbg >= 2) printf("numeric_term: '(' numeric_term\n");
    zzformulaStr.append("(");
  }
#line 4010 "fol.cpp"
    break;

  case 179: /* numeric_term: '(' $@52 numeric_term ')'  */
#line 2344 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,")");
    if (folDbg >= 1) printf(") ");
    zzformulaStr.append(")");
  }
#line 4020 "fol.cpp"
    break;

  case 181: /* $@53: %empty  */
#line 2355 "../src/parser/fol.y"
  {
    const char* predName = zztokenList.removeLast();
    if (folDbg >= 1) printf("p_%s ", predName);

    ListObj* predlo = new ListObj;

  if (PredicateTemplate::isInternalPredicateTemplateName(predName))
  {
    //zzinfixPredName is misused here to store internal pred. name
    zzinfixPredName = (char *)malloc((strlen(predName)
                        + 1)*sizeof(char));
    strcpy(zzinfixPredName, predName);
    const PredicateTemplate* t = zzdomain->getEmptyPredicateTemplate();
      zzassert(zzpred == NULL,"expecting zzpred==NULL");
      zzpred = new Predicate(t);
      predlo->append(PredicateTemplate::EMPTY_NAME);
  }
  else
  {
      zzcreatePred(zzpred, predName);
      predlo->append(predName);
  }

    zzformulaStr.append(predName);
    if(zzisNegated)  { zzpred->setSense(false); zzisNegated = false; }
    zzcontPred = predlo;
    delete [] predName;
  }
#line 4053 "fol.cpp"
    break;

  case 182: /* $@54: %empty  */
#line 2385 "../src/parser/fol.y"
   {
    zzconsumeToken(zztokenList,"=");
    if (folDbg >= 1) printf("= ");
    zzformulaStr.append(" = ");
    //if (zzisHybrid) zzcontinuousStr.append("=");
  }
#line 4064 "fol.cpp"
    break;

  case 183: /* gaussian_shorthand: ZZ_PREDICATE $@53 nothing_or_terms '=' $@54 ZZ_NUM  */
#line 2392 "../src/parser/fol.y"
  {
    const char* tmp = zztokenList.removeLast();
    //zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    //strcpy(zztmpReturnConstant, tmp);
    //zztmpReturnNum = true;
    zzformulaStr.append(tmp);
    if (zzisHybrid) zzmean = atof(tmp);
    if (folDbg >= 1) printf("icnum_%s ", tmp);
    delete []tmp;
  }
#line 4079 "fol.cpp"
    break;

  case 184: /* $@55: %empty  */
#line 2404 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"-");
    if (folDbg >= 1) printf("-");
    zzformulaStr.append("-");
  }
#line 4089 "fol.cpp"
    break;

  case 185: /* $@56: %empty  */
#line 2410 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"(");
    if (folDbg >= 1) printf("(");
    zzformulaStr.append("(");
  }
#line 4099 "fol.cpp"
    break;

  case 186: /* $@57: %empty  */
#line 2416 "../src/parser/fol.y"
  {
    const char* predName = zztokenList.removeLast();
    if (folDbg >= 1) printf("p_%s ", predName);

    ListObj* predlo = new ListObj;

  if (PredicateTemplate::isInternalPredicateTemplateName(predName))
  {
    //zzinfixPredName is misused here to store internal pred. name
    zzinfixPredName = (char *)malloc((strlen(predName)
                        + 1)*sizeof(char));
    strcpy(zzinfixPredName, predName);
    const PredicateTemplate* t = zzdomain->getEmptyPredicateTemplate();
      zzassert(zzpred == NULL,"expecting zzpred==NULL");
      zzpred = new Predicate(t);
      predlo->append(PredicateTemplate::EMPTY_NAME);
  }
  else
  {
      zzcreatePred(zzpred, predName);
      predlo->append(predName);
  }

    zzformulaStr.append(predName);
    if(zzisNegated)  { zzpred->setSense(false); zzisNegated = false; }
    zzcontPred = predlo;
    delete [] predName;
  }
#line 4132 "fol.cpp"
    break;

  case 187: /* $@58: %empty  */
#line 2446 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"-");
    if (folDbg >= 1) printf("- ");
    zzformulaStr.append(" - ");
  }
#line 4142 "fol.cpp"
    break;

  case 188: /* $@59: %empty  */
#line 2452 "../src/parser/fol.y"
  {
    const char* tmp = zztokenList.removeLast();
    //zztmpReturnConstant = (char *)malloc((strlen(tmp) + 1)*sizeof(char));
    //strcpy(zztmpReturnConstant, tmp);
    //zztmpReturnNum = true;
    zzformulaStr.append(tmp);
    if (zzisHybrid) zzmean = atof(tmp);
    if (folDbg >= 1) printf("icnum_%s ", tmp);
    delete []tmp;
  }
#line 4157 "fol.cpp"
    break;

  case 189: /* $@60: %empty  */
#line 2463 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,")");
    if (folDbg >= 1) printf(")");
    zzformulaStr.append(")");
  }
#line 4167 "fol.cpp"
    break;

  case 190: /* $@61: %empty  */
#line 2469 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"^");
    if (folDbg >= 1) printf("^");
    zzformulaStr.append("^");
  }
#line 4177 "fol.cpp"
    break;

  case 191: /* gaussian_shorthand: '-' $@55 '(' $@56 ZZ_PREDICATE $@57 nothing_or_terms '-' $@58 ZZ_NUM $@59 ')' $@60 '^' $@61 ZZ_NUM  */
#line 2475 "../src/parser/fol.y"
  {
    zzconsumeToken(zztokenList,"2");
    if (folDbg >= 1) printf("2");
    zzformulaStr.append("2");
  }
#line 4187 "fol.cpp"
    break;


#line 4191 "fol.cpp"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "parse error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a parse error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("parse error"));
      YYCASE_(1, YY_("parse error, unexpected %s"));
      YYCASE_(2, YY_("parse error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("parse error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("parse error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("parse error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("parse error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a parse error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("parse error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 2482 "../src/parser/fol.y"


/******************* function definitions ****************************/

  //warnDuplicates set to true by default
bool runYYParser(MLN* const & mln, Domain* const & dom,
                 const char* const & fileName,
                 const bool& allPredsExceptQueriesAreClosedWorld,
                 const StringHashArray* const & openWorldPredNames,
                 const StringHashArray* const & closedWorldPredNames,
                 const StringHashArray* const & queryPredNames,
                 const bool& addUnitClauses, const bool& warnDuplicates,
                 const double& defaultWt, const bool& mustHaveWtOrFullStop,
                 const Domain* const & domain0, const bool& lazyInference,
                 const bool& flipWtsOfFlippedClause)
{
  zzinit();
  if (fileName) { yyin = fopen(fileName, "r" ); zzinFileName = fileName; }
  else            yyin = stdin;
  if (yyin == NULL) zzexit("Failed to open file %s.", fileName);

  signal(SIGFPE,zzsigHandler);
  signal(SIGABRT,zzsigHandler);
  signal(SIGILL,zzsigHandler);
  signal(SIGSEGV,zzsigHandler);

  zzwarnDuplicates = warnDuplicates;
  zzdefaultWt = defaultWt;
  zzmustHaveWtOrFullStop = mustHaveWtOrFullStop;
  zzflipWtsOfFlippedClause = flipWtsOfFlippedClause;

  ungetc('\n', yyin); // pretend that file begin with a newline
  zzmln = mln;
  zzdomain = dom;

  zzanyTypeId = zzdomain->getTypeId(PredicateTemplate::ANY_TYPE_NAME);
  zzassert(zzanyTypeId >= 0, "expecting zzanyTypeId >= 0");

  // Declare internally implemented predicates and functions
  //declareInternalPredicatesAndFunctions();

  zzisParsing = true;
  yyparse();
  zzisParsing = false;

  zzcheckAllTypesHaveConstants(zzdomain);
  zzcreateBlocks(zzdomain);

  // Insert groundings generated from internally implemented functions and predicates
  zzgenerateGroundingsFromInternalPredicatesAndFunctions();

  // Insert groundings generated from linked-in predicates
  if (zzusingLinkedPredicates) zzgenerateGroundingsFromLinkedPredicates(zzdomain);

  // Insert groundings generated from linked-in functions
  if (zzusingLinkedFunctions) zzgenerateGroundingsFromLinkedFunctions(zzdomain);

  if (zzok)
  {
      //append the formulas to MLN and set the weights of the hard clauses
    cout << "Adding clauses to MLN..." << endl;
    zzappendFormulasToMLN(zzformulaInfos, mln, domain0);

    if (addUnitClauses) zzappendUnitClausesToMLN(zzdomain, zzmln, zzdefaultWt);

    zzmln->setClauseInfoPriorMeansToClauseWts();

      // Change the constant ids so that constants of same type are ordered
      // consecutively. Also ensure that the constants in the mln and map is
      // consistent with the new constant ids
    zzdomain->reorderConstants(zzmln, zzpredIdToGndPredMap);

    zzmln->compress();

    Array<bool> isClosedWorldArr;
    zzfillClosedWorldArray(isClosedWorldArr,allPredsExceptQueriesAreClosedWorld,
                           openWorldPredNames, closedWorldPredNames,
                           queryPredNames);

    Database* db = new Database(zzdomain, isClosedWorldArr, zzstoreGroundPreds);
    if (lazyInference) db->setLazyFlag();
    zzaddGndPredsToDb(db);
    zzdomain->setDB(db);
    zzdomain->compress();
  }

  if (zznumErrors > 0) cout << "Num of errors detected = " << zznumErrors<<endl;

  zzcleanUp();

  signal(SIGFPE,SIG_DFL);
  signal(SIGABRT,SIG_DFL);
  signal(SIGILL,SIG_DFL);
  signal(SIGSEGV,SIG_DFL);

  return zzok;
}

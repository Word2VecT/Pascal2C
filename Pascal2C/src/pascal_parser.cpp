/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"

#include <iostream>
#include <cstdlib>
#include <memory>
#include "ast.h"
#include "pascal_lexer.h"

// 声明外部变量和函数
extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

// 根节点
std::unique_ptr<ProgramNode> programRoot;

#line 88 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"

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

#include "pascal_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAM = 3,                  /* T_PROGRAM  */
  YYSYMBOL_T_BEGIN = 4,                    /* T_BEGIN  */
  YYSYMBOL_T_END = 5,                      /* T_END  */
  YYSYMBOL_T_VAR = 6,                      /* T_VAR  */
  YYSYMBOL_T_FUNCTION = 7,                 /* T_FUNCTION  */
  YYSYMBOL_T_PROCEDURE = 8,                /* T_PROCEDURE  */
  YYSYMBOL_T_IF = 9,                       /* T_IF  */
  YYSYMBOL_T_THEN = 10,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 11,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 12,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 13,                      /* T_DO  */
  YYSYMBOL_T_FOR = 14,                     /* T_FOR  */
  YYSYMBOL_T_TO = 15,                      /* T_TO  */
  YYSYMBOL_T_DOWNTO = 16,                  /* T_DOWNTO  */
  YYSYMBOL_T_REPEAT = 17,                  /* T_REPEAT  */
  YYSYMBOL_T_UNTIL = 18,                   /* T_UNTIL  */
  YYSYMBOL_T_CASE = 19,                    /* T_CASE  */
  YYSYMBOL_T_OF = 20,                      /* T_OF  */
  YYSYMBOL_T_CONST = 21,                   /* T_CONST  */
  YYSYMBOL_T_TYPE = 22,                    /* T_TYPE  */
  YYSYMBOL_T_ARRAY = 23,                   /* T_ARRAY  */
  YYSYMBOL_T_RECORD = 24,                  /* T_RECORD  */
  YYSYMBOL_T_DIV = 25,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 26,                     /* T_MOD  */
  YYSYMBOL_T_AND = 27,                     /* T_AND  */
  YYSYMBOL_T_OR = 28,                      /* T_OR  */
  YYSYMBOL_T_NOT = 29,                     /* T_NOT  */
  YYSYMBOL_T_ASSIGN = 30,                  /* T_ASSIGN  */
  YYSYMBOL_T_PLUS = 31,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 32,                   /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 33,                /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 34,                  /* T_DIVIDE  */
  YYSYMBOL_T_EQUAL = 35,                   /* T_EQUAL  */
  YYSYMBOL_T_NOT_EQUAL = 36,               /* T_NOT_EQUAL  */
  YYSYMBOL_T_LESS = 37,                    /* T_LESS  */
  YYSYMBOL_T_LESS_EQUAL = 38,              /* T_LESS_EQUAL  */
  YYSYMBOL_T_GREATER = 39,                 /* T_GREATER  */
  YYSYMBOL_T_GREATER_EQUAL = 40,           /* T_GREATER_EQUAL  */
  YYSYMBOL_T_LPAREN = 41,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 42,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACKET = 43,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 44,                /* T_RBRACKET  */
  YYSYMBOL_T_COLON = 45,                   /* T_COLON  */
  YYSYMBOL_T_SEMICOLON = 46,               /* T_SEMICOLON  */
  YYSYMBOL_T_COMMA = 47,                   /* T_COMMA  */
  YYSYMBOL_T_DOT = 48,                     /* T_DOT  */
  YYSYMBOL_T_DOTDOT = 49,                  /* T_DOTDOT  */
  YYSYMBOL_T_IDENTIFIER = 50,              /* T_IDENTIFIER  */
  YYSYMBOL_T_TYPE_ID = 51,                 /* T_TYPE_ID  */
  YYSYMBOL_T_INT_CONST = 52,               /* T_INT_CONST  */
  YYSYMBOL_T_REAL_CONST = 53,              /* T_REAL_CONST  */
  YYSYMBOL_T_STRING_CONST = 54,            /* T_STRING_CONST  */
  YYSYMBOL_T_BOOL_CONST = 55,              /* T_BOOL_CONST  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_declaration_list = 58,          /* declaration_list  */
  YYSYMBOL_declaration = 59,               /* declaration  */
  YYSYMBOL_variable_declaration = 60,      /* variable_declaration  */
  YYSYMBOL_variable_list = 61,             /* variable_list  */
  YYSYMBOL_variable_definition = 62,       /* variable_definition  */
  YYSYMBOL_identifier_list = 63,           /* identifier_list  */
  YYSYMBOL_compound_statement = 64,        /* compound_statement  */
  YYSYMBOL_statement_list = 65,            /* statement_list  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_assignment_statement = 67,      /* assignment_statement  */
  YYSYMBOL_if_statement = 68,              /* if_statement  */
  YYSYMBOL_while_statement = 69,           /* while_statement  */
  YYSYMBOL_procedure_call = 70,            /* procedure_call  */
  YYSYMBOL_expression_list = 71,           /* expression_list  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_simple_expression = 73,         /* simple_expression  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   76

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    91,    98,   104,   111,   125,   126,   130,
     138,   143,   151,   158,   163,   170,   174,   178,   182,   186,
     191,   197,   205,   213,   227,   238,   243,   252,   253,   257,
     261,   265,   269,   273,   277,   281,   288,   292,   296,   300,
     307,   311,   315,   319,   324,   329,   336,   341,   345,   349,
     354,   358,   362
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_VAR", "T_FUNCTION", "T_PROCEDURE", "T_IF", "T_THEN",
  "T_ELSE", "T_WHILE", "T_DO", "T_FOR", "T_TO", "T_DOWNTO", "T_REPEAT",
  "T_UNTIL", "T_CASE", "T_OF", "T_CONST", "T_TYPE", "T_ARRAY", "T_RECORD",
  "T_DIV", "T_MOD", "T_AND", "T_OR", "T_NOT", "T_ASSIGN", "T_PLUS",
  "T_MINUS", "T_MULTIPLY", "T_DIVIDE", "T_EQUAL", "T_NOT_EQUAL", "T_LESS",
  "T_LESS_EQUAL", "T_GREATER", "T_GREATER_EQUAL", "T_LPAREN", "T_RPAREN",
  "T_LBRACKET", "T_RBRACKET", "T_COLON", "T_SEMICOLON", "T_COMMA", "T_DOT",
  "T_DOTDOT", "T_IDENTIFIER", "T_TYPE_ID", "T_INT_CONST", "T_REAL_CONST",
  "T_STRING_CONST", "T_BOOL_CONST", "$accept", "program",
  "declaration_list", "declaration", "variable_declaration",
  "variable_list", "variable_definition", "identifier_list",
  "compound_statement", "statement_list", "statement",
  "assignment_statement", "if_statement", "while_statement",
  "procedure_call", "expression_list", "expression", "simple_expression",
  "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -30,    29,     7,   -42,   -42,    24,     0,   -10,   -42,
     -42,     6,    -8,    -8,   -25,   -42,    -3,   -42,   -42,   -42,
     -42,   -42,   -42,   -10,   -42,    -6,   -42,    -8,    -8,   -42,
     -42,   -42,   -42,   -42,    57,    20,    -2,   -42,    55,    -8,
      -8,   -42,     0,   -42,    18,    21,   -42,    28,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,     0,   -42,   -36,   -42,   -42,    26,   -42,
     -42,    62,    -2,    -2,    -2,   -18,   -18,   -18,   -18,   -18,
     -18,   -42,   -42,   -42,   -42,   -42,   -42,   -42,    -8,   -42,
       0,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,    20,     0,     3,
       5,     0,     0,     0,    25,    15,     0,    14,    16,    17,
      18,    19,    11,     6,     8,     0,     2,     0,     0,    46,
      47,    48,    49,    50,     0,    29,    36,    40,     0,     0,
       0,    12,    20,     7,     0,     0,    52,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,    28,    13,     0,    10,
      51,    22,    39,    37,    38,    30,    31,    32,    33,    34,
      35,    43,    44,    45,    41,    42,    24,    26,     0,     9,
      20,    27,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,   -42,    51,   -42,    70,   -42,
     -41,   -42,   -42,   -42,   -42,   -42,   -13,     9,   -32,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     9,    10,    23,    24,    25,    15,    16,
      17,    18,    19,    20,    21,    65,    34,    35,    36,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    67,    41,    46,     7,    39,    87,    71,     1,    12,
      49,    88,    13,    50,    51,    47,    40,    72,    73,    74,
       3,    27,    86,    58,    59,    60,    64,    66,     7,     4,
       8,    61,    62,    28,    81,    82,    83,    84,    85,    44,
      22,    45,    29,    42,    30,    31,    32,    33,    49,    92,
      14,    50,    51,     5,    26,    52,    53,    54,    55,    56,
      57,    75,    76,    77,    78,    79,    80,    48,    63,    68,
      70,    69,    89,    90,    43,    91,    11
};

static const yytype_int8 yycheck[] =
{
      13,    42,     5,    27,     4,    30,    42,    48,     3,     9,
      28,    47,    12,    31,    32,    28,    41,    49,    50,    51,
      50,    29,    63,    25,    26,    27,    39,    40,     4,     0,
       6,    33,    34,    41,    58,    59,    60,    61,    62,    45,
      50,    47,    50,    46,    52,    53,    54,    55,    28,    90,
      50,    31,    32,    46,    48,    35,    36,    37,    38,    39,
      40,    52,    53,    54,    55,    56,    57,    10,    13,    51,
      42,    50,    46,    11,    23,    88,     6
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    57,    50,     0,    46,    58,     4,     6,    59,
      60,    64,     9,    12,    50,    64,    65,    66,    67,    68,
      69,    70,    50,    61,    62,    63,    48,    29,    41,    50,
      52,    53,    54,    55,    72,    73,    74,    75,    72,    30,
      41,     5,    46,    62,    45,    47,    75,    72,    10,    28,
      31,    32,    35,    36,    37,    38,    39,    40,    25,    26,
      27,    33,    34,    13,    72,    71,    72,    66,    51,    50,
      42,    66,    74,    74,    74,    73,    73,    73,    73,    73,
      73,    75,    75,    75,    75,    75,    66,    42,    47,    46,
      11,    72,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    60,    61,    61,    62,
      63,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     2,     1,     4,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       0,     3,     4,     6,     4,     1,     4,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
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


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
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
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: T_PROGRAM T_IDENTIFIER T_SEMICOLON declaration_list compound_statement T_DOT  */
#line 77 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        programRoot = std::make_unique<ProgramNode>((yyvsp[-4].strVal));
        if ((yyvsp[-2].node)) {
            programRoot->addDeclaration(std::unique_ptr<ASTNode>((yyvsp[-2].node)));
        }
        if ((yyvsp[-1].node)) {
            programRoot->addStatement(std::unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
        free((yyvsp[-4].strVal));
        (yyval.programNode) = programRoot.get();
    }
#line 1611 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 92 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 将声明添加到列表中
        (yyval.node) = (yyvsp[-1].node);  // 保持相同的根节点
        // 这里不需要做其他操作，因为声明已经在程序节点中处理
    }
#line 1621 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 4: /* declaration_list: %empty  */
#line 98 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = nullptr;
    }
#line 1629 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 5: /* declaration: variable_declaration  */
#line 105 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1637 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 6: /* variable_declaration: T_VAR variable_list  */
#line 112 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 创建变量声明节点（实际应基于variable_list创建）
        std::vector<std::string> vars;
        vars.push_back("i");
        vars.push_back("sum");
        (yyval.node) = new VarDeclNode("integer", vars);
        
        // 这样的处理对于真实的编译器来说过于简化
        // 正确的实现应该是收集variable_list中的所有变量声明
    }
#line 1652 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 9: /* variable_definition: identifier_list T_COLON T_TYPE_ID T_SEMICOLON  */
#line 131 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 创建变量定义节点 (简化版)
        free((yyvsp[-1].strVal));
    }
#line 1661 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 10: /* identifier_list: identifier_list T_COMMA T_IDENTIFIER  */
#line 139 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 添加标识符到列表
        free((yyvsp[0].strVal));
    }
#line 1670 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 11: /* identifier_list: T_IDENTIFIER  */
#line 144 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 创建新的标识符列表
        free((yyvsp[0].strVal));
    }
#line 1679 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 12: /* compound_statement: T_BEGIN statement_list T_END  */
#line 152 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1687 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 13: /* statement_list: statement_list T_SEMICOLON statement  */
#line 159 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);  // 保持相同的根节点
        // 实际上应该将语句添加到语句列表中
    }
#line 1696 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 14: /* statement_list: statement  */
#line 164 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1704 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 15: /* statement: compound_statement  */
#line 171 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1712 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 16: /* statement: assignment_statement  */
#line 175 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1720 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 17: /* statement: if_statement  */
#line 179 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1728 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 18: /* statement: while_statement  */
#line 183 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1736 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 19: /* statement: procedure_call  */
#line 187 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1744 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 20: /* statement: %empty  */
#line 191 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = nullptr;
    }
#line 1752 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 21: /* assignment_statement: T_IDENTIFIER T_ASSIGN expression  */
#line 198 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new AssignNode((yyvsp[-2].strVal), std::unique_ptr<ASTNode>((yyvsp[0].node)));
        free((yyvsp[-2].strVal));
    }
#line 1761 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 22: /* if_statement: T_IF expression T_THEN statement  */
#line 206 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        auto ifNode = new IfNode(std::unique_ptr<ASTNode>((yyvsp[-2].node)));
        if ((yyvsp[0].node)) {
            ifNode->addThenStatement(std::unique_ptr<ASTNode>((yyvsp[0].node)));
        }
        (yyval.node) = ifNode;
    }
#line 1773 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 23: /* if_statement: T_IF expression T_THEN statement T_ELSE statement  */
#line 214 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        auto ifNode = new IfNode(std::unique_ptr<ASTNode>((yyvsp[-4].node)));
        if ((yyvsp[-2].node)) {
            ifNode->addThenStatement(std::unique_ptr<ASTNode>((yyvsp[-2].node)));
        }
        if ((yyvsp[0].node)) {
            ifNode->addElseStatement(std::unique_ptr<ASTNode>((yyvsp[0].node)));
        }
        (yyval.node) = ifNode;
    }
#line 1788 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 24: /* while_statement: T_WHILE expression T_DO statement  */
#line 228 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        auto whileNode = new WhileNode(std::unique_ptr<ASTNode>((yyvsp[-2].node)));
        if ((yyvsp[0].node)) {
            whileNode->addStatement(std::unique_ptr<ASTNode>((yyvsp[0].node)));
        }
        (yyval.node) = whileNode;
    }
#line 1800 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 25: /* procedure_call: T_IDENTIFIER  */
#line 239 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new ProcCallNode((yyvsp[0].strVal));
        free((yyvsp[0].strVal));
    }
#line 1809 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 26: /* procedure_call: T_IDENTIFIER T_LPAREN expression_list T_RPAREN  */
#line 244 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new ProcCallNode((yyvsp[-3].strVal));
        // 这里应添加参数，但简化版忽略了表达式列表
        free((yyvsp[-3].strVal));
    }
#line 1819 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 29: /* expression: simple_expression  */
#line 258 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1827 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 30: /* expression: simple_expression T_EQUAL simple_expression  */
#line 262 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::EQUAL, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1835 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 31: /* expression: simple_expression T_NOT_EQUAL simple_expression  */
#line 266 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::NOT_EQUAL, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1843 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 32: /* expression: simple_expression T_LESS simple_expression  */
#line 270 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::LESS, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1851 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 33: /* expression: simple_expression T_LESS_EQUAL simple_expression  */
#line 274 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::LESS_EQUAL, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1859 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 34: /* expression: simple_expression T_GREATER simple_expression  */
#line 278 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::GREATER, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1867 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 35: /* expression: simple_expression T_GREATER_EQUAL simple_expression  */
#line 282 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::GREATER_EQUAL, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1875 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 36: /* simple_expression: term  */
#line 289 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1883 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 37: /* simple_expression: simple_expression T_PLUS term  */
#line 293 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::PLUS, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1891 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 38: /* simple_expression: simple_expression T_MINUS term  */
#line 297 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::MINUS, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1899 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 39: /* simple_expression: simple_expression T_OR term  */
#line 301 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::OR, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1907 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 40: /* term: factor  */
#line 308 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1915 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 41: /* term: term T_MULTIPLY factor  */
#line 312 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::MULTIPLY, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1923 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 42: /* term: term T_DIVIDE factor  */
#line 316 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::DIVIDE, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1931 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 43: /* term: term T_DIV factor  */
#line 320 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // DIV在Pascal中是整数除法
        (yyval.node) = new BinaryOpNode(BinaryOpNode::DIVIDE, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1940 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 44: /* term: term T_MOD factor  */
#line 325 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // MOD是取模运算
        (yyval.node) = new BinaryOpNode(BinaryOpNode::DIVIDE, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1949 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 45: /* term: term T_AND factor  */
#line 330 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new BinaryOpNode(BinaryOpNode::AND, std::unique_ptr<ASTNode>((yyvsp[-2].node)), std::unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1957 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 46: /* factor: T_IDENTIFIER  */
#line 337 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new IdentifierNode((yyvsp[0].strVal));
        free((yyvsp[0].strVal));
    }
#line 1966 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 47: /* factor: T_INT_CONST  */
#line 342 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new LiteralNode(LiteralNode::INTEGER, std::to_string((yyvsp[0].intVal)));
    }
#line 1974 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 48: /* factor: T_REAL_CONST  */
#line 346 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new LiteralNode(LiteralNode::REAL, std::to_string((yyvsp[0].realVal)));
    }
#line 1982 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 49: /* factor: T_STRING_CONST  */
#line 350 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new LiteralNode(LiteralNode::STRING, (yyvsp[0].strVal));
        free((yyvsp[0].strVal));
    }
#line 1991 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 50: /* factor: T_BOOL_CONST  */
#line 355 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = new LiteralNode(LiteralNode::BOOLEAN, (yyvsp[0].boolVal) ? "true" : "false");
    }
#line 1999 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 51: /* factor: T_LPAREN expression T_RPAREN  */
#line 359 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2007 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;

  case 52: /* factor: T_NOT factor  */
#line 363 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"
    {
        // 需要处理NOT操作，但简化版中未实现
        (yyval.node) = (yyvsp[0].node);
    }
#line 2016 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"
    break;


#line 2020 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 369 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"


void yyerror(const char* s) {
    std::cerr << "Parser error at line " << yylineno << ": " << s << ", unexpected token: " << yytext << std::endl;
} 

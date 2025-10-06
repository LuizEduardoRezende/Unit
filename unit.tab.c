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
#line 1 "unit.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno; // Declaração da variável de linha do flex

// Tabela de Símbolos Simplificada (para guardar o tipo/unidade da variável)
typedef struct {
    char *name;
    int type_unit;
} Symbol;

// Simulação de uma tabela de símbolos (máximo 100 variáveis)
Symbol symbol_table[100];
int symbol_count = 0;

// Funções de ajuda
Symbol* new_symbol(const char *id, int unit);
Symbol* symbol_exists(const char *id);

int get_symbol_unit(const char *id);
int check_unit_compatibility(int left_unit, int right_unit, const char *op);

int yylex(void);
int yyerror(const char *s);

#define UNIT_METERS 1
#define UNIT_SECONDS 2
#define UNIT_M_PER_S 3
#define UNIT_SQ_METER 4
#define UNIT_ADIMENSIONAL 5


#line 107 "unit.tab.c"

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

#include "unit.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_FLOAT = 3,                    /* T_FLOAT  */
  YYSYMBOL_T_INT = 4,                      /* T_INT  */
  YYSYMBOL_T_FOR = 5,                      /* T_FOR  */
  YYSYMBOL_T_IF = 6,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 7,                     /* T_ELSE  */
  YYSYMBOL_T_PRINTF = 8,                   /* T_PRINTF  */
  YYSYMBOL_T_STRING_LITERAL = 9,           /* T_STRING_LITERAL  */
  YYSYMBOL_T_ID = 10,                      /* T_ID  */
  YYSYMBOL_T_FLOAT_LITERAL = 11,           /* T_FLOAT_LITERAL  */
  YYSYMBOL_T_INT_LITERAL = 12,             /* T_INT_LITERAL  */
  YYSYMBOL_T_LE = 13,                      /* T_LE  */
  YYSYMBOL_T_GE = 14,                      /* T_GE  */
  YYSYMBOL_T_EQ = 15,                      /* T_EQ  */
  YYSYMBOL_T_NE = 16,                      /* T_NE  */
  YYSYMBOL_T_UNIT_TYPE = 17,               /* T_UNIT_TYPE  */
  YYSYMBOL_18_ = 18,                       /* ';'  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* ':'  */
  YYSYMBOL_21_ = 21,                       /* '+'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_statements = 33,                /* statements  */
  YYSYMBOL_statement = 34,                 /* statement  */
  YYSYMBOL_declaration_statement = 35,     /* declaration_statement  */
  YYSYMBOL_assignment_statement = 36,      /* assignment_statement  */
  YYSYMBOL_expression = 37,                /* expression  */
  YYSYMBOL_primary = 38,                   /* primary  */
  YYSYMBOL_for_statement = 39,             /* for_statement  */
  YYSYMBOL_for_assignment_statement = 40,  /* for_assignment_statement  */
  YYSYMBOL_if_statement = 41,              /* if_statement  */
  YYSYMBOL_condition = 42,                 /* condition  */
  YYSYMBOL_print_statement = 43            /* print_statement  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
      25,    26,    23,    21,     2,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    18,
      29,    19,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    78,    79,    80,
      85,    90,    96,   101,   107,   112,   118,   123,   133,   142,
     143,   144,   145,   146,   150,   151,   152,   153,   158,   159,
     163,   171,   172,   176,   180,   184,   188,   192,   196,   204,
     205,   206
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "T_FLOAT", "T_INT", "T_FOR",
  "T_IF", "T_ELSE", "T_PRINTF", "T_STRING_LITERAL", "T_ID",
  "T_FLOAT_LITERAL", "T_INT_LITERAL", "T_LE", "T_GE", "T_EQ", "T_NE",
  "T_UNIT_TYPE", "';'", "'='", "':'", "'+'", "'-'", "'*'", "'/'", "'('",
  "')'", "'{'", "'}'", "'<'", "'>'", "$accept", "program", "statements",
  "statement", "declaration_statement", "assignment_statement",
  "expression", "primary", "for_statement", "for_assignment_statement",
  "if_statement", "condition", "print_statement", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,    -7,    15,   -23,   -19,     8,   -15,    36,    85,   -64,
     -64,   -64,   -64,   -64,   -64,    90,    26,    97,    28,    44,
      16,   113,    16,   -64,   -64,   -64,    16,    46,   -64,    16,
      52,    16,    16,   -64,   -64,   -64,    16,    57,   -64,    38,
      -3,    48,    82,    89,   111,    96,   127,    59,    64,   114,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      65,    58,    76,    78,   -64,   -64,   -64,    16,   -64,   -64,
      16,    91,    91,   -64,    45,    45,    45,    45,   -64,   -64,
     -64,   -64,    45,    45,    85,    81,   -64,   -64,   103,   110,
     120,   123,   124,     6,   -64,   -64,   -64,    16,   125,   126,
     144,    45,    85,    85,   128,    14,    47,    85,   -64,   -64,
      55,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     4,    10,     0,     0,    14,     0,
       0,     0,     0,    25,    24,    27,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    11,    12,     0,    15,    16,
       0,     0,     0,    26,    35,    36,    37,    38,    20,    21,
      22,    23,    33,    34,     0,     0,    39,    40,     0,     0,
       0,     0,     0,     0,    41,    13,    17,     0,     0,     0,
      31,    30,     0,     0,     0,     0,     0,     0,    29,    28,
       0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -63,    -8,   135,   137,   -21,    87,   -64,    86,
     -64,   116,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    37,    38,    12,    91,
      13,    39,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    42,    19,    15,    22,    43,    20,    61,    45,     1,
       2,     3,     4,    16,     5,    49,     6,     1,     2,     3,
       4,    93,     5,    62,     6,    17,    33,    34,    35,    74,
      75,    76,    77,    21,   100,    18,    23,    82,    83,   105,
     106,    36,   108,    27,   110,    30,    88,     1,     2,    89,
       1,     2,     3,     4,     6,     5,    44,     6,     1,     2,
       3,     4,    46,     5,    60,     6,    54,    55,    56,    57,
      50,    51,    52,    53,    63,   109,   101,    71,    54,    55,
      56,    57,    72,   111,    85,    24,    58,    59,     1,     2,
       3,     4,    84,     5,    86,     6,    87,    24,    24,    94,
      64,    90,    24,    54,    55,    56,    57,    65,    25,    26,
      54,    55,    56,    57,    68,    28,    29,    54,    55,    56,
      57,    95,    40,    41,    54,    55,    56,    57,    96,    66,
      67,    54,    55,    56,    57,    54,    55,    56,    57,    97,
      73,    78,    79,    80,    81,    69,    70,    47,    48,    98,
      99,   104,   102,   103,    31,   107,    32,     0,    92
};

static const yytype_int8 yycheck[] =
{
       8,    22,    25,    10,    19,    26,    25,    10,    29,     3,
       4,     5,     6,    20,     8,    36,    10,     3,     4,     5,
       6,    84,     8,    26,    10,    10,    10,    11,    12,    50,
      51,    52,    53,    25,    28,    20,     0,    58,    59,   102,
     103,    25,    28,    17,   107,    17,    67,     3,     4,    70,
       3,     4,     5,     6,    10,     8,    10,    10,     3,     4,
       5,     6,    10,     8,    26,    10,    21,    22,    23,    24,
      13,    14,    15,    16,    26,    28,    97,    18,    21,    22,
      23,    24,    18,    28,    26,    93,    29,    30,     3,     4,
       5,     6,    27,     8,    18,    10,    18,   105,   106,    18,
      18,    10,   110,    21,    22,    23,    24,    18,    18,    19,
      21,    22,    23,    24,    18,    18,    19,    21,    22,    23,
      24,    18,     9,    10,    21,    22,    23,    24,    18,    18,
      19,    21,    22,    23,    24,    21,    22,    23,    24,    19,
      26,    54,    55,    56,    57,    18,    19,    31,    32,    26,
      26,     7,    27,    27,    19,    27,    19,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    10,    32,    33,    34,
      35,    36,    39,    41,    43,    10,    20,    10,    20,    25,
      25,    25,    19,     0,    34,    18,    19,    17,    18,    19,
      17,    35,    36,    10,    11,    12,    25,    37,    38,    42,
       9,    10,    37,    37,    10,    37,    10,    42,    42,    37,
      13,    14,    15,    16,    21,    22,    23,    24,    29,    30,
      26,    10,    26,    26,    18,    18,    18,    19,    18,    18,
      19,    18,    18,    26,    37,    37,    37,    37,    38,    38,
      38,    38,    37,    37,    27,    26,    18,    18,    37,    37,
      10,    40,    40,    33,    18,    18,    18,    19,    26,    26,
      28,    37,    27,    27,     7,    33,    33,    27,    28,    28,
      33,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      35,    35,    35,    35,    35,    35,    35,    35,    36,    37,
      37,    37,    37,    37,    38,    38,    38,    38,    39,    39,
      40,    41,    41,    42,    42,    42,    42,    42,    42,    43,
      43,    43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     5,     5,     7,     3,     5,     5,     7,     4,     1,
       3,     3,     3,     3,     1,     1,     3,     1,    10,    10,
       3,     7,    11,     3,     3,     3,     3,     3,     3,     5,
       5,     6
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 67 "unit.y"
               { (yyval.node) = NULL; }
#line 1426 "unit.tab.c"
    break;

  case 3: /* statements: statement  */
#line 71 "unit.y"
              { (yyval.node) = NULL; }
#line 1432 "unit.tab.c"
    break;

  case 4: /* statements: statements statement  */
#line 72 "unit.y"
                         { (yyval.node) = NULL; }
#line 1438 "unit.tab.c"
    break;

  case 5: /* statement: declaration_statement  */
#line 76 "unit.y"
                          { (yyval.node) = NULL; }
#line 1444 "unit.tab.c"
    break;

  case 6: /* statement: assignment_statement  */
#line 77 "unit.y"
                         { (yyval.node) = NULL; }
#line 1450 "unit.tab.c"
    break;

  case 7: /* statement: for_statement  */
#line 78 "unit.y"
                  { (yyval.node) = NULL; }
#line 1456 "unit.tab.c"
    break;

  case 8: /* statement: if_statement  */
#line 79 "unit.y"
                 { (yyval.node) = NULL; }
#line 1462 "unit.tab.c"
    break;

  case 9: /* statement: print_statement  */
#line 80 "unit.y"
                    { (yyval.node) = NULL; }
#line 1468 "unit.tab.c"
    break;

  case 10: /* declaration_statement: T_FLOAT T_ID ';'  */
#line 85 "unit.y"
                     {
        // ex: float vel;
        new_symbol((yyvsp[-1].string), UNIT_ADIMENSIONAL);
        (yyval.node) = NULL;
    }
#line 1478 "unit.tab.c"
    break;

  case 11: /* declaration_statement: T_FLOAT T_ID '=' expression ';'  */
#line 90 "unit.y"
                                    {
        // ex: float vel = 0.0;
        new_symbol((yyvsp[-3].string), UNIT_ADIMENSIONAL);
        check_unit_compatibility(UNIT_ADIMENSIONAL, (yyvsp[-1].unit), "ASSIGN");
        (yyval.node) = NULL;
    }
#line 1489 "unit.tab.c"
    break;

  case 12: /* declaration_statement: T_FLOAT ':' T_UNIT_TYPE T_ID ';'  */
#line 96 "unit.y"
                                     { 
        // ex: float:seconds tempo_gasto;
        new_symbol((yyvsp[-1].string), (yyvsp[-2].unit));
        (yyval.node) = NULL;
    }
#line 1499 "unit.tab.c"
    break;

  case 13: /* declaration_statement: T_FLOAT ':' T_UNIT_TYPE T_ID '=' expression ';'  */
#line 101 "unit.y"
                                                    {
        // ex: float:seconds tempo = distancia / velocidade;
        new_symbol((yyvsp[-3].string), (yyvsp[-4].unit));
        check_unit_compatibility((yyvsp[-4].unit), (yyvsp[-1].unit), "ASSIGN");
        (yyval.node) = NULL;
    }
#line 1510 "unit.tab.c"
    break;

  case 14: /* declaration_statement: T_INT T_ID ';'  */
#line 107 "unit.y"
                   {
        // ex: int i;
        new_symbol((yyvsp[-1].string), UNIT_ADIMENSIONAL);
        (yyval.node) = NULL;
    }
#line 1520 "unit.tab.c"
    break;

  case 15: /* declaration_statement: T_INT T_ID '=' expression ';'  */
#line 112 "unit.y"
                                  {
        // ex: int i = 0;
        new_symbol((yyvsp[-3].string), UNIT_ADIMENSIONAL);
        check_unit_compatibility(UNIT_ADIMENSIONAL, (yyvsp[-1].unit), "ASSIGN");
        (yyval.node) = NULL;
    }
#line 1531 "unit.tab.c"
    break;

  case 16: /* declaration_statement: T_INT ':' T_UNIT_TYPE T_ID ';'  */
#line 118 "unit.y"
                                   {
        // ex: int:meters dist;
        new_symbol((yyvsp[-1].string), (yyvsp[-2].unit));
        (yyval.node) = NULL;
    }
#line 1541 "unit.tab.c"
    break;

  case 17: /* declaration_statement: T_INT ':' T_UNIT_TYPE T_ID '=' expression ';'  */
#line 123 "unit.y"
                                                  {
        // ex: int:meters dist = 100;
        new_symbol((yyvsp[-3].string), (yyvsp[-4].unit));
        check_unit_compatibility((yyvsp[-4].unit), (yyvsp[-1].unit), "ASSIGN");
        (yyval.node) = NULL;
    }
#line 1552 "unit.tab.c"
    break;

  case 18: /* assignment_statement: T_ID '=' expression ';'  */
#line 133 "unit.y"
                            {
        int target_unit = get_symbol_unit((yyvsp[-3].string));
        check_unit_compatibility(target_unit, (yyvsp[-1].unit), "ASSIGN"); 
        (yyval.node) = NULL;
    }
#line 1562 "unit.tab.c"
    break;

  case 19: /* expression: primary  */
#line 142 "unit.y"
                                        { (yyval.unit) = (yyvsp[0].unit); }
#line 1568 "unit.tab.c"
    break;

  case 20: /* expression: expression '+' primary  */
#line 143 "unit.y"
                                     { check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "+"); (yyval.unit) = (yyvsp[-2].unit); }
#line 1574 "unit.tab.c"
    break;

  case 21: /* expression: expression '-' primary  */
#line 144 "unit.y"
                                    { check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "-"); (yyval.unit) = (yyvsp[-2].unit); }
#line 1580 "unit.tab.c"
    break;

  case 22: /* expression: expression '*' primary  */
#line 145 "unit.y"
                                     { (yyval.unit) = check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "*"); }
#line 1586 "unit.tab.c"
    break;

  case 23: /* expression: expression '/' primary  */
#line 146 "unit.y"
                                      { (yyval.unit) = check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "/"); }
#line 1592 "unit.tab.c"
    break;

  case 24: /* primary: T_FLOAT_LITERAL  */
#line 150 "unit.y"
                                        { (yyval.unit) = UNIT_ADIMENSIONAL; }
#line 1598 "unit.tab.c"
    break;

  case 25: /* primary: T_ID  */
#line 151 "unit.y"
                                        { (yyval.unit) = get_symbol_unit((yyvsp[0].string)); }
#line 1604 "unit.tab.c"
    break;

  case 26: /* primary: '(' expression ')'  */
#line 152 "unit.y"
                              { (yyval.unit) = (yyvsp[-1].unit); }
#line 1610 "unit.tab.c"
    break;

  case 27: /* primary: T_INT_LITERAL  */
#line 153 "unit.y"
                                        { (yyval.unit) = UNIT_ADIMENSIONAL; }
#line 1616 "unit.tab.c"
    break;

  case 28: /* for_statement: T_FOR '(' assignment_statement condition ';' for_assignment_statement ')' '{' statements '}'  */
#line 158 "unit.y"
                                                                                                 { (yyval.node) = NULL; }
#line 1622 "unit.tab.c"
    break;

  case 29: /* for_statement: T_FOR '(' declaration_statement condition ';' for_assignment_statement ')' '{' statements '}'  */
#line 159 "unit.y"
                                                                                                  { (yyval.node) = NULL; }
#line 1628 "unit.tab.c"
    break;

  case 30: /* for_assignment_statement: T_ID '=' expression  */
#line 163 "unit.y"
                        { 
        int target_unit = get_symbol_unit((yyvsp[-2].string));
        check_unit_compatibility(target_unit, (yyvsp[0].unit), "ASSIGN"); 
        (yyval.node) = NULL; 
    }
#line 1638 "unit.tab.c"
    break;

  case 31: /* if_statement: T_IF '(' condition ')' '{' statements '}'  */
#line 171 "unit.y"
                                              { (yyval.node) = NULL; }
#line 1644 "unit.tab.c"
    break;

  case 32: /* if_statement: T_IF '(' condition ')' '{' statements '}' T_ELSE '{' statements '}'  */
#line 172 "unit.y"
                                                                        { (yyval.node) = NULL; }
#line 1650 "unit.tab.c"
    break;

  case 33: /* condition: expression '<' expression  */
#line 176 "unit.y"
                              { 
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "<"); 
        (yyval.integer) = 0; // Retorno simbólico
    }
#line 1659 "unit.tab.c"
    break;

  case 34: /* condition: expression '>' expression  */
#line 180 "unit.y"
                              {
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), ">");
        (yyval.integer) = 0;
    }
#line 1668 "unit.tab.c"
    break;

  case 35: /* condition: expression T_LE expression  */
#line 184 "unit.y"
                               {
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "<=");
        (yyval.integer) = 0;
    }
#line 1677 "unit.tab.c"
    break;

  case 36: /* condition: expression T_GE expression  */
#line 188 "unit.y"
                               {
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "GE");
        (yyval.integer) = 0;
    }
#line 1686 "unit.tab.c"
    break;

  case 37: /* condition: expression T_EQ expression  */
#line 192 "unit.y"
                               {
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "EQ");
        (yyval.integer) = 0;
    }
#line 1695 "unit.tab.c"
    break;

  case 38: /* condition: expression T_NE expression  */
#line 196 "unit.y"
                               {
        check_unit_compatibility((yyvsp[-2].unit), (yyvsp[0].unit), "!=");
        (yyval.integer) = 0;
    }
#line 1704 "unit.tab.c"
    break;

  case 39: /* print_statement: T_PRINTF '(' T_STRING_LITERAL ')' ';'  */
#line 204 "unit.y"
                                          { (yyval.node) = NULL; }
#line 1710 "unit.tab.c"
    break;

  case 40: /* print_statement: T_PRINTF '(' T_ID ')' ';'  */
#line 205 "unit.y"
                              { (yyval.node) = NULL; }
#line 1716 "unit.tab.c"
    break;

  case 41: /* print_statement: T_PRINTF '(' T_STRING_LITERAL T_ID ')' ';'  */
#line 206 "unit.y"
                                               { (yyval.node) = NULL; }
#line 1722 "unit.tab.c"
    break;


#line 1726 "unit.tab.c"

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
          = {yyssp, yytoken};
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 209 "unit.y"


// --- Implementação Simbólica das Funções de Unidade ---

// Adiciona uma variável à tabela de símbolos (com alocação dinâmica)
Symbol* new_symbol(const char *name, int type_unit) {
    if (symbol_count < 100) {
        symbol_table[symbol_count].name = strdup(name);
        symbol_table[symbol_count].type_unit = type_unit;
        Symbol *result = &symbol_table[symbol_count];
        symbol_count++;
        return result;
    }
    return NULL;
}

Symbol* symbol_exists(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

int get_symbol_unit(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type_unit;
        }
    }
    char msg[300];
    snprintf(msg, sizeof(msg), "ERRO FATAL: Variavel '%s' nao declarada.", name);
    yyerror(msg);
    exit(1);
    return UNIT_ADIMENSIONAL;
}

// Ação principal: Checagem de Compatibilidade de Unidades
int check_unit_compatibility(int left_unit, int right_unit, const char *op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "<") == 0 || (strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, "GE") == 0 || strcmp(op, "EQ") == 0)) {
        if (left_unit == UNIT_ADIMENSIONAL && right_unit != UNIT_ADIMENSIONAL) return right_unit;
        if (right_unit == UNIT_ADIMENSIONAL && left_unit != UNIT_ADIMENSIONAL) return left_unit;
        
        if (left_unit != right_unit) {
            char msg[300];
            snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Nao e possivel %s unidades diferentes.", op);
            yyerror(msg);
            exit(1);
        }
        return left_unit;
    }
    if (strcmp(op, "*") == 0) {
        if (left_unit == UNIT_ADIMENSIONAL && right_unit == UNIT_ADIMENSIONAL) return UNIT_ADIMENSIONAL;
        if (right_unit == UNIT_ADIMENSIONAL) return left_unit;
        if (left_unit == UNIT_ADIMENSIONAL) return right_unit;
        if (left_unit == UNIT_METERS && right_unit == UNIT_METERS) return UNIT_SQ_METER;
        if (left_unit == UNIT_M_PER_S && right_unit == UNIT_SECONDS) return UNIT_METERS;
        if (left_unit == UNIT_SECONDS && right_unit == UNIT_M_PER_S) return UNIT_METERS;

        // Multiplicação não aceita
        // Exemplo: meters * seconds = meters*seconds (não simplificado aqui)
        char msg[300];
        snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Multiplicacao de unidades sem regra definida.");
        yyerror(msg);
        exit(1);
    }
    if (strcmp(op, "/") == 0) {
        if (left_unit == UNIT_METERS && right_unit == UNIT_SECONDS) return UNIT_M_PER_S;
        
        if (left_unit == right_unit) return UNIT_ADIMENSIONAL;

        if (right_unit == UNIT_ADIMENSIONAL) return left_unit;
        
        if (left_unit == UNIT_METERS && right_unit == UNIT_M_PER_S) return UNIT_SECONDS;

        if (left_unit == UNIT_M_PER_S && right_unit == UNIT_SECONDS) return UNIT_METERS;
        
        // Divisão não aceita
        // Exemplo: seconds / meters
        char msg[300];
        snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Divisao de unidades sem regra definida.");
        yyerror(msg);
        exit(1);
    }
    if (strcmp(op, "ASSIGN") == 0) {
        if (left_unit != UNIT_ADIMENSIONAL && right_unit == UNIT_ADIMENSIONAL) {
            return left_unit;
        }
        if (left_unit != right_unit) {
            char msg[300];
            snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Atribuicao de unidade incompativel.");
            yyerror(msg);
            exit(1);
        }

        //atribuição de unidades iguais ou adimensionais, é permitida
        return left_unit;

    }
    return UNIT_ADIMENSIONAL;
}

// Função principal de bison/yacc
int main(void) {
    if (yyparse() == 0) {
        printf("Parse concluido com sucesso.\n");
    } else {
        printf("Falha no parse.\n");
    }
    return 0;
}

// Tratamento de erro do Parser
int yyerror(const char *s) {
    printf("Erro de Parse na linha %d: %s\n", yylineno, s);
    return 0;
}

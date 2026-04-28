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
#line 5 "src/parser.y"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <FlexLexer.h>
#include "ast.h"

using namespace std;

extern FILE* yyin;
class yyFlexLexer;

static ASTNode* g_root = nullptr;
static yyFlexLexer* g_scanner = nullptr;

extern int yylex();

static string sval(char* s) { return s ? string(s) : string(); }

void yyerror(const char* s);

#line 95 "build/parser.tab.cc"

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

#include "parser.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_CONST = 6,                      /* CONST  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_LP = 13,                        /* LP  */
  YYSYMBOL_RP = 14,                        /* RP  */
  YYSYMBOL_LB = 15,                        /* LB  */
  YYSYMBOL_RB = 16,                        /* RB  */
  YYSYMBOL_LC = 17,                        /* LC  */
  YYSYMBOL_RC = 18,                        /* RC  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 20,                 /* SEMICOLON  */
  YYSYMBOL_QUESTION = 21,                  /* QUESTION  */
  YYSYMBOL_COLON = 22,                     /* COLON  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_TILDE = 25,                     /* TILDE  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_ADD = 27,                       /* ADD  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_INT_LIT = 40,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 41,                 /* FLOAT_LIT  */
  YYSYMBOL_LEX_ERR = 42,                   /* LEX_ERR  */
  YYSYMBOL_UMINUS = 43,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_CompUnit = 45,                  /* CompUnit  */
  YYSYMBOL_ExtDefList = 46,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 47,                    /* ExtDef  */
  YYSYMBOL_VarDecl = 48,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 49,                /* VarDefList  */
  YYSYMBOL_VarDef = 50,                    /* VarDef  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_FuncDef = 52,                   /* FuncDef  */
  YYSYMBOL_ParamListOpt = 53,              /* ParamListOpt  */
  YYSYMBOL_ParamList = 54,                 /* ParamList  */
  YYSYMBOL_Param = 55,                     /* Param  */
  YYSYMBOL_Block = 56,                     /* Block  */
  YYSYMBOL_BlockItems = 57,                /* BlockItems  */
  YYSYMBOL_BlockItem = 58,                 /* BlockItem  */
  YYSYMBOL_Stmt = 59,                      /* Stmt  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_LOrExp = 61,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 62,                   /* LAndExp  */
  YYSYMBOL_EqExp = 63,                     /* EqExp  */
  YYSYMBOL_RelExp = 64,                    /* RelExp  */
  YYSYMBOL_AddExp = 65,                    /* AddExp  */
  YYSYMBOL_MulExp = 66,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 67,                  /* UnaryExp  */
  YYSYMBOL_ArgListOpt = 68,                /* ArgListOpt  */
  YYSYMBOL_ArgList = 69,                   /* ArgList  */
  YYSYMBOL_PrimaryExp = 70                 /* PrimaryExp  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    55,    56,    60,    61,    65,    69,    70,
      74,    75,    79,    80,    81,    85,    89,    90,    94,    95,
      99,   103,   107,   108,   112,   113,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   129,   130,   134,   135,   139,
     140,   144,   145,   146,   150,   151,   152,   153,   154,   158,
     159,   160,   164,   165,   166,   167,   171,   172,   173,   174,
     175,   179,   180,   184,   185,   189,   190,   191,   192
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "VOID",
  "CONST", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "LP",
  "RP", "LB", "RB", "LC", "RC", "COMMA", "SEMICOLON", "QUESTION", "COLON",
  "MINUS", "NOT", "TILDE", "ASSIGN", "ADD", "MUL", "DIV", "MOD", "AND",
  "OR", "EQ", "NE", "LT", "LE", "GT", "GE", "ID", "INT_LIT", "FLOAT_LIT",
  "LEX_ERR", "UMINUS", "$accept", "CompUnit", "ExtDefList", "ExtDef",
  "VarDecl", "VarDefList", "VarDef", "Type", "FuncDef", "ParamListOpt",
  "ParamList", "Param", "Block", "BlockItems", "BlockItem", "Stmt", "Exp",
  "LOrExp", "LAndExp", "EqExp", "RelExp", "AddExp", "MulExp", "UnaryExp",
  "ArgListOpt", "ArgList", "PrimaryExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -77,   -77,   -77,    26,    16,   -77,   -77,    -7,   -77,
     -77,   -77,    -2,   -18,   -77,    16,    43,    20,   -77,    47,
      35,    21,   -77,    43,    72,    72,    72,     1,   -77,   -77,
     -77,    23,    62,     4,    39,    31,    70,   -77,   -77,    52,
     -77,   -77,    77,    16,    87,    89,   -77,   -77,   -77,    43,
      43,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,   -77,   -77,   -77,   -77,   -77,    90,
      84,   -77,    62,     4,    39,    39,    31,    31,    31,    31,
      70,    70,   -77,   -77,   -77,     5,   -77,    43,    43,    92,
      93,    88,    94,   -77,   -77,   -77,    20,   -77,   -77,   -77,
      95,   -77,    96,    43,    43,   -77,   -77,   -77,   -77,   103,
     104,    40,    40,    98,   -77,    40,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     4,     5,     0,     6,
       1,     3,    10,     0,     9,    16,     0,     0,     7,     0,
       0,    17,    19,     0,     0,     0,     0,    66,    67,    68,
      11,    36,    38,    40,    43,    48,    51,    55,    56,    10,
       8,    20,     0,     0,     0,    66,    57,    58,    59,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    15,    18,    65,    64,     0,
      62,    35,    37,    39,    41,    42,    44,    45,    46,    47,
      50,    49,    52,    53,    54,     0,    60,     0,     0,     0,
       0,     0,     0,    21,    26,    24,     0,    34,    22,    25,
       0,    63,     0,     0,     0,    32,    33,    27,    28,     0,
       0,     0,     0,    29,    31,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   105,    24,   -77,   102,   -12,   -77,   -77,
     -77,    78,    80,   -77,   -77,   -76,   -16,   -77,    69,    71,
       8,    34,    10,   -20,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    13,    14,     8,     9,    20,
      21,    22,    97,    85,    98,    99,   100,    31,    32,    33,
      34,    35,    36,    37,    69,    70,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    17,    18,    19,    46,    47,    48,    44,     1,     2,
       3,    15,    88,    89,    49,    90,    91,    92,    23,     1,
       2,     3,    64,    93,    16,    94,    10,    50,    24,    25,
      26,    19,    12,    68,    71,   113,   114,    53,    54,   116,
      43,    82,    83,    84,    27,    28,    29,    88,    89,    42,
      90,    91,    92,    23,    59,    51,    23,    64,    60,    39,
      94,    74,    75,    24,    25,    26,    24,    25,    26,    80,
      81,   101,   102,    96,    55,    56,    57,    58,    16,    27,
      28,    29,    27,    28,    29,    23,    41,   109,   110,    76,
      77,    78,    79,    52,    64,    24,    25,    26,    61,    62,
      63,    67,    49,    87,    86,   103,   104,   115,   105,    95,
      11,    45,    28,    29,   106,   107,   108,   111,   112,    40,
      72,    66,    65,    73
};

static const yytype_int8 yycheck[] =
{
      16,    19,    20,    15,    24,    25,    26,    23,     3,     4,
       5,    13,     7,     8,    13,    10,    11,    12,    13,     3,
       4,     5,    17,    18,    26,    20,     0,    26,    23,    24,
      25,    43,    39,    49,    50,   111,   112,    33,    34,   115,
      19,    61,    62,    63,    39,    40,    41,     7,     8,    14,
      10,    11,    12,    13,    23,    32,    13,    17,    27,    39,
      20,    53,    54,    23,    24,    25,    23,    24,    25,    59,
      60,    87,    88,    85,    35,    36,    37,    38,    26,    39,
      40,    41,    39,    40,    41,    13,    39,   103,   104,    55,
      56,    57,    58,    31,    17,    23,    24,    25,    28,    29,
      30,    14,    13,    19,    14,    13,    13,     9,    20,    85,
       5,    39,    40,    41,    20,    20,    20,    14,    14,    17,
      51,    43,    42,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    45,    46,    47,    48,    51,    52,
       0,    47,    39,    49,    50,    13,    26,    19,    20,    51,
      53,    54,    55,    13,    23,    24,    25,    39,    40,    41,
      60,    61,    62,    63,    64,    65,    66,    67,    70,    39,
      50,    39,    14,    19,    60,    39,    67,    67,    67,    13,
      26,    32,    31,    33,    34,    35,    36,    37,    38,    23,
      27,    28,    29,    30,    17,    56,    55,    14,    60,    68,
      69,    60,    62,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    67,    57,    14,    19,     7,     8,
      10,    11,    12,    18,    20,    48,    51,    56,    58,    59,
      60,    60,    60,    13,    13,    20,    20,    20,    20,    60,
      60,    14,    14,    59,    59,     9,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    51,    52,    53,    53,    54,    54,
      55,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     6,     0,     1,     3,     1,
       2,     3,     2,     0,     1,     1,     1,     2,     3,     5,
       7,     5,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     2,     2,     2,
       4,     0,     1,     3,     1,     3,     1,     1,     1
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
  case 2: /* CompUnit: ExtDefList  */
#line 51 "src/parser.y"
                 { g_root = (yyvsp[0].node); }
#line 1499 "build/parser.tab.cc"
    break;

  case 3: /* ExtDefList: ExtDefList ExtDef  */
#line 55 "src/parser.y"
                        { (yyval.node) = makeAstNode("CompUnit", {(yyvsp[-1].node), (yyvsp[0].node)}); }
#line 1505 "build/parser.tab.cc"
    break;

  case 4: /* ExtDefList: ExtDef  */
#line 56 "src/parser.y"
             { (yyval.node) = makeAstNode("CompUnit", {(yyvsp[0].node)}); }
#line 1511 "build/parser.tab.cc"
    break;

  case 5: /* ExtDef: VarDecl  */
#line 60 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1517 "build/parser.tab.cc"
    break;

  case 6: /* ExtDef: FuncDef  */
#line 61 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1523 "build/parser.tab.cc"
    break;

  case 7: /* VarDecl: Type VarDefList SEMICOLON  */
#line 65 "src/parser.y"
                                { (yyval.node) = makeAstNode("VarDecl", {(yyvsp[-2].node), (yyvsp[-1].node)}); }
#line 1529 "build/parser.tab.cc"
    break;

  case 8: /* VarDefList: VarDefList COMMA VarDef  */
#line 69 "src/parser.y"
                              { (yyval.node) = makeAstNode("VarDefList", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1535 "build/parser.tab.cc"
    break;

  case 9: /* VarDefList: VarDef  */
#line 70 "src/parser.y"
             { (yyval.node) = makeAstNode("VarDefList", {(yyvsp[0].node)}); }
#line 1541 "build/parser.tab.cc"
    break;

  case 10: /* VarDef: ID  */
#line 74 "src/parser.y"
         { (yyval.node) = makeAstNode("Var", {}, sval((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 1547 "build/parser.tab.cc"
    break;

  case 11: /* VarDef: ID ASSIGN Exp  */
#line 75 "src/parser.y"
                    { (yyval.node) = makeAstNode("InitVar", {makeAstNode("Var", {}, sval((yyvsp[-2].str))), (yyvsp[0].node)}); free((yyvsp[-2].str)); }
#line 1553 "build/parser.tab.cc"
    break;

  case 12: /* Type: INT  */
#line 79 "src/parser.y"
          { (yyval.node) = makeAstNode("Type", {}, "int"); }
#line 1559 "build/parser.tab.cc"
    break;

  case 13: /* Type: FLOAT  */
#line 80 "src/parser.y"
            { (yyval.node) = makeAstNode("Type", {}, "float"); }
#line 1565 "build/parser.tab.cc"
    break;

  case 14: /* Type: VOID  */
#line 81 "src/parser.y"
           { (yyval.node) = makeAstNode("Type", {}, "void"); }
#line 1571 "build/parser.tab.cc"
    break;

  case 15: /* FuncDef: Type ID LP ParamListOpt RP Block  */
#line 85 "src/parser.y"
                                       { (yyval.node) = makeAstNode("FuncDef", {(yyvsp[-5].node), makeAstNode("Name", {}, sval((yyvsp[-4].str))), (yyvsp[-2].node), (yyvsp[0].node)}); free((yyvsp[-4].str)); }
#line 1577 "build/parser.tab.cc"
    break;

  case 16: /* ParamListOpt: %empty  */
#line 89 "src/parser.y"
                  { (yyval.node) = makeAstNode("Params", {}); }
#line 1583 "build/parser.tab.cc"
    break;

  case 17: /* ParamListOpt: ParamList  */
#line 90 "src/parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1589 "build/parser.tab.cc"
    break;

  case 18: /* ParamList: ParamList COMMA Param  */
#line 94 "src/parser.y"
                            { (yyval.node) = makeAstNode("Params", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1595 "build/parser.tab.cc"
    break;

  case 19: /* ParamList: Param  */
#line 95 "src/parser.y"
            { (yyval.node) = makeAstNode("Params", {(yyvsp[0].node)}); }
#line 1601 "build/parser.tab.cc"
    break;

  case 20: /* Param: Type ID  */
#line 99 "src/parser.y"
              { (yyval.node) = makeAstNode("Param", {(yyvsp[-1].node), makeAstNode("Name", {}, sval((yyvsp[0].str)))}); free((yyvsp[0].str)); }
#line 1607 "build/parser.tab.cc"
    break;

  case 21: /* Block: LC BlockItems RC  */
#line 103 "src/parser.y"
                       { (yyval.node) = makeAstNode("Block", {(yyvsp[-1].node)}); }
#line 1613 "build/parser.tab.cc"
    break;

  case 22: /* BlockItems: BlockItems BlockItem  */
#line 107 "src/parser.y"
                           { (yyval.node) = makeAstNode("BlockItems", {(yyvsp[-1].node), (yyvsp[0].node)}); }
#line 1619 "build/parser.tab.cc"
    break;

  case 23: /* BlockItems: %empty  */
#line 108 "src/parser.y"
                  { (yyval.node) = makeAstNode("BlockItems", {}); }
#line 1625 "build/parser.tab.cc"
    break;

  case 24: /* BlockItem: VarDecl  */
#line 112 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1631 "build/parser.tab.cc"
    break;

  case 25: /* BlockItem: Stmt  */
#line 113 "src/parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1637 "build/parser.tab.cc"
    break;

  case 26: /* Stmt: SEMICOLON  */
#line 117 "src/parser.y"
                { (yyval.node) = makeAstNode("EmptyStmt", {}); }
#line 1643 "build/parser.tab.cc"
    break;

  case 27: /* Stmt: Exp SEMICOLON  */
#line 118 "src/parser.y"
                    { (yyval.node) = makeAstNode("ExprStmt", {(yyvsp[-1].node)}); }
#line 1649 "build/parser.tab.cc"
    break;

  case 28: /* Stmt: RETURN Exp SEMICOLON  */
#line 119 "src/parser.y"
                           { (yyval.node) = makeAstNode("Return", {(yyvsp[-1].node)}); }
#line 1655 "build/parser.tab.cc"
    break;

  case 29: /* Stmt: IF LP Exp RP Stmt  */
#line 120 "src/parser.y"
                        { (yyval.node) = makeAstNode("If", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1661 "build/parser.tab.cc"
    break;

  case 30: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 121 "src/parser.y"
                                  { (yyval.node) = makeAstNode("IfElse", {(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1667 "build/parser.tab.cc"
    break;

  case 31: /* Stmt: WHILE LP Exp RP Stmt  */
#line 122 "src/parser.y"
                           { (yyval.node) = makeAstNode("While", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1673 "build/parser.tab.cc"
    break;

  case 32: /* Stmt: BREAK SEMICOLON  */
#line 123 "src/parser.y"
                      { (yyval.node) = makeAstNode("Break", {}); }
#line 1679 "build/parser.tab.cc"
    break;

  case 33: /* Stmt: CONTINUE SEMICOLON  */
#line 124 "src/parser.y"
                         { (yyval.node) = makeAstNode("Continue", {}); }
#line 1685 "build/parser.tab.cc"
    break;

  case 34: /* Stmt: Block  */
#line 125 "src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1691 "build/parser.tab.cc"
    break;

  case 35: /* Exp: ID ASSIGN Exp  */
#line 129 "src/parser.y"
                    { (yyval.node) = makeAstNode("Assign", {makeAstNode("Name", {}, sval((yyvsp[-2].str))), (yyvsp[0].node)}); free((yyvsp[-2].str)); }
#line 1697 "build/parser.tab.cc"
    break;

  case 36: /* Exp: LOrExp  */
#line 130 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1703 "build/parser.tab.cc"
    break;

  case 37: /* LOrExp: LOrExp OR LAndExp  */
#line 134 "src/parser.y"
                        { (yyval.node) = makeAstNode("||", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1709 "build/parser.tab.cc"
    break;

  case 38: /* LOrExp: LAndExp  */
#line 135 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1715 "build/parser.tab.cc"
    break;

  case 39: /* LAndExp: LAndExp AND EqExp  */
#line 139 "src/parser.y"
                        { (yyval.node) = makeAstNode("&&", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1721 "build/parser.tab.cc"
    break;

  case 40: /* LAndExp: EqExp  */
#line 140 "src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1727 "build/parser.tab.cc"
    break;

  case 41: /* EqExp: EqExp EQ RelExp  */
#line 144 "src/parser.y"
                      { (yyval.node) = makeAstNode("==", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1733 "build/parser.tab.cc"
    break;

  case 42: /* EqExp: EqExp NE RelExp  */
#line 145 "src/parser.y"
                      { (yyval.node) = makeAstNode("!=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1739 "build/parser.tab.cc"
    break;

  case 43: /* EqExp: RelExp  */
#line 146 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1745 "build/parser.tab.cc"
    break;

  case 44: /* RelExp: RelExp LT AddExp  */
#line 150 "src/parser.y"
                       { (yyval.node) = makeAstNode("<", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1751 "build/parser.tab.cc"
    break;

  case 45: /* RelExp: RelExp LE AddExp  */
#line 151 "src/parser.y"
                       { (yyval.node) = makeAstNode("<=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1757 "build/parser.tab.cc"
    break;

  case 46: /* RelExp: RelExp GT AddExp  */
#line 152 "src/parser.y"
                       { (yyval.node) = makeAstNode(">", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1763 "build/parser.tab.cc"
    break;

  case 47: /* RelExp: RelExp GE AddExp  */
#line 153 "src/parser.y"
                       { (yyval.node) = makeAstNode(">=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1769 "build/parser.tab.cc"
    break;

  case 48: /* RelExp: AddExp  */
#line 154 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1775 "build/parser.tab.cc"
    break;

  case 49: /* AddExp: AddExp ADD MulExp  */
#line 158 "src/parser.y"
                        { (yyval.node) = makeAstNode("+", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1781 "build/parser.tab.cc"
    break;

  case 50: /* AddExp: AddExp MINUS MulExp  */
#line 159 "src/parser.y"
                          { (yyval.node) = makeAstNode("-", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1787 "build/parser.tab.cc"
    break;

  case 51: /* AddExp: MulExp  */
#line 160 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1793 "build/parser.tab.cc"
    break;

  case 52: /* MulExp: MulExp MUL UnaryExp  */
#line 164 "src/parser.y"
                          { (yyval.node) = makeAstNode("*", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1799 "build/parser.tab.cc"
    break;

  case 53: /* MulExp: MulExp DIV UnaryExp  */
#line 165 "src/parser.y"
                          { (yyval.node) = makeAstNode("/", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1805 "build/parser.tab.cc"
    break;

  case 54: /* MulExp: MulExp MOD UnaryExp  */
#line 166 "src/parser.y"
                          { (yyval.node) = makeAstNode("%", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1811 "build/parser.tab.cc"
    break;

  case 55: /* MulExp: UnaryExp  */
#line 167 "src/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1817 "build/parser.tab.cc"
    break;

  case 56: /* UnaryExp: PrimaryExp  */
#line 171 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1823 "build/parser.tab.cc"
    break;

  case 57: /* UnaryExp: MINUS UnaryExp  */
#line 172 "src/parser.y"
                                  { (yyval.node) = makeAstNode("neg", {(yyvsp[0].node)}); }
#line 1829 "build/parser.tab.cc"
    break;

  case 58: /* UnaryExp: NOT UnaryExp  */
#line 173 "src/parser.y"
                   { (yyval.node) = makeAstNode("!", {(yyvsp[0].node)}); }
#line 1835 "build/parser.tab.cc"
    break;

  case 59: /* UnaryExp: TILDE UnaryExp  */
#line 174 "src/parser.y"
                     { (yyval.node) = makeAstNode("~", {(yyvsp[0].node)}); }
#line 1841 "build/parser.tab.cc"
    break;

  case 60: /* UnaryExp: ID LP ArgListOpt RP  */
#line 175 "src/parser.y"
                          { (yyval.node) = makeAstNode("Call", {makeAstNode("Name", {}, sval((yyvsp[-3].str))), (yyvsp[-1].node)}); free((yyvsp[-3].str)); }
#line 1847 "build/parser.tab.cc"
    break;

  case 61: /* ArgListOpt: %empty  */
#line 179 "src/parser.y"
                  { (yyval.node) = makeAstNode("Args", {}); }
#line 1853 "build/parser.tab.cc"
    break;

  case 62: /* ArgListOpt: ArgList  */
#line 180 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1859 "build/parser.tab.cc"
    break;

  case 63: /* ArgList: ArgList COMMA Exp  */
#line 184 "src/parser.y"
                        { (yyval.node) = makeAstNode("Args", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1865 "build/parser.tab.cc"
    break;

  case 64: /* ArgList: Exp  */
#line 185 "src/parser.y"
          { (yyval.node) = makeAstNode("Args", {(yyvsp[0].node)}); }
#line 1871 "build/parser.tab.cc"
    break;

  case 65: /* PrimaryExp: LP Exp RP  */
#line 189 "src/parser.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 1877 "build/parser.tab.cc"
    break;

  case 66: /* PrimaryExp: ID  */
#line 190 "src/parser.y"
         { (yyval.node) = makeAstNode("Name", {}, sval((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 1883 "build/parser.tab.cc"
    break;

  case 67: /* PrimaryExp: INT_LIT  */
#line 191 "src/parser.y"
              { (yyval.node) = makeAstNode("Int", {}, sval((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 1889 "build/parser.tab.cc"
    break;

  case 68: /* PrimaryExp: FLOAT_LIT  */
#line 192 "src/parser.y"
                { (yyval.node) = makeAstNode("Float", {}, sval((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 1895 "build/parser.tab.cc"
    break;


#line 1899 "build/parser.tab.cc"

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

#line 195 "src/parser.y"


int yylex() { return g_scanner ? g_scanner->yylex() : 0; }

void yyerror(const char* s) {
    cerr << "Parse error: " << s << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) return 1;
    ifstream in(argv[1]);
    if (!in) return 1;
    yyFlexLexer scanner(&in);
    g_scanner = &scanner;
    int ret = yyparse();
    if (ret == 0 && g_root) {
        printAst(g_root);
        return 0;
    }
    return 1;
}

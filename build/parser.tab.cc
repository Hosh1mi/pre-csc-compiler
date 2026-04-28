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
#line 5 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <FlexLexer.h>
#include "ast/ast.hpp"
#include "checker/checker.hpp"
#include "checker/errReporter.hpp"

using namespace std;

extern FILE* yyin;
class yyFlexLexer;

static ASTNode* g_root = nullptr;
static yyFlexLexer* g_scanner = nullptr;

extern int yylex();

static int currentLine() { return g_scanner ? g_scanner->lineno() : 0; }
static string sval(char* s) { return s ? string(s) : string(); }

void yyerror(const char* s);

#line 98 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"

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
  YYSYMBOL_ArrayDimsOpt = 51,              /* ArrayDimsOpt  */
  YYSYMBOL_ArrayDims = 52,                 /* ArrayDims  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_FuncDef = 54,                   /* FuncDef  */
  YYSYMBOL_ParamListOpt = 55,              /* ParamListOpt  */
  YYSYMBOL_ParamList = 56,                 /* ParamList  */
  YYSYMBOL_Param = 57,                     /* Param  */
  YYSYMBOL_Block = 58,                     /* Block  */
  YYSYMBOL_BlockItems = 59,                /* BlockItems  */
  YYSYMBOL_BlockItem = 60,                 /* BlockItem  */
  YYSYMBOL_Stmt = 61,                      /* Stmt  */
  YYSYMBOL_Exp = 62,                       /* Exp  */
  YYSYMBOL_LVal = 63,                      /* LVal  */
  YYSYMBOL_LOrExp = 64,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 65,                   /* LAndExp  */
  YYSYMBOL_EqExp = 66,                     /* EqExp  */
  YYSYMBOL_RelExp = 67,                    /* RelExp  */
  YYSYMBOL_AddExp = 68,                    /* AddExp  */
  YYSYMBOL_MulExp = 69,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 70,                  /* UnaryExp  */
  YYSYMBOL_ArgListOpt = 71,                /* ArgListOpt  */
  YYSYMBOL_ArgList = 72,                   /* ArgList  */
  YYSYMBOL_PrimaryExp = 73                 /* PrimaryExp  */
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
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

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
       0,    54,    54,    58,    59,    63,    64,    68,    72,    73,
      77,    78,    82,    83,    87,    88,    92,    93,    94,    98,
     102,   103,   107,   108,   112,   113,   117,   121,   122,   126,
     127,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     143,   144,   148,   149,   153,   154,   158,   159,   163,   164,
     165,   169,   170,   171,   172,   173,   177,   178,   179,   183,
     184,   185,   186,   190,   191,   192,   193,   194,   198,   199,
     203,   204,   208,   209,   210,   211
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
  "VarDecl", "VarDefList", "VarDef", "ArrayDimsOpt", "ArrayDims", "Type",
  "FuncDef", "ParamListOpt", "ParamList", "Param", "Block", "BlockItems",
  "BlockItem", "Stmt", "Exp", "LVal", "LOrExp", "LAndExp", "EqExp",
  "RelExp", "AddExp", "MulExp", "UnaryExp", "ArgListOpt", "ArgList",
  "PrimaryExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      27,  -111,  -111,  -111,     1,    27,  -111,  -111,   -24,  -111,
    -111,  -111,    29,    17,  -111,    27,    -6,    -2,    36,    16,
    -111,    19,    54,    45,  -111,    -6,    -6,    -6,    -6,    50,
    -111,  -111,    63,    55,    61,    65,    37,   -15,   -13,    20,
    -111,  -111,    -6,    -6,    71,  -111,    71,    80,    27,    88,
    -111,  -111,  -111,  -111,    -6,  -111,  -111,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,  -111,    87,  -111,  -111,  -111,  -111,  -111,  -111,    90,
      86,  -111,    65,    37,   -15,   -15,   -13,   -13,   -13,   -13,
      20,    20,  -111,  -111,  -111,  -111,    49,  -111,    -6,    -6,
     102,   103,    97,    99,  -111,  -111,  -111,    16,  -111,  -111,
    -111,   100,  -111,   107,    -6,    -6,  -111,  -111,  -111,  -111,
     108,   109,   101,   101,   119,  -111,   101,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    17,    18,     0,     2,     4,     5,     0,     6,
       1,     3,    12,     0,     9,    20,     0,    10,    13,     0,
       7,     0,     0,    21,    23,     0,     0,     0,     0,    12,
      74,    75,     0,    73,    41,    45,    47,    50,    55,    58,
      62,    63,     0,     0,    12,     8,    12,     0,     0,     0,
      73,    64,    65,    66,    68,    43,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,    25,    28,    19,    22,    72,    71,     0,
      69,    40,    44,    46,    48,    49,    51,    52,    53,    54,
      57,    56,    59,    60,    61,    14,     0,    67,     0,     0,
       0,     0,     0,     0,    26,    31,    29,     0,    39,    27,
      30,     0,    70,     0,     0,     0,    37,    38,    32,    33,
       0,     0,     0,     0,    34,    36,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -111,   124,    34,  -111,   112,   -21,  -111,    -9,
    -111,  -111,  -111,    84,    89,  -111,  -111,  -110,   -14,   -16,
    -111,    75,    76,    31,    13,    28,   -23,  -111,  -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    13,    14,    17,    18,     8,
       9,    22,    23,    24,   108,    96,   109,   110,   111,    50,
      34,    35,    36,    37,    38,    39,    40,    79,    80,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    10,    32,    51,    52,    53,    21,    25,    55,    33,
      66,    49,   124,   125,    67,    12,   127,    26,    27,    28,
      62,    63,    64,    65,    42,    73,    33,    33,    71,    72,
       1,     2,     3,    29,    30,    31,    19,    20,    33,    21,
      78,    33,    15,    81,    16,    92,    93,    94,    68,    69,
      70,    43,     1,     2,     3,    44,    99,   100,    46,   101,
     102,   103,    25,    54,    48,    16,    74,   104,    47,   105,
      60,    61,    26,    27,    28,    86,    87,    88,    89,    56,
      33,    57,    33,    33,   112,   113,    16,   107,    29,    30,
      31,    84,    85,    58,    90,    91,    59,    74,    33,    33,
     120,   121,    77,    95,    97,    98,    33,    33,    99,   100,
      33,   101,   102,   103,    25,   114,   115,   116,    74,   117,
     118,   105,   122,   123,    26,    27,    28,   119,   126,    11,
     106,    45,    76,    82,     0,    83,    75,     0,     0,     0,
      29,    30,    31
};

static const yytype_int8 yycheck[] =
{
      16,     0,    16,    26,    27,    28,    15,    13,    29,    25,
      23,    25,   122,   123,    27,    39,   126,    23,    24,    25,
      35,    36,    37,    38,    26,    46,    42,    43,    42,    43,
       3,     4,     5,    39,    40,    41,    19,    20,    54,    48,
      54,    57,    13,    57,    15,    68,    69,    70,    28,    29,
      30,    15,     3,     4,     5,    39,     7,     8,    39,    10,
      11,    12,    13,    13,    19,    15,    17,    18,    14,    20,
      33,    34,    23,    24,    25,    62,    63,    64,    65,    16,
      96,    26,    98,    99,    98,    99,    15,    96,    39,    40,
      41,    60,    61,    32,    66,    67,    31,    17,   114,   115,
     114,   115,    14,    16,    14,    19,   122,   123,     7,     8,
     126,    10,    11,    12,    13,    13,    13,    20,    17,    20,
      20,    20,    14,    14,    23,    24,    25,    20,     9,     5,
      96,    19,    48,    58,    -1,    59,    47,    -1,    -1,    -1,
      39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    45,    46,    47,    48,    53,    54,
       0,    47,    39,    49,    50,    13,    15,    51,    52,    19,
      20,    53,    55,    56,    57,    13,    23,    24,    25,    39,
      40,    41,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    73,    26,    15,    39,    50,    39,    14,    19,    62,
      63,    70,    70,    70,    13,    51,    16,    26,    32,    31,
      33,    34,    35,    36,    37,    38,    23,    27,    28,    29,
      30,    62,    62,    51,    17,    58,    57,    14,    62,    71,
      72,    62,    65,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    16,    59,    14,    19,     7,
       8,    10,    11,    12,    18,    20,    48,    53,    58,    60,
      61,    62,    62,    62,    13,    13,    20,    20,    20,    20,
      62,    62,    14,    14,    61,    61,     9,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       2,     4,     0,     1,     4,     3,     1,     1,     1,     6,
       0,     1,     3,     1,     2,     3,     3,     2,     0,     1,
       1,     1,     2,     3,     5,     7,     5,     2,     2,     1,
       3,     1,     1,     2,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     2,     2,     2,     4,     0,     1,
       3,     1,     3,     1,     1,     1
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
#line 54 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                 { g_root = (yyvsp[0].node); }
#line 1516 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 3: /* ExtDefList: ExtDefList ExtDef  */
#line 58 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("CompUnit", (yyvsp[-1].node)->children, "CompUnit", (yyvsp[-1].node) ? (yyvsp[-1].node)->line : currentLine()); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1522 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 4: /* ExtDefList: ExtDef  */
#line 59 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = makeAstNode("CompUnit", {(yyvsp[0].node)}, "CompUnit", currentLine()); }
#line 1528 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 5: /* ExtDef: VarDecl  */
#line 63 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1534 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 6: /* ExtDef: FuncDef  */
#line 64 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1540 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 7: /* VarDecl: Type VarDefList SEMICOLON  */
#line 68 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                                { (yyval.node) = makeAstNode("VarDecl", {(yyvsp[-2].node), (yyvsp[-1].node)}, "VarDecl", currentLine()); }
#line 1546 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 8: /* VarDefList: VarDefList COMMA VarDef  */
#line 72 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                              { (yyval.node) = makeAstNode("VarDefList", (yyvsp[-2].node)->children, "VarDefList", currentLine()); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1552 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 9: /* VarDefList: VarDef  */
#line 73 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = makeAstNode("VarDefList", {(yyvsp[0].node)}, "VarDefList", currentLine()); }
#line 1558 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 10: /* VarDef: ID ArrayDimsOpt  */
#line 77 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("Var", {(yyvsp[0].node)}, sval((yyvsp[-1].str)), currentLine()); free((yyvsp[-1].str)); }
#line 1564 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 11: /* VarDef: ID ArrayDimsOpt ASSIGN Exp  */
#line 78 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                                 { (yyval.node) = makeAstNode("InitVar", {makeAstNode("Var", {(yyvsp[-2].node)}, sval((yyvsp[-3].str)), currentLine()), (yyvsp[0].node)}, "InitVar", currentLine()); free((yyvsp[-3].str)); }
#line 1570 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 12: /* ArrayDimsOpt: %empty  */
#line 82 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                  { (yyval.node) = makeAstNode("ArrayDims", {}, "ArrayDims", currentLine()); }
#line 1576 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 13: /* ArrayDimsOpt: ArrayDims  */
#line 83 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1582 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 14: /* ArrayDims: ArrayDims LB Exp RB  */
#line 87 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("ArrayDims", {(yyvsp[-3].node), (yyvsp[-1].node)}, "ArrayDims", currentLine()); }
#line 1588 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 15: /* ArrayDims: LB Exp RB  */
#line 88 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = makeAstNode("ArrayDims", {(yyvsp[-1].node)}, "ArrayDims", currentLine()); }
#line 1594 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 16: /* Type: INT  */
#line 92 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
          { (yyval.node) = makeAstNode("Type", {}, "int", currentLine()); }
#line 1600 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 17: /* Type: FLOAT  */
#line 93 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
            { (yyval.node) = makeAstNode("Type", {}, "float", currentLine()); }
#line 1606 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 18: /* Type: VOID  */
#line 94 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
           { (yyval.node) = makeAstNode("Type", {}, "void", currentLine()); }
#line 1612 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 19: /* FuncDef: Type ID LP ParamListOpt RP Block  */
#line 98 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                                       { (yyval.node) = makeAstNode("FuncDef", {(yyvsp[-5].node), makeAstNode("Name", {}, sval((yyvsp[-4].str)), currentLine()), (yyvsp[-2].node), (yyvsp[0].node)}, "FuncDef", currentLine()); free((yyvsp[-4].str)); }
#line 1618 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 20: /* ParamListOpt: %empty  */
#line 102 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                  { (yyval.node) = makeAstNode("Params", {}, "Params", currentLine()); }
#line 1624 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 21: /* ParamListOpt: ParamList  */
#line 103 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1630 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 22: /* ParamList: ParamList COMMA Param  */
#line 107 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                            { (yyval.node) = makeAstNode("Params", (yyvsp[-2].node)->children, "Params", currentLine()); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1636 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 23: /* ParamList: Param  */
#line 108 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
            { (yyval.node) = makeAstNode("Params", {(yyvsp[0].node)}, "Params", currentLine()); }
#line 1642 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 24: /* Param: Type ID  */
#line 112 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = makeAstNode("Param", {(yyvsp[-1].node), makeAstNode("Name", {}, sval((yyvsp[0].str)), currentLine()), makeAstNode("ArrayDims", {}, "ArrayDims", currentLine())}, "Param", currentLine()); free((yyvsp[0].str)); }
#line 1648 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 25: /* Param: Type ID ArrayDimsOpt  */
#line 113 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                           { (yyval.node) = makeAstNode("Param", {(yyvsp[-2].node), makeAstNode("Name", {}, sval((yyvsp[-1].str)), currentLine()), (yyvsp[0].node)}, "Param", currentLine()); free((yyvsp[-1].str)); }
#line 1654 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 26: /* Block: LC BlockItems RC  */
#line 117 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                       { (yyval.node) = makeAstNode("Block", {(yyvsp[-1].node)}, "Block", currentLine()); }
#line 1660 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 27: /* BlockItems: BlockItems BlockItem  */
#line 121 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                           { (yyval.node) = makeAstNode("BlockItems", (yyvsp[-1].node)->children, "BlockItems", currentLine()); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1666 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 28: /* BlockItems: %empty  */
#line 122 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                  { (yyval.node) = makeAstNode("BlockItems", {}, "BlockItems", currentLine()); }
#line 1672 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 29: /* BlockItem: VarDecl  */
#line 126 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1678 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 30: /* BlockItem: Stmt  */
#line 127 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1684 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 31: /* Stmt: SEMICOLON  */
#line 131 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = makeAstNode("EmptyStmt", {}, "EmptyStmt", currentLine()); }
#line 1690 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 32: /* Stmt: Exp SEMICOLON  */
#line 132 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                    { (yyval.node) = makeAstNode("ExprStmt", {(yyvsp[-1].node)}, "ExprStmt", currentLine()); }
#line 1696 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 33: /* Stmt: RETURN Exp SEMICOLON  */
#line 133 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                           { (yyval.node) = makeAstNode("Return", {(yyvsp[-1].node)}, "Return", currentLine()); }
#line 1702 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 34: /* Stmt: IF LP Exp RP Stmt  */
#line 134 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("If", {(yyvsp[-2].node), (yyvsp[0].node)}, "If", currentLine()); }
#line 1708 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 35: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 135 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                                  { (yyval.node) = makeAstNode("IfElse", {(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)}, "IfElse", currentLine()); }
#line 1714 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 36: /* Stmt: WHILE LP Exp RP Stmt  */
#line 136 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                           { (yyval.node) = makeAstNode("While", {(yyvsp[-2].node), (yyvsp[0].node)}, "While", currentLine()); }
#line 1720 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 37: /* Stmt: BREAK SEMICOLON  */
#line 137 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("Break", {}, "Break", currentLine()); }
#line 1726 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 38: /* Stmt: CONTINUE SEMICOLON  */
#line 138 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                         { (yyval.node) = makeAstNode("Continue", {}, "Continue", currentLine()); }
#line 1732 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 39: /* Stmt: Block  */
#line 139 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1738 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 40: /* Exp: LVal ASSIGN Exp  */
#line 143 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("Assign", {(yyvsp[-2].node), (yyvsp[0].node)}, "Assign", currentLine()); }
#line 1744 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 41: /* Exp: LOrExp  */
#line 144 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1750 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 42: /* LVal: ID  */
#line 148 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
         { (yyval.node) = makeAstNode("Name", {}, sval((yyvsp[0].str)), currentLine()); free((yyvsp[0].str)); }
#line 1756 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 43: /* LVal: ID ArrayDimsOpt  */
#line 149 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("Name", {(yyvsp[0].node)}, sval((yyvsp[-1].str)), currentLine()); free((yyvsp[-1].str)); }
#line 1762 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 44: /* LOrExp: LOrExp OR LAndExp  */
#line 153 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("||", {(yyvsp[-2].node), (yyvsp[0].node)}, "||", currentLine()); }
#line 1768 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 45: /* LOrExp: LAndExp  */
#line 154 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1774 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 46: /* LAndExp: LAndExp AND EqExp  */
#line 158 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("&&", {(yyvsp[-2].node), (yyvsp[0].node)}, "&&", currentLine()); }
#line 1780 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 47: /* LAndExp: EqExp  */
#line 159 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1786 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 48: /* EqExp: EqExp EQ RelExp  */
#line 163 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("==", {(yyvsp[-2].node), (yyvsp[0].node)}, "==", currentLine()); }
#line 1792 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 49: /* EqExp: EqExp NE RelExp  */
#line 164 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                      { (yyval.node) = makeAstNode("!=", {(yyvsp[-2].node), (yyvsp[0].node)}, "!=", currentLine()); }
#line 1798 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 50: /* EqExp: RelExp  */
#line 165 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1804 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 51: /* RelExp: RelExp LT AddExp  */
#line 169 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                       { (yyval.node) = makeAstNode("<", {(yyvsp[-2].node), (yyvsp[0].node)}, "<", currentLine()); }
#line 1810 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 52: /* RelExp: RelExp LE AddExp  */
#line 170 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                       { (yyval.node) = makeAstNode("<=", {(yyvsp[-2].node), (yyvsp[0].node)}, "<=", currentLine()); }
#line 1816 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 53: /* RelExp: RelExp GT AddExp  */
#line 171 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                       { (yyval.node) = makeAstNode(">", {(yyvsp[-2].node), (yyvsp[0].node)}, ">", currentLine()); }
#line 1822 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 54: /* RelExp: RelExp GE AddExp  */
#line 172 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                       { (yyval.node) = makeAstNode(">=", {(yyvsp[-2].node), (yyvsp[0].node)}, ">=", currentLine()); }
#line 1828 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 55: /* RelExp: AddExp  */
#line 173 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1834 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 56: /* AddExp: AddExp ADD MulExp  */
#line 177 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("+", {(yyvsp[-2].node), (yyvsp[0].node)}, "+", currentLine()); }
#line 1840 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 57: /* AddExp: AddExp MINUS MulExp  */
#line 178 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("-", {(yyvsp[-2].node), (yyvsp[0].node)}, "-", currentLine()); }
#line 1846 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 58: /* AddExp: MulExp  */
#line 179 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1852 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 59: /* MulExp: MulExp MUL UnaryExp  */
#line 183 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("*", {(yyvsp[-2].node), (yyvsp[0].node)}, "*", currentLine()); }
#line 1858 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 60: /* MulExp: MulExp DIV UnaryExp  */
#line 184 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("/", {(yyvsp[-2].node), (yyvsp[0].node)}, "/", currentLine()); }
#line 1864 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 61: /* MulExp: MulExp MOD UnaryExp  */
#line 185 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("%", {(yyvsp[-2].node), (yyvsp[0].node)}, "%", currentLine()); }
#line 1870 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 62: /* MulExp: UnaryExp  */
#line 186 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1876 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 63: /* UnaryExp: PrimaryExp  */
#line 190 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1882 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 64: /* UnaryExp: MINUS UnaryExp  */
#line 191 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                                  { (yyval.node) = makeAstNode("neg", {(yyvsp[0].node)}, "neg", currentLine()); }
#line 1888 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 65: /* UnaryExp: NOT UnaryExp  */
#line 192 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                   { (yyval.node) = makeAstNode("!", {(yyvsp[0].node)}, "!", currentLine()); }
#line 1894 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 66: /* UnaryExp: TILDE UnaryExp  */
#line 193 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                     { (yyval.node) = makeAstNode("~", {(yyvsp[0].node)}, "~", currentLine()); }
#line 1900 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 67: /* UnaryExp: ID LP ArgListOpt RP  */
#line 194 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                          { (yyval.node) = makeAstNode("Call", {makeAstNode("Name", {}, sval((yyvsp[-3].str)), currentLine()), (yyvsp[-1].node)}, "Call", currentLine()); free((yyvsp[-3].str)); }
#line 1906 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 68: /* ArgListOpt: %empty  */
#line 198 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                  { (yyval.node) = makeAstNode("Args", {}, "Args", currentLine()); }
#line 1912 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 69: /* ArgListOpt: ArgList  */
#line 199 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1918 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 70: /* ArgList: ArgList COMMA Exp  */
#line 203 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                        { (yyval.node) = makeAstNode("Args", (yyvsp[-2].node)->children, "Args", currentLine()); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1924 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 71: /* ArgList: Exp  */
#line 204 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
          { (yyval.node) = makeAstNode("Args", {(yyvsp[0].node)}, "Args", currentLine()); }
#line 1930 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 72: /* PrimaryExp: LP Exp RP  */
#line 208 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 1936 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 73: /* PrimaryExp: LVal  */
#line 209 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1942 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 74: /* PrimaryExp: INT_LIT  */
#line 210 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
              { (yyval.node) = makeAstNode("Int", {}, sval((yyvsp[0].str)), currentLine()); free((yyvsp[0].str)); }
#line 1948 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;

  case 75: /* PrimaryExp: FLOAT_LIT  */
#line 211 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"
                { (yyval.node) = makeAstNode("Float", {}, sval((yyvsp[0].str)), currentLine()); free((yyvsp[0].str)); }
#line 1954 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"
    break;


#line 1958 "/Users/st4rgazer/Code/project/sysy2026-compiler/build/parser.tab.cc"

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

#line 214 "/Users/st4rgazer/Code/project/sysy2026-compiler/src/parser.y"


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
#ifndef DISABLE_SEMANTIC_CHECK
        ErrReporter reporter;
        Checker checker(reporter);
        checker.check(g_root);
        if (reporter.hasError()) {
            reporter.print();
            return 1;
        }
#endif
        printAst(g_root);
        return 0;
    }
    return 1;
}

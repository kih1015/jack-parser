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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char *tag;                  // XML tag
    char *value;                // Value (if leaf node)
    struct TreeNode **children; // Array of child nodes
    int child_count;            // Number of children
} TreeNode;

TreeNode* create_node(const char *tag, const char *value);
void add_child(TreeNode *parent, TreeNode *child);
void print_tree(TreeNode *node, int depth);
void free_tree(TreeNode *node);
void free_node(TreeNode *node);
void take_children(TreeNode *master, TreeNode *slave);

void yyerror(const char *s);
int yylex();
extern int yylineno;

#line 95 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_CONSTRUCTOR = 4,                /* CONSTRUCTOR  */
  YYSYMBOL_FUNCTION = 5,                   /* FUNCTION  */
  YYSYMBOL_METHOD = 6,                     /* METHOD  */
  YYSYMBOL_FIELD = 7,                      /* FIELD  */
  YYSYMBOL_STATIC = 8,                     /* STATIC  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 12,                   /* BOOLEAN  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_TRUE = 14,                      /* TRUE  */
  YYSYMBOL_FALSE = 15,                     /* FALSE  */
  YYSYMBOL_TK_NULL = 16,                   /* TK_NULL  */
  YYSYMBOL_THIS = 17,                      /* THIS  */
  YYSYMBOL_LET = 18,                       /* LET  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 28,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 29,                  /* RBRACKET  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 35,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 36,                    /* DIVIDE  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 43,                /* IDENTIFIER  */
  YYSYMBOL_STRING_CONSTANT = 44,           /* STRING_CONSTANT  */
  YYSYMBOL_INTEGER_CONSTANT = 45,          /* INTEGER_CONSTANT  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_class = 48,                     /* class  */
  YYSYMBOL_classVarDecList = 49,           /* classVarDecList  */
  YYSYMBOL_subroutineDecList = 50,         /* subroutineDecList  */
  YYSYMBOL_classVarDec = 51,               /* classVarDec  */
  YYSYMBOL_classVarType = 52,              /* classVarType  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_subroutineDec = 54,             /* subroutineDec  */
  YYSYMBOL_subroutineType = 55,            /* subroutineType  */
  YYSYMBOL_returnType = 56,                /* returnType  */
  YYSYMBOL_parameterList = 57,             /* parameterList  */
  YYSYMBOL_subroutineBody = 58,            /* subroutineBody  */
  YYSYMBOL_varDecList = 59,                /* varDecList  */
  YYSYMBOL_varDec = 60,                    /* varDec  */
  YYSYMBOL_varNameList = 61,               /* varNameList  */
  YYSYMBOL_className = 62,                 /* className  */
  YYSYMBOL_subroutineName = 63,            /* subroutineName  */
  YYSYMBOL_varName = 64,                   /* varName  */
  YYSYMBOL_statements = 65,                /* statements  */
  YYSYMBOL_statementList = 66,             /* statementList  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_letStatement = 68,              /* letStatement  */
  YYSYMBOL_ifStatement = 69,               /* ifStatement  */
  YYSYMBOL_whileStatement = 70,            /* whileStatement  */
  YYSYMBOL_doStatement = 71,               /* doStatement  */
  YYSYMBOL_returnStatement = 72,           /* returnStatement  */
  YYSYMBOL_expressions = 73,               /* expressions  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_subroutineCall = 76,            /* subroutineCall  */
  YYSYMBOL_expressionList = 77,            /* expressionList  */
  YYSYMBOL_op = 78,                        /* op  */
  YYSYMBOL_unaryOp = 79,                   /* unaryOp  */
  YYSYMBOL_keywordConstant = 80            /* keywordConstant  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    50,    54,    58,    65,    78,    81,    89,
      92,    99,   110,   113,   119,   122,   125,   128,   134,   148,
     151,   154,   161,   164,   170,   173,   178,   187,   198,   201,
     208,   218,   222,   230,   236,   242,   248,   255,   258,   265,
     268,   271,   274,   277,   283,   291,   305,   315,   332,   345,
     354,   359,   368,   372,   379,   383,   391,   395,   399,   403,
     407,   414,   418,   424,   432,   439,   448,   460,   463,   467,
     475,   479,   483,   487,   491,   495,   499,   503,   507,   514,
     518,   525,   528,   531,   534
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "CONSTRUCTOR",
  "FUNCTION", "METHOD", "FIELD", "STATIC", "VAR", "INT", "CHAR", "BOOLEAN",
  "VOID", "TRUE", "FALSE", "TK_NULL", "THIS", "LET", "DO", "IF", "ELSE",
  "WHILE", "RETURN", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "DOT", "COMMA", "SEMICOLON", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "AND", "OR", "LT", "GT", "EQ", "NOT", "IDENTIFIER",
  "STRING_CONSTANT", "INTEGER_CONSTANT", "$accept", "program", "class",
  "classVarDecList", "subroutineDecList", "classVarDec", "classVarType",
  "type", "subroutineDec", "subroutineType", "returnType", "parameterList",
  "subroutineBody", "varDecList", "varDec", "varNameList", "className",
  "subroutineName", "varName", "statements", "statementList", "statement",
  "letStatement", "ifStatement", "whileStatement", "doStatement",
  "returnStatement", "expressions", "expression", "term", "subroutineCall",
  "expressionList", "op", "unaryOp", "keywordConstant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -31,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    95,
    -114,  -114,    87,  -114,  -114,    18,  -114,  -114,    -5,     4,
      10,    -7,  -114,    28,    95,   188,  -114,  -114,    95,  -114,
    -114,    33,    31,  -114,  -114,  -114,  -114,  -114,  -114,     9,
    -114,     9,    95,    95,     9,    40,    49,    50,    60,    63,
    -114,  -114,  -114,  -114,  -114,  -114,   188,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,    95,  -114,  -114,  -114,
    -114,    74,    76,   188,    89,   136,    77,  -114,    -8,    84,
      83,    95,    95,  -114,   159,  -114,    52,    20,    95,  -114,
      95,  -114,    95,    95,    95,  -114,   108,   123,  -114,  -114,
    -114,    36,  -114,    20,    40,    91,    96,   188,    97,   149,
     169,   101,   102,  -114,  -114,    40,  -114,   107,    20,  -114,
    -114,    92,  -114,  -114,  -114,    43,  -114,  -114,  -114,    40,
      95,   109,   126,    40,  -114,   143,  -114,   179,   132,  -114,
    -114,    40,  -114,   129,  -114,   131,    53,  -114,  -114,  -114,
     141,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      37,     0,    19,    20,    21,    81,    82,    83,    84,     0,
      79,    80,    35,    57,    56,     0,     5,     4,     0,     0,
       0,    59,     3,    36,     2,    52,    54,    61,     0,    58,
      33,     0,     0,     1,    14,    15,    16,    22,    23,     0,
      17,     0,    67,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    53,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,    63,     7,    62,
      34,     0,     0,    68,     0,     0,     0,    35,     0,     0,
       0,     0,     0,    50,     0,    55,     9,    24,    67,    64,
       0,    60,    67,     0,     0,    49,     0,     0,    51,    13,
      12,     0,     8,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     6,    10,     0,    25,     0,     0,    65,
      66,     0,    44,    37,    37,     0,    31,    28,    18,     0,
       0,     0,     0,     0,    11,    37,    26,     0,    46,    48,
      32,     0,    29,     0,    45,     0,     0,    27,    37,    30,
       0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,  -114,  -114,  -114,   -74,    66,  -114,
    -114,  -114,  -114,  -114,  -114,    27,     1,    57,   -42,  -113,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,   -27,
     133,    44,  -114,  -114,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    16,    86,   101,   102,   103,    38,    17,    18,
      39,   105,   128,   135,   142,   125,    19,    20,    21,    22,
      23,    50,    51,    52,    53,    54,    55,    24,    73,    26,
      27,    74,    66,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    67,    31,    78,    79,    34,    35,    36,    37,    32,
     131,   132,    30,   104,     1,     2,     3,     4,    33,    40,
      93,    43,   143,    44,    56,     5,     6,     7,     8,   115,
      34,    35,    36,    94,    41,   150,    42,     9,    30,    85,
       2,     3,     4,    75,   129,    10,    45,    46,    47,    84,
      48,    49,    70,    11,    12,    13,    14,    68,    69,    99,
     100,   113,   116,    30,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   126,   133,   134,    81,     5,     6,     7,
       8,    96,    97,    77,   133,   149,    82,   136,    40,     9,
     107,   140,    12,   109,   110,    83,    71,    10,    72,   126,
      87,    76,    88,    92,    40,    11,    12,    13,    14,     5,
       6,     7,     8,   -34,    44,    95,    89,   -33,   117,    40,
      90,     9,   118,   119,   120,   123,   124,    90,    90,    10,
     137,   127,   106,   130,   138,   111,   108,    11,    12,    13,
      14,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     112,   139,   141,   145,   147,   148,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    91,   151,   114,   146,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   121,    80,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    98,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   122,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   144,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
       0,    28,     1,    45,    46,    10,    11,    12,    13,     9,
     123,   124,    43,    87,     3,     4,     5,     6,     0,    18,
      28,    28,   135,    30,    24,    14,    15,    16,    17,   103,
      10,    11,    12,    41,    30,   148,    26,    26,    43,    66,
       4,     5,     6,    43,   118,    34,    18,    19,    20,    49,
      22,    23,    43,    42,    43,    44,    45,    24,    27,     7,
       8,    25,   104,    43,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   115,    31,    32,    26,    14,    15,    16,
      17,    81,    82,    43,    31,    32,    26,   129,    87,    26,
      90,   133,    43,    93,    94,    32,    39,    34,    41,   141,
      26,    44,    26,    26,   103,    42,    43,    44,    45,    14,
      15,    16,    17,    26,    30,    32,    27,    30,    27,   118,
      31,    26,    31,    27,    27,    24,    24,    31,    31,    34,
     130,    24,    88,    41,    25,    27,    92,    42,    43,    44,
      45,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      27,    25,     9,    21,    25,    24,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    25,   101,   141,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    29,    46,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    33,    34,    35,    36,    37,    38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    14,    15,    16,    17,    26,
      34,    42,    43,    44,    45,    47,    48,    54,    55,    62,
      63,    64,    65,    66,    73,    74,    75,    76,    79,    80,
      43,    62,    74,     0,    10,    11,    12,    13,    53,    56,
      62,    30,    26,    28,    30,    18,    19,    20,    22,    23,
      67,    68,    69,    70,    71,    72,    74,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    78,    75,    24,    27,
      43,    63,    63,    74,    77,    74,    63,    43,    64,    64,
      76,    26,    26,    32,    74,    75,    49,    26,    26,    27,
      31,    29,    26,    28,    41,    32,    74,    74,    32,     7,
       8,    50,    51,    52,    53,    57,    77,    74,    77,    74,
      74,    27,    27,    25,    54,    53,    64,    27,    31,    27,
      27,    29,    32,    24,    24,    61,    64,    24,    58,    53,
      41,    65,    65,    31,    32,    59,    64,    74,    25,    25,
      64,     9,    60,    65,    32,    21,    61,    25,    24,    32,
      65,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     6,     0,     2,     0,
       2,     4,     1,     1,     1,     1,     1,     1,     7,     1,
       1,     1,     1,     1,     0,     2,     4,     4,     0,     2,
       3,     1,     3,     1,     1,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     5,     8,     7,    11,     7,     3,
       2,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       4,     1,     3,     2,     4,     6,     6,     0,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  case 2: /* program: expressions  */
#line 46 "parser.y"
                {
        print_tree((yyvsp[0].node), 0);
        free_tree((yyvsp[0].node));
    }
#line 1287 "parser.tab.c"
    break;

  case 3: /* program: statements  */
#line 50 "parser.y"
                 {
        print_tree((yyvsp[0].node), 0);
        free_tree((yyvsp[0].node));
    }
#line 1296 "parser.tab.c"
    break;

  case 4: /* program: subroutineDec  */
#line 54 "parser.y"
                    {
        print_tree((yyvsp[0].node), 0);
        free_tree((yyvsp[0].node));
    }
#line 1305 "parser.tab.c"
    break;

  case 5: /* program: class  */
#line 58 "parser.y"
            {
        print_tree((yyvsp[0].node), 0);
        free_tree((yyvsp[0].node));
    }
#line 1314 "parser.tab.c"
    break;

  case 6: /* class: CLASS className LBRACE classVarDecList subroutineDecList RBRACE  */
#line 65 "parser.y"
                                                                    {
        (yyval.node) = create_node("class", NULL);
        add_child((yyval.node), create_node("keyword", "class"));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", "{"));
        take_children((yyval.node), (yyvsp[-2].node));
        take_children((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1328 "parser.tab.c"
    break;

  case 7: /* classVarDecList: %empty  */
#line 78 "parser.y"
    {
        (yyval.node) = create_node("classVarDecList", NULL);
    }
#line 1336 "parser.tab.c"
    break;

  case 8: /* classVarDecList: classVarDecList classVarDec  */
#line 81 "parser.y"
                                  {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1345 "parser.tab.c"
    break;

  case 9: /* subroutineDecList: %empty  */
#line 89 "parser.y"
    {
        (yyval.node) = create_node("subroutineDecList", NULL);
    }
#line 1353 "parser.tab.c"
    break;

  case 10: /* subroutineDecList: subroutineDecList subroutineDec  */
#line 92 "parser.y"
                                      {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1362 "parser.tab.c"
    break;

  case 11: /* classVarDec: classVarType type varNameList SEMICOLON  */
#line 99 "parser.y"
                                            {
        (yyval.node) = create_node("classVarDec", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-2].node));
        take_children((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1374 "parser.tab.c"
    break;

  case 12: /* classVarType: STATIC  */
#line 110 "parser.y"
           {
        (yyval.node) = create_node("keyword", "static");
    }
#line 1382 "parser.tab.c"
    break;

  case 13: /* classVarType: FIELD  */
#line 113 "parser.y"
            {
        (yyval.node) = create_node("keyword", "field");
    }
#line 1390 "parser.tab.c"
    break;

  case 14: /* type: INT  */
#line 119 "parser.y"
        {
        (yyval.node) = create_node("keyword", "int");
    }
#line 1398 "parser.tab.c"
    break;

  case 15: /* type: CHAR  */
#line 122 "parser.y"
           {
        (yyval.node) = create_node("keyword", "char");
    }
#line 1406 "parser.tab.c"
    break;

  case 16: /* type: BOOLEAN  */
#line 125 "parser.y"
              {
        (yyval.node) = create_node("keyword", "boolean");
    }
#line 1414 "parser.tab.c"
    break;

  case 17: /* type: className  */
#line 128 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1422 "parser.tab.c"
    break;

  case 18: /* subroutineDec: subroutineType returnType subroutineName LPAREN parameterList RPAREN subroutineBody  */
#line 134 "parser.y"
                                                                                        {
        (yyval.node) = create_node("subroutineDec", NULL);
        add_child((yyval.node), (yyvsp[-6].node));
        add_child((yyval.node), (yyvsp[-5].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1437 "parser.tab.c"
    break;

  case 19: /* subroutineType: CONSTRUCTOR  */
#line 148 "parser.y"
                {
        (yyval.node) = create_node("keyword", "constructor");
    }
#line 1445 "parser.tab.c"
    break;

  case 20: /* subroutineType: FUNCTION  */
#line 151 "parser.y"
               {
        (yyval.node) = create_node("keyword", "function");
    }
#line 1453 "parser.tab.c"
    break;

  case 21: /* subroutineType: METHOD  */
#line 154 "parser.y"
             {
        (yyval.node) = create_node("keyword", "method");
    }
#line 1461 "parser.tab.c"
    break;

  case 22: /* returnType: VOID  */
#line 161 "parser.y"
         {
        (yyval.node) = create_node("keyword", "void");
    }
#line 1469 "parser.tab.c"
    break;

  case 23: /* returnType: type  */
#line 164 "parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1477 "parser.tab.c"
    break;

  case 24: /* parameterList: %empty  */
#line 170 "parser.y"
                {
        (yyval.node) = create_node("parameterList", NULL);
    }
#line 1485 "parser.tab.c"
    break;

  case 25: /* parameterList: type varName  */
#line 173 "parser.y"
                   {
        (yyval.node) = create_node("parameterList", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1495 "parser.tab.c"
    break;

  case 26: /* parameterList: parameterList COMMA type varName  */
#line 178 "parser.y"
                                       {
        (yyval.node) = (yyvsp[-3].node);
        add_child((yyval.node), create_node("symbol", ","));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1506 "parser.tab.c"
    break;

  case 27: /* subroutineBody: LBRACE varDecList statements RBRACE  */
#line 187 "parser.y"
                                        {
        (yyval.node) = create_node("subroutineBody", NULL);
        add_child((yyval.node), create_node("symbol", "{"));
        take_children((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node)); // statements
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1518 "parser.tab.c"
    break;

  case 28: /* varDecList: %empty  */
#line 198 "parser.y"
                {
        (yyval.node) = create_node("varDecList", NULL);
    }
#line 1526 "parser.tab.c"
    break;

  case 29: /* varDecList: varDecList varDec  */
#line 201 "parser.y"
                        {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1535 "parser.tab.c"
    break;

  case 30: /* varDec: VAR varNameList SEMICOLON  */
#line 208 "parser.y"
                              {
        (yyval.node) = create_node("varDec", NULL);
        add_child((yyval.node), create_node("keyword", "var"));
        take_children((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1546 "parser.tab.c"
    break;

  case 31: /* varNameList: varName  */
#line 218 "parser.y"
            {
        (yyval.node) = create_node("varNameList", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1555 "parser.tab.c"
    break;

  case 32: /* varNameList: varNameList COMMA varName  */
#line 222 "parser.y"
                                {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), create_node("symbol", ","));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1565 "parser.tab.c"
    break;

  case 33: /* className: IDENTIFIER  */
#line 230 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1573 "parser.tab.c"
    break;

  case 34: /* subroutineName: IDENTIFIER  */
#line 236 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1581 "parser.tab.c"
    break;

  case 35: /* varName: IDENTIFIER  */
#line 242 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1589 "parser.tab.c"
    break;

  case 36: /* statements: statementList  */
#line 248 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1597 "parser.tab.c"
    break;

  case 37: /* statementList: %empty  */
#line 255 "parser.y"
                {
        (yyval.node) = create_node("statements", NULL);
    }
#line 1605 "parser.tab.c"
    break;

  case 38: /* statementList: statementList statement  */
#line 258 "parser.y"
                              {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1614 "parser.tab.c"
    break;

  case 39: /* statement: letStatement  */
#line 265 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1622 "parser.tab.c"
    break;

  case 40: /* statement: ifStatement  */
#line 268 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1630 "parser.tab.c"
    break;

  case 41: /* statement: whileStatement  */
#line 271 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1638 "parser.tab.c"
    break;

  case 42: /* statement: doStatement  */
#line 274 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1646 "parser.tab.c"
    break;

  case 43: /* statement: returnStatement  */
#line 277 "parser.y"
                      {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1654 "parser.tab.c"
    break;

  case 44: /* letStatement: LET varName EQ expression SEMICOLON  */
#line 283 "parser.y"
                                        {
        (yyval.node) = create_node("letStatement", NULL);
        add_child((yyval.node), create_node("keyword", "let"));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("symbol", "="));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1667 "parser.tab.c"
    break;

  case 45: /* letStatement: LET varName LBRACKET expression RBRACKET EQ expression SEMICOLON  */
#line 291 "parser.y"
                                                                       {
        (yyval.node) = create_node("letStatement", NULL);
        add_child((yyval.node), create_node("keyword", "let"));
        add_child((yyval.node), (yyvsp[-6].node));
        add_child((yyval.node), create_node("symbol", "["));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", "]"));
        add_child((yyval.node), create_node("symbol", "="));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1683 "parser.tab.c"
    break;

  case 46: /* ifStatement: IF LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 305 "parser.y"
                                                         {
        (yyval.node) = create_node("ifStatement", NULL);
        add_child((yyval.node), create_node("keyword", "if"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1698 "parser.tab.c"
    break;

  case 47: /* ifStatement: IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE  */
#line 315 "parser.y"
                                                                                         {
        (yyval.node) = create_node("ifStatement", NULL);
        add_child((yyval.node), create_node("keyword", "if"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-8].node));
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-5].node));
        add_child((yyval.node), create_node("symbol", "}"));
        add_child((yyval.node), create_node("keyword", "else"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1717 "parser.tab.c"
    break;

  case 48: /* whileStatement: WHILE LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 332 "parser.y"
                                                            {
        (yyval.node) = create_node("whileStatement", NULL);
        add_child((yyval.node), create_node("keyword", "while"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1732 "parser.tab.c"
    break;

  case 49: /* doStatement: DO subroutineCall SEMICOLON  */
#line 345 "parser.y"
                                {
        (yyval.node) = create_node("doStatement", NULL);
        add_child((yyval.node), create_node("keyword", "do"));
        take_children((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1743 "parser.tab.c"
    break;

  case 50: /* returnStatement: RETURN SEMICOLON  */
#line 354 "parser.y"
                     {
        (yyval.node) = create_node("returnStatement", NULL);
        add_child((yyval.node), create_node("keyword", "return"));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1753 "parser.tab.c"
    break;

  case 51: /* returnStatement: RETURN expression SEMICOLON  */
#line 359 "parser.y"
                                  {
        (yyval.node) = create_node("returnStatement", NULL);
        add_child((yyval.node), create_node("keyword", "return"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1764 "parser.tab.c"
    break;

  case 52: /* expressions: expression  */
#line 368 "parser.y"
               {
        (yyval.node) = create_node("expressions", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1773 "parser.tab.c"
    break;

  case 53: /* expressions: expressions expression  */
#line 372 "parser.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1782 "parser.tab.c"
    break;

  case 54: /* expression: term  */
#line 379 "parser.y"
         {
        (yyval.node) = create_node("expression", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1791 "parser.tab.c"
    break;

  case 55: /* expression: expression op term  */
#line 383 "parser.y"
                         {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1801 "parser.tab.c"
    break;

  case 56: /* term: INTEGER_CONSTANT  */
#line 391 "parser.y"
                     {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), create_node("integerConstant", (yyvsp[0].sval)));
    }
#line 1810 "parser.tab.c"
    break;

  case 57: /* term: STRING_CONSTANT  */
#line 395 "parser.y"
                      {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), create_node("stringConstant", (yyvsp[0].sval)));
    }
#line 1819 "parser.tab.c"
    break;

  case 58: /* term: keywordConstant  */
#line 399 "parser.y"
                      {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1828 "parser.tab.c"
    break;

  case 59: /* term: varName  */
#line 403 "parser.y"
              {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1837 "parser.tab.c"
    break;

  case 60: /* term: varName LBRACKET expression RBRACKET  */
#line 407 "parser.y"
                                           {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("symbol", "["));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "]"));
    }
#line 1849 "parser.tab.c"
    break;

  case 61: /* term: subroutineCall  */
#line 414 "parser.y"
                     {
        (yyval.node) = create_node("term", NULL);
        take_children((yyval.node), (yyvsp[0].node));
    }
#line 1858 "parser.tab.c"
    break;

  case 62: /* term: LPAREN expression RPAREN  */
#line 418 "parser.y"
                               {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ")"));
    }
#line 1869 "parser.tab.c"
    break;

  case 63: /* term: unaryOp term  */
#line 424 "parser.y"
                   {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1879 "parser.tab.c"
    break;

  case 64: /* subroutineCall: subroutineName LPAREN expressionList RPAREN  */
#line 432 "parser.y"
                                                {
        (yyval.node) = create_node("subroutineCall", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ")"));
    }
#line 1891 "parser.tab.c"
    break;

  case 65: /* subroutineCall: className DOT subroutineName LPAREN expressionList RPAREN  */
#line 439 "parser.y"
                                                                {
        (yyval.node) = create_node("subroutineCall", NULL);
        add_child((yyval.node), (yyvsp[-5].node));
        add_child((yyval.node), create_node("symbol", "."));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ")"));
    }
#line 1905 "parser.tab.c"
    break;

  case 66: /* subroutineCall: varName DOT subroutineName LPAREN expressionList RPAREN  */
#line 448 "parser.y"
                                                              {
        (yyval.node) = create_node("subroutineCall", NULL);
        add_child((yyval.node), (yyvsp[-5].node));
        add_child((yyval.node), create_node("symbol", "."));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ")"));
    }
#line 1919 "parser.tab.c"
    break;

  case 67: /* expressionList: %empty  */
#line 460 "parser.y"
                {
        (yyval.node) = create_node("expressionList", NULL);
    }
#line 1927 "parser.tab.c"
    break;

  case 68: /* expressionList: expression  */
#line 463 "parser.y"
                 {
        (yyval.node) = create_node("expressionList", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1936 "parser.tab.c"
    break;

  case 69: /* expressionList: expressionList COMMA expression  */
#line 467 "parser.y"
                                      {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), create_node("symbol", ","));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1946 "parser.tab.c"
    break;

  case 70: /* op: PLUS  */
#line 475 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "+"));
    }
#line 1955 "parser.tab.c"
    break;

  case 71: /* op: MINUS  */
#line 479 "parser.y"
            {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "-"));
    }
#line 1964 "parser.tab.c"
    break;

  case 72: /* op: MULTIPLY  */
#line 483 "parser.y"
               {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "*"));
    }
#line 1973 "parser.tab.c"
    break;

  case 73: /* op: DIVIDE  */
#line 487 "parser.y"
             {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "/"));
    }
#line 1982 "parser.tab.c"
    break;

  case 74: /* op: AND  */
#line 491 "parser.y"
          {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "&"));
    }
#line 1991 "parser.tab.c"
    break;

  case 75: /* op: OR  */
#line 495 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "|"));
    }
#line 2000 "parser.tab.c"
    break;

  case 76: /* op: LT  */
#line 499 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "<"));
    }
#line 2009 "parser.tab.c"
    break;

  case 77: /* op: GT  */
#line 503 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", ">"));
    }
#line 2018 "parser.tab.c"
    break;

  case 78: /* op: EQ  */
#line 507 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "="));
    }
#line 2027 "parser.tab.c"
    break;

  case 79: /* unaryOp: MINUS  */
#line 514 "parser.y"
          {
        (yyval.node) = create_node("unaryOp", NULL);
        add_child((yyval.node), create_node("symbol", "-"));
    }
#line 2036 "parser.tab.c"
    break;

  case 80: /* unaryOp: NOT  */
#line 518 "parser.y"
          {
        (yyval.node) = create_node("unaryOp", NULL);
        add_child((yyval.node), create_node("symbol", "~"));
    }
#line 2045 "parser.tab.c"
    break;

  case 81: /* keywordConstant: TRUE  */
#line 525 "parser.y"
         {
        (yyval.node) = create_node("keyword", "true");
    }
#line 2053 "parser.tab.c"
    break;

  case 82: /* keywordConstant: FALSE  */
#line 528 "parser.y"
            {
        (yyval.node) = create_node("keyword", "false");
    }
#line 2061 "parser.tab.c"
    break;

  case 83: /* keywordConstant: TK_NULL  */
#line 531 "parser.y"
              {
        (yyval.node) = create_node("keyword", "null");
    }
#line 2069 "parser.tab.c"
    break;

  case 84: /* keywordConstant: THIS  */
#line 534 "parser.y"
           {
        (yyval.node) = create_node("keyword", "this");
    }
#line 2077 "parser.tab.c"
    break;


#line 2081 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 539 "parser.y"

TreeNode* create_node(const char *tag, const char *value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->tag = strdup(tag);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(TreeNode *parent, TreeNode *child) {
    parent->children = realloc(parent->children, sizeof(TreeNode *) * (parent->child_count + 1));
    parent->children[parent->child_count++] = child;
}

void print_tree(TreeNode *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", node->tag);
    if (node->value) {
        printf(" %s ", node->value);
        printf("</%s>\n", node->tag);
    } else {
        printf("\n");
	    for (int i = 0; i < node->child_count; i++) {
            print_tree(node->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", node->tag);
    }  
}

void free_tree(TreeNode *node) {
    if (!node) return;
    free(node->tag);
    if (node->value) free(node->value);
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

void free_node(TreeNode *node) {
    if (!node) return;
    free(node->tag);
    if (node->value) free(node->value);
    free(node->children);
    free(node);
}

void take_children(TreeNode *master, TreeNode *slave) {
    if (!master) return;
    if (!slave) return;
    for (int i = 0; i < slave->child_count; i++)
        add_child(master, slave->children[i]);
    free_node(slave);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (yyparse() != 0) printf("Parsing failed!\n");
    return 0;
}

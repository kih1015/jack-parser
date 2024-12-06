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

// Tree node structure
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
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_STRING_CONSTANT = 25,           /* STRING_CONSTANT  */
  YYSYMBOL_INTEGER_CONSTANT = 26,          /* INTEGER_CONSTANT  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 31,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 32,                  /* RBRACKET  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 38,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 39,                    /* DIVIDE  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_LT = 42,                        /* LT  */
  YYSYMBOL_GT = 43,                        /* GT  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
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
  YYSYMBOL_expressions = 71,               /* expressions  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_op = 74,                        /* op  */
  YYSYMBOL_unaryOp = 75                    /* unaryOp  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

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
       0,    46,    46,    52,    58,    62,    71,    90,    93,   101,
     104,   111,   124,   127,   133,   136,   139,   142,   148,   162,
     165,   168,   175,   178,   184,   187,   192,   201,   214,   217,
     224,   236,   240,   248,   254,   260,   266,   274,   277,   284,
     287,   290,   296,   304,   318,   328,   345,   358,   362,   369,
     373,   381,   385,   389,   395,   403,   407,   411,   415,   419,
     423,   427,   431,   435,   442,   446
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
  "WHILE", "RETURN", "IDENTIFIER", "STRING_CONSTANT", "INTEGER_CONSTANT",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "DOT",
  "COMMA", "SEMICOLON", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "AND", "OR",
  "LT", "GT", "EQ", "NOT", "$accept", "program", "class",
  "classVarDecList", "subroutineDecList", "classVarDec", "classVarType",
  "type", "subroutineDec", "subroutineType", "returnType", "parameterList",
  "subroutineBody", "varDecList", "varDec", "varNameList", "className",
  "subroutineName", "varName", "statements", "statementList", "statement",
  "letStatement", "ifStatement", "whileStatement", "expressions",
  "expression", "term", "op", "unaryOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,    -6,   -75,   -75,    16,   -75,   -75,    32,   -75,     4,
     -75,   -75,    17,    16,   119,   -75,    16,   -75,    14,    47,
     -75,   -75,   -75,   -75,    36,    19,    22,    23,   -75,   -75,
     -75,   -75,   119,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,    16,   -75,   -75,   -75,   -75,   -75,   -75,    19,
     -75,   -11,    16,    16,   -75,     4,    28,   -75,    16,    16,
      62,    77,     2,    19,   -75,    90,   100,    39,    40,   -75,
     -75,   -75,   -75,   -75,     3,   -75,    13,   -75,   -75,   -75,
     -75,   -75,    35,    16,    42,    43,   -75,    44,   110,    51,
     -75,    36,   -75,    41,    19,    24,   -75,   -75,    48,    36,
      46,   -75,   -75,    19,   -75,    67,   -75,    19,   -75,    53,
      30,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,    35,    51,     0,    64,    65,     0,     4,     5,
      52,     3,    36,     2,    47,    49,     0,    33,     0,     0,
       1,    13,    12,     8,     0,     0,     0,     0,    38,    39,
      40,    41,    48,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    54,     7,    53,    14,    15,    16,     0,
      17,     0,     0,     0,    50,     9,     0,    31,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    19,
      20,    21,     6,    10,     0,    32,     0,    42,    37,    37,
      22,    23,     0,     0,     0,     0,    34,     0,     0,    44,
      46,    24,    43,     0,     0,     0,    37,    25,     0,     0,
       0,    28,    18,     0,    45,    37,    26,     0,    29,     0,
       0,    27,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,    49,   -75,   -75,   -75,   -65,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -28,    93,   -75,   -25,   -74,
     -75,   -75,   -75,   -75,   -75,   -75,    -3,   -13,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    62,    23,    24,    49,    73,    74,
      82,    95,   102,   105,   108,    56,    50,    87,    10,    11,
      12,    28,    29,    30,    31,    13,    14,    15,    42,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    19,     1,    43,    84,    85,    69,    70,    71,    81,
      32,    21,    22,    46,    47,    48,    80,   -37,    17,   -37,
      58,   -37,   100,     2,    57,     3,    94,    17,     4,    54,
      72,   109,    20,    59,   103,    25,     5,    26,    75,    27,
       2,    44,     3,     2,     6,     4,    46,    47,    48,    60,
      61,    52,    53,     5,    98,    65,    66,    83,    99,    86,
      17,     6,    63,    64,    63,   112,    78,    79,    96,    97,
      89,    90,    93,    91,   104,   101,   107,    45,   106,   110,
      88,   111,    57,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    67,    55,    18,     0,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    68,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    76,     0,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    77,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    92,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    33,    34,    35,    36,    37,
      38,    39,    40,    41
};

static const yytype_int8 yycheck[] =
{
      25,     4,     3,    16,    78,    79,     4,     5,     6,    74,
      13,     7,     8,    10,    11,    12,    13,    18,    24,    20,
      31,    22,    96,    24,    49,    26,    91,    24,    29,    42,
      28,   105,     0,    44,    99,    18,    37,    20,    63,    22,
      24,    27,    26,    24,    45,    29,    10,    11,    12,    52,
      53,    29,    29,    37,    30,    58,    59,    44,    34,    24,
      24,    45,    34,    35,    34,    35,    27,    27,    27,    94,
      28,    28,    21,    29,    28,    27,     9,    30,   103,   107,
      83,    28,   107,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    30,    44,     1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    36,    37,    38,    39,    40,
      41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    24,    26,    29,    37,    45,    47,    48,    49,
      64,    65,    66,    71,    72,    73,    75,    24,    62,    72,
       0,     7,     8,    51,    52,    18,    20,    22,    67,    68,
      69,    70,    72,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    74,    73,    27,    30,    10,    11,    12,    53,
      62,    64,    29,    29,    73,    49,    61,    64,    31,    44,
      72,    72,    50,    34,    35,    72,    72,    30,    30,     4,
       5,     6,    28,    54,    55,    64,    32,    35,    27,    27,
      13,    53,    56,    44,    65,    65,    24,    63,    72,    28,
      28,    29,    35,    21,    53,    57,    27,    64,    30,    34,
      65,    27,    58,    53,    28,    59,    64,     9,    60,    65,
      61,    28,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    64,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     6,     0,     2,     0,
       2,     4,     1,     1,     1,     1,     1,     1,     7,     1,
       1,     1,     1,     1,     0,     2,     4,     4,     0,     2,
       3,     1,     3,     1,     1,     1,     1,     0,     2,     1,
       1,     1,     5,     8,     7,    11,     7,     1,     2,     1,
       3,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
        printf("<program>\n");
        print_tree((yyvsp[0].node), 1); // Print the XML representation
        printf("</program>\n");
        free_tree((yyvsp[0].node));     // Free the tree memory
    }
#line 1251 "parser.tab.c"
    break;

  case 3: /* program: statements  */
#line 52 "parser.y"
                 {
        printf("<program>\n");
        print_tree((yyvsp[0].node), 1); // Print the XML representation
        printf("</program>\n");
        free_tree((yyvsp[0].node));     // Free the tree memory
    }
#line 1262 "parser.tab.c"
    break;

  case 4: /* program: class  */
#line 58 "parser.y"
            {
        print_tree((yyvsp[0].node), 0); // Print the XML representation
        free_tree((yyvsp[0].node));     // Free the tree memory
    }
#line 1271 "parser.tab.c"
    break;

  case 5: /* program: classVarDecList  */
#line 62 "parser.y"
                      {
        printf("<program>\n");
        print_tree((yyvsp[0].node), 1); // Print the XML representation
        printf("</program>\n");
        free_tree((yyvsp[0].node));     // Free the tree memory
    }
#line 1282 "parser.tab.c"
    break;

  case 6: /* class: CLASS className LBRACE classVarDecList subroutineDecList RBRACE  */
#line 71 "parser.y"
                                                                    {
        (yyval.node) = create_node("class", NULL);
        add_child((yyval.node), create_node("keword", "class"));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", "{"));
        for (int i = 0; i < (yyvsp[-2].node)->child_count; i++) {
            add_child((yyval.node), (yyvsp[-2].node)->children[i]);
        }
        free_node((yyvsp[-2].node));
        for (int i = 0; i < (yyvsp[-1].node)->child_count; i++) {
            add_child((yyval.node), (yyvsp[-1].node)->children[i]);
        }
        free_node((yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1302 "parser.tab.c"
    break;

  case 7: /* classVarDecList: %empty  */
#line 90 "parser.y"
    {
        (yyval.node) = create_node("classVarDecList", NULL);
    }
#line 1310 "parser.tab.c"
    break;

  case 8: /* classVarDecList: classVarDecList classVarDec  */
#line 93 "parser.y"
                                  {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1319 "parser.tab.c"
    break;

  case 9: /* subroutineDecList: %empty  */
#line 101 "parser.y"
    {
        (yyval.node) = create_node("subroutineDecList", NULL);
    }
#line 1327 "parser.tab.c"
    break;

  case 10: /* subroutineDecList: subroutineDecList subroutineDec  */
#line 104 "parser.y"
                                      {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1336 "parser.tab.c"
    break;

  case 11: /* classVarDec: classVarType type varNameList SEMICOLON  */
#line 111 "parser.y"
                                            {
        (yyval.node) = create_node("classVarDec", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-2].node));
        for (int i = 0; i < (yyvsp[-1].node)->child_count; i++) {
            add_child((yyval.node), (yyvsp[-1].node)->children[i]);
        }
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1350 "parser.tab.c"
    break;

  case 12: /* classVarType: STATIC  */
#line 124 "parser.y"
           {
        (yyval.node) = create_node("keyword", "static");
    }
#line 1358 "parser.tab.c"
    break;

  case 13: /* classVarType: FIELD  */
#line 127 "parser.y"
            {
        (yyval.node) = create_node("keyword", "field");
    }
#line 1366 "parser.tab.c"
    break;

  case 14: /* type: INT  */
#line 133 "parser.y"
        {
        (yyval.node) = create_node("keword", "int");
    }
#line 1374 "parser.tab.c"
    break;

  case 15: /* type: CHAR  */
#line 136 "parser.y"
           {
        (yyval.node) = create_node("keword", "char");
    }
#line 1382 "parser.tab.c"
    break;

  case 16: /* type: BOOLEAN  */
#line 139 "parser.y"
              {
        (yyval.node) = create_node("keword", "boolean");
    }
#line 1390 "parser.tab.c"
    break;

  case 17: /* type: className  */
#line 142 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1398 "parser.tab.c"
    break;

  case 18: /* subroutineDec: subroutineType returnType subroutineName LPAREN parameterList RPAREN subroutineBody  */
#line 148 "parser.y"
                                                                                        {
        (yyval.node) = create_node("subroutineDec", NULL);
        add_child((yyval.node), (yyvsp[-6].node));  // subroutineType: 'constructor', 'function', or 'method'
        add_child((yyval.node), (yyvsp[-5].node));  // returnType: 'void' or type
        add_child((yyval.node), (yyvsp[-4].node));  // subroutineName
        add_child((yyval.node), create_node("symbol", "("));  // LPAREN
        add_child((yyval.node), (yyvsp[-2].node));  // parameterList
        add_child((yyval.node), create_node("symbol", ")"));  // RPAREN
        add_child((yyval.node), (yyvsp[0].node));  // subroutineBody
    }
#line 1413 "parser.tab.c"
    break;

  case 19: /* subroutineType: CONSTRUCTOR  */
#line 162 "parser.y"
                {
        (yyval.node) = create_node("keyword", "constructor");
    }
#line 1421 "parser.tab.c"
    break;

  case 20: /* subroutineType: FUNCTION  */
#line 165 "parser.y"
               {
        (yyval.node) = create_node("keyword", "function");
    }
#line 1429 "parser.tab.c"
    break;

  case 21: /* subroutineType: METHOD  */
#line 168 "parser.y"
             {
        (yyval.node) = create_node("keyword", "method");
    }
#line 1437 "parser.tab.c"
    break;

  case 22: /* returnType: VOID  */
#line 175 "parser.y"
         {
        (yyval.node) = create_node("symbol", "void");
    }
#line 1445 "parser.tab.c"
    break;

  case 23: /* returnType: type  */
#line 178 "parser.y"
           {
        (yyval.node) = (yyvsp[0].node);  // Pass the type node directly
    }
#line 1453 "parser.tab.c"
    break;

  case 24: /* parameterList: %empty  */
#line 184 "parser.y"
                          {
        (yyval.node) = create_node("parameterList", NULL);         // Empty parameter list
    }
#line 1461 "parser.tab.c"
    break;

  case 25: /* parameterList: type varName  */
#line 187 "parser.y"
                   {
        (yyval.node) = create_node("parameterList", NULL);
        add_child((yyval.node), (yyvsp[-1].node));                               // type
        add_child((yyval.node), (yyvsp[0].node));                               // varName
    }
#line 1471 "parser.tab.c"
    break;

  case 26: /* parameterList: parameterList COMMA type varName  */
#line 192 "parser.y"
                                       {
        (yyval.node) = (yyvsp[-3].node);
        add_child((yyval.node), create_node("symbol", ","));       // COMMA
        add_child((yyval.node), (yyvsp[-1].node));                               // type
        add_child((yyval.node), (yyvsp[0].node));                               // varName
    }
#line 1482 "parser.tab.c"
    break;

  case 27: /* subroutineBody: LBRACE varDecList statements RBRACE  */
#line 201 "parser.y"
                                        {
        (yyval.node) = create_node("subroutineBody", NULL);
        add_child((yyval.node), create_node("symbol", "{"));
        for (int i = 0; i < (yyvsp[-2].node)->child_count; i++) {
            add_child((yyval.node), (yyvsp[-2].node)->children[i]);
        }
        add_child((yyval.node), (yyvsp[-1].node)); // statements
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1496 "parser.tab.c"
    break;

  case 28: /* varDecList: %empty  */
#line 214 "parser.y"
                {
        (yyval.node) = create_node("varDecList", NULL);
    }
#line 1504 "parser.tab.c"
    break;

  case 29: /* varDecList: varDecList varDec  */
#line 217 "parser.y"
                        {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1513 "parser.tab.c"
    break;

  case 30: /* varDec: VAR varNameList SEMICOLON  */
#line 224 "parser.y"
                              {
        (yyval.node) = create_node("varDec", NULL);
        add_child((yyval.node), create_node("keyword", "var"));
        for (int i = 0; i < (yyvsp[-1].node)->child_count; i++) {
            add_child((yyval.node), (yyvsp[-1].node)->children[i]);
        }
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1526 "parser.tab.c"
    break;

  case 31: /* varNameList: varName  */
#line 236 "parser.y"
            {
        (yyval.node) = create_node("varNameList", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1535 "parser.tab.c"
    break;

  case 32: /* varNameList: varNameList COMMA varName  */
#line 240 "parser.y"
                                {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), create_node("symbol", ","));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1545 "parser.tab.c"
    break;

  case 33: /* className: IDENTIFIER  */
#line 248 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1553 "parser.tab.c"
    break;

  case 34: /* subroutineName: IDENTIFIER  */
#line 254 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1561 "parser.tab.c"
    break;

  case 35: /* varName: IDENTIFIER  */
#line 260 "parser.y"
               {
        (yyval.node) = create_node("identifier", (yyvsp[0].sval));
    }
#line 1569 "parser.tab.c"
    break;

  case 36: /* statements: statementList  */
#line 266 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1577 "parser.tab.c"
    break;

  case 37: /* statementList: %empty  */
#line 274 "parser.y"
    {
        (yyval.node) = create_node("statements", NULL);
    }
#line 1585 "parser.tab.c"
    break;

  case 38: /* statementList: statementList statement  */
#line 277 "parser.y"
                              {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1594 "parser.tab.c"
    break;

  case 39: /* statement: letStatement  */
#line 284 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1602 "parser.tab.c"
    break;

  case 40: /* statement: ifStatement  */
#line 287 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1610 "parser.tab.c"
    break;

  case 41: /* statement: whileStatement  */
#line 290 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1618 "parser.tab.c"
    break;

  case 42: /* letStatement: LET varName EQ expression SEMICOLON  */
#line 296 "parser.y"
                                        {
        (yyval.node) = create_node("letStatement", NULL);
        add_child((yyval.node), create_node("keyword", "let"));
        add_child((yyval.node), (yyvsp[-3].node)); // varName
        add_child((yyval.node), create_node("symbol", "="));
        add_child((yyval.node), (yyvsp[-1].node)); // expression
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1631 "parser.tab.c"
    break;

  case 43: /* letStatement: LET varName LBRACKET expression RBRACKET EQ expression SEMICOLON  */
#line 304 "parser.y"
                                                                       {
        (yyval.node) = create_node("letStatement", NULL);
        add_child((yyval.node), create_node("keyword", "let"));
        add_child((yyval.node), (yyvsp[-6].node)); // varName
        add_child((yyval.node), create_node("symbol", "["));
        add_child((yyval.node), (yyvsp[-4].node)); // expression (index)
        add_child((yyval.node), create_node("symbol", "]"));
        add_child((yyval.node), create_node("symbol", "="));
        add_child((yyval.node), (yyvsp[-1].node)); // expression
        add_child((yyval.node), create_node("symbol", ";"));
    }
#line 1647 "parser.tab.c"
    break;

  case 44: /* ifStatement: IF LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 318 "parser.y"
                                                         {
        (yyval.node) = create_node("ifStatement", NULL);
        add_child((yyval.node), create_node("keyword", "if"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-4].node)); // expression
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node)); // statements
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1662 "parser.tab.c"
    break;

  case 45: /* ifStatement: IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE  */
#line 328 "parser.y"
                                                                                         {
        (yyval.node) = create_node("ifStatement", NULL);
        add_child((yyval.node), create_node("keyword", "if"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-8].node)); // expression
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-5].node)); // if statements
        add_child((yyval.node), create_node("symbol", "}"));
        add_child((yyval.node), create_node("keyword", "else"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node)); // else statements
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1681 "parser.tab.c"
    break;

  case 46: /* whileStatement: WHILE LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 345 "parser.y"
                                                            {
        (yyval.node) = create_node("whileStatement", NULL);
        add_child((yyval.node), create_node("keword", "while"));
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), create_node("symbol", ")"));
        add_child((yyval.node), create_node("symbol", "{"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", "}"));
    }
#line 1696 "parser.tab.c"
    break;

  case 47: /* expressions: expression  */
#line 358 "parser.y"
               {
        (yyval.node) = create_node("expressions", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1705 "parser.tab.c"
    break;

  case 48: /* expressions: expressions expression  */
#line 362 "parser.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1714 "parser.tab.c"
    break;

  case 49: /* expression: term  */
#line 369 "parser.y"
         {
        (yyval.node) = create_node("expression", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1723 "parser.tab.c"
    break;

  case 50: /* expression: expression op term  */
#line 373 "parser.y"
                         {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1733 "parser.tab.c"
    break;

  case 51: /* term: INTEGER_CONSTANT  */
#line 381 "parser.y"
                     {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), create_node("integerConstant", strdup((yyvsp[0].sval))));
    }
#line 1742 "parser.tab.c"
    break;

  case 52: /* term: varName  */
#line 385 "parser.y"
              {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1751 "parser.tab.c"
    break;

  case 53: /* term: LPAREN expression RPAREN  */
#line 389 "parser.y"
                               {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), create_node("symbol", "("));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("symbol", ")"));
    }
#line 1762 "parser.tab.c"
    break;

  case 54: /* term: unaryOp term  */
#line 395 "parser.y"
                   {
        (yyval.node) = create_node("term", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1772 "parser.tab.c"
    break;

  case 55: /* op: PLUS  */
#line 403 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "+"));
    }
#line 1781 "parser.tab.c"
    break;

  case 56: /* op: MINUS  */
#line 407 "parser.y"
            {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "-"));
    }
#line 1790 "parser.tab.c"
    break;

  case 57: /* op: MULTIPLY  */
#line 411 "parser.y"
               {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "*"));
    }
#line 1799 "parser.tab.c"
    break;

  case 58: /* op: DIVIDE  */
#line 415 "parser.y"
             {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "/"));
    }
#line 1808 "parser.tab.c"
    break;

  case 59: /* op: AND  */
#line 419 "parser.y"
          {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "&"));
    }
#line 1817 "parser.tab.c"
    break;

  case 60: /* op: OR  */
#line 423 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "|"));
    }
#line 1826 "parser.tab.c"
    break;

  case 61: /* op: LT  */
#line 427 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "<"));
    }
#line 1835 "parser.tab.c"
    break;

  case 62: /* op: GT  */
#line 431 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", ">"));
    }
#line 1844 "parser.tab.c"
    break;

  case 63: /* op: EQ  */
#line 435 "parser.y"
         {
        (yyval.node) = create_node("op", NULL);
        add_child((yyval.node), create_node("symbol", "="));
    }
#line 1853 "parser.tab.c"
    break;

  case 64: /* unaryOp: MINUS  */
#line 442 "parser.y"
          {
        (yyval.node) = create_node("unaryOp", NULL);
        add_child((yyval.node), create_node("symbol", "-"));
    }
#line 1862 "parser.tab.c"
    break;

  case 65: /* unaryOp: NOT  */
#line 446 "parser.y"
          {
        (yyval.node) = create_node("unaryOp", NULL);
        add_child((yyval.node), create_node("symbol", "~"));
    }
#line 1871 "parser.tab.c"
    break;


#line 1875 "parser.tab.c"

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

#line 452 "parser.y"

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

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (yyparse() == 0) {
        printf("Parsing complete!\n");
    } else {
        printf("Parsing failed!\n");
    }
    return 0;
}

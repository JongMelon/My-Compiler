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
#line 6 "syntax.y"


#include <stdio.h>
#include <string>
#include "Tree.h"

int yylex(void);
void yyerror(const char *s);


#line 82 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 9,                   /* CONTINUE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_IDENT = 11,                     /* IDENT  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_INTCONST = 13,                  /* INTCONST  */
  YYSYMBOL_LEFTSQB = 14,                   /* LEFTSQB  */
  YYSYMBOL_RIGHTSQB = 15,                  /* RIGHTSQB  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LEFTBRACE = 18,                 /* LEFTBRACE  */
  YYSYMBOL_RIGHTBRACE = 19,                /* RIGHTBRACE  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_25_ = 25,                       /* '<'  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '!'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LOR = 35,                       /* LOR  */
  YYSYMBOL_LAND = 36,                      /* LAND  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_CompUnit = 38,                  /* CompUnit  */
  YYSYMBOL_CompList = 39,                  /* CompList  */
  YYSYMBOL_DecOrDef = 40,                  /* DecOrDef  */
  YYSYMBOL_Decl = 41,                      /* Decl  */
  YYSYMBOL_ConstDecl = 42,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 43,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 44,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 45,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 46,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 47,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 48,                /* VarDefList  */
  YYSYMBOL_VarDef = 49,                    /* VarDef  */
  YYSYMBOL_ConstArrayIndex = 50,           /* ConstArrayIndex  */
  YYSYMBOL_InitVal = 51,                   /* InitVal  */
  YYSYMBOL_InitValList = 52,               /* InitValList  */
  YYSYMBOL_FuncDef = 53,                   /* FuncDef  */
  YYSYMBOL_VarType = 54,                   /* VarType  */
  YYSYMBOL_FuncType = 55,                  /* FuncType  */
  YYSYMBOL_FuncFParamList = 56,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 57,                /* FuncFParam  */
  YYSYMBOL_ArrayIndex = 58,                /* ArrayIndex  */
  YYSYMBOL_Block = 59,                     /* Block  */
  YYSYMBOL_BlockItemList = 60,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 61,                 /* BlockItem  */
  YYSYMBOL_Stmt = 62,                      /* Stmt  */
  YYSYMBOL_ConstExp = 63,                  /* ConstExp  */
  YYSYMBOL_Exp = 64,                       /* Exp  */
  YYSYMBOL_Cond = 65,                      /* Cond  */
  YYSYMBOL_LVal = 66,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 67,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 68,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 69,                   /* UnaryOp  */
  YYSYMBOL_FuncRParamList = 70,            /* FuncRParamList  */
  YYSYMBOL_MulExp = 71,                    /* MulExp  */
  YYSYMBOL_AddExp = 72,                    /* AddExp  */
  YYSYMBOL_RelExp = 73,                    /* RelExp  */
  YYSYMBOL_EqExp = 74,                     /* EqExp  */
  YYSYMBOL_LAndExp = 75,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 76                     /* LOrExp  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
       2,     2,     2,    27,     2,     2,     2,    24,     2,     2,
       2,     2,    22,    20,    28,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      25,    30,    26,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    31,    32,    33,    34,    35,
      36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    64,    69,    78,    84,    91,    97,   105,
     113,   118,   126,   133,   143,   148,   153,   161,   166,   174,
     181,   186,   194,   200,   207,   214,   224,   229,   237,   243,
     248,   256,   261,   269,   276,   286,   293,   298,   305,   310,
     318,   325,   332,   342,   347,   355,   359,   366,   371,   379,
     385,   393,   400,   405,   411,   417,   424,   432,   439,   444,
     449,   454,   462,   469,   476,   483,   489,   498,   504,   510,
     518,   524,   530,   537,   546,   549,   552,   557,   562,   570,
     576,   584,   592,   602,   608,   616,   626,   632,   640,   648,
     656,   666,   672,   680,   690,   696,   705,   711
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "INT", "IF",
  "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "IDENT", "VOID",
  "INTCONST", "LEFTSQB", "RIGHTSQB", "LPAREN", "RPAREN", "LEFTBRACE",
  "RIGHTBRACE", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'!'",
  "','", "';'", "'='", "LE", "GE", "EQ", "NE", "LOR", "LAND", "$accept",
  "CompUnit", "CompList", "DecOrDef", "Decl", "ConstDecl", "ConstDefList",
  "ConstDef", "ConstInitVal", "ConstInitValList", "VarDecl", "VarDefList",
  "VarDef", "ConstArrayIndex", "InitVal", "InitValList", "FuncDef",
  "VarType", "FuncType", "FuncFParamList", "FuncFParam", "ArrayIndex",
  "Block", "BlockItemList", "BlockItem", "Stmt", "ConstExp", "Exp", "Cond",
  "LVal", "PrimaryExp", "UnaryExp", "UnaryOp", "FuncRParamList", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,    13,  -144,  -144,     9,    83,  -144,  -144,  -144,  -144,
    -144,    16,  -144,    35,  -144,  -144,    -1,    -9,    37,     5,
      39,    42,   217,     4,   181,    17,  -144,    61,   193,    18,
    -144,    35,    -2,  -144,   217,  -144,  -144,  -144,    64,  -144,
    -144,  -144,  -144,   217,    97,     2,    73,    82,    77,    68,
     157,  -144,  -144,   217,   181,    45,  -144,   169,  -144,  -144,
     193,  -144,   217,   205,    99,    80,  -144,  -144,   217,   217,
     217,   217,   217,    96,  -144,   104,    73,    13,  -144,    94,
      92,   109,  -144,  -144,   101,   111,  -144,   116,  -144,   120,
     115,   217,  -144,  -144,  -144,  -144,    97,    97,   123,   134,
     126,   128,   145,  -144,  -144,  -144,    61,  -144,   140,   133,
    -144,   135,   122,   148,  -144,  -144,   181,  -144,  -144,   193,
    -144,  -144,   217,  -144,   152,   217,   217,  -144,  -144,  -144,
     142,  -144,  -144,  -144,   217,   155,  -144,  -144,  -144,  -144,
     162,     2,   102,    43,   147,   146,   174,  -144,   164,    99,
      53,   217,   217,   217,   217,   217,   217,   217,   217,    53,
    -144,   180,     2,     2,     2,     2,   102,   102,    43,   147,
    -144,    53,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    37,    36,     0,     2,     3,     5,     7,     8,
       6,     0,    35,     0,     1,     4,    22,     0,    20,     0,
       0,    10,     0,     0,     0,    24,    19,     0,     0,     0,
       9,     0,    65,    69,     0,    74,    75,    76,     0,    62,
      68,    70,    79,     0,    83,    63,     0,     0,     0,    38,
       0,    23,    28,     0,     0,    22,    21,     0,    12,    14,
       0,    11,     0,     0,    66,     0,    26,    73,     0,     0,
       0,     0,     0,     0,    33,    40,     0,     0,    29,    31,
       0,     0,    25,    15,    17,     0,    13,     0,    71,    77,
       0,     0,    67,    80,    81,    82,    84,    85,     0,     0,
       0,     0,     0,    45,    52,    49,     0,    54,     0,    47,
      50,     0,    68,     0,    34,    39,     0,    30,    27,     0,
      16,    43,     0,    72,     0,     0,     0,    58,    59,    60,
       0,    46,    48,    53,     0,    41,    32,    18,    78,    44,
       0,    86,    91,    94,    96,    64,     0,    61,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    55,    87,    88,    89,    90,    92,    93,    95,    97,
      57,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   190,   -72,  -144,   167,  -144,   -26,    81,
    -144,   176,  -144,   186,   -21,    91,  -144,   209,   -68,   138,
    -144,    84,   -40,   103,  -144,  -143,   -11,   -24,    98,   -69,
    -144,   -25,  -144,    95,    12,  -101,   -67,    66,    69,  -144
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    21,    84,    85,
       9,    17,    18,    25,    79,    80,    10,    47,    11,    48,
      49,    64,   107,   108,   109,   110,    59,    39,   140,    40,
      41,    42,    43,    90,    44,    45,   142,   143,   144,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,   105,    58,    51,   112,   106,    74,   161,    12,    14,
      65,    38,    62,    22,    63,    23,   170,    12,    67,    22,
      26,    46,    71,    72,   141,   141,    52,    16,   172,    24,
      52,    53,    53,    82,    86,    28,   114,   105,    87,    89,
     112,   106,    81,    93,    94,    95,    19,    54,    60,   111,
     162,   163,   164,   165,   141,   141,   141,   141,    98,    22,
      99,   100,   101,   102,    32,    27,    33,   124,    30,    34,
      31,    73,    55,    35,    36,    24,   155,   156,   130,    66,
      37,   112,   104,    96,    97,   111,     1,     2,   166,   167,
     112,    73,    52,    75,    76,     3,    77,    92,    89,     1,
       2,    98,   112,    99,   100,   101,   102,    32,     3,    33,
     148,   117,    34,    91,    73,   103,    35,    36,   113,    68,
      69,    70,   116,    37,   118,   104,   111,   151,   152,   119,
     120,   121,   123,   153,   154,   111,     1,     2,    98,   125,
      99,   100,   101,   102,    32,     3,    33,   111,   122,    34,
     126,    73,   134,    35,    36,   127,    32,   128,    33,   131,
      37,    34,   104,   135,   133,    35,    36,   139,    32,    62,
      33,   147,    37,    34,   129,    50,    78,    35,    36,   150,
      32,   158,    33,   157,    37,    34,   171,    57,    83,    35,
      36,   159,    32,   160,    33,    15,    37,    34,    61,    50,
     137,    35,    36,    56,    32,    29,    33,   136,    37,    34,
      13,    57,   132,    35,    36,   115,    32,   138,    33,   149,
      37,    34,    88,   168,   146,    35,    36,   169,    32,     0,
      33,     0,    37,    34,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,    37
};

static const yytype_int16 yycheck[] =
{
      24,    73,    28,    24,    73,    73,    46,   150,     4,     0,
      34,    22,    14,    14,    16,    16,   159,     4,    43,    14,
      29,    17,    20,    21,   125,   126,    50,    11,   171,    30,
      54,    14,    14,    54,    60,    30,    76,   109,    62,    63,
     109,   109,    53,    68,    69,    70,    11,    30,    30,    73,
     151,   152,   153,   154,   155,   156,   157,   158,     5,    14,
       7,     8,     9,    10,    11,    28,    13,    91,    29,    16,
      28,    18,    11,    20,    21,    30,    33,    34,   102,    15,
      27,   150,    29,    71,    72,   109,     3,     4,   155,   156,
     159,    18,   116,    11,    17,    12,    28,    17,   122,     3,
       4,     5,   171,     7,     8,     9,    10,    11,    12,    13,
     134,    19,    16,    14,    18,    19,    20,    21,    14,    22,
      23,    24,    28,    27,    15,    29,   150,    25,    26,    28,
      19,    15,    17,    31,    32,   159,     3,     4,     5,    16,
       7,     8,     9,    10,    11,    12,    13,   171,    28,    16,
      16,    18,    30,    20,    21,    29,    11,    29,    13,    19,
      27,    16,    29,    15,    29,    20,    21,    15,    11,    14,
      13,    29,    27,    16,    29,    18,    19,    20,    21,    17,
      11,    35,    13,    36,    27,    16,     6,    18,    19,    20,
      21,    17,    11,    29,    13,     5,    27,    16,    31,    18,
     119,    20,    21,    27,    11,    19,    13,   116,    27,    16,
       1,    18,   109,    20,    21,    77,    11,   122,    13,   135,
      27,    16,    17,   157,   126,    20,    21,   158,    11,    -1,
      13,    -1,    27,    16,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    12,    38,    39,    40,    41,    42,    47,
      53,    55,     4,    54,     0,    40,    11,    48,    49,    11,
      43,    44,    14,    16,    30,    50,    29,    28,    30,    50,
      29,    28,    11,    13,    16,    20,    21,    27,    63,    64,
      66,    67,    68,    69,    71,    72,    17,    54,    56,    57,
      18,    51,    64,    14,    30,    11,    48,    18,    45,    63,
      30,    43,    14,    16,    58,    64,    15,    68,    22,    23,
      24,    20,    21,    18,    59,    11,    17,    28,    19,    51,
      52,    63,    51,    19,    45,    46,    45,    64,    17,    64,
      70,    14,    17,    68,    68,    68,    71,    71,     5,     7,
       8,     9,    10,    19,    29,    41,    55,    59,    60,    61,
      62,    64,    66,    14,    59,    56,    28,    19,    15,    28,
      19,    15,    28,    17,    64,    16,    16,    29,    29,    29,
      64,    19,    60,    29,    30,    15,    52,    46,    70,    15,
      65,    72,    73,    74,    75,    76,    65,    29,    64,    58,
      17,    25,    26,    31,    32,    33,    34,    36,    35,    17,
      29,    62,    72,    72,    72,    72,    73,    73,    74,    75,
      62,     6,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    52,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    65,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       1,     3,     3,     4,     1,     2,     3,     1,     3,     3,
       1,     3,     1,     3,     2,     4,     3,     4,     1,     2,
       3,     1,     3,     5,     6,     1,     1,     1,     1,     3,
       2,     4,     5,     3,     4,     2,     3,     1,     2,     1,
       1,     4,     1,     2,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     1,     1,     1,     2,     3,     1,     1,
       1,     3,     4,     2,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3
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
  case 2: /* CompUnit: CompList  */
#line 53 "syntax.y"
           {
    auto compUnit = new CompUnit();
    compUnit->compList = shared_ptr<CompList>((CompList* )(yyvsp[0].tree));
    (yyval.tree) = compUnit;
    std::cout << "digraph \" \"{" << std::endl;
    std::cout << "node [shape = record,height=.1]" << std::endl;
    compUnit->print(0, "");
    std::cout << "}" << std::endl;
}
#line 1284 "syntax.tab.c"
    break;

  case 3: /* CompList: DecOrDef  */
#line 64 "syntax.y"
           {
    auto compList = new CompList();
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )(yyvsp[0].tree));
    (yyval.tree) = compList;
}
#line 1294 "syntax.tab.c"
    break;

  case 4: /* CompList: CompList DecOrDef  */
#line 69 "syntax.y"
                    {
    auto compList = new CompList();
    compList->if_more_CompList = true;
    compList->compList = shared_ptr<CompList>((CompList* )(yyvsp[-1].tree));
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )(yyvsp[0].tree));
    (yyval.tree) = compList;
}
#line 1306 "syntax.tab.c"
    break;

  case 5: /* DecOrDef: Decl  */
#line 78 "syntax.y"
       {
    auto decOrDef = new DeclOrDef();
    decOrDef->if_decl = true;
    decOrDef->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1317 "syntax.tab.c"
    break;

  case 6: /* DecOrDef: FuncDef  */
#line 84 "syntax.y"
          {
    auto decOrDef = new DeclOrDef();
    decOrDef->funcDef = shared_ptr<FuncDef>((FuncDef* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1327 "syntax.tab.c"
    break;

  case 7: /* Decl: ConstDecl  */
#line 91 "syntax.y"
            {
    auto decl = new Decl();
    decl->decType = DecType::ConstDecl;
    decl->constDecl = shared_ptr<ConstDecl>((ConstDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1338 "syntax.tab.c"
    break;

  case 8: /* Decl: VarDecl  */
#line 97 "syntax.y"
          {
    auto decl = new Decl();
    decl->decType = DecType::VarDecl;
    decl->varDecl = shared_ptr<VarDecl>((VarDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1349 "syntax.tab.c"
    break;

  case 9: /* ConstDecl: CONST VarType ConstDefList ';'  */
#line 105 "syntax.y"
                                 {
    auto constDecl = new ConstDecl();
    constDecl->varType = shared_ptr<VarType>((VarType* )(yyvsp[-2].tree));
    constDecl->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[-1].tree));
    (yyval.tree) = constDecl;
}
#line 1360 "syntax.tab.c"
    break;

  case 10: /* ConstDefList: ConstDef  */
#line 113 "syntax.y"
           {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[0].tree));
    (yyval.tree) = constDefList;
}
#line 1370 "syntax.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 118 "syntax.y"
                            {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[-2].tree));
    constDefList->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[0].tree));
    (yyval.tree) = constDefList;
}
#line 1381 "syntax.tab.c"
    break;

  case 12: /* ConstDef: IDENT '=' ConstInitVal  */
#line 126 "syntax.y"
                         {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Var;
    constDef->ident = *((yyvsp[-2].sval));
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1393 "syntax.tab.c"
    break;

  case 13: /* ConstDef: IDENT ConstArrayIndex '=' ConstInitVal  */
#line 133 "syntax.y"
                                         {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Array;
    constDef->ident = *((yyvsp[-3].sval));
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1406 "syntax.tab.c"
    break;

  case 14: /* ConstInitVal: ConstExp  */
#line 143 "syntax.y"
           {
    auto constInitVal = new ConstInitVal();
    constInitVal->constExp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[0].tree));
    (yyval.tree) = constInitVal;
}
#line 1416 "syntax.tab.c"
    break;

  case 15: /* ConstInitVal: LEFTBRACE RIGHTBRACE  */
#line 148 "syntax.y"
                       {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    (yyval.tree) = constInitVal;
}
#line 1426 "syntax.tab.c"
    break;

  case 16: /* ConstInitVal: LEFTBRACE ConstInitValList RIGHTBRACE  */
#line 153 "syntax.y"
                                        {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    constInitVal->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[-1].tree));
    (yyval.tree) = constInitVal;
}
#line 1437 "syntax.tab.c"
    break;

  case 17: /* ConstInitValList: ConstInitVal  */
#line 161 "syntax.y"
               {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1447 "syntax.tab.c"
    break;

  case 18: /* ConstInitValList: ConstInitVal ',' ConstInitValList  */
#line 166 "syntax.y"
                                    {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[-2].tree));
    constInitValList->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1458 "syntax.tab.c"
    break;

  case 19: /* VarDecl: FuncType VarDefList ';'  */
#line 174 "syntax.y"
                          {
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-1].tree));
    (yyval.tree) = varDecl;
}
#line 1468 "syntax.tab.c"
    break;

  case 20: /* VarDefList: VarDef  */
#line 181 "syntax.y"
         {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[0].tree));
    (yyval.tree) = varDefList;
}
#line 1478 "syntax.tab.c"
    break;

  case 21: /* VarDefList: VarDef ',' VarDefList  */
#line 186 "syntax.y"
                        {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[-2].tree));
    varDefList->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[0].tree));
    (yyval.tree) = varDefList;
}
#line 1489 "syntax.tab.c"
    break;

  case 22: /* VarDef: IDENT  */
#line 194 "syntax.y"
        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[0].sval));
    (yyval.tree) = varDef;
}
#line 1500 "syntax.tab.c"
    break;

  case 23: /* VarDef: IDENT '=' InitVal  */
#line 200 "syntax.y"
                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[-2].sval));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1512 "syntax.tab.c"
    break;

  case 24: /* VarDef: IDENT ConstArrayIndex  */
#line 207 "syntax.y"
                        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-1].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1524 "syntax.tab.c"
    break;

  case 25: /* VarDef: IDENT ConstArrayIndex '=' InitVal  */
#line 214 "syntax.y"
                                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-3].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1537 "syntax.tab.c"
    break;

  case 26: /* ConstArrayIndex: LEFTSQB ConstExp RIGHTSQB  */
#line 224 "syntax.y"
                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    (yyval.tree) = constArrayIndex;
}
#line 1547 "syntax.tab.c"
    break;

  case 27: /* ConstArrayIndex: ConstArrayIndex LEFTSQB ConstExp RIGHTSQB  */
#line 229 "syntax.y"
                                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-3].tree));
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    (yyval.tree) = constArrayIndex;
}
#line 1558 "syntax.tab.c"
    break;

  case 28: /* InitVal: Exp  */
#line 237 "syntax.y"
      {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Var;
    initVal->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = initVal;
}
#line 1569 "syntax.tab.c"
    break;

  case 29: /* InitVal: LEFTBRACE RIGHTBRACE  */
#line 243 "syntax.y"
                       {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    (yyval.tree) = initVal;
}
#line 1579 "syntax.tab.c"
    break;

  case 30: /* InitVal: LEFTBRACE InitValList RIGHTBRACE  */
#line 248 "syntax.y"
                                   {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    initVal->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[-1].tree));
    (yyval.tree) = initVal;
}
#line 1590 "syntax.tab.c"
    break;

  case 31: /* InitValList: InitVal  */
#line 256 "syntax.y"
          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = initValList;
}
#line 1600 "syntax.tab.c"
    break;

  case 32: /* InitValList: InitVal ',' InitValList  */
#line 261 "syntax.y"
                          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[-2].tree));
    initValList->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[0].tree));
    (yyval.tree) = initValList;
}
#line 1611 "syntax.tab.c"
    break;

  case 33: /* FuncDef: FuncType IDENT LPAREN RPAREN Block  */
#line 269 "syntax.y"
                                     {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-4].tree));
    funcDef->ident = *((yyvsp[-3].sval));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1623 "syntax.tab.c"
    break;

  case 34: /* FuncDef: FuncType IDENT LPAREN FuncFParamList RPAREN Block  */
#line 276 "syntax.y"
                                                    {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-5].tree));
    funcDef->ident = *((yyvsp[-4].sval));
    funcDef->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[-2].tree));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1636 "syntax.tab.c"
    break;

  case 35: /* VarType: INT  */
#line 286 "syntax.y"
      {
    auto varType = new VarType();
    varType->type = "int";
    (yyval.tree) = varType;
}
#line 1646 "syntax.tab.c"
    break;

  case 36: /* FuncType: VOID  */
#line 293 "syntax.y"
       {
    auto funcType = new FuncType();
    funcType->type = "void";
    (yyval.tree) = funcType;
}
#line 1656 "syntax.tab.c"
    break;

  case 37: /* FuncType: INT  */
#line 298 "syntax.y"
      {
    auto funcType = new FuncType();
    funcType->type = "int";
    (yyval.tree) = funcType;
}
#line 1666 "syntax.tab.c"
    break;

  case 38: /* FuncFParamList: FuncFParam  */
#line 305 "syntax.y"
             {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[0].tree));
    (yyval.tree) = funcFParamList;
}
#line 1676 "syntax.tab.c"
    break;

  case 39: /* FuncFParamList: FuncFParam ',' FuncFParamList  */
#line 310 "syntax.y"
                                {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[-2].tree));
    funcFParamList->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[0].tree));
    (yyval.tree) = funcFParamList;
}
#line 1687 "syntax.tab.c"
    break;

  case 40: /* FuncFParam: VarType IDENT  */
#line 318 "syntax.y"
                {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-1].tree));
    funcFParam->ident = *((yyvsp[0].sval));
    (yyval.tree) = funcFParam;
}
#line 1699 "syntax.tab.c"
    break;

  case 41: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB  */
#line 325 "syntax.y"
                                 {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-3].tree));
    funcFParam->ident = *((yyvsp[-2].sval));
    (yyval.tree) = funcFParam;
}
#line 1711 "syntax.tab.c"
    break;

  case 42: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB ArrayIndex  */
#line 332 "syntax.y"
                                            {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-4].tree));
    funcFParam->ident = *((yyvsp[-3].sval));
    funcFParam->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = funcFParam;
}
#line 1724 "syntax.tab.c"
    break;

  case 43: /* ArrayIndex: LEFTSQB Exp RIGHTSQB  */
#line 342 "syntax.y"
                       {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = arrayIndex;
}
#line 1734 "syntax.tab.c"
    break;

  case 44: /* ArrayIndex: ArrayIndex LEFTSQB Exp RIGHTSQB  */
#line 347 "syntax.y"
                                  {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[-3].tree));
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = arrayIndex;
}
#line 1745 "syntax.tab.c"
    break;

  case 45: /* Block: LEFTBRACE RIGHTBRACE  */
#line 355 "syntax.y"
                       {
    auto block = new Block();
    (yyval.tree) = block;
}
#line 1754 "syntax.tab.c"
    break;

  case 46: /* Block: LEFTBRACE BlockItemList RIGHTBRACE  */
#line 359 "syntax.y"
                                     {
    auto block = new Block();
    block->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[-1].tree));
    (yyval.tree) = block;
}
#line 1764 "syntax.tab.c"
    break;

  case 47: /* BlockItemList: BlockItem  */
#line 366 "syntax.y"
            {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[0].tree));
    (yyval.tree) = blockItemList;
}
#line 1774 "syntax.tab.c"
    break;

  case 48: /* BlockItemList: BlockItem BlockItemList  */
#line 371 "syntax.y"
                          {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[-1].tree));
    blockItemList->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[0].tree));
    (yyval.tree) = blockItemList;
}
#line 1785 "syntax.tab.c"
    break;

  case 49: /* BlockItem: Decl  */
#line 379 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Decl;
    blockItem->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1796 "syntax.tab.c"
    break;

  case 50: /* BlockItem: Stmt  */
#line 385 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Stmt;
    blockItem->stmt = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1807 "syntax.tab.c"
    break;

  case 51: /* Stmt: LVal '=' Exp ';'  */
#line 393 "syntax.y"
                   {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Assign;
    stmt->lVal = shared_ptr<LVal>((LVal* )(yyvsp[-3].tree));
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 1819 "syntax.tab.c"
    break;

  case 52: /* Stmt: ';'  */
#line 400 "syntax.y"
      {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Empty;
    (yyval.tree) = stmt;
}
#line 1829 "syntax.tab.c"
    break;

  case 53: /* Stmt: Exp ';'  */
#line 405 "syntax.y"
          {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Exp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 1840 "syntax.tab.c"
    break;

  case 54: /* Stmt: Block  */
#line 411 "syntax.y"
        {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Block;
    stmt->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1851 "syntax.tab.c"
    break;

  case 55: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 417 "syntax.y"
                             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::If;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1863 "syntax.tab.c"
    break;

  case 56: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 424 "syntax.y"
                                       {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::IfElse;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-4].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[-2].tree));
    stmt->stmt_if_else = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1876 "syntax.tab.c"
    break;

  case 57: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 432 "syntax.y"
                                {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::While;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_while = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1888 "syntax.tab.c"
    break;

  case 58: /* Stmt: BREAK ';'  */
#line 439 "syntax.y"
            {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Break;
    (yyval.tree) = stmt;
}
#line 1898 "syntax.tab.c"
    break;

  case 59: /* Stmt: CONTINUE ';'  */
#line 444 "syntax.y"
               {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Continue;
    (yyval.tree) = stmt;
}
#line 1908 "syntax.tab.c"
    break;

  case 60: /* Stmt: RETURN ';'  */
#line 449 "syntax.y"
             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Return;
    (yyval.tree) = stmt;
}
#line 1918 "syntax.tab.c"
    break;

  case 61: /* Stmt: RETURN Exp ';'  */
#line 454 "syntax.y"
                 {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::ReturnExp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 1929 "syntax.tab.c"
    break;

  case 62: /* ConstExp: Exp  */
#line 462 "syntax.y"
      {
    auto constExp = new ConstExp();
    constExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = constExp;
}
#line 1939 "syntax.tab.c"
    break;

  case 63: /* Exp: AddExp  */
#line 469 "syntax.y"
         {
    auto exp = new Exp();
    exp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = exp;
}
#line 1949 "syntax.tab.c"
    break;

  case 64: /* Cond: LOrExp  */
#line 476 "syntax.y"
         {
    auto cond = new Cond();
    cond->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[0].tree));
    (yyval.tree) = cond;
}
#line 1959 "syntax.tab.c"
    break;

  case 65: /* LVal: IDENT  */
#line 483 "syntax.y"
        {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Var;
    lVal->ident = *((yyvsp[0].sval));
    (yyval.tree) = lVal;
}
#line 1970 "syntax.tab.c"
    break;

  case 66: /* LVal: IDENT ArrayIndex  */
#line 489 "syntax.y"
                   {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Array;
    lVal->ident = *((yyvsp[-1].sval));
    lVal->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = lVal;
}
#line 1982 "syntax.tab.c"
    break;

  case 67: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 498 "syntax.y"
                    {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Exp;
    primaryExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = primaryExp;
}
#line 1993 "syntax.tab.c"
    break;

  case 68: /* PrimaryExp: LVal  */
#line 504 "syntax.y"
       {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::LVal;
    primaryExp->lVal = shared_ptr<LVal>((LVal* )(yyvsp[0].tree));
    (yyval.tree) = primaryExp;
}
#line 2004 "syntax.tab.c"
    break;

  case 69: /* PrimaryExp: INTCONST  */
#line 510 "syntax.y"
           {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Number;
    primaryExp->number = (yyvsp[0].ival);
    (yyval.tree) = primaryExp;
}
#line 2015 "syntax.tab.c"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 518 "syntax.y"
             {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::PrimaryExp;
    unaryExp->primary_exp = shared_ptr<PrimaryExp>((PrimaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2026 "syntax.tab.c"
    break;

  case 71: /* UnaryExp: IDENT LPAREN RPAREN  */
#line 524 "syntax.y"
                      {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-2].sval));
    (yyval.tree) = unaryExp;
}
#line 2037 "syntax.tab.c"
    break;

  case 72: /* UnaryExp: IDENT LPAREN FuncRParamList RPAREN  */
#line 530 "syntax.y"
                                     {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-3].sval));
    unaryExp->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[-1].tree));
    (yyval.tree) = unaryExp;
}
#line 2049 "syntax.tab.c"
    break;

  case 73: /* UnaryExp: UnaryOp UnaryExp  */
#line 537 "syntax.y"
                   {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = (yyvsp[-1].chval);
    unaryExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2061 "syntax.tab.c"
    break;

  case 74: /* UnaryOp: '+'  */
#line 546 "syntax.y"
      {
    (yyval.chval) = '+';
}
#line 2069 "syntax.tab.c"
    break;

  case 75: /* UnaryOp: '-'  */
#line 549 "syntax.y"
      {
    (yyval.chval) = '-';
}
#line 2077 "syntax.tab.c"
    break;

  case 76: /* UnaryOp: '!'  */
#line 552 "syntax.y"
      {
    (yyval.chval) = '!';
}
#line 2085 "syntax.tab.c"
    break;

  case 77: /* FuncRParamList: Exp  */
#line 557 "syntax.y"
      {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = funcRParamList;
}
#line 2095 "syntax.tab.c"
    break;

  case 78: /* FuncRParamList: Exp ',' FuncRParamList  */
#line 562 "syntax.y"
                         {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[-2].tree));
    funcRParamList->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[0].tree));
    (yyval.tree) = funcRParamList;
}
#line 2106 "syntax.tab.c"
    break;

  case 79: /* MulExp: UnaryExp  */
#line 570 "syntax.y"
           {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::UnaryExp;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2117 "syntax.tab.c"
    break;

  case 80: /* MulExp: MulExp '*' UnaryExp  */
#line 576 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "*";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2130 "syntax.tab.c"
    break;

  case 81: /* MulExp: MulExp '/' UnaryExp  */
#line 584 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "/";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2143 "syntax.tab.c"
    break;

  case 82: /* MulExp: MulExp '%' UnaryExp  */
#line 592 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "%";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2156 "syntax.tab.c"
    break;

  case 83: /* AddExp: MulExp  */
#line 602 "syntax.y"
         {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::MulExp;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2167 "syntax.tab.c"
    break;

  case 84: /* AddExp: AddExp '+' MulExp  */
#line 608 "syntax.y"
                    {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "+";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2180 "syntax.tab.c"
    break;

  case 85: /* AddExp: AddExp '-' MulExp  */
#line 616 "syntax.y"
                    {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "-";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2193 "syntax.tab.c"
    break;

  case 86: /* RelExp: AddExp  */
#line 626 "syntax.y"
         {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::AddExp;
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2204 "syntax.tab.c"
    break;

  case 87: /* RelExp: RelExp '<' AddExp  */
#line 632 "syntax.y"
                    {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2217 "syntax.tab.c"
    break;

  case 88: /* RelExp: RelExp '>' AddExp  */
#line 640 "syntax.y"
                    {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2230 "syntax.tab.c"
    break;

  case 89: /* RelExp: RelExp LE AddExp  */
#line 648 "syntax.y"
                   {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2243 "syntax.tab.c"
    break;

  case 90: /* RelExp: RelExp GE AddExp  */
#line 656 "syntax.y"
                   {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2256 "syntax.tab.c"
    break;

  case 91: /* EqExp: RelExp  */
#line 666 "syntax.y"
         {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::RelExp;
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2267 "syntax.tab.c"
    break;

  case 92: /* EqExp: EqExp EQ RelExp  */
#line 672 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "==";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2280 "syntax.tab.c"
    break;

  case 93: /* EqExp: EqExp NE RelExp  */
#line 680 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "!=";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2293 "syntax.tab.c"
    break;

  case 94: /* LAndExp: EqExp  */
#line 690 "syntax.y"
        {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::EqExp;
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2304 "syntax.tab.c"
    break;

  case 95: /* LAndExp: LAndExp LAND EqExp  */
#line 696 "syntax.y"
                     {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::LAndEqExp;
    lAndExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[-2].tree));
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2316 "syntax.tab.c"
    break;

  case 96: /* LOrExp: LAndExp  */
#line 705 "syntax.y"
          {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LAndExp;
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2327 "syntax.tab.c"
    break;

  case 97: /* LOrExp: LOrExp LOR LAndExp  */
#line 711 "syntax.y"
                     {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LOrLAndExp;
    lOrExp->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[-2].tree));
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2339 "syntax.tab.c"
    break;


#line 2343 "syntax.tab.c"

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

#line 720 "syntax.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main()
{
    freopen("input.sy", "r", stdin);
    freopen("output.dot", "w", stdout);
    yyparse();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


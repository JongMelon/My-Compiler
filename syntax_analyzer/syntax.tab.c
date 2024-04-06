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
#line 1 "syntax.y"


#include <stdio.h>
#include <string>

int yylex(void);
void yyerror(const char *s);


#line 81 "syntax.tab.c"

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
  YYSYMBOL_FuncFParams = 56,               /* FuncFParams  */
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
  YYSYMBOL_FuncRParams = 70,               /* FuncRParams  */
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
#define YYLAST   243

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
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    46,    47,    50,    51,    54,    55,    58,
      61,    62,    65,    66,    69,    70,    71,    74,    75,    78,
      81,    82,    85,    86,    87,    88,    91,    92,    95,    96,
      97,   100,   101,   104,   105,   108,   111,   112,   115,   116,
     120,   121,   122,   125,   126,   129,   130,   133,   134,   137,
     138,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   154,   157,   160,   163,   164,   167,   168,   169,
     172,   173,   174,   175,   178,   179,   180,   183,   184,   187,
     188,   189,   190,   193,   194,   195,   198,   199,   200,   201,
     202,   205,   206,   207,   210,   211,   214,   215
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
  "VarType", "FuncType", "FuncFParams", "FuncFParam", "ArrayIndex",
  "Block", "BlockItemList", "BlockItem", "Stmt", "ConstExp", "Exp", "Cond",
  "LVal", "PrimaryExp", "UnaryExp", "UnaryOp", "FuncRParams", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      61,    23,  -114,  -114,    42,    61,  -114,  -114,  -114,  -114,
    -114,    48,  -114,    73,  -114,  -114,    -2,    91,    93,    18,
      95,    94,   216,    65,    59,    31,  -114,    76,   192,    33,
    -114,    73,    97,  -114,   216,  -114,  -114,  -114,   112,  -114,
    -114,  -114,  -114,   216,    -3,    -4,   110,   118,   113,   103,
     168,  -114,  -114,   216,    59,    46,  -114,   180,  -114,  -114,
     192,  -114,   216,   204,   119,   115,  -114,  -114,   216,   216,
     216,   216,   216,    96,  -114,   120,   110,    23,  -114,  -114,
      43,   124,  -114,  -114,  -114,    55,  -114,   135,  -114,   127,
     131,   216,  -114,  -114,  -114,  -114,    -3,    -3,   136,   140,
     128,   129,     2,  -114,  -114,  -114,    76,  -114,   149,   133,
    -114,   130,   141,   155,  -114,  -114,  -114,    59,  -114,  -114,
     192,  -114,   216,  -114,   158,   216,   216,  -114,  -114,  -114,
     146,  -114,  -114,  -114,   216,   164,  -114,  -114,  -114,  -114,
     163,    -4,    63,    58,   154,   147,   175,  -114,   165,   119,
     156,   216,   216,   216,   216,   216,   216,   216,   216,   156,
    -114,   191,    -4,    -4,    -4,    -4,    63,    63,    58,   154,
    -114,   156,  -114
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
      50,     0,    68,     0,    34,    39,    30,     0,    27,    16,
       0,    43,     0,    72,     0,     0,     0,    58,    59,    60,
       0,    46,    48,    53,     0,    41,    32,    18,    78,    44,
       0,    86,    91,    94,    96,    64,     0,    61,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    55,    87,    88,    89,    90,    92,    93,    95,    97,
      57,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   197,   -66,  -114,   173,  -114,   -54,  -114,
    -114,   179,  -114,   190,   -49,  -114,  -114,   210,   -65,   137,
    -114,    81,   -35,   109,  -114,  -113,   -20,   -24,   100,   -69,
    -114,   -34,  -114,   101,    25,  -101,   -37,    71,    64,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    21,    58,    85,
       9,    17,    18,    25,    51,    80,    10,    47,    11,    48,
      49,    64,   107,   108,   109,   110,    59,    39,   140,    40,
      41,    42,    43,    90,    44,    45,   142,   143,   144,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    79,    38,    84,   112,    82,    86,   105,   106,    67,
      65,    74,    22,    32,    23,    33,    71,    72,    34,    68,
      69,    70,    35,    36,   141,   141,    52,    12,    24,    37,
      52,   129,    22,    81,    93,    94,    95,   161,    87,    89,
     112,   114,    14,   105,   106,    53,   170,    53,    28,   111,
     162,   163,   164,   165,   141,   141,   141,   141,   172,    16,
      22,    54,   116,    60,     1,     2,   137,   124,   136,    12,
      32,   117,    33,     3,   119,    34,    24,    50,   130,    35,
      36,   112,    46,   120,    19,   111,    37,    55,   151,   152,
     112,   155,   156,    52,   153,   154,    96,    97,    89,     1,
       2,    98,   112,    99,   100,   101,   102,    32,     3,    33,
     148,    62,    34,    63,    73,   103,    35,    36,   166,   167,
      26,    27,    31,    37,    30,   104,   111,    66,    73,    75,
      76,    77,    92,    91,   113,   111,     1,     2,    98,   118,
      99,   100,   101,   102,    32,     3,    33,   111,   123,    34,
     121,    73,   125,    35,    36,   122,   126,   127,   128,   133,
      37,    98,   104,    99,   100,   101,   102,    32,   131,    33,
     135,   134,    34,   139,    73,   147,    35,    36,    62,    32,
     150,    33,   158,    37,    34,   104,    50,    78,    35,    36,
     157,    32,   159,    33,   160,    37,    34,   171,    57,    83,
      35,    36,    15,    32,    61,    33,    56,    37,    34,    29,
      57,    13,    35,    36,   115,    32,   149,    33,   132,    37,
      34,    88,   169,   138,    35,    36,   146,    32,   168,    33,
       0,    37,    34,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,    37
};

static const yytype_int16 yycheck[] =
{
      24,    50,    22,    57,    73,    54,    60,    73,    73,    43,
      34,    46,    14,    11,    16,    13,    20,    21,    16,    22,
      23,    24,    20,    21,   125,   126,    50,     4,    30,    27,
      54,    29,    14,    53,    68,    69,    70,   150,    62,    63,
     109,    76,     0,   109,   109,    14,   159,    14,    30,    73,
     151,   152,   153,   154,   155,   156,   157,   158,   171,    11,
      14,    30,    19,    30,     3,     4,   120,    91,   117,     4,
      11,    28,    13,    12,    19,    16,    30,    18,   102,    20,
      21,   150,    17,    28,    11,   109,    27,    11,    25,    26,
     159,    33,    34,   117,    31,    32,    71,    72,   122,     3,
       4,     5,   171,     7,     8,     9,    10,    11,    12,    13,
     134,    14,    16,    16,    18,    19,    20,    21,   155,   156,
      29,    28,    28,    27,    29,    29,   150,    15,    18,    11,
      17,    28,    17,    14,    14,   159,     3,     4,     5,    15,
       7,     8,     9,    10,    11,    12,    13,   171,    17,    16,
      15,    18,    16,    20,    21,    28,    16,    29,    29,    29,
      27,     5,    29,     7,     8,     9,    10,    11,    19,    13,
      15,    30,    16,    15,    18,    29,    20,    21,    14,    11,
      17,    13,    35,    27,    16,    29,    18,    19,    20,    21,
      36,    11,    17,    13,    29,    27,    16,     6,    18,    19,
      20,    21,     5,    11,    31,    13,    27,    27,    16,    19,
      18,     1,    20,    21,    77,    11,   135,    13,   109,    27,
      16,    17,   158,   122,    20,    21,   126,    11,   157,    13,
      -1,    27,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27
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
      62,    64,    66,    14,    59,    56,    19,    28,    15,    19,
      28,    15,    28,    17,    64,    16,    16,    29,    29,    29,
      64,    19,    60,    29,    30,    15,    51,    45,    70,    15,
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
#line 43 "syntax.y"
           {}
#line 1275 "syntax.tab.c"
    break;

  case 3: /* CompList: DecOrDef  */
#line 46 "syntax.y"
           {}
#line 1281 "syntax.tab.c"
    break;

  case 4: /* CompList: CompList DecOrDef  */
#line 47 "syntax.y"
                    {}
#line 1287 "syntax.tab.c"
    break;

  case 5: /* DecOrDef: Decl  */
#line 50 "syntax.y"
       {}
#line 1293 "syntax.tab.c"
    break;

  case 6: /* DecOrDef: FuncDef  */
#line 51 "syntax.y"
          {}
#line 1299 "syntax.tab.c"
    break;

  case 7: /* Decl: ConstDecl  */
#line 54 "syntax.y"
            {}
#line 1305 "syntax.tab.c"
    break;

  case 8: /* Decl: VarDecl  */
#line 55 "syntax.y"
          {}
#line 1311 "syntax.tab.c"
    break;

  case 9: /* ConstDecl: CONST VarType ConstDefList ';'  */
#line 58 "syntax.y"
                                 {}
#line 1317 "syntax.tab.c"
    break;

  case 10: /* ConstDefList: ConstDef  */
#line 61 "syntax.y"
           {}
#line 1323 "syntax.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 62 "syntax.y"
                            {}
#line 1329 "syntax.tab.c"
    break;

  case 12: /* ConstDef: IDENT '=' ConstInitVal  */
#line 65 "syntax.y"
                         {}
#line 1335 "syntax.tab.c"
    break;

  case 13: /* ConstDef: IDENT ConstArrayIndex '=' ConstInitVal  */
#line 66 "syntax.y"
                                         {}
#line 1341 "syntax.tab.c"
    break;

  case 14: /* ConstInitVal: ConstExp  */
#line 69 "syntax.y"
           {}
#line 1347 "syntax.tab.c"
    break;

  case 15: /* ConstInitVal: LEFTBRACE RIGHTBRACE  */
#line 70 "syntax.y"
                       {}
#line 1353 "syntax.tab.c"
    break;

  case 16: /* ConstInitVal: LEFTBRACE ConstInitValList RIGHTBRACE  */
#line 71 "syntax.y"
                                        {}
#line 1359 "syntax.tab.c"
    break;

  case 17: /* ConstInitValList: ConstInitVal  */
#line 74 "syntax.y"
               {}
#line 1365 "syntax.tab.c"
    break;

  case 18: /* ConstInitValList: ConstInitValList ',' ConstInitVal  */
#line 75 "syntax.y"
                                    {}
#line 1371 "syntax.tab.c"
    break;

  case 19: /* VarDecl: FuncType VarDefList ';'  */
#line 78 "syntax.y"
                          {}
#line 1377 "syntax.tab.c"
    break;

  case 20: /* VarDefList: VarDef  */
#line 81 "syntax.y"
         {}
#line 1383 "syntax.tab.c"
    break;

  case 21: /* VarDefList: VarDef ',' VarDefList  */
#line 82 "syntax.y"
                        {}
#line 1389 "syntax.tab.c"
    break;

  case 22: /* VarDef: IDENT  */
#line 85 "syntax.y"
        {}
#line 1395 "syntax.tab.c"
    break;

  case 23: /* VarDef: IDENT '=' InitVal  */
#line 86 "syntax.y"
                    {}
#line 1401 "syntax.tab.c"
    break;

  case 24: /* VarDef: IDENT ConstArrayIndex  */
#line 87 "syntax.y"
                        {}
#line 1407 "syntax.tab.c"
    break;

  case 25: /* VarDef: IDENT ConstArrayIndex '=' InitVal  */
#line 88 "syntax.y"
                                    {}
#line 1413 "syntax.tab.c"
    break;

  case 26: /* ConstArrayIndex: LEFTSQB ConstExp RIGHTSQB  */
#line 91 "syntax.y"
                            {}
#line 1419 "syntax.tab.c"
    break;

  case 27: /* ConstArrayIndex: ConstArrayIndex LEFTSQB ConstExp RIGHTSQB  */
#line 92 "syntax.y"
                                            {}
#line 1425 "syntax.tab.c"
    break;

  case 28: /* InitVal: Exp  */
#line 95 "syntax.y"
      {}
#line 1431 "syntax.tab.c"
    break;

  case 29: /* InitVal: LEFTBRACE RIGHTBRACE  */
#line 96 "syntax.y"
                       {}
#line 1437 "syntax.tab.c"
    break;

  case 30: /* InitVal: LEFTBRACE InitValList RIGHTBRACE  */
#line 97 "syntax.y"
                                   {}
#line 1443 "syntax.tab.c"
    break;

  case 31: /* InitValList: InitVal  */
#line 100 "syntax.y"
          {}
#line 1449 "syntax.tab.c"
    break;

  case 32: /* InitValList: InitValList ',' InitVal  */
#line 101 "syntax.y"
                          {}
#line 1455 "syntax.tab.c"
    break;

  case 33: /* FuncDef: FuncType IDENT LPAREN RPAREN Block  */
#line 104 "syntax.y"
                                     {}
#line 1461 "syntax.tab.c"
    break;

  case 34: /* FuncDef: FuncType IDENT LPAREN FuncFParams RPAREN Block  */
#line 105 "syntax.y"
                                                 {}
#line 1467 "syntax.tab.c"
    break;

  case 35: /* VarType: INT  */
#line 108 "syntax.y"
      {}
#line 1473 "syntax.tab.c"
    break;

  case 36: /* FuncType: VOID  */
#line 111 "syntax.y"
       {}
#line 1479 "syntax.tab.c"
    break;

  case 37: /* FuncType: INT  */
#line 112 "syntax.y"
      {}
#line 1485 "syntax.tab.c"
    break;

  case 38: /* FuncFParams: FuncFParam  */
#line 115 "syntax.y"
             {}
#line 1491 "syntax.tab.c"
    break;

  case 39: /* FuncFParams: FuncFParam ',' FuncFParams  */
#line 116 "syntax.y"
                             {}
#line 1497 "syntax.tab.c"
    break;

  case 40: /* FuncFParam: VarType IDENT  */
#line 120 "syntax.y"
                {}
#line 1503 "syntax.tab.c"
    break;

  case 41: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB  */
#line 121 "syntax.y"
                                 {}
#line 1509 "syntax.tab.c"
    break;

  case 42: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB ArrayIndex  */
#line 122 "syntax.y"
                                            {}
#line 1515 "syntax.tab.c"
    break;

  case 43: /* ArrayIndex: LEFTSQB Exp RIGHTSQB  */
#line 125 "syntax.y"
                       {}
#line 1521 "syntax.tab.c"
    break;

  case 44: /* ArrayIndex: ArrayIndex LEFTSQB Exp RIGHTSQB  */
#line 126 "syntax.y"
                                  {}
#line 1527 "syntax.tab.c"
    break;

  case 45: /* Block: LEFTBRACE RIGHTBRACE  */
#line 129 "syntax.y"
                       {}
#line 1533 "syntax.tab.c"
    break;

  case 46: /* Block: LEFTBRACE BlockItemList RIGHTBRACE  */
#line 130 "syntax.y"
                                     {}
#line 1539 "syntax.tab.c"
    break;

  case 47: /* BlockItemList: BlockItem  */
#line 133 "syntax.y"
            {}
#line 1545 "syntax.tab.c"
    break;

  case 48: /* BlockItemList: BlockItem BlockItemList  */
#line 134 "syntax.y"
                          {}
#line 1551 "syntax.tab.c"
    break;

  case 49: /* BlockItem: Decl  */
#line 137 "syntax.y"
       {}
#line 1557 "syntax.tab.c"
    break;

  case 50: /* BlockItem: Stmt  */
#line 138 "syntax.y"
       {}
#line 1563 "syntax.tab.c"
    break;

  case 51: /* Stmt: LVal '=' Exp ';'  */
#line 141 "syntax.y"
                   {}
#line 1569 "syntax.tab.c"
    break;

  case 52: /* Stmt: ';'  */
#line 142 "syntax.y"
      {}
#line 1575 "syntax.tab.c"
    break;

  case 53: /* Stmt: Exp ';'  */
#line 143 "syntax.y"
          {}
#line 1581 "syntax.tab.c"
    break;

  case 54: /* Stmt: Block  */
#line 144 "syntax.y"
        {}
#line 1587 "syntax.tab.c"
    break;

  case 55: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 145 "syntax.y"
                             {}
#line 1593 "syntax.tab.c"
    break;

  case 56: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 146 "syntax.y"
                                       {}
#line 1599 "syntax.tab.c"
    break;

  case 57: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 147 "syntax.y"
                                {}
#line 1605 "syntax.tab.c"
    break;

  case 58: /* Stmt: BREAK ';'  */
#line 148 "syntax.y"
            {}
#line 1611 "syntax.tab.c"
    break;

  case 59: /* Stmt: CONTINUE ';'  */
#line 149 "syntax.y"
               {}
#line 1617 "syntax.tab.c"
    break;

  case 60: /* Stmt: RETURN ';'  */
#line 150 "syntax.y"
             {}
#line 1623 "syntax.tab.c"
    break;

  case 61: /* Stmt: RETURN Exp ';'  */
#line 151 "syntax.y"
                 {}
#line 1629 "syntax.tab.c"
    break;

  case 62: /* ConstExp: Exp  */
#line 154 "syntax.y"
      {}
#line 1635 "syntax.tab.c"
    break;

  case 63: /* Exp: AddExp  */
#line 157 "syntax.y"
         {}
#line 1641 "syntax.tab.c"
    break;

  case 64: /* Cond: LOrExp  */
#line 160 "syntax.y"
         {}
#line 1647 "syntax.tab.c"
    break;

  case 65: /* LVal: IDENT  */
#line 163 "syntax.y"
        {}
#line 1653 "syntax.tab.c"
    break;

  case 66: /* LVal: IDENT ArrayIndex  */
#line 164 "syntax.y"
                   {}
#line 1659 "syntax.tab.c"
    break;

  case 67: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 167 "syntax.y"
                    {}
#line 1665 "syntax.tab.c"
    break;

  case 68: /* PrimaryExp: LVal  */
#line 168 "syntax.y"
       {}
#line 1671 "syntax.tab.c"
    break;

  case 69: /* PrimaryExp: INTCONST  */
#line 169 "syntax.y"
           {}
#line 1677 "syntax.tab.c"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 172 "syntax.y"
             {}
#line 1683 "syntax.tab.c"
    break;

  case 71: /* UnaryExp: IDENT LPAREN RPAREN  */
#line 173 "syntax.y"
                      {}
#line 1689 "syntax.tab.c"
    break;

  case 72: /* UnaryExp: IDENT LPAREN FuncRParams RPAREN  */
#line 174 "syntax.y"
                                  {}
#line 1695 "syntax.tab.c"
    break;

  case 73: /* UnaryExp: UnaryOp UnaryExp  */
#line 175 "syntax.y"
                   {}
#line 1701 "syntax.tab.c"
    break;

  case 74: /* UnaryOp: '+'  */
#line 178 "syntax.y"
      {}
#line 1707 "syntax.tab.c"
    break;

  case 75: /* UnaryOp: '-'  */
#line 179 "syntax.y"
      {}
#line 1713 "syntax.tab.c"
    break;

  case 76: /* UnaryOp: '!'  */
#line 180 "syntax.y"
      {}
#line 1719 "syntax.tab.c"
    break;

  case 77: /* FuncRParams: Exp  */
#line 183 "syntax.y"
      {}
#line 1725 "syntax.tab.c"
    break;

  case 78: /* FuncRParams: Exp ',' FuncRParams  */
#line 184 "syntax.y"
                      {}
#line 1731 "syntax.tab.c"
    break;

  case 79: /* MulExp: UnaryExp  */
#line 187 "syntax.y"
           {}
#line 1737 "syntax.tab.c"
    break;

  case 80: /* MulExp: MulExp '*' UnaryExp  */
#line 188 "syntax.y"
                      {}
#line 1743 "syntax.tab.c"
    break;

  case 81: /* MulExp: MulExp '/' UnaryExp  */
#line 189 "syntax.y"
                      {}
#line 1749 "syntax.tab.c"
    break;

  case 82: /* MulExp: MulExp '%' UnaryExp  */
#line 190 "syntax.y"
                      {}
#line 1755 "syntax.tab.c"
    break;

  case 83: /* AddExp: MulExp  */
#line 193 "syntax.y"
         {}
#line 1761 "syntax.tab.c"
    break;

  case 84: /* AddExp: AddExp '+' MulExp  */
#line 194 "syntax.y"
                    {}
#line 1767 "syntax.tab.c"
    break;

  case 85: /* AddExp: AddExp '-' MulExp  */
#line 195 "syntax.y"
                    {}
#line 1773 "syntax.tab.c"
    break;

  case 86: /* RelExp: AddExp  */
#line 198 "syntax.y"
         {}
#line 1779 "syntax.tab.c"
    break;

  case 87: /* RelExp: RelExp '<' AddExp  */
#line 199 "syntax.y"
                    {}
#line 1785 "syntax.tab.c"
    break;

  case 88: /* RelExp: RelExp '>' AddExp  */
#line 200 "syntax.y"
                    {}
#line 1791 "syntax.tab.c"
    break;

  case 89: /* RelExp: RelExp LE AddExp  */
#line 201 "syntax.y"
                   {}
#line 1797 "syntax.tab.c"
    break;

  case 90: /* RelExp: RelExp GE AddExp  */
#line 202 "syntax.y"
                   {}
#line 1803 "syntax.tab.c"
    break;

  case 91: /* EqExp: RelExp  */
#line 205 "syntax.y"
         {}
#line 1809 "syntax.tab.c"
    break;

  case 92: /* EqExp: EqExp EQ RelExp  */
#line 206 "syntax.y"
                  {}
#line 1815 "syntax.tab.c"
    break;

  case 93: /* EqExp: EqExp NE RelExp  */
#line 207 "syntax.y"
                  {}
#line 1821 "syntax.tab.c"
    break;

  case 94: /* LAndExp: EqExp  */
#line 210 "syntax.y"
        {}
#line 1827 "syntax.tab.c"
    break;

  case 95: /* LAndExp: LAndExp LAND EqExp  */
#line 211 "syntax.y"
                     {}
#line 1833 "syntax.tab.c"
    break;

  case 96: /* LOrExp: LAndExp  */
#line 214 "syntax.y"
          {}
#line 1839 "syntax.tab.c"
    break;

  case 97: /* LOrExp: LOrExp LOR LAndExp  */
#line 215 "syntax.y"
                     {}
#line 1845 "syntax.tab.c"
    break;


#line 1849 "syntax.tab.c"

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

#line 218 "syntax.y"


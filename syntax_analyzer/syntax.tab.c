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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
     111,   119,   124,   132,   139,   149,   154,   159,   167,   172,
     180,   185,   194,   199,   207,   213,   220,   227,   235,   242,
     250,   258,   269,   274,   282,   288,   293,   301,   306,   314,
     321,   329,   340,   347,   352,   359,   364,   372,   379,   386,
     394,   405,   410,   418,   422,   429,   434,   442,   448,   456,
     463,   468,   474,   480,   487,   495,   502,   507,   512,   517,
     525,   532,   539,   546,   552,   561,   567,   573,   581,   587,
     593,   600,   609,   612,   615,   620,   625,   633,   639,   647,
     655,   665,   671,   679,   689,   695,   703,   715,   723,   731,
     741,   747,   755,   765,   771,   780,   786
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

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   120,    22,  -158,  -158,    33,   255,  -158,  -158,  -158,
    -158,  -158,   136,    48,    59,    34,    40,  -158,    63,  -158,
    -158,    42,    71,   233,   209,    50,    52,  -158,   120,    61,
      86,    96,    56,  -158,     7,  -158,   233,  -158,  -158,  -158,
      70,  -158,  -158,  -158,  -158,   233,    82,    -5,   185,  -158,
    -158,   233,   209,   209,    57,  -158,  -158,   221,    79,  -158,
     124,   127,   138,   153,   159,   157,   233,    81,   176,   175,
    -158,  -158,   233,   233,   233,   233,   233,  -158,   167,   148,
     182,  -158,  -158,   209,   197,  -158,  -158,   221,    93,  -158,
     138,   109,  -158,   193,   138,    22,   184,  -158,   181,   194,
     233,  -158,  -158,  -158,  -158,    82,    82,   209,  -158,  -158,
    -158,  -158,   186,   200,  -158,  -158,   205,   207,   199,   202,
     121,  -158,  -158,  -158,   120,  -158,   214,   150,  -158,   206,
     196,    19,  -158,  -158,  -158,   233,  -158,   223,  -158,   221,
    -158,   233,   233,  -158,  -158,  -158,   211,  -158,  -158,  -158,
     233,   228,   231,  -158,  -158,  -158,   230,    -5,   114,   139,
     215,   217,   240,  -158,   232,  -158,   176,   173,    68,   233,
     233,   233,   233,   233,   233,   233,   173,  -158,   244,  -158,
      -5,    -5,    -5,    -5,   114,   114,   139,   215,  -158,   173,
    -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    44,    43,     0,     0,     3,     5,     7,
       8,     6,     0,    24,     0,     0,    22,    42,     0,     1,
       4,    24,     0,     0,     0,    26,    28,    21,     0,     0,
       0,    11,     0,    20,    73,    77,     0,    82,    83,    84,
       0,    70,    76,    78,    87,     0,    91,    71,     0,    25,
      34,     0,     0,     0,    30,    23,    10,     0,     0,     9,
       0,     0,     0,     0,     0,    45,     0,     0,    74,     0,
      32,    81,     0,     0,     0,     0,     0,    35,    37,     0,
       0,    27,    29,     0,     0,    13,    15,     0,     0,    12,
       0,     0,    39,    47,     0,     0,     0,    79,    85,     0,
       0,    75,    88,    89,    90,    92,    93,     0,    36,    33,
      31,    16,    18,     0,    14,    41,     0,     0,     0,     0,
       0,    53,    60,    57,     0,    62,     0,     0,    58,     0,
      76,     0,    40,    46,    51,     0,    80,     0,    38,     0,
      17,     0,     0,    66,    67,    68,     0,    54,    56,    61,
       0,     0,    48,    86,    52,    19,     0,    94,   100,   103,
     105,    72,     0,    69,     0,    50,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    63,    96,
      95,    97,    98,    99,   101,   102,   104,   106,    65,     0,
      64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,   256,   -87,  -158,   203,  -158,   -49,   125,
    -158,     8,  -158,   -23,   -22,   158,  -158,   264,   -86,   174,
    -158,   116,   -55,   143,  -158,  -157,     4,   -24,   129,   -90,
    -158,   -20,  -158,   137,    99,  -124,    15,   100,    98,  -158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    30,    31,   112,   113,
      10,    22,    16,    25,    78,    79,    11,    63,    12,    64,
      65,    68,   125,   126,   127,   128,    86,    41,   156,    42,
      43,    44,    45,    99,    46,    47,   158,   159,   160,   161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   130,    49,    54,   123,   124,    58,    92,    85,    15,
     178,     1,    69,     2,     3,    75,    76,   157,   157,   188,
     151,    66,     4,    67,    50,    71,    17,    40,    50,    50,
      81,    82,   190,    19,   152,   115,    55,   130,   114,   132,
     123,   124,    96,    98,   180,   181,   182,   183,   157,   157,
     157,   157,   102,   103,   104,    80,    23,    61,    32,    50,
      17,   110,    23,    27,    51,    58,    23,   129,    28,   179,
      26,    51,    24,    62,    29,    23,   137,   130,    24,    34,
      52,    35,    53,    50,    36,    70,   130,    83,    37,    38,
      56,    57,    34,    51,    35,    39,   146,    36,    97,   130,
      33,    37,    38,   129,    72,    73,    74,    23,    39,    87,
       1,    98,     2,     3,   116,    59,   117,   118,   119,   120,
      34,     4,    35,    57,    60,    36,   164,    91,   121,    37,
      38,    13,    34,    14,    35,    88,    39,    36,   122,   168,
     169,    37,    38,   129,    90,   170,   171,    21,    39,    14,
     145,     1,   129,     2,     3,   116,    91,   117,   118,   119,
     120,    34,     4,    35,    93,   129,    36,   108,    91,   -55,
      37,    38,   172,   173,   105,   106,    94,    39,   116,   122,
     117,   118,   119,   120,    34,    95,    35,   184,   185,    36,
     100,    91,   101,    37,    38,   107,    34,   109,    35,   134,
      39,    36,   122,    48,    77,    37,    38,   131,    34,   135,
      35,   136,    39,    36,   139,    84,   111,    37,    38,   140,
      34,   141,    35,   142,    39,    36,   150,    48,   143,    37,
      38,   144,    34,   147,    35,   149,    39,    36,   154,    84,
     163,    37,    38,   165,    34,    66,    35,   167,    39,    36,
     189,   174,   175,    37,    38,    -2,     1,   176,     2,     3,
      39,   177,    20,    89,   155,   138,    18,     4,   166,   133,
     148,   162,   153,   187,   186
};

static const yytype_uint8 yycheck[] =
{
      24,    91,    24,    26,    91,    91,    29,    62,    57,     1,
     167,     1,    36,     3,     4,    20,    21,   141,   142,   176,
       1,    14,    12,    16,    48,    45,     4,    23,    52,    53,
      52,    53,   189,     0,    15,    90,    28,   127,    87,    94,
     127,   127,    66,    67,   168,   169,   170,   171,   172,   173,
     174,   175,    72,    73,    74,    51,    14,     1,    16,    83,
       4,    83,    14,    29,    14,    88,    14,    91,    28,     1,
      11,    14,    30,    17,    11,    14,   100,   167,    30,    11,
      30,    13,    30,   107,    16,    15,   176,    30,    20,    21,
      29,    30,    11,    14,    13,    27,   120,    16,    17,   189,
      29,    20,    21,   127,    22,    23,    24,    14,    27,    30,
       1,   135,     3,     4,     5,    29,     7,     8,     9,    10,
      11,    12,    13,    30,    28,    16,   150,    18,    19,    20,
      21,    11,    11,    13,    13,    11,    27,    16,    29,    25,
      26,    20,    21,   167,    17,    31,    32,    11,    27,    13,
      29,     1,   176,     3,     4,     5,    18,     7,     8,     9,
      10,    11,    12,    13,    11,   189,    16,    19,    18,    19,
      20,    21,    33,    34,    75,    76,    17,    27,     5,    29,
       7,     8,     9,    10,    11,    28,    13,   172,   173,    16,
      14,    18,    17,    20,    21,    28,    11,    15,    13,    15,
      27,    16,    29,    18,    19,    20,    21,    14,    11,    28,
      13,    17,    27,    16,    28,    18,    19,    20,    21,    19,
      11,    16,    13,    16,    27,    16,    30,    18,    29,    20,
      21,    29,    11,    19,    13,    29,    27,    16,    15,    18,
      29,    20,    21,    15,    11,    14,    13,    17,    27,    16,
       6,    36,    35,    20,    21,     0,     1,    17,     3,     4,
      27,    29,     6,    60,   139,   107,     2,    12,   152,    95,
     127,   142,   135,   175,   174
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    12,    38,    39,    40,    41,    42,
      47,    53,    55,    11,    13,    48,    49,     4,    54,     0,
      40,    11,    48,    14,    30,    50,    11,    29,    28,    11,
      43,    44,    16,    29,    11,    13,    16,    20,    21,    27,
      63,    64,    66,    67,    68,    69,    71,    72,    18,    51,
      64,    14,    30,    30,    50,    48,    29,    30,    50,    29,
      28,     1,    17,    54,    56,    57,    14,    16,    58,    64,
      15,    68,    22,    23,    24,    20,    21,    19,    51,    52,
      63,    51,    51,    30,    18,    45,    63,    30,    11,    43,
      17,    18,    59,    11,    17,    28,    64,    17,    64,    70,
      14,    17,    68,    68,    68,    71,    71,    28,    19,    15,
      51,    19,    45,    46,    45,    59,     5,     7,     8,     9,
      10,    19,    29,    41,    55,    59,    60,    61,    62,    64,
      66,    14,    59,    56,    15,    28,    17,    64,    52,    28,
      19,    16,    16,    29,    29,    29,    64,    19,    60,    29,
      30,     1,    15,    70,    15,    46,    65,    72,    73,    74,
      75,    76,    65,    29,    64,    15,    58,    17,    25,    26,
      31,    32,    33,    34,    36,    35,    17,    29,    62,     1,
      72,    72,    72,    72,    73,    73,    74,    75,    62,     6,
      62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       4,     1,     3,     3,     4,     1,     2,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     2,     4,     2,     4,
       3,     5,     3,     4,     1,     2,     3,     1,     3,     5,
       6,     6,     1,     1,     1,     1,     3,     2,     4,     5,
       5,     3,     4,     2,     3,     1,     2,     1,     1,     4,
       1,     2,     1,     5,     7,     5,     2,     2,     2,     3,
       1,     1,     1,     1,     2,     3,     1,     1,     1,     3,
       4,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3
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
#line 1299 "syntax.tab.c"
    break;

  case 3: /* CompList: DecOrDef  */
#line 64 "syntax.y"
           {
    auto compList = new CompList();
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )(yyvsp[0].tree));
    (yyval.tree) = compList;
}
#line 1309 "syntax.tab.c"
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
#line 1321 "syntax.tab.c"
    break;

  case 5: /* DecOrDef: Decl  */
#line 78 "syntax.y"
       {
    auto decOrDef = new DeclOrDef();
    decOrDef->if_decl = true;
    decOrDef->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1332 "syntax.tab.c"
    break;

  case 6: /* DecOrDef: FuncDef  */
#line 84 "syntax.y"
          {
    auto decOrDef = new DeclOrDef();
    decOrDef->funcDef = shared_ptr<FuncDef>((FuncDef* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1342 "syntax.tab.c"
    break;

  case 7: /* Decl: ConstDecl  */
#line 91 "syntax.y"
            {
    auto decl = new Decl();
    decl->decType = DecType::ConstDecl;
    decl->constDecl = shared_ptr<ConstDecl>((ConstDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1353 "syntax.tab.c"
    break;

  case 8: /* Decl: VarDecl  */
#line 97 "syntax.y"
          {
    auto decl = new Decl();
    decl->decType = DecType::VarDecl;
    decl->varDecl = shared_ptr<VarDecl>((VarDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1364 "syntax.tab.c"
    break;

  case 9: /* ConstDecl: CONST VarType ConstDefList ';'  */
#line 105 "syntax.y"
                                 {
    auto constDecl = new ConstDecl();
    constDecl->varType = shared_ptr<VarType>((VarType* )(yyvsp[-2].tree));
    constDecl->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[-1].tree));
    (yyval.tree) = constDecl;
}
#line 1375 "syntax.tab.c"
    break;

  case 10: /* ConstDecl: CONST VarType IDENT ';'  */
#line 111 "syntax.y"
                          {
    fprintf(stderr, "Error: Unknown constdeflist\n");
    auto constDecl = new ConstDecl();
    constDecl->err_empty = true;
    (yyval.tree) = constDecl;
}
#line 1386 "syntax.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 119 "syntax.y"
           {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[0].tree));
    (yyval.tree) = constDefList;
}
#line 1396 "syntax.tab.c"
    break;

  case 12: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 124 "syntax.y"
                            {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[-2].tree));
    constDefList->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[0].tree));
    (yyval.tree) = constDefList;
}
#line 1407 "syntax.tab.c"
    break;

  case 13: /* ConstDef: IDENT '=' ConstInitVal  */
#line 132 "syntax.y"
                         {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Var;
    constDef->ident = *((yyvsp[-2].sval));
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1419 "syntax.tab.c"
    break;

  case 14: /* ConstDef: IDENT ConstArrayIndex '=' ConstInitVal  */
#line 139 "syntax.y"
                                         {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Array;
    constDef->ident = *((yyvsp[-3].sval));
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1432 "syntax.tab.c"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 149 "syntax.y"
           {
    auto constInitVal = new ConstInitVal();
    constInitVal->constExp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[0].tree));
    (yyval.tree) = constInitVal;
}
#line 1442 "syntax.tab.c"
    break;

  case 16: /* ConstInitVal: LEFTBRACE RIGHTBRACE  */
#line 154 "syntax.y"
                       {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    (yyval.tree) = constInitVal;
}
#line 1452 "syntax.tab.c"
    break;

  case 17: /* ConstInitVal: LEFTBRACE ConstInitValList RIGHTBRACE  */
#line 159 "syntax.y"
                                        {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    constInitVal->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[-1].tree));
    (yyval.tree) = constInitVal;
}
#line 1463 "syntax.tab.c"
    break;

  case 18: /* ConstInitValList: ConstInitVal  */
#line 167 "syntax.y"
               {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1473 "syntax.tab.c"
    break;

  case 19: /* ConstInitValList: ConstInitVal ',' ConstInitValList  */
#line 172 "syntax.y"
                                    {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[-2].tree));
    constInitValList->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1484 "syntax.tab.c"
    break;

  case 20: /* VarDecl: FuncType VarDefList ';'  */
#line 180 "syntax.y"
                          {
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-1].tree));
    (yyval.tree) = varDecl;
}
#line 1494 "syntax.tab.c"
    break;

  case 21: /* VarDecl: error VarDefList ';'  */
#line 185 "syntax.y"
                       {
    fprintf(stderr, "Error: Unknown VarType\n");
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-1].tree));
    varDecl->unknownType = true;
    (yyval.tree) = varDecl;
}
#line 1506 "syntax.tab.c"
    break;

  case 22: /* VarDefList: VarDef  */
#line 194 "syntax.y"
         {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[0].tree));
    (yyval.tree) = varDefList;
}
#line 1516 "syntax.tab.c"
    break;

  case 23: /* VarDefList: VarDef ',' VarDefList  */
#line 199 "syntax.y"
                        {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[-2].tree));
    varDefList->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[0].tree));
    (yyval.tree) = varDefList;
}
#line 1527 "syntax.tab.c"
    break;

  case 24: /* VarDef: IDENT  */
#line 207 "syntax.y"
        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[0].sval));
    (yyval.tree) = varDef;
}
#line 1538 "syntax.tab.c"
    break;

  case 25: /* VarDef: IDENT '=' InitVal  */
#line 213 "syntax.y"
                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[-2].sval));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1550 "syntax.tab.c"
    break;

  case 26: /* VarDef: IDENT ConstArrayIndex  */
#line 220 "syntax.y"
                        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-1].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1562 "syntax.tab.c"
    break;

  case 27: /* VarDef: IDENT ConstArrayIndex '=' InitVal  */
#line 227 "syntax.y"
                                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-3].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1575 "syntax.tab.c"
    break;

  case 28: /* VarDef: INTCONST IDENT  */
#line 235 "syntax.y"
                 {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[0].sval));
    (yyval.tree) = varDef;
}
#line 1587 "syntax.tab.c"
    break;

  case 29: /* VarDef: INTCONST IDENT '=' InitVal  */
#line 242 "syntax.y"
                             {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[-2].sval));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1600 "syntax.tab.c"
    break;

  case 30: /* VarDef: INTCONST IDENT ConstArrayIndex  */
#line 250 "syntax.y"
                                 {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-1].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1613 "syntax.tab.c"
    break;

  case 31: /* VarDef: INTCONST IDENT ConstArrayIndex '=' InitVal  */
#line 258 "syntax.y"
                                             {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-3].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1627 "syntax.tab.c"
    break;

  case 32: /* ConstArrayIndex: LEFTSQB ConstExp RIGHTSQB  */
#line 269 "syntax.y"
                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    (yyval.tree) = constArrayIndex;
}
#line 1637 "syntax.tab.c"
    break;

  case 33: /* ConstArrayIndex: ConstArrayIndex LEFTSQB ConstExp RIGHTSQB  */
#line 274 "syntax.y"
                                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-3].tree));
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    (yyval.tree) = constArrayIndex;
}
#line 1648 "syntax.tab.c"
    break;

  case 34: /* InitVal: Exp  */
#line 282 "syntax.y"
      {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Var;
    initVal->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = initVal;
}
#line 1659 "syntax.tab.c"
    break;

  case 35: /* InitVal: LEFTBRACE RIGHTBRACE  */
#line 288 "syntax.y"
                       {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    (yyval.tree) = initVal;
}
#line 1669 "syntax.tab.c"
    break;

  case 36: /* InitVal: LEFTBRACE InitValList RIGHTBRACE  */
#line 293 "syntax.y"
                                   {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    initVal->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[-1].tree));
    (yyval.tree) = initVal;
}
#line 1680 "syntax.tab.c"
    break;

  case 37: /* InitValList: InitVal  */
#line 301 "syntax.y"
          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = initValList;
}
#line 1690 "syntax.tab.c"
    break;

  case 38: /* InitValList: InitVal ',' InitValList  */
#line 306 "syntax.y"
                          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[-2].tree));
    initValList->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[0].tree));
    (yyval.tree) = initValList;
}
#line 1701 "syntax.tab.c"
    break;

  case 39: /* FuncDef: FuncType IDENT LPAREN RPAREN Block  */
#line 314 "syntax.y"
                                     {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-4].tree));
    funcDef->ident = *((yyvsp[-3].sval));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1713 "syntax.tab.c"
    break;

  case 40: /* FuncDef: FuncType IDENT LPAREN FuncFParamList RPAREN Block  */
#line 321 "syntax.y"
                                                    {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-5].tree));
    funcDef->ident = *((yyvsp[-4].sval));
    funcDef->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[-2].tree));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1726 "syntax.tab.c"
    break;

  case 41: /* FuncDef: FuncType IDENT LPAREN error RPAREN Block  */
#line 329 "syntax.y"
                                           {
    fprintf(stderr, "Error: Unknown funcfparamlist\n");
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-5].tree));
    funcDef->ident = *((yyvsp[-4].sval));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    funcDef->err_empty = true;
    (yyval.tree) = funcDef;
}
#line 1740 "syntax.tab.c"
    break;

  case 42: /* VarType: INT  */
#line 340 "syntax.y"
      {
    auto varType = new VarType();
    varType->type = "int";
    (yyval.tree) = varType;
}
#line 1750 "syntax.tab.c"
    break;

  case 43: /* FuncType: VOID  */
#line 347 "syntax.y"
       {
    auto funcType = new FuncType();
    funcType->type = "void";
    (yyval.tree) = funcType;
}
#line 1760 "syntax.tab.c"
    break;

  case 44: /* FuncType: INT  */
#line 352 "syntax.y"
      {
    auto funcType = new FuncType();
    funcType->type = "int";
    (yyval.tree) = funcType;
}
#line 1770 "syntax.tab.c"
    break;

  case 45: /* FuncFParamList: FuncFParam  */
#line 359 "syntax.y"
             {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[0].tree));
    (yyval.tree) = funcFParamList;
}
#line 1780 "syntax.tab.c"
    break;

  case 46: /* FuncFParamList: FuncFParam ',' FuncFParamList  */
#line 364 "syntax.y"
                                {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[-2].tree));
    funcFParamList->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[0].tree));
    (yyval.tree) = funcFParamList;
}
#line 1791 "syntax.tab.c"
    break;

  case 47: /* FuncFParam: VarType IDENT  */
#line 372 "syntax.y"
                {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-1].tree));
    funcFParam->ident = *((yyvsp[0].sval));
    (yyval.tree) = funcFParam;
}
#line 1803 "syntax.tab.c"
    break;

  case 48: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB  */
#line 379 "syntax.y"
                                 {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-3].tree));
    funcFParam->ident = *((yyvsp[-2].sval));
    (yyval.tree) = funcFParam;
}
#line 1815 "syntax.tab.c"
    break;

  case 49: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB ArrayIndex  */
#line 386 "syntax.y"
                                            {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-4].tree));
    funcFParam->ident = *((yyvsp[-3].sval));
    funcFParam->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = funcFParam;
}
#line 1828 "syntax.tab.c"
    break;

  case 50: /* FuncFParam: VarType IDENT LEFTSQB error RIGHTSQB  */
#line 394 "syntax.y"
                                       {
    fprintf(stderr, "Error: Unknown function param\n");
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-4].tree));
    funcFParam->ident = *((yyvsp[-3].sval));
    funcFParam->err_empty = true;
    (yyval.tree) = funcFParam;
}
#line 1842 "syntax.tab.c"
    break;

  case 51: /* ArrayIndex: LEFTSQB Exp RIGHTSQB  */
#line 405 "syntax.y"
                       {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = arrayIndex;
}
#line 1852 "syntax.tab.c"
    break;

  case 52: /* ArrayIndex: ArrayIndex LEFTSQB Exp RIGHTSQB  */
#line 410 "syntax.y"
                                  {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[-3].tree));
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = arrayIndex;
}
#line 1863 "syntax.tab.c"
    break;

  case 53: /* Block: LEFTBRACE RIGHTBRACE  */
#line 418 "syntax.y"
                       {
    auto block = new Block();
    (yyval.tree) = block;
}
#line 1872 "syntax.tab.c"
    break;

  case 54: /* Block: LEFTBRACE BlockItemList RIGHTBRACE  */
#line 422 "syntax.y"
                                     {
    auto block = new Block();
    block->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[-1].tree));
    (yyval.tree) = block;
}
#line 1882 "syntax.tab.c"
    break;

  case 55: /* BlockItemList: BlockItem  */
#line 429 "syntax.y"
            {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[0].tree));
    (yyval.tree) = blockItemList;
}
#line 1892 "syntax.tab.c"
    break;

  case 56: /* BlockItemList: BlockItem BlockItemList  */
#line 434 "syntax.y"
                          {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[-1].tree));
    blockItemList->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[0].tree));
    (yyval.tree) = blockItemList;
}
#line 1903 "syntax.tab.c"
    break;

  case 57: /* BlockItem: Decl  */
#line 442 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Decl;
    blockItem->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1914 "syntax.tab.c"
    break;

  case 58: /* BlockItem: Stmt  */
#line 448 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Stmt;
    blockItem->stmt = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1925 "syntax.tab.c"
    break;

  case 59: /* Stmt: LVal '=' Exp ';'  */
#line 456 "syntax.y"
                   {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Assign;
    stmt->lVal = shared_ptr<LVal>((LVal* )(yyvsp[-3].tree));
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 1937 "syntax.tab.c"
    break;

  case 60: /* Stmt: ';'  */
#line 463 "syntax.y"
      {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Empty;
    (yyval.tree) = stmt;
}
#line 1947 "syntax.tab.c"
    break;

  case 61: /* Stmt: Exp ';'  */
#line 468 "syntax.y"
          {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Exp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 1958 "syntax.tab.c"
    break;

  case 62: /* Stmt: Block  */
#line 474 "syntax.y"
        {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Block;
    stmt->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1969 "syntax.tab.c"
    break;

  case 63: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 480 "syntax.y"
                             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::If;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1981 "syntax.tab.c"
    break;

  case 64: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 487 "syntax.y"
                                       {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::IfElse;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-4].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[-2].tree));
    stmt->stmt_if_else = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 1994 "syntax.tab.c"
    break;

  case 65: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 495 "syntax.y"
                                {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::While;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_while = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 2006 "syntax.tab.c"
    break;

  case 66: /* Stmt: BREAK ';'  */
#line 502 "syntax.y"
            {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Break;
    (yyval.tree) = stmt;
}
#line 2016 "syntax.tab.c"
    break;

  case 67: /* Stmt: CONTINUE ';'  */
#line 507 "syntax.y"
               {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Continue;
    (yyval.tree) = stmt;
}
#line 2026 "syntax.tab.c"
    break;

  case 68: /* Stmt: RETURN ';'  */
#line 512 "syntax.y"
             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Return;
    (yyval.tree) = stmt;
}
#line 2036 "syntax.tab.c"
    break;

  case 69: /* Stmt: RETURN Exp ';'  */
#line 517 "syntax.y"
                 {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::ReturnExp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 2047 "syntax.tab.c"
    break;

  case 70: /* ConstExp: Exp  */
#line 525 "syntax.y"
      {
    auto constExp = new ConstExp();
    constExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = constExp;
}
#line 2057 "syntax.tab.c"
    break;

  case 71: /* Exp: AddExp  */
#line 532 "syntax.y"
         {
    auto exp = new Exp();
    exp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = exp;
}
#line 2067 "syntax.tab.c"
    break;

  case 72: /* Cond: LOrExp  */
#line 539 "syntax.y"
         {
    auto cond = new Cond();
    cond->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[0].tree));
    (yyval.tree) = cond;
}
#line 2077 "syntax.tab.c"
    break;

  case 73: /* LVal: IDENT  */
#line 546 "syntax.y"
        {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Var;
    lVal->ident = *((yyvsp[0].sval));
    (yyval.tree) = lVal;
}
#line 2088 "syntax.tab.c"
    break;

  case 74: /* LVal: IDENT ArrayIndex  */
#line 552 "syntax.y"
                   {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Array;
    lVal->ident = *((yyvsp[-1].sval));
    lVal->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = lVal;
}
#line 2100 "syntax.tab.c"
    break;

  case 75: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 561 "syntax.y"
                    {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Exp;
    primaryExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = primaryExp;
}
#line 2111 "syntax.tab.c"
    break;

  case 76: /* PrimaryExp: LVal  */
#line 567 "syntax.y"
       {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::LVal;
    primaryExp->lVal = shared_ptr<LVal>((LVal* )(yyvsp[0].tree));
    (yyval.tree) = primaryExp;
}
#line 2122 "syntax.tab.c"
    break;

  case 77: /* PrimaryExp: INTCONST  */
#line 573 "syntax.y"
           {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Number;
    primaryExp->number = (yyvsp[0].ival);
    (yyval.tree) = primaryExp;
}
#line 2133 "syntax.tab.c"
    break;

  case 78: /* UnaryExp: PrimaryExp  */
#line 581 "syntax.y"
             {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::PrimaryExp;
    unaryExp->primary_exp = shared_ptr<PrimaryExp>((PrimaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2144 "syntax.tab.c"
    break;

  case 79: /* UnaryExp: IDENT LPAREN RPAREN  */
#line 587 "syntax.y"
                      {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-2].sval));
    (yyval.tree) = unaryExp;
}
#line 2155 "syntax.tab.c"
    break;

  case 80: /* UnaryExp: IDENT LPAREN FuncRParamList RPAREN  */
#line 593 "syntax.y"
                                     {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-3].sval));
    unaryExp->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[-1].tree));
    (yyval.tree) = unaryExp;
}
#line 2167 "syntax.tab.c"
    break;

  case 81: /* UnaryExp: UnaryOp UnaryExp  */
#line 600 "syntax.y"
                   {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = (yyvsp[-1].chval);
    unaryExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2179 "syntax.tab.c"
    break;

  case 82: /* UnaryOp: '+'  */
#line 609 "syntax.y"
      {
    (yyval.chval) = '+';
}
#line 2187 "syntax.tab.c"
    break;

  case 83: /* UnaryOp: '-'  */
#line 612 "syntax.y"
      {
    (yyval.chval) = '-';
}
#line 2195 "syntax.tab.c"
    break;

  case 84: /* UnaryOp: '!'  */
#line 615 "syntax.y"
      {
    (yyval.chval) = '!';
}
#line 2203 "syntax.tab.c"
    break;

  case 85: /* FuncRParamList: Exp  */
#line 620 "syntax.y"
      {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = funcRParamList;
}
#line 2213 "syntax.tab.c"
    break;

  case 86: /* FuncRParamList: Exp ',' FuncRParamList  */
#line 625 "syntax.y"
                         {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[-2].tree));
    funcRParamList->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[0].tree));
    (yyval.tree) = funcRParamList;
}
#line 2224 "syntax.tab.c"
    break;

  case 87: /* MulExp: UnaryExp  */
#line 633 "syntax.y"
           {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::UnaryExp;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2235 "syntax.tab.c"
    break;

  case 88: /* MulExp: MulExp '*' UnaryExp  */
#line 639 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "*";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2248 "syntax.tab.c"
    break;

  case 89: /* MulExp: MulExp '/' UnaryExp  */
#line 647 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "/";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2261 "syntax.tab.c"
    break;

  case 90: /* MulExp: MulExp '%' UnaryExp  */
#line 655 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "%";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2274 "syntax.tab.c"
    break;

  case 91: /* AddExp: MulExp  */
#line 665 "syntax.y"
         {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::MulExp;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2285 "syntax.tab.c"
    break;

  case 92: /* AddExp: AddExp '+' MulExp  */
#line 671 "syntax.y"
                    {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "+";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2298 "syntax.tab.c"
    break;

  case 93: /* AddExp: AddExp '-' MulExp  */
#line 679 "syntax.y"
                    {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "-";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2311 "syntax.tab.c"
    break;

  case 94: /* RelExp: AddExp  */
#line 689 "syntax.y"
         {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::AddExp;
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2322 "syntax.tab.c"
    break;

  case 95: /* RelExp: RelExp '<' AddExp  */
#line 695 "syntax.y"
                    {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2335 "syntax.tab.c"
    break;

  case 96: /* RelExp: RelExp '<' error  */
#line 703 "syntax.y"
                   {
    fprintf(stderr, "Error: Unknown operator\n");
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<";
    auto addExp = new AddExp();
    addExp->err_empty = true;
    relExp->add_exp = shared_ptr<AddExp>(addExp);
    (yyval.tree) = relExp;

}
#line 2352 "syntax.tab.c"
    break;

  case 97: /* RelExp: RelExp '>' AddExp  */
#line 715 "syntax.y"
                    {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2365 "syntax.tab.c"
    break;

  case 98: /* RelExp: RelExp LE AddExp  */
#line 723 "syntax.y"
                   {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2378 "syntax.tab.c"
    break;

  case 99: /* RelExp: RelExp GE AddExp  */
#line 731 "syntax.y"
                   {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2391 "syntax.tab.c"
    break;

  case 100: /* EqExp: RelExp  */
#line 741 "syntax.y"
         {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::RelExp;
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2402 "syntax.tab.c"
    break;

  case 101: /* EqExp: EqExp EQ RelExp  */
#line 747 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "==";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2415 "syntax.tab.c"
    break;

  case 102: /* EqExp: EqExp NE RelExp  */
#line 755 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "!=";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2428 "syntax.tab.c"
    break;

  case 103: /* LAndExp: EqExp  */
#line 765 "syntax.y"
        {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::EqExp;
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2439 "syntax.tab.c"
    break;

  case 104: /* LAndExp: LAndExp LAND EqExp  */
#line 771 "syntax.y"
                     {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::LAndEqExp;
    lAndExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[-2].tree));
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2451 "syntax.tab.c"
    break;

  case 105: /* LOrExp: LAndExp  */
#line 780 "syntax.y"
          {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LAndExp;
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2462 "syntax.tab.c"
    break;

  case 106: /* LOrExp: LOrExp LOR LAndExp  */
#line 786 "syntax.y"
                     {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LOrLAndExp;
    lOrExp->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[-2].tree));
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2474 "syntax.tab.c"
    break;


#line 2478 "syntax.tab.c"

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

#line 795 "syntax.y"


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


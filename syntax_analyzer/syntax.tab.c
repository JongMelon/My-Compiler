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
#line 5 "syntax.y"


#include <stdio.h>
#include <string>
//#include "Tree.h"
#include "Trans.h"

int yylex(void);
void yyerror(const char *s);

string file_name = "assembly1.s";


#line 85 "syntax.tab.c"

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
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_INCLUDE = 14,                   /* INCLUDE  */
  YYSYMBOL_FILE_NAME = 15,                 /* FILE_NAME  */
  YYSYMBOL_INTCONST = 16,                  /* INTCONST  */
  YYSYMBOL_LEFTSQB = 17,                   /* LEFTSQB  */
  YYSYMBOL_RIGHTSQB = 18,                  /* RIGHTSQB  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LEFTBRACE = 21,                 /* LEFTBRACE  */
  YYSYMBOL_RIGHTBRACE = 22,                /* RIGHTBRACE  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '%'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NE = 37,                        /* NE  */
  YYSYMBOL_LOR = 38,                       /* LOR  */
  YYSYMBOL_LAND = 39,                      /* LAND  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_CompList = 43,                  /* CompList  */
  YYSYMBOL_DecOrDef = 44,                  /* DecOrDef  */
  YYSYMBOL_Decl = 45,                      /* Decl  */
  YYSYMBOL_ConstDecl = 46,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 47,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 48,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 49,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 50,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 52,                /* VarDefList  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_ConstArrayIndex = 54,           /* ConstArrayIndex  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitValList = 56,               /* InitValList  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_VarType = 58,                   /* VarType  */
  YYSYMBOL_FuncType = 59,                  /* FuncType  */
  YYSYMBOL_FuncFParamList = 60,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 61,                /* FuncFParam  */
  YYSYMBOL_ArrayIndex = 62,                /* ArrayIndex  */
  YYSYMBOL_Block = 63,                     /* Block  */
  YYSYMBOL_BlockItemList = 64,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 65,                 /* BlockItem  */
  YYSYMBOL_Stmt = 66,                      /* Stmt  */
  YYSYMBOL_ConstExp = 67,                  /* ConstExp  */
  YYSYMBOL_Exp = 68,                       /* Exp  */
  YYSYMBOL_Cond = 69,                      /* Cond  */
  YYSYMBOL_LVal = 70,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 71,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 72,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 73,                   /* UnaryOp  */
  YYSYMBOL_FuncRParamList = 74,            /* FuncRParamList  */
  YYSYMBOL_MulExp = 75,                    /* MulExp  */
  YYSYMBOL_AddExp = 76,                    /* AddExp  */
  YYSYMBOL_RelExp = 77,                    /* RelExp  */
  YYSYMBOL_EqExp = 78,                     /* EqExp  */
  YYSYMBOL_LAndExp = 79,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 80,                    /* LOrExp  */
  YYSYMBOL_INCLUDE_STMT = 81               /* INCLUDE_STMT  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,    29,     2,     2,     2,    26,    40,     2,
       2,     2,    24,    23,    30,     2,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      27,    32,    28,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    72,    78,    91,    97,   104,   110,   118,
     124,   132,   138,   150,   157,   175,   180,   185,   193,   198,
     206,   212,   221,   227,   238,   244,   251,   258,   266,   273,
     281,   289,   300,   306,   316,   322,   327,   335,   343,   355,
     362,   370,   381,   388,   393,   400,   408,   420,   427,   434,
     442,   453,   459,   469,   473,   480,   488,   500,   506,   514,
     521,   526,   532,   538,   545,   553,   560,   565,   570,   575,
     583,   590,   690,   697,   703,   712,   718,   724,   730,   738,
     744,   750,   757,   764,   773,   776,   779,   784,   790,   800,
     806,   814,   822,   832,   838,   846,   856,   865,   873,   883,
     891,   899,   909,   918,   929,   942,   948,   957,   963,   972
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
  "STRING", "INCLUDE", "FILE_NAME", "INTCONST", "LEFTSQB", "RIGHTSQB",
  "LPAREN", "RPAREN", "LEFTBRACE", "RIGHTBRACE", "'+'", "'*'", "'/'",
  "'%'", "'<'", "'>'", "'!'", "','", "';'", "'='", "MINUS", "LE", "GE",
  "EQ", "NE", "LOR", "LAND", "'&'", "$accept", "CompUnit", "CompList",
  "DecOrDef", "Decl", "ConstDecl", "ConstDefList", "ConstDef",
  "ConstInitVal", "ConstInitValList", "VarDecl", "VarDefList", "VarDef",
  "ConstArrayIndex", "InitVal", "InitValList", "FuncDef", "VarType",
  "FuncType", "FuncFParamList", "FuncFParam", "ArrayIndex", "Block",
  "BlockItemList", "BlockItem", "Stmt", "ConstExp", "Exp", "Cond", "LVal",
  "PrimaryExp", "UnaryExp", "UnaryOp", "FuncRParamList", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "INCLUDE_STMT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,     2,    50,   131,    47,  -166,   146,    83,  -166,  -166,
     125,  -166,  -166,  -166,  -166,  -166,   147,    41,    42,    84,
     129,  -166,  -166,    88,  -166,    53,   150,  -166,   299,   235,
      64,    65,   146,  -166,    61,   157,  -166,    20,  -166,    39,
    -166,  -166,   299,  -166,  -166,  -166,    94,    90,  -166,  -166,
    -166,  -166,   299,   116,    -7,    91,  -166,  -166,   299,   235,
     235,    66,  -166,  -166,   250,    77,   100,  -166,    95,    96,
     112,    -2,  -166,   299,   265,   110,   113,  -166,  -166,  -166,
     299,   299,   299,   299,   299,  -166,  -166,    12,   118,  -166,
    -166,   235,   220,  -166,  -166,   235,    86,  -166,    96,   163,
    -166,   127,    96,    83,   143,  -166,  -166,    56,   299,  -166,
    -166,  -166,  -166,   116,   116,  -166,   235,  -166,  -166,  -166,
     135,   161,  -166,  -166,   172,   174,   164,   166,   280,  -166,
    -166,  -166,   146,  -166,   197,  -166,  -166,   168,   182,     7,
    -166,  -166,  -166,  -166,   299,   199,  -166,   250,  -166,   299,
     299,  -166,  -166,  -166,   184,  -166,  -166,  -166,   299,   203,
     205,  -166,  -166,  -166,  -166,   204,   111,   141,   186,   185,
     207,  -166,   198,  -166,   110,    44,     4,   299,   299,   299,
     299,   299,   299,   299,    44,  -166,   226,  -166,  -166,  -166,
    -166,  -166,   111,   111,   141,   186,  -166,    44,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,    44,    43,
       0,     3,     5,     7,     8,     6,     0,     0,    24,     0,
       0,    22,    42,     0,     4,    24,     0,   109,     0,     0,
      26,    28,     0,    21,     0,     0,    11,     0,    20,    73,
      78,    77,     0,    84,    86,    85,     0,     0,    70,    76,
      79,    89,     0,    93,    71,     0,    25,    34,     0,     0,
       0,    30,    23,    10,     0,     0,     0,     9,     0,     0,
       0,     0,    45,     0,     0,    74,     0,    83,    32,    82,
       0,     0,     0,     0,     0,    35,    37,     0,     0,    27,
      29,     0,     0,    13,    15,     0,     0,    12,     0,     0,
      39,    47,     0,     0,     0,    80,    87,     0,     0,    75,
      90,    91,    92,    94,    95,    36,     0,    33,    31,    16,
      18,     0,    14,    41,     0,     0,     0,     0,     0,    53,
      60,    57,     0,    62,     0,    55,    58,     0,    76,     0,
      40,    46,    51,    81,     0,     0,    38,     0,    17,     0,
       0,    66,    67,    68,     0,    54,    56,    61,     0,     0,
      48,    88,    52,    19,    96,     0,   102,   105,   107,    72,
       0,    69,     0,    50,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    63,    98,    97,    99,
     100,   101,   103,   104,   106,   108,    65,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   224,   -93,  -166,  -166,   169,   176,    97,
    -166,   232,   213,   -30,   -48,  -166,  -166,   240,   -86,  -166,
     149,    99,   -67,  -166,   121,  -165,   -19,   -28,   107,   -96,
    -166,     9,  -166,  -166,   106,  -166,    31,    68,    79,  -166,
    -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,    11,    12,    13,    35,    36,   120,   121,
      14,    26,    21,    30,    56,    87,    15,    70,    16,    71,
      72,    75,   133,   134,   135,   136,    94,    57,   165,    49,
      50,    51,    52,   107,    53,    54,   166,   167,   168,   169,
       3
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    61,   100,   138,    65,   187,   131,    86,   159,    47,
     186,    89,    90,   132,    76,    39,    83,    40,   102,   196,
      41,    68,     1,    42,    22,   160,    84,    43,   103,     4,
      48,   123,   198,    44,   115,   140,    48,    45,   138,    88,
      69,   131,   116,   118,    46,   104,   106,   122,   132,   124,
       5,   125,   126,   127,   128,    39,    73,    40,    74,    28,
      41,    79,    17,    42,    48,    99,    65,    43,   146,    27,
      28,   137,    37,    44,    29,   130,   143,    45,    28,   138,
     145,    58,    28,    58,    46,    29,   144,    22,   138,   110,
     111,   112,    63,    64,    58,    31,    59,    60,    91,    34,
     154,   138,    39,    28,    40,    77,   137,    41,    78,    95,
      42,    96,    55,    85,    43,    98,   161,    99,    64,    48,
      44,   164,   164,   101,    45,    -2,     6,   108,     7,     8,
     172,    46,     6,   109,     7,     8,   117,     9,   176,   177,
      80,    81,    82,     9,   139,   178,   179,   137,   188,   189,
     190,   191,   164,   164,   164,   164,   137,    18,    25,    32,
      33,   142,    19,    19,     6,   147,     7,     8,   124,   137,
     125,   126,   127,   128,    39,     9,    40,   180,   181,    41,
      32,    38,    42,   148,    99,   129,    43,    66,    67,   113,
     114,   149,    44,   150,   130,   151,    45,   152,     6,   157,
       7,     8,   124,    46,   125,   126,   127,   128,    39,     9,
      40,   192,   193,    41,   158,   171,    42,   162,    99,   155,
      43,   173,    73,   183,   175,   182,    44,   184,   130,   185,
      45,    39,   197,    40,    24,    97,    41,    46,    20,    42,
      93,    92,   119,    43,   163,    62,    39,    23,    40,    44,
     194,    41,   141,    45,    42,   156,    55,   170,    43,   174,
      46,    39,   195,    40,    44,     0,    41,     0,    45,    42,
       0,    92,     0,    43,     0,    46,    39,     0,    40,    44,
       0,    41,     0,    45,    42,   105,     0,     0,    43,     0,
      46,    39,     0,    40,    44,     0,    41,     0,    45,    42,
       0,     0,     0,    43,     0,    46,     0,     0,     0,    44,
      39,   153,    40,    45,     0,    41,     0,     0,    42,     0,
      46,     0,    43,     0,     0,     0,     0,     0,    44,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
      28,    31,    69,    99,    34,     1,    99,    55,     1,    28,
     175,    59,    60,    99,    42,    11,    23,    13,    20,   184,
      16,     1,    14,    19,     4,    18,    33,    23,    30,    27,
      58,    98,   197,    29,    22,   102,    64,    33,   134,    58,
      20,   134,    30,    91,    40,    73,    74,    95,   134,     5,
       0,     7,     8,     9,    10,    11,    17,    13,    19,    17,
      16,    52,    15,    19,    92,    21,    96,    23,   116,    28,
      17,    99,    19,    29,    32,    31,    20,    33,    17,   175,
     108,    17,    17,    17,    40,    32,    30,     4,   184,    80,
      81,    82,    31,    32,    17,    11,    32,    32,    32,    11,
     128,   197,    11,    17,    13,    11,   134,    16,    18,    32,
      19,    11,    21,    22,    23,    20,   144,    21,    32,   147,
      29,   149,   150,    11,    33,     0,     1,    17,     3,     4,
     158,    40,     1,    20,     3,     4,    18,    12,    27,    28,
      24,    25,    26,    12,    17,    34,    35,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    11,    11,    30,
      31,    18,    16,    16,     1,    30,     3,     4,     5,   197,
       7,     8,     9,    10,    11,    12,    13,    36,    37,    16,
      30,    31,    19,    22,    21,    22,    23,    30,    31,    83,
      84,    19,    29,    19,    31,    31,    33,    31,     1,    31,
       3,     4,     5,    40,     7,     8,     9,    10,    11,    12,
      13,   180,   181,    16,    32,    31,    19,    18,    21,    22,
      23,    18,    17,    38,    20,    39,    29,    20,    31,    31,
      33,    11,     6,    13,    10,    66,    16,    40,     6,    19,
      64,    21,    22,    23,   147,    32,    11,     7,    13,    29,
     182,    16,   103,    33,    19,   134,    21,   150,    23,   160,
      40,    11,   183,    13,    29,    -1,    16,    -1,    33,    19,
      -1,    21,    -1,    23,    -1,    40,    11,    -1,    13,    29,
      -1,    16,    -1,    33,    19,    20,    -1,    -1,    23,    -1,
      40,    11,    -1,    13,    29,    -1,    16,    -1,    33,    19,
      -1,    -1,    -1,    23,    -1,    40,    -1,    -1,    -1,    29,
      11,    31,    13,    33,    -1,    16,    -1,    -1,    19,    -1,
      40,    -1,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    42,    81,    27,     0,     1,     3,     4,    12,
      43,    44,    45,    46,    51,    57,    59,    15,    11,    16,
      52,    53,     4,    58,    44,    11,    52,    28,    17,    32,
      54,    11,    30,    31,    11,    47,    48,    19,    31,    11,
      13,    16,    19,    23,    29,    33,    40,    67,    68,    70,
      71,    72,    73,    75,    76,    21,    55,    68,    17,    32,
      32,    54,    53,    31,    32,    54,    30,    31,     1,    20,
      58,    60,    61,    17,    19,    62,    68,    11,    18,    72,
      24,    25,    26,    23,    33,    22,    55,    56,    67,    55,
      55,    32,    21,    49,    67,    32,    11,    48,    20,    21,
      63,    11,    20,    30,    68,    20,    68,    74,    17,    20,
      72,    72,    72,    75,    75,    22,    30,    18,    55,    22,
      49,    50,    55,    63,     5,     7,     8,     9,    10,    22,
      31,    45,    59,    63,    64,    65,    66,    68,    70,    17,
      63,    61,    18,    20,    30,    68,    55,    30,    22,    19,
      19,    31,    31,    31,    68,    22,    65,    31,    32,     1,
      18,    68,    18,    50,    68,    69,    77,    78,    79,    80,
      69,    31,    68,    18,    62,    20,    27,    28,    34,    35,
      36,    37,    39,    38,    20,    31,    66,     1,    68,    68,
      68,    68,    77,    77,    78,    79,    66,     6,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    57,
      57,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    68,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     4,
       4,     1,     3,     3,     4,     1,     2,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     2,     4,     2,     4,
       3,     5,     3,     4,     1,     2,     3,     1,     3,     5,
       6,     6,     1,     1,     1,     1,     3,     2,     4,     5,
       5,     3,     4,     2,     3,     1,     2,     1,     1,     4,
       1,     2,     1,     5,     7,     5,     2,     2,     2,     3,
       1,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       3,     4,     2,     2,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     4
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
  case 2: /* CompUnit: INCLUDE_STMT CompList  */
#line 58 "syntax.y"
                        {
    auto compUnit = new CompUnit();
    compUnit->compList = shared_ptr<CompList>((CompList* )(yyvsp[0].tree));
    (yyval.tree) = compUnit;
    std::cout << "digraph \" \"{" << std::endl;
    std::cout << "node [shape = record,height=.1]" << std::endl;
    compUnit->print(0, "");
    std::cout << "}" << std::endl;

    auto Code_Generator = new CodeGenerator();
    Code_Generator->dump(shared_ptr<CompUnit>(compUnit), file_name);
}
#line 1325 "syntax.tab.c"
    break;

  case 3: /* CompList: DecOrDef  */
#line 72 "syntax.y"
           {
    auto compList = new CompList();
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )(yyvsp[0].tree));
    compList->declOrDefs.push_back(compList->declOrDef);
    (yyval.tree) = compList;
}
#line 1336 "syntax.tab.c"
    break;

  case 4: /* CompList: CompList DecOrDef  */
#line 78 "syntax.y"
                    {
    auto compList = new CompList();
    compList->if_more_CompList = true;
    compList->compList = shared_ptr<CompList>((CompList* )(yyvsp[-1].tree));
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )(yyvsp[0].tree));

    compList->declOrDefs = compList->compList->declOrDefs;
    compList->declOrDefs.push_back(compList->declOrDef);

    (yyval.tree) = compList;
}
#line 1352 "syntax.tab.c"
    break;

  case 5: /* DecOrDef: Decl  */
#line 91 "syntax.y"
       {
    auto decOrDef = new DeclOrDef();
    decOrDef->if_decl = true;
    decOrDef->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1363 "syntax.tab.c"
    break;

  case 6: /* DecOrDef: FuncDef  */
#line 97 "syntax.y"
          {
    auto decOrDef = new DeclOrDef();
    decOrDef->funcDef = shared_ptr<FuncDef>((FuncDef* )(yyvsp[0].tree));
    (yyval.tree) = decOrDef;
}
#line 1373 "syntax.tab.c"
    break;

  case 7: /* Decl: ConstDecl  */
#line 104 "syntax.y"
            {
    auto decl = new Decl();
    decl->decType = DecType::ConstDecl;
    decl->constDecl = shared_ptr<ConstDecl>((ConstDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1384 "syntax.tab.c"
    break;

  case 8: /* Decl: VarDecl  */
#line 110 "syntax.y"
          {
    auto decl = new Decl();
    decl->decType = DecType::VarDecl;
    decl->varDecl = shared_ptr<VarDecl>((VarDecl* )(yyvsp[0].tree));
    (yyval.tree) = decl;
}
#line 1395 "syntax.tab.c"
    break;

  case 9: /* ConstDecl: CONST VarType ConstDefList ';'  */
#line 118 "syntax.y"
                                 {
    auto constDecl = new ConstDecl();
    constDecl->varType = shared_ptr<VarType>((VarType* )(yyvsp[-2].tree));
    constDecl->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[-1].tree));
    (yyval.tree) = constDecl;
}
#line 1406 "syntax.tab.c"
    break;

  case 10: /* ConstDecl: CONST VarType IDENT ';'  */
#line 124 "syntax.y"
                          {
    fprintf(stderr, "Error: Unknown constdeflist\n");
    auto constDecl = new ConstDecl();
    constDecl->err_empty = true;
    (yyval.tree) = constDecl;
}
#line 1417 "syntax.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 132 "syntax.y"
           {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[0].tree));
    constDefList->constdefs.push_back(constDefList->constDef);
    (yyval.tree) = constDefList;
}
#line 1428 "syntax.tab.c"
    break;

  case 12: /* ConstDefList: ConstDefList ',' ConstDef  */
#line 138 "syntax.y"
                            {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )(yyvsp[0].tree));
    constDefList->constDefList = shared_ptr<ConstDefList>((ConstDefList* )(yyvsp[-2].tree));

    constDefList->constdefs = constDefList->constDefList->constdefs;
    constDefList->constdefs.push_back(constDefList->constDef);

    (yyval.tree) = constDefList;
}
#line 1443 "syntax.tab.c"
    break;

  case 13: /* ConstDef: IDENT '=' ConstInitVal  */
#line 150 "syntax.y"
                         {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Var;
    constDef->ident = *((yyvsp[-2].sval));
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1455 "syntax.tab.c"
    break;

  case 14: /* ConstDef: IDENT ConstArrayIndex '=' InitVal  */
#line 157 "syntax.y"
                                    {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Array;
    constDef->ident = *((yyvsp[-3].sval));
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    constDef->array_initval = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = constDef;
}
#line 1468 "syntax.tab.c"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 175 "syntax.y"
           {
    auto constInitVal = new ConstInitVal();
    constInitVal->constExp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[0].tree));
    (yyval.tree) = constInitVal;
}
#line 1478 "syntax.tab.c"
    break;

  case 16: /* ConstInitVal: LEFTBRACE RIGHTBRACE  */
#line 180 "syntax.y"
                       {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    (yyval.tree) = constInitVal;
}
#line 1488 "syntax.tab.c"
    break;

  case 17: /* ConstInitVal: LEFTBRACE ConstInitValList RIGHTBRACE  */
#line 185 "syntax.y"
                                        {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    constInitVal->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[-1].tree));
    (yyval.tree) = constInitVal;
}
#line 1499 "syntax.tab.c"
    break;

  case 18: /* ConstInitValList: ConstInitVal  */
#line 193 "syntax.y"
               {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1509 "syntax.tab.c"
    break;

  case 19: /* ConstInitValList: ConstInitVal ',' ConstInitValList  */
#line 198 "syntax.y"
                                    {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )(yyvsp[-2].tree));
    constInitValList->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )(yyvsp[0].tree));
    (yyval.tree) = constInitValList;
}
#line 1520 "syntax.tab.c"
    break;

  case 20: /* VarDecl: FuncType VarDefList ';'  */
#line 206 "syntax.y"
                          {
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-1].tree));
    varDecl->vardefs = varDecl->varDefList->vardefs;
    (yyval.tree) = varDecl;
}
#line 1531 "syntax.tab.c"
    break;

  case 21: /* VarDecl: error VarDefList ';'  */
#line 212 "syntax.y"
                       {
    fprintf(stderr, "Error: Unknown VarType\n");
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-1].tree));
    varDecl->unknownType = true;
    (yyval.tree) = varDecl;
}
#line 1543 "syntax.tab.c"
    break;

  case 22: /* VarDefList: VarDef  */
#line 221 "syntax.y"
         {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[0].tree));
    varDefList->vardefs.push_back(varDefList->varDef);
    (yyval.tree) = varDefList;
}
#line 1554 "syntax.tab.c"
    break;

  case 23: /* VarDefList: VarDefList ',' VarDef  */
#line 227 "syntax.y"
                        {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )(yyvsp[0].tree));
    varDefList->varDefList = shared_ptr<VarDefList>((VarDefList* )(yyvsp[-2].tree));

    varDefList->vardefs = varDefList->varDefList->vardefs;
    varDefList->vardefs.push_back(varDefList->varDef);
    (yyval.tree) = varDefList;
}
#line 1568 "syntax.tab.c"
    break;

  case 24: /* VarDef: IDENT  */
#line 238 "syntax.y"
        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[0].sval));
    (yyval.tree) = varDef;
}
#line 1579 "syntax.tab.c"
    break;

  case 25: /* VarDef: IDENT '=' InitVal  */
#line 244 "syntax.y"
                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[-2].sval));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1591 "syntax.tab.c"
    break;

  case 26: /* VarDef: IDENT ConstArrayIndex  */
#line 251 "syntax.y"
                        {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-1].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1603 "syntax.tab.c"
    break;

  case 27: /* VarDef: IDENT ConstArrayIndex '=' InitVal  */
#line 258 "syntax.y"
                                    {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-3].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1616 "syntax.tab.c"
    break;

  case 28: /* VarDef: INTCONST IDENT  */
#line 266 "syntax.y"
                 {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[0].sval));
    (yyval.tree) = varDef;
}
#line 1628 "syntax.tab.c"
    break;

  case 29: /* VarDef: INTCONST IDENT '=' InitVal  */
#line 273 "syntax.y"
                             {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *((yyvsp[-2].sval));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1641 "syntax.tab.c"
    break;

  case 30: /* VarDef: INTCONST IDENT ConstArrayIndex  */
#line 281 "syntax.y"
                                 {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-1].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1654 "syntax.tab.c"
    break;

  case 31: /* VarDef: INTCONST IDENT ConstArrayIndex '=' InitVal  */
#line 289 "syntax.y"
                                             {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *((yyvsp[-3].sval));
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-2].tree));
    varDef->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    (yyval.tree) = varDef;
}
#line 1668 "syntax.tab.c"
    break;

  case 32: /* ConstArrayIndex: LEFTSQB ConstExp RIGHTSQB  */
#line 300 "syntax.y"
                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    constArrayIndex->const_exps.push_back(constArrayIndex->const_exp);
    (yyval.tree) = constArrayIndex;
}
#line 1679 "syntax.tab.c"
    break;

  case 33: /* ConstArrayIndex: ConstArrayIndex LEFTSQB ConstExp RIGHTSQB  */
#line 306 "syntax.y"
                                            {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )(yyvsp[-3].tree));
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )(yyvsp[-1].tree));
    constArrayIndex->const_exps = constArrayIndex->constArrayIndex->const_exps;
    constArrayIndex->const_exps.push_back(constArrayIndex->const_exp);
    (yyval.tree) = constArrayIndex;
}
#line 1692 "syntax.tab.c"
    break;

  case 34: /* InitVal: Exp  */
#line 316 "syntax.y"
      {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Var;
    initVal->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = initVal;
}
#line 1703 "syntax.tab.c"
    break;

  case 35: /* InitVal: LEFTBRACE RIGHTBRACE  */
#line 322 "syntax.y"
                       {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    (yyval.tree) = initVal;
}
#line 1713 "syntax.tab.c"
    break;

  case 36: /* InitVal: LEFTBRACE InitValList RIGHTBRACE  */
#line 327 "syntax.y"
                                   {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    initVal->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[-1].tree));
    (yyval.tree) = initVal;
}
#line 1724 "syntax.tab.c"
    break;

  case 37: /* InitValList: InitVal  */
#line 335 "syntax.y"
          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));

    initValList->initVals.push_back(initValList->initVal);

    (yyval.tree) = initValList;
}
#line 1737 "syntax.tab.c"
    break;

  case 38: /* InitValList: InitValList ',' InitVal  */
#line 343 "syntax.y"
                          {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )(yyvsp[0].tree));
    initValList->initValList = shared_ptr<InitValList>((InitValList* )(yyvsp[-2].tree));

    initValList->initVals = initValList->initValList->initVals;
    initValList->initVals.push_back(initValList->initVal);

    (yyval.tree) = initValList;
}
#line 1752 "syntax.tab.c"
    break;

  case 39: /* FuncDef: FuncType IDENT LPAREN RPAREN Block  */
#line 355 "syntax.y"
                                     {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-4].tree));
    funcDef->ident = *((yyvsp[-3].sval));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1764 "syntax.tab.c"
    break;

  case 40: /* FuncDef: FuncType IDENT LPAREN FuncFParamList RPAREN Block  */
#line 362 "syntax.y"
                                                    {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-5].tree));
    funcDef->ident = *((yyvsp[-4].sval));
    funcDef->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[-2].tree));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = funcDef;
}
#line 1777 "syntax.tab.c"
    break;

  case 41: /* FuncDef: FuncType IDENT LPAREN error RPAREN Block  */
#line 370 "syntax.y"
                                           {
    fprintf(stderr, "Error: Unknown funcfparamlist\n");
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )(yyvsp[-5].tree));
    funcDef->ident = *((yyvsp[-4].sval));
    funcDef->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    funcDef->err_empty = true;
    (yyval.tree) = funcDef;
}
#line 1791 "syntax.tab.c"
    break;

  case 42: /* VarType: INT  */
#line 381 "syntax.y"
      {
    auto varType = new VarType();
    varType->type = "int";
    (yyval.tree) = varType;
}
#line 1801 "syntax.tab.c"
    break;

  case 43: /* FuncType: VOID  */
#line 388 "syntax.y"
       {
    auto funcType = new FuncType();
    funcType->type = "void";
    (yyval.tree) = funcType;
}
#line 1811 "syntax.tab.c"
    break;

  case 44: /* FuncType: INT  */
#line 393 "syntax.y"
      {
    auto funcType = new FuncType();
    funcType->type = "int";
    (yyval.tree) = funcType;
}
#line 1821 "syntax.tab.c"
    break;

  case 45: /* FuncFParamList: FuncFParam  */
#line 400 "syntax.y"
             {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[0].tree));

    funcFParamList->funcFParams.push_back(funcFParamList->funcFParam);

    (yyval.tree) = funcFParamList;
}
#line 1834 "syntax.tab.c"
    break;

  case 46: /* FuncFParamList: FuncFParamList ',' FuncFParam  */
#line 408 "syntax.y"
                                {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )(yyvsp[0].tree));
    funcFParamList->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )(yyvsp[-2].tree));

    funcFParamList->funcFParams = funcFParamList->funcFParamList->funcFParams;
    funcFParamList->funcFParams.push_back(funcFParamList->funcFParam);

    (yyval.tree) = funcFParamList;
}
#line 1849 "syntax.tab.c"
    break;

  case 47: /* FuncFParam: VarType IDENT  */
#line 420 "syntax.y"
                {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-1].tree));
    funcFParam->ident = *((yyvsp[0].sval));
    (yyval.tree) = funcFParam;
}
#line 1861 "syntax.tab.c"
    break;

  case 48: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB  */
#line 427 "syntax.y"
                                 {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-3].tree));
    funcFParam->ident = *((yyvsp[-2].sval));
    (yyval.tree) = funcFParam;
}
#line 1873 "syntax.tab.c"
    break;

  case 49: /* FuncFParam: VarType IDENT LEFTSQB RIGHTSQB ArrayIndex  */
#line 434 "syntax.y"
                                            {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-4].tree));
    funcFParam->ident = *((yyvsp[-3].sval));
    funcFParam->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = funcFParam;
}
#line 1886 "syntax.tab.c"
    break;

  case 50: /* FuncFParam: VarType IDENT LEFTSQB error RIGHTSQB  */
#line 442 "syntax.y"
                                       {
    fprintf(stderr, "Error: Unknown function param\n");
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )(yyvsp[-4].tree));
    funcFParam->ident = *((yyvsp[-3].sval));
    funcFParam->err_empty = true;
    (yyval.tree) = funcFParam;
}
#line 1900 "syntax.tab.c"
    break;

  case 51: /* ArrayIndex: LEFTSQB Exp RIGHTSQB  */
#line 453 "syntax.y"
                       {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    arrayIndex->exps.push_back(arrayIndex->exp);
    (yyval.tree) = arrayIndex;
}
#line 1911 "syntax.tab.c"
    break;

  case 52: /* ArrayIndex: ArrayIndex LEFTSQB Exp RIGHTSQB  */
#line 459 "syntax.y"
                                  {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[-3].tree));
    arrayIndex->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    arrayIndex->exps = arrayIndex->arrayIndex->exps;
    arrayIndex->exps.push_back(arrayIndex->exp);
    (yyval.tree) = arrayIndex;
}
#line 1924 "syntax.tab.c"
    break;

  case 53: /* Block: LEFTBRACE RIGHTBRACE  */
#line 469 "syntax.y"
                       {
    auto block = new Block();
    (yyval.tree) = block;
}
#line 1933 "syntax.tab.c"
    break;

  case 54: /* Block: LEFTBRACE BlockItemList RIGHTBRACE  */
#line 473 "syntax.y"
                                     {
    auto block = new Block();
    block->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[-1].tree));
    (yyval.tree) = block;
}
#line 1943 "syntax.tab.c"
    break;

  case 55: /* BlockItemList: BlockItem  */
#line 480 "syntax.y"
            {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[0].tree));

    blockItemList->blockItems.push_back(blockItemList->blockItem);

    (yyval.tree) = blockItemList;
}
#line 1956 "syntax.tab.c"
    break;

  case 56: /* BlockItemList: BlockItemList BlockItem  */
#line 488 "syntax.y"
                          {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )(yyvsp[0].tree));
    blockItemList->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )(yyvsp[-1].tree));

    blockItemList->blockItems = blockItemList->blockItemList->blockItems;
    blockItemList->blockItems.push_back(blockItemList->blockItem);

    (yyval.tree) = blockItemList;
}
#line 1971 "syntax.tab.c"
    break;

  case 57: /* BlockItem: Decl  */
#line 500 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Decl;
    blockItem->decl = shared_ptr<Decl>((Decl* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1982 "syntax.tab.c"
    break;

  case 58: /* BlockItem: Stmt  */
#line 506 "syntax.y"
       {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Stmt;
    blockItem->stmt = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = blockItem;
}
#line 1993 "syntax.tab.c"
    break;

  case 59: /* Stmt: LVal '=' Exp ';'  */
#line 514 "syntax.y"
                   {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Assign;
    stmt->lVal = shared_ptr<LVal>((LVal* )(yyvsp[-3].tree));
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 2005 "syntax.tab.c"
    break;

  case 60: /* Stmt: ';'  */
#line 521 "syntax.y"
      {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Empty;
    (yyval.tree) = stmt;
}
#line 2015 "syntax.tab.c"
    break;

  case 61: /* Stmt: Exp ';'  */
#line 526 "syntax.y"
          {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Exp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 2026 "syntax.tab.c"
    break;

  case 62: /* Stmt: Block  */
#line 532 "syntax.y"
        {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Block;
    stmt->block = shared_ptr<Block>((Block* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 2037 "syntax.tab.c"
    break;

  case 63: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 538 "syntax.y"
                             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::If;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 2049 "syntax.tab.c"
    break;

  case 64: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 545 "syntax.y"
                                       {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::IfElse;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-4].tree));
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )(yyvsp[-2].tree));
    stmt->stmt_if_else = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 2062 "syntax.tab.c"
    break;

  case 65: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 553 "syntax.y"
                                {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::While;
    stmt->cond = shared_ptr<Cond>((Cond* )(yyvsp[-2].tree));
    stmt->stmt_while = shared_ptr<Stmt>((Stmt* )(yyvsp[0].tree));
    (yyval.tree) = stmt;
}
#line 2074 "syntax.tab.c"
    break;

  case 66: /* Stmt: BREAK ';'  */
#line 560 "syntax.y"
            {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Break;
    (yyval.tree) = stmt;
}
#line 2084 "syntax.tab.c"
    break;

  case 67: /* Stmt: CONTINUE ';'  */
#line 565 "syntax.y"
               {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Continue;
    (yyval.tree) = stmt;
}
#line 2094 "syntax.tab.c"
    break;

  case 68: /* Stmt: RETURN ';'  */
#line 570 "syntax.y"
             {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Return;
    (yyval.tree) = stmt;
}
#line 2104 "syntax.tab.c"
    break;

  case 69: /* Stmt: RETURN Exp ';'  */
#line 575 "syntax.y"
                 {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::ReturnExp;
    stmt->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = stmt;
}
#line 2115 "syntax.tab.c"
    break;

  case 70: /* ConstExp: Exp  */
#line 583 "syntax.y"
      {
    auto constExp = new ConstExp();
    constExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = constExp;
}
#line 2125 "syntax.tab.c"
    break;

  case 71: /* Exp: AddExp  */
#line 590 "syntax.y"
         {
    auto exp = new Exp();
    exp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[0].tree));
    exp->is_const = exp->add_exp->is_const;
    (yyval.tree) = exp;
}
#line 2136 "syntax.tab.c"
    break;

  case 72: /* Cond: LOrExp  */
#line 690 "syntax.y"
         {
    auto cond = new Cond();
    cond->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[0].tree));
    (yyval.tree) = cond;
}
#line 2146 "syntax.tab.c"
    break;

  case 73: /* LVal: IDENT  */
#line 697 "syntax.y"
        {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Var;
    lVal->ident = *((yyvsp[0].sval));
    (yyval.tree) = lVal;
}
#line 2157 "syntax.tab.c"
    break;

  case 74: /* LVal: IDENT ArrayIndex  */
#line 703 "syntax.y"
                   {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Array;
    lVal->ident = *((yyvsp[-1].sval));
    lVal->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )(yyvsp[0].tree));
    (yyval.tree) = lVal;
}
#line 2169 "syntax.tab.c"
    break;

  case 75: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 712 "syntax.y"
                    {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Exp;
    primaryExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[-1].tree));
    (yyval.tree) = primaryExp;
}
#line 2180 "syntax.tab.c"
    break;

  case 76: /* PrimaryExp: LVal  */
#line 718 "syntax.y"
       {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::LVal;
    primaryExp->lVal = shared_ptr<LVal>((LVal* )(yyvsp[0].tree));
    (yyval.tree) = primaryExp;
}
#line 2191 "syntax.tab.c"
    break;

  case 77: /* PrimaryExp: INTCONST  */
#line 724 "syntax.y"
           {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Number;
    primaryExp->number = (yyvsp[0].ival);
    (yyval.tree) = primaryExp;
}
#line 2202 "syntax.tab.c"
    break;

  case 78: /* PrimaryExp: STRING  */
#line 730 "syntax.y"
         {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::String;
    primaryExp->str = *((yyvsp[0].sval));
    (yyval.tree) = primaryExp;
}
#line 2213 "syntax.tab.c"
    break;

  case 79: /* UnaryExp: PrimaryExp  */
#line 738 "syntax.y"
             {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::PrimaryExp;
    unaryExp->primary_exp = shared_ptr<PrimaryExp>((PrimaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2224 "syntax.tab.c"
    break;

  case 80: /* UnaryExp: IDENT LPAREN RPAREN  */
#line 744 "syntax.y"
                      {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-2].sval));
    (yyval.tree) = unaryExp;
}
#line 2235 "syntax.tab.c"
    break;

  case 81: /* UnaryExp: IDENT LPAREN FuncRParamList RPAREN  */
#line 750 "syntax.y"
                                     {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *((yyvsp[-3].sval));
    unaryExp->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[-1].tree));
    (yyval.tree) = unaryExp;
}
#line 2247 "syntax.tab.c"
    break;

  case 82: /* UnaryExp: UnaryOp UnaryExp  */
#line 757 "syntax.y"
                   {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = (yyvsp[-1].chval);
    unaryExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = unaryExp;
}
#line 2259 "syntax.tab.c"
    break;

  case 83: /* UnaryExp: '&' IDENT  */
#line 764 "syntax.y"
            {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = "&";
    unaryExp->ident = *((yyvsp[0].sval));
    (yyval.tree) = unaryExp;
}
#line 2271 "syntax.tab.c"
    break;

  case 84: /* UnaryOp: '+'  */
#line 773 "syntax.y"
      {
    (yyval.chval) = '+';
}
#line 2279 "syntax.tab.c"
    break;

  case 85: /* UnaryOp: MINUS  */
#line 776 "syntax.y"
        {
    (yyval.chval) = '-';
}
#line 2287 "syntax.tab.c"
    break;

  case 86: /* UnaryOp: '!'  */
#line 779 "syntax.y"
      {
    (yyval.chval) = '!';
}
#line 2295 "syntax.tab.c"
    break;

  case 87: /* FuncRParamList: Exp  */
#line 784 "syntax.y"
      {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    funcRParamList->exps.push_back(funcRParamList->exp);
    (yyval.tree) = funcRParamList;
}
#line 2306 "syntax.tab.c"
    break;

  case 88: /* FuncRParamList: FuncRParamList ',' Exp  */
#line 790 "syntax.y"
                         {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    funcRParamList->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )(yyvsp[-2].tree));
    funcRParamList->exps = funcRParamList->funcRParamList->exps;
    funcRParamList->exps.push_back(funcRParamList->exp);
    (yyval.tree) = funcRParamList;
}
#line 2319 "syntax.tab.c"
    break;

  case 89: /* MulExp: UnaryExp  */
#line 800 "syntax.y"
           {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::UnaryExp;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2330 "syntax.tab.c"
    break;

  case 90: /* MulExp: MulExp '*' UnaryExp  */
#line 806 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "*";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2343 "syntax.tab.c"
    break;

  case 91: /* MulExp: MulExp '/' UnaryExp  */
#line 814 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "/";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2356 "syntax.tab.c"
    break;

  case 92: /* MulExp: MulExp '%' UnaryExp  */
#line 822 "syntax.y"
                      {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[-2].tree));
    mulExp->op = "%";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )(yyvsp[0].tree));
    (yyval.tree) = mulExp;
}
#line 2369 "syntax.tab.c"
    break;

  case 93: /* AddExp: MulExp  */
#line 832 "syntax.y"
         {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::MulExp;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2380 "syntax.tab.c"
    break;

  case 94: /* AddExp: AddExp '+' MulExp  */
#line 838 "syntax.y"
                    {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "+";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2393 "syntax.tab.c"
    break;

  case 95: /* AddExp: AddExp MINUS MulExp  */
#line 846 "syntax.y"
                      {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )(yyvsp[-2].tree));
    addExp->op = "-";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )(yyvsp[0].tree));
    (yyval.tree) = addExp;
}
#line 2406 "syntax.tab.c"
    break;

  case 96: /* RelExp: Exp  */
#line 856 "syntax.y"
      {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::Exp;
    relExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));

    relExp->is_exp = true;

    (yyval.tree) = relExp;
}
#line 2420 "syntax.tab.c"
    break;

  case 97: /* RelExp: RelExp '<' Exp  */
#line 865 "syntax.y"
                 {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<";
    relExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2433 "syntax.tab.c"
    break;

  case 98: /* RelExp: RelExp '<' error  */
#line 873 "syntax.y"
                   {
    fprintf(stderr, "Error: Unknown operator\n");
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<";
    relExp->err_empty = true;
    (yyval.tree) = relExp;

}
#line 2448 "syntax.tab.c"
    break;

  case 99: /* RelExp: RelExp '>' Exp  */
#line 883 "syntax.y"
                 {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>";
    relExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2461 "syntax.tab.c"
    break;

  case 100: /* RelExp: RelExp LE Exp  */
#line 891 "syntax.y"
                {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\<=";
    relExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2474 "syntax.tab.c"
    break;

  case 101: /* RelExp: RelExp GE Exp  */
#line 899 "syntax.y"
                {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[-2].tree));
    relExp->op = "\\>=";
    relExp->exp = shared_ptr<Exp>((Exp* )(yyvsp[0].tree));
    (yyval.tree) = relExp;
}
#line 2487 "syntax.tab.c"
    break;

  case 102: /* EqExp: RelExp  */
#line 909 "syntax.y"
         {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::RelExp;
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));

    eqExp->is_rel_exp = eqExp->relExp->is_exp;

    (yyval.tree) = eqExp;
}
#line 2501 "syntax.tab.c"
    break;

  case 103: /* EqExp: EqExp EQ RelExp  */
#line 918 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "==";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));

    eqExp->is_rel_exp = eqExp->relExp->is_exp;

    (yyval.tree) = eqExp;
}
#line 2517 "syntax.tab.c"
    break;

  case 104: /* EqExp: EqExp NE RelExp  */
#line 929 "syntax.y"
                  {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[-2].tree));
    eqExp->op = "!=";

    eqExp->is_rel_exp = eqExp->relExp->is_exp;

    eqExp->relExp = shared_ptr<RelExp>((RelExp* )(yyvsp[0].tree));
    (yyval.tree) = eqExp;
}
#line 2533 "syntax.tab.c"
    break;

  case 105: /* LAndExp: EqExp  */
#line 942 "syntax.y"
        {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::EqExp;
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2544 "syntax.tab.c"
    break;

  case 106: /* LAndExp: LAndExp LAND EqExp  */
#line 948 "syntax.y"
                     {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::LAndEqExp;
    lAndExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[-2].tree));
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )(yyvsp[0].tree));
    (yyval.tree) = lAndExp;
}
#line 2556 "syntax.tab.c"
    break;

  case 107: /* LOrExp: LAndExp  */
#line 957 "syntax.y"
          {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LAndExp;
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2567 "syntax.tab.c"
    break;

  case 108: /* LOrExp: LOrExp LOR LAndExp  */
#line 963 "syntax.y"
                     {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LOrLAndExp;
    lOrExp->lOrExp = shared_ptr<LOrExp>((LOrExp* )(yyvsp[-2].tree));
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )(yyvsp[0].tree));
    (yyval.tree) = lOrExp;
}
#line 2579 "syntax.tab.c"
    break;

  case 109: /* INCLUDE_STMT: INCLUDE '<' FILE_NAME '>'  */
#line 972 "syntax.y"
                            {
    //fprintf(stderr, "Error: Include statement is not supported\n");
}
#line 2587 "syntax.tab.c"
    break;


#line 2591 "syntax.tab.c"

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

#line 976 "syntax.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main()
{
    freopen("input.c", "r", stdin);
    freopen("output.dot", "w", stdout);
    yyparse();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


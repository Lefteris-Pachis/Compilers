/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

	#include <stdio.h>
	#include "actions_handler.h"
	#include "symtable.h"
	int yyerror(const char* yaccProvidedMessage);
	int alpha_yylex(void);
	int scope_count = 0;
	char* funcname = NULL;
	
	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

/* Line 371 of yacc.c  */
#line 82 "parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     DOUBLE = 259,
     STRING = 260,
     CHAR = 261,
     ID = 262,
     L_BRACE = 263,
     R_BRACE = 264,
     L_PARENTHESIS = 265,
     R_PARENTHESIS = 266,
     L_BRACKET = 267,
     R_BRACKET = 268,
     SEMICOLON = 269,
     COMMA = 270,
     COLON = 271,
     D_COLON = 272,
     DOT = 273,
     D_DOT = 274,
     PLUS = 275,
     MINUS = 276,
     MUL = 277,
     DIV = 278,
     MOD = 279,
     PLUS_PLUS = 280,
     MINUS_MINUS = 281,
     ASSIGN = 282,
     EQ = 283,
     NOT_EQ = 284,
     LESS_THAN = 285,
     GREATER_THAN = 286,
     LESS_EQ = 287,
     GREATER_EQ = 288,
     IF = 289,
     ELSE = 290,
     AND = 291,
     NOT = 292,
     OR = 293,
     LOCAL = 294,
     TRUE = 295,
     FALSE = 296,
     WHILE = 297,
     FOR = 298,
     FUNCTION = 299,
     RETURN = 300,
     BREAK = 301,
     CONTINUE = 302,
     NIL = 303,
     UMINUS = 304
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define DOUBLE 259
#define STRING 260
#define CHAR 261
#define ID 262
#define L_BRACE 263
#define R_BRACE 264
#define L_PARENTHESIS 265
#define R_PARENTHESIS 266
#define L_BRACKET 267
#define R_BRACKET 268
#define SEMICOLON 269
#define COMMA 270
#define COLON 271
#define D_COLON 272
#define DOT 273
#define D_DOT 274
#define PLUS 275
#define MINUS 276
#define MUL 277
#define DIV 278
#define MOD 279
#define PLUS_PLUS 280
#define MINUS_MINUS 281
#define ASSIGN 282
#define EQ 283
#define NOT_EQ 284
#define LESS_THAN 285
#define GREATER_THAN 286
#define LESS_EQ 287
#define GREATER_EQ 288
#define IF 289
#define ELSE 290
#define AND 291
#define NOT 292
#define OR 293
#define LOCAL 294
#define TRUE 295
#define FALSE 296
#define WHILE 297
#define FOR 298
#define FUNCTION 299
#define RETURN 300
#define BREAK 301
#define CONTINUE 302
#define NIL 303
#define UMINUS 304



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "parser.y"

	int intVal;
	double realVal;
	char *strVal;


/* Line 387 of yacc.c  */
#line 230 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 258 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    18,
      21,    24,    26,    28,    30,    32,    36,    40,    44,    48,
      52,    56,    60,    64,    68,    72,    76,    80,    84,    86,
      90,    93,    96,    99,   102,   105,   108,   110,   114,   116,
     118,   120,   124,   126,   128,   131,   134,   136,   140,   145,
     149,   154,   159,   162,   169,   171,   173,   177,   183,   185,
     189,   190,   194,   198,   200,   204,   210,   211,   216,   219,
     220,   221,   222,   230,   231,   232,   241,   243,   245,   247,
     249,   251,   253,   256,   257,   260,   261,   267,   275,   281,
     291,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    51,    -1,    -1,    53,    14,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    46,    14,
      -1,    47,    14,    -1,    67,    -1,    70,    -1,    14,    -1,
      55,    -1,    53,    20,    53,    -1,    53,    21,    53,    -1,
      53,    22,    53,    -1,    53,    23,    53,    -1,    53,    24,
      53,    -1,    53,    28,    53,    -1,    53,    29,    53,    -1,
      53,    30,    53,    -1,    53,    31,    53,    -1,    53,    32,
      53,    -1,    53,    33,    53,    -1,    53,    36,    53,    -1,
      53,    38,    53,    -1,    54,    -1,    10,    53,    11,    -1,
      49,    53,    -1,    37,    53,    -1,    25,    57,    -1,    57,
      25,    -1,    26,    57,    -1,    57,    26,    -1,    56,    -1,
      57,    27,    53,    -1,    57,    -1,    59,    -1,    64,    -1,
      10,    70,    11,    -1,    75,    -1,     7,    -1,    39,     7,
      -1,    17,     7,    -1,    58,    -1,    57,    18,     7,    -1,
      57,    12,    53,    13,    -1,    59,    18,     7,    -1,    59,
      12,    53,    13,    -1,    59,    10,    63,    11,    -1,    57,
      60,    -1,    10,    70,    11,    10,    63,    11,    -1,    61,
      -1,    62,    -1,    10,    63,    11,    -1,    19,     7,    10,
      63,    11,    -1,    53,    -1,    63,    15,    53,    -1,    -1,
      12,    63,    13,    -1,    12,    65,    13,    -1,    66,    -1,
      65,    15,    66,    -1,     8,    53,    16,    53,     9,    -1,
      -1,     8,    68,    69,     9,    -1,    52,    69,    -1,    -1,
      -1,    -1,    44,    71,    10,    72,    76,    11,    67,    -1,
      -1,    -1,    44,     7,    73,    10,    74,    76,    11,    67,
      -1,     3,    -1,     4,    -1,     5,    -1,    48,    -1,    40,
      -1,    41,    -1,     7,    77,    -1,    -1,    15,    76,    -1,
      -1,    34,    10,    53,    11,    52,    -1,    34,    10,    53,
      11,    52,    35,    52,    -1,    42,    10,    53,    11,    52,
      -1,    43,    10,    63,    14,    53,    14,    63,    11,    52,
      -1,    45,    53,    14,    -1,    45,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    53,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    88,    89,    90,    91,    92,    93,    96,    99,   100,
     101,   102,   103,   106,   107,   108,   109,   112,   113,   114,
     115,   118,   119,   120,   123,   124,   127,   130,   133,   134,
     135,   140,   141,   144,   145,   150,   153,   153,   156,   157,
     160,   160,   160,   161,   161,   161,   164,   165,   166,   167,
     168,   169,   172,   173,   176,   177,   180,   181,   184,   187,
     190,   191
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DOUBLE", "STRING", "CHAR",
  "ID", "L_BRACE", "R_BRACE", "L_PARENTHESIS", "R_PARENTHESIS",
  "L_BRACKET", "R_BRACKET", "SEMICOLON", "COMMA", "COLON", "D_COLON",
  "DOT", "D_DOT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "PLUS_PLUS",
  "MINUS_MINUS", "ASSIGN", "EQ", "NOT_EQ", "LESS_THAN", "GREATER_THAN",
  "LESS_EQ", "GREATER_EQ", "IF", "ELSE", "AND", "NOT", "OR", "LOCAL",
  "TRUE", "FALSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK",
  "CONTINUE", "NIL", "UMINUS", "$accept", "program", "stmt", "expr",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "block", "$@1", "block_1", "funcdef", "$@2", "$@3", "$@4",
  "$@5", "const", "idlist", "idlist_1", "ifstmt", "whilestmt", "forstmt",
  "returnstmt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    58,    58,
      58,    59,    59,    59,    60,    60,    61,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    68,    67,    69,    69,
      71,    72,    70,    73,    74,    70,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    80,
      81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     1,     3,
       0,     3,     3,     1,     3,     5,     0,     4,     2,     0,
       0,     0,     7,     0,     0,     8,     1,     1,     1,     1,
       1,     1,     2,     0,     2,     0,     5,     7,     5,     9,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    76,    77,    78,    43,    66,     0,    60,    13,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,    70,
       0,     0,     0,    79,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,    69,     0,     0,     0,    58,     0,     0,    63,
      45,     0,    32,     0,    34,     0,    31,    44,     0,    60,
      73,     0,    91,     0,     9,    10,    30,     1,     2,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,    33,    35,     0,
      52,    54,    55,    60,     0,     0,    69,     0,    29,    41,
       0,    61,     0,    62,     0,     0,     0,     0,     0,     0,
      71,    90,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,    47,     0,    37,
       0,     0,    49,    68,    67,    60,     0,    59,    64,     0,
       0,     0,     0,    74,    83,    56,    48,    60,    51,    50,
       0,     0,    86,    88,     0,    83,    85,     0,     0,    53,
      65,     0,    60,     0,    83,    82,     0,    57,    87,     0,
       0,    84,    72,     0,    75,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      90,    91,    92,    47,    34,    48,    49,    35,    42,    97,
      36,    61,   144,   109,   155,    37,   157,   165,    38,    39,
      40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const yytype_int16 yypact[] =
{
     106,  -152,  -152,  -152,  -152,  -152,   154,   180,  -152,     8,
       2,     2,    -4,   237,    40,  -152,  -152,    32,    50,    85,
     220,    91,    93,  -152,   237,   103,   106,   378,  -152,  -152,
    -152,    36,  -152,    33,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,   106,     0,    97,   237,   456,    82,    89,  -152,
    -152,    68,    -2,    33,    -2,   237,  -152,  -152,   237,   237,
    -152,   105,  -152,   398,  -152,  -152,  -152,  -152,  -152,  -152,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   110,   112,  -152,  -152,   237,
    -152,  -152,  -152,   237,   237,   115,   106,   116,  -152,   114,
     437,  -152,   237,  -152,   118,   117,   293,   316,    11,   124,
    -152,  -152,    35,    35,  -152,  -152,  -152,   492,   492,   520,
     520,   520,   520,   506,   475,    29,   337,  -152,   125,   456,
      69,   358,  -152,  -152,  -152,   237,   237,   456,  -152,   114,
     106,   106,   237,  -152,   120,  -152,  -152,   237,  -152,  -152,
      70,   270,   102,  -152,   418,   120,   123,   128,    71,  -152,
    -152,   106,   237,   131,   120,  -152,   136,  -152,  -152,    78,
     136,  -152,  -152,   106,  -152,  -152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,   134,   -40,    -6,  -152,  -152,  -152,    24,  -152,    88,
    -152,  -152,  -152,   -56,  -152,  -152,    58,   -76,  -152,    67,
      -1,  -152,  -152,  -152,  -152,  -152,  -151,  -152,  -152,  -152,
    -152,  -152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      43,    46,    96,   108,   163,    44,    55,    56,    83,     4,
      84,    98,    51,   171,    63,    50,    85,    86,    66,     9,
      70,    71,    72,    73,    74,   142,   102,   125,    75,    76,
      77,    78,    79,    80,    52,    54,    81,   130,    82,   100,
     145,    14,    58,    93,   102,    94,    83,    57,    84,   106,
     105,    95,   107,    46,    85,    86,    96,    72,    73,    74,
      59,    87,    88,    89,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    46,   126,   150,
     148,   159,   167,   129,   102,   102,   102,    46,   131,   173,
     172,   158,    60,   102,   174,   101,   137,   102,    53,    53,
     152,   153,   103,    67,   104,    64,   169,    65,    99,     1,
       2,     3,    19,     4,     5,   110,     6,   127,     7,   128,
       8,   168,   132,     9,   135,   134,    45,   156,   139,    46,
     151,    10,    11,   175,   143,   147,   154,   161,   164,   166,
      12,    46,   170,    13,     5,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    46,     1,     2,     3,
      68,     4,   138,   133,     6,     0,     7,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     1,     2,     3,     0,     4,    45,     0,
       6,    13,     7,    14,    15,    16,     0,     9,    19,     0,
       0,     0,    23,    24,     0,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    14,
      15,    16,     0,     1,     2,     3,     0,     4,    23,    24,
       6,     0,     7,     0,    62,     0,     0,     9,     0,     0,
       1,     2,     3,     0,     4,    10,    11,     6,     0,     7,
       0,     0,     0,     0,     9,     0,     0,    13,     0,    14,
      15,    16,    10,    11,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,    13,     0,    14,    15,    16,   160,
       0,     0,     0,     0,     0,    23,    24,     0,     0,     0,
      70,    71,    72,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,   140,     0,    81,     0,    82,     0,
       0,     0,     0,    70,    71,    72,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,   141,     0,    81,
       0,    82,     0,     0,     0,     0,    70,    71,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
     146,     0,    81,     0,    82,     0,     0,    70,    71,    72,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,   149,     0,    81,     0,    82,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    69,     0,    81,     0,    82,     0,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,   111,     0,    81,     0,    82,     0,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,   162,     0,    81,     0,    82,     0,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,     0,   136,    81,     0,    82,    70,    71,    72,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,     0,     0,    81,     0,    82,    70,    71,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
       0,     0,    81,     0,    82,    70,    71,    72,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    70,    71,    72,    73,    74,     0,     0,     0,
      -1,    -1,    77,    78,    79,    80,    70,    71,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
      -1,    -1,    -1,    -1
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
       6,     7,    42,    59,   155,     6,    10,    13,    10,     7,
      12,    11,    10,   164,    20,     7,    18,    19,    24,    17,
      20,    21,    22,    23,    24,    14,    15,    83,    28,    29,
      30,    31,    32,    33,    10,    11,    36,    93,    38,    45,
      11,    39,    10,    10,    15,    12,    10,     7,    12,    55,
      51,    18,    58,    59,    18,    19,    96,    22,    23,    24,
      10,    25,    26,    27,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   135,
      11,    11,    11,    89,    15,    15,    15,    93,    94,    11,
     166,   147,     7,    15,   170,    13,   102,    15,    10,    11,
     140,   141,    13,     0,    15,    14,   162,    14,    11,     3,
       4,     5,    44,     7,     8,    10,    10,     7,    12,     7,
      14,   161,     7,    17,    10,     9,     8,     7,    11,   135,
     136,    25,    26,   173,    10,    10,   142,    35,    15,    11,
      34,   147,    11,    37,     8,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   162,     3,     4,     5,
      26,     7,   104,    96,    10,    -1,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      10,    37,    12,    39,    40,    41,    -1,    17,    44,    -1,
      -1,    -1,    48,    49,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      40,    41,    -1,     3,     4,     5,    -1,     7,    48,    49,
      10,    -1,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,
       3,     4,     5,    -1,     7,    25,    26,    10,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    37,    -1,    39,
      40,    41,    25,    26,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,     9,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    11,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    11,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      13,    -1,    36,    -1,    38,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    13,    -1,    36,    -1,    38,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    14,    -1,    36,    -1,    38,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    14,    -1,    36,    -1,    38,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    14,    -1,    36,    -1,    38,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    16,    36,    -1,    38,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    -1,    38,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    38,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    10,    12,    14,    17,
      25,    26,    34,    37,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    64,    67,    70,    75,    78,    79,
      80,    81,    68,    53,    70,     8,    53,    63,    65,    66,
       7,    10,    57,    59,    57,    10,    53,     7,    10,    10,
       7,    71,    14,    53,    14,    14,    53,     0,    51,    14,
      20,    21,    22,    23,    24,    28,    29,    30,    31,    32,
      33,    36,    38,    10,    12,    18,    19,    25,    26,    27,
      60,    61,    62,    10,    12,    18,    52,    69,    11,    11,
      53,    13,    15,    13,    15,    70,    53,    53,    63,    73,
      10,    14,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    63,    53,     7,     7,    53,
      63,    53,     7,    69,     9,    10,    16,    53,    66,    11,
      11,    11,    14,    10,    72,    11,    13,    10,    11,    13,
      63,    53,    52,    52,    53,    74,     7,    76,    63,    11,
       9,    35,    14,    76,    15,    77,    11,    11,    52,    63,
      11,    76,    67,    11,    67,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1787 of yacc.c  */
#line 57 "parser.y"
    { Handle_stmt_expr_semicolon(yylineno); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 58 "parser.y"
    { Handle_stmt_ifstmt(yylineno); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 59 "parser.y"
    { Handle_stmt_whilestmt(yylineno); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 60 "parser.y"
    { Handle_stmt_forstmt(yylineno); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 61 "parser.y"
    { Handle_stmt_returnstmt(yylineno); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 62 "parser.y"
    { Handle_stmt_break_semicolon(yylineno); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 63 "parser.y"
    { Handle_stmt_continue_semicolon(yylineno); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 64 "parser.y"
    { Handle_stmt_block(yylineno); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 65 "parser.y"
    { Handle_stmt_funcdef(yylineno); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 66 "parser.y"
    { Handle_stmt_semicolon(yylineno); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 69 "parser.y"
    { Handle_expr_assignexpr(yylineno); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 70 "parser.y"
    { Handle_expr_expr_plus_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 71 "parser.y"
    { Handle_expr_expr_minus_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 72 "parser.y"
    { Handle_expr_expr_mul_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 73 "parser.y"
    { Handle_expr_expr_div_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 74 "parser.y"
    { Handle_expr_expr_mod_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 75 "parser.y"
    { Handle_expr_expr_eq_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 76 "parser.y"
    { Handle_expr_expr_not_eq_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 77 "parser.y"
    { Handle_expr_expr_less_than_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 78 "parser.y"
    { Handle_expr_expr_greater_than_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 79 "parser.y"
    { Handle_expr_expr_less_eq_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 80 "parser.y"
    { Handle_expr_expr_greater_eq_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 81 "parser.y"
    { Handle_expr_expr_and_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 82 "parser.y"
    { Handle_expr_expr_or_expr((yyvsp[(1) - (3)].intVal),(yyvsp[(3) - (3)].intVal),yylineno); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 83 "parser.y"
    { Handle_expr_term(yylineno); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 86 "parser.y"
    { Handle_term_l_parenthesis_expr_r_parenthesis(yylineno); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 87 "parser.y"
    { Handle_term_uminus_expr(yylineno); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 88 "parser.y"
    { Handle_term_not_expr(yylineno); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 89 "parser.y"
    { Handle_term_plus_plus_lvalue(yylineno); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 90 "parser.y"
    { Handle_term_lvalue_plus_plus(yylineno); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 91 "parser.y"
    { Handle_term_minus_minus_lvalue(yylineno); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 92 "parser.y"
    { Handle_term_lvalue_minus_minus(yylineno); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 93 "parser.y"
    { Handle_term_primary(yylineno); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 96 "parser.y"
    { Handle_assignexpr_lvalue_assign_expr(yylineno); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 99 "parser.y"
    { Handle_primary_lvalue(yylineno); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 100 "parser.y"
    { Handle_primary_call(yylineno); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 101 "parser.y"
    { Handle_primary_objectdef(yylineno); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 102 "parser.y"
    { Handle_primary_l_parenthesis_funcdef_r_parenthesis(yylineno); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 103 "parser.y"
    { Handle_primary_const(yylineno); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { Handle_lvalue_id((yyvsp[(1) - (1)].strVal),scope_count,yylineno,0); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    { Handle_lvalue_local_id((yyvsp[(2) - (2)].strVal),scope_count,yylineno); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 108 "parser.y"
    { Handle_lvalue_d_colon_id((yyvsp[(2) - (2)].strVal),yylineno); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 109 "parser.y"
    { Handle_lvalue_member(yylineno); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 112 "parser.y"
    { Handle_member_lvalue_dot_id(yylineno); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 113 "parser.y"
    { Handle_member_lvalue_l_bracket_expr_r_bracket(yylineno); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    { Handle_member_call_dot_id(yylineno); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 115 "parser.y"
    { Handle_member_call_l_bracket_expr_r_bracket(yylineno); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 118 "parser.y"
    { Handle_call_call_l_parenthesis_elist_r_parenthesis(yylineno); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 119 "parser.y"
    { Handle_call_lvalue_callsuffix(yylineno); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    { Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(yylineno); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 123 "parser.y"
    { Handle_callsuffix_normcall(yylineno); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 124 "parser.y"
    { Handle_callsuffix_methodcall(yylineno); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 127 "parser.y"
    { Handle_normcall_l_parenthesis_elist_r_parenthesis(yylineno); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 130 "parser.y"
    { Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(yylineno); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 133 "parser.y"
    { Handle_elist_expr(yylineno); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 134 "parser.y"
    { Handle_elist_elist_comma_expr(yylineno); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    { Handle_objectdef_l_bracket_elist_r_bracket(yylineno); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 141 "parser.y"
    { Handle_objectdef_l_bracket_indexed_r_bracket(yylineno); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 144 "parser.y"
    { Handle_indexed_indexedelem(yylineno); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 145 "parser.y"
    { Handle_indexed_indexed_comma_indexedelem(yylineno); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 150 "parser.y"
    { Handle_indexedelem_l_brace_expr_colon_expr_r_brace(yylineno); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    {scope_count++;}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    { scope_count--; Handle_block_l_brace_block_1_r_brace(0,0,yylineno); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 156 "parser.y"
    { Handle_block_1_stmt_block_1(yylineno); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 157 "parser.y"
    {  }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    {Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block( "NO_ID" ,scope_count, yylineno);}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    {scope_count++;}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    { scope_count--; }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    {funcname = (yyvsp[(2) - (2)].strVal); Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block(funcname, scope_count, yylineno);}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    { scope_count++;}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    { scope_count--; }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 164 "parser.y"
    { Handle_const_integer(yylineno); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    { Handle_const_double(yylineno); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 166 "parser.y"
    { Handle_const_string(yylineno); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 167 "parser.y"
    { Handle_const_nil(yylineno); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 168 "parser.y"
    { Handle_const_true(yylineno); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 169 "parser.y"
    { Handle_const_false(yylineno); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 172 "parser.y"
    { Handle_idlist_id_idlist_1((yyvsp[(1) - (2)].strVal),funcname,scope_count,yylineno); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 173 "parser.y"
    {  }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    { Handle_idlist_1_comma_idlist(yylineno); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    {  }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 180 "parser.y"
    { Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 181 "parser.y"
    { Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(yylineno); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    { Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 187 "parser.y"
    { Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(yylineno); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    { Handle_returnstmt_return_expr_semicolon(yylineno); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    { Handle_returnstmt_return_semicolon(yylineno); }
    break;


/* Line 1787 of yacc.c  */
#line 2207 "parser.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 194 "parser.y"




int yyerror(const char* yaccProvidedMessage){
	printf("%s: at line %d, before token: %s\n",yaccProvidedMessage,yylineno,yytext);
	printf("INPUT NOT VALID\n");
}

int main(int argc, char** argv){
	if(argc > 1){
		if(!(yyin = fopen(argv[1], "r"))){
			printf("Cannot read file: %s\n",argv[1]);
			return 1;
		}
	}
	else
		yyin = stdin;
	mytable = SymTable_new();

	yyparse();


	//Insert_Var(mytable, "giwrgadakis", "pro" , 0, 1);
	//Insert_Func(mytable, "giwrgadakis", "pro","x,y" , 0, 1);

	Print_Hash(mytable);
	return 0;
}
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
	#include "quads.h"
	int yyerror(const char* yaccProvidedMessage);
	int alpha_yylex(void);
	int scope_count = 0;
	int function_counter = 0;
	int state = 0;
	int tmp_state = 0;
	int count_id = 0;
	int prev_id_state = 0;
	int error = 0;
	int flag_emit = 0;
	int for_flag = 0;
	int total_expr;
	int loopcounter = 0;
	char* id_val;
	char* funcName = NULL;
	label_list* break_list;
	label_list* cont_list;
	int loop_index = 0;
	int max_loop_index = 0;
	int relop = 0;
	unsigned start = 0;
	unsigned end = 0;


	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

/* Line 371 of yacc.c  */
#line 102 "parser.c"

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
#line 37 "parser.y"

	int intVal;
	double realVal;
	char *strVal;
	struct symbol *Symbol;
	struct expr *exprNode;
	unsigned uVal;
	struct forprefix *forVal;
	struct statement *stmtVal;
	struct calls *CallsVar;
	struct indexed *indexedVar;


/* Line 387 of yacc.c  */
#line 257 "parser.c"
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
#line 285 "parser.c"

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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

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
       0,     0,     3,     4,     8,     9,    12,    15,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    42,
      46,    50,    54,    58,    62,    66,    70,    74,    78,    82,
      83,    89,    90,    96,    98,   102,   105,   108,   111,   114,
     117,   120,   122,   126,   128,   130,   132,   136,   138,   140,
     143,   146,   148,   152,   157,   161,   166,   171,   174,   181,
     183,   185,   189,   195,   197,   201,   202,   203,   208,   209,
     214,   216,   220,   226,   227,   232,   235,   236,   238,   239,
     242,   243,   248,   249,   250,   254,   258,   260,   262,   264,
     266,   268,   270,   273,   274,   277,   278,   283,   285,   288,
     293,   294,   295,   299,   301,   305,   309,   310,   311,   312,
     321,   322,   331,   335
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    55,    52,    51,    -1,    -1,    46,
      14,    -1,    47,    14,    -1,    56,    14,    -1,    90,    -1,
      96,    -1,   101,    -1,   103,    -1,    53,    -1,    54,    -1,
      74,    -1,    84,    -1,    14,    -1,    60,    -1,    56,    20,
      56,    -1,    56,    21,    56,    -1,    56,    22,    56,    -1,
      56,    23,    56,    -1,    56,    24,    56,    -1,    56,    28,
      56,    -1,    56,    29,    56,    -1,    56,    30,    56,    -1,
      56,    31,    56,    -1,    56,    32,    56,    -1,    56,    33,
      56,    -1,    -1,    56,    36,    57,    98,    56,    -1,    -1,
      56,    38,    58,    98,    56,    -1,    59,    -1,    10,    56,
      11,    -1,    21,    56,    -1,    37,    56,    -1,    25,    62,
      -1,    62,    25,    -1,    26,    62,    -1,    62,    26,    -1,
      61,    -1,    62,    27,    56,    -1,    62,    -1,    64,    -1,
      69,    -1,    10,    84,    11,    -1,    85,    -1,     7,    -1,
      39,     7,    -1,    17,     7,    -1,    63,    -1,    62,    18,
       7,    -1,    62,    12,    56,    13,    -1,    64,    18,     7,
      -1,    64,    12,    56,    13,    -1,    64,    10,    68,    11,
      -1,    62,    65,    -1,    10,    84,    11,    10,    68,    11,
      -1,    66,    -1,    67,    -1,    10,    68,    11,    -1,    19,
       7,    10,    68,    11,    -1,    56,    -1,    68,    15,    56,
      -1,    -1,    -1,    12,    70,    68,    13,    -1,    -1,    12,
      71,    72,    13,    -1,    73,    -1,    72,    15,    73,    -1,
       8,    56,    16,    56,     9,    -1,    -1,     8,    75,    76,
       9,    -1,    55,    76,    -1,    -1,     7,    -1,    -1,    44,
      77,    -1,    -1,    10,    80,    86,    11,    -1,    -1,    -1,
      81,    74,    82,    -1,    78,    79,    83,    -1,     3,    -1,
       4,    -1,     5,    -1,    48,    -1,    40,    -1,    41,    -1,
       7,    87,    -1,    -1,    15,    86,    -1,    -1,    34,    10,
      56,    11,    -1,    35,    -1,    88,    55,    -1,    88,    55,
      89,    55,    -1,    -1,    -1,    91,    55,    92,    -1,    42,
      -1,    10,    56,    11,    -1,    94,    95,    93,    -1,    -1,
      -1,    -1,    43,   100,    10,    68,    14,    98,    56,    14,
      -1,    -1,    99,    97,    68,    11,   102,    97,    93,    97,
      -1,    45,    56,    14,    -1,    45,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   118,   119,   122,   132,   143,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     171,   177,   177,   182,   186,   195,   201,   204,   217,   232,
     246,   262,   266,   305,   309,   310,   311,   316,   321,   335,
     344,   352,   355,   362,   369,   370,   373,   381,   394,   406,
     407,   410,   418,   426,   439,   451,   454,   454,   470,   470,
     488,   489,   492,   507,   507,   513,   514,   518,   519,   522,
     544,   544,   547,   548,   550,   553,   563,   566,   569,   572,
     575,   578,   583,   587,   590,   591,   594,   604,   607,   608,
     611,   612,   613,   615,   618,   630,   640,   641,   643,   643,
     658,   658,   665,   666
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
  "CONTINUE", "NIL", "UMINUS", "$accept", "program", "$@1", "break",
  "continue", "stmt", "expr", "$@2", "$@3", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "objectdef", "$@4", "$@5", "indexed",
  "indexedelem", "block", "$@6", "block_1", "funcname", "funcprefix",
  "funcargs", "$@7", "funcblockstart", "funcblockend", "funcbody",
  "funcdef", "const", "idlist", "idlist_1", "ifprefix", "elseprefix",
  "ifstmt", "loopstart", "loopend", "loopstmt", "whilestart", "whilecond",
  "whilestmt", "N", "M", "forprefix", "$@8", "forstmt", "$@9",
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
       0,    50,    52,    51,    51,    53,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      56,    58,    56,    56,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    67,    68,    68,    68,    70,    69,    71,    69,
      72,    72,    73,    75,    74,    76,    76,    77,    77,    78,
      80,    79,    81,    82,    83,    84,    85,    85,    85,    85,
      85,    85,    86,    86,    87,    87,    88,    89,    90,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   100,    99,
     102,   101,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       5,     0,     5,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     6,     1,
       1,     3,     5,     1,     3,     0,     0,     4,     0,     4,
       1,     3,     5,     0,     4,     2,     0,     1,     0,     2,
       0,     4,     0,     0,     3,     3,     1,     1,     1,     1,
       1,     1,     2,     0,     2,     0,     4,     1,     2,     4,
       0,     0,     3,     1,     3,     3,     0,     0,     0,     8,
       0,     8,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    86,    87,    88,    48,    73,     0,    66,    16,     0,
       0,     0,     0,     0,     0,     0,    90,    91,   103,   108,
      78,     0,     0,     0,    89,     0,    12,    13,     2,     0,
      33,    17,    41,    43,    51,    44,    45,    14,     0,    15,
      47,     0,     8,     0,     9,   106,    10,    11,    76,     0,
       0,    65,     0,    50,    35,     0,    37,     0,    39,     0,
      36,    49,     0,    77,    79,   113,     0,     5,     6,     1,
       4,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    31,    65,     0,     0,     0,    38,
      40,     0,    57,    59,    60,    65,     0,     0,    80,    82,
      98,     0,   100,    65,    76,     0,    34,    46,    63,     0,
       0,     0,    70,     0,     0,    65,   112,     3,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   107,
     107,     0,     0,    52,     0,    42,     0,     0,    54,    93,
       0,    85,    97,     0,     0,     0,   105,     0,    75,    74,
      65,    67,     0,     0,    69,     0,     0,    96,     0,     0,
       0,    61,    53,    65,    56,    55,    95,     0,    83,    99,
     104,   101,   110,     0,    64,     0,    71,   107,    30,    32,
       0,    93,    92,    81,    84,   102,   106,    58,     0,     0,
      62,    94,   100,    72,     0,   106,   109,   111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    70,    26,    27,    28,    29,   129,   130,    30,
      31,    32,    33,    34,    35,    92,    93,    94,   109,    36,
      51,    52,   111,   112,    37,    48,   105,    64,    38,    99,
     139,   140,   184,   141,    39,    40,   167,   182,    41,   143,
      42,   145,   185,   146,    43,   102,    44,   103,   159,    45,
      62,    46,   186,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -170
static const yytype_int16 yypact[] =
{
     156,  -170,  -170,  -170,  -170,  -170,    15,     2,  -170,     0,
     202,    -1,    -1,    27,   202,    37,  -170,  -170,  -170,  -170,
      44,    89,    72,    73,  -170,    88,  -170,  -170,  -170,   355,
    -170,  -170,  -170,   113,  -170,    90,  -170,  -170,    95,  -170,
    -170,   156,  -170,    97,  -170,  -170,  -170,  -170,   156,   247,
      87,   202,   103,  -170,  -170,    75,    -7,    90,    -7,   202,
    -170,  -170,   102,  -170,  -170,  -170,   375,  -170,  -170,  -170,
     156,  -170,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,  -170,  -170,   202,   202,   106,   110,  -170,
    -170,   202,  -170,  -170,  -170,   202,   202,   114,  -170,  -170,
      85,   202,  -170,   202,   156,   115,  -170,   112,   433,    68,
     202,    69,  -170,   116,   270,   202,  -170,  -170,    38,    38,
    -170,  -170,  -170,   469,   469,   497,   497,   497,   497,  -170,
    -170,    13,   314,  -170,   123,   433,    18,   335,  -170,   127,
     128,  -170,  -170,   156,   293,   156,  -170,    19,  -170,  -170,
     202,  -170,   202,   414,  -170,   103,   112,  -170,    33,   202,
     202,  -170,  -170,   202,  -170,  -170,   120,   130,  -170,  -170,
    -170,  -170,  -170,    24,   433,   202,  -170,  -170,   483,   452,
      31,   127,  -170,  -170,  -170,  -170,  -170,  -170,   224,   202,
    -170,  -170,  -170,  -170,   395,  -170,  -170,  -170
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,    77,  -170,  -170,  -170,   -27,    -6,  -170,  -170,  -170,
    -170,  -170,    46,  -170,    53,  -170,  -170,  -170,   -72,  -170,
    -170,  -170,  -170,   -13,     3,  -170,    41,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,    -5,  -170,   -33,  -170,  -170,  -170,
    -170,  -170,  -170,   -43,  -170,  -170,  -170,  -169,  -128,  -170,
    -170,  -170,  -170,  -170
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -69
static const yytype_int16 yytable[] =
{
      49,    50,   160,    85,    54,    86,     4,    53,    60,    55,
     -68,    87,    88,   131,   100,    66,     9,   192,     1,     2,
       3,   104,     4,   136,   161,     6,   197,     7,   152,   164,
     172,   147,     9,   152,   152,   187,    10,    59,    15,   152,
      11,    12,   190,   158,    61,   108,   152,   177,   152,   189,
     113,    63,    14,   114,    15,    16,    17,    56,    58,    20,
      74,    75,    76,    24,    57,    57,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   104,   173,   108,
     132,   151,   154,   152,   155,   135,    67,    68,    69,   108,
     137,   180,     1,     2,     3,   144,     4,   108,   107,     6,
      95,     7,    96,    65,   153,    98,     9,   101,    97,   108,
      10,   110,   115,   133,    11,    12,   169,   134,   171,    20,
     142,   138,   150,    85,   149,    86,    14,   156,    15,    16,
      17,    87,    88,   163,   166,   181,     5,    24,    89,    90,
      91,   183,   176,   168,   108,   148,   174,   117,   191,   195,
       0,     0,     0,   178,   179,     0,     0,   108,     0,     1,
       2,     3,     0,     4,     5,     0,     6,     0,     7,   188,
       8,     0,     0,     9,     0,     0,     0,    10,     0,     0,
       0,    11,    12,   194,     0,     0,     0,     0,     0,     0,
      13,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     1,     2,     3,     0,     4,
       0,     0,     6,     0,     7,     0,     0,     0,     0,     9,
       0,     0,     0,    10,     0,     0,     0,    11,    12,     0,
       0,     0,     0,   193,     0,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    72,    73,    74,    75,    76,     0,
      24,     0,    77,    78,    79,    80,    81,    82,   106,     0,
      83,     0,    84,     0,     0,     0,     0,    72,    73,    74,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,   157,     0,    83,     0,    84,     0,     0,     0,     0,
      72,    73,    74,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,   170,     0,    83,     0,    84,     0,
       0,     0,     0,    72,    73,    74,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,   162,     0,    83,
       0,    84,     0,     0,    72,    73,    74,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,   165,     0,
      83,     0,    84,     0,     0,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    71,
       0,    83,     0,    84,     0,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,   116,
       0,    83,     0,    84,     0,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,   196,
       0,    83,     0,    84,     0,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,     0,
     175,    83,     0,    84,    72,    73,    74,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,     0,     0,
      83,     0,    84,    72,    73,    74,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,     0,     0,    83,
       0,    84,    72,    73,    74,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,     0,     0,    83,    72,
      73,    74,    75,    76,     0,     0,     0,   -69,   -69,    79,
      80,    81,    82,    72,    73,    74,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,   -69,   -69,   -69,
     -69
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-69)))

static const yytype_int16 yycheck[] =
{
       6,     6,   130,    10,    10,    12,     7,     7,    14,    10,
       8,    18,    19,    85,    41,    21,    17,   186,     3,     4,
       5,    48,     7,    95,    11,    10,   195,    12,    15,    11,
      11,   103,    17,    15,    15,    11,    21,    10,    39,    15,
      25,    26,    11,   115,     7,    51,    15,    14,    15,   177,
      55,     7,    37,    59,    39,    40,    41,    11,    12,    44,
      22,    23,    24,    48,    11,    12,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   104,   150,    85,
      86,    13,    13,    15,    15,    91,    14,    14,     0,    95,
      96,   163,     3,     4,     5,   101,     7,   103,    11,    10,
      10,    12,    12,    14,   110,    10,    17,    10,    18,   115,
      21,     8,    10,     7,    25,    26,   143,     7,   145,    44,
      35,     7,    10,    10,     9,    12,    37,    11,    39,    40,
      41,    18,    19,    10,     7,    15,     8,    48,    25,    26,
      27,    11,   155,   140,   150,   104,   152,    70,   181,   192,
      -1,    -1,    -1,   159,   160,    -1,    -1,   163,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    10,    -1,    12,   175,
      14,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    25,    26,   189,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    20,    21,    22,    23,    24,    -1,
      48,    -1,    28,    29,    30,    31,    32,    33,    11,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    11,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    11,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    13,    -1,    36,
      -1,    38,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    13,    -1,
      36,    -1,    38,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    14,
      -1,    36,    -1,    38,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    14,
      -1,    36,    -1,    38,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    14,
      -1,    36,    -1,    38,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      16,    36,    -1,    38,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    -1,    38,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      -1,    38,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    10,    12,    14,    17,
      21,    25,    26,    34,    37,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    51,    53,    54,    55,    56,
      59,    60,    61,    62,    63,    64,    69,    74,    78,    84,
      85,    88,    90,    94,    96,    99,   101,   103,    75,    56,
      84,    70,    71,     7,    56,    10,    62,    64,    62,    10,
      56,     7,   100,     7,    77,    14,    56,    14,    14,     0,
      52,    14,    20,    21,    22,    23,    24,    28,    29,    30,
      31,    32,    33,    36,    38,    10,    12,    18,    19,    25,
      26,    27,    65,    66,    67,    10,    12,    18,    10,    79,
      55,    10,    95,    97,    55,    76,    11,    11,    56,    68,
       8,    72,    73,    84,    56,    10,    14,    51,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    68,    56,     7,     7,    56,    68,    56,     7,    80,
      81,    83,    35,    89,    56,    91,    93,    68,    76,     9,
      10,    13,    15,    56,    13,    15,    11,    11,    68,    98,
      98,    11,    13,    10,    11,    13,     7,    86,    74,    55,
      11,    55,    11,    68,    56,    16,    73,    14,    56,    56,
      68,    15,    87,    11,    82,    92,   102,    11,    56,    98,
      11,    86,    97,     9,    56,    93,    14,    97
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
        case 2:
/* Line 1787 of yacc.c  */
#line 118 "parser.y"
    {loop_index = max_loop_index;}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 122 "parser.y"
    { 	
										if(loopcounter > 0){
											break_list = label_list_insert(break_list,next_quad_label(),loop_index);
											emit_jump(jump, 0, 0, 0, 0); 
											Handle_stmt_break_semicolon(yylineno);
										}else{
											printf("Error at line: %d break is not in a loop\n",yylineno);
											error = 1;
										} 
									}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 132 "parser.y"
    { 	
										if(loopcounter > 0){
											cont_list = label_list_insert(cont_list,next_quad_label(),loop_index); 
											emit_jump(jump, 0, 0, 0, 0); 
											Handle_stmt_continue_semicolon(yylineno); 
										}else{
											printf("Error at line: %d continue is not in a loop\n",yylineno);
											error = 1;
										}
									}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 143 "parser.y"
    { 	Handle_stmt_expr_semicolon(yylineno);
										if(Handle_relop(relop,(yyvsp[(1) - (2)].exprNode))!=NULL)
											relop = 0;
										prev_id_state=0;
									}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 148 "parser.y"
    { Handle_stmt_ifstmt(yylineno); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 149 "parser.y"
    { Handle_stmt_whilestmt(yylineno); Scan_jumps(0,start,end);}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 150 "parser.y"
    { Handle_stmt_forstmt(yylineno); Scan_jumps(1,start,end);}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 151 "parser.y"
    { Handle_stmt_returnstmt(yylineno); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 152 "parser.y"
    {(yyval.stmtVal) = (yyvsp[(1) - (1)].stmtVal);}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    {(yyval.stmtVal) = (yyvsp[(1) - (1)].stmtVal);}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 154 "parser.y"
    { Handle_stmt_block(yylineno); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 155 "parser.y"
    { Handle_stmt_funcdef(yylineno); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 156 "parser.y"
    { Handle_stmt_semicolon(yylineno); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 159 "parser.y"
    { (yyval.exprNode)=(yyvsp[(1) - (1)].exprNode); Handle_expr_assignexpr(yylineno); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_plus_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode), yylineno); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_minus_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode), yylineno); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 162 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_mul_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode), yylineno); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 163 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_div_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode), yylineno); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 164 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_mod_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode), yylineno); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_eq_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 166 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_not_eq_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 167 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_less_than_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 168 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_greater_than_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 169 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_less_eq_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 170 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_greater_eq_expr((yyvsp[(1) - (3)].exprNode), (yyvsp[(3) - (3)].exprNode),yylineno); relop = 1;}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 171 "parser.y"
    {					if((yyvsp[(1) - (2)].exprNode)->type == var_e){
											emit_jump(if_eq,(yyvsp[(1) - (2)].exprNode),newexpr_constbool('1'),(expr*)0,next_quad_label()+2);
											(yyvsp[(1) - (2)].exprNode)->false_list = label_list_insert((yyvsp[(1) - (2)].exprNode)->false_list,next_quad_label(),0);
											emit_jump(jump,(expr*)0, (expr*)0, (expr*)0,0);
										}	
				}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_and_expr((yyvsp[(1) - (5)].exprNode), (yyvsp[(5) - (5)].exprNode),(yyvsp[(4) - (5)].uVal),yylineno); relop = 1;}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    {						if((yyvsp[(1) - (2)].exprNode)->type == var_e){
											(yyvsp[(1) - (2)].exprNode)->true_list = label_list_insert((yyvsp[(1) - (2)].exprNode)->true_list,next_quad_label(),0);
											emit_jump(if_eq,(yyvsp[(1) - (2)].exprNode),newexpr_constbool('1'),(expr*)0,0);
										}	
				}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 181 "parser.y"
    { (yyval.exprNode) = Handle_expr_expr_or_expr((yyvsp[(1) - (5)].exprNode), (yyvsp[(5) - (5)].exprNode),(yyvsp[(4) - (5)].uVal),yylineno); relop = 1;}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    { (yyval.exprNode)=(yyvsp[(1) - (1)].exprNode); Handle_expr_term(yylineno); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    { 
												expr *e = Handle_relop(relop,(yyvsp[(2) - (3)].exprNode));
												if(e!=NULL)
													relop = 0;
												else
													e = (yyvsp[(2) - (3)].exprNode);
												(yyval.exprNode) = e;
												Handle_term_l_parenthesis_expr_r_parenthesis(yylineno); 
											}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { 	Handle_term_uminus_expr(yylineno); 
												checkuminus((yyvsp[(2) - (2)].exprNode));
												(yyval.exprNode) = newexpr(arithexpr_e);
												(yyval.exprNode)->sym = new_temp();
												emit(uminus,(yyvsp[(2) - (2)].exprNode),0,(yyval.exprNode));
											}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 201 "parser.y"
    { 	(yyval.exprNode) = Handle_term_not_expr((yyvsp[(2) - (2)].exprNode),yylineno); 
												relop = 1;
											}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 204 "parser.y"
    { state = Handle_term_plus_plus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } 
												if((yyvsp[(2) - (2)].exprNode)->type == tableitem_e){
													(yyval.exprNode) = emit_iftableitem((yyvsp[(2) - (2)].exprNode));
													emit(add,(yyval.exprNode),newexpr_constint(1),(yyval.exprNode));
													emit(tablesetelem,(yyvsp[(2) - (2)].exprNode),(yyvsp[(2) - (2)].exprNode)->index,(yyval.exprNode));
												}
												else{
													emit(add,(yyvsp[(2) - (2)].exprNode),newexpr_constint(1),(yyvsp[(2) - (2)].exprNode));
													(yyval.exprNode) = newexpr(arithexpr_e);
													(yyval.exprNode)->sym = new_temp();
													emit(assign,(yyvsp[(2) - (2)].exprNode),0,(yyval.exprNode));
												}
											}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 217 "parser.y"
    { state = Handle_term_lvalue_plus_plus(yylineno,id_val); if(state == -1) { error = 1; }
												(yyval.exprNode) = newexpr(var_e);
												(yyval.exprNode)->sym = new_temp();
												if((yyvsp[(1) - (2)].exprNode)->type == tableitem_e){
													expr* val = emit_iftableitem((yyvsp[(1) - (2)].exprNode));
													emit(assign,val,0,(yyval.exprNode));
													emit(add,val,newexpr_constint(1),val);
													emit(tablesetelem,(yyvsp[(1) - (2)].exprNode),(yyvsp[(1) - (2)].exprNode)->index,val);

												}
												else{
													emit(assign,(yyvsp[(1) - (2)].exprNode),0,(yyval.exprNode));
													emit(add,(yyvsp[(1) - (2)].exprNode),newexpr_constint(1),(yyvsp[(1) - (2)].exprNode));
												}
											}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    { state = Handle_term_minus_minus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } 
												if((yyvsp[(2) - (2)].exprNode)->type == tableitem_e){
													(yyval.exprNode) = emit_iftableitem((yyvsp[(2) - (2)].exprNode));
													emit(sub,(yyval.exprNode),newexpr_constint(1),(yyval.exprNode));
													emit(tablesetelem,(yyvsp[(2) - (2)].exprNode),(yyvsp[(2) - (2)].exprNode)->index,(yyval.exprNode));

												}
												else{
													emit(sub,(yyvsp[(2) - (2)].exprNode),newexpr_constint(1),(yyvsp[(2) - (2)].exprNode));
													(yyval.exprNode) = newexpr(arithexpr_e);
													(yyval.exprNode)->sym = new_temp();
													emit(assign,(yyvsp[(2) - (2)].exprNode),0,(yyval.exprNode));
												}
											}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 246 "parser.y"
    { state = Handle_term_lvalue_minus_minus(yylineno,id_val); if(state == -1) { error = 1; } 
												(yyval.exprNode) = newexpr(var_e);
												(yyval.exprNode)->sym = new_temp();														

												if((yyvsp[(1) - (2)].exprNode)->type == tableitem_e){
													expr* val = emit_iftableitem((yyvsp[(1) - (2)].exprNode));
													emit(assign,val,0,(yyval.exprNode));
													emit(sub,val,newexpr_constint(1),val);
													emit(tablesetelem,(yyvsp[(1) - (2)].exprNode),(yyvsp[(1) - (2)].exprNode)->index,val);

												}
												else{
													emit(assign,(yyvsp[(1) - (2)].exprNode),0,(yyval.exprNode));
													emit(sub,(yyvsp[(1) - (2)].exprNode),newexpr_constint(1),(yyvsp[(1) - (2)].exprNode));
												}
											}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    { (yyval.exprNode) = (yyvsp[(1) - (1)].exprNode); Handle_term_primary(yylineno); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    {
										if(count_id > 1)
											if(prev_id_state == 0 && (tmp_state == -2 || tmp_state == -3 ))
												tmp_state = 0;
										count_id = 0; 
										state = Handle_assignexpr_lvalue_assign_expr(yylineno,tmp_state); 
										if(state == -1) { error = 1; }
										if(((yyvsp[(1) - (3)].exprNode)->type)==tableitem_e){
											emit(tablesetelem,(yyvsp[(1) - (3)].exprNode),(yyvsp[(1) - (3)].exprNode)->index,(yyvsp[(3) - (3)].exprNode));
											(yyval.exprNode)=emit_iftableitem((yyvsp[(1) - (3)].exprNode));
											(yyval.exprNode)->type=assignexpr_e;
										}
										else{ 
											if(((yyvsp[(1) - (3)].exprNode))!=NULL){
												if(istempname((yyvsp[(1) - (3)].exprNode)->sym->name)){
													emit(assign,(yyvsp[(1) - (3)].exprNode),(expr*)0,(yyvsp[(1) - (3)].exprNode));
												}
												else{
													expr *e = Handle_relop(relop,(yyvsp[(3) - (3)].exprNode));
													if(e!=NULL){
														relop = 0;
														emit(assign, e, (expr*)0, (yyvsp[(1) - (3)].exprNode));
													}
													else{
														emit(assign,(yyvsp[(3) - (3)].exprNode),(expr*)0,(yyvsp[(1) - (3)].exprNode));	
														(yyval.exprNode)=newexpr(assignexpr_e);
														(yyval.exprNode)->sym=new_temp();
														emit(assign,(yyvsp[(1) - (3)].exprNode),(expr*)0,(yyval.exprNode));
													}
												}
											}
											else{
												emit(assign,(yyvsp[(3) - (3)].exprNode),(expr*)0,(yyval.exprNode));
											}

										}
									}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 305 "parser.y"
    { 	
														Handle_primary_lvalue(yylineno); 
														(yyval.exprNode)=emit_iftableitem((yyvsp[(1) - (1)].exprNode));
													}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 309 "parser.y"
    { Handle_primary_call(yylineno); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 310 "parser.y"
    { Handle_primary_objectdef(yylineno); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    { 
														(yyval.exprNode) = newexpr(programfunc_e);
														(yyval.exprNode)->sym = (yyvsp[(2) - (3)].Symbol);
														Handle_primary_l_parenthesis_funcdef_r_parenthesis(yylineno); 
													}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 316 "parser.y"
    { 	Handle_primary_const(yylineno);
														(yyval.exprNode)=(yyvsp[(1) - (1)].exprNode);										 
													}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 321 "parser.y"
    { 	state = Handle_lvalue_id((yyvsp[(1) - (1)].strVal),scope_count,yylineno,function_counter - (scope_count-1));
 														count_id++; 
 														if(count_id == 1) { prev_id_state = state; } 
 														if(state < -1) { tmp_state = state; } else { tmp_state = 0; } 
 														if(state == -1) { error = 1; }
 														id_val = strdup((yyvsp[(1) - (1)].strVal));
 														(yyval.exprNode) = newexpr(var_e);
 														int i = scope_count;
 														while(!(yyval.exprNode)->sym){
 															(yyval.exprNode)->sym = Lookup(mytable,id_val,i);
 															i--;
 														}
 														(yyval.exprNode) = lvalue_expr((yyval.exprNode)->sym);
 													}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 335 "parser.y"
    { 	
														state = Handle_lvalue_local_id((yyvsp[(2) - (2)].strVal),scope_count,yylineno); 
														if(state == -1) { error = 1; }
														id_val = strdup((yyvsp[(2) - (2)].strVal));
														(yyval.exprNode) = newexpr(var_e);
 														(yyval.exprNode)->sym = Lookup(mytable,id_val,scope_count);
 														if((yyval.exprNode)->sym)
 															(yyval.exprNode) = lvalue_expr((yyval.exprNode)->sym);
													}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    { 	state = Handle_lvalue_d_colon_id((yyvsp[(2) - (2)].strVal),yylineno); 
														if(state == -1) { error = 1; }
														id_val = strdup((yyvsp[(2) - (2)].strVal));
														(yyval.exprNode) = newexpr(var_e);
 														(yyval.exprNode)->sym = Lookup(mytable,id_val,0);
 														if((yyval.exprNode)->sym)
 															(yyval.exprNode) = lvalue_expr((yyval.exprNode)->sym);
													}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 352 "parser.y"
    { (yyval.exprNode) = (yyvsp[(1) - (1)].exprNode); Handle_lvalue_member(yylineno); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 355 "parser.y"
    { 		Handle_member_lvalue_dot_id(yylineno);
															(yyvsp[(1) - (3)].exprNode) = emit_iftableitem((yyvsp[(1) - (3)].exprNode));
															(yyval.exprNode) = newexpr(tableitem_e);
															(yyval.exprNode)->sym = (yyvsp[(1) - (3)].exprNode)->sym;
															(yyval.exprNode)->index = newexpr_conststring((yyvsp[(3) - (3)].strVal));
													 }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 362 "parser.y"
    { 		Handle_member_lvalue_l_bracket_expr_r_bracket(yylineno); 
															(yyvsp[(1) - (4)].exprNode) = emit_iftableitem((yyvsp[(1) - (4)].exprNode));
															(yyval.exprNode) = newexpr(tableitem_e);
															(yyval.exprNode)->sym = (yyvsp[(1) - (4)].exprNode)->sym;
															(yyval.exprNode)->index = (yyvsp[(3) - (4)].exprNode);

													}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 369 "parser.y"
    { tmp_state = 0; Handle_member_call_dot_id(yylineno); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 370 "parser.y"
    { Handle_member_call_l_bracket_expr_r_bracket(yylineno); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 373 "parser.y"
    { 	Handle_call_call_l_parenthesis_elist_r_parenthesis(yylineno);
															expr *e = Handle_relop(relop,(yyvsp[(3) - (4)].exprNode));
															if(e!=NULL){
																(yyvsp[(3) - (4)].exprNode) = e;
																relop = 0; 
															}
															(yyval.exprNode) = make_call((yyvsp[(1) - (4)].exprNode),(yyvsp[(3) - (4)].exprNode));
														}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 381 "parser.y"
    { 	Handle_call_lvalue_callsuffix(yylineno);
															expr *e = Handle_relop(relop,(yyvsp[(2) - (2)].CallsVar)->elist);
															if(e!=NULL){
																(yyvsp[(2) - (2)].CallsVar)->elist = e;
																relop = 0; 
															}
															if((yyvsp[(2) - (2)].CallsVar)->method==1){
																expr* self = (yyvsp[(1) - (2)].exprNode);
																(yyvsp[(1) - (2)].exprNode) = emit_iftableitem(member_item(self,(yyvsp[(2) - (2)].CallsVar)->name));
																(yyvsp[(2) - (2)].CallsVar)->elist=expr_list_insert((yyvsp[(2) - (2)].CallsVar)->elist,self);
															}
															(yyval.exprNode) = make_call((yyvsp[(1) - (2)].exprNode),(yyvsp[(2) - (2)].CallsVar)->elist);
														}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 394 "parser.y"
    { 	Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(yylineno); 
																							expr *e = Handle_relop(relop,(yyvsp[(5) - (6)].exprNode));
																							if(e!=NULL){
																								(yyvsp[(5) - (6)].exprNode) = e;
																								relop = 0; 
																							}
																							expr* func = newexpr(programfunc_e);
																							func->sym = (yyvsp[(2) - (6)].Symbol);
																							(yyval.exprNode) = make_call(func,(yyvsp[(5) - (6)].exprNode));
																						}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 406 "parser.y"
    { Handle_callsuffix_normcall(yylineno); (yyval.CallsVar)=(yyvsp[(1) - (1)].CallsVar); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 407 "parser.y"
    { Handle_callsuffix_methodcall(yylineno); (yyval.CallsVar)=(yyvsp[(1) - (1)].CallsVar); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 410 "parser.y"
    { 	Handle_normcall_l_parenthesis_elist_r_parenthesis(yylineno);
 														(yyval.CallsVar) = malloc(sizeof(calls));
														(yyval.CallsVar)->elist = (yyvsp[(2) - (3)].exprNode);
														(yyval.CallsVar)->method = 0;
														(yyval.CallsVar)->name = NULL;
													}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 418 "parser.y"
    { 	Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(yylineno); 
															(yyval.CallsVar) = malloc(sizeof(calls));
															(yyval.CallsVar)->elist = (yyvsp[(4) - (5)].exprNode);
															(yyval.CallsVar)->method = 1;
															(yyval.CallsVar)->name = strdup((yyvsp[(2) - (5)].strVal));
														}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 426 "parser.y"
    { 
									Handle_elist_expr(yylineno);
									if(for_flag == 0){
										total_expr++;
										expr *e = NULL;
										e = Handle_relop(relop,(yyvsp[(1) - (1)].exprNode));
										if(e){
											(yyvsp[(1) - (1)].exprNode) = e;
											relop = 0;
										}
									}
									(yyval.exprNode)=(yyvsp[(1) - (1)].exprNode);
								}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 439 "parser.y"
    { 	Handle_elist_elist_comma_expr(yylineno);
									if(for_flag == 0){
										total_expr++;
										expr *e = NULL;
										e = Handle_relop(relop,(yyvsp[(3) - (3)].exprNode));
										if(e){
											(yyvsp[(3) - (3)].exprNode) = e;
											relop = 0;
										}
										(yyval.exprNode)=expr_list_insert((yyvsp[(1) - (3)].exprNode),(yyvsp[(3) - (3)].exprNode));
									}
								}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 451 "parser.y"
    {(yyval.exprNode)=NULL;}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 454 "parser.y"
    {push_total_expr_stack(total_expr);total_expr=0;}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 454 "parser.y"
    { 
												Handle_objectdef_l_bracket_elist_r_bracket(yylineno);
												expr* t = newexpr(newtable_e);
												t->sym = new_temp();
												emit(tablecreate,0,0,t);
												int i=0;
												expr* tmp=(yyvsp[(3) - (4)].exprNode);
												if(total_expr!=0){
													while(tmp!=NULL){
														emit(tablesetelem,t,newexpr_constint(i++),tmp);
														tmp=tmp->next;
													}
												}
												(yyval.exprNode) = t;
												total_expr=pop_total_expr_stack();
											}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 470 "parser.y"
    {push_total_expr_stack(total_expr);total_expr=0;}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 470 "parser.y"
    { 
												Handle_objectdef_l_bracket_indexed_r_bracket(yylineno);
												expr* t = newexpr(newtable_e);
												t->sym = new_temp();
												emit(tablecreate,0,0,t);
												int i=0;
												indexed* tmp=(yyvsp[(3) - (4)].indexedVar);
												if(total_expr!=0){
													while(tmp!=NULL){
														emit(tablesetelem,t,tmp->x,tmp->y);
														tmp=tmp->next;
													}
												}
												(yyval.exprNode) = t;
												total_expr=pop_total_expr_stack();
											}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 488 "parser.y"
    { Handle_indexed_indexedelem(yylineno); (yyval.indexedVar)=(yyvsp[(1) - (1)].indexedVar);}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 489 "parser.y"
    { Handle_indexed_indexed_comma_indexedelem(yylineno); (yyval.indexedVar) = indexed_list_insert((yyvsp[(1) - (3)].indexedVar),(yyvsp[(3) - (3)].indexedVar));}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 492 "parser.y"
    { Handle_indexedelem_l_brace_expr_colon_expr_r_brace(yylineno); 
														total_expr++;
														(yyval.indexedVar) = malloc(sizeof(struct indexed));
														(yyval.indexedVar)->x=expr_list_insert((yyval.indexedVar)->x,(yyvsp[(2) - (5)].exprNode));
														total_expr++;
														expr *e = NULL;
														e = Handle_relop(relop,(yyvsp[(4) - (5)].exprNode));
														if(e){
															(yyvsp[(4) - (5)].exprNode) = e;
															relop = 0;
														}
														(yyval.indexedVar)->y=expr_list_insert((yyval.indexedVar)->y,(yyvsp[(4) - (5)].exprNode));
													}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 507 "parser.y"
    { EnterScopeSpace(); scope_count++;}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 507 "parser.y"
    { 	Hide(mytable,scope_count--); 
																					Handle_block_l_brace_block_1_r_brace(yylineno); 
																					ExitScopeSpace();
																				}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 513 "parser.y"
    { Handle_block_1_stmt_block_1(yylineno); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 514 "parser.y"
    {  }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 518 "parser.y"
    { (yyval.strVal)=(yyvsp[(1) - (1)].strVal); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 519 "parser.y"
    { (yyval.strVal)=Create_Function_Id(); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 522 "parser.y"
    {	
									if(function_counter < scope_count)
										function_counter = scope_count; 
									function_counter++; 
									funcName=(yyvsp[(2) - (2)].strVal);
									if(istempname((yyvsp[(2) - (2)].strVal))){
										state = Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block((yyvsp[(2) - (2)].strVal) ,scope_count, yylineno); 
									}
									else{
										state = Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block((yyvsp[(2) - (2)].strVal), scope_count, yylineno); 
									}
									if(state == -1) { error = 1; }
									(yyval.Symbol)=Lookup(mytable,(yyvsp[(2) - (2)].strVal),scope_count);
									(yyval.Symbol)->iaddress=next_quad_label();	
									emit(funcstart,0,0,lvalue_expr((yyval.Symbol)));
									push_to_stack(CurrScopeSpace()); //push Current_Scope_offset
									EnterScopeSpace();
									resetformalargsoffset();
								}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 544 "parser.y"
    {scope_count++;}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 544 "parser.y"
    { EnterScopeSpace(); scope_count--;  resetfuctionlocalsoffset();}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 547 "parser.y"
    { push_loopcounter_stack(loopcounter); loopcounter = 0; }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 548 "parser.y"
    { loopcounter = pop_loopcounter_stack(); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 550 "parser.y"
    { (yyval.intVal)=CurrScopeOffset(); ExitScopeSpace(); function_counter--; }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 553 "parser.y"
    {	
											ExitScopeSpace();
											(yyvsp[(1) - (3)].Symbol)->totallocals=(yyvsp[(3) - (3)].intVal);
											unsigned old_offset=pop_from_stack();
											restorecurrscopeoffset(old_offset);
											(yyval.Symbol)=(yyvsp[(1) - (3)].Symbol);
											emit(funcend,0,0,lvalue_expr((yyvsp[(1) - (3)].Symbol)));
										}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 563 "parser.y"
    { 	Handle_const_integer(yylineno); 
						(yyval.exprNode) = newexpr_constint((yyvsp[(1) - (1)].intVal));
					}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 566 "parser.y"
    { 	Handle_const_double(yylineno);
						(yyval.exprNode) = newexpr_constdouble((yyvsp[(1) - (1)].realVal));
					}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 569 "parser.y"
    { 	Handle_const_string(yylineno); 
						(yyval.exprNode) = newexpr_conststring((yyvsp[(1) - (1)].strVal));
					}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 572 "parser.y"
    { 	Handle_const_nil(yylineno);
						(yyval.exprNode) = newexpr(nil_e);
		 			}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 575 "parser.y"
    { 	Handle_const_true(yylineno);
						(yyval.exprNode) = newexpr_constbool('1');
					}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 578 "parser.y"
    { 	Handle_const_false(yylineno);
						(yyval.exprNode) = newexpr_constbool('0');
					}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 583 "parser.y"
    {	
							state = Handle_idlist_id_idlist_1((yyvsp[(1) - (2)].strVal),funcName,scope_count,yylineno); 
							if(state == -1) { error = 1; }
						}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 587 "parser.y"
    {  }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 590 "parser.y"
    { ;Handle_idlist_1_comma_idlist(yylineno); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 591 "parser.y"
    {  }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 594 "parser.y"
    { 
														expr *e = Handle_relop(relop,(yyvsp[(3) - (4)].exprNode));
														if(e!=NULL)
															relop = 0;
														else
															e = (yyvsp[(3) - (4)].exprNode);
														(yyval.uVal) = Handle_ifprefix_if_l_parenthesis_expr_r_parenthesis(e,yylineno); 													
													}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 604 "parser.y"
    { (yyval.uVal) = Handle_elseprefix_else(yylineno); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 607 "parser.y"
    { Handle_ifstmt_ifprefix_stmt((yyvsp[(1) - (2)].uVal),yylineno); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 608 "parser.y"
    { Handle_ifstmt_ifprefix_stmt_elseprefix_stmt((yyvsp[(1) - (4)].uVal),(yyvsp[(3) - (4)].uVal),yylineno); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 611 "parser.y"
    { ++loopcounter; loop_index++; if(max_loop_index<loop_index){max_loop_index = loop_index;} push_loopindex_stack(loop_index);}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 612 "parser.y"
    { --loopcounter; loop_index = pop_loopindex_stack();}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 613 "parser.y"
    { (yyval.stmtVal) = (yyvsp[(2) - (3)].stmtVal); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 615 "parser.y"
    { (yyval.uVal) = Handle_whilestart_while(yylineno); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 618 "parser.y"
    { 
													start = next_quad_label();
													push_start_stack(start);
													expr *e = Handle_relop(relop,(yyvsp[(2) - (3)].exprNode));
													if(e!=NULL)
														relop = 0;
													else
														e = (yyvsp[(2) - (3)].exprNode);
													(yyval.uVal) = Handle_whilecond_l_parenthesis_expr_r_parenthesis(e,yylineno); 
												}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 630 "parser.y"
    { 
													(yyval.stmtVal) = (yyvsp[(3) - (3)].stmtVal); 
													Handle_whilestmt_whilestart_whilecond_stmt((yyvsp[(1) - (3)].uVal),(yyvsp[(2) - (3)].uVal),(yyvsp[(3) - (3)].stmtVal),loop_index,yylineno); 
													end = next_quad_label(); 
													push_stop_stack(end);
													start=pop_start_stack(); 
													end = pop_stop_stack(); 
												}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 640 "parser.y"
    { (yyval.uVal) = next_quad_label(); emit_jump(jump, 0, 0, 0, 0); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 641 "parser.y"
    { (yyval.uVal) = next_quad_label(); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 643 "parser.y"
    {for_flag = 1;}
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 643 "parser.y"
    { 
																					start = next_quad_label();
																					push_start_stack(start);
																					expr *e = Handle_relop(relop,(yyvsp[(7) - (8)].exprNode));
																					if(e!=NULL)
																						relop = 0;
																					else
																						e = (yyvsp[(7) - (8)].exprNode);
																					(yyval.forVal) = malloc(sizeof(struct forprefix));
																					(yyval.forVal)->test = (yyvsp[(6) - (8)].uVal);
																					(yyval.forVal)->enter = next_quad_label();
																					emit(if_eq,e,newexpr_constbool('1'),0);
																				}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 658 "parser.y"
    {for_flag = 0;}
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 658 "parser.y"
    { 	Handle_forstmt_forprefix_N_elist_r_parenthesis_N_loopstmt_N((yyvsp[(1) - (8)].forVal),(yyvsp[(2) - (8)].uVal),(yyvsp[(6) - (8)].uVal),(yyvsp[(7) - (8)].stmtVal),(yyvsp[(8) - (8)].uVal),loop_index,yylineno);
																				end = next_quad_label();	
																				push_stop_stack(end);
																				start=pop_start_stack(); end = pop_stop_stack(); 
 																			}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 665 "parser.y"
    { error = Handle_returnstmt_return_expr_semicolon((yyvsp[(2) - (3)].exprNode),function_counter,yylineno); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 666 "parser.y"
    { error = Handle_returnstmt_return_semicolon(function_counter,yylineno); }
    break;


/* Line 1787 of yacc.c  */
#line 2763 "parser.c"
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
#line 669 "parser.y"




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
	
	if(error == 0){
		Print_Hash(mytable);
		Print_Quads();
	}else
		printf("Errors occured!\n");	
	return 0;
}
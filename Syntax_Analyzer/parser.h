/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:1909  */

	int intVal;
	double realVal;
	char *strVal;
	struct Node *exprNode;

#line 159 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

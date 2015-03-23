%{
	#include <stdio.h>
	#include "actions_handler.h"
	int yyerror(char* yaccProvidedMessage);
	int alpha_yylex(void);
	
	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
%}
%defines
%error-verbose

%union{
	int intVal;
	double realVal;
	char *strVal;
}

%start program
%token <intVal> INTEGER
%token <realVal> DOUBLE
%token <strVal> STRING
%token <strVal> CHAR
%token <strVal> ID
%token L_BRACE R_BRACE L_PARENTHESIS R_PARENTHESIS L_BRACKET R_BRACKET SEMICOLON COMMA COLON D_COLON DOT D_DOT
%token PLUS MINUS MUL DIV MOD PLUS_PLUS MINUS_MINUS ASSIGN EQ NOT_EQ LESS_THAN GREATER_THAN LESS_EQ GREATER_EQ
%token IF ELSE AND NOT OR LOCAL TRUE FALSE WHILE FOR FUNCTION RETURN BREAK CONTINUE NIL

%right		ASSIGN
%left		OR
%left		AND
%nonassoc	EQ NOT_EQ
%nonassoc	GREATER_THAN GREATER_EQ LESS_THAN LESS_EQ
%left		PLUS MINUS
%left		MUL DIV MOD
%right		NOT PLUS_PLUS MINUS_MINUS UMINUS
%left		DOT D_DOT
%left		L_BRACKET R_BRACKET
%left		L_PARENTHESIS R_PARENTHESIS

%%

program:	stmt program
		|/* empty */
		;


stmt:	expr SEMICOLON
		| ifstmt
		| whilestmt
		| forstmt
		| returnstmt
		| brk
		| cont
		| block
		| funcdef
		;

ifstmt:	IF L_PARENTHESIS expr R_PARENTHESIS block ELSE block {printf(" IF STATEMENT IN LINE %d \n",yylineno);}
		;

whilestmt:	WHILE L_PARENTHESIS expr R_PARENTHESIS block {printf(" WHILE STATEMENT IN LINE %d \n",yylineno);}
			;

forstmt:	FOR L_PARENTHESIS expr SEMICOLON expr SEMICOLON expr R_PARENTHESIS block {printf(" FOR STATEMENT IN LINE %d \n",yylineno);}
			;

returnstmt:	RETURN expr SEMICOLON {printf(" RETURN STATEMENT IN LINE %d \n",yylineno);}
			;

brk:	BREAK SEMICOLON { Handle_stmt_break_semicolon(yylineno); }
		;

cont: 	CONTINUE SEMICOLON {printf(" CONTINUE STATEMENT IN LINE %d \n",yylineno);}
		;

funcdef FUNCTION L_PARENTHESIS  R_PARENTHESIS block {printf(" FUNCTION STATEMENT IN LINE %d \n",yylineno);}
		;

block:	L_BRACE stmt R_BRACE
		;

expr:	
		| expr op expr
		| expr 
		;


op:		/*empty*/
		|'+'
		|'-'
		|'<'
		|'>'
		|'=='
		|'<='
		|'>='
		|'!='
		|'*'
		|'/'
		|'%'
		|'and'
		|'or'
		;

%%



int yyerror(char* yaccProvidedMessage){
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

	yyparse();
	return 0;
}
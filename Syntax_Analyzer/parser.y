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


stmt:	expr SEMICOLON 			{ Handle_stmt_expr_semicolon(yylineno); }
		| ifstmt				{ Handle_stmt_ifstmt(yylineno); }
		| whilestmt				{ Handle_stmt_whilestmt(yylineno); }
		| forstmt				{ Handle_stmt_forstmt(yylineno); }
		| returnstmt			{ Handle_stmt_returnstmt(yylineno); }
		| BREAK SEMICOLON 		{ Handle_stmt_break_semicolon(yylineno); }
		| CONTINUE SEMICOLON 	{ Handle_stmt_continue_semicolon(yylineno); }
		| block					{ Handle_stmt_block(yylineno); }
		;

ifstmt:	IF L_PARENTHESIS expr R_PARENTHESIS stmt 			{ Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
		|IF L_PARENTHESIS expr R_PARENTHESIS stmt ELSE stmt { Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(yylineno); }
		;

whilestmt:	WHILE L_PARENTHESIS expr R_PARENTHESIS stmt 	{ Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
			;

forstmt:	FOR L_PARENTHESIS expr SEMICOLON expr SEMICOLON expr R_PARENTHESIS stmt { Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(yylineno); }
			;

returnstmt:	RETURN expr SEMICOLON 	{ Handle_returnstmt_return_expr_semicolon(yylineno); }
			|RETURN SEMICOLON 		{ Handle_returnstmt_return_semicolon(yylineno); }
			;



block:	L_BRACE stmt R_BRACE 		{ }
		;

expr:	assignexpr					{ Handle_expr_assignexpr(yylineno); }
		| expr PLUS expr 			{ Handle_expr_expr_plus_expr(yylineno); }
		| expr MINUS expr 			{ Handle_expr_expr_minus_expr(yylineno); }
		| expr MUL expr 			{ Handle_expr_expr_mul_expr(yylineno); }
		| expr DIV expr 			{ Handle_expr_expr_div_expr(yylineno); }
		| expr MOD expr 			{ Handle_expr_expr_mod_expr(yylineno); }
		| expr EQ expr 				{ Handle_expr_expr_eq_expr(yylineno); }
		| expr NOT_EQ expr  		{ Handle_expr_expr_not_eq_expr(yylineno); }
		| expr LESS_THAN expr  		{ Handle_expr_expr_less_than_expr(yylineno); }
		| expr GREATER_THAN expr  	{ Handle_expr_expr_greater_than_expr(yylineno); }
		| expr LESS_EQ expr 		{ Handle_expr_expr_less_eq_expr(yylineno); }
		| expr GREATER_EQ expr 		{ Handle_expr_expr_greater_eq_expr(yylineno); }
		| expr AND expr  			{ Handle_expr_expr_and_expr(yylineno); }
		| expr OR expr 				{ Handle_expr_expr_or_expr(yylineno); }
		| expr 						{ Handle_expr_term(yylineno); }
		;

assignexpr:	lvalue ASSIGN expr 		{ Handle_assignexpr_lvalue_assign_expr(yylineno); }
			;

lvalue:		ID
			|LOCAL ID
			|D_COLON ID
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
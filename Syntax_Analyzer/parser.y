%{
	#include <stdio.h>
	#include "actions_handler.h"
	#include "symtable.h"
	int yyerror(char* yaccProvidedMessage);
	int alpha_yylex(void);
	int scope_count = 0;
	char *arguments;
	
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

%type <intVal> expr
%type <strVal> idlist
%type <strVal> idlist_1
%type <strVal> funcdef

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
%left 		ELSE
%%

program:	stmt program
		|/* empty */
		;


stmt:	expr SEMICOLON 								{ Handle_stmt_expr_semicolon(yylineno); }
		| ifstmt									{ Handle_stmt_ifstmt(yylineno); }
		| whilestmt									{ Handle_stmt_whilestmt(yylineno); }
		| forstmt									{ Handle_stmt_forstmt(yylineno); }
		| returnstmt								{ Handle_stmt_returnstmt(yylineno); }
		| BREAK SEMICOLON 							{ Handle_stmt_break_semicolon(yylineno); }
		| CONTINUE SEMICOLON 						{ Handle_stmt_continue_semicolon(yylineno); }
		| block										{ Handle_stmt_block(yylineno); }
		| funcdef									{ Handle_stmt_funcdef(yylineno); }
		| SEMICOLON 								{ Handle_stmt_semicolon(yylineno); }
		;

expr:	assignexpr									{ Handle_expr_assignexpr(yylineno); }
		| expr PLUS expr 							{ Handle_expr_expr_plus_expr($1,$3,yylineno); }
		| expr MINUS expr 							{ Handle_expr_expr_minus_expr($1,$3,yylineno); }
		| expr MUL expr 							{ Handle_expr_expr_mul_expr($1,$3,yylineno); }
		| expr DIV expr 							{ Handle_expr_expr_div_expr($1,$3,yylineno); }
		| expr MOD expr 							{ Handle_expr_expr_mod_expr($1,$3,yylineno); }
		| expr EQ expr 								{ Handle_expr_expr_eq_expr($1,$3,yylineno); }
		| expr NOT_EQ expr  						{ Handle_expr_expr_not_eq_expr($1,$3,yylineno); }
		| expr LESS_THAN expr  						{ Handle_expr_expr_less_than_expr($1,$3,yylineno); }
		| expr GREATER_THAN expr  					{ Handle_expr_expr_greater_than_expr($1,$3,yylineno); }
		| expr LESS_EQ expr 						{ Handle_expr_expr_less_eq_expr($1,$3,yylineno); }
		| expr GREATER_EQ expr 						{ Handle_expr_expr_greater_eq_expr($1,$3,yylineno); }
		| expr AND expr  							{ Handle_expr_expr_and_expr($1,$3,yylineno); }
		| expr OR expr 								{ Handle_expr_expr_or_expr($1,$3,yylineno); }
		| term 										{ Handle_expr_term(yylineno); }
		;

term: 	L_PARENTHESIS expr R_PARENTHESIS 			{ Handle_term_l_parenthesis_expr_r_parenthesis(yylineno); }
		| UMINUS expr 								{ Handle_term_uminus_expr(yylineno); }
		| NOT expr 									{ Handle_term_not_expr(yylineno); }
		| PLUS_PLUS lvalue 							{ Handle_term_plus_plus_lvalue(yylineno); }
		| lvalue PLUS_PLUS							{ Handle_term_lvalue_plus_plus(yylineno); }
		| MINUS_MINUS lvalue 						{ Handle_term_minus_minus_lvalue(yylineno); }
		| lvalue MINUS_MINUS 						{ Handle_term_lvalue_minus_minus(yylineno); }
		| primary 									{ Handle_term_primary(yylineno); }
		;

assignexpr:	lvalue ASSIGN expr 						{ Handle_assignexpr_lvalue_assign_expr(yylineno); }
			;	

primary:	lvalue 									{ Handle_primary_lvalue(yylineno); }
			| call 									{ Handle_primary_call(yylineno); }
			| objectdef 							{ Handle_primary_objectdef(yylineno); }
			| L_PARENTHESIS funcdef R_PARENTHESIS 	{ Handle_primary_l_parenthesis_funcdef_r_parenthesis(yylineno); }
			| const 								{ Handle_primary_const(yylineno); }
			;

lvalue:		ID 										{ Handle_lvalue_id($1,scope_count,yylineno,0); }
			| LOCAL ID 								{ Handle_lvalue_local_id($2,scope_count,yylineno); }
			| D_COLON ID 							{ Handle_lvalue_d_colon_id(NULL,yylineno); }
			| member 								{ Handle_lvalue_member(yylineno); }
			;

member:		lvalue DOT ID 							{ Handle_member_lvalue_dot_id(yylineno); }
			| lvalue L_BRACKET expr R_BRACKET 		{ Handle_member_lvalue_l_bracket_expr_r_bracket(yylineno); }
			| call DOT ID 							{ Handle_member_call_dot_id(yylineno); }
			| call L_BRACKET expr R_BRACKET 		{ Handle_member_call_l_bracket_expr_r_bracket(yylineno); }
			;

call: 		call L_PARENTHESIS elist R_PARENTHESIS 		{ Handle_call_call_l_parenthesis_elist_r_parenthesis(yylineno); }
			| lvalue callsuffix 						{ Handle_call_lvalue_callsuffix(yylineno); }
			| L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS elist R_PARENTHESIS 	{ Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(yylineno); }
			;

callsuffix: normcall 		{ Handle_callsuffix_normcall(yylineno); }
			| methodcall 	{ Handle_callsuffix_methodcall(yylineno); }
			;

normcall: 	L_PARENTHESIS elist R_PARENTHESIS 		{ Handle_normcall_l_parenthesis_elist_r_parenthesis(yylineno); }
			;

methodcall: D_DOT ID L_PARENTHESIS elist R_PARENTHESIS 	{ Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(yylineno); }
			;

elist: 		expr  				{ Handle_elist_expr(yylineno); }
			| elist COMMA expr 	{ Handle_elist_elist_comma_expr(yylineno); }
			|
			;



objectdef: 	L_BRACKET elist R_BRACKET 		{ Handle_objectdef_l_bracket_elist_r_bracket(yylineno); }
			| L_BRACKET indexed R_BRACKET 	{ Handle_objectdef_l_bracket_indexed_r_bracket(yylineno); }
			;

indexed: 	indexedelem  		{ Handle_indexed_indexedelem(yylineno); }
			| indexed COMMA indexedelem { Handle_indexed_indexed_comma_indexedelem(yylineno); }
			;



indexedelem: 	L_BRACE expr COLON expr R_BRACE 	{ Handle_indexedelem_l_brace_expr_colon_expr_r_brace(yylineno); }
				;

block: 		L_BRACE { scope_count++; } block_1 R_BRACE 		{ scope_count--; Handle_block_l_brace_block_1_r_brace(0,0,yylineno); }
			;

block_1: 	stmt block_1 	{ Handle_block_1_stmt_block_1(yylineno); }
			| 				{  }
			;

funcdef: 	FUNCTION L_PARENTHESIS {scope_count++;} idlist R_PARENTHESIS block 				{ scope_count--; Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block(scope_count, arguments, yylineno); }
			| FUNCTION ID L_PARENTHESIS {scope_count++;} idlist R_PARENTHESIS block 		{ scope_count--; Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block($2, $5, scope_count, yylineno); }
			;

const:	INTEGER 	{ Handle_const_integer(yylineno); }
		| DOUBLE 	{ Handle_const_double(yylineno); }
		| STRING 	{ Handle_const_string(yylineno); }
		| NIL 		{ Handle_const_nil(yylineno); }
		| TRUE 		{ Handle_const_true(yylineno); }
		| FALSE 	{ Handle_const_false(yylineno); }
		;

idlist: ID idlist_1 	{ Handle_idlist_id_idlist_1(NULL,NULL,0,yylineno); }
		|				{ arguments = NULL; }
		;

idlist_1: 	COMMA idlist 	{ Handle_idlist_1_comma_idlist(NULL,NULL,0,yylineno); }
			| 				{  }
			;

ifstmt:	IF L_PARENTHESIS expr R_PARENTHESIS stmt 			{ Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
		|IF L_PARENTHESIS expr R_PARENTHESIS stmt ELSE stmt { Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(yylineno); }
		;

whilestmt:	WHILE L_PARENTHESIS expr R_PARENTHESIS stmt 	{ Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
			;

forstmt:	FOR L_PARENTHESIS elist SEMICOLON expr SEMICOLON elist R_PARENTHESIS stmt { Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(yylineno); }
			;

returnstmt:	RETURN expr SEMICOLON 	{ Handle_returnstmt_return_expr_semicolon(yylineno); }
			|RETURN SEMICOLON 		{ Handle_returnstmt_return_semicolon(yylineno); }
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
	mytable = SymTable_new();

	yyparse();


	//Insert_Var(mytable, "giwrgadakis", "pro" , 0, 1);
	//Insert_Func(mytable, "giwrgadakis", "pro","x,y" , 0, 1);

	Print_Hash(mytable);
	return 0;
}
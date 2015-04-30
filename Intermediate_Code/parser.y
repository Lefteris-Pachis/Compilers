%{
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
	int loopcounter = 0;
	int assign_counter = 0;
	char* id_val;
	char* funcName = NULL;
	expr* tmp;
	label_list* break_list;
	

	elist_l* top;

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
	struct symbol *Symbol;
	struct expr *exprNode;
	unsigned uVal;
	struct statement *stmtVal;
	struct calls *CallsVar;
	struct elist_l *ElistVar;
}

%start program
%token <intVal> INTEGER
%token <realVal> DOUBLE
%token <strVal> STRING
%token <strVal> CHAR
%token <strVal> ID
%token <strVal> L_BRACE R_BRACE L_PARENTHESIS R_PARENTHESIS L_BRACKET R_BRACKET SEMICOLON COMMA COLON D_COLON DOT D_DOT
%token <strVal> PLUS MINUS MUL DIV MOD PLUS_PLUS MINUS_MINUS ASSIGN EQ NOT_EQ LESS_THAN GREATER_THAN LESS_EQ GREATER_EQ
%token <strVal> IF ELSE AND NOT OR LOCAL TRUE FALSE WHILE FOR FUNCTION RETURN BREAK CONTINUE NIL



%type <strVal> idlist
%type <strVal> idlist_1
%type <strVal> funcname
%type <intVal> funcbody
%type <Symbol> funcprefix
%type <Symbol> funcdef

%type <exprNode> expr
%type <exprNode> lvalue
%type <exprNode> const
%type <exprNode> term
%type <exprNode> member		/* tableitem */
%type <exprNode> primary
%type <exprNode> assignexpr

%type <uVal> ifprefix
%type <uVal> elseprefix

%type <uVal> whilestart
%type <uVal> whilecond

%type <uVal> N
%type <uVal> M
%type <uVal> forprefix

%type <stmtVal> stmt
%type <stmtVal> loopstmt
%type <stmtVal> whilestmt
%type <stmtVal> break
%type <stmtVal> continue

%type <exprNode> call

%type <CallsVar> callsuffix
%type <CallsVar> methodcall
%type <CallsVar> normcall

%type <ElistVar> elist
%type <ElistVar> objectdef

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

//stmts: 	stmt {$$ = $1;}
//		| stmts stmt 		{
								//printf("WTF\n"); 
								//$$->break_list = merge($1->break_list,$2->break_list);
								//$$->cont_list = merge($1->cont_list,$2->cont_list);
//						 	};


break: 		BREAK SEMICOLON 						{ 	
														if(loopcounter > 0){
															//$$->break_list=new_label_list(break_list,next_quad_label());
															//printf("sssssssss%d\n",$$->break_list->label);
															//emit_jump(jump, 0, 0, 0, 0); 
															Handle_stmt_break_semicolon(yylineno);
														}else{
															printf("Error at line: %d break is not in a loop\n",yylineno);
															error = 1;
														} 
													};
continue:	CONTINUE SEMICOLON 						{ 	
														if(loopcounter > 0){
														//$$->cont_list=new_label_list($$->cont_list,next_quad_label()); 
														//emit_jump(jump, 0, 0, 0, 0); 
														//Handle_stmt_continue_semicolon(yylineno); 
														}else{
															printf("Error at line: %d continue is not in a loop\n",yylineno);
															error = 1;
														}
													};

stmt:	expr SEMICOLON 								{ Handle_stmt_expr_semicolon(yylineno); assign_counter = 0;}
		| ifstmt									{ Handle_stmt_ifstmt(yylineno); }
		| whilestmt									{ Handle_stmt_whilestmt(yylineno); }
		| forstmt									{ Handle_stmt_forstmt(yylineno); }
		| returnstmt								{ Handle_stmt_returnstmt(yylineno); }
		| break 									{$$ = $1;}
		| continue 									{$$ = $1;}
		| block										{ Handle_stmt_block(yylineno); }
		| funcdef									{ Handle_stmt_funcdef(yylineno); }
		| SEMICOLON 								{ Handle_stmt_semicolon(yylineno); }
		;

expr:	assignexpr									{ Handle_expr_assignexpr(yylineno);
													$$=$1;
													 }
		| expr PLUS expr 							{ $$ = Handle_expr_expr_plus_expr($1, $3, yylineno); }
		| expr MINUS expr 							{ $$ = Handle_expr_expr_minus_expr($1, $3, yylineno); }
		| expr MUL expr 							{ $$ = Handle_expr_expr_mul_expr($1, $3, yylineno); }
		| expr DIV expr 							{ $$ = Handle_expr_expr_div_expr($1, $3, yylineno); }
		| expr MOD expr 							{ $$ = Handle_expr_expr_mod_expr($1, $3, yylineno); }
		| expr EQ expr 								{ $$ = Handle_expr_expr_eq_expr($1, $3,yylineno);tmp =$$; }
		| expr NOT_EQ expr  						{ $$ = Handle_expr_expr_not_eq_expr($1, $3,yylineno); tmp =$$;}
		| expr LESS_THAN expr  						{ $$ = Handle_expr_expr_less_than_expr($1, $3,yylineno);tmp =$$;}
		| expr GREATER_THAN expr  					{ $$ = Handle_expr_expr_greater_than_expr($1, $3,yylineno); tmp =$$;}
		| expr LESS_EQ expr 						{ $$ = Handle_expr_expr_less_eq_expr($1, $3,yylineno);tmp =$$; }
		| expr GREATER_EQ expr 						{ $$ = Handle_expr_expr_greater_eq_expr($1, $3,yylineno);tmp =$$; }
		| expr AND expr  							{ $$ = Handle_expr_expr_and_expr($1, $3,yylineno); }
		| expr OR expr 								{ $$ = Handle_expr_expr_or_expr($1, $3,yylineno); }
		| term 										{ $$=$1;	Handle_expr_term(yylineno); }
		;

term: 	L_PARENTHESIS expr R_PARENTHESIS 			{ $$ = $2; Handle_term_l_parenthesis_expr_r_parenthesis(yylineno); }
		| UMINUS expr 								{ Handle_term_uminus_expr(yylineno); }
		| NOT expr 									{ Handle_term_not_expr(yylineno); }
		| PLUS_PLUS lvalue 							{ state = Handle_term_plus_plus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } }
		| lvalue PLUS_PLUS							{ $$ = $1; state = Handle_term_lvalue_plus_plus(yylineno,id_val); if(state == -1) { error = 1; } }
		| MINUS_MINUS lvalue 						{ state = Handle_term_minus_minus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } }
		| lvalue MINUS_MINUS 						{ $$ = $1; state = Handle_term_lvalue_minus_minus(yylineno,id_val); if(state == -1) { error = 1; } }
		| primary 									{ $$ = $1; Handle_term_primary(yylineno); }
		;


assignexpr:	lvalue ASSIGN expr 						{ 	
														assign_counter++;
														if(count_id > 1)
															if(prev_id_state == 0 && (tmp_state == -2 || tmp_state == -3 ))
																tmp_state = 0;
														count_id = 0; 
														state = Handle_assignexpr_lvalue_assign_expr(yylineno,tmp_state); 
														if(state == -1) { error = 1; }
														if(($1->type)==tableitem_e){
															emit(tablesetelem,$1,$1->index,$3);
															$$=emit_iftableitem($1);
															$$->type=assignexpr_e;
														}
														else{ 
															if(($1)!=NULL){
																printf("ifffffffffff\n");
																if(istempname($1->sym->name)){
																	
																	emit(assign,$1,(expr*)0,$1);
																	

																}
																
																else{
																	emit(assign,$3,(expr*)0,$1);	
																	
																	if(assign_counter > 1){
																		$$=newexpr(assignexpr_e);
																		$$->sym=new_temp();
																		
																		emit(assign,$1,(expr*)0,$$);
																	}
																}
															}
															else{
																printf("ELSEEEEEEEEEEEEe\n");
																emit(assign,$3,(expr*)0,$$);
															}

														}
	}
			;	

primary:	lvalue 									{ Handle_primary_lvalue(yylineno); 
															printf("NAME = %s\n",$1->sym->name);
															$$=emit_iftableitem($1);
													}
			| call 									{ Handle_primary_call(yylineno); }
			| objectdef 							{ Handle_primary_objectdef(yylineno); }
			| L_PARENTHESIS funcdef R_PARENTHESIS 	{ 
														$$ = newexpr(programfunc_e);
														$$->sym = $2; 
														//$$->type = programfunc_e;

														Handle_primary_l_parenthesis_funcdef_r_parenthesis(yylineno); }
			| const 								{ Handle_primary_const(yylineno);
														$$=$1;										 
													}
			;

lvalue:		ID 										{ 	state = Handle_lvalue_id($1,scope_count,yylineno,function_counter - (scope_count-1));
 														count_id++; 
 														if(count_id == 1) { prev_id_state = state; } 
 														if(state < -1) { tmp_state = state; } else { tmp_state = 0; } 
 														if(state == -1) { error = 1; }
 														id_val = strdup($1);
 														$$ = malloc(sizeof(expr*));
 														int i = scope_count;
 														$$ = malloc(sizeof(expr*));
 														while(!$$->sym){
 															$$->sym = Lookup(mytable,id_val,i);
 															i--;
 														}
 														$$ = lvalue_expr($$->sym);
 													}
			| LOCAL ID 								{ 	
														state = Handle_lvalue_local_id($2,scope_count,yylineno); 
														if(state == -1) { error = 1; }
														id_val = strdup($2);
														$$ = malloc(sizeof(expr*));
 														$$->sym = Lookup(mytable,id_val,scope_count);
 														if($$->sym)
 															$$ = lvalue_expr($$->sym);
													}
			| D_COLON ID 							{ 	state = Handle_lvalue_d_colon_id($2,yylineno); 
														if(state == -1) { error = 1; }
														id_val = strdup($2);
														$$ = malloc(sizeof(expr*));
 														$$->sym = Lookup(mytable,id_val,0);
 														if($$->sym)
 															$$ = lvalue_expr($$->sym);
													}
			| member 								{ Handle_lvalue_member(yylineno); }
			;

member:		lvalue DOT ID 							{ Handle_member_lvalue_dot_id(yylineno);

															$1 = emit_iftableitem($1);
															$$ = newexpr(tableitem_e);
															$$->sym = $1->sym;
															$$->index = newexpr_conststring($3);
													 }

			| lvalue L_BRACKET expr R_BRACKET 		{ Handle_member_lvalue_l_bracket_expr_r_bracket(yylineno); 

															$1 = emit_iftableitem($1);
															$$ = newexpr(tableitem_e);
															$$->sym = $1->sym;
															$$->index = $3;

													}
			| call DOT ID 							{ tmp_state = 0; Handle_member_call_dot_id(yylineno); }
			| call L_BRACKET expr R_BRACKET 		{ Handle_member_call_l_bracket_expr_r_bracket(yylineno); }
			;

call: 		call L_PARENTHESIS elist R_PARENTHESIS 		{ Handle_call_call_l_parenthesis_elist_r_parenthesis(yylineno); 
															$$ = make_call($1,$3);
														}
			| lvalue callsuffix 						{ Handle_call_lvalue_callsuffix(yylineno);
															
															if($2->method==1){
																expr* self = $1;															
																self->sym = Lookup(mytable,self->sym->name,scope_count);
																$1 = emit_iftableitem(self);

															}
															$$ = make_call($1,$2->elist);
														}
			| L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS elist R_PARENTHESIS 	{ Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(yylineno); 
																							expr* func = newexpr(programfunc_e);
																							func->sym = $2;
																							$$ = make_call(func,$5);
																						}
			;

callsuffix: normcall 		{ Handle_callsuffix_normcall(yylineno); $$=$1; }
			| methodcall 	{ Handle_callsuffix_methodcall(yylineno); $$=$1; }
			;

normcall: 	L_PARENTHESIS elist R_PARENTHESIS 		{ Handle_normcall_l_parenthesis_elist_r_parenthesis(yylineno);
 														$$ = malloc(sizeof(calls));
														$$->elist = $2;
														$$->method = 0;
														$$->name = NULL;
													}
			;

methodcall: D_DOT ID L_PARENTHESIS elist R_PARENTHESIS 	{ Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(yylineno); 
															$$ = malloc(sizeof(calls));
															$$->elist = $4;
															$$->method = 1;
															$$->name = strdup($2);
														}
			;

elist: 		expr  				{ 
									Handle_elist_expr(yylineno); 
									push_elist((expr*)$1,top);
								}
			| elist COMMA expr 	{ Handle_elist_elist_comma_expr(yylineno); 

									push_elist((expr*)$3,top);
								}
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

block: 		L_BRACE { EnterScopeSpace(); scope_count++;} block_1 R_BRACE 		{ 	Hide(mytable,scope_count--); 
																Handle_block_l_brace_block_1_r_brace(yylineno); 
																ExitScopeSpace();
															}
			;

block_1: 	stmt block_1 	{ Handle_block_1_stmt_block_1(yylineno); }
			| 				{  }
			;


funcname:	ID{		$$=$1;							}		
			| 	{$$=Create_Function_Id(); 		 	}
			;

funcprefix: FUNCTION funcname {	
								if(function_counter < scope_count)
									function_counter = scope_count; 
								function_counter++; 
								funcName=$2;

								if(istempname($2)){
									state = Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block($2 ,scope_count, yylineno); 
								}
								else{

									state = Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block($2, scope_count, yylineno); 
								}

								if(state == -1) { error = 1; }
								//printf("---------scope_count%d-------------",scope_count);
								$<Symbol>$=Lookup(mytable,$2,scope_count);
								$<Symbol>$->iaddress=next_quad_label();	
								emit(funcstart,0,0,lvalue_expr($<Symbol>$));
								push_to_stack(CurrScopeSpace()); //push Current_Scope_offset
								EnterScopeSpace();
								resetformalargsoffset();
								}								
			;


funcargs: L_PARENTHESIS{scope_count++;} idlist R_PARENTHESIS {;EnterScopeSpace(); scope_count--;  resetfuctionlocalsoffset();}
			;


funcbody:  block { $$=CurrScopeOffset(); ExitScopeSpace(); function_counter--; }
			;

funcdef:  funcprefix funcargs funcbody  {	
											ExitScopeSpace();
											$1->totallocals=$3;
											unsigned old_offset=pop_from_stack();
											printf("----Offset=%d",old_offset);
											restorecurrscopeoffset(old_offset);
											$$=$1;

											emit(funcend,0,0,lvalue_expr($1));
										}
			;

/*funcdef: 	FUNCTION 	{ 	if(function_counter < scope_count)
								function_counter = scope_count; 
							function_counter++; 
							funcname = Create_Function_Id(); 	
							state = Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block(funcname ,scope_count, yylineno); 
							if(state == -1) { error = 1; }
							$<Symbol>$=Lookup(mytable,funcname,scope_count);
							$<Symbol>$->iaddress=next_quad_label();
							emit(funcstart,lvalue_expr($<Symbol>$),0,0);
							push_to_stack(CurrScopeSpace()); //push Current_Scope_offset
							EnterScopeSpace();
							resetformalargsoffset();



						} L_PARENTHESIS { EnterScopeSpace(); scope_count++; resetfuctionlocalsoffset()} idlist R_PARENTHESIS { scope_count--; $$=Current_Scope_offset(); ExitScopeSpace();  } block { ExitScopeSpace(); function_counter--; }
			| FUNCTION ID 	{	if(function_counter < scope_count)
									function_counter = scope_count;
								function_counter++; 
								funcname = $2; 
								state = Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block(funcname, scope_count, yylineno); 
								if(state == -1) { error = 1; }
								$<Symbol>$=Lookup(mytable,funcname,scope_count);

							} L_PARENTHESIS { EnterScopeSpace(); scope_count++; resetfuctionlocalsoffset()} idlist R_PARENTHESIS { scope_count--; $$=Current_Scope_offset(); ExitScopeSpace();  } block { function_counter--; }
			;*/

const:	INTEGER 	{ 	Handle_const_integer(yylineno); 
						$$ = newexpr_constint($1);
					}
		| DOUBLE 	{ 	Handle_const_double(yylineno);
						$$ = newexpr_constdouble($1);
					}
		| STRING 	{ 	Handle_const_string(yylineno); 
						$$ = newexpr_conststring($1);
					}
		| NIL 		{ 	Handle_const_nil(yylineno);
						$$ = newexpr(nil_e);
		 			}
		| TRUE 		{ 	Handle_const_true(yylineno);
						$$ = newexpr_constbool('1');
					}
		| FALSE 	{ 	Handle_const_false(yylineno);
						$$ = newexpr_constbool('0');
					}
		;

idlist: ID idlist_1 	{	//printf("$$$333");
							state = Handle_idlist_id_idlist_1($1,funcName,scope_count,yylineno); 
							if(state == -1) { error = 1; }
							//printf("$$$333_ENd");

						}
		|				{  }
		;

idlist_1: 	COMMA idlist 	{ ;Handle_idlist_1_comma_idlist(yylineno); }
			| 				{  }
			;

//ifstmt:	IF L_PARENTHESIS expr R_PARENTHESIS stmt 			{ Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
//		|IF L_PARENTHESIS expr R_PARENTHESIS stmt ELSE stmt { Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(yylineno); }
//		;
ifprefix: 	IF L_PARENTHESIS expr R_PARENTHESIS 	{ $$ = Handle_ifprefix_if_l_parenthesis_expr_r_parenthesis($3,yylineno); }
			;

elseprefix: ELSE 									{ $$ = Handle_elseprefix_else(yylineno); }
			;

ifstmt: 	ifprefix stmt 						{ Handle_ifstmt_ifprefix_stmt($1,yylineno); }
		| 	ifprefix stmt elseprefix stmt 		{ Handle_ifstmt_ifprefix_stmt_elseprefix_stmt($1,$3,yylineno); }
		;

loopstart:	{ ++loopcounter; };
loopend: 	{ --loopcounter; };
loopstmt: 	loopstart stmt loopend 				{ $$ = $2; }

whilestart:	WHILE 								{ $$ = Handle_whilestart_while(yylineno); }
			;

whilecond:	L_PARENTHESIS expr R_PARENTHESIS 	{ $$ = Handle_whilecond_l_parenthesis_expr_r_parenthesis($2,yylineno); }
			;

whilestmt:	whilestart whilecond loopstmt 		{ $$ = $3; Handle_whilestmt_whilestart_whilecond_stmt($1,$2,$3,yylineno); }

/*whilestmt:	WHILE L_PARENTHESIS expr R_PARENTHESIS stmt 	{ Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(yylineno); }
			;*/


N:			{ $$ = next_quad_label(); emit_jump(jump, 0, 0, 0, 0); };
M:			{ $$ = next_quad_label(); };

forprefix:	FOR L_PARENTHESIS elist SEMICOLON M expr SEMICOLON 	{  }
			;

forstmt: 	forprefix N elist R_PARENTHESIS N loopstmt N 			{  }
			;
/*forstmt:	FOR L_PARENTHESIS elist SEMICOLON expr SEMICOLON elist R_PARENTHESIS stmt { Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(yylineno); }
			;*/

returnstmt:	RETURN expr SEMICOLON 	{ Handle_returnstmt_return_expr_semicolon($2,yylineno); }
			|RETURN SEMICOLON 		{ Handle_returnstmt_return_semicolon(yylineno); }
			;

%%



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
	
	if(error == 0)
		Print_Hash(mytable);
	else
		printf("Errors occured!\n");
	Print_Quads();	
	return 0;
}
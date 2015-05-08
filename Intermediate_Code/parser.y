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
	int for_flag = 0;
	int total_expr;
	int loopcounter = 0;
	int assign_counter = 0;
	char* id_val;
	char* funcName = NULL;
	label_list* break_list;
	label_list* cont_list;
	int loop_index = 0;
	int max_loop_index = 0;
	int table_flag;
	int relop = 0;
	unsigned start = 0;
	unsigned end = 0;


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
	struct forprefix *forVal;
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
%type <forVal> forprefix

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
%type <exprNode> objectdef
%type <ElistVar> indexed

%right		ASSIGN
%left		OR
%left		AND
%nonassoc	NOT
%nonassoc	EQ NOT_EQ
%nonassoc	GREATER_THAN GREATER_EQ LESS_THAN LESS_EQ
%left		PLUS MINUS
%left		MUL DIV MOD
%right		PLUS_PLUS MINUS_MINUS UMINUS
%left		DOT D_DOT
%left		L_BRACKET R_BRACKET
%left		L_PARENTHESIS R_PARENTHESIS
%left 		ELSE
%%

program:	stmt {loop_index = max_loop_index;}program
		|/* empty */
		;

break: 		BREAK SEMICOLON 						{ 	
														if(loopcounter > 0){
															break_list = label_list_insert(break_list,next_quad_label(),loop_index);
															emit_jump(jump, 0, 0, 0, 0); 
															Handle_stmt_break_semicolon(yylineno);
														}else{
															printf("Error at line: %d break is not in a loop\n",yylineno);
															error = 1;
														} 
													};
continue:	CONTINUE SEMICOLON 						{ 	
														if(loopcounter > 0){
															cont_list = label_list_insert(cont_list,next_quad_label(),loop_index); 
															emit_jump(jump, 0, 0, 0, 0); 
															Handle_stmt_continue_semicolon(yylineno); 
														}else{
															printf("Error at line: %d continue is not in a loop\n",yylineno);
															error = 1;
														}
													};

stmt:	expr SEMICOLON 								{ 	Handle_stmt_expr_semicolon(yylineno); assign_counter = 0;
														if(Handle_relop(relop,$1)!=NULL)
															relop = 0;
													}
		| ifstmt									{ Handle_stmt_ifstmt(yylineno); }
		| whilestmt									{ Handle_stmt_whilestmt(yylineno); Scan_jumps(0,start,end);}
		| forstmt									{ Handle_stmt_forstmt(yylineno); Scan_jumps(1,start,end);}
		| returnstmt								{ Handle_stmt_returnstmt(yylineno); }
		| break 									{$$ = $1;}
		| continue 									{$$ = $1;}
		| block										{ Handle_stmt_block(yylineno); }
		| funcdef									{ Handle_stmt_funcdef(yylineno); }
		| SEMICOLON 								{ Handle_stmt_semicolon(yylineno); }
		;

expr:	assignexpr									{ 	Handle_expr_assignexpr(yylineno);
														$$=$1;
													 }
		| expr PLUS expr 							{ $$ = Handle_expr_expr_plus_expr($1, $3, yylineno); }
		| expr MINUS expr 							{ $$ = Handle_expr_expr_minus_expr($1, $3, yylineno); }
		| expr MUL expr 							{ $$ = Handle_expr_expr_mul_expr($1, $3, yylineno); }
		| expr DIV expr 							{ $$ = Handle_expr_expr_div_expr($1, $3, yylineno); }
		| expr MOD expr 							{ $$ = Handle_expr_expr_mod_expr($1, $3, yylineno); }
		| expr EQ expr 								{ $$ = Handle_expr_expr_eq_expr($1, $3,yylineno); relop = 1;}
		| expr NOT_EQ expr  						{ $$ = Handle_expr_expr_not_eq_expr($1, $3,yylineno); relop = 1;}
		| expr LESS_THAN expr  						{ $$ = Handle_expr_expr_less_than_expr($1, $3,yylineno); relop = 1;}
		| expr GREATER_THAN expr  					{ $$ = Handle_expr_expr_greater_than_expr($1, $3,yylineno); relop = 1;}
		| expr LESS_EQ expr 						{ $$ = Handle_expr_expr_less_eq_expr($1, $3,yylineno); relop = 1;}
		| expr GREATER_EQ expr 						{ $$ = Handle_expr_expr_greater_eq_expr($1, $3,yylineno); relop = 1;}
		| expr AND M expr  							{ $$ = Handle_expr_expr_and_expr($1, $4,$3,yylineno); relop = 1;}
		| expr OR M expr 							{ $$ = Handle_expr_expr_or_expr($1, $4,$3,yylineno); relop = 1;}
		| term 										{ $$=$1;	Handle_expr_term(yylineno); }
		;


term: 	L_PARENTHESIS expr R_PARENTHESIS 			{ 
														expr *e = Handle_relop(relop,$2);
														if(e!=NULL)
															relop = 0;
														else
															e = $2;
														$$ = e;
														Handle_term_l_parenthesis_expr_r_parenthesis(yylineno); 
													}
		| MINUS expr %prec UMINUS						{ Handle_term_uminus_expr(yylineno); 
														checkuminus($2);
														$$ = newexpr(arithexpr_e);
														$$->sym = new_temp();
														emit(uminus,$2,0,$$);
													}
		| NOT expr 									{ $$ = Handle_term_not_expr($2,yylineno); 
														relop = 1;
													}
		| PLUS_PLUS lvalue 							{ state = Handle_term_plus_plus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } 
														if($2->type == tableitem_e){
															$$ = emit_iftableitem($2);
															emit(add,$$,newexpr_constint(1),$$);
															emit(tablesetelem,$2,$2->index,$$);
														}
														else{
															emit(add,$2,newexpr_constint(1),$2);
															$$ = newexpr(arithexpr_e);
															$$->sym = new_temp();
															emit(assign,$2,0,$$);
														}
													}
		| lvalue PLUS_PLUS							{ state = Handle_term_lvalue_plus_plus(yylineno,id_val); if(state == -1) { error = 1; }
														$$ = newexpr(var_e);
														$$->sym = new_temp();														

														if($1->type == tableitem_e){
															expr* val = emit_iftableitem($1);
															emit(assign,val,0,$$);
															emit(add,val,newexpr_constint(1),val);
															emit(tablesetelem,$1,$1->index,val);

														}
														else{
															emit(assign,$1,0,$$);
															emit(add,$1,newexpr_constint(1),$1);
														}
													}
		| MINUS_MINUS lvalue 						{ state = Handle_term_minus_minus_lvalue(yylineno,id_val); if(state == -1) { error = 1; } 
														if($2->type == tableitem_e){
															$$ = emit_iftableitem($2);
															emit(sub,$$,newexpr_constint(1),$$);
															emit(tablesetelem,$2,$2->index,$$);

														}
														else{
															emit(sub,$2,newexpr_constint(1),$2);
															$$ = newexpr(arithexpr_e);
															$$->sym = new_temp();
															emit(assign,$2,0,$$);
														}
													}
		| lvalue MINUS_MINUS 						{ state = Handle_term_lvalue_minus_minus(yylineno,id_val); if(state == -1) { error = 1; } 
														$$ = newexpr(var_e);
														$$->sym = new_temp();														

														if($1->type == tableitem_e){
															expr* val = emit_iftableitem($1);
															emit(assign,val,0,$$);
															emit(sub,val,newexpr_constint(1),val);
															emit(tablesetelem,$1,$1->index,val);

														}
														else{
															emit(assign,$1,0,$$);
															emit(sub,$1,newexpr_constint(1),$1);
														}
													}
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
																if(istempname($1->sym->name)){
																	emit(assign,$1,(expr*)0,$1);
																}
																else{
																	expr *e = Handle_relop(relop,$3);
																	if(e!=NULL){
																		relop = 0;
																		emit(assign, e, (expr*)0, $1);
																	}
																	else{
																		emit(assign,$3,(expr*)0,$1);	
																		//if(assign_counter > 1){
																			$$=newexpr(assignexpr_e);
																			$$->sym=new_temp();
																			emit(assign,$1,(expr*)0,$$);
																		//}
																	}
																}
															}
															else{
																emit(assign,$3,(expr*)0,$$);
															}

														}
	}
			;	

primary:	lvalue 									{ 	
														Handle_primary_lvalue(yylineno); 
														$$=emit_iftableitem($1);
													}
			| call 									{ Handle_primary_call(yylineno); }
			| objectdef 							{ Handle_primary_objectdef(yylineno); }
			| L_PARENTHESIS funcdef R_PARENTHESIS 	{ 
														$$ = newexpr(programfunc_e);
														$$->sym = $2;
														Handle_primary_l_parenthesis_funcdef_r_parenthesis(yylineno); 
													}
			| const 								{ 	Handle_primary_const(yylineno);
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

member:		lvalue DOT ID 							{ 		Handle_member_lvalue_dot_id(yylineno);
															$1 = emit_iftableitem($1);
															$$ = newexpr(tableitem_e);
															$$->sym = $1->sym;
															$$->index = newexpr_conststring($3);
													 }

			| lvalue L_BRACKET expr R_BRACKET 		{ 		Handle_member_lvalue_l_bracket_expr_r_bracket(yylineno); 
															$1 = emit_iftableitem($1);
															$$ = newexpr(tableitem_e);
															$$->sym = $1->sym;
															$$->index = $3;

													}
			| call DOT ID 							{ tmp_state = 0; Handle_member_call_dot_id(yylineno); }
			| call L_BRACKET expr R_BRACKET 		{ Handle_member_call_l_bracket_expr_r_bracket(yylineno); }
			;

call: 		call L_PARENTHESIS elist R_PARENTHESIS 		{ 	Handle_call_call_l_parenthesis_elist_r_parenthesis(yylineno); 
															$$ = make_call($1,$3);
														}
			| lvalue callsuffix 						{ 	Handle_call_lvalue_callsuffix(yylineno);
															if($2->method==1){
																expr* self = $1;
																															
																$1 = emit_iftableitem(member_item(self,$2->name));
																push_elist(self,0);

															}
															$$ = make_call($1,$2->elist);
														}
			| L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS elist R_PARENTHESIS 	{ 	Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(yylineno); 
																							expr* func = newexpr(programfunc_e);
																							func->sym = $2;
																							$$ = make_call(func,$5);
																						}
			;

callsuffix: normcall 		{ Handle_callsuffix_normcall(yylineno); $$=$1; }
			| methodcall 	{ Handle_callsuffix_methodcall(yylineno); $$=$1; }
			;

normcall: 	L_PARENTHESIS elist R_PARENTHESIS 		{ 	Handle_normcall_l_parenthesis_elist_r_parenthesis(yylineno);
 														$$ = malloc(sizeof(calls));
														$$->elist = $2;
														$$->method = 0;
														$$->name = NULL;
													}
			;

methodcall: D_DOT ID L_PARENTHESIS elist R_PARENTHESIS 	{ 	Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(yylineno); 
															$$ = malloc(sizeof(calls));
															$$->elist = $4;
															$$->method = 1;
															$$->name = strdup($2);
														}
			;

elist: 		expr  				{ 
									Handle_elist_expr(yylineno);
									if(for_flag == 0){
										if(table_flag == 1){
											push_elist($1,1);
											table_flag = 0;
											printf("------%d",$1->intConst );
										}
										else{
											push_elist($1,0);
											printf("------%d",$1->intConst );
										}
										total_expr++;
										$$=top;
									}

								}
			| elist COMMA expr 	{ 	Handle_elist_elist_comma_expr(yylineno); 
										if(table_flag == 1){
											push_elist($3,1);
											table_flag = 0;
											printf("------%d",$3->intConst );
										}
										else{
											push_elist($3,0);
											printf("------%d",$3->intConst );
										}
										total_expr++;
										$$=top;
									
								}
			|
			;



objectdef: 	L_BRACKET{table_flag=1;push_total_expr_stack(total_expr);total_expr=0;} elist R_BRACKET { Handle_objectdef_l_bracket_elist_r_bracket(yylineno); 
												expr* t = newexpr(newtable_e);
												t->sym = new_temp();
												emit(tablecreate,0,0,t);
												int i=0;
												elist_l* tmp=top;
												elist_l* tmp1=top;
												elist_l* temporary;

												while(tmp!=NULL){
													printf("LIST:::::%d",tmp->arg->intConst);
													printf("del:::::\t%d\n",tmp->del);
													tmp=tmp->next;

												}

												while((tmp = pop_elist())!=NULL){
													printf("POP:::::%d\n",tmp->arg->intConst);
													//push_elist_1 (tmp->arg,tmp->del);

													

													if(tmp->del == 1){

														emit(tablesetelem,t,newexpr_constint(--total_expr),tmp->arg);

														break;
													}
													else{
														//printf("GG");
														emit(tablesetelem,t,newexpr_constint(--total_expr),tmp->arg);
													}


												}
												/*while((tmp = pop_elist_1())!=NULL){
													printf("POP_1:::::%d\n",tmp->arg->intConst);
						

													if(tmp->del == 1){

														emit(tablesetelem,t,newexpr_constint(i++),tmp->arg);

														//break;
													}
													else{
														//printf("GG");
														emit(tablesetelem,t,newexpr_constint(i++),tmp->arg);
													}
													

												}*/



												$$ = t;
												total_expr=pop_total_expr_stack();
											}


			| L_BRACKET {table_flag = 1;} indexed R_BRACKET { Handle_objectdef_l_bracket_indexed_r_bracket(yylineno);
												expr* t = newexpr(newtable_e);
												t->sym = new_temp();
												emit(tablecreate,0,0,t);
												int i=0;
												elist_l* tmp;
												elist_l* tmp2;
												while((tmp = pop_elist())!=NULL  && (tmp2 = pop_elist())!=NULL){
													emit(tablesetelem,t,tmp->arg,tmp2->arg);
												}
												$$ = t;
											}
			;

indexed: 	indexedelem  				{ Handle_indexed_indexedelem(yylineno); }
			| indexed COMMA indexedelem { Handle_indexed_indexed_comma_indexedelem(yylineno); }
			;



indexedelem: 	L_BRACE expr COLON expr R_BRACE 	{ Handle_indexedelem_l_brace_expr_colon_expr_r_brace(yylineno); push_elist($2,0); push_elist($4,0);}
				;

block: 		L_BRACE { EnterScopeSpace(); scope_count++;} block_1 R_BRACE 		{ 	Hide(mytable,scope_count--); 
																					Handle_block_l_brace_block_1_r_brace(yylineno); 
																					ExitScopeSpace();
																				}
			;

block_1: 	stmt block_1 	{ Handle_block_1_stmt_block_1(yylineno); }
			| 				{  }
			;


funcname:	ID 				{ $$=$1; }		
			| 				{ $$=Create_Function_Id(); }
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

funcblockstart: { push_loopcounter_stack(loopcounter); loopcounter = 0; };
funcblockend: 	{ loopcounter = pop_loopcounter_stack(); };

funcbody:	funcblockstart block funcblockend { $$=CurrScopeOffset(); ExitScopeSpace(); function_counter--; }
			;

funcdef:  funcprefix funcargs funcbody  {	
											ExitScopeSpace();
											$1->totallocals=$3;
											unsigned old_offset=pop_from_stack();
											restorecurrscopeoffset(old_offset);
											$$=$1;
											emit(funcend,0,0,lvalue_expr($1));
										}
			;

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

idlist: ID idlist_1 	{	
							state = Handle_idlist_id_idlist_1($1,funcName,scope_count,yylineno); 
							if(state == -1) { error = 1; }
						}
		|				{  }
		;

idlist_1: 	COMMA idlist 	{ ;Handle_idlist_1_comma_idlist(yylineno); }
			| 				{  }
			;

ifprefix: 	IF L_PARENTHESIS expr R_PARENTHESIS 	{ 
														expr *e = Handle_relop(relop,$3);
														if(e!=NULL)
															relop = 0;
														else
															e = $3;
														$$ = Handle_ifprefix_if_l_parenthesis_expr_r_parenthesis(e,yylineno); 

														
}
			;

elseprefix: ELSE 									{ $$ = Handle_elseprefix_else(yylineno); }
			;

ifstmt: 	ifprefix stmt 						{ 	Handle_ifstmt_ifprefix_stmt($1,yylineno); }
		| 	ifprefix stmt elseprefix stmt 		{ Handle_ifstmt_ifprefix_stmt_elseprefix_stmt($1,$3,yylineno); }
		;

loopstart:	{ ++loopcounter; loop_index++; if(max_loop_index<loop_index){max_loop_index = loop_index;} push_loopindex_stack(loop_index);};
loopend: 	{ --loopcounter; loop_index = pop_loopindex_stack();};
loopstmt: 	loopstart stmt loopend 				{ $$ = $2; }

whilestart:	WHILE 								{ $$ = Handle_whilestart_while(yylineno); }
			;

whilecond:	L_PARENTHESIS expr R_PARENTHESIS 	{ 
													start = next_quad_label();
													push_start_stack(start);
													expr *e = Handle_relop(relop,$2);
													if(e!=NULL)
														relop = 0;
													else
														e = $2;
													$$ = Handle_whilecond_l_parenthesis_expr_r_parenthesis(e,yylineno); 
												}
			;

whilestmt:	whilestart whilecond loopstmt 		{ $$ = $3; Handle_whilestmt_whilestart_whilecond_stmt($1,$2,$3,loop_index,yylineno); end = next_quad_label(); push_stop_stack(end);start=pop_start_stack(); end = pop_stop_stack(); }


N:			{ $$ = next_quad_label(); emit_jump(jump, 0, 0, 0, 0); };
M:			{ $$ = next_quad_label(); };

forprefix:	FOR {for_flag = 1;} L_PARENTHESIS elist SEMICOLON M expr SEMICOLON 	{ 
																	start = next_quad_label();
																	push_start_stack(start);
																	expr *e = Handle_relop(relop,$7);
																	if(e!=NULL)
																		relop = 0;
																	else
																		e = $7;
																	$$ = malloc(sizeof(struct forprefix));
																	$$->test = $6;
																	$$->enter = next_quad_label();
																	emit(if_eq,e,newexpr_constbool('1'),0);
																}
			;

forstmt: 	forprefix N elist R_PARENTHESIS {for_flag = 0;} N loopstmt N 			{ 	Handle_forstmt_forprefix_N_elist_r_parenthesis_N_loopstmt_N($1,$2,$6,$7,$8,loop_index,yylineno);
																						end = next_quad_label();	
																						push_stop_stack(end);
																						start=pop_start_stack(); end = pop_stop_stack(); 
 																	}
			;

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
	
	if(error == 0){
		Print_Hash(mytable);
		Print_Quads();
	}else
		printf("Errors occured!\n");	
	return 0;
}
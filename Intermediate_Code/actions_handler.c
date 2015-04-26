#include "actions_handler.h"
#include "symtable.h"
#include <stdio.h>
#include <string.h>

void Handle_stmt_expr_semicolon(int lineNo){
	printf("Line: %d \tstmt: expr;\n", lineNo);
}
void Handle_stmt_ifstmt(int lineNo){
	printf("Line: %d \tstmt: ifstmt\n", lineNo);
}
void Handle_stmt_whilestmt(int lineNo){
	printf("Line: %d \tstmt: whilestmt\n", lineNo);
}
void Handle_stmt_forstmt(int lineNo){
	printf("Line: %d \tstmt: forstmt\n", lineNo);
}
void Handle_stmt_returnstmt(int lineNo){
	printf("Line: %d \tstmt: returnstmt\n", lineNo);
}
void Handle_stmt_break_semicolon(int lineNo){
	printf("Line: %d \tstmt: break;\n", lineNo);
}
void Handle_stmt_continue_semicolon(int lineNo){
	printf("Line: %d \tstmt: continue;\n", lineNo);
}
void Handle_stmt_block(int lineNo){
	printf("Line: %d \tstmt: block\n", lineNo);
}
void Handle_stmt_funcdef(int lineNo){
	printf("Line: %d \tstmt: funcdef\n", lineNo);
}
void Handle_stmt_semicolon(int lineNo){
	printf("Line: %d \tstmt: ;\n", lineNo);
}

void Handle_expr_assignexpr(int lineNo){
	printf("Line: %d \texpr: assignexpr\n", lineNo);
}
void Handle_expr_expr_plus_expr(int lineNo){
	printf("Line: %d \texpr: expr + expr \n", lineNo);
}
void Handle_expr_expr_minus_expr(int lineNo){
	printf("Line: %d \texpr: expr - expr \n", lineNo);
}
void Handle_expr_expr_mul_expr(int lineNo){
	printf("Line: %d \texpr: expr * expr \n", lineNo);
}
void Handle_expr_expr_div_expr(int lineNo){
	printf("Line: %d \texpr: expr / expr \n", lineNo);
}
void Handle_expr_expr_mod_expr(int lineNo){
	printf("Line: %d \texpr: expr %% expr \n", lineNo);
}
void Handle_expr_expr_greater_than_expr(int lineNo){
	printf("Line: %d \texpr: expr > expr \n", lineNo);
}
void Handle_expr_expr_less_than_expr(int lineNo){
	printf("Line: %d \texpr: expr < expr \n", lineNo);
}
void Handle_expr_expr_greater_eq_expr(int lineNo){
	printf("Line: %d \texpr: expr >= expr \n", lineNo);
}
void Handle_expr_expr_less_eq_expr(int lineNo){
	printf("Line: %d \texpr: expr <= expr \n", lineNo);
}
void Handle_expr_expr_eq_expr(int lineNo){
	printf("Line: %d \texpr: expr == expr \n", lineNo);
}
void Handle_expr_expr_not_eq_expr(int lineNo){
	printf("Line: %d \texpr: expr != expr \n", lineNo);
}
void Handle_expr_expr_and_expr(int lineNo){
	printf("Line: %d \texpr: expr and expr \n", lineNo);
}
void Handle_expr_expr_or_expr(int lineNo){
	printf("Line: %d \texpr: expr or expr \n", lineNo);
}
void Handle_expr_term(int lineNo){
	printf("Line: %d \texpr: term\n", lineNo);
}

void Handle_term_l_parenthesis_expr_r_parenthesis(int lineNo){
	printf("Line: %d \tterm: (term)\n", lineNo);
}
void Handle_term_uminus_expr(int lineNo){
	printf("Line: %d \tterm: -expr\n", lineNo);
}
void Handle_term_not_expr(int lineNo){
	printf("Line: %d \tterm: not expr\n", lineNo);
}
int Handle_term_plus_plus_lvalue(int lineNo, char* id_val){
	printf("Line: %d \tterm: ++lvalue\n", lineNo);
	if(id_val != NULL)
	{
		symbol sym = Lookup(mytable,id_val,0);
		if(sym->type == libraryfunc_s){
			printf("Error at line: %d cannot increment a library function\n",lineNo);
			return -1;
		}
	}
	return 0;
}
int Handle_term_lvalue_plus_plus(int lineNo, char* id_val){
	printf("Line: %d \tterm: lvalue++\n", lineNo);
	if(id_val != NULL)
	{
		symbol sym = Lookup(mytable,id_val,0);
		if(sym->type == libraryfunc_s){
			printf("Error at line: %d cannot increment a library function\n",lineNo);
			return -1;
		}
	}
	return 0;
}
int Handle_term_minus_minus_lvalue(int lineNo, char* id_val){
	printf("Line: %d \tterm: --lvalue\n", lineNo);
	if(id_val != NULL)
	{
		symbol sym = Lookup(mytable,id_val,0);
		if(sym->type == libraryfunc_s){
			printf("Error at line: %d cannot decrement a library function\n",lineNo);
			return -1;
		}
	}
	return 0;
}
int Handle_term_lvalue_minus_minus(int lineNo, char* id_val){
	printf("Line: %d \tterm: lvalue--\n", lineNo);
	if(id_val != NULL)
	{
		symbol sym = Lookup(mytable,id_val,0);
		if(sym->type == libraryfunc_s){
			printf("Error at line: %d cannot decrement a library function\n",lineNo);
			return -1;
		}
	}
	return 0;
}
void Handle_term_primary(int lineNo){
	printf("Line: %d \tterm: primary\n", lineNo);
}

int Handle_assignexpr_lvalue_assign_expr(int lineNo, int state){
	printf("Line: %d \tassignexpr: expr lvalue = expr\n", lineNo);
	if(state == -2){
		printf("Error at line: %d trying to assign to Library Function\n",lineNo );
		return -1;
	}else if(state == -3){
		printf("Error at line: %d trying to assign to Program Function\n",lineNo );
		return -1;
	}else
		return 0;
}

void Handle_primary_lvalue(int lineNo){
	printf("Line: %d \tprimary: lvalue\n", lineNo);
}
void Handle_primary_call(int lineNo){
	printf("Line: %d \tprimary: call\n", lineNo);
}
void Handle_primary_objectdef(int lineNo){
	printf("Line: %d \tprimary: objectdef\n", lineNo);
}
void Handle_primary_l_parenthesis_funcdef_r_parenthesis(int lineNo){
	printf("Line: %d \tprimary: (funcdef)\n", lineNo);
}
void Handle_primary_const(int lineNo){
	printf("Line: %d \tprimary: const\n", lineNo);
}

int Handle_lvalue_id(char* name, int scope, int lineNo, int function_counter){
	printf("Line: %d \tlvalue: id\n", lineNo);
	int i=scope;
	int j=scope;
	int found = 0;
	int is_lib_func = 0;
	int is_program_func = 0;
	int is_global_var = 0;
	int user_function_found = 0;
	symbol temp;
	symbol tmp = Lookup(mytable,name,0);
	if(tmp != NULL && tmp->type == libraryfunc_s)
		is_lib_func = 1;
	else if(tmp != NULL && tmp->type == programfunc_s)
		is_program_func = 1;
	else if(tmp != NULL && tmp->type == var_s)
		is_global_var = 1;
	symbol parse;

	while(j>=1){
		temp = Lookup(mytable,name,j);
		if(temp != NULL && temp->type == programfunc_s)
			user_function_found = 1;
		j--;
	}

	while(i>=1){

		parse = Lookup(mytable,name,i);
		if(parse!=NULL){
			if(parse->scope == scope)
			{
				/* do nothing */
				return 0;
			}
			else if(parse->scope < scope && function_counter > 0 && is_lib_func == 0 && parse->type == var_s && user_function_found == 0)
			{
				printf("Error at line: %d variable cannot access variable at line %d\n",lineNo,parse->line);
				return -1;
			}
			else if(parse->scope < scope && function_counter == 0)
			{
				/* Do Nothing */
				return 0;
			}
			found = 1;
		}
		i--;
	}

	if(found == 0 && is_lib_func == 0 && is_program_func == 0 && is_global_var == 0){
		Insert_to_Hash(mytable,name,var_s,scope,lineNo);
		IncCurrScopeOffset();
	}
	if(is_lib_func == 1)
		return -2;
	else if(is_program_func == 1)
		return -3;
	else
		return 0;
}

int Handle_lvalue_local_id(char* name, int scope, int lineNo){
	printf("Line: %d \tlvalue: local id\n", lineNo);
	symbol tmp = Lookup(mytable,name,scope);
	if(tmp == NULL){
		if(scope > 0){
			Insert_to_Hash(mytable, name, var_s , scope, lineNo);
			IncCurrScopeOffset();
		}
	}
	tmp = Lookup(mytable,name,0);
	if(tmp != NULL && tmp->type == libraryfunc_s && scope > 0){
		printf("Error at line: %d name of variable is a library function\n",lineNo);
		return -1;
	}
	return 0;
}

int Handle_lvalue_d_colon_id(char* name, int lineNo){
	printf("Line: %d \tlvalue: ::id\n", lineNo);
	symbol tmp = Lookup(mytable,name,0);
	if(tmp == NULL){
		printf("Error at line: %d name of variable isn't a global variable\n",lineNo);
		return -1;
	}
	return 0;
}
void Handle_lvalue_member(int lineNo){
	printf("Line: %d \tlvalue: member\n", lineNo);
}

void Handle_member_lvalue_dot_id(int lineNo){
	printf("Line: %d \tmember: lvalue.id\n", lineNo);
}
void Handle_member_lvalue_l_bracket_expr_r_bracket(int lineNo){
	printf("Line: %d \tmember: lvalue[expr]\n", lineNo);
}
void Handle_member_call_dot_id(int lineNo){
	printf("Line: %d \tmember: call.id\n", lineNo);
}
void Handle_member_call_l_bracket_expr_r_bracket(int lineNo){
	printf("Line: %d \tmember: call[expr]\n", lineNo);
}

void Handle_call_call_l_parenthesis_elist_r_parenthesis(int lineNo){
	printf("Line: %d \tcall: call(elist)\n", lineNo);
}
void Handle_call_lvalue_callsuffix(int lineNo){
	printf("Line: %d \tcall: lvalue callsuffix\n", lineNo);
}
void Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(int lineNo){
	printf("Line: %d \tcall: (funcdef)(elist)\n", lineNo);
}

void Handle_callsuffix_normcall(int lineNo){
	printf("Line: %d \tcallsuffix: normcall\n", lineNo);
}
void Handle_callsuffix_methodcall(int lineNo){
	printf("Line: %d \tcallsuffix: methodcall\n", lineNo);
}

void Handle_normcall_l_parenthesis_elist_r_parenthesis(int lineNo){
	printf("Line: %d \tnormcall: (elist)\n", lineNo);
}
void Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(int lineNo){
	printf("Line: %d \tmethodcall: ..id(elist)\n", lineNo);
}

void Handle_elist_expr(int lineNo){
	printf("Line: %d \telist: expr\n", lineNo);
}
void Handle_elist_elist_comma_expr(int lineNo){
	printf("Line: %d \telist: elist , expr\n", lineNo);
}

void Handle_objectdef_l_bracket_elist_r_bracket(int lineNo){
	printf("Line: %d \tobjectdef: [elist]\n", lineNo);
}
void Handle_objectdef_l_bracket_indexed_r_bracket(int lineNo){
	printf("Line: %d \tobjectdef: [indexed]\n", lineNo);
}

void Handle_indexed_indexedelem(int lineNo){
	printf("Line: %d \tindexed: indexedelem\n", lineNo);
}
void Handle_indexed_indexed_comma_indexedelem(int lineNo){
	printf("Line: %d \tindexed: indexed , indexedelem\n", lineNo);
}
void Handle_indexedelem_l_brace_expr_colon_expr_r_brace(int lineNo){
	printf("Line: %d \tindexedelem: {expr: exprexpr}\n", lineNo);
}

void Handle_block_l_brace_block_1_r_brace(int lineNo){
	printf("Line: %d \tblock: {block_1}\n", lineNo);
}
void Handle_block_1_stmt_block_1(int lineNo){
	printf("Line: %d \tblock_1: stmt block_1\n", lineNo);
}

int Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block(char* name, int scope, int lineNo){
	printf("Line: %d \tfuncdef: function id(idlist) block\n", lineNo);
	symbol tmp = Lookup(mytable,name,scope);
	if(tmp != NULL){
		if(tmp->type == programfunc_s){
			printf("Error at line: %d name of function is a user function\n",lineNo);
			return -1;
		}else if(tmp->type == var_s){
			printf("Error at line: %d name of function is a %s variable\n",lineNo,tmp->type);
			return -1;
		}
	}
	tmp = Lookup(mytable,name,0);
	if(tmp != NULL && tmp->type == libraryfunc_s){
		printf("Error at line: %d name of function is a library function\n",lineNo);
		return -1;
	}
	Insert_to_Hash(mytable, name, programfunc_s , scope, lineNo);
	return 0;
}

int Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block(char* name, int scope, int lineNo){
	printf("Line: %d \tfuncdef: function (idlist) block\n", lineNo);
	Insert_to_Hash(mytable, name, programfunc_s, scope, lineNo);
	return 0;
}

void Handle_const_integer(int lineNo){
	printf("Line: %d \tconst: integer\n", lineNo);
}
void Handle_const_double(int lineNo){
	printf("Line: %d \tconst: double\n", lineNo);
}
void Handle_const_string(int lineNo){
	printf("Line: %d \tconst: string\n", lineNo);
}
void Handle_const_nil(int lineNo){
	printf("Line: %d \tconst: nil\n", lineNo);
}
void Handle_const_true(int lineNo){
	printf("Line: %d \tconst: true\n", lineNo);
}
void Handle_const_false(int lineNo){
	printf("Line: %d \tconst: false\n", lineNo);
}

int Handle_idlist_id_idlist_1(char* name, char* functionName, int scope, int lineNo){
	printf("Line: %d \tidlist: id idlist_1\n", lineNo);
	symbol tmp = Lookup(mytable,name,0);
	if(tmp != NULL && tmp->type == libraryfunc_s){
		printf("Error at line: %d name of formal argument is a library function\n",lineNo);
		return -1;
	}
	tmp = Lookup(mytable,functionName, scope - 1);
	if(tmp != NULL)
		tmp->args = Insert_args(tmp, name);
	tmp = Lookup(mytable,name, scope);
	if(tmp != NULL){
		printf("Error at line: %d name of formal argumet is already declared\n",lineNo);
		return -1;
	}
	else
		Insert_to_Hash(mytable, name, var_s, scope, lineNo);
	return 0;
}
void Handle_idlist_1_comma_idlist(int lineNo){
	printf("Line: %d \tidlist_1: ,idlist\n", lineNo);
}

void Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(int lineNo){
	printf("Line: %d \tifstmt: if (expr) stmt\n", lineNo);
}
void Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(int lineNo){
	printf("Line: %d \tifstmt: if (expr) stmt else stmt\n", lineNo);
}

void Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(int lineNo){
	printf("Line: %d \twhilestmt: while (expr) stmt\n", lineNo);
}

void Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(int lineNo){
	printf("Line: %d \tforstmt: for (elist; expr; elist) stmt\n", lineNo);
}

void Handle_returnstmt_return_expr_semicolon(int lineNo){
	printf("Line: %d \treturnstmt: return expr;\n", lineNo);
}
void Handle_returnstmt_return_semicolon(int lineNo){
	printf("Line: %d \treturnstmt: return;\n", lineNo);
}
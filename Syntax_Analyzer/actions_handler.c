#include "actions_handler.h"
#include "symtable.h"
#include <stdio.h>
#include <string.h>

char* lib_functions[12] = { "print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin" };

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
int Handle_expr_expr_plus_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr + expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return exp1 + exp2;
}
int Handle_expr_expr_minus_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr - expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return exp1 - exp2;
}
int Handle_expr_expr_mul_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr * expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return exp1 * exp2;
}
int Handle_expr_expr_div_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr / expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return exp1 / exp2;
}
int Handle_expr_expr_mod_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr %% expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return exp1 % exp2;
}
int Handle_expr_expr_greater_than_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr > expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 > exp2)?1:0;
}
int Handle_expr_expr_less_than_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr < expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 < exp2)?1:0;
}
int Handle_expr_expr_greater_eq_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr >= expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 >= exp2)?1:0;
}
int Handle_expr_expr_less_eq_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr <= expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 <= exp2)?1:0;
}
int Handle_expr_expr_eq_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr == expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 == exp2)?1:0;
}
int Handle_expr_expr_not_eq_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr != expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 != exp2)?1:0;
}
int Handle_expr_expr_and_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr and expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 && exp2)?1:0;
}
int Handle_expr_expr_or_expr(int exp1,int exp2,int lineNo){
	printf("Line: %d \texpr: expr or expr (Val1:%d , Val2:%d)\n", lineNo, exp1, exp2);
	return (exp1 || exp2)?1:0;
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
void Handle_term_plus_plus_lvalue(int lineNo){
	printf("Line: %d \tterm: ++lvalue\n", lineNo);
}
void Handle_term_lvalue_plus_plus(int lineNo){
	printf("Line: %d \tterm: lvalue++\n", lineNo);
}
void Handle_term_minus_minus_lvalue(int lineNo){
	printf("Line: %d \tterm: --lvalue\n", lineNo);
}
void Handle_term_lvalue_minus_minus(int lineNo){
	printf("Line: %d \tterm: lvalue--\n", lineNo);
}
void Handle_term_primary(int lineNo){
	printf("Line: %d \tterm: primary\n", lineNo);
}

void Handle_assignexpr_lvalue_assign_expr(int lineNo){
	printf("Line: %d \tassignexpr: expr lvalue = expr\n", lineNo);
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

void Handle_lvalue_id(char* name, int scope, int lineNo, int off){
	printf("Line: %d \tlvalue: id\n", lineNo);
	int i = 0, error_flag = 0;
	for(i = 0; i < 12; i++)
		if(strcmp(name,lib_functions[i]) == 0)
			error_flag = 1;
	node_t tmp = Lookup(mytable,name, scope);

	if(tmp != NULL && tmp->var_type == NULL && tmp->scope == scope)
		printf("Error at line: %d name of variable is a user function\n",lineNo);
	else if(tmp != NULL && tmp->func_type == NULL && tmp->scope == scope)
		printf("Error at line: %d name of variable is a %s\n",lineNo, tmp->var_type);
	if(tmp == NULL && error_flag == 0 && scope == 0)
		Insert_Var(mytable, name, "GLOBAL" , scope, lineNo);
	else if(tmp == NULL && error_flag == 0 && scope > 0)
		Insert_Var(mytable, name, "LOCAL" , scope, lineNo);
	else if(error_flag == 1)
		printf("Error at line: %d name of variable is a library function\n",lineNo);
}
void Handle_lvalue_local_id(char* name, int scope, int lineNo){
	printf("Line: %d \tlvalue: local id\n", lineNo);
	int i = 0, error_flag = 0;
	for(i = 0; i < 12; i++)
		if(strcmp(name,lib_functions[i]) == 0)
			error_flag = 1;
	if(error_flag == 0){
		node_t tmp = Lookup(mytable,name, scope);
		if(tmp != NULL && tmp->scope == scope)
			printf("");
		else
			Insert_Var(mytable, name, "LOCAL" , scope, lineNo);
	}
	else
		printf("Error at line: %d name of variable is a library function\n",lineNo);
}
void Handle_lvalue_d_colon_id(char* name, int lineNo){
	printf("Line: %d \tlvalue: ::id\n", lineNo);
	int i = 0, error_flag = 0;
	for(i = 0; i < 12; i++)
		if(strcmp(name,lib_functions[i]) == 0)
			error_flag = 1;
	if(error_flag == 0){
		node_t tmp = Lookup(mytable,name, 0);
		if(tmp != NULL && tmp->scope == 0)
			printf("");
		else
			printf("Error at line: %d name of variable isn't a global variable\n",lineNo);
	}
	else
		printf("Error at line: %d name of variable is a library function\n",lineNo);
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

int Handle_block_l_brace_block_1_r_brace(int scope, int flag, int lineNo){
	printf("Line: %d \tblock: {block_1}\n", lineNo);
}
void Handle_block_1_stmt_block_1(int lineNo){
	printf("Line: %d \tblock_1: stmt block_1\n", lineNo);
}

void Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block(char* name, int scope, int lineNo){
	printf("Line: %d \tfuncdef: function id(idlist) block\n", lineNo);
	int i = 0, error_flag = 0;
	for(i = 0; i < 12; i++)
		if(strcmp(name,lib_functions[i]) == 0)
			error_flag = 1;
	node_t tmp = Lookup(mytable,name, scope);
	if(tmp != NULL && tmp->hiden == 0)
		error_flag = 2;
	if(error_flag == 0){
		Insert_Func(mytable, name, "USER DEFINED" , scope, lineNo, 0);
	}
	else if(error_flag == 1)
		printf("Error at line: %d name of function is a library function\n",lineNo);
	else if(error_flag == 2)
		printf("Error at line: %d name of function is a %s variable\n",lineNo, tmp->var_type);
}
char* Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block(char* name, int scope, int lineNo){
	printf("Line: %d \tfuncdef: function (idlist) block\n", lineNo);
		Insert_Func(mytable, name, "USER DEFINED", scope, lineNo, 0);

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

void Handle_idlist_id_idlist_1(char* name, char* functionName, int scope, int lineNo){
	printf("Line: %d \tidlist: id idlist_1\n", lineNo);
	node_t tmp = Lookup(mytable,functionName, scope);
	if(tmp != NULL){
		tmp->args = Insert_args(tmp, name);
	}

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
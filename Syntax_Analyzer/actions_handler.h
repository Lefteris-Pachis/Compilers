#ifndef ACTIONS_HANDLER_H
#define ACTIONS_HANDLER_H

void Handle_stmt_expr_semicolon(int lineNo);
void Handle_stmt_ifstmt(int lineNo);
void Handle_stmt_whilestmt(int lineNo);
void Handle_stmt_forstmt(int lineNo);
void Handle_stmt_returnstmt(int lineNo);
void Handle_stmt_break_semicolon(int lineNo);
void Handle_stmt_continue_semicolon(int lineNo);
void Handle_stmt_block(int lineNo);
void Handle_stmt_funcdef(int lineNo);

void Handle_expr_assignexpr(int lineNo);
void Handle_expr_expr_plus_expr(int lineNo);
void Handle_expr_expr_minus_expr(int lineNo);
void Handle_expr_expr_mul_expr(int lineNo);
void Handle_expr_expr_div_expr(int lineNo);
void Handle_expr_expr_mod_expr(int lineNo);
void Handle_expr_expr_greater_than_expr(int lineNo);
void Handle_expr_expr_less_than_expr(int lineNo);
void Handle_expr_expr_greater_eq_expr(int lineNo);
void Handle_expr_expr_less_eq_expr(int lineNo);
void Handle_expr_expr_eq_expr(int lineNo);
void Handle_expr_expr_not_eq_expr(int lineNo);
void Handle_expr_expr_and_expr(int lineNo);
void Handle_expr_expr_or_expr(int lineNo);
void Handle_expr_term(int lineNo);

void Handle_term_l_parenthesis_expr_r_parenthesis(int lineNo);
void Handle_term_uminus_expr(int lineNo);
void Handle_term_not_expr(int lineNo);
void Handle_term_plus_plus_lvalue(int lineNo);
void Handle_term_lvalue_plus_plus(int lineNo);
void Handle_term_minus_minus_lvalue(int lineNo);
void Handle_term_lvalue_minus_minus(int lineNo);
void Handle_term_primary(int lineNo);

void Handle_assignexpr_lvalue_assign_expr(int lineNo);

void Handle_primary_lvalue(int lineNo);
void Handle_primary_call(int lineNo);
void Handle_primary_objectdef(int lineNo);
void Handle_primary_l_parenthesis_funcdef_r_parenthesis(int lineNo);
void Handle_primary_const(int lineNo);

void Handle_lvalue_id(char* name, int scope, int lineNo, int off);
void Handle_lvalue_local_id(char* name, int scope, int lineNo);
void Handle_lvalue_d_colon_id(char* name, int lineNo);
void Handle_lvalue_member(int lineNo);

void Handle_member_lvalue_dot_id(int lineNo);
void Handle_member_lvalue_l_bracket_expr_r_bracket(int lineNo);
void Handle_member_call_dot_id(int lineNo);
void Handle_member_call_l_bracket_expr_r_bracket(int lineNo);

void Handle_call_call_l_parenthesis_elist_r_parenthesis(int lineNo);
void Handle_call_lvalue_callsuffix(int lineNo);
void Handle_call_l_parenthesis_funcdef_r_parenthesis_l_parenthesis_elist_r_parenthesis(int lineNo);

void Handle_callsuffix_normcall(int lineNo);
void Handle_callsuffix_methodcall(int lineNo);

void Handle_normcall_l_parenthesis_elist_r_parenthesis(int lineNo);
void Handle_methodcall_d_dot_id_l_parenthesis_elist_r_parenthesis(int lineNo);

void Handle_elist_expr_elist1(int lineNo);
void Handle_elist1_comma_elist(int lineNo);

void Handle_objectdef_l_bracket_objectdef1_r_bracket(int lineNo);
void Handle_objectdef1_elist(int lineNo);
void Handle_objectdef1_indexed(int lineNo);

void Handle_indexed_indexedelem_indexed1(int lineNo);
void Handle_indexed1_comma_indexedelem_indexed1(int lineNo);
void Handle_indexedelem_l_brace_expr_colon_expr_r_brace(int lineNo);

int Handle_block_l_brace_block1_r_brace(int scope, int flag, int lineNo);
void Handle_block1_stmt_block1(int lineNo);

void Handle_funcdef_function_id_l_parenthesis_idlist_r_parenthesis_block(char* name, int scope, int lineNo);
char* Handle_funcdef_function_l_parenthesis_idlist_r_parenthesis_block(int scope, int lineNo);

void Handle_const_integer(int lineNo);
void Handle_const_double(int lineNo);
void Handle_const_string(int lineNo);
void Handle_const_nil(int lineNo);
void Handle_const_true(int lineNo);
void Handle_const_false(int lineNo);

void Handle_idlist_id_idlist1(char* name, char* functionName, int scope, int lineNo);
void Handle_idlist1_comma_id_idlist1(char* name, char* functionName, int scope, int lineNo);

void Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt(int lineNo);
void Handle_ifstmt_if_l_parenthesis_expr_r_parenthesis_stmt_else_stmt(int lineNo);

void Handle_whilestmt_while_l_parenthesis_expr_r_parenthesis_stmt(int lineNo);

void Handle_forstmt_for_l_parenthesis_elist_semicolon_expr_semicolon_elist_r_parenthesis_stmt(int lineNo);

void Handle_returnstmt_return_expr_semicolon(int lineNo);
void Handle_returnstmt_return_semicolon(int lineNo);

#endif
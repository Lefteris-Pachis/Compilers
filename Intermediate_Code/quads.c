#include "quads.h"

#include <stdio.h>
extern int scope_count;
extern int yylineno;

/*QUADS FUNCTIONS*/
void expand(void){
	assert(total == currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if(quads) {
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads= p;
	total += EXPAND_SIZE;
}

void emit(iopcode op, expr* arg1, expr* arg2, expr* result){
	if(currQuad == total)
		expand();
	quad* p 		= quads + currQuad++;
	p->arg1			= arg1;
	p->arg2 		= arg2;
	p->result 		= result;
	//p->label 		= label;
	//p->line 		= line;
}

expr* emit_iftableitem(expr* e){
	if(e->type != tableitem_e)
		return e;
	else{
		expr* result = newexpr(var_e);
		result->sym = new_temp();
		emit(tablegetelem,e,e->index,result);
		return result;
	}
}

/*TEMP VARIABLES FUNCTIONS*/
char* new_temp_name(){
	char * t_id=malloc(102);
 	strcpy(t_id, "_t");
 	char buffer[100];
 	sprintf(buffer, "%d",temp_counter);
 	strcat(t_id, buffer);
 	temp_counter++;
 	return(t_id);
}

void reset_temp(){
	temp_counter = 0;
}

symbol new_temp(){
	char* name = new_temp_name();
	symbol sym = Lookup(mytable,name,scope_count);
	if(sym == NULL){
		Insert_to_Hash(mytable,name,var_s,scope_count,yylineno);
		return sym;
	}else
		return sym;
}

unsigned int istempname(char* s){
	return *s == '_';
}

/*SCOPE SPACE FUNCTIONS*/
scopespace_t CurrScopeSpace(void){
	if(scopeSpaceCounter == 1)
		return programVar;
	else if(scopeSpaceCounter % 2 == 0)
		return formalArg;
	else
		return functionLocal;
}

void EnterScopeSpace(void){
	scopeSpaceCounter++;
}

void ExitScopeSpace(void){
	assert(scopeSpaceCounter > 1);
	scopeSpaceCounter--;
}

/*SCOPE OFFSET FUNCTIONS*/
unsigned CurrScopeOffset(void){
	switch(CurrScopeSpace()){
		case programVar: 	return programVarOffset;
		case functionLocal:	return functionLocalOffset;
		case formalArg: 	return formalArgOffset;
		default: assert(0);
	}
}

void IncCurrScopeOffset(void){
	switch(CurrScopeSpace()){
		case programVar: 	++programVarOffset; break;
		case functionLocal:	++functionLocalOffset; break;
		case formalArg: 	++formalArgOffset; break;
		default: assert(0);
	}
}

/*EXPRESSION FUNCTIONS*/
expr* lvalue_expr(symbol sym){
	assert(sym);
	expr* e = (expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->next = (expr*) 0;
	e->sym = sym;

	switch(sym->type){
		case var_s:			e->type = var_e; break; 
		case programfunc_s:	e->type = programfunc_e; break;
		case libraryfunc_s:	e->type = libraryfunc_e; break;
		default: assert(0);
	}
	return e;
}

expr* newexpr(expr_t t){
	expr* e = (expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->type = t;
	return e;
}

expr* newexpr_conststring(char* s){
	expr* e = (expr*)malloc(sizeof(expr));
	e->strConst = strdup(s);
	return e;
}

expr* newexpr_constnum(double num){
	expr* e = (expr*)malloc(sizeof(expr));
	e->numConst = num;
	return e;
}

expr* newexpr_constbool(unsigned char x){
	expr* e = (expr*)malloc(sizeof(expr));
	e->boolConst = x;
	return e;
}

void checkuminus(expr* e){
	if(	e->type == constbool_e		||
		e->type == conststring_e	||
		e->type == nil_e			||
		e->type == newtable_e		||
		e->type == programfunc_e 	||
		e->type == libraryfunc_e 	||
		e->type == boolexpr_e)
		printf("Compile Error: Illegal expr to unary -\n");
}

unsigned int istempexpr(expr* e){
	return 	e->sym &&
			e->sym->type == var_s &&
			istempname(e->sym->name);
}

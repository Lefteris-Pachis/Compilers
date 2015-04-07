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

void emit(iopcode op, expr* arg1, expr* arg2, unsigned label, unsigned line){
	if(currQuad == total)
		expand();
	quad* p 		= quads + currQuad++;
	p->arg1			= arg1;
	p->arg2 		= arg2;
	p->result 		= result;
	unsigned label 	= label;
	unsigned line 	= line;
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

node_t new_temp(){
	char* name = new_temp_name();
	node_t sym = Lookup(mytable,name,scope_count);
	if(sym == NULL){
		Insert_Var(mytable,name,"TEMP",scope_count,yylineno);
		return sym;
	}else
		return sym;
}

/*SCOPE SPACE FUNCTIONS*/
scopespace_t CurrScopeSpace(void){
	if(scopeSpaceCounter == 1)
		return programVar;
	else if(scopeSpaceCounter % 2 == 0)
		return formalarg;
	else
		return functionlocal;
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
		case functionlocal:	return functionLocalOffset;
		case formalarg: 	return formalArgOffset;
		default: assert(0);
	}
}

void IncCurrScopeOffset(void){
	switch(CurrScopeSpace()){
		case programVar: 	++programVarOffset; break;
		case functionlocal:	++functionLocalOffset; break;
		case formalarg: 	++formalArgOffset; break;
		default: assert(0);
	}
}
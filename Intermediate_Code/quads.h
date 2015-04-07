#ifndef QUADS_H
#define QUADS_H

#include "symtable.h"
#include <assert.h>

typedef enum iopcode { 
	assign,			add,			sub,
	mul,			div,			mod,
	uminus,			and, 			or,
	not,			if_eq,			if_noteq,
	if_lesseq,		if_greatereq,	if_less,
	if_greater,		call, 			param,
	ret,			getretval,		funcstart,
	funcend,		tablecreate,	
	tablegetelem,	tablesetelem
}iopcode;

typedef struct expr {

}expr;

typedef struct quad {
	iopcode		op;
	expr*		result;
	expr*		arg1;
	expr*		arg2;
	unsigned 	label;
	unsigned	line;
}quad;

/*GLOBAL VARIABLES*/
quad*			quads = (quad*) 0;
unsigned		total = 0;
unsigned int 	currQuad = 0;
int 			temp_counter = 0; 
unsigned		programVarOffset = 0;
unsigned 		functionLocalOffset = 0;
unsigned 		formalArgOffset = 0;
unsigned 		scopeSpaceCounter = 0;

#define EXPAND_SIZE	1024
#define CURR_SIZE	(total*sizeof(quad))
#define NEW_SIZE	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

/*QUADS FUNCTIONS*/
void expand(void);
void emit(iopcode op, expr* arg1, expr* arg2, unsigned label, unsigned line);

/*TEMP VARIABLES FUNCTIONS*/
char* new_temp_name();
void reset_temp();
node_t new_temp();

/*SCOPE SPACE FUNCTIONS*/
scopespace_t CurrScopeSpace(void);
void EnterScopeSpace(void);
void ExitScopeSpace(void);

/*SCOPE OFFSET FUNCTIONS*/
unsigned CurrScopeOffset(void);
void IncCurrScopeOffset(void);

#endif
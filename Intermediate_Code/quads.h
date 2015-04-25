#ifndef QUADS_H
#define QUADS_H

#include <assert.h>
#include "symtable.h"

#define EXPAND_SIZE	1024
#define CURR_SIZE	(total*sizeof(quad))
#define NEW_SIZE	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

typedef enum iopcode { 
	assign,			add,			sub,
	mul,			divv,			mod,
	uminus,			and, 			or,
	not,			if_eq,			if_noteq,
	if_lesseq,		if_greatereq,	if_less,
	if_greater,		call, 			param,
	ret,			getretval,		funcstart,
	funcend,		tablecreate,	jump,
	tablegetelem,	tablesetelem
}iopcode;

typedef enum expr_t { 
		var_e,
		tableitem_e,

		programfunc_e,
		libraryfunc_e,

		arithexpr_e,
		boolexpr_e,
		assignexpr_e,
		newtable_e,
		
		constint_e,
		constdouble_e,
		constbool_e,
		conststring_e,
		
		nil_e
}expr_t;

typedef struct expr expr;
struct expr {
	expr_t				type;
	symbol	 			sym;
	expr* 				index;
	int 				intConst;
	double 				doubleConst;
	char*				strConst;
	unsigned char 		boolConst;
	expr*				next;
};

typedef struct quad {
	iopcode		op;
	expr*		result;
	expr*		arg1;
	expr*		arg2;
	unsigned 	label;
	unsigned	line;
}quad;

/*GLOBAL VARIABLES*/




/*QUADS FUNCTIONS*/
void expand(void);
void emit(iopcode op, expr* arg1, expr* arg2, expr* result);

/*TEMP VARIABLES FUNCTIONS*/
char* new_temp_name();
void reset_temp();
symbol new_temp();
unsigned int istempname(char* s);

/*SCOPE SPACE FUNCTIONS*/
scopespace_t CurrScopeSpace(void);
void EnterScopeSpace(void);
void ExitScopeSpace(void);

/*SCOPE OFFSET FUNCTIONS*/
unsigned CurrScopeOffset(void);
void IncCurrScopeOffset(void);

/*EXPRESSION FUNCTIONS*/
expr* lvalue_expr(symbol sym);
expr* newexpr(expr_t t);
expr* newexpr_conststring(char* s);
expr* newexpr_constint(int num);
expr* newexpr_constdouble(double num);
expr* newexpr_constbool(unsigned char x);
expr* emit_iftableitem(expr* e);
void checkuminus(expr* e);
unsigned int istempexpr(expr* e);

void printquads();
static char *print_expr(expr * expression);
#endif
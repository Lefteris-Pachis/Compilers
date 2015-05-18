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

typedef struct S_Stack{
	unsigned offset;
	struct S_Stack *next;
	struct S_Stack *previous;
}Stack;


Stack *Head;
Stack *Tail;

typedef struct label_list{
	unsigned label;
	unsigned index;
	struct label_list *next;
}label_list;

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
	label_list 			*true_list;
	label_list 			*false_list;
};

typedef struct quad {
	iopcode		op;
	expr*		result;
	expr*		arg1;
	expr*		arg2;
	unsigned 	label;
	unsigned	taddress;
	unsigned	line;
}quad;

typedef struct statement{
	label_list *break_list;
	label_list *cont_list;
	struct statement *next;
}statement;

struct loopcounter_stack{
	int loopcounter;
	struct loopcounter_stack *next;
}*loopcounter_stack_top;

struct loopindex_stack{
	int loopindex;
	struct loopindex_stack *next;
}*loopindex_stack_top;

struct start_stack{
	unsigned start;
	struct start_stack *next;
}*start_stack_top;

struct stop_stack{
	unsigned stop;
	struct stop_stack *next;
}*stop_stack_top;

struct total_expr_stack{
	unsigned total_expr;
	struct total_expr_stack *next;
}*total_expr_stack_top;

struct forprefix{
	unsigned test;
	unsigned enter;
};

typedef struct indexed{
	expr*	 		x;
	expr*	 		y;
	struct indexed* next;
}indexed;

typedef struct calls{
	expr* 		elist;
	unsigned 	method;
	char* 		name;
}calls;

void push_loopcounter_stack(int loopcounter);
int pop_loopcounter_stack();
void push_loopindex_stack(int loopindex);
int pop_loopindex_stack();
void push_start_stack(unsigned start);
unsigned pop_start_stack();
void push_stop_stack(unsigned stop);
unsigned pop_stop_stack();
void push_total_expr_stack(unsigned total_expr);
unsigned pop_total_expr_stack();

/*push sthn stoiva pou krataei ta offset*/
void push_to_stack(scopespace_t offset);

/*pop apo stn stoiva gia offset*/
scopespace_t pop_from_stack();

expr* member_item(expr* lval, char* name);

/*push sthn stoiva*/
void push_to_stack(unsigned offset);

void resetformalargsoffset(void);
void resetfuctionlocalsoffset(void);
void restorecurrscopeoffset(unsigned n);

/* CALL FUNCTIONS */
expr* make_call(expr *lval, expr* elist);

/*QUADS FUNCTIONS*/
void expand(void);
void emit(iopcode op, expr* arg1, expr* arg2, expr* result);
void emit_jump(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned label);
void emit_ret(iopcode op, expr* result);
unsigned next_quad_label();
void patchlabel (unsigned quadnum, unsigned label);

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

label_list* label_list_insert(label_list* head,unsigned label,unsigned index);
label_list* merge(label_list* list1, label_list* list2);

expr* expr_list_insert(expr* head,expr *expr);
indexed* indexed_list_insert(indexed* head, indexed* index);

void Print_Quads(void);
static char *print_expr(expr * expression);
int ispached(unsigned quadnum);
#endif
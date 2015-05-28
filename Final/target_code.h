#ifndef TARGET_CODE_H
#define TARGET_CODE_H

#include <stdio.h>
#include "symtable.h"
#include "quads.h"

#define T_CURR_SIZE (totalIn*sizeof(instruction))
#define T_NEW_SIZE 	(EXPAND_SIZE*sizeof(instruction)+T_CURR_SIZE)

typedef enum vmopcode{
	assign_v,		add_v,			sub_v,
	mul_v,			div_v,			mod_v,
	uminus_v,		and_v, 			or_v,
	not_v, 			jeq_v,			jne_v,
	jle_v,			jge_v,			jlt_v,
	jgt_v,			jump_v, 		call_v,		
	pusharg_v, 		funcenter_v,	funcexit_v,
	newtable_v, 	tablegetelem_v,	tablesetelem_v,
	nop_v
}vmopcode;

typedef enum vmarg_t{

	label_a 	= 0,
	global_a 	= 1,
	formal_a 	= 2,
	local_a 	= 3,
	integer_a 	= 4,
	double_a	= 5,
	string_a 	= 6,
	bool_a 		= 7,
	nil_a 		= 8,
	userfunc_a 	= 9,
	libfunc_a 	= 10,
	retval_a 	= 11
}vmarg_t;

typedef struct vmarg{
	vmarg_t 	type;
	unsigned int val;
}vmarg;

typedef struct instruction{
	vmopcode 	opcode;
	vmarg 		result;
	vmarg 		arg1;
	vmarg 		arg2;
	unsigned 	srcLine;
}instruction;

typedef struct userfunc{
	int	address;
	int	localSize;
	char *		id;
}userfunc;

typedef struct incomplete_jump{
	unsigned 				instrNo;
	unsigned 				iaddress;
	struct incomplete_jump* next;
}incomplete_jump;

typedef struct return_List{
	int return_label;
	struct return_List *next;

}return_list;

typedef struct func_stack{
	symbol func;
	struct func_stack* next;
	struct return_List * node;
}func_stack;

struct func_stack *f_top;


void push_func(func_stack* function);
func_stack* pop_func();
func_stack* top_func();


void make_operand(expr* e, vmarg* arg);
void make_int_operand(vmarg* arg, int val);
void make_double_operand(vmarg* arg, double val);
void make_bool_operand(vmarg* arg, unsigned val);
void make_retval_operand(vmarg* arg);

incomplete_jump *add_incomplete_jump(incomplete_jump *head,unsigned instrNo, unsigned iaddress);
void patch_incomplete_jumps();

void generate_instruction(vmopcode op, quad* quad);
void generate_relational_instruction(vmopcode op, quad* quad);


int  consts_newstring(char* s);
int  consts_newdouble(double d);
int  consts_newint(int d);

unsigned userfuncs_newfunc(symbol sym);
unsigned libfuncs_newused(const char* s);
char* consts_getstring(unsigned index);
double consts_getnumber(unsigned index);
userfunc* userfuncs_get(unsigned index);
char* libfuncs_getused(unsigned index);

void t_expand();
void t_emit(instruction* instruction);
unsigned int  nextinstructionlabel();
void Print_Instructions(FILE *fp );
int add_userfunction(symbol f);


void printConsts();
#endif
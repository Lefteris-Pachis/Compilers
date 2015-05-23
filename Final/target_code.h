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
	number_a 	= 4,
	string_a 	= 5,
	bool_a 		= 6,
	nil_a 		= 7,
	userfunc_a 	= 8,
	libfunc_a 	= 9,
	retval_a 	= 10
}vmarg_t;

typedef struct vmarg{
	vmarg_t 	type;
	unsigned 	val;
}vmarg;

typedef struct instruction{
	vmopcode 	opcode;
	vmarg 		result;
	vmarg 		arg1;
	vmarg 		arg2;
	unsigned 	srcLine;
}instruction;

typedef struct userfunc{
	unsigned 	address;
	unsigned 	localSize;
	char *		id;
}userfunc;

typedef struct incomplete_jump{
	unsigned 				instrNo;
	unsigned 				iaddress;
	struct incomplete_jump* next;
}incomplete_jump;




void make_operand(expr* e, vmarg* arg);
void make_number_operand(vmarg* arg, double val);
void make_bool_operand(vmarg* arg, unsigned val);
void make_retval_operand(vmarg* arg);

void add_incomplete_jump(unsigned instrNo, unsigned iaddress);
void patch_incomplete_jumps();

void generate_instruction(vmopcode op, quad* quad);
void generate_relational_instruction(vmopcode op, quad* quad);
void generate_param_instruction(quad* quad);
void generate_call_instruction(quad* quad);
void generate_retval_instruction(quad* quad);
void generate_funcstart_instruction(quad* quad);
void generate_funcend_instruction(quad* quad);
void generate_return_instruction(quad* quad);

unsigned consts_newstring(char* s);
unsigned consts_newnumber(double d);
unsigned userfuncs_newfunc(symbol sym);
unsigned libfuncs_newused(const char* s);
char* consts_getstring(unsigned index);
double consts_getnumber(unsigned index);
userfunc* userfuncs_get(unsigned index);
char* libfuncs_getused(unsigned index);

void t_expand();
void t_emit(instruction* instruction);
unsigned nextinstructionlabel();
void Print_Instructions();
#endif
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "target_code.h"

extern unsigned	total_instr;

#define AVM_ENDING_PC 			total_instr
#define AVM_MAX_INSTRUCTIONS	(unsigned) nop_v

#define execute_add	execute_arithmetic
#define execute_sub	execute_arithmetic
#define execute_mul	execute_arithmetic
#define execute_div	execute_arithmetic
#define execute_mod	execute_arithmetic

#define execute_jge	execute_relop
#define execute_jle	execute_relop
#define execute_jgt	execute_relop
#define execute_jlt	execute_relop

void execute_arithmetic(instruction*);
void execute_uminus(instruction*);
void execute_assign(instruction*);
void execute_call(instruction*);
void execute_pusharg(instruction*);
void execute_funcenter(instruction*);
void execute_funcexit(instruction*);
void execute_and(instruction*);
void execute_or(instruction*);
void execute_not(instruction*);
void execute_nop(instruction*);
void execute_jeq(instruction*);
void execute_jne(instruction*);
void execute_jle(instruction*);
void execute_jge(instruction*);
void execute_jlt(instruction*);
void execute_jgt(instruction*);
void execute_jump(instruction*);
void execute_newtable(instruction*);
void execute_tablegetelem(instruction*);
void execute_tablesetelem(instruction*);

typedef void (*execute_func_t) (instruction*);
void execute_cycle();

#endif
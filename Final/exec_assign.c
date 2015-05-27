#include "exec_assign.h"

extern avm_memcell	stack[AVM_STACKSIZE];
extern avm_memcell 	ax;
extern avm_memcell	retval;
extern unsigned		top;

void execute_assign (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell *) 0);
	avm_memcell* rv = avm_translate_operand(&instr->arg1, &ax);
	assert(lv && ((&stack[AVM_STACKSIZE-1] >= lv) && (lv > &stack[top]) || (lv==&retval)));
	assert(rv);
	avm_assign(lv, rv);
}
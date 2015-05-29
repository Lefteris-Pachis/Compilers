#include "exec_assign.h"

extern avm_memcell	stack[AVM_STACKSIZE];
extern avm_memcell 	ax,bx;
extern avm_memcell	retval;
extern unsigned	int	top;

void execute_assign (instruction* instr){
	printf("exec_assign\n");
	avm_memcell* rv = avm_translate_operand(&instr->result, &ax);
	avm_memcell* lv = avm_translate_operand(&instr->arg1,0);
	printf("lv  %d:%d:%d\n", lv,&stack[top],&stack[AVM_STACKSIZE-1]);
	printf("lv=%d\n", lv);
	printf("&stack[AVM_STACKSIZE-1]=%d\n", &stack[AVM_STACKSIZE-1]);
	assert((&stack[AVM_STACKSIZE-1] >= lv));
	assert(lv && ((&stack[AVM_STACKSIZE-1] >= lv) && (lv > &stack[top]) || (lv==&retval)));
	assert(rv);
	avm_assign(lv, rv);
}
#include "exec_arithm.h"

extern avm_memcell		stack[AVM_STACKSIZE];
extern avm_memcell		ax, bx;
extern avm_memcell		retval;
extern unsigned			top;
extern unsigned char 	executionFinished;

double add_impl (double x, double y){ 
	return x+y; 
}
double sub_impl (double x, double y){ 
	return x-y; 
}
double mul_impl (double x, double y){ 
	return x*y; 
}
double div_impl (double x, double y){ 
	if(y == 0){
		avm_error("error: division by 0"); 
		executionFinished = 1; 
		return -1.0;
	}
	return x/y;
}
double mod_impl (double x, double y){ 
	if(y == 0){
		avm_error("error: division by 0"); 
		executionFinished = 1;  
		return -1.0;
	} 
	return ((unsigned ) x) % ((unsigned) y);
}

arithmetic_func_t arithmeticFuncs[] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};

void execute_arithmetic(instruction* instr){
	//printf("exec_arithm\n");
	avm_memcell* lv = avm_translate_operand(&instr->result, &retval);
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));
	assert(rv1 && rv2 );
	
	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!");
		executionFinished = 1;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - 1];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
	}
}

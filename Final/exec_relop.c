#include "exec_relop.h"

extern avm_memcell		stack[AVM_STACKSIZE];
extern avm_memcell		ax, bx;
extern avm_memcell		retval;
extern unsigned			top;
extern unsigned char 	executionFinished;
extern unsigned 		pc;

unsigned char jge_impl(double x, double y) { return x >= y; }
unsigned char jgt_impl(double x, double y) { return x > y; }
unsigned char jle_impl(double x, double y) { return x <= y; }
unsigned char jlt_impl(double x, double y) { return x < y; }

cmp_func cmpFunctions[] = {
	jle_impl,
	jge_impl,
	jlt_impl,
	jgt_impl
};

void execute_relop(instruction* instr){
	//printf("exec_relop\n");
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
	cmp_func op;
	unsigned char result = 0;
	
	assert(instr->result.type == label_a);
	assert(rv1 && rv2 );
	
	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!");
		executionFinished = 1;
	}
	else{
		op = cmpFunctions[instr->opcode - 12];
		result = (*op)(rv1->data.numVal, rv2->data.numVal);
		if(result)
			pc = instr->result.val;
	}
}

void execute_jeq(instruction* instr){
	//printf("exec_jeq\n");
	assert(instr->result.type == label_a);
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
	unsigned char result = 0;
		
	if (rv1->type == undef_m || rv2->type == undef_m)
		avm_error("'undef' involved in equality!");
		else
			if(rv1->type == nil_m || rv2->type == nil_m)
				result = rv1->type == nil_m && rv2->type == nil_m;
				else
					if(rv1->type == bool_m || rv2->type == bool_m)
						result = (avm_tobool(rv1) == avm_tobool(rv2));
					else
						if(rv1->type != rv2->type)
							avm_error("illegal! equality!");
						else{
							if(rv1->type == number_m)
								result = rv1->data.numVal == rv2->data.numVal;
							else if(rv1->type == string_m )
								result = !strcmp(rv1->data.strVal, rv2->data.strVal); 
							else if(rv1->type == table_m)
								result = (rv1->data.tableVal == rv2->data.tableVal);
							else if(rv1->type == userfunc_m)
								result = rv1->data.funcVal == rv2->data.funcVal ;
							else
								result = !strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
						}
	if (!executionFinished && result )
		pc = instr->result.val;
}

void execute_jne(instruction* instr){
	//printf("exec_jne\n");
	assert(instr->result.type == label_a);
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
	unsigned char result = 0;
	
	if (rv1->type == undef_m || rv2->type == undef_m)
		avm_error("'undef' involved in inequality!");
		else
			if(rv1->type == nil_m || rv2->type == nil_m)
				result = !(rv1->type == nil_m && rv2->type == nil_m);
			else
				if(rv1->type == bool_m || rv2->type == bool_m)
					result = (avm_tobool(rv1) != avm_tobool(rv2));
				else
					if(rv1->type != rv2->type)
						avm_error("illegal inequality!");
					else{
						if(rv1->type == number_m)
							result = rv1->data.numVal != rv2->data.numVal;
						else if(rv1->type == string_m )
							result = strcmp(rv1->data.strVal, rv2->data.strVal); 
						else if(rv1->type == table_m)
							result = (rv1->data.tableVal != rv2->data.tableVal);
						else if(rv1->type == userfunc_m)
							result = rv1->data.funcVal != rv2->data.funcVal ;
						else
							result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
					}
	if (!executionFinished && result )
		pc = instr->result.val;
}

void execute_jump(instruction* instr){
	//printf("exec_jump\n");
	assert(instr->result.type == label_a);
	pc = instr->result.val;
	//printf("PC = %d\n",pc );
}
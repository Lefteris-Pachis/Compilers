#include "exec_func.h"

extern avm_memcell		stack[AVM_STACKSIZE];
extern avm_memcell		ax;
extern avm_memcell		retval;
extern unsigned 		pc;
extern instruction*		code;
extern unsigned char	executionFinished;
extern unsigned			top, topsp;
extern unsigned 		totalActuals;
extern unsigned			codeSize;

char* typeStrings[] = {
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};

void execute_call(instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	avm_callsaveenvironment();
	
	switch (func->type){
		
		case userfunc_m: {
			
			pc = func->data.funcVal;
			assert(pc < AVM_ENDING_PC);
			assert(code[pc].opcode = funcenter_v);
			break;
		}
		
		case string_m: {
			avm_calllibfunc(func->data.strVal);
			break;
		}
		
		case libfunc_m: {
			avm_calllibfunc(func->data.strVal);
			break;
		}
		
		default: {
			char *s = (char*) malloc(sizeof(char));
			s = avm_tostring(func);
			avm_error("call: cannot bind '%s' to function!", s);
			free(s);
			executionFinished = 1;
		}
	}
}

void execute_pusharg(instruction* instr){
	avm_memcell* arg = avm_translate_operand(&instr->result, &ax);
	assert(arg);	
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

void execute_funcenter(instruction* instr){
	userfunc* funcInfo;
	avm_memcell* func = avm_translate_operand(&instr->arg1, &ax);
	assert(func);
	assert(pc == func->data.funcVal);
	totalActuals = 0;
	funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->localSize;
}

void execute_funcexit(instruction* unused){
	unsigned int oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	while (oldTop++ <= top){
		avm_memcellclear(&stack[oldTop]);
	}
}

/******************LIBRARY FUNCTIONS********************/
void libfunc_print(void){
	unsigned n = avm_totalactuals();
	unsigned i;
	char* s;
	for(i = 0; i < n; ++i){
		s = (char*)avm_tostring(avm_getactual(i));
		puts(s);
		free(s);
	}
}

void libfunc_typeof(void){
	unsigned n = avm_totalactuals();
	if(n != 1)
		avm_error("one argument expected in 'typeof'!","");
	else{
		avm_memcellclear(&retval);
		retval->type = string_m;
		retval->data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_totalarguments(void){
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	if(!p_topsp){
		avm_error("'totalarguments' called outside a function!","");
		retval->type = nil_m;
	}
	else{
		retval->type = number_m;
		retval->data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}
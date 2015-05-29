#include "dispatcher.h"

unsigned char	executionFinished = 0;
unsigned 		pc = 0;
unsigned		currLine = 0;
unsigned		codeSize = 0;
//instruction*	code = (instruction*)0;
extern instruction* instr;

execute_func_t executeFuncs[] = {
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	0,
	0,
	0,
	0,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_jump,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	0
};

void execute_cycle(void){
	if(executionFinished){
		return;
	}else
		if(pc == AVM_ENDING_PC){
			executionFinished = 1;
			return;
		}
		else{
			assert(pc < AVM_ENDING_PC);
			instruction* i = instr + pc;
			printf("OP %d PC %d\n",i->opcode,pc );
			assert(i->opcode >= 0 && i->opcode <= AVM_MAX_INSTRUCTIONS);
			if(i->srcLine)
				currLine = i->srcLine;
			unsigned oldPC = pc;
			(*executeFuncs[i->opcode])(i);
			if(pc == oldPC)
				++pc;
		}

}
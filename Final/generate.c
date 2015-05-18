#include "generate.h"
#include "quads.h"

extern quad* quads;
extern unsigned currQuad;
extern unsigned int currInstr;
unsigned i;

generator_func_t generators[] = {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATERQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_JUMP,
	generate_CALL,
	generate_PARAM,
	generate_RETURN,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
	generate_NOP
};

void generate(void){
	for (i = 0; i < currQuad; ++i){
		(*generators[quads[i].op]) (quads + i);
	}
}

void generate_ADD(quad* quad){
	printf("***GENERATE_ADD***\n");
	generate_instruction(add_v, quad);
}

void generate_SUB(quad* quad){
	printf("***GENERATE_SUB***\n");
	generate_instruction(sub_v, quad);
}

void generate_MUL(quad* quad){
	printf("***GENERATE_MUL***\n");
	generate_instruction(mul_v, quad);
}

void generate_DIV(quad* quad){
	printf("***GENERATE_DIV***\n");
	generate_instruction(div_v, quad);
}

void generate_MOD(quad* quad){
	printf("***GENERATE_MOD***\n");
	generate_instruction(mod_v, quad);
}

void generate_NEWTABLE(quad* quad){
	printf("***GENERATE_NEWTABLE***\n");
	generate_instruction(newtable_v, quad);
}

void generate_TABLEGETELEM(quad* quad){
	printf("***GENERATE_TABLEGETELEM***\n");
	generate_instruction(tablegetelem_v, quad);
}

void generate_TABLESETELEM(quad* quad){
	printf("***GENERATE_TABLESETELEM***\n");
	generate_instruction(tablesetelem_v, quad);
}

void generate_ASSIGN(quad* quad){
	printf("***GENERATE_ASSIGN***\n");
	generate_instruction(assign_v, quad);
}

void generate_NOP(){
	instruction i;
	printf("***GENERATE_NOP***\n");
	i.opcode = nop_v;
	t_emit(&i);
}

void generate_JUMP(quad* quad){
	printf("***GENERATE_JUMP***\n");
	generate_relational_instruction(jump_v, quad);
}

void generate_IF_EQ(quad* quad){
	printf("***GENERATE_IF_EQ***\n");
	generate_relational_instruction(jeq_v, quad);
}

void generate_IF_NOTEQ(quad* quad){
	printf("***GENERATE_IF_NOTEQ***\n");
	generate_relational_instruction(jne_v, quad);
}

void generate_IF_GREATER(quad* quad){
	printf("***GENERATE_IF_GREATER***\n");
	generate_relational_instruction(jgt_v, quad);
}

void generate_IF_GREATERQ(quad* quad){
	printf("***GENERATE_IF_GREATERQ***\n");
	generate_relational_instruction(jge_v, quad);
}

void generate_IF_LESS(quad* quad){
	printf("***GENERATE_IF_LESS***\n");
	generate_relational_instruction(jlt_v, quad);
}

void generate_IF_LESSEQ(quad* quad){
	printf("***GENERATE_IF_LESSEQ***\n");
	generate_relational_instruction(jle_v, quad);
}

void generate_PARAM(quad* quad){
	printf("***GENERATE_PARAM***\n");
	generate_param_instruction(quad);
}

void generate_CALL(quad* quad){
	printf("***GENERATE_CALL***\n");
	generate_call_instruction(quad);
}

void generate_GETRETVAL(quad* quad){
	printf("***GENERATE_GETRETVAL***\n");
	generate_retval_instruction(quad);
}

void generate_FUNCSTART(quad* quad){
	printf("***GENERATE_FUNCSTART***\n");
	generate_funcstart_instruction(quad);
}

void generate_RETURN(quad* quad){
	printf("***GENERATE_RETURN***\n");
	generate_return_instruction(quad);
}

void generate_FUNCEND(quad* quad){
	printf("***GENERATE_FUNCEND***\n");
	generate_funcend_instruction(quad);
}

void generate_UMINUS(quad* quad){
	printf("***GENERATE_UMINUS***\n");
	generate_instruction(uminus_v, quad);
}
#include "generate.h"
#include "quads.h"
#include "target_code.h"

extern quad* quads;
extern instruction*	instructions;
extern unsigned currQuad;
extern unsigned int currInstr;
extern int total_userFuncs;
unsigned i;

generator_func_t generators[] = {
generate_ASSIGN ,
	generate_ADD ,
    generate_SUB ,
    generate_MUL ,
    generate_DIV ,
    generate_MOD ,
	generate_UMINUS ,
	generate_AND,
	generate_OR ,
	generate_NOT ,
	generate_IF_EQ ,
	generate_IF_NOTEQ ,	
	generate_IF_LESSEQ ,
	generate_IF_GREATERQ ,
	generate_IF_LESS ,
	generate_IF_GREATER ,
	generate_CALL ,
	generate_PARAM ,
	generate_RETURN ,
	generate_GETRETVAL ,
	generate_FUNCSTART ,
	generate_FUNCEND ,
	generate_JUMP ,
	generate_NEWTABLE ,
    generate_TABLEGETELEM ,
   	generate_TABLESETELEM ,
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
	//printf("***GENERATE_PARAM***\n");
	quad->taddress = nextinstructionlabel();
	instruction t;
	t.opcode = pusharg_v;
	make_operand(quad->arg1, &t.arg1);
	t_emit(&t);
}

void generate_CALL(quad* quad){
	//printf("***GENERATE_CALL***\n");
	quad->taddress = nextinstructionlabel();
	instruction t;
	t.opcode = call_v;
	make_operand(quad->arg1, &t.arg1);
	t_emit(&t);
}

void generate_GETRETVAL(quad* quad){
	printf("***GENERATE_GETRETVAL***\n");
	quad->taddress = nextinstructionlabel();
	instruction t;
	t.opcode = assign_v;
	make_operand(quad->result, &t.result);
	make_retval_operand(&t.arg1);
	t_emit(&t);
}

void generate_FUNCSTART(quad* quad){
	printf("***GENERATE_FUNCSTART***\n");
	int index;
	func_stack* function= malloc(sizeof(func_stack));

	symbol f = quad->result->sym;
	function->func=f;
	function->node=NULL;
	f->taddress = nextinstructionlabel();
	printf("%d\n", f->taddress);
	quad->taddress = nextinstructionlabel();

	index = add_userfunction(f);

	push_func(function);

	instruction t;

	t.opcode = funcenter_v;
	make_operand(quad->result,&t.result);
	t.result.val = index;
	t_emit(&t);

}

void generate_RETURN(quad* quad){
	func_stack *f;
	printf("***GENERATE_RETURN***\n");
	quad->taddress = nextinstructionlabel();
	instruction t;
	t.opcode = assign_v;
	make_retval_operand(&t.result);
	make_operand(quad->result,&t.arg1);
	t_emit(&t);
	f=pop_func();
	f->node=appendRL(f->node,nextinstructionlabel());
	push_func(f);
	t.opcode=jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type=label_a;
	t_emit(&t);


	
}



vmarg * reset_operand(){
	 return( (vmarg *) NULL);
}

void generate_FUNCEND(quad* quad){
	return_list *tmp;
	printf("***GENERATE_FUNCEND***\n");
	func_stack *f;
	f=pop_func();
	tmp=f->node;
	if(tmp!=NULL){
		while(tmp){
			printf("while\n");
			instructions[tmp->return_label].result.val=nextinstructionlabel();


			tmp=tmp->next;

		}
	}
	quad->taddress = nextinstructionlabel();
	instruction t;
	t.opcode=funcexit_v;
	make_operand(quad->result,&t.result);
	t.result.val = total_userFuncs-1;
	t_emit(&t);




}



return_list * appendRL(return_list *head,int label){

	return_list *tmp = malloc( sizeof( struct return_List ) );
	tmp->return_label = label;

	if( head == NULL ){
		tmp->next = NULL;
	}
	else{
		tmp->next = head;
	}
	head = tmp;

	return( head );
}

void generate_UMINUS(quad* quad){
	printf("***GENERATE_UMINUS***\n");
	generate_instruction(uminus_v, quad);
}

void generate_OR(quad* quad){

}
void generate_NOT(quad* quad){
	
}
void generate_AND(quad* quad){
	
}
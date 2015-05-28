#include "exec_tables.h"

extern avm_memcell		stack[AVM_STACKSIZE];
extern avm_memcell		retval;
extern avm_memcell		ax, bx;
extern unsigned			top;

void execute_newtable(instruction* instr){
	printf("exec_newtable\n");
	avm_memcell* lv = avm_translate_operand(&instr->result,(avm_memcell*) 0);
	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));
	avm_memcellclear(lv);
	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(instruction* instr){
	printf("exec_tableget\n");
	avm_memcell* lv = avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* t = avm_translate_operand(&instr->arg1,(avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg2,&ax);
	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));
	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i);
	avm_memcellclear(lv);
	lv->type = nil_m;
	if(t->type != table_m){
		avm_error("illigal use of type as table!","");
	}
	else{
		avm_memcell* content = avm_tablegetelem(t->data.tableVal,i);
		if(content)
			avm_assign(lv,content);
		else{
			char* ts = avm_tostring(t);
			char* is = avm_tostring(i);
			avm_warning("not found!");
			free(ts);
			free(is);
		}
	}
}

void execute_tablesetelem(instruction* instr){
		printf("exec_tableset\n");
	avm_memcell* t = avm_translate_operand(&instr->arg1,(avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg2,&ax);
	avm_memcell* c = avm_translate_operand(&instr->result,&bx);
	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i && c);
	if(t->type != table_m)
		avm_error("illigal use of type as table!","");
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}
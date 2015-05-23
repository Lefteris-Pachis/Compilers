#include "avm.h"

avm_memcell stack[AVM_STACKSIZE];
avm_memcell ax, bx, cx;
avm_memcell retval;
avm_memcell top, topsp;




void avm_initstack(void){
	unsigned i;
	for(i=0; i<AVM_STACKSIZE; ++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type = undef_m;
	}
}

void avm_bucketsinit(avm_table_bucket** p){
	unsigned i;
	for(i=0; i<AVM_TABLE_HASHSIZE; ++i)
		p[i] = (avm_table_bucket*) 0;
}

avm_table* avm_tablenew(void){
	avm_table* t = (avm_table*)malloc(sizeof(avm_table));
	AVM_WIPEOUT(*t);
	t->refCounter = t->total = 0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);
	return t;
}

void avm_tablebucketsdestroy(avm_table_bucket** p){
	unsigned i;
	avm_table_bucket* b,del;
	for(i=0; i<AVM_TABLE_HASHSIZE; ++i){
		for(b = *p; b;){
			del = b;
			b = b->next;
			avm_memclear(&del->key);
			avm_memclear(&del->value);
			free(del);
		}
		p[i] = (avm_table_bucket*) 0;
	}
}

void avm_tabledestroy(avm_table* t){
	avm_tablebucketsdestroy(t->strIndexed);
	avm_tablebucketsdestroy(t->numIndexed);
	free(t);
}

void avm_tableincrefcounter(avm_table* t){
	++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t){
	assert(t->refCounter > 0);
	if(!--t->refCounter)
		avm_tabledestroy(t);
}

avm_memcell* avm_tablegetelem(avm_memcell* key){

}

void avm_tablesetelem(avm_memcell* key, avm_memcell* value){

}

double consts_getnumber(unsigned index){

}
char* consts_getstring(unsigned index){

}
char* libfuncs_getused(unsigned index){

}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
	switch(arg->type){
		/*Variables*/
		case global_a: 	return &stack[AVM_STACKSIZE - 1 - arg->val];
		case local_a: 	return &stack[topsp - arg->val];
		case formal_a: 	return &stack[topsp + AVM_STACKSIZE + 1 + arg->val];

		case retval_a: 	return &retval;

		case number_a:  {
			reg->type = number_m;
			reg->data.numVal = consts_getnumber(arg->val);
			return reg;
		}

		case string_a: 	{
			reg->type = string_m;
			reg->data.strVal = strdup(consts_getstring(arg->val));
			return reg;
		}

		case bool_a: 	{
			reg->type = bool_m;
			reg->data.boolVal = arg->val;
			return reg;
		}

		case nil_a: 	{
			reg->type = nil_m;
			return reg;
		}

		case userfunc_a:{
			reg->type = userfunc_m;
			reg->data.funcVal = arg->val;
			return reg;
		}

		case libfunc_a: {
			reg->type = libfunc_m;
			reg->data.libfuncVal = libfuncs_getused(arg->val);
			return reg;
		}

		default: 		assert(0);
	}
}

memclear_func_t memclearFuncs[] = {
	0, /*number*/
	memclear_string,
	0,/*bool*/
	memclear_table,
	0,/*userfunc*/
	0,/*livfunc*/
	0,/*nil*/
	0/*undef*/
};

void avm_memcellclear(avm_memcell* m){
	if(m->type != undef_m)
	{
		memclear_func_t f = memclearFuncs[m->type];
		if(f)
		{
			(*f)(m);
		}
		m->type = undef_m;
	}
}

extern void memclear_string (avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

extern void memclear_table (avm_memcell* m){
	assert(m->data.tableVal);
	//avm_tabledecrefcounter(m->data.tableVal);
}

void avm_warning(char* format){
	printf("Warning! %s\n", format);
}

void avm_error(char* format, char* s){
	printf("Runtime error! %s\n", format, s);		/* message may need to include %s */
	executionFinished = 1;
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
	if(lv == rv)			/* Same cells? Destructive to assign*/
		return;

	if((lv->type == table_m) && (rv->type == table_m) && 			/* Same tables? No need to assign*/
		(lv->data.tableVal == rv->data.tableVal)){
		return;
	}

	if(rv->type == undef_m)
		avm_warning("assigning from 'undef' content!");

	avm_memcellclear(lv);			/* Clear old cell contents */
	memcpy(lv, rv, sizeof(avm_memcell));

	/* Now take care of copied valus or reference counting */
	if(lv->type == string_m)
		lv->data.strVal = strdup(rv->data.strVal);
	else if(lv->type == table_m){
		avm_tableincrefcounter(lv->data.tableVal);
	}
}
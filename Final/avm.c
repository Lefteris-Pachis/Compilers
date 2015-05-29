#include "avm.h"

avm_memcell 			stack[AVM_STACKSIZE];
avm_memcell 			ax, bx, cx;
avm_memcell 			retval;
unsigned int 			top, topsp;
unsigned 				totalActuals = 0;
extern unsigned 		pc;
extern userfunc* 		userFuncs;
extern unsigned char 	executionFinished;
char**					VMlibs = (char**) 0;
unsigned 				countlibs = 0;
unsigned 				totalVMlibs = 0;
instruction* 			instr;
unsigned 				total_instr;
double* 				Consts_Double;
unsigned 				total_Double_Consts;
double*					Consts_Integer;
unsigned 				total_Integer_Consts;
char** 					Consts_String;
unsigned 				total_String_Consts;
userfunc* 				Consts_Func;
unsigned 				total_Func_Consts;


library_func_t LibFuncs[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

tostring_func_t tostringFuncs[] = {
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

tobool_func_t toboolFuncs[] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

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

void avm_tablebucketsinit (avm_table_bucket** p){
	unsigned i;
	for (i = 0; i<AVM_TABLE_HASHSIZE; ++i)
		p[i] = (avm_table_bucket *) 0;
	return;
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
	avm_table_bucket *b,*del;
	for(i=0; i<AVM_TABLE_HASHSIZE; ++i){
		for(b = *p; b;){
			del = b;
			b = b->next;
			//avm_memclear(&del->key);
			//avm_memclear(&del->value);
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

avm_memcell* avm_tablegetelem(avm_table* table,avm_memcell* index){

}

void avm_tablesetelem(avm_table* table,avm_memcell* index, avm_memcell* content){
	
}

double consts_getint(unsigned index){
	return Consts_Integer[index];
}

double consts_getdouble(unsigned index){
	return Consts_Double[index];
}

char* consts_getstring(unsigned index){
	return Consts_String[index];
}

char* libfuncs_getused(unsigned index){
	char* namedLibfuncs[12] = {"print","input","objectmemberkeys","objecttotalmembers","objectcopy","totalarguments","argument","typeof","strtonum","sqrt","cos","sin"};
	return namedLibfuncs[index];
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
	int i;
	switch(arg->type){
		/*Variables*/
		case global_a:	return &stack[AVM_STACKSIZE - 1 - arg->val];
		case local_a: 	printf("aaaaaaaa %d\n", arg->val); return &stack[topsp - arg->val];
		case formal_a: 	/*return &stack[topsp + AVM_STACKSIZE + 1 + arg->val];*/ return &stack[AVM_STACKSIZE - arg->val];

		case retval_a: 	printf("retval_a\n");return &retval;

		case integer_a:  {
			reg->type = number_m;
			reg->data.numVal = consts_getint(arg->val);
			printf("zzzzzz %f\n", reg->data.numVal);
			return reg;
		}

		case double_a:  {
			reg->type = number_m;
			reg->data.numVal = consts_getdouble(arg->val);
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

void memclear_string (avm_memcell* m){
	//assert(m->data.strVal);
	free(m->data.strVal);
}

void memclear_table (avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
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

void avm_dec_top(void){
	if(!top){
		avm_error("stack overflow","");
		executionFinished = 1;
	}
	else
		--top;
}

void avm_push_envvalue(unsigned val){
	stack[top].type 		= number_m;
	stack[top].data.numVal 	= val;
	avm_dec_top();
}

void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc + 1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}

unsigned avm_get_envvalue(unsigned i){
	unsigned val;
	printf("xxxxxxxxxxxx %f\n", stack[i].data.numVal);
	//assert(stack[i].type == number_m);
	val = (unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
	return val;
}

unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

userfunc* avm_getfuncinfo(unsigned address){
	int i=0;
	printf("%d\n", address);
	for (i = 0; i < total_Func_Consts; ++i)
	{
		printf("Consts_Func %s\n", Consts_Func[i].id);
	}
	return (Consts_Func + address);
}

void avm_calllibfunc(char* id){	
	library_func_t f = avm_getlibraryfunc(id);
	if(!f){
		avm_error("Unsupported lib func '%s' called!", id);
		executionFinished = 1;
	}
	else{
		topsp = top;		/* Enter function sequence. No stack locals */
		totalActuals = 0;
		(*f) ();
		if(!executionFinished)		/* An error may naturally occur inside */
			execute_funcexit((instruction*) 0);	/* Return sequence */
	}
}

library_func_t avm_getlibraryfunc(char* id){
	unsigned i;	
	for(i = 0; i < 12; i++){
		if(strcmp(id, *(VMlibs+i)) == 0)
			return LibFuncs[i];
	}
}

void avm_registerlibfunc(char* id, library_func_t addr){
		char** str;
		if(countlibs == totalVMlibs) expand_VMlibs();
		str = VMlibs + countlibs;
		*str = strdup(id);
		LibFuncs[countlibs] = addr;
		countlibs++;
}

void expand_VMlibs(){
	char** s = (char**) malloc(VMLIB_NEW_SIZE);
	assert(totalVMlibs == countlibs);
	if (VMlibs){
		memcpy(s, VMlibs, VMLIB_CURR_SIZE);
		free(VMlibs);
	}
	VMlibs = s;
	totalVMlibs += EXPAND_SIZE;
}

char* avm_tostring(avm_memcell* m){
	assert(m->type >= 0 && m->type <= undef_m);
	return (*tostringFuncs[m->type])(m);
}

char* number_tostring(avm_memcell* m){
	char* s = (char*)malloc(512*sizeof(char));
	sprintf(s, "%f", m->data.numVal);
	return s;
}

char* string_tostring(avm_memcell* m){
	char* s;
	s = strdup(m->data.strVal);
	return s;
}

char* bool_tostring(avm_memcell* m){
	if(m->data.boolVal == 1)
		return "true";
	else
		return "false";
}

char* table_tostring(avm_memcell* m){

}

char* userfunc_tostring(avm_memcell* m){
	char* s = (char*) malloc(512*sizeof(char));
	sprintf(s, "%d", m->data.funcVal);
	return s;
}

char* libfunc_tostring(avm_memcell* m){
	char* s;
	s = strdup(m->data.libfuncVal);
	return s;
}

char* nil_tostring(avm_memcell* m){
	return "nil";
}

char* undef_tostring(avm_memcell* m){
	return "undef";
}

unsigned char avm_tobool(avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}

unsigned char number_tobool(avm_memcell* m){
	return (m->data.numVal != 0);
}

unsigned char string_tobool(avm_memcell* m){
	return (m->data.strVal[0] != 0);
}

unsigned char bool_tobool(avm_memcell* m){
	return m->data.boolVal;
}

unsigned char table_tobool(avm_memcell* m){
	return 1;
}

unsigned char userfunc_tobool(avm_memcell* m){
	return 1;
}

unsigned char libfunc_tobool(avm_memcell* m){
	return 1;
}

unsigned char nil_tobool(avm_memcell* m){
	return 0;
}

unsigned char undef_tobool(avm_memcell* m){
	assert(0);
	return 0;
}

void avm_initialize(){
	avm_initstack();
	avm_registerlibfunc("print", libfunc_print);
	//avm_registerlibfunc("typeof", libfunc_typeof);
}


int Read_Bin(){

    FILE* Nicode = fopen("tcode.bin","rb");
    int x=0;
	int i;
    int tot[5];
   
    char magic[12];
    
    fread(magic,12,1,Nicode);

    
    
    if(strcmp(magic,"giwrgadakhs")!=0){
    	return -1;
    }

    fread(tot,sizeof(int),5,Nicode);
    
    double DoubCon[tot[0]];
    fread(DoubCon,sizeof(double),tot[0],Nicode);

    total_Double_Consts = tot[0];
    Consts_Double = malloc(sizeof(double)*total_Double_Consts);
    for ( i = 0; i < total_Double_Consts; ++i)
    	Consts_Double[i] = DoubCon[i];
   
    int IntCon[tot[1]];
    double temp;
    fread(IntCon,sizeof(int),tot[1],Nicode);
    total_Integer_Consts = tot[1];
    Consts_Integer = malloc(sizeof(double)*total_Integer_Consts);
    for ( i = 0; i < total_Integer_Consts; ++i){
    	temp = (double)IntCon[i];
    	Consts_Integer[i] = temp;
    }
    

    char* StrCon[tot[2]];
    fread(StrCon,sizeof(char*),tot[2],Nicode);
    total_String_Consts = tot[2];
    Consts_String = malloc(sizeof(char*)*total_String_Consts);
    for ( i = 0; i < total_String_Consts; ++i)
    	Consts_String[i] = strdup(StrCon[i]);

    userfunc FuncCon[tot[3]];
    fread(FuncCon,sizeof(userfunc),tot[3],Nicode);
    total_Func_Consts = tot[3];
    Consts_Func = malloc(sizeof(userfunc)*total_Func_Consts);
    for ( i = 0; i < total_Func_Consts; ++i)
    	Consts_Func[i] = FuncCon[i];

    instruction* buffer = malloc(sizeof(instruction)*tot[4]);
    fread(buffer,sizeof(instruction),tot[4],Nicode);
    //instr = buffer;
    total_instr = tot[4];
    instr = malloc(sizeof(instruction)*total_instr);
    for ( i = 0; i < total_instr; ++i){
    	instr[i] = buffer[i];
    	printf("instr[i] %d\n",instr[i].opcode );
    }
   	
	fclose(Nicode);
	return 0;
}

void run_avm(){
	avm_initialize();
	top = AVM_STACKSIZE - (findMaxOffset());
	printf("%d\n",top );
	topsp = top;
	while (executionFinished != 1){
		execute_cycle();
	}
}
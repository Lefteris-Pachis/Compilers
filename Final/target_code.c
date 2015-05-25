#include "target_code.h"

double* 	doubleConsts 			= (double*) 0;
unsigned	total_double_Consts 	= 0;
int* 		intConsts 				= (int*) 0;
int			total_int_Consts 		= 0;
char** 		stringConsts 			= (char**) 0;
int			total_string_Consts 	= 0;
char** 		namedLibfuncs 			= (char**) 0;
int  		total_namedLibfuncs 	= 0;
userfunc*	userFuncs 				= (userfunc*) 0;
int  	total_userFuncs 		= 0;
incomplete_jump* ij_head 			= (incomplete_jump*) 0;
unsigned	ij_total 				= 0;


extern int 		yylineno;
extern quad* 	quads;
extern int 		currQuad;
extern unsigned	i;

instruction*	instructions = (instruction*) 0;
unsigned		totalIn = 0;
unsigned int	currInstr = 0;
char* enum_types[] = {"label", "global", "formal", "local", "number", "string", "bool", "nil", "userfunc", "libfunc", "retval"};

void make_operand(expr* e, vmarg* arg){

	assert(e!=NULL);
	switch (e->type){
		case var_e:
		case assignexpr_e:
		case tableitem_e:
		case arithexpr_e:
		case boolexpr_e:
		case newtable_e:
			assert(e->sym);
			arg->val = e->sym->offset;
			switch(e->sym->space){
				case programVar:	arg->type = global_a; 	break;
				case functionLocal: arg->type = local_a; 	break;
				case formalArg: 	arg->type = formal_a; printf("fffffff\n");	break;
				default: assert(0);
			}
			break;
		case constbool_e:
			arg->val = e->boolConst;
			arg->type = bool_a;
			break;
		case conststring_e:
			arg->val = consts_newstring(e->strConst);
			arg->type = string_a;
			break;
		case constint_e:
			//if(e->sym == NULL){
				arg->val = consts_newint(e->intConst);
				arg->type = integer_a;
			//}
			//else{
			//	arg->val = e->sym->offset;
			//	arg->type = global_a;
			//}
			break;
		case constdouble_e:
			arg->val = consts_newdouble(e->doubleConst);
			arg->type = double_a;
			break;
		case nil_e:
			arg->type = nil_a;
			break;
		case programfunc_e:
			arg->type = userfunc_a;
			arg->val = e->sym->taddress;
			/* or alternatively... */
			/*arg->val = userfuncs_newfunc(e->sym);*/
			/*userfuncs_newfunc(e->sym);*/
			break;
		case libraryfunc_e:
			printf("LIBRARY FUNC OPERAND\n");
			arg->type = libfunc_a;
			//arg->val = libfuncs_newused(e->sym->value.funcVal->name);
			break;
		default: assert(0);
	}
}

void push_func(func_stack* function){

	function->next = f_top;
	f_top = function;
}

func_stack* pop_func(){

	func_stack* tmp;

	if(f_top == NULL)
		return NULL;

	tmp = f_top;
	f_top = f_top->next;
	return tmp;

}

func_stack* top_func(){
	func_stack* tmp;
	if(f_top == NULL)
		return NULL;
	tmp = f_top;
	return tmp;
}




void make_int_operand(vmarg* arg, int val){
	arg->val = consts_newint(val);
	arg->type = integer_a;
}

void make_double_operand(vmarg* arg, double val){
	arg->val = consts_newdouble(val);
	arg->type = double_a;
}

void make_bool_operand(vmarg* arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}
void make_retval_operand(vmarg* arg){
	arg->type = retval_a;
}

void add_incomplete_jump(unsigned instrNo, unsigned iaddress){

	incomplete_jump* tmp = ij_head;

	if(ij_head == NULL){
		ij_head->instrNo = instrNo;
		ij_head->iaddress = iaddress;
		ij_head->next = NULL;
		ij_total++;
	}
	else if(ij_head!=NULL){

		while(tmp!=NULL){

			tmp = tmp->next;
		}

		tmp->instrNo = instrNo;
		tmp->iaddress = iaddress;
		tmp->next = NULL;
		ij_total++;
	}

}
void Print_Instructions(FILE * fp){


	vmopcode op;
	int i = 0;
	char *table_op[25] = {"ASSIGN","ADD","SUB","MUL","DIV","MOD","UMINUS","AND","OR","NOT","JEQ","JNOTEQ",
      "JLESSEQ","JGREATEREQ","JLESS","JGREATER","JUMP","CALL","PUSHARG","ENTERFUNC","EXITFUNC","NEWTABLE","TABLEGETELEM","TABLESETELEM","NOP"};
     char *vmarg_t[12]={"label","global","formal","local","integer","double","string","bool","nil","userfunc","libfunc","retval"};
   FILE* icode = fp;
    for(i=0; i<currInstr; i++){

    	op = (instructions[i]).opcode;

    	fprintf(icode,"%d: %s\t",i,table_op[op]);
    	if((op==add_v) || (op==and_v) || (op==or_v) || (op==sub_v) || (op==mul_v) || (op==div_v) || (op==mod_v) || (op==tablegetelem_v) || (op==tablesetelem_v)){
			fprintf(icode,"%d(%s),%d\t", instructions[i].arg1.type,vmarg_t[instructions[i].arg1.type],instructions[i].arg1.val);
			fprintf(icode,"%d(%s),%d\t", instructions[i].arg2.type,vmarg_t[instructions[i].arg2.type],instructions[i].arg2.val);
			fprintf(icode,"%d(%s),%d\t", instructions[i].result.type,vmarg_t[instructions[i].result.type],instructions[i].result.val);
      	}else if((op==jgt_v) || (op==jge_v)	|| (op==jlt_v) || (op==jle_v) || (op==jne_v) || (op==jeq_v)){
			fprintf(icode,"%d(%s),%d\t", instructions[i].arg1.type,vmarg_t[instructions[i].arg1.type],instructions[i].arg1.val);
			fprintf(icode,"%d(%s),%d\t", instructions[i].arg2.type,vmarg_t[instructions[i].arg2.type],instructions[i].arg2.val);
			fprintf(icode,"%d(%s),%d\t", instructions[i].result.type,vmarg_t[instructions[i].result.type],instructions[i].result.val);
     	}else if((op==not_v) || (op==uminus_v) || (op==assign_v)){
			fprintf(icode,"%d(%s),%d\t", instructions[i].arg1.type,vmarg_t[instructions[i].arg1.type],instructions[i].arg1.val);
			fprintf(icode,"%d(%s),%d\t", instructions[i].result.type,vmarg_t[instructions[i].result.type],instructions[i].result.val);
	 		
      	}else if((op==call_v) ||   (op==funcenter_v) ||  (op==funcexit_v) || (op==newtable_v)){	
			fprintf(icode,"%d(%s),%d\t", instructions[i].result.type,vmarg_t[instructions[i].result.type],instructions[i].result.val);
      	}else{
	 		if(instructions[i].result.type==0 )
	    		fprintf(icode,"%d(%s),%d\t", instructions[i].result.type,vmarg_t[instructions[i].result.type],instructions[i].result.val);
      	//fprintf(icode,"\t\t\tLine: %d", quads[i].line);
    	
    	}
    	fprintf(icode,"\n");
   	
	}
}

void patch_incomplete_jumps(){

	incomplete_jump* tmp = ij_head;

	while(tmp!=NULL){
		if(tmp->iaddress == currQuad){
			instructions[tmp->instrNo].result.val = totalIn;	
		}
		else{
			instructions[tmp->instrNo].result.val = quads[tmp->iaddress].taddress;	
		}
		tmp = tmp->next;
	}
}

void generate_instruction(vmopcode op, quad* quad){
	instruction i;
	i.opcode = op;
	make_operand(quad->arg1,&i.arg1);
	if(quad->arg2!=NULL)
		make_operand(quad->arg2,&i.arg2);
	make_operand(quad->result,&i.result);
	quad->taddress = nextinstructionlabel();
	i.srcLine = quad->line;
	t_emit(&i);
}

void generate_relational_instruction(vmopcode op, quad* quad){

	instruction t;

	t.opcode = op;
	make_operand(quad->arg1,&t.arg1);
	make_operand(quad->arg2,&t.arg2);

	t.result.type = label_a;

	if(quad->label < i){
		t.result.val = quads[quad->label].taddress;
	}
	else{
		add_incomplete_jump(nextinstructionlabel(),quad->label);
	}

	quad->taddress = nextinstructionlabel();
	t_emit(&t);

}






int consts_newdouble(double d){

	total_double_Consts++;

	double* newdoubleConsts = malloc(sizeof(double)*total_double_Consts);

	memcpy(newdoubleConsts,doubleConsts,8*(total_double_Consts-1));
	free(doubleConsts);

	doubleConsts = newdoubleConsts;
	doubleConsts[total_double_Consts-1] = d;

	return total_double_Consts-1;
}


int consts_newint(int d){
	total_int_Consts++;

	int* newintConsts = malloc(sizeof(int)*total_int_Consts);

	memcpy(newintConsts,intConsts,4*(total_int_Consts-1));
	free(intConsts);

	intConsts = newintConsts;

	intConsts[total_int_Consts-1] = d;

	
	return total_int_Consts-1;
}


int consts_newstring(char* s){

	total_string_Consts++;

	char** newstringConsts = malloc(sizeof(char*)*total_string_Consts);

	memcpy(newstringConsts,stringConsts,sizeof(char*)*(total_string_Consts-1));
	free(stringConsts);

	stringConsts = newstringConsts;
	stringConsts[total_string_Consts-1] = strdup(s);

	return total_string_Consts-1;
}

int add_userfunction(symbol f){
	total_userFuncs++;
	userfunc* newuserFuncs = malloc(sizeof(userfunc)*total_userFuncs);
	memcpy(newuserFuncs,userFuncs,sizeof(userfunc)*(total_userFuncs-1));

	free(userFuncs);
	userFuncs=newuserFuncs;
	//printf("Function :: %s\n", f->name);
	userFuncs[total_userFuncs-1].id=strdup(f->name);
	//printf("Function :: %s\n", tmp->id);
	userFuncs[total_userFuncs-1].address=f->taddress;

	userFuncs[total_userFuncs-1].localSize=f->totallocals;

	printf("address  %d\n",userFuncs[total_userFuncs-1].address );

	return total_userFuncs-1;


}

void t_expand(){
	assert(totalIn == currInstr);
	instruction* i = (instruction*)malloc(T_NEW_SIZE);
	if(instructions){
		memcpy(i,instructions,T_CURR_SIZE);
		free(instructions);
	}
	instructions = i;
	totalIn += EXPAND_SIZE;
}

void t_emit(instruction* instruction){
	struct instruction* i;
	printf("currInstr%d\n", currInstr);
	if(currInstr == totalIn)
		t_expand();
	i = instructions + currInstr++;
	i->opcode = instruction->opcode;
	i->arg1 = instruction->arg1;
	i->arg2 = instruction->arg2;
	i->result = instruction->result;
	i->srcLine = instruction->srcLine;
	totalIn++;
}

unsigned int  nextinstructionlabel(){
	return currInstr;
}
void printUserFunction(FILE *fp){

	int i;
   for(i=0; i<total_userFuncs; i++){ 
      fprintf( fp, "\n%d: %s %d %d ", i, userFuncs[ i].id, userFuncs[ i ].address, userFuncs[ i ].localSize);
   }
   fprintf(fp,"\n\n\n");
   return;

}

void printConsts(){
	int i = 0;
	

	FILE* fp = fopen("const.txt","w");
	fprintf(fp, "total_int_Consts : %d\n", total_int_Consts);
	fprintf(fp, "total_double_Consts : %d\n", total_double_Consts);
	fprintf(fp, "total_string_Consts : %d\n", total_string_Consts);
	fprintf(fp, "total_userFuncs : %d\n", total_userFuncs);

	for(i=0; i<total_int_Consts ; i++){

		fprintf(fp, "INT -------- %d  %d\n", i, intConsts[i]);

	}

	for(i=0; i<total_double_Consts ; i++){

		fprintf(fp, "DOUBLE -------- %d %f\n",i, doubleConsts[i]);

	}

	for(i=0; i<total_string_Consts ; i++){

		fprintf(fp, "STR -------- %d  %s\n", i, stringConsts[i]);

	}
	printUserFunction(fp);

	fprintf( fp, "\n\n\n");
	Print_Instructions(fp);
	fclose(fp);
}


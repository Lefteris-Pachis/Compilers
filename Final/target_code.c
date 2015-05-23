#include "target_code.h"

double* 	numberConsts 			= (double*) 0;
unsigned	total_number_Consts 	= 0;
char** 		stringConsts 			= (char**) 0;
unsigned 	total_string_Consts 	= 0;
char** 		namedLibfuncs 			= (char**) 0;
unsigned 	total_namedLibfuncs 	= 0;
userfunc* 	userFuncs 				= (userfunc*) 0;
unsigned 	total_userFuncs 		= 0;

extern int 		yylineno;
extern quad* 	quads;

instruction*	instructions = (instruction*) 0;
unsigned		totalIn = 0;
unsigned int	currInstr = 0;
char* enum_types[] = {"label", "global", "formal", "local", "number", "string", "bool", "nil", "userfunc", "libfunc", "retval"};

void make_operand(expr* e, vmarg* arg){
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
				case programVar:	arg->type = global_a;	break;
				case functionLocal: arg->type = local_a; 	break;
				case formalArg: 	arg->type = formal_a; 	break;
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
				arg->val = consts_newnumber(e->intConst);
				arg->type = integer_a;
			//}
			//else{
			//	arg->val = e->sym->offset;
			//	arg->type = global_a;
			//}
			break;
		case constdouble_e:
			arg->val = consts_newnumber(e->doubleConst);
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

void make_number_operand(vmarg* arg, int val){
	arg->val = consts_newnumber(val);
	arg->type = number_a;
}

void make_bool_operand(vmarg* arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}
void make_retval_operand(vmarg* arg){
	arg->type = retval_a;
}

void add_incomplete_jump(unsigned instrNo, unsigned iaddress){

}

void generate_instruction(vmopcode op, quad* quad){
	instruction i;
	i.opcode = op;
	make_operand(quad->arg1,&i.arg1);
	make_operand(quad->arg2,&i.arg2);
	make_operand(quad->result,&i.result);
	quad->taddress = nextinstructionlabel();
	i.srcLine = quad->line;
	t_emit(&i);
}

void generate_relational_instruction(vmopcode op, quad* quad){

}

void generate_param_instruction(quad* quad){

}

void generate_call_instruction(quad* quad){

}

void generate_retval_instruction(quad* quad){

}

void generate_funcstart_instruction(quad* quad){

}

void generate_funcend_instruction(quad* quad){

}

void generate_return_instruction(quad* quad){

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
	if(currInstr == totalIn)
		t_expand();
	i = instructions + currInstr++;
	i->opcode = instruction->opcode;
	i->arg1 = instruction->arg1;
	i->arg2 = instruction->arg2;
	i->srcLine = instruction->srcLine;
	totalIn++;
}

unsigned nextinstructionlabel(){
	return currInstr;
}

void Print_Instructions(){
	FILE *instruction_file;
	int counter;

	char* vm_opcodes[]={ 	"ASSIGN", "ADD", "SUB",
				"MUL", "DIV", "MOD",
				"UMINUS", "AND", "OR",
				"NOT", "JEQ", "JNE",
				"JLE", "JGE", "JLT",
				"JGT", "JUMP", "CALL",
				"PARAM", "FUNCENTER", "FUNCEXIT",
				"NEWTABLE", "TABLEGETELEM", "TABLESETELEM",
				"NOP"
	};

	
	instruction_file = fopen("instructions.txt", "w");
	
	fprintf(instruction_file, "******************************************************INSTRUCTIONS TABLE*****************************************************\n\n");
	
	fprintf(instruction_file, "Instruction Number|	Operation	|	Argument 1	|	Argument 2	|	Result		| SrcLine\n");
	
	fprintf(instruction_file, "_____________________________________________________________________________________________________________________________\n\n");
	
	for (counter = 0; counter<currInstr; counter++){
		
		fprintf(instruction_file, "%d:		  |", counter+1);

		if ( (((instructions + counter)->opcode >= 11) && ((instructions + counter)->opcode <=13)) || ((instructions + counter)->opcode == 15) || ((instructions + counter)->opcode ==19) || (((instructions + counter)->opcode >=21) && ((instructions + counter)->opcode <=23)) ){

			fprintf(instruction_file, "	%s	|", vm_opcodes[(instructions + counter)->opcode]);
		}else{
			
			fprintf(instruction_file, "	%s		|", vm_opcodes[(instructions + counter)->opcode]);
		}

		//if ( ((instructions + counter)->arg1.type) != null_a ){

			
			fprintf(instruction_file, " %d(%s), ", (instructions + counter)->arg1.type, enum_types[(instructions + counter)->arg1.type]);
			
			if ( ((instructions + counter)->arg1.type >= 0 ) && ((instructions + counter)->arg1.type <=3)){
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg1.val);
			}
			else if ((instructions + counter)->arg1.type == 4){

				fprintf(instruction_file, "%d: %f", (instructions + counter)->arg1.val, consts_getnumber((instructions + counter)->arg1.val));
			}
			else if ((instructions + counter)->arg1.type == 5){
				
				fprintf(instruction_file, "%d: %s", (instructions + counter)->arg1.val, consts_getstring((instructions + counter)->arg1.val));
			}
			else if ((instructions + counter)->arg1.type == 6){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg1.val);
			}
			else if ((instructions + counter)->arg1.type == 7){
				
				fprintf(instruction_file, "nil");
			}
			else if ((instructions + counter)->arg1.type == 8){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg1.val);
			}
			else if ((instructions + counter)->arg1.type == 9){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg1.val);
			}
			else if ((instructions + counter)->arg1.type == 10){
				
				/* fprintf(instruction_file, "%d: ", ); */
			}
			fprintf(instruction_file, "	|");
		//}
		//else fprintf(instruction_file, " NULL	|");
		
		
		//if ( ((instructions + counter)->arg2.type) != null_a ){


			fprintf(instruction_file, " %d(%s), ", (instructions + counter)->arg2.type, enum_types[(instructions + counter)->arg2.type]);
			
			if ( ((instructions + counter)->arg2.type >= 0 ) && ((instructions + counter)->arg2.type <=3)){
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg2.val);
			}
			else if ((instructions + counter)->arg2.type == 4){

				fprintf(instruction_file, "%d: %f", (instructions + counter)->arg2.val, consts_getnumber((instructions + counter)->arg2.val));
			}
			else if ((instructions + counter)->arg2.type == 5){
				
				fprintf(instruction_file, "%d: %s", (instructions + counter)->arg2.val, consts_getstring((instructions + counter)->arg2.val));
			}
			else if ((instructions + counter)->arg2.type == 6){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg2.val);
			}
			else if ((instructions + counter)->arg2.type == 7){
				
				fprintf(instruction_file, "nil");
			}
			else if ((instructions + counter)->arg2.type == 8){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg2.val);
			}
			else if ((instructions + counter)->arg2.type == 9){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->arg2.val);
			}
			else if ((instructions + counter)->arg2.type == 10){
				
				/* fprintf(instruction_file, "%d: ", ); */
			}
			fprintf(instruction_file, "	|");
		//}
		//else fprintf(instruction_file, " NULL	|");
		
		
		//if ( ((instructions + counter)->result.type) != null_a ){


			fprintf(instruction_file, " %d(%s), ", (instructions + counter)->result.type, enum_types[(instructions + counter)->result.type]);
			
			if((instructions + counter)->result.type == 0){
				fprintf(instruction_file, "%d: ", (instructions + counter)->result.val + 1);
			}
			else if ( ((instructions + counter)->result.type > 0 ) && ((instructions + counter)->result.type <=3)){
				fprintf(instruction_file, "%d: ", (instructions + counter)->result.val);
			}
			else if ((instructions + counter)->result.type == 4){
				
				fprintf(instruction_file, "%d: %f", (instructions + counter)->result.val, consts_getnumber((instructions + counter)->result.val));
			}
			else if ((instructions + counter)->result.type == 5){
				
				fprintf(instruction_file, "%d: %s", (instructions + counter)->result.val, consts_getstring((instructions + counter)->result.val));
			}
			else if ((instructions + counter)->result.type == 6){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->result.val);
			}
			else if ((instructions + counter)->result.type == 7){
				
				fprintf(instruction_file, "nil");
			}
			else if ((instructions + counter)->result.type == 8){
				
				fprintf(instruction_file, "%d: ", (instructions + counter)->result.val);
			}
			else if ((instructions + counter)->result.type == 9){
				printf("CURR NAMED LIB FUNCS IS: %d", (instructions + counter)->result.val);
				fprintf(instruction_file, "%d: ", (instructions + counter)->result.val);
			}
			else if ((instructions + counter)->result.type == 10){
				
				/* fprintf(instruction_file, "%d: ", ); */
			}
			fprintf(instruction_file, "	|");
		//}
		//else fprintf(instruction_file, " NULL	|");
		
		fprintf(instruction_file, " %d", (instructions + counter)->srcLine);
		
		fprintf(instruction_file, "\n\n");

	}
	fprintf(instruction_file, "\n");
	fclose(instruction_file);
}
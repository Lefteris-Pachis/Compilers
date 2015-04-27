#include "quads.h"

#include <stdio.h>

extern int scope_count;
extern int yylineno;

quad*			quads = (quad*) 0;
unsigned		total = 0;
unsigned int 	currQuad = 0;
int 			temp_counter = 0; 
unsigned		programVarOffset = 0;
unsigned 		functionLocalOffset = 0;
unsigned 		formalArgOffset = 0;
unsigned 		scopeSpaceCounter = 1;

/*QUADS FUNCTIONS*/
void expand(void){
	assert(total == currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if(quads) {
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads= p;
	total += EXPAND_SIZE;
}

void emit(iopcode op, expr* arg1, expr* arg2, expr* result){
	if(currQuad == total)
		expand();
	quad* p 	= quads + currQuad++;
	p->op 		= op;
	p->arg1		= arg1;
	p->arg2 	= arg2;
	p->result 	= result;
	p->label 	= currQuad;
	p->line 	= yylineno;
	total++;
}

void emit_jump(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned label){
	if (currQuad == total) 
		expand();
	quad* p 	= quads + currQuad++;
	p->op 		= op;
	p->arg1 	= arg1;
	p->arg2 	= arg2;
	p->result 	= result;
	p->label 	= label;
	p->line 	= yylineno;
	total++;
}

expr* emit_iftableitem(expr* e){
	if(e->type != tableitem_e)
		return e;
	else{
		expr* result = newexpr(var_e);
		result->sym = new_temp();
		emit(tablegetelem,e,e->index,result);
		return result;
	}
}

unsigned next_quad_label(){
	return currQuad+1;
}

/*TEMP VARIABLES FUNCTIONS*/
char* new_temp_name(){
	char * t_id=malloc(102);
 	strcpy(t_id, "_t");
 	char buffer[100];
 	sprintf(buffer, "%d",temp_counter);
 	strcat(t_id, buffer);
 	temp_counter++;
 	return(t_id);
}

void reset_temp(){
	temp_counter = 0;
}

symbol new_temp(){
	char* name = new_temp_name();
	Insert_to_Hash(mytable,name,var_s,scope_count,yylineno);
	symbol sym = Lookup(mytable,name,scope_count);
	if(sym)
		return sym;
	else
		return NULL;
}

unsigned int istempname(char* s){
	return *s == '_';
}

/*SCOPE SPACE FUNCTIONS*/
scopespace_t CurrScopeSpace(void){
	if(scopeSpaceCounter == 1)
		return programVar;
	else if(scopeSpaceCounter % 2 == 0)
		return formalArg;
	else
		return functionLocal;
}

void EnterScopeSpace(void){
	scopeSpaceCounter++;
}

void ExitScopeSpace(void){
	assert(scopeSpaceCounter > 1);
	scopeSpaceCounter--;
}

/*SCOPE OFFSET FUNCTIONS*/
unsigned CurrScopeOffset(void){
	switch(CurrScopeSpace()){
		case programVar: 	return programVarOffset;
		case functionLocal:	return functionLocalOffset;
		case formalArg: 	return formalArgOffset;
		default: assert(0);
	}
}

void IncCurrScopeOffset(void){
	switch(CurrScopeSpace()){
		case programVar: 	++programVarOffset; break;
		case functionLocal:	++functionLocalOffset; break;
		case formalArg: 	++formalArgOffset; break;
		default: assert(0);
	}
}

/*EXPRESSION FUNCTIONS*/
expr* lvalue_expr(symbol sym){
	assert(sym);
	expr* e = (expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->next = (expr*) 0;
	e->sym = sym;

	switch(sym->type){
		case var_s:			e->type = var_e; break; 
		case programfunc_s:	e->type = programfunc_e; break;
		case libraryfunc_s:	e->type = libraryfunc_e; break;
		default: assert(0);
	}
	return e;
}

expr* newexpr(expr_t t){
	expr* e = (expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->type = t;
	return e;
}

expr* newexpr_conststring(char* s){
	expr* e = newexpr(conststring_e);
	e->strConst = strdup(s);
	return e;
}

expr* newexpr_constint(int num){
	expr* e = newexpr(constint_e);
	e->intConst = num;
	return e;
}

expr* newexpr_constdouble(double num){
	expr* e = newexpr(constdouble_e);
	e->doubleConst = num;
	return e;
}

expr* newexpr_constbool(unsigned char x){
	expr* e = newexpr(constbool_e);
	e->boolConst = x;
	return e;
}

void checkuminus(expr* e){
	if(	e->type == constbool_e		||
		e->type == conststring_e	||
		e->type == nil_e			||
		e->type == newtable_e		||
		e->type == programfunc_e 	||
		e->type == libraryfunc_e 	||
		e->type == boolexpr_e)
		printf("Compile Error: Illegal expr to unary -\n");
}

unsigned int istempexpr(expr* e){
	return 	e->sym &&
			e->sym->type == var_s &&
			istempname(e->sym->name);
}

void Print_Quads(void){
	FILE *icode;
	iopcode op;
	int i = 0;
	char *table_op[26] = {"ASSIGN","ADD","SUB","MUL","DIV","MOD","UMINUS","AND","OR","NOT","IF_EQ","IF_NOTEQ",
      "IF_LESSEQ","IF_GREATEREQ","IF_LESS","IF_GREATER","CALL","PARAM","RETURN","GETRETVAL","FUNCSTART",
      "FUNCEND","TABLECREATE","JUMP","TABLEGETELEM","TABLESETELEM"};
    icode = fopen("icode.txt","w");
    for(i=0; i<currQuad; i++){
    	op = (quads[i]).op;
    	fprintf(icode,"%d: %s\t ",i+1,table_op[op]);
    	if((op==add) || (op==and) || (op==or) || (op==sub) || (op==mul) || (op==divv) || (op==mod) || (op==tablegetelem) || (op==tablesetelem)){
			fprintf(icode,"%s\t ", print_expr(quads[i].arg1));
			fprintf(icode,"%s\t ", print_expr(quads[i].arg2));
			fprintf(icode,"%s\t ", print_expr(quads[i].result));
      	}else if((op==if_greater) || (op==if_greatereq)	|| (op==if_less) || (op==if_lesseq) || (op==if_noteq) || (op==if_eq)){
			fprintf(icode,"%s\t ", print_expr(quads[i].arg1));
			fprintf(icode,"%s\t ", print_expr(quads[i].arg2));
			fprintf(icode,"%d ", quads[i].label);
     	}else if((op==not) || (op==uminus) || (op==assign)){
			fprintf(icode,"%s\t ", print_expr(quads[i].arg1));
			fprintf(icode,"%s\t ", print_expr(quads[i].result));
      	}else if(op==jump){
	 		fprintf(icode,"%d ", quads[i].label);	 
      	}else if((op==call)	|| (op==param) || (op==getretval) ||  (op==funcstart) ||  (op==funcend) || (op==tablecreate)){	
			fprintf(icode,"%s\t ", print_expr(quads[i].result));
      	}else{
	 		if(quads[i].result!= NULL)
	    		fprintf(icode,"%s\t ", print_expr(quads[i].result));
      	}
    	fprintf(icode,"\n");
    }
    fclose(icode);
   	return;
}

static char *print_expr(expr * expression){
	if (!expression) return " ";
   	expr_t type = expression->type;
   	char *tmp;
   	tmp=malloc(1000*sizeof(char));
   	if (type==var_e){
    	return (expression->sym)->name;
   	}else if(type==tableitem_e){
    	return (expression->sym)->name;
   	}else if(type==libraryfunc_e){
    	return (expression->sym)->name;
   	}else if(type==arithexpr_e){
    	return (expression->sym)->name;
   	}else if(type==constint_e){
    	sprintf(tmp, "%d", expression->intConst);
    	return tmp;
   	}else if(type==constdouble_e){
    	sprintf(tmp, "%lf", expression->doubleConst);
    	return tmp;
   	}else if(type==constbool_e){
    	if (expression->boolConst=='0')return "FALSE";
    	else return "TRUE";
   	}else if(type==conststring_e){
    	char *tmp = malloc(strlen(expression->strConst)+2);
    	tmp[0]= '\"';
	  	tmp = strcat(tmp,expression->strConst);
		tmp[strlen(tmp)] = '\"';
		return tmp;
        // return expression->strConst;
   	}else if(type==newtable_e){
   		return (expression->sym)->name;
   	}else if(type==nil_e){
    	return "NIL";
   	}else if(type==programfunc_e){
    	return (expression->sym)->name;
   	}else if(type==boolexpr_e){
    	return (expression->sym)->name;
   	}else if(type==assignexpr_e){
    	return (expression->sym)->name;
   	}else{
		printf("RESULT:%d\n", type);
		printf("%d\n", expression->type); 
    	assert(0);
   	}
}
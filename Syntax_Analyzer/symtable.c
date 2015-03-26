/* Hatzidakis Emmanouil AM:2571*/
#include "symtable.h"



int SymTable_hash(const char *str)
{
    int c;
    int sum=0;
    int hash;

    while (c = *str++)
    	sum = sum+c;
    hash = sum%BUCKETS;

    return hash;
}


SymTable_T SymTable_new(void)
{
	SymTable_T myhash;
	node_t node;
	int i=0;

	myhash=malloc(sizeof(struct table));

	node=malloc(sizeof(struct Node));

	node->var_name = NULL;
	node->var_type = NULL;
	node->scope = 0;
	node->line = 0;
	node->func_name = NULL;
	node->func_type = NULL;
	node->func_args = NULL;
	node->hiden = 0;
	node->next = NULL;

	while(i<BUCKETS)
	{
		myhash->hashtable[i] = node;
		i++;
	}

	return myhash;
}

void SymTable_free(SymTable_T oSymTable)
{
	/*int i = 0;
	node_t makefree;
	node_t parse;

	assert(oSymTable!=NULL);

	while(i<BUCKETS)
	{
		parse = oSymTable->hashtable[i];

		while(parse!=NULL)
		{
			makefree = parse->next;
			free(parse->var_name);
			free(parse);
			parse = makefree;
		}
		i++;
	}
	
	free(parse);
	free(oSymTable);*/
}


int Insert_Var(SymTable_T oSymTable, const char *var_name, const char *var_type, int var_scope, int var_line)
{
	int hashcode=SymTable_hash(var_name);
	node_t put;
	node_t parse;

	//assert(oSymTable!=NULL && var_name!=NULL);

	/*if(Lookup(oSymTable,var_name)==0)	
		return -1;*/

	put=malloc(sizeof(struct Node));

	put->var_name=malloc((strlen(var_name)+1)*sizeof(char));
	put->var_name = strdup(var_name);

	put->var_type=malloc((strlen(var_type)+1)*sizeof(char));
	put->var_type = strdup(var_type);

	put->scope = var_scope;

	put->line = var_line;

	put->hiden = 0;

	put->next = NULL;


	if(oSymTable->hashtable[hashcode]->var_name==NULL && oSymTable->hashtable[hashcode]->func_name==NULL)
	{
		oSymTable->hashtable[hashcode] = put;

	}
	else{
		parse = oSymTable->hashtable[hashcode];
		put->next = parse;
		parse = put;
		oSymTable->hashtable[hashcode] = parse;
	}


	return 1;
}

int Insert_Func(SymTable_T oSymTable, const char *func_name, const char *func_type, const char *func_args, int func_scope, int func_line, int called)
{
	int hashcode;
	if(func_name != NULL)
		hashcode = SymTable_hash(func_name);
	else
		hashcode = 0;

	node_t put;
	node_t parse;

	assert(oSymTable!=NULL);

	/*if(Lookup(oSymTable,func_name)==0)	
		return -1;*/

	put=malloc(sizeof(struct Node));

	if(func_name != NULL){
		
		put->func_name=malloc((strlen(func_name)+1)*sizeof(char));
		put->func_name = strdup(func_name);
	}

	if(func_type != NULL){
		
		put->func_type=malloc((strlen(func_type)+1)*sizeof(char));
		put->func_type = strdup(func_type);
	}

	if(func_args != NULL){
		
		put->func_args=malloc((strlen(func_args)+1)*sizeof(char));
		put->func_args = strdup(func_args);
	}

	put->scope = func_scope;

	put->line = func_line;

	put->hiden = 0;

	put->called = called;

	put->next = NULL;

	
	if(oSymTable->hashtable[hashcode]->var_name==NULL && oSymTable->hashtable[hashcode]->func_name==NULL)
	{
		oSymTable->hashtable[hashcode] = put;

	}
	else{
		parse = oSymTable->hashtable[hashcode];
		put->next = parse;
		parse = put;
		oSymTable->hashtable[hashcode] = parse;
	}


	return 1;
}

void Hide(SymTable_T oSymTable, int scope)
{
	node_t parse;

	int i=0;

	while(i<BUCKETS){

		parse= oSymTable->hashtable[i];
		while(parse)
		{
			if(parse->scope!=scope)
			{
				parse->hiden = 1;
			}
			else if(parse->scope == scope)
			{
				parse->hiden = 0;
			}
			parse = parse->next;
		}
	}
}

node_t Lookup(SymTable_T oSymTable, const char *name)
{
	assert(name != NULL && oSymTable != NULL);
	int hashcode=SymTable_hash(name);
	node_t parse=oSymTable->hashtable[hashcode];


	while(parse!=NULL)
	{
		if(parse->var_name!=NULL && parse->func_name==NULL){
			if(strcmp(parse->var_name,name) == 0)
				return parse;
		}
		else if(parse->var_name==NULL && parse->func_name!=NULL)
		{
			if(strcmp(parse->func_name,name) == 0)
				return parse;
		}
		parse=parse->next;
	}
	return NULL;
}

void Print_Hash(SymTable_T oSymTable)
{
	node_t parse;

	int i=0;

	while(i<BUCKETS){

		parse= oSymTable->hashtable[i];
		while(parse)
		{
			if(parse->var_name == NULL)
			{
				if(parse->func_type != NULL){
					if(parse->func_name != NULL)
						printf(" Function Name = %s ", parse->func_name);
					else
						printf(" Function Name = ");
					if(parse->func_args != NULL)
						printf(" Function Arguments = %s", parse->func_args);
					else
						printf(" Function Arguments = ");
					printf(" Function Type = %s ", parse->func_type);
					printf(" Function Scope = %d \n", parse->scope);
				}
			}
			else if(parse->var_name != NULL && parse->func_name == NULL)
			{
				printf(" Variable Name = %s ", parse->var_name);
				printf(" Variable Type = %s ", parse->var_type);
				printf(" Variable Scope = %d \n", parse->scope);
			}
			//printf("\n");
			parse = parse->next;
		}

		i++;
	}
}

/*int main(){

	SymTable_T mytable = SymTable_new();

	Insert_Var(mytable, "giwrgadakis", "pro" , 0, 1);
	Insert_Func(mytable, "giwrgadakis", "pro","x,y" , 0, 1);

	Print_Hash(mytable);
}*/
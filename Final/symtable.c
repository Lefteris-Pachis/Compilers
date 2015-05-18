#include "symtable.h"
int func_id_un=0;


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
A_list Insert_args(symbol node, char *arg_name){
	A_list tmp;
	A_list head = node->args;

	if(arg_name!=NULL){
		tmp = malloc(sizeof(struct Args));
		tmp->arg = malloc((strlen(arg_name)+1)*sizeof(char));
		tmp->arg = strdup(arg_name);
		tmp->next = NULL;
	}

	if(head==NULL){
		head = tmp;
		tail = head;
		return head;	
	}
	if(head->next == NULL){
		head->next = tmp;
		tail = tmp;
	}
	else{
		tail->next = tmp;
		tail = tmp;
	}

	return  head;	
}

void Print_args(symbol node){
	printf(" | Arguments = ");
	A_list head = node->args;
	while(head!=NULL){
		if(head->next != NULL)
			printf("%s ,",head->arg);
		else
			printf(" %s",head->arg);
		head=head->next;
	}
}

/*create Function_id*/
 char* Create_Function_Id(void){
 	char * f_id=malloc(102);
 	strcpy(f_id, "_F");
 	char buffer[100];
 	sprintf(buffer, "%d",func_id_un);
 	strcat(f_id, buffer);
 	func_id_un++;
 	return(f_id);
 }



SymTable_T SymTable_new(void)
{
	SymTable_T myhash;
	symbol node;
	int i=0;

	myhash=malloc(sizeof(struct table));

	node=malloc(sizeof(struct symbol));

	node->name = NULL;
	node->scope = 0;
	node->line = 0;
	node->args = NULL;
	node->hiden = 0;
	node->offset = 0;
	node->next = NULL;

	while(i<BUCKETS)
	{
		myhash->hashtable[i] = node;
		i++;
	}

	Insert_to_Hash(myhash,"print",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"input",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"objectmemberkeys",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"objecttotalmembers",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"objectcopy",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"totalarguments",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"arguments",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"typeof",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"strtonum",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"sqrt",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"cos",libraryfunc_s, 0,0);
	Insert_to_Hash(myhash,"sin",libraryfunc_s, 0,0);

	return myhash;
}

void SymTable_free(SymTable_T oSymTable)
{
	/*int i = 0;
	symbol makefree;
	symbol parse;

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


int Insert_to_Hash(SymTable_T oSymTable, const char *name, symbol_t type, unsigned scope, unsigned line)
{
	int hashcode=SymTable_hash(name);
	symbol put;
	symbol parse;

	assert(oSymTable!=NULL && name!=NULL);

	put=malloc(sizeof(struct symbol));

	put->name=malloc((strlen(name)+1)*sizeof(char));
	put->name = strdup(name);
	put->type = type;
	put->scope = scope;
	put->line = line;
	put->hiden = 0;
	put->next = NULL;
	put->space = CurrScopeSpace();
	put->offset = CurrScopeOffset();


	if(oSymTable->hashtable[hashcode]->name==NULL)
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
	if(scope != 0){
		symbol parse;
		int i = 0;
		while(i<BUCKETS){
			parse = oSymTable->hashtable[i];
			while(parse){
					if(parse->scope == scope)
						parse->hiden = 1;
				parse = parse->next;
			}
			i++;
		}
	}
}

symbol Lookup

(SymTable_T oSymTable, const char *name ,  int scope)
{	
	int hashcode=SymTable_hash(name);
	symbol parse=oSymTable->hashtable[hashcode];

	if(scope == -1)
	{
		while(parse!=NULL)
		{
			if(parse->name != NULL){
				if(strcmp(parse->name,name) == 0 && parse->hiden == 0)
					return parse;
			}
			parse=parse->next;
		}
	}
	else
	{
		while(parse!=NULL)
		{
			if(parse->name!=NULL && parse->scope == scope){
				if((strcmp(parse->name,name) == 0) && parse->hiden == 0)
					return parse;
			}
			parse=parse->next;
		}
	}
	return NULL;
}

void Print_Hash(SymTable_T oSymTable)
{
	symbol parse;
	int i=0;
	printf("-------------------HASHTABLE-------------------\n");
	while(i<BUCKETS){
		
		parse= oSymTable->hashtable[i];
		while(parse != NULL)
		{
			if(parse->line != 0){
				printf("Bucket : %d\n",i );
				if(parse->type != var_s)
				{
					if(parse->type != libraryfunc_s){
						printf(" Function -->");
						printf(" | Line = %d ",parse->line);
						printf(" | Name = %s ", parse->name);
						Print_args(parse);
						printf(" | Scope = %d ", parse->scope);
						printf(" | Hidden = %d |\n",parse->hiden);
					}
				}
				else if(parse->type == var_s)
				{
					printf(" Variable -->");
					printf(" | Line = %d ",parse->line);
					printf(" | Name = %s ", parse->name);
					printf(" | Scope = %d ", parse->scope);
					printf(" | Hidden = %d ",parse->hiden);
					printf(" | Offset = %d \n",parse->offset);
				}
			}
			parse = parse->next;
		}
		i++;
	}
	printf("-----------------------------------------------\n");
}
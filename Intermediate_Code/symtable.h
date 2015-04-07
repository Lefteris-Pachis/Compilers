#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_

#define BUCKETS 100

typedef enum scopespace_t { 
	programvar,
	functionlocal,
	formalarg				
 }scopespace_t;

 typedef enum symbol_t { var_s, programfunc_s, libraryfunc_s }symbol_t;

typedef struct Args{
	char* arg;
	struct Args *next;
}*A_list;

struct Args *tail;

typedef struct Node{
	symbol_t 		type;
	char*			name;
	scopespace_t	space;
	unsigned		offset;
	char* var_name;
	char* var_type;

	char* func_name;
	char* func_type;
	A_list args;

	unsigned scope;
	unsigned line;
	int hiden;

	struct Node *next;
}*node_t;


typedef struct table{

	node_t hashtable[BUCKETS];
}*SymTable_T;
/* my symbol table structure */
SymTable_T mytable;
/* returns a new empty item of type SymTable_T */
SymTable_T SymTable_new();

/* frees all memory used by oSymtable */
void SymTable_free(SymTable_T oSymTable);

/* inserts a new binding in oSymTable. Returns True on success and False on failure */
int Insert_Var(SymTable_T oSymTable, const char *var_name, const char *var_type, int var_scope, int var_line);

int Insert_Func(SymTable_T oSymTable, const char *func_name, const char *func_type, int func_scope, int func_line);

/* removes the binding of given pcKey. Returns True on success and False on failure */
void Hide(SymTable_T oSymTable,int scope);

/* Returns True if binding with given pcKey is found or False on failure */
node_t Lookup(SymTable_T oSymTable, const char *name , int scope);

/* Print the list of args */
void Print_args(node_t node);
char* Create_Function_Id();
void Print_Hash(SymTable_T oSymTable);
A_list Insert_args(node_t node, char *arg_name);


#endif
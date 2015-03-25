

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_

#define BUCKETS 100


typedef struct Node{
	char* var_name;
	char* var_type;

	char* func_name;
	char* func_type;
	char* func_args;

	int scope;
	int line;
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

int Insert_Func(SymTable_T oSymTable, const char *func_name, const char *func_type, const void *func_args, int func_scope, int func_line);

/* removes the binding of given pcKey. Returns True on success and False on failure */
int Hide(SymTable_T oSymTable, const char *name, int line, int hiden);

/* Returns True if binding with given pcKey is found or False on failure */
int Lookup(SymTable_T oSymTable, const char *name, int line, int scope);


void Print_Hash(SymTable_T oSymTable);


#endif
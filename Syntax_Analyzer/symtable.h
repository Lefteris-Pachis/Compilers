 

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_


struct table{
	char* var_name;
	char* var_type;
	int var_scope;
	int var_line;
	char* func_name;
	char* func_type;
	char* func_args;
	int func_scope;
	int func_line;
	struct Node *next;
};

/* my symbol table structure */
typedef struct table *SymTable_T;

/* returns a new empty item of type SymTable_T */
SymTable_T SymTable_new();

/* frees all memory used by oSymtable */
void SymTable_free(SymTable_T oSymTable);

/* inserts a new binding in oSymTable. Returns True on success and False on failure */
int Insert(SymTable_T oSymTable, const char *symbol, const char *name, const void *type, int scope, const char* formal_args, int line);

/* removes the binding of given pcKey. Returns True on success and False on failure */
int Hide(SymTable_T oSymTable, const char *symbol, const char *name, int line);

/* Returns True if binding with given pcKey is found or False on failure */
int Lookup(SymTable_T oSymTable, const char *symbol, const char *name, int line);


#endif
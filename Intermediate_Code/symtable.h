#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_

#define BUCKETS 100

typedef enum scopespace_t { 
	programVar,
	functionLocal,
	formalArg,
 }scopespace_t;

 typedef enum symbol_t { var_s, programfunc_s, libraryfunc_s }symbol_t;

typedef struct Args{
	char* arg;
	struct Args *next;
}*A_list;

struct Args *tail;

typedef struct symbol{
	symbol_t 		type;
	char*			name;
	scopespace_t	space;
	unsigned		offset;
	A_list args;

	unsigned scope;
	unsigned line;
	int hiden;
	struct symbol *next;
}*symbol;


typedef struct table{
	symbol hashtable[BUCKETS];
}*SymTable_T;
/* my symbol table structure */
SymTable_T mytable;
/* returns a new empty item of type SymTable_T */
SymTable_T SymTable_new();

/* frees all memory used by oSymtable */
void SymTable_free(SymTable_T oSymTable);

/* inserts a new binding in oSymTable. Returns True on success and False on failure */
int Insert_to_Hash(SymTable_T oSymTable, const char *name, symbol_t type, unsigned scope, unsigned line);

//int Insert_Func(SymTable_T oSymTable, const char *func_name, const char *func_type, int func_scope, int func_line);

/* removes the binding of given pcKey. Returns True on success and False on failure */
void Hide(SymTable_T oSymTable,int scope);

/* Returns True if binding with given pcKey is found or False on failure */
symbol Lookup(SymTable_T oSymTable, const char *name , int scope);

/* Print the list of args */
void Print_args(symbol node);
char* Create_Function_Id();
void Print_Hash(SymTable_T oSymTable);
A_list Insert_args(symbol node, char *arg_name);


#endif
#ifndef AVM_H
#define AVM_H

#include "target_code.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exec_func.h"

#define AVM_STACKSIZE 			4096
#define AVM_WIPEOUT(m) 			memset(&(m),0,sizeof(m))
#define AVM_TABLE_HASHSIZE 		211
#define AVM_STACKENV_SIZE 		4
#define AVM_NUMACTUALS_OFFSET 	4
#define	AVM_SAVEDPC_OFFSET 		3
#define	AVM_SAVEDTOP_OFFSET		2
#define	AVM_SAVEDTOPSP_OFFSET 	1
#define VMLIB_CURR_SIZE			(totalVMlibs*sizeof(char*))
#define VMLIB_NEW_SIZE			(EXPAND_SIZE*sizeof(char*) + VMLIB_CURR_SIZE)

typedef enum avm_memcell_t{
	number_m  	= 0,
	string_m 	= 1,
	bool_m 		= 2,
	table_m 	= 3,
	userfunc_m 	= 4,
	libfunc_m 	= 5,
	nil_m 		= 6,
	undef_m 	= 7
}avm_memcell_t;

typedef struct avm_table avm_table;

typedef struct avm_memcell {
	avm_memcell_t type;
	union{
		double 			numVal;
		char* 			strVal;
		unsigned char	boolVal;
		avm_table* 		tableVal;
		unsigned 		funcVal;
		char* 			libfuncVal;
	}data;
}avm_memcell;

typedef struct avm_table_bucket{
	avm_memcell key;
	avm_memcell value;
	struct avm_table_bucket* next;
}avm_table_bucket;

struct avm_table{
	unsigned 			refCounter;
	avm_table_bucket*	strIndexed[AVM_TABLE_HASHSIZE];
	avm_table_bucket* 	numIndexed[AVM_TABLE_HASHSIZE];
	unsigned 			total;
};

typedef void (*memclear_func_t)(avm_memcell *);
typedef void (*library_func_t) (void);
typedef char* (*tostring_func_t) (avm_memcell*);
typedef unsigned char (*tobool_func_t) (avm_memcell*);


avm_table* 		avm_tablenew(void);
void 			avm_tabledestroy(avm_table* t);
avm_memcell* 	avm_tablegetelem(avm_table* table,avm_memcell* index);
void 			avm_tablesetelem(avm_table* table,avm_memcell* index, avm_memcell* content);
void 			avm_bucketsinit(avm_table_bucket** p);
void 			avm_tablebucketsinit (avm_table_bucket** p);
void 			avm_tablebucketsdestroy(avm_table_bucket** p);
void 			avm_tableincrefcounter(avm_table* t);
void 			avm_tabledecrefcounter(avm_table* t);


void 			avm_memclear(avm_memcell* m);
void 			avm_initstack(void);
avm_memcell* 	avm_translate_operand(vmarg* arg, avm_memcell* reg);

int 			consts_getint(unsigned index);
double 			consts_getdouble(unsigned index);
char* 			consts_getstring(unsigned index);
char* 			libfuncs_getused(unsigned index);

void 			avm_memcellclear(avm_memcell* m);

void 			avm_warning(char* format);
void 			avm_error(char* format, char* s);

void 			avm_assign(avm_memcell* lv, avm_memcell* rv);

void 			memclear_table (avm_memcell* m);
void 			memclear_string (avm_memcell* m);

void 			avm_dec_top(void);
void 			avm_push_envvalue(unsigned val);
void 			avm_callsaveenviroment(void);
unsigned 		avm_get_envvalue(unsigned i);
unsigned 		avm_totalactuals(void);
avm_memcell* 	avm_getactual(unsigned i);
userfunc* 		avm_getfuncinfo(unsigned address);
void 			avm_calllibfunc(char* id);
void 			avm_registerlibfunc(char* id, library_func_t addr);
library_func_t 	avm_getlibraryfunc(char* id);	/* Typical hashing */
void 			expand_VMlibs(void);

char* 			avm_tostring(avm_memcell* m);
char* 			number_tostring(avm_memcell* m);
char* 			string_tostring(avm_memcell* m);
char* 			bool_tostring(avm_memcell* m);
char* 			table_tostring(avm_memcell* m);
char* 			userfunc_tostring(avm_memcell* m);
char* 			libfunc_tostring(avm_memcell* m);
char* 			nil_tostring(avm_memcell* m);
char* 			undef_tostring(avm_memcell* m);

unsigned char 	avm_tobool(avm_memcell* m);
unsigned char 	number_tobool(avm_memcell* m);
unsigned char 	string_tobool(avm_memcell* m);
unsigned char 	bool_tobool(avm_memcell* m);
unsigned char 	table_tobool(avm_memcell* m);
unsigned char 	userfunc_tobool(avm_memcell* m);
unsigned char 	libfunc_tobool(avm_memcell* m);
unsigned char 	nil_tobool(avm_memcell* m);
unsigned char 	undef_tobool(avm_memcell* m);

void 			avm_initialize(void);

int 			Read_Bin();
void 			run_avm();

#endif
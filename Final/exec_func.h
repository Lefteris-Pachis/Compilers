#ifndef EXEC_FUNC_H
#define EXEC_FUNC_H

#include "avm.h"
#include "dispatcher.h"

void execute_call(instruction*);
void execute_pusharg(instruction*);
void execute_funcenter(instruction*);
void execute_funcexit(instruction*);

/******************LIBRARY FUNCTIONS********************/
void libfunc_print(void);
void libfunc_typeof(void);
void libfunc_totalarguments(void);

#endif
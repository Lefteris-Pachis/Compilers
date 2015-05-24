#ifndef EXEC_RELOP_H
#define EXEC_RELOP_H

#include "target_code.h"
#include "avm.h"

typedef unsigned char (*cmp_func)(double x, double y);

void execute_jeq(instruction*);
void execute_jne(instruction*);
void execute_jump(instruction* instr);

#endif
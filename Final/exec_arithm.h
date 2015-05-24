#ifndef ARITHM_H
#define ARITHM_H

#include "avm.h"

typedef double (*arithmetic_func_t)(double x, double y);

void execute_arithmetic(instruction* instr);
void execute_uminus(instruction* instr);

#endif
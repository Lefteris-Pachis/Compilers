#ifndef EXEC_TABLES_H
#define EXEC_TABLES_H

#include "target_code.h"
#include "avm.h"

void execute_newtable(instruction* instr);
void execute_tablegetelem(instruction* instr);
void execute_tablesetelem(instruction* instr);

#endif
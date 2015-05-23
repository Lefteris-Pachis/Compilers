#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "target_code.h"

#define AVM_ENDING_PC codeSize
#define AVM_MAX_INSTRUCTIONS	(unsigned) nop_v

typedef void (*execute_func_t) (instruction*);
void execute_cycle();

#endif
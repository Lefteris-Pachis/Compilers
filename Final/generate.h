#ifndef GENERATE_H
#define GENERATE_H

#include "quads.h"
#include "target_code.h"

typedef void (*generator_func_t) (quad*);

void generate(void);
void generate_ADD(quad* quad);
void generate_SUB(quad* quad);
void generate_MUL(quad* quad);
void generate_DIV(quad* quad);
void generate_MOD(quad* quad);
void generate_NEWTABLE(quad* quad);
void generate_TABLEGETELEM(quad* quad);
void generate_TABLESETELEM(quad* quad);
void generate_ASSIGN(quad* quad);
void generate_NOP();
void generate_JUMP(quad* quad);
void generate_IF_EQ(quad* quad);
void generate_IF_NOTEQ(quad* quad);
void generate_IF_GREATER(quad* quad);
void generate_IF_GREATERQ(quad* quad);
void generate_IF_LESS(quad* quad);
void generate_IF_LESSEQ(quad* quad);
//void generate_NOT(quad* quad);
//void generate_OR(quad* quad);
//void generate_AND(quad* quad);
void generate_PARAM(quad* quad);
void generate_CALL(quad* quad);
void generate_GETRETVAL(quad* quad);
void generate_FUNCSTART(quad* quad);
void generate_RETURN(quad* quad);
void generate_FUNCEND(quad* quad);
void generate_UMINUS(quad* quad);

#endif
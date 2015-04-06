#include "quads.h"

#include <stdio.h>

void expand(void){
	assert(total == currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if(quads) {
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads= p;
	total += EXPAND_SIZE;
}

void emit(iopcode op, expr* arg1, expr* arg2, unsigned label, unsigned line){
	if(currQuad == total)
		expand();
	quad* p 		= quads + currQuad++;
	p->arg1			= arg1;
	p->arg2 		= arg2;
	p->result 		= result;
	unsigned label 	= label;
	unsigned line 	= line;
}
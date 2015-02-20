#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define MAX_LEXEME 1024

char lookAhead = '\0';
int useLookAhead = 0;
FILE* inputFile = (FILE*) 0;
char lexeme[MAX_LEXEME];
unsigned curr = 0;
unsigned lineNo = 0;

void ResetLexeme(void){
	curr = 0; 
}

char* GetLexeme(void){
	lexeme[curr] = '\0';
	return lexeme;
}

char GetNextChar(void){
	if (useLookAhead){
		useLookAhead = 0;
		return lookAhead;
	}
	else{
		assert(!feof(inputFile));
		return fgetc(inputFile);
	}
}

void Retract(char c){
	assert(!useLookAhead);
	useLookAhead = 1;
	lookAhead = c;
}

void CheckLine(char c){
	if(c == '\n')
		++lineNo;
}

void ExtendLexeme(char c){
	assert(curr < MAX_LEXEME - 1);
	lexeme[curr++] = c;
}
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define MAX_LEXEME 				1024
#define UNKNOWN_TOKEN 			-1
#define END_OF_FILE				0
#define LE						1 		/* <= */
#define LT						2 		/* < */
#define GE 						3		/* >= */
#define GT 						4 		/* > */
#define NE						5 		/* != */
#define NOT						6 		/* ! */
#define EQ						7		/* == */
#define ASSIGN					8		/* = */
#define ADD						9		/* + */
#define SUB						10		/* - */
#define MUL						11		/* * */
#define DIV 					12		/* / */
#define MOD						13		/* % */
#define ADDONE					14		/* ++ */
#define SUBONE					15		/* -- */
#define IDENTIFIER				16
#define KEYWORD_IF		 		17 		/* if */
#define KEYWORD_ELSE			18 		/* else */
#define KEYWORD_WHILE			19 		/* while */
#define KEYWORD_FOR 			20 		/* for */
#define KEYWORD_FUNCTION		21 		/* function */
#define KEYWORD_RETURN			22 		/* return */
#define KEYWORD_BREAK			23 		/* break */
#define KEYWORD_CONTINUE		24 		/* continue */
#define KEYWORD_AND				25 		/* and */
#define KEYWORD_NOT				26 		/* not */
#define KEYWORD_OR				27 		/* or */
#define KEYWORD_LOCAL			28 		/* local */
#define KEYWORD_TRUE			29 		/* true */
#define KEYWORD_FALSE			30 		/* false */
#define KEYWORD_NIL				31 		/* nil */
#define INTCONST				32
#define DOUBLE					33
#define STRING					34
#define SEMICOLON				35 		/* ; */
#define LBRACKET				36  	/* [ */
#define RBRACKET				37 		/* ] */
#define LPARENTHESES			38 		/* ( */
#define RPARENTHESES			39 		/* ) */
#define LBRACE					40 		/* { */
#define RBRACE 					41 		/* } */
#define COMMA					42 		/* , */
#define DOT						43 		/* . */
#define DDOT					44 		/* .. */
#define COLON					45 		/* : */
#define DCOLON					46 		/* :: */
#define COMMENTS				47 		/* // */


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

int state = 0;
int gettoken(void){
	state = 0;
	ResetLexeme();
	while(1){
		if(state == -1)
			return UNKNOWN_TOKEN;
		if(feof(inputFile))
			return END_OF_FILE;
		printf("state = %d\n",state);
		char c = GetNextChar();
		switch(state){
			case 0:
				if(c == '<') state = 1; else
				if(c == '!') state = 2; else
				if(c == '=') state = 3; else
				if(c == '>') state = 4; else
				if(isalpha(c)) state = 5; else
				if(isspace(c))
					{ CheckLine(c); state = 6; continue; } else
				if(c == '\n') { CheckLine(c); state = 0; continue; } else 		///////////////
				if(c == '/') state = 7; else
				if(c == '+') state = 8; else
				if(c == '-') state = 9; else
				if(isdigit(c)) state = 10; else
				if(c == '"') state = 11; else
				if(c == ':') state = 12; else
				if(c == '.') state = 13; else
				if(c == ';') { ExtendLexeme(c); return SEMICOLON; } else
				if(c == '[') { ExtendLexeme(c); return LBRACKET; } else
				if(c == '[') { ExtendLexeme(c); return RBRACKET; } else
				if(c == '(') { ExtendLexeme(c); return LPARENTHESES; } else
				if(c == ')') { ExtendLexeme(c); return RPARENTHESES; } else
				if(c == '{') { ExtendLexeme(c); return LBRACE; } else
				if(c == '}') { ExtendLexeme(c); return RBRACE; } else
				if(c == ',') { ExtendLexeme(c); return COMMA; } else
				if(c == '*') { ExtendLexeme(c); return MUL; } else
				if(c == '%') { ExtendLexeme(c); return DIV; }
				else
					{ state = -1; continue; }
				break;
			case 1:
				if(c == '=') { ExtendLexeme(c); return LE; }
				Retract(c); return LT;
			case 2:
				if(c == '=') { ExtendLexeme(c); return NE; }
				Retract(c); return NOT;
			case 3:
				if(c == '=') { ExtendLexeme(c); return EQ; }
				Retract(c); return ASSIGN;
			case 4:
				if(c == '=') { ExtendLexeme(c); return GE; }
				Retract(c); return GT;
			case 5:
				if(isalpha(c) || isdigit(c)) state = 5;
				else { Retract(c); return IDENTIFIER; }
				break;
			case 6:
				if(isspace(c))
					{ CheckLine(c); }
				else
					{ Retract(c); state = 0; }
				continue;
			case 7:
				if(c == '*') { state == 15; continue;  }
				else if(c == '/') { state == 16; continue; }
				else { Retract(c); return DIV; }
			case 8:
				if(c == '+') { ExtendLexeme(c); return ADDONE; }
				Retract(c); return ADD;
			case 9:
				if(c == '-') { ExtendLexeme(c); return SUBONE; }
				Retract(c); return SUB;
			case 10:
				if(isdigit(c)) { state = 10; ExtendLexeme(c); continue; }
				else if(c == '.') { state = 14; ExtendLexeme(c); continue; }
				else { Retract(c); return INTCONST; } 
			case 11:
				if(isalpha(c) || isdigit(c) || isspace(c)) { state = 11; ExtendLexeme(c); continue; }
				else if(c == '"') { ExtendLexeme(c); return STRING; }
				else state = -1;					//ERROR
			case 12:
				if(c == ':') { ExtendLexeme(c); return DCOLON; }
				Retract(c); return COLON;
			case 13:
				if(c == '.') { ExtendLexeme(c); return DDOT; }
				Retract(c); return DOT;
			case 14:
				if(isdigit(c)) { state = 14; ExtendLexeme(c); continue; }
				else { Retract(c); return DOUBLE; } 
			case 15:
				if(isalpha(c) || isdigit(c) || isspace(c)) { state = 15; continue; }
				else if(c == '*') { state = 17; continue; }
				break;
			case 16:
				if(isalpha(c) || isdigit(c) || isspace(c)) { state = 16; continue; }
				else if(c == '\n') { CheckLine(c); return COMMENTS; }
				else state = -1;					//ERROR
				break;
			case 17:
				if(c == '/') return COMMENTS;
				else state = -1;	 				//ERROR
				break;


			default: assert(0); /*Giwrgadakhs*/
		}
		ExtendLexeme(c);
	}
}

void main(int argc, char const *argv[])
{
	inputFile = fopen("gg.txt","r");
	char ch;
	int i = gettoken();

	while(i != 0)
	{
		if(i == -1){
			printf("ERROR\n");
			break;
		}
		printf("%d\n", i );
		i = gettoken();
	}
	
}

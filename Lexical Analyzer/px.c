#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

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

struct token_t{
	int id;
	char *buffer;
	char *category;
	int line;
	struct token_t *next;
}*head;

struct token_t* list_w_tokens(int line,int id,char* buffer,char* category){
	struct token_t *list;
	list = (struct token_t *)malloc(sizeof(struct token_t));
	list->line=line;
	list->id=id;
	list->buffer=strdup(buffer);
	list->category=strdup(category);
	list->next=head;
	head=list;
	return head;
};

void print_token(int id){
	struct token_t *tmp = head;
	while(tmp!=NULL){
		if(tmp->id == id)
   			printf("%d:    %d    %s    \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category);
   		tmp=tmp->next;
   	}
}

char lookAhead = '\0';
int useLookAhead = 0;
FILE* inputFile = (FILE*) 0;
char lexeme[MAX_LEXEME];
unsigned curr = 0;
unsigned lineNo = 1;

void ResetLexeme(void){
	int i = 0;
	while(lexeme[i] != '\0'){
		lexeme[i] = '\0';
		i++;
	}
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
		//printf("state = %d\n",state);
		char c = GetNextChar();
		switch(state){
			case 0:
				if(c == '<') state = 1; else
				if(c == '!') state = 2; else
				if(c == '=') state = 3; else
				if(c == '>') state = 4; else
				if(c == 'i') state = 18; else
				if(c == 'w') state = 20; else
				if(c == 'f') state = 21; else
				if(c == 'r') state = 22; else
				if(c == 'e') state = 23; else
				if(c == 'b') state = 24; else
				if(c == 'c') state = 25; else
				if(c == 'a') state = 26; else
				if(c == 'n') state = 27; else
				if(c == 'o') state = 28; else
				if(c == 'l') state = 29; else
				if(c == 't') state = 30; else
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
				if(isalpha(c) || isdigit(c) || c == '_') state = 5;
				else { Retract(c); return IDENTIFIER; }
				break;
			case 6:
				if(isspace(c))
					{ CheckLine(c); }
				else
					{ Retract(c); state = 0; }
				continue;
			case 7:
				if(c == '*') { state = 15; ExtendLexeme(c); continue;  }
				else if(c == '/') { state = 16; ExtendLexeme(c); continue; }
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
				if(isalpha(c) || isdigit(c) || isspace(c)) { state = 15; ExtendLexeme(c); continue; }
				else if(c == '*') { state = 17; ExtendLexeme(c); continue; }
				break;
			case 16:
				if(isalpha(c) || isdigit(c) || isspace(c) && c != '\n') { state = 16; ExtendLexeme(c); continue; }
				else if(c == '\n') { CheckLine(c); return COMMENTS; }
				else state = -1;					//ERROR
				break;
			case 17:
				if(c == '/') { ExtendLexeme(c); return COMMENTS; }
				else state = -1;	 				//ERROR
				break;
			case 18:
				if(c == 'f') { state = 33; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 33:
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD_IF; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 20:
				if(c == 'h') { state = 34; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 34:
				if(c == 'i') { state = 35; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 35:
				if(c == 'l') { state = 36; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 36:
				if(c == 'e') { state = 37; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 37:
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD_WHILE; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 21:
				if(c == 'o') { state = 38; ExtendLexeme(c); continue; } else
				if(c == 'u') { state = 40; ExtendLexeme(c); continue; } else
				if(c == 'a') { state = 47; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 38:
				if(c == 'r') { state = 39; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 39:
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD_FOR; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 40:
				if(c == 'n') { state = 41; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 41:
				if(c == 'c') { state = 42; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 42:
				if(c == 't') { state = 43; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 43:
				if(c == 'i') { state = 44; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 44:
				if(c == 'o') { state = 45; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 45:
				if(c == 'n') { state = 46; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 46:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_FUNCTION; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 47:
				if(c == 'l') { state = 48; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 48:
				if(c == 's') { state = 49; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 49:
				if(c == 'e') { state = 50; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 50:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_FALSE; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 22:
				if(c == 'e') { state = 51; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 51:
				if(c == 't') { state = 52; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 52:
				if(c == 'e') { state = 53; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 53:
				if(c == 'r') { state = 54; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 54:
				if(c == 'n') { state = 55; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 55:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_RETURN; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 23:
				if(c == 'l') { state = 56; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 56:
				if(c == 's') { state = 57; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 57:
				if(c == 'e') { state = 58; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 58:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_ELSE; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 24:
				if(c == 'r') { state = 59; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 59:
				if(c == 'e') { state = 60; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 60:
				if(c == 'a') { state = 61; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 61:
				if(c == 'k') { state = 62; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 62:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_RETURN; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 25:
				if(c == 'o') { state = 63; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 63:
				if(c == 'n') { state = 64; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 64:
				if(c == 't') { state = 65; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 65:
				if(c == 'i') { state = 66; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 66:
				if(c == 'n') { state = 67; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 67:
				if(c == 'u') { state = 68; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 68:
				if(c == 'e') { state = 69; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 69:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_CONTINUE; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 26:
				if(c == 'n') { state = 70; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 70:
				if(c == 'd') { state = 71; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 71:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_AND; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 27:
				if(c == 'o') { state = 72; ExtendLexeme(c); continue; } else
				if(c == 'i') { state = 74; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 72:
				if(c == 't') { state = 73; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 73:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_NOT; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 74:
				if(c == 'l') { state = 75; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 75:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_NIL; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 28:
				if(c == 'r') { state = 76; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 76:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_OR; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 29:
				if(c == 'o') { state = 77; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 77:
				if(c == 'c') { state = 78; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 78:
				if(c == 'a') { state = 79; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 79:
				if(c == 'l') { state = 80; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 80:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_LOCAL; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 30:
				if(c == 'r') { state = 81; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 81:
				if(c == 'u') { state = 82; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 82:
				if(c == 'e') { state = 83; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 83:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD_TRUE; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			default: assert(0); /*Giwrgadakhs*/
		}
		ExtendLexeme(c);
	}
}

char* Convert(int x){
	switch(x){
		case 0:
			return "END_OF_FILE";
		case 1:
			return "LE";
		case 2:
			return "LT";
		case 3:
			return "GE";
		case 4:
			return "GT";
		case 5:
			return "NE";
		case 6:
			return "NOT";
		case 7:
			return "EQ";
		case 8:
			return "ASSIGN";
		case 9:
			return "ADD";
		case 10:
			return "SUB";
		case 11:
			return "MUL";
		case 12:
			return "DIV";
		case 13:
			return "MOD";
		case 14:
			return "ADDONE";
		case 15:
			return "SUBONE";
		case 16:
			return "IDENTIFIER";
		case 17:
			return "KEYWORD_IF";
		case 18:
			return "KEYWORD_ELSE";
		case 19:
			return "KEYWORD_WHILE";
		case 20:
			return "KEYWORD_FOR";
		case 21:
			return "KEYWORD_FUNCTION";
		case 22:
			return "KEYWORD_RETURN";
		case 23:
			return "KEYWORD_BREAK";
		case 24:
			return "KEYWORD_CONTINUE";
		case 25:
			return "KEYWORD_AND";
		case 26:
			return "KEYWORD_NOT";
		case 27:
			return "KEYWORD_OR";
		case 28:
			return "KEYWORD_LOCAL";
		case 29:
			return "KEYWORD_TRUE";
		case 30:
			return "KEYWORD_FALSE";
		case 31:
			return "KEYWORD_NIL";
		case 32:
			return "INTCONST";
		case 33:
			return "DOUBLE";
		case 34:
			return "STRING";
		case 35:
			return "SEMICOLON";
		case 36:
			return "LBRACKET";
		case 37:
			return "RBRACKET";
		case 38:
			return "LPARENTHESES";
		case 39:
			return "RPARENTHESES";
		case 40:
			return "LBRACE";
		case 41:
			return "RBRACE";
		case 42:
			return "COMMA";
		case 43:
			return "DOT";
		case 44:
			return "DDOT";
		case 45:
			return "COLON";
		case 46:
			return "DCOLON";
		case 47:
			return "COMMENTS";
	}
	return "ERROR";
}

void main(int argc, char const *argv[])
{
	inputFile = fopen(argv[1],"r");
	char ch;
	int id = 1;
	struct alpha_token_t *ggwp;
	int i = gettoken();
	

	while(i != 0)
	{
		if(i == -1){
			printf("ERROR\n");
			break;
		}
		head = list_w_tokens(lineNo,id++,lexeme,Convert(i));
		i = gettoken();
	}
	int j = 0;
	for(j = 1; j <= id; j++)
		print_token(j);
}

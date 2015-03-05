#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEXEME 				1024
#define UNKNOWN_TOKEN 			-1
#define END_OF_FILE				0
#define OPERATOR				1 		/* <= */
#define KEYWORD					2 		/* < */
#define IDENTIFIER				3
#define INTCONST				4
#define DOUBLE					5
#define STRING					6
#define PUNCTUATION				7 		/* ; */
#define SINGLE_LINE_COMMENTS	8 		/* // */
#define NESTED_COMMENTS			9
#define MULTI_LINE_COMMENTS		10

typedef enum { IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL }keyword;
typedef enum { ASSIGN, PLUS, MINUS, MUL, DIV, MOD, EQUAL, NOT_EQUAL, ADD, SUB, GREATER, LESS, GREATER_EQUAL, LESS_EQUAL }operator;
typedef enum { LEFT_BRACER, RIGHT_BRACER, LEFT_BRACKET, RIGHT_BRACKET, LEFT_PARENTHESES, RIGHT_PARENTHESES, SEMICOLON, COMMA, COLON, DOUBLE_COLON, DOT, DOUBLE_DOT }punctuation;

struct token_t{
	int id;
	char *buffer;
	char *category;
	int line;
	keyword keywrd;
	operator op;
	punctuation p;
	int intconst;
	float fl;
	struct token_t *next;
}*head,*tail;

keyword Convert_key_to_enum(char *x){
	if(strcmp(x,"if") == 0) return IF;
	else if(strcmp(x,"else") == 0) return ELSE;
	else if(strcmp(x,"while") == 0) return WHILE;
	else if(strcmp(x,"for") == 0) return FOR;
	else if(strcmp(x,"function") == 0) return FUNCTION;
	else if(strcmp(x,"return") == 0) return RETURN;
	else if(strcmp(x,"break") == 0) return BREAK;
	else if(strcmp(x,"continue") == 0) return CONTINUE;
	else if(strcmp(x,"and") == 0) return AND;
	else if(strcmp(x,"not") == 0) return NOT;
	else if(strcmp(x,"or") == 0) return OR;
	else if(strcmp(x,"local") == 0) return LOCAL;
	else if(strcmp(x,"true") == 0) return TRUE;
	else if(strcmp(x,"false") == 0) return FALSE;
	else if(strcmp(x,"nil") == 0) return NIL;
}

operator Convert_op_to_enum(char *x){
	if(strcmp(x,"=") == 0) return ASSIGN;
	else if(strcmp(x,"+") == 0) return PLUS;
	else if(strcmp(x,"-") == 0) return MINUS;
	else if(strcmp(x,"*") == 0) return MUL;
	else if(strcmp(x,"/") == 0) return DIV;
	else if(strcmp(x,"%") == 0) return MOD;
	else if(strcmp(x,"==") == 0) return EQUAL;
	else if(strcmp(x,"!=") == 0) return NOT_EQUAL;
	else if(strcmp(x,"++") == 0) return ADD;
	else if(strcmp(x,"--") == 0) return SUB;
	else if(strcmp(x,">") == 0) return GREATER;
	else if(strcmp(x,"<") == 0) return LESS;
	else if(strcmp(x,">=") == 0) return GREATER_EQUAL;
	else if(strcmp(x,"<=") == 0) return LESS_EQUAL;
}

punctuation Convert_p_to_enum(char *x){
	if(strcmp(x,"{") == 0) return LEFT_BRACER;
	else if(strcmp(x,"}") == 0) return RIGHT_BRACER;
	else if(strcmp(x,"[") == 0) return LEFT_BRACKET;
	else if(strcmp(x,"]") == 0) return RIGHT_BRACKET;
	else if(strcmp(x,"(") == 0) return LEFT_PARENTHESES;
	else if(strcmp(x,")") == 0) return RIGHT_PARENTHESES;
	else if(strcmp(x,";") == 0) return SEMICOLON;
	else if(strcmp(x,",") == 0) return COMMA;
	else if(strcmp(x,":") == 0) return COLON;
	else if(strcmp(x,"::") == 0) return DOUBLE_COLON;
	else if(strcmp(x,".") == 0) return DOT;
	else if(strcmp(x,"..") == 0) return DOUBLE_DOT;
}

char *Convert_key_to_string(keyword keywrd){
	if(keywrd == IF) return "IF";
	else if(keywrd == ELSE) return "ELSE";
	else if(keywrd == WHILE) return "WHILE";
	else if(keywrd == FOR) return "FOR";
	else if(keywrd == FUNCTION) return "FUNCTION";
	else if(keywrd == RETURN) return "RETURN";
	else if(keywrd == BREAK) return "BREAK";
	else if(keywrd == CONTINUE) return "CONTINUE";
	else if(keywrd == AND) return "AND";
	else if(keywrd == NOT) return "NOT";
	else if(keywrd == OR) return "OR";
	else if(keywrd == LOCAL) return "LOCAL";
	else if(keywrd == TRUE) return "TRUE";
	else if(keywrd == FALSE) return "FALSE";
	else if(keywrd == NIL) return "NIL";
}

char *Convert_op_to_string(operator op){
	if(op == ASSIGN) return "ASSIGN";
	else if(op == PLUS) return "PLUS";
	else if(op == MINUS) return "MINUS";
	else if(op == MUL) return "MUL";
	else if(op == DIV) return "DIV";
	else if(op == MOD) return "MOD";
	else if(op == EQUAL) return "EQUAL";
	else if(op == NOT_EQUAL) return "NOT_EQUAL";
	else if(op == ADD) return "ADD";
	else if(op == SUB) return "SUB";
	else if(op == GREATER) return "GREATER";
	else if(op == LESS) return "LESS";
	else if(op == GREATER_EQUAL) return "GREATER_EQUAL";
	else if(op == LESS_EQUAL) return "LESS_EQUAL";
}

char *Convert_p_to_string(punctuation p){
	if(p == LEFT_BRACER) return "LEFT_BRACER";
	else if(p == RIGHT_BRACER) return "RIGHT_BRACER";
	else if(p == LEFT_BRACKET) return "LEFT_BRACKET";
	else if(p == RIGHT_BRACKET) return "RIGHT_BRACKET";
	else if(p == LEFT_PARENTHESES) return "LEFT_PARENTHESES";
	else if(p == RIGHT_PARENTHESES) return "RIGHT_PARENTHESES";
	else if(p == SEMICOLON) return "SEMICOLON";
	else if(p == COMMA) return "COMMA";
	else if(p == COLON) return "COLON";
	else if(p == DOUBLE_COLON) return "DOUBLE_COLON";
	else if(p == DOT) return "DOT";
	else if(p == DOUBLE_DOT) return "DOUBLE_DOT";
}

struct token_t* list_w_tokens(int line,int id,char* buffer,char* category){
	struct token_t *list;
	list = (struct token_t *)malloc(sizeof(struct token_t));
	list->line=line;
	list->id=id;
	list->buffer=strdup(buffer);
	list->category=strdup(category);
	if(strcmp(list->category,"KEYWORD") == 0)
		list->keywrd = Convert_key_to_enum(list->buffer);
	else if(strcmp(list->category,"OPERATOR") == 0)
		list->op = Convert_op_to_enum(list->buffer);
	else if(strcmp(list->category,"PUNCTUATION") == 0)
		list->p = Convert_p_to_enum(list->buffer);
	else if(strcmp(list->category,"INTEGER") == 0)
		list->intconst = atoi(list->buffer);
	else if(strcmp(list->category,"DOUBLE") == 0)
		list->fl = atof(list->buffer);
	list->next=NULL;
	if(head==NULL){
		head=list;
		tail=head;
		return head;
	}
	if(head->next==NULL)
		head->next=list;
	else
		tail->next=list;
	tail=list;
	return head;
};

void print_list(struct token_t *head){
 	struct token_t *tmp = head;
 	while(tmp!=NULL){
 		if(strcmp(tmp->category,"KEYWORD") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_key_to_string(tmp->keywrd));
 		else if(strcmp(tmp->category,"OPERATOR") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_op_to_string(tmp->op));
 		else if(strcmp(tmp->category,"PUNCTUATION") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_p_to_string(tmp->p));
 		else if(strcmp(tmp->category,"INTEGER") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%d\n",tmp->line,tmp->id,tmp->buffer,tmp->category,tmp->intconst);
 		else if(strcmp(tmp->category,"DOUBLE") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%f\n",tmp->line,tmp->id,tmp->buffer,tmp->category,tmp->fl);
 		else
   			printf("%d: #%d    \"%s\"    \t%s \t\"%s\"\n",tmp->line,tmp->id,tmp->buffer,tmp->category, tmp->buffer);
   		tmp=tmp->next;
   	}
}

char lookAhead = '\0';
int useLookAhead = 0;
FILE* inputFile = (FILE*) 0;
char lexeme[MAX_LEXEME];
unsigned curr = 0;
unsigned lineNo = 1;
int anoigei = 0, kleinei = 0;

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
		printf("state = %d\n",state);
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
				if(c == ';') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == '[') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == ']') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == '(') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == ')') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == '{') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == '}') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == ',') { ExtendLexeme(c); return PUNCTUATION; } else
				if(c == '*') { ExtendLexeme(c); return OPERATOR; } else
				if(c == '%') { ExtendLexeme(c); return OPERATOR; }
				else
					{ state = -1; continue; }
				break;
			case 1:
				if(c == '=') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
			case 2:
				if(c == '=') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
			case 3:
				if(c == '=') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
			case 4:
				if(c == '=') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
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
				if(c == '*') { anoigei++; state = 15; ExtendLexeme(c); continue;  }
				else if(c == '/') { state = 16; ExtendLexeme(c); continue; }
				else { Retract(c); return DIV; }
			case 8:
				if(c == '+') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
			case 9:
				if(c == '-') { ExtendLexeme(c); return OPERATOR; }
				Retract(c); return OPERATOR;
			case 10:
				if(isdigit(c)) { state = 10; ExtendLexeme(c); continue; }
				else if(c == '.') { state = 14; ExtendLexeme(c); continue; }
				else { Retract(c); return INTCONST; } 
			case 11:
				if(isalpha(c) || isdigit(c) || isspace(c)) { state = 11; CheckLine(c); ExtendLexeme(c); continue; }
				else if(c == '"') { ExtendLexeme(c); return STRING; }
				else state = -1;					//ERROR
			case 12:
				if(c == ':') { ExtendLexeme(c); return PUNCTUATION; }
				Retract(c); return PUNCTUATION;
			case 13:
				if(c == '.') { ExtendLexeme(c); return PUNCTUATION; }
				Retract(c); return PUNCTUATION;
			case 14:
				if(isdigit(c)) { state = 14; ExtendLexeme(c); continue; }
				else { Retract(c); return DOUBLE; } 
			case 15:
				if(isalpha(c) || isdigit(c) || isspace(c) || c == '\n') { CheckLine(c); state = 15; ExtendLexeme(c); continue; }
				else if(c == '/') { state = 84; ExtendLexeme(c); continue; }
				else if(c == '*') { state = 17; ExtendLexeme(c); continue; }
				break;
			case 84:
				if(c == '*') { anoigei++; state = 15; ExtendLexeme(c); continue; }
				else { state = 15; ExtendLexeme(c); continue; }
			case 16:
				if(c != '\n') { state = 16; ExtendLexeme(c); continue; }
				else if(c == '\n') { CheckLine(c); return SINGLE_LINE_COMMENTS; }
				break;
			case 17:
				if(anoigei > kleinei+1 && c == '/') { kleinei++; ExtendLexeme(c); return NESTED_COMMENTS;}
				if(c == '/') { kleinei++; printf("anoigei = %d kleinei = %d\n",anoigei,kleinei ); ExtendLexeme(c); return MULTI_LINE_COMMENTS; }
				else state = 15;
				break;
			case 18:
				if(c == 'f') { state = 33; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 33:
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '(' || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 74:
				if(c == 'l') { state = 75; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 75:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;
			case 28:
				if(c == 'r') { state = 76; ExtendLexeme(c); continue; }
				else { ExtendLexeme(c); state = 5; continue; }	
				break;
			case 76:
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
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
				if(isspace(c) || c == '\n') { Retract(c); return KEYWORD; }
				else { ExtendLexeme(c); state = 5; continue; }
				break;

			default: assert(0);
		}
		ExtendLexeme(c);
	}
}

char* Convert(int x){
	switch(x){
		case 0:
			return "END_OF_FILE";
		case 1:
			return "OPERATOR";
		case 2:
			return "KEYWORD";
		case 3:
			return "IDENTIFIER";
		case 4:
			return "INTCONST";
		case 5:
			return "DOUBLE";
		case 6:
			return "STRING";
		case 7:
			return "PUNCTUATION";
		case 8:
			return "SINGLE_LINE_COMMENTS";
		case 9:
			return "NESTED_COMMENTS";
		case 10:
			return "MULTI_LINE_COMMENTS";
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
	print_list(head);
}
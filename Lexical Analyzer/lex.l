%{
#include <stdio.h>
#include <stdlib.h>
int id = 1;

typedef enum { IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL }keyword;
typedef enum { ASSIGN, PLUS, MINUS, MUL, DIV, MOD, EQUAL, NOT_EQUAL, ADD, SUB, GREATER, LESS, GREATER_EQUAL, LESS_EQUAL }operator;
typedef enum { LEFT_BRACER, RIGHT_BRACER, LEFT_BRACKET, RIGHT_BRACKET, LEFT_PARENTHESES, RIGHT_PARENTHESES, SEMICOLON, COMMA, COLON, DOUBLE_COLON, DOT, DOUBLE_DOT }punctuation;

struct alpha_token_t{
	int id;
	char *buffer;
	char *category;
	int line;
	keyword keywrd;
	operator op;
	punctuation p;
	int intconst;
	float fl;
	struct alpha_token_t *next;
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

struct alpha_token_t* list_w_tokens(int line,int id,char* buffer,char* category){
	struct alpha_token_t *list;
	list = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	list->line=line;
	list->id=id;
	list->buffer=strdup(buffer);
	list->category = strdup(category);
	if(strcmp(list->category, "KEYWORD") == 0)
		list->keywrd = Convert_key_to_enum(list->buffer);
	else if(strcmp(list->category, "OPERATOR") == 0)
		list->op = Convert_op_to_enum(list->buffer);
	else if(strcmp(list->category, "PUNCTUATION") == 0)
		list->p = Convert_p_to_enum(list->buffer);
	else if(strcmp(list->category, "INTEGER") == 0)
		list->intconst = atoi(list->buffer);
	else if(strcmp(list->category, "DOUBLE") == 0)
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

void print_list(struct alpha_token_t *head){
 	struct alpha_token_t *tmp = head;
 	while(tmp!=NULL){
 		if(strcmp(tmp->category, "KEYWORD") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_key_to_string(tmp->keywrd));
 		else if(strcmp(tmp->category, "OPERATOR") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_op_to_string(tmp->op));
 		else if(strcmp(tmp->category, "PUNCTUATION") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category,Convert_p_to_string(tmp->p));
 		else if(strcmp(tmp->category, "INTEGER") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%d\n",tmp->line,tmp->id,tmp->buffer,tmp->category,tmp->intconst);
 		else if(strcmp(tmp->category, "DOUBLE") == 0)
 			printf("%d: #%d    \"%s\"    \t%s \t%f\n",tmp->line,tmp->id,tmp->buffer,tmp->category,tmp->fl);
 		else
   			printf("%d: #%d    \"%s\"    \t%s \t\"%s\"\n",tmp->line,tmp->id,tmp->buffer,tmp->category, tmp->buffer);
   		tmp=tmp->next;
   	}
}

%}

%option yylineno
%option noyywrap
%option prefix = "alpha_yy"

id          [A-Za-z_][A-Za-z_0-9]*
integer		[0-9]+
double		[0-9]+\.[0-9]+
character	'.'
space		" "
comment1	"//".*


%%

"\""	{
			int c;
			char *get;
			get=malloc(4);
			int size=4;
			char* get_ptr;
			get_ptr=get;
			int flag=0;
			int nt=0;
			int save_line = yylineno;
			while ((c = input()) != EOF ) {
				
				if(c=='\"'){
					nt=0;
					get=realloc(get,size+4);
					*get_ptr++='\0';
					head = list_w_tokens(save_line,id++,get,"STRING");
					break;
					
				}else if(c=='\\'){
					c=input();
					if((c)=='"'){
						get=realloc(get,size+4);
						*get_ptr++='\"';
						size+=4;
					}
					else if((c)=='n'){
						get=realloc(get,size+4);
						*get_ptr++='\n';
						size+=4;
					}
					else if((c)=='\\'){
						get=realloc(get,size+4);
						*get_ptr++='\\';
						size+=4;
					}
					else if((c)=='t'){
						get=realloc(get,size+4);
						*get_ptr++='\t';
						size+=4;
					}
					else{
						flag=1;
						unput(c);
					}

					if(flag==1){
						printf("INVALID ESCAPE CHARACTER at line %d\n",yylineno );
						flag=0;
					}

				}
				else{
					nt++;
					get=realloc(get,size+4);
					*get_ptr++=c;
					size+=4;
				}
			}
			if(nt>0){
					printf("NON TERMINATED STRING at line %d\n",yylineno );
					exit(1);
			}
		}


"if"|"else"|"for"|"function"|"return"|"break"|"continue"|"and"|"not"|"or"|"local"|"true"|"while"|"false"|"nil" {
	head = list_w_tokens(yylineno,id++,yytext,"KEYWORD"); 
}

"="|"+"|"-"|"*"|"/"|"%"|"=="|"!="|"++"|"--"|">"|"<"|">="|"<=" {
	head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); 
}

"{"|"}"|"["|"]"|"("|")"|";"|","|":"|"::"|"."|".." {
	head = list_w_tokens(yylineno,id++,yytext,"PUNCTUATION"); 
}

"/*"	{
			int anoigei = 1, kleinei = 0;
			int c;
			
			int nested_comment(){
				while ((c = input()) != EOF ){
					if(anoigei == kleinei+1){
						unput(c);
						break;
					}
					if(c=='*'){
						if((c = input()) == '/'){
							kleinei++;
							continue;
						}
						else
							unput(c);
					}
					if(c=='/'){
						if((c=input())=='*'){
							anoigei++;
							head = list_w_tokens(yylineno,id++,yytext,"NESTED_COMMENT");
							nested_comment();
						}
						else
							unput(c);
					}
					else
						continue;
				}
			}
			head = list_w_tokens(yylineno,id++,yytext,"MULTI_LINE_COMMENT");
			while ((c = input()) != EOF ) {
				if(c == '*') {
					if((c = input()) == '/'){
						kleinei++;
						break;
					}else
						unput(c);
				}
				if(c=='/'){
					if((c=input())=='*'){
						anoigei++;
						head = list_w_tokens(yylineno,id++,yytext,"NESTED_COMMENT");
						nested_comment();
					}
					else
						unput(c);
				}
				else
					continue;
			}
			printf("%d::%d\n",anoigei,kleinei);
			if(anoigei != kleinei){
				if(kleinei > anoigei)
					printf("Error.Comment closes more times than needed in line %d\nExit\n",yylineno);
				else
					printf("\nError.Comment not terminated in line %d\nExit\n",yylineno);
				exit(1);
			}
		}
"_"					{ printf("undefined character %s in line %d\n",yytext,yylineno); }
{id}				{ head = list_w_tokens(yylineno,id++,yytext,"ID"); }
{integer} 			{ head = list_w_tokens(yylineno,id++,yytext,"INTEGER"); }
{double} 			{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE"); }
{character} 		{ head = list_w_tokens(yylineno,id++,yytext,"CHAR"); }
{comment1} 			{ head = list_w_tokens(yylineno,id++,yytext,"SINGLE_LINE_COMMENT"); }
{space}				{}

[\t\r\n]   			{}
.					{ printf("undefined character %s in line %d\n",yytext,yylineno); }
<<EOF>> {	printf("(eof %u)\n", yylineno); 
			
			return 0;
}

%%

int main(int argc, char* argv[]) {
	if(argc > 1) {
		if(!(yyin = fopen(argv[1],"r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}
	else
		yyin = stdin;
  	alpha_yylex();
  	print_list(head);

    return 0;
}
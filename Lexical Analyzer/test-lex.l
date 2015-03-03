%{
#include <stdio.h>
#include <stdlib.h>
int id = 1;

struct token_t{
	int id;
	char *buffer;
	char *category;
	int line;
	struct token_t *next;
}*head,*tail;

struct token_t* list_w_tokens(int line,int id,char* buffer,char* category){
	struct token_t *list;
	list = (struct token_t *)malloc(sizeof(struct token_t));
	list->line=line;
	list->id=id;
	list->buffer=strdup(buffer);
	list->category=strdup(category);
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
   		printf("%d: #%d    \"%s\"    \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category);
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
undefined  	(.)
op_add		"+"
op_sub		"-"
op_less		"<"
op_greater	">"
op_equal	"="
op_less_eq	"<="
op_great_eq	">="
op_diff		"!="
op_log_eq	"=="
op_plus		"++"
op_minus	"--"
op_mod		"%"
op_mul		"*"
op_div		"/"
left_bracer			"{"
right_bracer		"}"
left_bracket		"["
right_bracket		"]"
left_parentheses	"("
right_parentheses	")"
semicolon			";"
comma				","
colon				":"
double_colon		"::"
dot					"."
double_dot			".."
comment1			"//".*	

%x COMMENT
%s STRING

%%

"\""	{
			int c;
			char get[10000];
			char* get_ptr;
			get_ptr=get;
			while ((c = input()) != EOF ) {
				if(c  == '\\'){
					if((c=input())=='n')
						*get_ptr++ ='\n';
					else
						unput(c);					
					if((c=input())=='t')
						*get_ptr++ ='\t';
					else
						unput(c);
					if((c=input())=='\\')
						*get_ptr++ ='\\';
					else
						unput(c);
					if((c=input())=='\"')
						*get_ptr++ ='\"';
					else
						unput(c);
				}else if(c == '\"'){
					*get_ptr++ = '\0';
					break;
				}else{
					*get_ptr++ = c;
				}
			}
			head = list_w_tokens(yylineno,id++,get,"STRING");
		}


"if"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_IF"); }
"else"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_ELSE"); }
"for"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_FOR"); }
"function"	{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_FUNCTION"); }
"return"	{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_RETURN"); }
"break"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_BREAK"); }
"continue"	{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_CONTINUE"); }
"and"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_AND"); }
"not"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_NOT"); }
"or"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_OR"); }
"local"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_LOCAL"); }
"true"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_TRUE"); }
"while"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_WHILE"); }
"false"		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_FALSE"); }
"nil" 		{ head = list_w_tokens(yylineno,id++,yytext,"KEYWORD_NIL"); }

"/*"	{
			int anoigei = 1, kleinei = 0;
			int c;
			int nested_comment(){
				while ((c = input()) != EOF ){
					if(c=='*'){
						if((c = input()) == '/'){
							kleinei++;
							head = list_w_tokens(yylineno,id++,yytext,"NESTED_COMMENT");
						}
						else
							unput(c);
					}
					if(c=='/'){
						if(c=input()=='*'){
							anoigei++;
							nested_comment();
						}
					}
				}
			}

			while ((c = input()) != EOF ) {
				if(c == '*') {
					if((c = input()) == '/'){
						kleinei++;
						head = list_w_tokens(yylineno,id++,yytext,"COMMENT");
						break;
					}else
						unput(c);
				}
				if(c=='/'){
					if(c=input()=='*'){
						anoigei++;
						nested_comment();
					}
				}
			}
			if(anoigei != kleinei){
				if(kleinei > anoigei)
					printf("Error.Comment closes more times than needed in line %d\nExit\n",yylineno);
				else
					printf("\nError.Comment not terminated in line %d\nExit\n",yylineno);
				exit(1);
			}
		}

{id}				{ head = list_w_tokens(yylineno,id++,yytext,"IDENTIFIER"); }
{integer} 			{ head = list_w_tokens(yylineno,id++,yytext,"INTEGER"); }
{double} 			{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE"); }
{character} 		{ head = list_w_tokens(yylineno,id++,yytext,"CHARACTER"); }
{op_add} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_ADD"); }
{op_sub} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_SUB"); }
{op_less} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_LESS"); }
{op_greater} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_GREATER"); }
{op_equal} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_EQUAL"); }
{op_less_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_LESS_EQUAL"); }
{op_great_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_GREATER_EQUAL"); }
{op_diff} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_DIFF"); }
{op_log_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_LOG_EQ"); }
{op_plus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_PLUS"); }
{op_minus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_MINUS"); }
{op_mod} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_MOD"); }
{op_mul} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_MUL"); }
{op_div} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR_DIV"); }
{left_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"LEFT_BRACER"); }
{right_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"RIGHT_BRACER"); }
{left_bracket} 		{ head = list_w_tokens(yylineno,id++,yytext,"LEFT_BRACKET"); }
{right_bracket} 	{ head = list_w_tokens(yylineno,id++,yytext,"RIGHT_BRACKET"); }
{left_parentheses} 	{ head = list_w_tokens(yylineno,id++,yytext,"LEFT_PARENTHESES"); }
{right_parentheses} { head = list_w_tokens(yylineno,id++,yytext,"RIGHT_PARENTHESES"); }
{semicolon} 		{ head = list_w_tokens(yylineno,id++,yytext,"SEMICOLON"); }
{comma} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMA"); }
{colon} 			{ head = list_w_tokens(yylineno,id++,yytext,"COLON"); }
{double_colon} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE COLON"); }
{dot} 				{ head = list_w_tokens(yylineno,id++,yytext,"DOT"); }
{double_dot} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE DOT"); }
{comment1} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMENT"); }
{undefined}         { printf("undefined character %s in line %d\n",yytext,yylineno); }

[\t\r\n]   {}

<<EOF>> {	printf("(eof %u)\n", yylineno); 
			print_list(head);
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
  	yylex();
    return 0;
}
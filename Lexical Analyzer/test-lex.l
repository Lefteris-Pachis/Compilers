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

void print_list(struct token_t *head){

	printf("The Linked List : \n");
 	struct token_t *tmp = head;
 	while(tmp!=NULL){
   		printf("%d:    %d    %s    \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category);
   		tmp=tmp->next;
   		}
  	printf("NULL");
}

void print_token(int id){
	struct token_t *tmp = head;
	while(tmp!=NULL){
		if(tmp->id == id)
   			printf("%d:    %d    %s    \t%s\n",tmp->line,tmp->id,tmp->buffer,tmp->category);
   		tmp=tmp->next;
   	}
}


%}

%option yylineno
%option noyywrap
%option prefix = "alpha_yy"

id          [A-Za-z_][A-Za-z_0-9]*
integer		(0[xX][0-9A-Fa-f]*)|([0-9]*)
double		[0-9]+.[0-9]+
character	'.'
string		\".*\"
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

keyword_if			"if"
keyword_else		"else"
keyword_for			"for"
keyword_function	"function"
keyword_return		"return"
keyword_break		"break"
keyword_continue	"continue"
keyword_and			"and"
keyword_not 		"not"
keyword_or 			"or"
keyword_local		"local"
keyword_true		"true"
keyword_false		"false"
keyword_nil 		"nil"

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

%%


"if"|"else"|"for"|"function"|"return"|"break"|"continue"|"and"|"not"|"or"|"local"|"true"|"while"|"false"|"nil" {
	head = list_w_tokens(yylineno,id++,yytext,"KEYWORD");
}
"/*"	{
			int c;
			while ((c = input()) != EOF ) {
				if(c == '*') {
					if((c = input()) == '/'){
						head = list_w_tokens(yylineno,id++,yytext,"COMMENT");
						break;
					}else
						unput(c);
				}
			}
			if(c==EOF){
				printf("\nError.Comment not terminated in line %d\nExit\n",yylineno);
				exit(1);
			}
		}


{id}				{ head = list_w_tokens(yylineno,id++,yytext,"IDENTIFIER"); }
{string}			{ head = list_w_tokens(yylineno,id++,yytext,"STRING"); }
{integer} 			{ head = list_w_tokens(yylineno,id++,yytext,"INTEGER"); }
{double} 			{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE"); }
{character} 		{ head = list_w_tokens(yylineno,id++,yytext,"CHARACTER"); }
{op_add} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_sub} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_less} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_greater} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_equal} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_less_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_great_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_diff} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_log_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_plus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_minus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_mod} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_mul} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{op_div} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR"); }
{left_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACER"); }
{right_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACER"); }
{left_bracket} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACKET"); }
{right_bracket} 	{ head = list_w_tokens(yylineno,id++,yytext,"BRACKET"); }
{left_parentheses} 	{ head = list_w_tokens(yylineno,id++,yytext,"PARENTHESES"); }
{right_parentheses} { head = list_w_tokens(yylineno,id++,yytext,"PARENTHESES"); }
{semicolon} 		{ head = list_w_tokens(yylineno,id++,yytext,"SEMICOLON"); }
{comma} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMA"); }
{colon} 			{ head = list_w_tokens(yylineno,id++,yytext,"COLON"); }
{double_colon} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE COLON"); }
{dot} 				{ head = list_w_tokens(yylineno,id++,yytext,"DOT"); }
{double_dot} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE DOT"); }
{comment1} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMENT"); }
{undefined}         {head = list_w_tokens(yylineno,id++,yytext,"UNDEFINED");}
 /* Ignore comments and whitespace. */

#[^\n]*     {}
[\t\r\n]   {}


<<EOF>> {	printf("(eof %u)\n", yylineno); 
			//print_list(head);
			int i = 0;
			for(i = 1; i <= id; i++)
				print_token(i);
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


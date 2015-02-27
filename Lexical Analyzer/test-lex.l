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
	id++;
	return head;
};

void print_list(struct token_t *head){

	printf("The Linked List : \n");
 	struct token_t *tmp = head;
 	while(tmp!=NULL){
   		printf("%d:    %d    %s    %s\n",tmp->line,tmp->id,tmp->buffer,tmp->category);
   		tmp=tmp->next;
   		}
  	printf("NULL");
}



%}

%option yylineno
%option noyywrap
%option prefix = "alpha_yy"

id          [A-Za-z_][A-Za-z_0-9]*
integer		(0[xX][0-9A-Fa-f]*)|([0-9]*)
double		[0-9]+.[0-9]+
character	'.'

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


"/*"			BEGIN(COMMENT);
<COMMENT>[^*]*
<COMMENT>"*"+[^*/]*
<COMMENT>"*"+"/"	BEGIN(INITIAL);

"if"|"else"|"for"|"function"|"return"|"break"|"continue"|"and"|"not"|"or"|"local"|"true"|"false"|"nil" { 
	printf("%d:    %d    %s    KEYWORD\n",yylineno,id,yytext); 
	head = list_w_tokens(yylineno,id,yytext,"KEYWORD");
}
"/*"	{
			int c;
			while ((c = input()) != EOF ) {
				if(c == '*') {
					if((c = input()) == '/'){
						printf("%d:    %d    %s    COMMENT\n",yylineno,id,yytext);
						break;
					}else
						unput(c);
				}
			}
		}


{id}	{printf("%d:    %d    %s    IDENTIFIER\n",yylineno,id,yytext); 
		 head = list_w_tokens(yylineno,id,yytext,"IDENTIFIER");		
}

{integer} 			{printf("%d:    %d    %s    INTEGER     \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"IDENTIFIER"); }
{double} 			{printf("%d:    %d    %s    DOUBLE      \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"DOUBLE"); }
{character} 		{printf("%d:    %d    %s    CHARACTER   \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"CHARACTER"); }
{op_add} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_sub} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_less} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_greater} 		{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_equal} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_less_eq} 		{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_great_eq} 		{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_diff} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_log_eq} 		{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_plus} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_minus} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_mod} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_mul} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{op_div} 			{printf("%d:    %d    %s    OPERATOR    \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"OPERATOR"); }
{left_bracer} 		{printf("%d:    %d    %s    BRACER      \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"BRACER"); }
{right_bracer} 		{printf("%d:    %d    %s    BRACER      \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"BRACER"); }
{left_bracket} 		{printf("%d:    %d    %s    BRACKET     \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"BRACKET"); }
{right_bracket} 	{printf("%d:    %d    %s    BRACKET     \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"BRACKET"); }
{left_parentheses} 	{printf("%d:    %d    %s    PARENTHESES \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"PARENTHESES"); }
{right_parentheses} {printf("%d:    %d    %s    PARENTHESES \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"PARENTHESES"); }
{semicolon} 		{printf("%d:    %d    %s    SEMICOLON   \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"SEMICOLON"); }
{comma} 			{printf("%d:    %d    %s    COMMA       \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"COMMA"); }
{colon} 			{printf("%d:    %d    %s    COLON       \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"COLON"); }
{double_colon} 		{printf("%d:    %d    %s    DOUBLE COLON\n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"DOUBLE COLON"); }
{dot} 				{printf("%d:    %d    %s    DOT         \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"DOT"); }
{double_dot} 		{printf("%d:    %d    %s    DOUBLE DOT  \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"DOUBLE DOT"); }
{comment1} 			{printf("%d:    %d    %s    COMMENT     \n",yylineno,id,yytext); head = list_w_tokens(yylineno,id,yytext,"COMMENT"); }
 /* Ignore comments and whitespace. */

#[^\n]*     {}
[\t\r\n]   {}


<<EOF>> {	printf("(eof %u)\n", yylineno); 
			print_list(head);

			return 0;
}

%%

int main(int argc, char* argv[]) {
  yylex() ;
    return EXIT_SUCCESS ;
}


%{
#include <stdio.h>
#include <stdlib.h>
int id = 1;
struct token_t{
	int id;
	char *buffer;
	char *category;
	int line;
	int comment_level;
	struct token_t *next;
}*head;
struct token_t* list_w_tokens(int line,int id,char* buffer,char* category,int comment_level){
	struct token_t *list;
	list = (struct token_t *)malloc(sizeof(struct token_t));
	list->line=line;
	list->id=id;
	list->buffer=strdup(buffer);
	list->category=strdup(category);
	list->next=head;
	list->comment_level=comment_level;
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
		/*if(strcmp(tmp->category,"NESTED_COMMENT_")==0){
			printf("%d:    %d    %s    \t%s\tlevel: %d\n",tmp->line,tmp->id,tmp->buffer,tmp->category,tmp->comment_level);
			tmp=tmp->next;
			break;
		}*/
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
%s STRING

%%

"\""	{
			int c;
			char get[100];
			char* get_ptr;
			get_ptr=get;
			int len=0;
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
				}else if(c == '\"'){
					*get_ptr++ = '\0';
					break;
				}else{
					*get_ptr++ = c;
				}
			}

			printf("%d:    %d    %s    STRING\n",yylineno,id++,get);
			head = list_w_tokens(yylineno,id++,get,"STRING");
		}


"if"|"else"|"for"|"function"|"return"|"break"|"continue"|"and"|"not"|"or"|"local"|"true"|"while"|"false"|"nil" {
	head = list_w_tokens(yylineno,id++,yytext,"KEYWORD",0);
}
"/*"	{
			static 	int level;
			int c;
			int nested_comment(int level){
				while ((c = input()) != EOF ){
					if(c=='*'){
						if((c = input()) == '/'){
							
							head = list_w_tokens(yylineno,id++,yytext,"NESTED_COMMENT_",level);
							break;
							return level;
						}
						else
							unput(c);
					}
					if(c=='/'){
						if(c=input()=='*'){
							level++;
							nested_comment(level);
						}
					
				}
			}
		}

		while ((c = input()) != EOF ) {
				if(c == '*') {
					if((c = input()) == '/'){
						head = list_w_tokens(yylineno,id++,yytext,"COMMENT",level);
						break;
					}else
						unput(c);
				}
				if(c=='/'){
					if(c=input()=='*'){
						level++;
						nested_comment(level);
						}
					
				}
			if(c==EOF){
				printf("\nError.Comment not terminated in line %d\nExit\n",yylineno);
				exit(1);
			}
		}
}



{id}				{ head = list_w_tokens(yylineno,id++,yytext,"IDENTIFIER",0); }
{integer} 			{ head = list_w_tokens(yylineno,id++,yytext,"INTEGER",0); }
{double} 			{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE",0); }
{character} 		{ head = list_w_tokens(yylineno,id++,yytext,"CHARACTER",0); }
{op_add} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_sub} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_less} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_greater} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_equal} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_less_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_great_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_diff} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_log_eq} 		{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_plus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_minus} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_mod} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_mul} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{op_div} 			{ head = list_w_tokens(yylineno,id++,yytext,"OPERATOR",0); }
{left_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACER",0); }
{right_bracer} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACER",0); }
{left_bracket} 		{ head = list_w_tokens(yylineno,id++,yytext,"BRACKET",0); }
{right_bracket} 	{ head = list_w_tokens(yylineno,id++,yytext,"BRACKET",0); }
{left_parentheses} 	{ head = list_w_tokens(yylineno,id++,yytext,"PARENTHESES",0); }
{right_parentheses} { head = list_w_tokens(yylineno,id++,yytext,"PARENTHESES",0); }
{semicolon} 		{ head = list_w_tokens(yylineno,id++,yytext,"SEMICOLON",0); }
{comma} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMA",0); }
{colon} 			{ head = list_w_tokens(yylineno,id++,yytext,"COLON",0); }
{double_colon} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE COLON",0); }
{dot} 				{ head = list_w_tokens(yylineno,id++,yytext,"DOT",0); }
{double_dot} 		{ head = list_w_tokens(yylineno,id++,yytext,"DOUBLE DOT",0); }
{comment1} 			{ head = list_w_tokens(yylineno,id++,yytext,"COMMENT",0); }
{undefined}         {head = list_w_tokens(yylineno,id++,yytext,"UNDEFINED",0);}
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


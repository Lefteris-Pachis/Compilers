%{
	#include <stdio.h>
	int yyerror(char* yaccProvidedMessage);
	int alpha_yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
%}


%start program

%token ID INTEGER OPERATOR PUNCTUATION KEYWORD DOUBLE CHAR STR SINGLE_LINE_COMMENT MULTI_LINE_COMMENT NESTED_COMMENT

%right		'='
%left		','
%left		'+' '-'
%left		'*' '/'
%nonassoc	UMINUS
%left		'(' ')'

%%

program:
			;

%%



int yyerror(char* yaccProvidedMessage){
	printf("%s: at line %d, before token: %s\n",yaccProvidedMessage,yylineno,yytext);
	printf("INPUT NOT VALID\n");
}

int main(int argc, char** argv){
	if(argc > 1){
		if(!(yyin = fopen(argv[1], "r"))){
			printf("Cannot read file: %s\n",argv[1]);
			return 1;
		}
	}
	else
		yyin = stdin;

	yyparse();
	return 0;
}
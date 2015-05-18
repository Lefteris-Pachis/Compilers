%{
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

%}

%option yylineno
%option noyywrap

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
					yylval.strVal = strdup(get);
					return STRING;
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
						exit(1);
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


"if"		{ return IF; }
"else"		{ return ELSE; }
"for"		{ return FOR; }
"function"	{ return FUNCTION; }
"return"	{ return RETURN; }
"break"		{ return BREAK; }
"continue"	{ return CONTINUE; }
"and"		{ return AND; }
"not"		{ return NOT; }
"or"		{ return OR; }
"local"		{ return LOCAL; }
"true"		{ return TRUE; }
"while"		{ return WHILE; }
"false"		{ return FALSE; }
"nil" 		{ return NIL; }

"="			{ return ASSIGN; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return MUL; }
"/"			{ return DIV; }
"%"			{ return MOD; }
"=="		{ return EQ; }
"!="		{ return NOT_EQ; }
"++"		{ return PLUS_PLUS; }
"--"		{ return MINUS_MINUS; }
">"			{ return GREATER_THAN; }
"<"			{ return LESS_THAN; }
">="		{ return GREATER_EQ; }
"<=" 		{ return LESS_EQ; }

"{"			{ return L_BRACE; }
"}"			{ return R_BRACE; }
"["			{ return L_BRACKET; }
"]"			{ return R_BRACKET; }
"("			{ return L_PARENTHESIS; }
")"			{ return R_PARENTHESIS; }
";"			{ return SEMICOLON; }
","			{ return COMMA; }
":"			{ return COLON; }
"::"		{ return D_COLON; }
"."			{ return DOT; }
".." 		{ return D_DOT; }

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
							nested_comment();
						}
						else
							unput(c);
					}
					else
						continue;
				}
			}
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
{id}				{ yylval.strVal = strdup(yytext); return ID; }
{integer} 			{ yylval.intVal = atoi(yytext); return INTEGER; }
{double} 			{ yylval.realVal = atof(yytext); return DOUBLE; }
{character} 		{ yylval.strVal = strdup(yytext); return CHAR; }
{comment1} 			{}
{space}				{}

[\t\r\n]   			{}
.					{ printf("undefined character %s in line %d\n",yytext,yylineno); }
<<EOF>> {	printf("(eof %u)\n", yylineno); 
			
			return 0;
}

%%
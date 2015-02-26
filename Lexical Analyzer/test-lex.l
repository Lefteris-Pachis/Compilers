%{
#include <stdio.h>
#include <stdlib.h>
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

keyword_if		"if"
keyword_else		"else"
keyword_for		"for"
keyword_function	"function"
keyword_return		"return"
keyword_break		"break"
keyword_continue	"continue"
keyword_and		"and"
keyword_not 		"not"
keyword_or 		"or"
keyword_local		"local"
keyword_true		"true"
keyword_false		"false"
keyword_nil 		"nil"

left_bracer		"{"
right_bracer		"}"
left_bracket		"["
right_bracket		"]"
left_parentheses	"("
right_parentheses	")"
semicolon		";"
comma			","
colon			":"
double_colon		"::"
dot			"."
double_dot		".."


comment1		"//".*	

%x COMMENT

%%

"/*"				BEGIN(COMMENT);
<COMMENT>[^*]*
<COMMENT>"*"+[^*/]*
<COMMENT>"*"+"/"	BEGIN(INITIAL);


 /* Ignore comments and whitespace. */

#[^\n]*     {}
[\t\r\n]   {}


<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
    return EXIT_SUCCESS ;
}
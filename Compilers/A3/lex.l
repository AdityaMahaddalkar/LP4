%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	char *datatype;	

%}

number [0-9]+
variable [a-zA-Z_][0-9a-zA-Z_]*
float_number {number}\.{number}
type_keyword int|float|char|double|long|void
unary_operator \+\+|\-\-
assignment \+=|\-=|\*=|\/=
arithmetic_operator \+|\-|\*|\/
logical_operator &&|\|\|
bitwise_operator &|\||\^
comparators ==|!=|<|>|<=|>=
string_literal \"(\\.|[^"\\])*\"


%%
[\n\t ]+ {};
"main" {return MAIN;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
{string_literal} {yylval.sValue = strdup(yytext); return STRING;}
{unary_operator} {return UNARYOP;}
{type_keyword} {yylval.sValue = strdup(yytext); datatype = strdup(yytext); return DTYPE;}
{comparators} {return COMP;}
{arithmetic_operator} {return ARITHOP;}
{assignment} {return ASSIGNOP;}
{logical_operator} {return LOGICOP;}
{variable} {yylval.sValue = strdup(yytext); return VAR;}
{float_number} {yylval.fValue = atof(yytext); return FNUM;}
{number} {yylval.iValue = atoi(yytext); return NUM;}
. {return yytext[0];}

%%

int yywrap(){

	return 1;
}

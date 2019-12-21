%{
#include <stdio.h>

// line variable counts number of lines

int line = 0;
%}

number [0-9]+
variable [a-zA-Z_][0-9a-zA-Z_]+
type_keyword int|float|char|double|long|void
init_assignment =
assignment \+=|\-=|\*=|\/=
arithmetic_operator \+|\-|\*|\/
logical_operator &&|\|\|
bitwise_operator &|\||\^
comparators ==|!=|<|>|<=|>=
string_literal \"(\\.|[^"\\])*\"

%%
"#include" {fprintf(yyout, "%s\tMACRO\t%d\n", yytext, line);}
"return" {fprintf(yyout, "%s\tRET\t%d\n", yytext, line);}
"<".+\.h">" {fprintf(yyout, "%s\tHEADER\t%d\n", yytext, line);} //TODO: DEBUG
"if" {fprintf(yyout, "%s\tIF\t%d\n", yytext, line);}
"else" {fprintf(yyout, "%s\tELSE\t%d\n", yytext, line);}
"else if" {fprintf(yyout, "%s\tELIF\t%d\n", yytext, line);}
"(" {fprintf(yyout, "%s\tORB\t%d\n", yytext, line);}
")" {fprintf(yyout, "%s\tCRB\t%d\n", yytext, line);}
"{" {fprintf(yyout, "%s\tOCB\t%d\n", yytext, line);}
"}" {fprintf(yyout, "%s\tCCB\t%d\n", yytext, line);}
";" {fprintf(yyout, "%s\tBREAK\t%d\n", yytext, line);}
{string_literal} {fprintf(yyout, "%s\tSTRING\t%d\n", yytext, line);}
{type_keyword} {fprintf(yyout, "%s\tTYPE\t%d\n", yytext, line);}
{comparators} {fprintf(yyout, "%s\tCOMP\t%d\n", yytext, line);}
{init_assignment} {fprintf(yyout, "%s\tINIT\t%d\n", yytext, line);}
{assignment} {fprintf(yyout, "%s\tASSIGN\t%d\n", yytext, line);}
{arithmetic_operator} {fprintf(yyout, "%s\tARITH\t%d\n", yytext, line);}
{logical_operator} {fprintf(yyout, "%s\tLOGIC\t%d\n", yytext, line);}
{bitwise_operator} {fprintf(yyout, "%s\tBITWISE\t%d\n", yytext, line);}
{variable} {fprintf(yyout, "%s\tVAR\t%d\n", yytext, line);}
{number} {fprintf(yyout, "%s\tNUM\t%d\n", yytext, line);}
. ;
\n {line++;}
%%

int yywrap(){
  return 1;
}

int main(){
  extern FILE *yyin, *yyout;
  yyin = fopen("data/sample.c", "r");
  yyout = fopen("data/output.txt", "w+");
  yylex();
}

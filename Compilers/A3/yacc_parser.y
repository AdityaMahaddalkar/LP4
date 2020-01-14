%{
	#include <stdio.h>
	#include "symbol_table.h"
	FILE *logfile;
	symtab sTab;
	int yylex();
	int yyerror();
	char *datatype;
	char var_names[256][128];
	int iterator;
%}

%union
{
	int iValue;
	float fValue;
	char *sValue;
}

%token <iValue> NUM
%token <fValue> FNUM
%token <sValue> DTYPE
%token <sValue> STRING
%token <sValue> VAR
%token <sValue> ARITHOP
%token <sValue> EQUAL

%token MAIN IF ELSE COMP LOGICOP ASSIGNOP FOR UNARYOP WHILE
%start prog

/*
%type <iValue> int_arithlist
%type <fValue> float_arithlist
*/

%%

prog: DTYPE MAIN '(' ')' '{' body '}' ;

body: stmtlist;

stmtlist: stmt stmtlist | ;

stmt: declaration | if_stmt | assignment | for_stmt | VAR UNARYOP ';' | while_stmt;

declaration: DTYPE var_list ';'			{fprintf(logfile, "Setting datatype\n"); checkDatatype(&sTab, $1, var_names, iterator); iterator = 0;}
		;

var_list: VAR					{fprintf(logfile, "%s\n", $1); addVariableWithoutValue(&sTab, $1); strcpy(var_names[iterator++],$1);}
		 | VAR EQUAL NUM			{fprintf(logfile, "%s\t%d\n", $1, $3); addInt(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR EQUAL NUM ',' var_list	{fprintf(logfile, "%s\t%d\n", $1, $3); addInt(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR ',' var_list		{fprintf(logfile, "%s\n", $1); addVariableWithoutValue(&sTab, $1); strcpy(var_names[iterator++], $1);}
		 | VAR EQUAL FNUM			{fprintf(logfile, "%s\t%f\n", $1, $3); addFloat(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR EQUAL FNUM ',' var_list	{fprintf(logfile, "%s\t%f\n", $1, $3); addFloat(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR EQUAL STRING		{fprintf(logfile, "%s\t%s\n", $1, $3); addString(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR EQUAL STRING ',' var_list	{fprintf(logfile, "%s\t%s\n", $1, $3); addString(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 ;

if_stmt: IF '(' condition ')' '{' stmtlist '}'
		|IF '(' condition ')' '{' stmtlist '}' ELSE '{' stmtlist '}'
		;

condition: VAR COMP VAR
		 | VAR COMP NUM
		 | VAR COMP FNUM
		 | VAR COMP VAR LOGICOP condition
		 | VAR COMP NUM LOGICOP condition
		 | VAR COMP FNUM LOGICOP condition
		 ;

assignment: VAR EQUAL expression ';' {

				char *dtype = returnDataType(&sTab, $1);

				if(strcmp(dtype, "int")==0){
					assignNumberToVariable(&sTab, $1, $<iValue>3);
				}
				else if(strcmp(dtype, "float")==0){
					assignFNumberToVariable(&sTab, $1, $<fValue>3);
				}
				else{
					fprintf(stderr, "ERROR: in expression -> expression Arithop expression\n");
				}
			}
			;

expression: expression ARITHOP expression	{$<fValue>$ = returnArithmeticOperationFloat($<fValue>1, $2, $<fValue>3);}
		| VAR	{

				char *dtype = returnDataType(&sTab, $1);

				if(strcmp(dtype, "int")==0){
					$<iValue>$ = returnIntegerValue(&sTab, $1);
				}
				else if(strcmp(dtype, "float")==0){
					$<fValue>$ = returnFloatValue(&sTab, $1);
				}
				else{
					fprintf(stderr, "ERROR: in expression -> expression Arithop expression\n");
				}


		}
		| NUM	{$<iValue>$ = $1;}
		| FNUM	{$<fValue>$ = $1;}
		;


for_stmt: FOR '(' for_declaration ';' condition ';' for_arithmetic ')' '{' stmtlist '}'
		;

for_declaration: DTYPE var_list | var_list;

for_arithmetic: VAR EQUAL VAR 
			   | VAR EQUAL NUM
			   | VAR UNARYOP
			   ;

while_stmt: WHILE '(' condition ')' '{' stmtlist '}'
			;

%%

int yyerror(char * s)
{
	fprintf(stderr, "%s\n", s);
	return -1;
}


int main(void)
{
	iterator=0;
	extern FILE *yyin;
	logfile = fopen("logfile.log", "w+");
	yyin = fopen("data/sample.c", "r");
	yyparse();
	printSymtab(&sTab);
	return 0;
}

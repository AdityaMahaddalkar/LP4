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

%token MAIN IF ELSE COMP LOGICOP ASSIGNOP FOR UNARYOP WHILE
%start prog

%type <iValue> arithlist

%%

prog: DTYPE MAIN '(' ')' '{' body '}' ;

body: stmtlist;

stmtlist: stmt stmtlist | ;

stmt: declaration | if_stmt | arithmetic_stmt | for_stmt | VAR UNARYOP ';' | while_stmt;

declaration: DTYPE var_list ';'			{fprintf(logfile, "Setting datatype\n"); checkDatatype(&sTab, $1, var_names, iterator); iterator = 0;}
		;

var_list: VAR					{fprintf(logfile, "%s\n", $1); addVariableWithoutValue(&sTab, $1); strcpy(var_names[iterator++],$1);}
		 | VAR '=' NUM			{fprintf(logfile, "%s\t%d\n", $1, $3); addInt(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR '=' NUM ',' var_list	{fprintf(logfile, "%s\t%d\n", $1, $3); addInt(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR ',' var_list		{fprintf(logfile, "%s\n", $1); addVariableWithoutValue(&sTab, $1); strcpy(var_names[iterator++], $1);}
		 | VAR '=' FNUM			{fprintf(logfile, "%s\t%f\n", $1, $3); addFloat(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR '=' FNUM ',' var_list	{fprintf(logfile, "%s\t%f\n", $1, $3); addFloat(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR '=' STRING		{fprintf(logfile, "%s\t%s\n", $1, $3); addString(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
		 | VAR '=' STRING ',' var_list	{fprintf(logfile, "%s\t%s\n", $1, $3); addString(&sTab, $1, $3); strcpy(var_names[iterator++], $1);}
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

arithmetic_stmt: VAR '=' VAR ARITHOP arithlist ';'	{assignNumberToVariable(&sTab, $1, returnArithmeticOperationInt(returnIntegerValue(&sTab, $3), $4, $5));}
			   | VAR '=' NUM ARITHOP arithlist ';'				{assignNumberToVariable(&sTab, $1, returnArithmeticOperationInt($3, $4, $5));}
			   | VAR '=' VAR ';'													{assignVariableToVariable(&sTab, $1, $3);}
			   | VAR '=' NUM ';'													{assignNumberToVariable(&sTab, $1, $3);}
			   ;
arithlist: VAR ARITHOP arithlist	{$$ = returnArithmeticOperationInt(returnIntegerValue(&sTab, $1), $2, $3);}
		 | NUM ARITHOP arithlist			{$$ = returnArithmeticOperationInt($1, $2, $3); }
		 | VAR												{$$ = returnIntegerValue(&sTab, $1);}
		 | NUM												{$$ = $1;}
		 ;

for_stmt: FOR '(' for_declaration ';' condition ';' for_arithmetic ')' '{' stmtlist '}'
		;

for_declaration: DTYPE var_list | var_list;

for_arithmetic: VAR '=' VAR ARITHOP arithlist
			   | VAR '=' NUM ARITHOP arithlist
			   | VAR '=' VAR
			   | VAR '=' NUM
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

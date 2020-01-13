%{
	#include <stdio.h>
	int yylex();
	int yyerror();
%}

%token DTYPE STRING VAR NUM MAIN FNUM IF ELSE COMP LOGICOP ARITHOP ASSIGNOP FOR UNARYOP WHILE
%start prog

%%

prog: DTYPE MAIN '(' ')' '{' body '}' ;

body: stmtlist;

stmtlist: stmt stmtlist | ;

stmt: declaration | if_stmt | arithmetic_stmt | for_stmt | VAR UNARYOP ';' | while_stmt;

declaration: DTYPE var_list ';';

var_list: VAR
		 | VAR '=' NUM
		 | VAR '=' NUM ',' var_list
		 | VAR ',' var_list
		 | VAR '=' FNUM
		 | VAR '=' FNUM ',' var_list
		 | VAR '=' STRING
		 | VAR '=' STRING ',' var_list
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

arithmetic_stmt: VAR '=' VAR ARITHOP arithlist ';'
			   | VAR '=' NUM ARITHOP arithlist ';'
			   | VAR '=' VAR ';'
			   | VAR '=' NUM ';'
			   ;
arithlist: VAR ARITHOP arithlist
		 | NUM ARITHOP arithlist
		 | VAR
		 | NUM
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
/* yacc error handler */
{    
	fprintf(stderr, "%s\n", s); 
	return -1;
}  
   
int main(void)  
{ 
	extern FILE *yyin, *yyout;
	yyin = fopen("data/sample.c", "r");
	return yyparse(); 
}

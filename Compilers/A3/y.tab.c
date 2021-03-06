#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yacc_parser.y"
	#include <stdio.h>
	#include "symbol_table.h"
	FILE *logfile;
	symtab sTab;
	int yylex();
	int yyerror();
	char *datatype;
	char var_names[256][128];
	int iterator;
#line 13 "yacc_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int iValue;
	float fValue;
	char *sValue;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define FNUM 258
#define DTYPE 259
#define STRING 260
#define VAR 261
#define ARITHOP 262
#define EQUAL 263
#define MAIN 264
#define IF 265
#define ELSE 266
#define COMP 267
#define LOGICOP 268
#define ASSIGNOP 269
#define FOR 270
#define UNARYOP 271
#define WHILE 272
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    4,    9,    9,    9,    9,    9,    9,    9,    9,    5,
    5,   10,   10,   10,   10,   10,   10,    6,   11,   11,
   11,   11,    7,   12,   12,   13,   13,   13,    8,
};
static const short yylen[] = {                            2,
    7,    1,    2,    0,    1,    1,    1,    1,    3,    1,
    3,    1,    3,    5,    3,    3,    5,    3,    5,    7,
   11,    3,    3,    3,    5,    5,    5,    4,    3,    1,
    1,    1,   11,    2,    1,    3,    3,    2,    7,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    0,    5,    6,    7,    8,   10,    0,
    0,    0,    0,    0,    0,    0,    1,    3,    0,    0,
   11,   31,   32,   30,    0,    9,    0,    0,    0,   35,
    0,    0,    0,    0,    0,   15,    0,   28,    0,    0,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   14,   17,   19,    0,    0,    0,    0,
    0,    0,   26,   27,   25,    0,    0,    0,   39,    0,
    0,   38,    0,    0,   37,   36,    0,    0,    0,   21,
   33,
};
static const short yydgoto[] = {                          2,
   12,   13,   14,   15,   16,   17,   18,   19,   21,   38,
   35,   41,   78,
};
static const short yysindex[] = {                      -232,
 -247,    0,  -12,   -9,  -90, -250, -217, -242,    3,    8,
   13,  -71,    0, -250,    0,    0,    0,    0,    0,  -44,
   -4, -245,   -3, -204, -210, -204,    0,    0, -218, -217,
    0,    0,    0,    0,  -58,    0, -209,   18, -217,    0,
    1,   20,   19,   21,   22,    0, -245,    0, -220,  -61,
    0, -204,  -59, -217, -217, -217, -195, -200, -199, -198,
 -250,   12, -250,    0,    0,    0, -204, -204, -204,  -53,
 -187,  -50,    0,    0,    0, -189, -240,   37,    0,  -43,
 -243,    0,  -42, -250,    0,    0, -250,  -46,  -41,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  -40,    0,    0,    0,    0,
    0,    0,    0,  -40,    0,    0,    0,    0,    0,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,   27,   28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   29,  -35,  -34,  -33,
  -40,    0,  -40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -123,    0,    0,    0,    0,
    0,    0,    0,  -40,    0,    0,  -40,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,  -11,    0,    0,    0,    0,    0,    0,  -20,  -22,
   42,    0,    0,
};
#define YYTABLESIZE 219
static const short yytable[] = {                         30,
   48,   20,   28,   42,   40,   23,   24,   22,    7,   46,
    8,   32,   33,   85,    9,   34,    3,   86,   51,   10,
   22,   11,   81,   23,   24,   22,    1,    4,   23,   62,
   82,    5,    6,   64,   65,   66,   58,   59,   43,   44,
   60,   45,   24,   20,   73,   74,   75,   25,   39,   70,
   20,   72,   26,   27,   31,   36,   37,   49,   50,   52,
   53,   61,   54,   63,   55,   56,   47,   67,   68,   69,
   71,   76,   88,   77,   79,   89,   80,   83,   90,   84,
   87,   12,   13,   91,    4,   16,   18,   29,   57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,    0,   20,    0,    0,
    0,   20,    0,    0,    0,    0,   20,    0,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   29,
};
static const short yycheck[] = {                         44,
   59,  125,   14,   26,   25,   41,   41,   41,  259,   30,
  261,  257,  258,  257,  265,  261,  264,  261,   39,  270,
  263,  272,  263,   59,   59,   59,  259,   40,  271,   52,
  271,   41,  123,   54,   55,   56,  257,  258,  257,  258,
  261,  260,   40,  261,   67,   68,   69,   40,  259,   61,
  261,   63,   40,  125,   59,   59,  261,  267,   41,   59,
   41,  123,   44,  123,   44,   44,  262,  268,  268,  268,
   59,  125,   84,  261,  125,   87,  266,   41,  125,  123,
  123,   59,   59,  125,  125,   59,   59,   59,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  259,   -1,  261,   -1,   -1,
   -1,  265,   -1,   -1,   -1,   -1,  270,   -1,  272,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  262,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUM",
"FNUM","DTYPE","STRING","VAR","ARITHOP","EQUAL","MAIN","IF","ELSE","COMP",
"LOGICOP","ASSIGNOP","FOR","UNARYOP","WHILE",
};
static const char *yyrule[] = {
"$accept : prog",
"prog : DTYPE MAIN '(' ')' '{' body '}'",
"body : stmtlist",
"stmtlist : stmt stmtlist",
"stmtlist :",
"stmt : declaration",
"stmt : if_stmt",
"stmt : assignment",
"stmt : for_stmt",
"stmt : VAR UNARYOP ';'",
"stmt : while_stmt",
"declaration : DTYPE var_list ';'",
"var_list : VAR",
"var_list : VAR EQUAL NUM",
"var_list : VAR EQUAL NUM ',' var_list",
"var_list : VAR ',' var_list",
"var_list : VAR EQUAL FNUM",
"var_list : VAR EQUAL FNUM ',' var_list",
"var_list : VAR EQUAL STRING",
"var_list : VAR EQUAL STRING ',' var_list",
"if_stmt : IF '(' condition ')' '{' stmtlist '}'",
"if_stmt : IF '(' condition ')' '{' stmtlist '}' ELSE '{' stmtlist '}'",
"condition : VAR COMP VAR",
"condition : VAR COMP NUM",
"condition : VAR COMP FNUM",
"condition : VAR COMP VAR LOGICOP condition",
"condition : VAR COMP NUM LOGICOP condition",
"condition : VAR COMP FNUM LOGICOP condition",
"assignment : VAR EQUAL expression ';'",
"expression : expression ARITHOP expression",
"expression : VAR",
"expression : NUM",
"expression : FNUM",
"for_stmt : FOR '(' for_declaration ';' condition ';' for_arithmetic ')' '{' stmtlist '}'",
"for_declaration : DTYPE var_list",
"for_declaration : var_list",
"for_arithmetic : VAR EQUAL VAR",
"for_arithmetic : VAR EQUAL NUM",
"for_arithmetic : VAR UNARYOP",
"while_stmt : WHILE '(' condition ')' '{' stmtlist '}'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 122 "yacc_parser.y"

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
#line 313 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 11:
#line 46 "yacc_parser.y"
	{fprintf(logfile, "Setting datatype\n"); checkDatatype(&sTab, yystack.l_mark[-2].sValue, var_names, iterator); iterator = 0;}
break;
case 12:
#line 49 "yacc_parser.y"
	{fprintf(logfile, "%s\n", yystack.l_mark[0].sValue); addVariableWithoutValue(&sTab, yystack.l_mark[0].sValue); strcpy(var_names[iterator++],yystack.l_mark[0].sValue);}
break;
case 13:
#line 50 "yacc_parser.y"
	{fprintf(logfile, "%s\t%d\n", yystack.l_mark[-2].sValue, yystack.l_mark[0].iValue); addInt(&sTab, yystack.l_mark[-2].sValue, yystack.l_mark[0].iValue); strcpy(var_names[iterator++], yystack.l_mark[-2].sValue);}
break;
case 14:
#line 51 "yacc_parser.y"
	{fprintf(logfile, "%s\t%d\n", yystack.l_mark[-4].sValue, yystack.l_mark[-2].iValue); addInt(&sTab, yystack.l_mark[-4].sValue, yystack.l_mark[-2].iValue); strcpy(var_names[iterator++], yystack.l_mark[-4].sValue);}
break;
case 15:
#line 52 "yacc_parser.y"
	{fprintf(logfile, "%s\n", yystack.l_mark[-2].sValue); addVariableWithoutValue(&sTab, yystack.l_mark[-2].sValue); strcpy(var_names[iterator++], yystack.l_mark[-2].sValue);}
break;
case 16:
#line 53 "yacc_parser.y"
	{fprintf(logfile, "%s\t%f\n", yystack.l_mark[-2].sValue, yystack.l_mark[0].fValue); addFloat(&sTab, yystack.l_mark[-2].sValue, yystack.l_mark[0].fValue); strcpy(var_names[iterator++], yystack.l_mark[-2].sValue);}
break;
case 17:
#line 54 "yacc_parser.y"
	{fprintf(logfile, "%s\t%f\n", yystack.l_mark[-4].sValue, yystack.l_mark[-2].fValue); addFloat(&sTab, yystack.l_mark[-4].sValue, yystack.l_mark[-2].fValue); strcpy(var_names[iterator++], yystack.l_mark[-4].sValue);}
break;
case 18:
#line 55 "yacc_parser.y"
	{fprintf(logfile, "%s\t%s\n", yystack.l_mark[-2].sValue, yystack.l_mark[0].sValue); addString(&sTab, yystack.l_mark[-2].sValue, yystack.l_mark[0].sValue); strcpy(var_names[iterator++], yystack.l_mark[-2].sValue);}
break;
case 19:
#line 56 "yacc_parser.y"
	{fprintf(logfile, "%s\t%s\n", yystack.l_mark[-4].sValue, yystack.l_mark[-2].sValue); addString(&sTab, yystack.l_mark[-4].sValue, yystack.l_mark[-2].sValue); strcpy(var_names[iterator++], yystack.l_mark[-4].sValue);}
break;
case 28:
#line 71 "yacc_parser.y"
	{

				char *dtype = returnDataType(&sTab, yystack.l_mark[-3].sValue);

				if(strcmp(dtype, "int")==0){
					assignNumberToVariable(&sTab, yystack.l_mark[-3].sValue, yystack.l_mark[-1].iValue);
				}
				else if(strcmp(dtype, "float")==0){
					assignFNumberToVariable(&sTab, yystack.l_mark[-3].sValue, yystack.l_mark[-1].fValue);
				}
				else{
					fprintf(stderr, "ERROR: in expression -> expression Arithop expression\n");
				}
			}
break;
case 29:
#line 87 "yacc_parser.y"
	{yyval.fValue = returnArithmeticOperationFloat(yystack.l_mark[-2].fValue, yystack.l_mark[-1].sValue, yystack.l_mark[0].fValue);}
break;
case 30:
#line 88 "yacc_parser.y"
	{

				char *dtype = returnDataType(&sTab, yystack.l_mark[0].sValue);

				if(strcmp(dtype, "int")==0){
					yyval.iValue = returnIntegerValue(&sTab, yystack.l_mark[0].sValue);
				}
				else if(strcmp(dtype, "float")==0){
					yyval.fValue = returnFloatValue(&sTab, yystack.l_mark[0].sValue);
				}
				else{
					fprintf(stderr, "ERROR: in expression -> expression Arithop expression\n");
				}

		}
break;
case 31:
#line 103 "yacc_parser.y"
	{yyval.iValue = yystack.l_mark[0].iValue;}
break;
case 32:
#line 104 "yacc_parser.y"
	{yyval.fValue = yystack.l_mark[0].fValue;}
break;
#line 602 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

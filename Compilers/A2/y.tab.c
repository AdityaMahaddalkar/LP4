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
#line 21 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

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

#define DTYPE 257
#define STRING 258
#define VAR 259
#define NUM 260
#define MAIN 261
#define FNUM 262
#define IF 263
#define ELSE 264
#define COMP 265
#define LOGICOP 266
#define ARITHOP 267
#define ASSIGNOP 268
#define FOR 269
#define UNARYOP 270
#define WHILE 271
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    4,    9,    9,    9,    9,    9,    9,    9,    9,    5,
    5,   10,   10,   10,   10,   10,   10,    6,    6,    6,
    6,   11,   11,   11,   11,    7,   12,   12,   13,   13,
   13,   13,   13,    8,
};
static const short yylen[] = {                            2,
    7,    1,    2,    0,    1,    1,    1,    1,    3,    1,
    3,    1,    3,    5,    3,    3,    5,    3,    5,    7,
   11,    3,    3,    3,    5,    5,    5,    6,    6,    4,
    4,    3,    3,    1,    1,   11,    2,    1,    5,    5,
    3,    3,    2,    7,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    0,    5,    6,    7,    8,   10,    0,
    0,    0,    0,    0,    0,    0,    1,    3,    0,    0,
   11,    9,    0,    0,    0,    0,    0,   38,    0,    0,
    0,    0,    0,   15,    0,   30,    0,   31,    0,    0,
   37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,   14,   17,    0,
    0,   28,   29,    0,    0,    0,    0,    0,    0,   32,
   33,   25,   26,   27,    0,    0,    0,   44,    0,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   21,   39,   40,   36,
};
static const short yydgoto[] = {                          2,
   12,   13,   14,   15,   16,   17,   18,   19,   21,   36,
   59,   39,   87,
};
static const short yysindex[] = {                      -244,
 -245,    0,  -20,  -17,  -94, -217, -225,  -61,    1,    3,
   13,  -69,    0, -217,    0,    0,    0,    0,    0,  -22,
    6,    7, -211, -192, -234, -192,    0,    0, -241, -225,
    0,    0,  -56,  -55, -197,   28, -225,    0,   11,   30,
   29,   31,   32,    0, -209,    0, -209,    0, -215,  -51,
    0, -192,  -49, -225, -225, -225, -190, -189,   20,   21,
 -185, -184, -183, -217,   26, -217,    0,    0,    0, -209,
 -209,    0,    0, -192, -192, -192,  -39, -171,  -36,    0,
    0,    0,    0,    0, -174,  -60,   50,    0,  -30,    0,
 -196,  -29, -217, -175, -172, -217,  -28, -209, -209,  -25,
    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  -24,    0,    0,    0,    0,
    0,    0,    0,  -24,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,   40,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -33,  -32,    0,    0,
  -31,  -27,  -26,  -24,    0,  -24,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -123,    0,    0,    0,    0,    0,
    0,    0,  -24,   62,   63,  -24,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   -9,    0,    0,    0,    0,    0,    0,  -19,  -14,
  -40,    0,    0,
};
#define YYTABLESIZE 212
static const short yytable[] = {                         23,
   91,   20,   46,   48,   28,   38,   60,   34,   35,   22,
   44,   40,    1,   23,   24,    3,   41,   51,   42,    4,
   43,   30,   37,    5,   20,   34,   35,   22,    6,   80,
   81,   23,   24,   20,   67,   68,   69,   65,   29,    7,
   24,    8,   25,   61,   62,    9,   63,   33,   34,   57,
   58,   10,   26,   11,   77,   27,   79,  102,  103,   82,
   83,   84,   94,   95,   31,   32,   35,   49,   50,   52,
   53,   64,   54,   66,   55,   56,   70,   71,   72,   73,
   74,   75,   76,   97,   78,   85,  100,   86,   88,   89,
   92,   98,   93,   96,   99,   12,  101,   18,   13,  104,
    4,   16,   41,   42,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   20,    0,   20,    0,    0,    0,   20,
    0,    0,    0,    0,    0,   20,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   22,   90,
   45,   47,
};
static const short yycheck[] = {                         61,
   61,  125,   59,   59,   14,   25,   47,   41,   41,   41,
   30,   26,  257,   41,   41,  261,  258,   37,  260,   40,
  262,   44,  257,   41,  259,   59,   59,   59,  123,   70,
   71,   59,   59,  259,   54,   55,   56,   52,   61,  257,
   40,  259,   40,  259,  260,  263,  262,  259,  260,  259,
  260,  269,   40,  271,   64,  125,   66,   98,   99,   74,
   75,   76,  259,  260,   59,   59,  259,  265,   41,   59,
   41,  123,   44,  123,   44,   44,  267,  267,   59,   59,
  266,  266,  266,   93,   59,  125,   96,  259,  125,  264,
   41,  267,  123,  123,  267,   59,  125,   59,   59,  125,
  125,   59,   41,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,   -1,  259,   -1,   -1,   -1,  263,
   -1,   -1,   -1,   -1,   -1,  269,   -1,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  270,
  267,  267,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"DTYPE","STRING","VAR","NUM","MAIN","FNUM","IF","ELSE","COMP","LOGICOP",
"ARITHOP","ASSIGNOP","FOR","UNARYOP","WHILE",
};
static const char *yyrule[] = {
"$accept : prog",
"prog : DTYPE MAIN '(' ')' '{' body '}'",
"body : stmtlist",
"stmtlist : stmt stmtlist",
"stmtlist :",
"stmt : declaration",
"stmt : if_stmt",
"stmt : arithmetic_stmt",
"stmt : for_stmt",
"stmt : VAR UNARYOP ';'",
"stmt : while_stmt",
"declaration : DTYPE var_list ';'",
"var_list : VAR",
"var_list : VAR '=' NUM",
"var_list : VAR '=' NUM ',' var_list",
"var_list : VAR ',' var_list",
"var_list : VAR '=' FNUM",
"var_list : VAR '=' FNUM ',' var_list",
"var_list : VAR '=' STRING",
"var_list : VAR '=' STRING ',' var_list",
"if_stmt : IF '(' condition ')' '{' stmtlist '}'",
"if_stmt : IF '(' condition ')' '{' stmtlist '}' ELSE '{' stmtlist '}'",
"condition : VAR COMP VAR",
"condition : VAR COMP NUM",
"condition : VAR COMP FNUM",
"condition : VAR COMP VAR LOGICOP condition",
"condition : VAR COMP NUM LOGICOP condition",
"condition : VAR COMP FNUM LOGICOP condition",
"arithmetic_stmt : VAR '=' VAR ARITHOP arithlist ';'",
"arithmetic_stmt : VAR '=' NUM ARITHOP arithlist ';'",
"arithmetic_stmt : VAR '=' VAR ';'",
"arithmetic_stmt : VAR '=' NUM ';'",
"arithlist : VAR ARITHOP arithlist",
"arithlist : NUM ARITHOP arithlist",
"arithlist : VAR",
"arithlist : NUM",
"for_stmt : FOR '(' for_declaration ';' condition ';' for_arithmetic ')' '{' stmtlist '}'",
"for_declaration : DTYPE var_list",
"for_declaration : var_list",
"for_arithmetic : VAR '=' VAR ARITHOP arithlist",
"for_arithmetic : VAR '=' NUM ARITHOP arithlist",
"for_arithmetic : VAR '=' VAR",
"for_arithmetic : VAR '=' NUM",
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
#line 69 "yacc_parser.y"

void yyerror(char * s) 
/* yacc error handler */
{    
	fprintf(stderr, "%s\n", s); 
}  
   
int main(void)  
{ 
	extern FILE *yyin, *yyout;
	yyin = fopen("data/sample.c", "r");
	return yyparse(); 
}
#line 299 "y.tab.c"

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

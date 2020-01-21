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
extern YYSTYPE yylval;

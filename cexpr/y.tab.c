/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 9 "cexpr.y"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 15 "cexpr.y"
typedef union {
  int num;
  char *string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 63 "cexpr.y"
    int yylex();
    int alphabet[26];
	void val_dump();
    void val_clear();
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
#define VAR 258
#define DUMP 259
#define CLEAR 260
#define EQUAL 261
#define ADD_EQUAL 262
#define SUB_EQUAL 263
#define MUL_EQUAL 264
#define DIV_EQUAL 265
#define REM_EQUAL 266
#define LSHIFT_EQUAL 267
#define RSHIFT_EQUAL 268
#define AND_EQUAL 269
#define XOR_EQUAL 270
#define OR_EQUAL 271
#define BIT_OR 272
#define BIT_XOR 273
#define BIT_AND 274
#define LSHIFT 275
#define RSHIFT 276
#define ADD 277
#define SUB 278
#define MUL 279
#define DIV 280
#define REM 281
#define BIT_NOT 282
#define OPEN_PAREN 283
#define CLOSE_PAREN 284
#define SEMICOLON 285
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   12,   12,   12,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    2,    2,    3,
    3,    4,    4,    5,    5,    5,    6,    6,    6,    7,
    7,    7,    7,    8,    8,    9,    9,   10,   10,   11,
   11,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    1,    3,    1,
    3,    1,    3,    1,    3,    3,    1,    3,    3,    1,
    3,    3,    3,    1,    2,    1,    2,    1,    3,    1,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,   34,   36,   38,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    5,   41,   35,   37,    0,    3,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   39,
    0,    0,    0,    0,    0,    0,    0,   31,   32,   33,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
   19,   20,
};
static const YYINT yysindex[] = {                         0,
 -257,    0, -131, -227, -213, -247, -253, -251, -170, -244,
 -152, -150, -256, -255, -266,    0,    0,    0,    0,    0,
 -249, -249, -249, -249, -249, -249, -249, -249, -249, -249,
 -249,    0,    0,    0,    0,    0, -260,    0, -251, -251,
 -251, -251, -251, -251, -251, -251, -251, -251,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -152, -150, -256, -255, -255, -266, -266,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0, -235,    0,    0,    0,    0,    0,    0, -160,
 -158, -211, -225, -186, -221,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -156, -162, -165, -179, -172, -207, -193,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  120,  144,  114,  115,  113,   33,   73,  -30,  150,  151,
    0,    0,
};
#define YYTABLESIZE 158
static const YYINT yytable[] = {                          2,
    3,    4,    5,    2,   34,    2,   34,    2,    3,    2,
   34,   39,   46,   47,   48,   68,   69,   70,   42,   43,
    6,   44,   45,   60,    7,    8,    6,   39,    6,    8,
    7,    8,    7,    8,    7,    8,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   22,   22,   22,   41,
   27,   27,   27,   27,   27,   27,   27,   32,   22,   22,
   20,   20,   27,   27,   28,   28,   28,   28,   28,   28,
   28,   33,   20,   20,   64,   65,   28,   28,   29,   29,
   29,   29,   29,   29,   29,   24,   24,   24,   24,   24,
   29,   29,   25,   25,   25,   25,   25,   24,   24,   26,
   26,   26,   26,   26,   25,   25,   23,   23,   23,   21,
   21,   26,   26,   18,   38,   19,   66,   67,   23,   23,
   40,   21,   21,   41,   17,   18,   18,   19,   19,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,
   59,   37,   61,   63,   62,   35,    0,   36,
};
static const YYINT yycheck[] = {                        257,
  258,  259,  260,  257,  258,  257,  258,  257,  258,  257,
  258,  272,  279,  280,  281,   46,   47,   48,  275,  276,
  278,  277,  278,  284,  282,  283,  278,  272,  278,  283,
  282,  283,  282,  283,  282,  283,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  272,  273,  274,  285,
  272,  273,  274,  275,  276,  277,  278,  285,  284,  285,
  272,  273,  284,  285,  272,  273,  274,  275,  276,  277,
  278,  285,  284,  285,   42,   43,  284,  285,  272,  273,
  274,  275,  276,  277,  278,  272,  273,  274,  275,  276,
  284,  285,  272,  273,  274,  275,  276,  284,  285,  272,
  273,  274,  275,  276,  284,  285,  272,  273,  274,  272,
  273,  284,  285,  272,  285,  272,   44,   45,  284,  285,
  273,  284,  285,  274,  285,  284,  285,  284,  285,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
   31,    8,   39,   41,   40,    6,   -1,    7,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 300
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUM","VAR","DUMP","CLEAR",
"EQUAL","ADD_EQUAL","SUB_EQUAL","MUL_EQUAL","DIV_EQUAL","REM_EQUAL",
"LSHIFT_EQUAL","RSHIFT_EQUAL","AND_EQUAL","XOR_EQUAL","OR_EQUAL","BIT_OR",
"BIT_XOR","BIT_AND","LSHIFT","RSHIFT","ADD","SUB","MUL","DIV","REM","BIT_NOT",
"OPEN_PAREN","CLOSE_PAREN","SEMICOLON",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : commands",
"commands :",
"commands : commands command",
"command : equal SEMICOLON",
"command : DUMP SEMICOLON",
"command : CLEAR SEMICOLON",
"equal : VAR EQUAL equal",
"equal : VAR ADD_EQUAL equal",
"equal : VAR SUB_EQUAL equal",
"equal : VAR MUL_EQUAL equal",
"equal : VAR DIV_EQUAL equal",
"equal : VAR REM_EQUAL equal",
"equal : VAR LSHIFT_EQUAL equal",
"equal : VAR RSHIFT_EQUAL equal",
"equal : VAR AND_EQUAL equal",
"equal : VAR XOR_EQUAL equal",
"equal : VAR OR_EQUAL equal",
"equal : bitwise_or",
"bitwise_or : bitwise_xor",
"bitwise_or : bitwise_or BIT_OR bitwise_xor",
"bitwise_xor : bitwise_and",
"bitwise_xor : bitwise_xor BIT_XOR bitwise_and",
"bitwise_and : shifts",
"bitwise_and : bitwise_and BIT_AND shifts",
"shifts : add_sub",
"shifts : shifts LSHIFT add_sub",
"shifts : shifts RSHIFT add_sub",
"add_sub : mul_div_rem",
"add_sub : add_sub ADD mul_div_rem",
"add_sub : add_sub SUB mul_div_rem",
"mul_div_rem : negation",
"mul_div_rem : mul_div_rem MUL negation",
"mul_div_rem : mul_div_rem DIV negation",
"mul_div_rem : mul_div_rem REM negation",
"negation : bitwise_not",
"negation : SUB bitwise_not",
"bitwise_not : parentheses",
"bitwise_not : BIT_NOT parentheses",
"parentheses : value",
"parentheses : OPEN_PAREN bitwise_or CLOSE_PAREN",
"value : NUM",
"value : VAR",

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
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 137 "cexpr.y"

int main(int argc, char **argv){
   FILE *input = stdin;
   if (yyparse())
      printf("\nInvalid expression.\n");
   else
      printf("\nCalculator off.\n");
}

void yyerror(s)
char *s;
{
    fprintf(stderr, "%s\n", s);
}

void dump_value(){
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", ('a'+i), alphabet[i]);
    }
}

void clear_value(){
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 0;
    }
}
#line 323 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

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

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
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
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
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
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 3:
#line 74 "cexpr.y"
	{ if(yystack.l_mark[-1].num != INT_MIN) {printf("%lld\n", yystack.l_mark[-1].num); } }
break;
case 4:
#line 75 "cexpr.y"
	{ dump_value(); }
break;
case 5:
#line 76 "cexpr.y"
	{ clear_value(); }
break;
case 6:
#line 79 "cexpr.y"
	{ if (yystack.l_mark[0].num <= INT_MAX && yystack.l_mark[0].num > INT_MIN) {alphabet[yystack.l_mark[-2].num] = yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = INT_MIN; } }
break;
case 7:
#line 80 "cexpr.y"
	{ if (yystack.l_mark[-2].num <= INT_MAX - yystack.l_mark[0].num) { alphabet[yystack.l_mark[-2].num] += yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = INT_MIN; } }
break;
case 8:
#line 81 "cexpr.y"
	{ if (yystack.l_mark[-2].num > INT_MIN + yystack.l_mark[0].num) { alphabet[yystack.l_mark[-2].num] -= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = INT_MIN; } }
break;
case 9:
#line 82 "cexpr.y"
	{ if(yystack.l_mark[0].num == 0) yyval.num = 0; else if (yystack.l_mark[-2].num <= INT_MAX / yystack.l_mark[0].num) {alphabet[yystack.l_mark[-2].num] *= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = INT_MIN; } }
break;
case 10:
#line 83 "cexpr.y"
	{ if (yystack.l_mark[0].num != 0) {alphabet[yystack.l_mark[-2].num] /= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("dividebyzero\n"); yyval.num = INT_MIN; } }
break;
case 11:
#line 84 "cexpr.y"
	{ if (yystack.l_mark[0].num != 0) {alphabet[yystack.l_mark[-2].num] %= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num];} else { printf("dividebyzero\n"); yyval.num = INT_MIN; } }
break;
case 12:
#line 85 "cexpr.y"
	{ alphabet[yystack.l_mark[-2].num] <<= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num]; }
break;
case 13:
#line 86 "cexpr.y"
	{ alphabet[yystack.l_mark[-2].num] >>= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num]; }
break;
case 14:
#line 87 "cexpr.y"
	{ alphabet[yystack.l_mark[-2].num] &= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num]; }
break;
case 15:
#line 88 "cexpr.y"
	{ alphabet[yystack.l_mark[-2].num] ^= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num]; }
break;
case 16:
#line 89 "cexpr.y"
	{ alphabet[yystack.l_mark[-2].num] |= yystack.l_mark[0].num; yyval.num = alphabet[yystack.l_mark[-2].num]; }
break;
case 17:
#line 90 "cexpr.y"
	{ yyval.num = yystack.l_mark[0].num; }
break;
case 19:
#line 94 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num | yystack.l_mark[0].num; }
break;
case 21:
#line 98 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num ^ yystack.l_mark[0].num; }
break;
case 23:
#line 102 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num; }
break;
case 25:
#line 106 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num << yystack.l_mark[0].num; }
break;
case 26:
#line 107 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num >> yystack.l_mark[0].num; }
break;
case 28:
#line 111 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num + yystack.l_mark[0].num; }
break;
case 29:
#line 112 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num - yystack.l_mark[0].num; }
break;
case 31:
#line 116 "cexpr.y"
	{ if(yystack.l_mark[0].num == 0) yyval.num = yystack.l_mark[-2].num * yystack.l_mark[0].num; else if (yystack.l_mark[-2].num <= INT_MAX / yystack.l_mark[0].num) yyval.num = yystack.l_mark[-2].num * yystack.l_mark[0].num; else { printf("overflow\n"); yyval.num = INT_MIN; }}
break;
case 32:
#line 117 "cexpr.y"
	{ if (yystack.l_mark[0].num != 0) yyval.num = yystack.l_mark[-2].num / yystack.l_mark[0].num; else { printf("dividebyzero\n"); yyval.num = INT_MIN; }}
break;
case 33:
#line 118 "cexpr.y"
	{ if (yystack.l_mark[0].num != 0) yyval.num = yystack.l_mark[-2].num % yystack.l_mark[0].num; else { printf("dividebyzero\n"); yyval.num = INT_MIN; }}
break;
case 35:
#line 122 "cexpr.y"
	{ yyval.num = - yystack.l_mark[0].num; }
break;
case 37:
#line 126 "cexpr.y"
	{ yyval.num = ~ yystack.l_mark[0].num; }
break;
case 39:
#line 130 "cexpr.y"
	{ yyval.num = yystack.l_mark[-1].num; }
break;
case 40:
#line 133 "cexpr.y"
	{ yyval.num = yystack.l_mark[0].num; }
break;
case 41:
#line 134 "cexpr.y"
	{ yyval.num = alphabet[yystack.l_mark[0].num]; }
break;
#line 642 "y.tab.c"
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
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

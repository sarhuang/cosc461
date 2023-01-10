/* Name: Sarah Huang
 * Course: COSC 461
 * Program: scan.l
 * Purpose: Define language of the cexpr.y program
			Tokens include integer numbers, 26 predefined integer variables, and many operators.
 */


%{
#include "y.tab.h"
%}

%{
    void yyerror(char *);
%}

%%
[0-9]+  { sscanf(yytext, "%d", &yylval.num);
          return NUM; }

[a-z]  { yylval.num = *yytext - 'a';
          return VAR; }

"dump"  { yylval.string=strdup(yytext);
          return DUMP; }

"clear" { yylval.string=strdup(yytext);
		  return CLEAR; }

"="    	{ return  EQUAL; }
"+="   	{ return  ADD_EQUAL; }
"-="    { return  SUB_EQUAL; }
"*="    { return  MUL_EQUAL; }
"/="    { return  DIV_EQUAL; }
"%="    { return  REM_EQUAL; }
"<<="   { return  LSHIFT_EQUAL; }
">>="   { return  RSHIFT_EQUAL; }
"&="    { return  AND_EQUAL; }
"^="    { return  XOR_EQUAL; }
"|="    { return  OR_EQUAL; }
"|"     { return  BIT_OR; }
"^"     { return  BIT_XOR; }
"&"     { return  BIT_AND; }
"<<"    { return  LSHIFT; }
">>"    { return  RSHIFT; }
"+"     { return  ADD; }
"-"     { return  SUB; }
"*"     { return  MUL; }
"/"     { return  DIV; }
"%"     { return  REM; }
"~"     { return  BIT_NOT; }
"("     { return  OPEN_PAREN; }
")"     { return  CLOSE_PAREN; }
";"     { return  SEMICOLON; }

[ /t]+  {}
.       { return yytext[0]; }

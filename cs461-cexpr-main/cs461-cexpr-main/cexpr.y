/* Name: Sarah Huang
 * Course: COSC 461
 * Program: cexpr.y
 * Purpose: Implement a calculator of C integer expressions.
			The calculator will process expressions until it encounters EOF or invalid syntax. 
 */

%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
%}

%union {
  int num;
  char *string;
}

%token <num> NUM
%token <num> VAR
%token <string> DUMP
%token <string> CLEAR
%token <num> EQUAL
%token <num> ADD_EQUAL
%token <num> SUB_EQUAL
%token <num> MUL_EQUAL
%token <num> DIV_EQUAL
%token <num> REM_EQUAL
%token <num> LSHIFT_EQUAL
%token <num> RSHIFT_EQUAL
%token <num> AND_EQUAL
%token <num> XOR_EQUAL
%token <num> OR_EQUAL
%token <num> BIT_OR
%token <num> BIT_XOR
%token <num> BIT_AND
%token <num> LSHIFT
%token <num> RSHIFT
%token <num> ADD
%token <num> SUB
%token <num> MUL
%token <num> DIV
%token <num> REM
%token <num> BIT_NOT
%token <num> OPEN_PAREN
%token <num> CLOSE_PAREN
%token <num> SEMICOLON

%type <num> equal
%type <num> bitwise_or
%type <num> bitwise_xor
%type <num> bitwise_and
%type <num> shifts
%type <num> add_sub
%type <num> mul_div_rem
%type <num> negation
%type <num> bitwise_not
%type <num> parentheses
%type <num> value

%{
    int yylex();
    int alphabet[26];
	void val_dump();
    void val_clear();
%}

%%
commands:
		| commands command
		;

command: equal SEMICOLON  	{ if($1 != INT_MIN) {printf("%lld\n", $1); } }
       | DUMP SEMICOLON     { dump_value(); }
       | CLEAR SEMICOLON    { clear_value(); }
	   ;

equal: VAR EQUAL equal  	   { if ($3 <= INT_MAX && $3 > INT_MIN) {alphabet[$1] = $3; $$ = alphabet[$1];} else { printf("overflow\n"); $$ = INT_MIN; } }
     | VAR ADD_EQUAL equal     { if ($1 <= INT_MAX - $3) { alphabet[$1] += $3; $$ = alphabet[$1];} else { printf("overflow\n"); $$ = INT_MIN; } }
     | VAR SUB_EQUAL equal     { if ($1 > INT_MIN + $3) { alphabet[$1] -= $3; $$ = alphabet[$1];} else { printf("overflow\n"); $$ = INT_MIN; } }  
	 | VAR MUL_EQUAL equal     { if($3 == 0) $$ = 0; else if ($1 <= INT_MAX / $3) {alphabet[$1] *= $3; $$ = alphabet[$1];} else { printf("overflow\n"); $$ = INT_MIN; } }
	 | VAR DIV_EQUAL equal	   { if ($3 != 0) {alphabet[$1] /= $3; $$ = alphabet[$1];} else { printf("dividebyzero\n"); $$ = INT_MIN; } }
     | VAR REM_EQUAL equal     { if ($3 != 0) {alphabet[$1] %= $3; $$ = alphabet[$1];} else { printf("dividebyzero\n"); $$ = INT_MIN; } }
     | VAR LSHIFT_EQUAL equal  { alphabet[$1] <<= $3; $$ = alphabet[$1]; }
     | VAR RSHIFT_EQUAL equal  { alphabet[$1] >>= $3; $$ = alphabet[$1]; }
     | VAR AND_EQUAL equal     { alphabet[$1] &= $3; $$ = alphabet[$1]; }
     | VAR XOR_EQUAL equal     { alphabet[$1] ^= $3; $$ = alphabet[$1]; }
	 | VAR OR_EQUAL equal	   { alphabet[$1] |= $3; $$ = alphabet[$1]; }
     | bitwise_or              { $$ = $1; }
     ;

bitwise_or: bitwise_xor
    	  | bitwise_or BIT_OR bitwise_xor	{ $$ = $1 | $3; }
    	  ;

bitwise_xor: bitwise_and
    	   | bitwise_xor BIT_XOR bitwise_and	{ $$ = $1 ^ $3; }
    	   ;

bitwise_and: shifts
    	   | bitwise_and BIT_AND shifts  { $$ = $1; }
    	   ;

shifts:	add_sub
      | shifts LSHIFT add_sub 	{ $$ = $1 << $3; }
      | shifts RSHIFT add_sub 	{ $$ = $1 >> $3; }
      ;

add_sub: mul_div_rem
       | add_sub ADD mul_div_rem	{ $$ = $1 + $3; }
       | add_sub SUB mul_div_rem 	{ $$ = $1 - $3; }
       ;

mul_div_rem: negation
    	   | mul_div_rem MUL negation 	{ if($3 == 0) $$ = $1 * $3; else if ($1 <= INT_MAX / $3) $$ = $1 * $3; else { printf("overflow\n"); $$ = INT_MIN; }}
    	   | mul_div_rem DIV negation 	{ if ($3 != 0) $$ = $1 / $3; else { printf("dividebyzero\n"); $$ = INT_MIN; }}
    	   | mul_div_rem REM negation 	{ if ($3 != 0) $$ = $1 % $3; else { printf("dividebyzero\n"); $$ = INT_MIN; }} 
    	   ;

negation: bitwise_not
    	| SUB bitwise_not	{ $$ = - $2; }
	    ;

bitwise_not: parentheses
    	   | BIT_NOT parentheses	{ $$ = ~ $2; }
    	   ;

parentheses: value
    	   | OPEN_PAREN bitwise_or CLOSE_PAREN	{ $$ = $2; }
    	   ;

value: NUM  { $$ = $1; }
     | VAR	{ $$ = alphabet[$1]; }
     ;
%%

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

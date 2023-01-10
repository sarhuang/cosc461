# cexpr

## How to cexpr
./cexpr

From input.txt
- a = 55-3;
- b = c = a-42;
- a+b*c;
- dump;
- clear;
- c = 6;
- a = b;
- a = 10000;
- b = 100000;
- a*b;
- a*b*10;
- c/d;
- d/c;

## More about cexpr

1. The problem I attempted to solve is to make a scanner and parser using lex and yacc
respectively for a calculator based on C integer expressions. It also supports 26 integer
variables named after each letter of the alphabet. Expressions include basic arithmetic,
parentheses, bitwise operations, shifts, negation, and assignment.


2. First, I took a look at the provided example files ex.l and ex.y. I was still not familiar with
yaac grammar rules and the lex token defining process, so I referred to these examples
and did outside research on the syntax. For scan.l, I thought it would be helpful if I
labeled every supported operation so I knew to only use these characters in cexpr.y


3. To check the program, I tested the example input text file and any expressions I could
think of including divide by zero and integer overflow errors. I made sure to use
ref_cexpr to verify all my outputs.


4. I was not familiar with lex and yacc, so I did prior research and looked at simpler lex and
yacc calculators that only did basic arithmetic. I wish the errors messages were more
helpful instead of “invalid expression” because it made it harder to identify where the
problem was. Additionally, being unable to use yaac’s built-in precedence %left and
%right tags were a little annoying.

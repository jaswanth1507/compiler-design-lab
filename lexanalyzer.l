{
#include <stdio.h>
%}

DIGIT       [0-9]
WS          [ \t\n]
PLUS        "+"
MINUS       "-"
TIMES       "*"
DIVIDE      "/"
LPAREN      "("
RPAREN      ")"
OP          {PLUS}|{MINUS}|{TIMES}|{DIVIDE}
NUM         {DIGIT}+(\.{DIGIT}+)?
WS          {WS}+

%%

{NUM}       { printf("NUMBER: %s\n", yytext); }
{OP}        { printf("OPERATOR: %s\n", yytext); }
{LPAREN}    { printf("LEFT PARENTHESIS\n"); }
{RPAREN}    { printf("RIGHT PARENTHESIS\n"); }
{WS}        ;  // Skip whitespace

.           { printf("ERROR: Invalid character: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}


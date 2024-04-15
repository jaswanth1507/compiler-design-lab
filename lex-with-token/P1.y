%{
    #include<stdio.h>  
    #include<string.h> 
    int yydebug;
    extern int yylex();
    extern int yyerror();
    
%}
%union{
char* str;    
}

%token<str> NOT 
%token<str> CURLY_OPEN 
%token<str> CURLY_CLOSE
%token<str> PAR_OPEN
%token<str> PAR_CLOSE
%token<str> SQR_CLOSE
%token<str> IF
%token<str> WHILE 
%token<str> CLASS
%token<str> PUBLIC
%token<str> STATIC
%token<str> VOID
%token<str> MAIN 
%token<str> STR
%token<str> PRINTLN
%token<str> EXTENDS
%token<str> THIS
%token<str> NEW
%token<str> SEMI_COLON
%token<str> COMMA
%token<str> LENGTH
%token<str> TRUE
%token<str> FALSE 
%token<str> NUMBER 
%token<str> RET
%token<str> BOOL INT IDENTIFIER ADD SUB MUL DIV MOD AND LEQ NEQ SQR_OPEN DOT ASSIGNMENT ELSE 

%nonassoc ELSE 
%left BOOL INT IDENTIFIER
%left ADD SUB MUL DIV MOD AND LEQ  NEQ SQR_OPEN DOT
%right ASSIGNMENT

%%
/* YOUR CODE HERE; after writing the grammar rules above */
%%
main (int argc, char **argv) {
 yyparse();
 
}

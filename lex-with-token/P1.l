%{
#include "P1.tab.h"   
#include<stdio.h>
#include<stdlib.h>
%}

%%
"//".*[\n]              {}
"="                     {return ASSIGNMENT;}
"+"                     {return ADD;}
"-"                     {return SUB;}
"*"                     {return MUL;}
"/"                     {return DIV;}
"%"                     {return MOD;}
"&&"                    {return AND;}
"<="                    {return LEQ;}
"{"                     {return CURLY_OPEN;}
"}"                     {return CURLY_CLOSE;}
"("                     {return PAR_OPEN;}
")"                     {return PAR_CLOSE;}
"["                     {return SQR_OPEN;}
"]"                     {return SQR_CLOSE;}
"if"                    {return IF;} 
"else"                  {return ELSE;}
"while"                 {return WHILE;}
"class"                 {return CLASS;}
"int"               	{return INT;}
"boolean"               {return BOOL;}
"public"                {return PUBLIC;}
"static"                {return STATIC;}
"void"		        {return VOID;}
"main"                  {return MAIN;}
"String"                {return STR;}
"System.out.println"    {return PRINTLN;}
"extends"               {return EXTENDS;}
"this"                  {return THIS;}
"new"                   {return NEW;}
";"                     {return SEMI_COLON;}
","                     {return COMMA;}
"."                     {return DOT;}
"length"                {return LENGTH;}
"true"                  {return TRUE;}
"false"                 {return FALSE;}
"!"                     {return NOT;}
"!="                    {return NEQ;}
"return"                {return RET;}
[0-9]+                  {return NUMBER;}
[_$]?[a-zA-Z][0-9a-zA-Z_$]* {return IDENTIFIER;}
[ \n\t\r]+              {} 
.                       {printf("Invalid token: *%s*\n",yytext);}
%%


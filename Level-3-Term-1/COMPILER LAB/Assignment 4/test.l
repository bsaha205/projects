%{
#include<stdio.h>
#include<stdlib.h>

#include "y.tab.h"	//generated via test -d
%}

%option noyywrap 

PROC "proc"
ID   [[:alpha:]_][[:alnum:]_]*
INTEGER "int"
REAL	"real"
END		"end"
START	"start"


%%
[ \t\n]+ 	{}

{REAL}	{return REAL;}
";" {return *yytext;}
":" {return *yytext;}
"=" {return *yytext;}
{INTEGER}	{return INTEGER;}
{PROC}	{return PROC;}
{START}	{return START;}
{END} 	{return END;}
{ID}	{return ID;}
%%
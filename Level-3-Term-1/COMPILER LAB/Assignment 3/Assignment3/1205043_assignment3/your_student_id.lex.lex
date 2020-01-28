%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include "y.tab.h"
using namespace std;

int yyerror(char*);
simple s;
%}



INCLUDE	#include<[a-z]+\.h>


%%
[ \t\n]+ 	{}

{INCLUDE}	{
		s.ch=yytext;
		yylval=&s;
		return INCLUDE;
	}
. 	{
		return DOT;
	}






%%

int yywrap()
{
return -1;
}

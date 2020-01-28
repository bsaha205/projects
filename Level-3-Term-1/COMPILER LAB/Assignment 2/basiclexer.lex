%{
#include <stdlib.h>
%}

%option noyywrap

INT	    int
IF	    if
THEN	    then
ELSE	    else
ID          [[:alpha:]_][[:alnum:]_]*
NUM         [[:digit:]]+(\.[[:digit:]]+)?
PM	    [+-]
MD	    [*/]
ASSGN	    =
LOGEQ	    ==
WS          [ \t\n]+


%%
{INT}       printf("<INT>\n");
{IF}        printf("<IF>\n");
{THEN}      printf("<THEN>\n");
{ELSE}      printf("<ELSE>\n");
{PM}        printf("<PM>\n");
{MD}        printf("<MD>\n");
{ASSGN}     printf("<ASSGN>\n");
{LOGEQ}     printf("<LOGEQ>\n");

{ID}        printf("<ID, %s>\n", yytext);

{NUM}       printf("<NUM, %s>\n", yytext);

{WS}        // Eat up white space

.           printf("Error: unrecognized character %s\n", yytext); 

%%

int main()
{
  /* You need this line if you are using g++ */
  // yyFlexLexer lexer;

  printf("Starting lexical analysis\n");

  /* For C */
  yylex();

  /* For C++ */
  // lexer.yylex();

  printf("Finished lexical analysis\n");

}

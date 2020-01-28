%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double      /* yyparse() stack type */
  extern FILE * yyin;
  extern FILE * yyout;
int yyparse(void);
int yylex(void);
void yyerror(char *s)
{
	fprintf(stdout,"Found an ERROR-> %s\n",s);
	return;
}
%}

%token NEWLINE NUMBER PLUS MINUS SLASH ASTERISK LPAREN RPAREN


%%
input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { printf("\t%.10g\n",$1); }
    ;
expr: expr PLUS term         { $$ = $1 + $3; printf("%g = %g + %g\n",$$,$1,$3);}
    | expr MINUS term        { $$ = $1 - $3; printf("%g = %g - %g\n",$$,$1,$3); }
    | term		{ $$ = $1; }
    ;
term: term ASTERISK factor   { $$ = $1 * $3; }
    | term SLASH factor      { $$ = $1 / $3; }
    | factor		{ $$ = $1; printf("factor is %g\n",$1); }
    ;
factor:  LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER			{ $$ = $1; printf("number is %g\n",$1); }
      ;
%%

main()
{
  yyparse();
  exit(0);
}

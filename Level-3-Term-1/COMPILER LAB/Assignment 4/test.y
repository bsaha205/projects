%{
#include<stdio.h>
#include<stdlib.h>

extern int yylex();
void yyerror(char *msg);

%}

%expect 2

%token  PROC ID INTEGER REAL START END


%%
P	:	{printf("Create global table, push tblptr and offset, etc.\n\n");} D 
	;
	
D	: ID ':' T  			{printf("Enter id to the last table\nIncrement offset according to width, etc\n");}
	; 
	
	
D	: PROC ID ';' {printf("\nCreate local table for procedure, push tblptr and offset, etc.\n");} D START S END {printf("Enter PROC info into global, pop, etc.\n\n");}
	;
	
D	: D ';' D
	|
	;

T	: INTEGER 			{printf("Get Int, size\n");}
	| REAL 				{printf("Get Real, size\n");;}
	;	


S 	: ID '=' ID {printf("Lookup id and check error, etc\n");}
	; 


S 	: S ';' S
	| 
	;

%%


void yyerror(char *msg){
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(){
	yyparse();
	
	//Show the symbol table

	return 0;
}

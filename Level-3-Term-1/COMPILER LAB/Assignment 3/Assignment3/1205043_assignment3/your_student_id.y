%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <iostream>
using namespace std;
#define YYSTYPE simple*      /* yyparse() stack type */
int yyparse(void);
int yylex(void);

extern FILE *yyin, *yyout;
char* temp;
FILE * fp1,*fp2,*fp3;
void yyerror(char *s)
{
	fprintf(stdout,"At Line %d, ERROR-> %s\n",10+1,s);
	return;
}
%}


%token  INCLUDE DOT


%%
PROGRAM:
	PRELI MAIN	{printf("Found all\n");}		
	;

PRELI:
	PRELI INCLUDE	{printf("Include statement found\n");
				size_t length = strlen($2->ch);
				temp = new char[length + 1];
				strcpy(temp, $2->ch);
				cout<<"  "<<temp<<"\n";
				fprintf(fp2,"Include statement found\n");
			}		
	| 						
	;
MAIN:	MAIN DOT		
	|
	;
%%

int main(void){
	fp1=fopen("your_student_id_input.txt","r");	fp2=fopen("your_student_id_output.txt","w+");
	yyin=fp1;yyout=fp2;
	printf("START\n");
	yyparse();
	printf("END\n");
	//fprintf(fp3,"Input file contains %d lines in total",ln);
	fclose(fp1);fclose(fp2);
	return 0;
}

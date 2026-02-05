%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex();
void yyerror(const char*);

bool accept = false;
%}

%token TOK_A
%token TOK_B

%%
 expr: TOK_A expr TOK_B          { }
     | TOK_A TOK_B               {accept = true;}
%%

int main(){
    printf("=>");
    yyparse();
    if(accept)
        printf("valid string\n");
    return 0;
}

void yyerror(const char*){
    printf("invalid expr\n");
    accept=false;
}
%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex();
void yyerror(const char*);

bool accept = false;
%}

%token TOK_OPEN
%token TOK_CLOSE
%token TOK_OTHER

%%
expr : TOK_OPEN expr TOK_CLOSE expr   { }
     | TOK_OTHER expr                 {accept = true;}
     |                                {accept= true;}
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
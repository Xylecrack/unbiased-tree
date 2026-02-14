%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex();
void yyerror(const char*);

bool accept = false;
%}
%token ZERO
%%
    start: even                         {accept=true;}
         ;

    even: even ZERO ZERO
        |
        ;
%%

int main(){
    printf("=>");
    yyparse();
    if(accept){
        printf("valid expr\n");
    }
}

void yyerror(const char*){
    printf("invalid expr\n");

}

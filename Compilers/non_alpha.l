%option noyywrap
%{
#include <stdio.h>
int found = 0;
%}

%%
[^a-zA-Z\n] {
    found = 1;
    printf("Non-alphabet character found: %s\n", yytext);
}
[a-zA-Z\n]  { }
%%

int main() {
    yylex();
    if(!found)
        printf("Only alphabets found\n");
    return 0;
}

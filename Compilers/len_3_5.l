%option noyywrap
%{
#include <stdio.h>
%}

%%

[a-zA-Z]{6,}    ;
[a-zA-Z]{3,5}   { printf("Found: %s\n", yytext); }
.|\n            ;

%%

int main() {
    yylex();
    return 0;
}
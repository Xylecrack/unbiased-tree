%option noyywrap
%{
#include <stdio.h>
int words=0, chars=0, lines=0;
%}

%%
\n          { lines++; chars++; }
[ \t]+      { chars += yyleng; }
[^ \t\n]+   { words++; chars += yyleng; }
%%

int main() {
    yylex();
    printf("Words: %d\nCharacters: %d\nLines: %d\n",
           words, chars, lines);
    return 0;
}

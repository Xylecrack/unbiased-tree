%option noyywrap
%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]              { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonants++; }
.|\n                      { }
%%

int main() {
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}

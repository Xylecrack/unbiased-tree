%option noyywrap
%{
#include <stdio.h>
int pos_int=0, neg_int=0, pos_frac=0, neg_frac=0;
%}

%%
\+[0-9]+              { pos_int++; }
-[0-9]+               { neg_int++; }
\+[0-9]*\.[0-9]+      { pos_frac++; }
-[0-9]*\.[0-9]+       { neg_frac++; }
.|\n                  { }
%%

int main() {
    yylex();
    printf("+integers: %d\n-integers: %d\n+fractions: %d\n-fractions: %d\n",
           pos_int, neg_int, pos_frac, neg_frac);
    return 0;
}

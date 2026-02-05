%{
#include "palindrome.tab.h"
%}

%%
a       { return TOK_A; }
b       { return TOK_B; }
\n      { return 0;     }

%%

int yywrap() {
    return 1;
}
%{
#include "paranthesis.tab.h"
%}

%%
[(]       { return TOK_OPEN; }
[)]       { return TOK_CLOSE;}
\n        { return 0;        }
.         { return TOK_OTHER;}
%%

int yywrap() {
    return 1;
}
%{
#include "evenZero.tab.h"
%}

%%

0        { return ZERO; }
\n       { return 0; }
.        { }

%%

int yywrap() {
    return 1;
}

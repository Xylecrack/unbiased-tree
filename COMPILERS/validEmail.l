%option noyywrap
%{
    #include <stdio.h>
    int accept = 0;
%}

%%
^[A-Za-z0-9]+@[A-Za-z0-9]+\.[A-Za-z]+$   { accept = 1; }
.|\n                                     { }
%%

int main(){
    yylex();
    if(accept)
        printf("Valid email\n");
    else
        printf("Invalid email\n");
}



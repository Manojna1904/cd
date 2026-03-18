%{
#include<stdio.h>
int count=0;
%}

%%
[0-9]+ { printf("%s\n", yytext); count++; }
.|\n   ;
%%

int main() {
    yyin = fopen("input.txt","r");
    yylex();

    printf("Total Numbers: %d\n", count);
    return 0;
}

int yywrap() {
    return 1;
}

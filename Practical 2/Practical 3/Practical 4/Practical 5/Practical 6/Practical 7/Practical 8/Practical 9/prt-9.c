%{
#include<stdio.h>
int lines=0, words=0, chars=0;
%}

%%
\n      { lines++; words++; }
[ \t]+  { words++; }
.       { chars++; }
%%

int main() {
    yyin = fopen("input.txt","r");
    yylex();

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    return 0;
}

int yywrap() {
    return 1;
}

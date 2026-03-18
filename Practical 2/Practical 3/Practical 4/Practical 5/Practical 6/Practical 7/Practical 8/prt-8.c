%{
#include "y.tab.h"
%}

%%
"hi"    { return HI; }
"bye"   { return BYE; }
\n      ;
.       ;
%%

int yywrap() {
    return 1;
}

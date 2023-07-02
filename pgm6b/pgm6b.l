%{
#include "y.tab.h"
%}

%%
[ \t];
[+*\-/] {printf("operator is %s\n",yytext);return OP;}
int|char|bool|float|void|for|do|while|if|else|return|void {printf("keyword is %s\n",yytext);return KEY;}
[a-zA-Z_][a-zA-Z0-9_]* {printf("identifier is %s\n",yytext);return ID;}
. ;
%%
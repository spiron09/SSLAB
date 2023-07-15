%{
#include"y.tab.h"
%}
%%
a	{return A;}          /*For recognizing the character a*/
b	{return B;}           /*For recognizing the character b*/
.	{return yytext[0];}
\n {return yytext[0];}
%%

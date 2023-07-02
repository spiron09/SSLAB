%{
#include <stdio.h>
%}

%token ID KEY OP

%%
D : ID D
| KEY D
| OP D
| ID
| KEY
| OP
;
%%

extern FILE *yyin;



void main()
{
 yyin = fopen("A.c", "r");
 yyparse();
 fclose(yyin);
}

void yyerror()
{
 printf("error");
 return 0;
}
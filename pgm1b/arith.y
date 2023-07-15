%{
#include <stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S: E '\n' {printf("value = %d", $1);}
E: E '+' E {$$ = $1 + $3;}
 | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;}
 | E '/' E {if($3==0) printf("Div by 0");
            else $$ = $1 * $3;}
 | '(' E ')' {$$ = $2;}
 | NUM {$$ = $1;}
%%

void yyerror(){
    printf("Invalid!");
}

void main(){
    printf("Enter exp!");
    yyparse();
    return 0;
}

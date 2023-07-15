%{
#include<stdio.h>
int opr_cnt = 0, opnd_cnt = 0, brac_cnt = 0;    
%}
%%
[0-9]+ {opnd_cnt++;}
[+\-*/] {opr_cnt++;}
[(] {brac_cnt++;}
[)] {brac_cnt--;}
%%
int main(){
    printf("Enter expression!\n");
    yylex();
    if(brac_cnt!=0 || opr_cnt>=opnd_cnt || opnd_cnt == 1)
        printf("Invalid");
    else
        printf("Valid");

    return 0;
}

void yyerror(){
    printf("Invalid Expression");
    return 0;
}

int yywrap(){return(1);}
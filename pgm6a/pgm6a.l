%{
%}

%%
"//".* {fprintf(yyout, "");}
"/*"([^*]|"*"+[^*/])*"*"+"/" {fprintf(yyout, "");}
. {fprintf(yyout, "%s", yytext);}
%%

int main(){
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
}

int yywrap(){return(1);}


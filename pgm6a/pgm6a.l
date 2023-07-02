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

-----------------OR---------------------

%{
%}

%%
"//".* {fprintf(yyout, "");}

"/*"(.*|\n).*"*/" {fprintf(yyout, "");}

. {fprintf(yyout, "%s", yytext);}
%%

int main(){
    yyin = fopen('input.c', "r");
    yyout = fopen("output.c", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

int yywrap(){return(1);}
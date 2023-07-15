%token A B                    /*tokens declaration*/
%%
str: s'\n'	{return 0;}              /*Productions for recognizing the grammar*/
s : x B ;
x : x A
| ;
%%
int main()
{
printf("Type the string\n");
yyparse();
printf("Valid string");
}

int yyerror()
{
printf("Invalid string");
exit(0);
}

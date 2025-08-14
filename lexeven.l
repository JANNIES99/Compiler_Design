EVEN [1-9]*[24680]
ODD [1-9]*[13579]
%%
{EVEN}+ {printf("%s is even\n",yytext);}
{ODD}+ {printf("%s is odd\n",yytext);}
%%
void main()
{
printf("Enter a number:");
yylex();
}

int yywrap(){
return (0);
}

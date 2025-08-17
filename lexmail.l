VALID [a-z|0-9]*@[a-z|0-9]*.[a-z|0-9|.]*
NOTVALID [a-z|0-9|A-Z|.|@|!|?|*|(|)|%|$|#|^|_|-|+|{|}|[|]|>|<]*
%%
{VALID}+ {printf("%s is valid\n",yytext);}
[a-z0-9A-Z.@]* {printf("%s is not valid\n",yytext);}
%%
void main()
{
printf("Enter a email:");
yylex();
}

int yywrap(){
return (0);
}

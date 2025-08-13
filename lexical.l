DIGIT [0-9]
ID [_a-zA-Z][a-zA-Z0-9]*
KEYWORD "if"|"else"|"while"|"int"
OP ">"|"<"|"="|">="|"<="|"+"|"-"|"*"|"/"
SPECIALCHARACTER "'"|":"|";"|","|"("|")"
%%
{KEYWORD}+ {printf("%s is a keyword\n",yytext);}
{DIGIT}+ {printf("%s is a integer\n",yytext);}
[_a-zA-Z][a-zA-Z0-9]* {printf("%s is a identifier\n",yytext);}
{OP}+ {printf("%s is a operater\n",yytext);}
{SPECIALCHARACTER}+ {printf("%s is a SPECIALCHARACTER\n",yytext);}
%%

void main()
{
printf("Enter a string\n");
yylex();
}
int yywrap()
{
return(1);
}

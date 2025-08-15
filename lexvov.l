%{
	int vocount=0;
	int cocount=0;
%}
VOWEL[aeiouAEIOU]
CONSONANT[a-zA-Z]
%%
{VOWEL}+ {vocount++;}
[a-zA-Z] {cocount++;}
%%
void main()
{
	printf("Enter a string");
	yylex();
	printf("Vowel count:%d\n",vocount);
	printf("Consonant count:%d\n",cocount);
}

int yywrap()
{
 
}

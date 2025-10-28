%{
#include<stdio.h>
#include<stdlib.h>

void yyerror(char *s);
%}

%token EXPR
%token NOT

%%
input:
	EXPR {printf("Valid Expression");}
	| NOT {printf("Not a valid expression");}
	;
%%

int main() {
    printf("Enter variable identifier: ");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    printf("Parsing error: %s\n", s);
}

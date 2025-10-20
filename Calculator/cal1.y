%{
#include<stdio.h>
#include<stdlib.h>
 void yyerror(char *s);
%}

%token INTEGER

%left '+' '-'
%left '*' '/'

%%
program:
	program expr '\n' {printf("=%d\n",$2)}
	|
	;
expr:
	INTEGER {$$=$1;}
	| expr + expr {$$ = $1+$3;}
	| expr - expr {$$ = $1-$3;}
	| expr * expr {$$ = $1*$3;}
	| expr / expr {$$ = $1/$3;}
	;
%%
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter expressions. Press Ctrl+D (or Ctrl+Z on Windows) to exit.\n");
    yyparse();
    return 0;
}

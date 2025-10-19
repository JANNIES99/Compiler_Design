#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *input;

void error() {
	printf("Parsing Error!\n");
	exit(1);
}

void match(char s){
	if(*input == s){
		input++;
	}
	else{
		error();	
	}
}

void E();
void E_prime();
void T();
void T_prime();
void F();

void main(){
	char s[200];
	printf("Enter the expression:");
	scanf("%s",s);
	input=s;
	E();
	if(*input=='\n' || *input=='\0'){
		printf("Parsing successfull\n");
	}
	else{
		printf("Parsing failed\n");	
	}
	
}
void E(){
	T();
	E_prime();
}

void E_prime(){
	if(*input=='+'){
		match('+');
		T();
		E_prime();
	}
}

void T(){
	F();
	T_prime();
}

void T_prime(){
	if(*input=='*'){
		match('*');
		F();
		T_prime();
	}
}

void F(){
	if(*input == '('){
		match('(');
		E();
		match(')');
	}
	else if(isalpha(*input)){
		match(*input);
	}
	else{
		error();
	}
}




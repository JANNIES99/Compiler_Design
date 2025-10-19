#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sptr;

char str_input[100],stack[100];

void reduce(){
	char temp[100];
	int ptr=strlen(stack)-1;
	temp[0]=stack[ptr];
	temp[1]='\0';
	if(!strcmp(temp,"a") || !strcmp(temp,"b") ){
		stack[ptr]='E';
		printf("$%s\t\t%s$\t\treduce %s\n",stack,str_input,temp);
	}
	if(ptr>1){
		temp[0]=stack[ptr-2];
		temp[1]=stack[ptr-1];
		temp[2]=stack[ptr];
		temp[3]='\0';
		if(!strcmp(temp,"E+E")|| !strcmp(temp,"E*E") || !strcmp(temp,"E/E") ){
			stack[ptr-2]='E';
			stack[ptr-1]='\0';
			printf("$%s\t\t%s$\t\treduce %s\n",stack,str_input,temp);
		}
	}
	
}

void main(){
	char temp[100];
	printf("Enter a input string:");
	scanf("%s",str_input);
	printf("Stack\t\tInputString\t\tAction\n");
	printf("$\t\t%s$\t\t--\n",str_input);
	int len=strlen(str_input);
	for(int i=0;i<len;i++){
		temp[0]=str_input[0];
		temp[1]='\0';
		strcat(stack,temp);
		memmove(str_input,str_input+1,strlen(str_input));
		printf("$%s\t\t%s$\t\tshift %s\n",stack,str_input,temp);
		reduce();
	}
	reduce();
	if(!strcmp(stack,"E")){
		printf("Successfully parsed\n");
	}
	else{
		printf("parsing failed\n");
	}
}

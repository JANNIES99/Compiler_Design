#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	char str[100];
	printf("Enter a string (of 1s and 0s):");
	scanf("%s",str);
	char state='A';
	int error;
	int i=0;
	while(str[i]!='\0'){
		if(str[i]!='1' && str[i]!='0'){
			printf("!Error wrong symbol...");
			error=1;
			break;
		}
		else if(state=='A' && str[i]=='0'){
			state='B';
		}
		else if(state=='B' && str[i]=='1'){
			state='C';
		}
		else if(state=='C' && str[i]=='1'){
			state='A';
		}
		else if(state=='C' && str[i]=='0'){
			state='B';
		}
		printf("State %c\n",state);
		i++;
	}
	if(error==0 && state=='C'){
		printf("Accepted\n");
	}
	else{
		printf("Not Accepted\n");
	}
}

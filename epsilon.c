#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,t,arr[10][10],visited[10];

void closure(int i){
	int j;
	visited[i]=1;
	printf(",q%d",i);
	for(j=0;j<n;j++){
		if(arr[i][j]==1&&visited[j]!=1){
			closure(j);
		}
	}
}

void main(){
	int s1,s2,i,j;
	FILE *fp;
	fp=fopen("hfile.txt","r");
	char trans;
	fscanf(fp,"%d\n",&n);
	while(!feof(fp)){
		fscanf(fp,"%d %c %d\n",&s1,&trans,&s2);
		if(trans=='e'){
			arr[s1][s2]=1;
		}
	}
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			visited[j]=0;		
		}
		printf("\nClosure of q%d:",i);
		closure(i);
	}
}

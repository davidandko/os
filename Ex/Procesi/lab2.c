#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>

int main(int argc,char* argv[]){
	printf("Enter number of commands:\n");
	int n=0;
	
	scanf("%d",&n);
	
	if(n==0){
		printf("Invalid number of arguments\n");
		return 1;
	}
	pid_t child[n];
	for(int i=0;i<n;i++){
		child[i] = fork();
		if(child[i] ==0){
			break;
		}
	}
	
	int j;
	for(int i=0;i<n;i++){
		j=i*4+1;
		if(child[i]==0){
			int T=rand()%10;
			sleep(T);
			execvp(argv[j],&argv[j],&argv[j+1],&argv[j+2],&argv[j+3]);
			printf("Command not valid");
		}
		else{
		wait(NULL);
		}
		
	}
	

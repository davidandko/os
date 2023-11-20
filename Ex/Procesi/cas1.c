#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>


int numVowels(char* arr){
	int vowels=0;
	int i=0;
	while(arr[i] != '\0'){
		switch(arr[i]){
		case 'a':
			vowels++;
			break;
		case 'e':
			vowels++;
			break;
		case 'i':
			vowels++;
			break;
		case 'o':
			vowels++;
			break;
		case 'u':
			vowels++;
			break;
		default:
			continue;	
		
		}
	}
	return vowels;	
}

int numNorm(char* arr){
	int norm=0;
	int i=0;
	while(arr[i] != '\0'){
		if(arr[i] != 'a' || arr[i]!='e' || arr[i]!='i' || arr[i]!='o'|| arr[i]!='u'){
			norm++;
		}
	}
	return norm;	
}

int main(int argc, char* argv[]){

const char* file_name= argv[1];
char file_arr[1000];
FILE* file;
file=fopen(file_name,"r");

if(file == NULL){
printf("The file cannot be opened or is empty!");
return 1;
}
int i=0;
while(!feof(file)){ // start filling the char array with characters from the file if they are only alphabetical (excludes commas, periods,etc.)
	char c = fgetc(file);
	if(isalpha(c)){
		
		file_arr[i]=tolower(c);
	}
	i++;
}
fclose(file);

pid_t child1,child2;

child1 = fork();
if(child1 != 0){
	child2 = fork();
}


if(child1 == 0 ){
	printf("No. Vowels: %d",numVowels(file_arr));	
}else{
	wait(NULL);
}
if(child2 == 0 ){
	printf("No. letters: %d",numNorm(file_arr));	
}else{
	wait(NULL);
}






return 0;
}


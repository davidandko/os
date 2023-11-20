#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<signal.h>
#include<ctype.h>
#include<stdlib.h>

int numberOfChars(int type,char* arr){
    int count=0;
    if(type==0){ // counting vowels
        for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
            if(arr[i] == 'a' || arr[i] =='e' || arr[i] == 'i'
             || arr[i] =='o' || arr[i] =='u'){
                count++;
             }
        }
    }
    else if(type==1){
         for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
            if(arr[i] != 'a' || arr[i] !='e' || arr[i] != 'i'
             || arr[i] !='o' || arr[i] !='u'){
                count++;
             }
        }
    }
    else{
        printf("Bad function call\n");
    }
    return count;
}

int main(int argc,char *argv[]){
    if(argc >2){
        printf("Too many arguments\n");
        fflush(stdout);
        return 1;
    }
    int i=0;
    char file_content[1000]="";
    
    FILE* file;
    file = fopen(argv[1],"r");
    while(!feof(file)){
        char c = fgetc(file);
        if(isalpha(c)){
            c = tolower(c);
            file_content[i] = c;
        }
        else{
            continue;
        }
        i++;
    }
    fclose(file);
    int type_of_char=0;
    pid_t child1=fork();
    pid_t child2;
    if(child1!=0){ //parent
        child2 = fork();
    }
    if(child1 == 0 ){
        printf("Child 1 has counted %d vowels\n",numberOfChars(type_of_char,file_content));
    }
    else if(child2==0){
        type_of_char=1;
        printf("Child 2 has counted %d non-vowels\n",numberOfChars(type_of_char,file_content));
    }

    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

// // print the first five counts with the child process, and the second five with the parent process

// int main(int argc,char* argv[]){
//     int id = fork();
//     int n;
//     if(id == 0){
//         n=1;
//     }
//     else{
//         n=6;
//     }
//     if(id != 0){
//         wait(1); // without the wait we get an intertwined result, we do not want that
//     }
    

//     for(int i=n;i<n+5;i++){
//         printf("%d",i);
//         fflush(stdout);
//     }
//     if(id!=0){
//         printf("\n");
//     }
    



//     return 0;
// }



// visualisation of fork
// each process has a copy of its own values
// when we fork we get an exact copy of the parent process
int main(int argc,char *argv[]){

    

    return 0;
}
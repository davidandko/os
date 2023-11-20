/*
Да се напише програма за пребарување на кутии и пронаоѓање на милионот. Програмот
треба да ги пополни со вредности 100 кутии, притоа вредностите можат да бидат 100,
200, 300,...,1000 или милион. Потоа, програмот треба да креира 5 нитки кои ќе се борат
за пронаоѓање на милионот, притоа само една нитка може да биде победник. Секоја од
нитките треба да отвори по 33 кутии, при што доколку при отворање на кутиите не го
пронајде милионот, испишува на екран дека неуспешно го пронашла милионот.
Доколку некоја од кутиите го најде милионот, истата кажува дека е победник и
испишува после колку отворени кутии го пронашла милионот.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
#define NUM_THREADS 5
int boxes[100];
void *searchForMil(void*t){
    int i,random;
    long tid=(long)t;
    printf("Thread %ld is starting search...\n",tid);
    for(i=0;i<33;i++){
        random=rand()%100;
        if(boxes[random] == 1000000){
            boxes[random]=0;
            printf("Thread %ld has found the prize after %d iterations.WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN\n ",tid,i);
            break;
        }
        else if(boxes[random]!=0){
            boxes[random]=0;
        }
    }
    if(i==33){
            printf("Thread %ld did not find the prize\n",tid);
            pthread_exit((void*)t);
        }
}



int main(int argc,char *argv[]){
    pthread_t threads[NUM_THREADS];
    int i=0,rc=0;
    long trc=0;
    int number;
    void *status;
    for(i=0;i<100;i++){
        number=rand()%10;
        boxes[i]=number*100;
    }
    number=rand()%100;
    boxes[number]=1000000;
    for(i=0;i<100;i++){
        printf("\t %d \t",boxes[i]);
    }
    for(trc=0;trc<NUM_THREADS;trc++){
        rc=pthread_create(&threads[trc],NULL,searchForMil,(void*)trc);
        if(rc){
            printf("Thread %ld was not created, error code: %d\n",trc,rc);
            exit(-1);
        }
    }
    rc=0;
    for(trc=0;trc<NUM_THREADS;trc++){
        rc=pthread_join(threads[trc],&status);
        if(rc){
            printf("Trouble joining thread %ld. Exiting...\n",trc);
            exit(-1);
        }
    }
    printf("Main program completed.Exiting\n");
    pthread_exit(NULL);
}
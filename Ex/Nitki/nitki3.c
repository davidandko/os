#include<stdio.h>
#include<string.h>
#include<string.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<signal.h>
#include<math.h>
#define NUM_THREADS 4
void *doMath(void* t){
    long tid=(long)t; //this is which created thread is working atm
    long result=0.0;
    long ttid=pthread_self(); // this is the actual tid
    printf("Thread %ld starting with TID=%ld...\n",tid,ttid);
    for(int i=0;i<1000000;i++){
        result = result + sin(i) * tan(i);

    }
    pthread_exit((void*)t);
}

int main(int argc,char* argv[]){
    pthread_t threads[NUM_THREADS];
    long t=0;
    int rc=0;
    void *status;
    for(t=0;t<NUM_THREADS;t++){
        rc=pthread_create(&threads[t],NULL,doMath,(void*)t);
        if(rc){
            printf("Creating thread %ld failed with return code %d. Exiting...\n",t,rc);
            exit(-1);
        }
    }
    rc=0;
    for(t=0;t<NUM_THREADS;t++){
        rc=pthread_join(threads[t],&status);
        if(rc){
            printf("Joining thread %ld failed with return code %d. Exiting...\n",t,rc);
            exit(-1);
        }
        printf("Main completed join with thread %ld having status of %ld\n",t,(long)status);
    }
    printf("Main program executed successfully. Exiting\n");

    pthread_exit(NULL);
}
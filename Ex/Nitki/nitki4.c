#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<signal.h>
#include<string.h>
#define NUM_THREADS 5
void *printTID(void* t){
    long tid = (long)t;
    pthread_t ttid = pthread_self();
    printf("Hello from thread %ld with TID= %ld\n",tid,ttid);
    pthread_exit((void*)t);
}

int main(int argc, char **argv){
    pthread_t threads[5];
    long t;
    int rc,i;
    void *status;
    for(t=0;t<NUM_THREADS;t++){
        rc =pthread_create(&threads[t],NULL,printTID,(void*)t);
        if(rc){
            printf("Failed to create thread %ld. Exiting...\n",t);
            exit(-1);
        }
    }
    for(t=0;t<NUM_THREADS;t++){
        rc = pthread_join(threads[t],&status);
        printf("Status of thread: %ld, %ld",status,&status);
        if(rc){
            printf("Failed to join thread %ld. Exiting with status %ld\n",t,&status);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
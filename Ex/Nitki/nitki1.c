/*
Да се напише програма за пребарување на најголемиот елемент во низа од 1000
случајно генерирани броеви. Програмата треба да креира 10 нитки кои што најпрво ќе
генерираат 1000 броеви (секоја по 100). Потоа, треба да се креираат нови 10 нитки кои
што ќе ги изминат тие 1000 (секоја своите 100) и ќе го најдат најголемиот елемент. На
крај, главната програма треба да го испише најголемиот генериран број
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
int arrays[10][100];
int max=-2147483647;
pthread_t threads_gen[10];
void *generate(void *t){
    long tid = (long)t; // kastiranje na void pokazuvacot vo long
    pthread_t ttid=pthread_self(); // vrakja id na nitkata
    srand(time(NULL));
    printf("Thread %ld start generating...\n",tid);
    for(int i=0;i<100;i++){
        arrays[tid][i] = rand()%100;
    }
    pthread_exit((void*)t);
}
void find_max(void* t){
    int i,rc=1,cycles=0;      
    long tid = (long)t;
    void *status;
    printf("Thread %ld start searching\n",tid);
    while(rc){
        rc=pthread_join(threads_gen[tid],&status);
        cycles++;
        if(cycles>10)
            break;
    }
    if(rc){
        printf("Failed to join %ld\n",tid);
        pthread_exit((void*)t);
    }
    for(i=0;i<100;i++){
        printf("\t %d \t",threads_gen[tid][i]);
        if(arrays[tid][i]>max){
            max=arrays[tid][i];
        }
        pthread_exit((void*)t);
    }
}
int main(int argc, char *argv[]){
    pthread_t threads[10];
    int rc1,rc2;
    long t;
    void *status;
    for(t=0;t<10;t++){
        printf("Main: creating thread %ld\n",t);
        rc1=pthread_create(&threads_gen[t],NULL,generate,(void*)t);
        if(rc1){
            printf("ERROR;return code from pthread_create is %d\n",rc1);
            exit(-1);
        }
    }
    for(t=0;t<10;t++){
        printf("Main: creating thread %ld\n",t);
        rc2=pthread_create(&threads[t],NULL,find_max,(void*)t);
        if(rc2){
            printf("ERROR;return code from pthread_create is %d\n",rc2);
            exit(-1);
        }
    }
    for(t=0;t<10;t++){
        rc1=pthread_join(threads[t],&status);
        if(rc1){
            printf("ERROR;return code from pthread_join is %d\n",rc1);
            exit(-1);
        }
        printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
    }
    printf("Main program completed. %d is the largest number. Exiting...\n",max);
    pthread_exit(NULL);
}
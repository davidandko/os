// Да се напише програма во C која работи со процеси и нитки. Програмата
// (главната нитка) како аргументи од командна линија добива збор што се
// пребарува и листа од имиња на датотеки. Доколку не добие листа од датотеки
// од командна линија (добие само збор за пребарување), програмата
// треба да му дозволи да внесе имиња на 3 датотеки од тастатура. Доколку нема
// ни збор за пребарување, најпрво го внесува зборот од тастатура, а потоа
// имињата на 3те датотеки. За секоја датотека во која се прави пребарување, се
// креира посебна нитка која го прави пребарувањето, притоа, на секоја нитка ѝ
// се испраќа кој е зборот што треба да го пребарува и името на датотеката во
// која треба да го прави пребарувањето. Секоја нитка го пребарува зборот во
// својата датотека, и штом заврши, на екран го печати името на датотеката и
// колку пати се појавил зборот. Откако ќе завршат сите нитки, главната нитка
// на екран печати, за секоја датотека одделно, колку процентуално се појавил
// зборот во таа датотека (процент од вкупното појавување на зборот во сите
// датотеки).



// NE JA DOVRSIV AMA GLAVNOTO E RESENO


#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<signal.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<pthread.h>
typedef struct{
    char word[1024];
    char file[1024];
    int i;
}data;

int pojavuvanja[100];
char ime_datoteka[100][1024];

void *search(void *x){
    data lista = *(data*) x;
    FILE *file;
    file=fopen(lista.file,"r");
    char word[1024];

    while(fscanf(file,"%s",word) != EOF){
         if(strcmp(word,lista.word)){
            pojavuvanja[lista.i]++;
            char ime_datoteka[lista.file];
         }
    }

}

int main(int argc,char **argv){
    int i,N;
    data lista[100];
    char files[3][1024];
    char word[1024];
    pthread_t threads[100];

    N = argc-2;

if(argc>2){
    for(i=0;i<N;i++){
        strcpy(lista[i].word,argv[1]);
        strcpy(lista[i].file,argv[i+2]);
        lista[i].i = i;
        pthread_create(&threads[i],NULL,search,(void*)&lista[i]);

    }
    int vkupno_pojavuvanja=0;
    for(i=0;i<N;i++){
        pthread_join(threads[i],NULL);
        vkupno_pojavuvanja+=pojavuvanja[i];
    }

}
else{
    if(N==1){ // ne sme dobile ni zbor za prebaruvanje 
        printf("Enter the word you want to search\n");
        scanf("%s",word);
    }
        printf("Enter three names of files\n");
        scanf("%s%s%s",files[0],files[1],files[2]);
        for(i=0;i<N;i++){
            strcpy(lista[i].word,argv[1]);
            strcpy(lista[i].file,files[i]); // tuka gi stavam fajlovite
            lista[i].i = i;
            pthread_create(&threads[i],NULL,search,(void*)&lista[i]);
        }

        int vkupno_pojavuvanja=0;
        for(i=0;i<N;i++){
            pthread_join(threads[i],NULL);
            vkupno_pojavuvanja+=pojavuvanja[i];
        }

}





    return 0;
}
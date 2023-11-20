// Задача4
// Да се напише програма во C која работи со процеси и нитки. Главната програма
// (родител процесот) пополнува низа од 1000 броеви на случаен начин со помош
// на rand() функцијата. Потоа, креира два деца процеси, така што, двата деца
// процеси вршат пребарување на бројот 0 во низата од 1000 броеви. Првото дете
// процес, пребарувањето го прави со помош на 10 деца процеси, додека пак второто
// дете, пребарувањето го прави со 10 нитки. Секоја нитка/дете процес добива
// дел од низата што треба да го пребара бројот 0 и печати на екран колку пати
// е пронајден бројот кај соодветната нитка/дете процес. Родител процесот чека
// да завршат двете деца процеси и на екран печати кое од двете завршило прво.
// Доколку прво заврши дете процесот кое пребарувањето го прави со помош на деца
// процеси, тогаш на екран се печати „pobrzo zavrshi prebaruvanjeto so deca
// procesi“, инаку печати „pobrzo zavrsi prebaruvanjetopobrzo zavrshi
// prebaruvanjeto so deca procesi“, инаку печати „pobrzo zavrshi prebaruvanjeto
// so deca procesi“, инаку печати „pobrzo zavrsi prebaruvanjetopobrzo zavrsi
// prebaruvanjeto so nitki“.
// БОНУС: Да се имплементира кодот така што двете деца процеси печатат само по
// еднаш колку вкупно е пронајдена 0. Кај првото дете процес, комуникацијата со
// децата процеси кои пребаруваат да се прави со помош на датотека со име „pobrzo
// zavrshi prebaruvanjeto so deca procesi“, инаку печати „pobrzo zavrsi
// prebaruvanjetocommunicate.txt“.




#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int niza[1000];

int main(int argc,char **argv){

    int i;
    pid_t deteProces,deteNitka;
    pid_t deca[10];
    pthread_t nitki[10];
    FILE *f;
    f=fopen("communicate.txt","r");
    for(i=0;i<1000;i++){
        niza[i]=rand()%200;
    }
    

    if(deteProces==0){
         for(i = 0;i<10;i++){
            deca[i] = fork();
            if(deca[i] == 0 ){
                break;
            }
        }
        if(i<10){ // se naogjame vo dete proces
            for(i=0;i<100;i++){
                if(niza[i] == 0){
                    printf()
                }
            }
        }
    }
   

    return 0;
}
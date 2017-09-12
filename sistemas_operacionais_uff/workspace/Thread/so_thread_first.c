#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *ola(){

    FILE *arq = fopen("arquivo1.txt","r");
    char msg[255];
    fgets(msg, 255 , arq);
    printf("%s",msg);
    fclose(arq);

}

void *f2(){
    FILE *arq = fopen("arquivo2.txt","w+");
    printf("\nRespondi essa pergunta no arquivo2.txt\n");
    fprintf(arq,"Ola, está tudo bem sim!");
    fclose(arq);
}

int main(){
    pthread_t t1, t2;
    int x = 1;
    pthread_create(&t1,NULL,ola,NULL);
    pthread_create(&t2,NULL,f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
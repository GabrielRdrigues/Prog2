// Criando um arquivo .txt com 1000 números inteiros aleatórios
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE* f =fopen("numeros.txt","w");
    srand(time(NULL));
    for(int i=0;i<10;i++){
        fprintf(f,"%d ",rand()%10);
    }
}
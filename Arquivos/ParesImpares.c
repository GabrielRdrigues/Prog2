// Lendo um arquivo de texto com 1000 números aleatórios e separando entre pares e impares
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(){
    FILE* f,*p,*i;
    f=fopen("numeros.txt","r");
    p=fopen("pares.txt","w");
    i=fopen("impares.txt","w");
    int x;
    for(int j=0;j<10;j++){
        fscanf(f,"%d ",&x);
        if(x%2==0)
            fprintf(p,"%d ",x);
        else
            fprintf(i,"%d ",x);
    }
    fclose(f);
    fclose(p);
    fclose(i);
}
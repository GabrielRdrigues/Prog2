#include <stdio.h>

int main(){
    FILE* f = fopen("numeros.txt","r");
    int soma=0,x;
    while(fscanf(f,"%d",&x)==1){
        soma+=x;
    }
    fclose(f);
    printf("%d",soma);
    return 0;
}
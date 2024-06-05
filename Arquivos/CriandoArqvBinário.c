#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE* f = fopen("numeros.bin","wb");
    srand(time(NULL));
    int* v=malloc(10*sizeof(int));
    for(int i =0;i<10;i++)
        v[i]=rand()%100;
    fwrite(v,sizeof(int),10,f);
    fclose(f);
    free(v);
}
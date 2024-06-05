#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* f = fopen("numeros.bin","rb");
    int v[10];
    fread(v,sizeof(int),10,f);
    fclose(f);
    FILE* p=fopen("pares.bin","wb");
    FILE* i=fopen("impares.bin","wb");
    for(int j =0;j<10;j++){
        if(v[j]%2==0)
            fwrite(&v[j],sizeof(int),1,p);
        else
            fwrite(&v[j],sizeof(int),1,i);
    }
    fclose(p);
    fclose(i);
}
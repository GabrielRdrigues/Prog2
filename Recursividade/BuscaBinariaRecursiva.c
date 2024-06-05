#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int num,int* v,int I0,int I1){
    if(I0>I1)
        return -1;
    int meio=(I0+I1)/2;
    if(num>v[meio])
        return busca_binaria(num,v,meio+1,I1);
    if(num<v[meio])
        return busca_binaria(num,v,I0,meio-1);
    return meio;
}

int main(){
    
    int v[10]={9,46,47,48,62,75,97,102,204,300};
    int i = busca_binaria(75,v,0,9);

    if(i<0)
        puts("\nvalor nao encontrado ;(");
    else 
        printf("valor %d encontrado na posicao %d",v[i],i);
    
}
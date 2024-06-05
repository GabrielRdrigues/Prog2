#include <stdio.h>

void troca(int *p,int *q){
    int temp;
    temp=*p;*p=*q;*q=temp;
}

int main () {
    /*int A=5,B=4;
    int *p,*q;
    p=&A;
    q=&B;*/
  int *p;
  int *q,**r;
  int A=5,B=4;
  p=&A;
  q=&B;
  printf("\n%ld\n",(long int)p);
  printf("%p\n",&A);
  printf("%p",p);

  // Utilizando ponteiros de ponteiros de inteiro
    //r=&q;
    //printf("%d",**r+*p);

  // Trocando o valor de duas variáveis em uma função
    //troca(p,q);
    //printf("A=%d",A);
    //printf("\nB=%d",B);

    return 0;
}
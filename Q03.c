/*Escreva um programa que receba dois números inteiros, e imprima uma das três mensagens
abaixo, de acordo com os números informados:
- Ambos são pares
- Ambos são ímpares
- Um valor é par, o outro é ímpar (não importa a ordem)*/
#include <stdio.h>

int main(){
    int A,B;
    scanf("%d %d",&A ,&B);
    if(A%2==0 && B%2==0){
        puts("Ambos são pares");
    }else{
        if(A%2!=0 && B%2!=0){
            puts("Ambos são ímpares");
        }else(puts("Um valor é par, o outro é impar"));
    }
    
    return 0;
}

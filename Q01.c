/*Escreva um programa que receba dois números inteiros, imprima a soma desses números, e
depois uma mensagem indicando se essa soma é um número múltiplo de 3 */ 

#include <stdio.h>
#include <string.h>

int main(){
    int A,B;
    puts("Digite dois números");
    scanf("%d %d",&A,&B); 
    printf("Soma: %d\n",A+B);
    puts((A+B)%3==0? "É múltiplo de 3":"Não é múltiplo de 3");
    
    return 0;
}

// %i identifica a base pelo prefixo, podemos entrar com números em octal e hexadecimal
// no printf não há diferença entre %i e %d
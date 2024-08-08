#include <stdio.h>

#define MAXSIZE 1024
// Implementação de uma pilha estática

void numero_arbitrario_de_valores(){
    char stack[MAXSIZE];
    int n = 0; // INIT

    char c;
    while(n < MAXSIZE && scanf("%c", &c)==1){ // Verifica se chegou na capacidade máxima da pilha e se leu um caracter
        stack[n++] = c;  // PUSH
    }

    while(n>0){ // IS_EMPTY
        printf("%c ", stack[n-1]);  // TOP
        n--; // POP
    }

}


int main(){
    char stack[MAXSIZE];
    int n=0; //INIT

    stack[n++]= 'A'; // PUSH  stack[0] n=1
    stack[n++]= 'B'; // PUSH  stack[1] n=2
    stack[n++]= 'C'; // PUSH  stack[2] n=3
    stack[n++]= 'D'; // PUSH  stack[3] n=4

    while(n>0){ // IS_EMPTY (Verificar se a pilha está vazia)
        printf("%c ",stack[n-1]); // TOP (ver quem é o topo)
        n--; //     POP
    }
}

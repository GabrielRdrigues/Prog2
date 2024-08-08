#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 1024

// Verifica se os parenteses, colchetes e chaves estão corretas
// Utilizando pilha estática

bool is_open(char c){
    return c == '(' || c == '{' || c=='[' ;
}

bool is_close(char c){
    return c == ')' || c == '}' || c==']' ;
}

bool is_match(char c1,char c2){
    return (c1 == '[' && c2==']') ||  (c1 == '(' && c2==')' ) || (c1 == '{' && c2=='}');
}


bool balanceado(const char* str){
    char stack[strlen(str)];
    int n=0;

    for(int i=0;i<strlen(str);i++){
        char c = str[i];

        if(is_open(c))
            stack[n++]=c; // PUSH

        if(is_close(c)){
            return n==0 || !is_match(c,stack[n-1]);
            n--; // POP
        }
    }

    return n==0;
}


int main(){
    if(balanceado("(23+[45*{26-18}])"))
        puts("balanceado");
    else
        puts("errado");
}
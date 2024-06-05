// Esse programa possui uma função que irá pegar uma String S e irá tirar tudo que não for letra.
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* copia_letras(char* S){
    char* X = malloc((strlen(S)+1)*sizeof(char));
    char c;
    int i,j=0;
    j=0;
    for(i=0;i<strlen(S);i++){
        if((S[i]>='a'&& S[i]<='z')||(S[i]>='A' && S[i]<='Z')){
            X[j]=S[i];
            j++;   
        }      
    }
    X[j]='\0';
    return X;
}

int main(){
    char* s = copia_letras("quem? eu? eu nao, oxe!");
    puts(s);
    free(s);
}
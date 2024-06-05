#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* procura_espaco(char*S,int n){
  int* espaco = malloc((n-1)*sizeof(int));
  int j=0;
  for(int i=0;i<strlen(S);i++){
    if(S[i]==' '){
      espaco[j]=i;
      j++;
    }
  }
  return espaco;
}

char* substring(char* S,int I0,int I1){
  char* Aux = malloc((I1-I0+2)*sizeof(char));
  for(int i=0;i<=I1-I0;i++)
    Aux[i]=S[I0+i];
  Aux[I1-I0+1]='\0';
  return Aux;
}
  
char** split(char* S,int* N){
  char** palavras = malloc((*N)*sizeof(char*));
  int* esp=procura_espaco(S,*N);
  int I0=0;
  int I1;
  for(int i=0;i<*N-1;i++){
    I1=esp[i];
    palavras[i]=substring(S, I0, I1);
    I0=I1+1;
  }
  free(esp);
  palavras[*N-1]=substring(S, I0, strlen(S)-1);
  return palavras;
}

int main() {
  int N=5;
  char** ola = split("olha que coisa mais linda",&N);
  for(int i =0;i<N;i++){ 
    printf("%d : %s\n",i,ola[i]);
  }
  for(int i=0;i<N;i++)
    free(ola[i]);
  free(ola);
  

  return 0;
}
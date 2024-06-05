#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idade;
    float peso;
    float altura;
    char nome[50];
}Aluno;

void ordena(Aluno* Dados,int n){
    for(int i=n;i>1;i--){
        for(int j=1;j<n;j++){
            if(strcmp(Dados[j-1].nome,Dados[j].nome)>0){
                Aluno aux = Dados[j-1];
                Dados[j-1]=Dados[j];
                Dados[j]=aux;
            }
        }
    }
}

int main(){
    FILE* f = fopen("dados.txt","r");
    int x;
    fscanf(f,"%d",&x);
    Aluno* Dados = malloc(x*sizeof(Aluno));
    for(int i=0;i<x;i++){
        fscanf(f,"%d %f %f %50[^\n]",&Dados[i].idade,&Dados[i].peso,&Dados[i].altura,Dados[i].nome);
    }
    fclose(f);
    ordena(Dados,x);
    f=fopen("dados_ordenados.txt","w");
    fprintf(f,"%d\n",x);
    for(int i=0;i<x;i++){
        fprintf(f,"%d %g %g %s\n",Dados[i].idade,Dados[i].peso,Dados[i].altura,Dados[i].nome);
    }
    fclose(f);
    free(Dados);
}
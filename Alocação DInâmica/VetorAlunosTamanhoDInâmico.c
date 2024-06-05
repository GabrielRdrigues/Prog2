/*Crie a estrutura VetorAlunos que representa um vetor de tamanho dinâmico de Alunos, 
conforme o exemplo abaixo:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int serie;
    char turma;
    float nota;
}Aluno;

typedef struct{
    Aluno* dados;
    int n;
    int capacidade;
}VetorAlunos;

VetorAlunos inicializa_alunos(){
    VetorAlunos X;
    X.dados = malloc(sizeof(Aluno));
    X.n = 0;
    X.capacidade= 1;
    return X;
}

void adiciona_aluno(VetorAlunos* X,Aluno Y){
    if(X->n==X->capacidade){
        X->capacidade*=2;
        X->dados= realloc(X->dados,X->capacidade*sizeof(Aluno));
    }
    X->dados[X->n] = Y;
    X->n++;
}

void imprime_aluno(VetorAlunos V){
    for(int i=0;i<V.n;i++){
        printf("%-20s %d %c %f\n",V.dados[i].nome,V.dados[i].serie,V.dados[i].turma,V.dados[i].nota);
    }
}

int main(){
    VetorAlunos V = inicializa_alunos();
    
    Aluno x;
    while(scanf(" %[^:]: %d %c %f", x.nome, &x.serie, &x.turma, &x.nota) == 4)
        adiciona_aluno(&V, x);
    
    imprime_aluno(V);
    free(V.dados);
}


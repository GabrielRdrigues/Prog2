#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXSIZE 100

typedef struct{
    int priority;
    char name[51];
}Dados;

typedef struct{
    Dados data[MAXSIZE];
    int n;
}PriorityQueue;

void init_queue(PriorityQueue* q){
    q->n = 0;
}

Dados dequeue(PriorityQueue* q){
    assert(q->n > 0);
    q->n--;
    return q->data[q->n];
}

void enqueue(PriorityQueue* q, int priority, const char* name){
    assert(q->n < MAXSIZE);
    int i = q->n;
    while(i > 0 && q->data[i-1].priority >= priority){
        q->data[i] = q->data[i-1];
        i--;
    }
    q->data[i].priority = priority;
    strcpy(q->data[i].name, name);
    q->n++;
}


int main(){
    PriorityQueue q;
    init_queue(&q);
    int opcao;
    int idade;
    char s[50];

    while(1){
        scanf("%d",&opcao);
        if(opcao==1){
            puts("Digite o nome e idade: ");
            scanf(" %[^\n] %d",s,&idade);
            puts("");
            if(idade<18)
                enqueue(&q,1,s);
            else{
                if(idade>=60)
                    enqueue(&q,3,s);
                else
                    enqueue(&q,2,s);
            }
        }else{
            if(opcao==2 && q.n>0){
                Dados D = dequeue(&q);
                puts("Próximo a ser chamado eh : ");
                puts(D.name);
            }else
                break;
        }
            
    }

    // while(q.n > 0){
    //     Dados D = dequeue(&q);
    //     puts(D.name);
    // }
}


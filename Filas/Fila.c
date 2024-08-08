#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct{
   char** data;          // Vetor para armazenar os elementos da fila
   int capacity;        // Tamanho atualmente alocado do vetor
   int n;               // Número de elementos inseridos
   int first;           // Primeiro elemento da fila
   int end;             // Final da fila (próxima posição disponível)
}Queue;

// Inicializar uma fila vazia.
void init_queue(Queue* q){
   q->data = malloc(sizeof(char*));
   q->capacity = 1;
   q->n = 0;
   q->first = q->end = 0;
}

// Verificar se a fila está vazia.
bool is_empty(Queue* q){
   return q->n == 0;
}

// Liberar os dados alocados para uma fila.
void free_queue(Queue* q){
    //for(int i=0;i< q->n;i++)
        //free(q->data[i]);
   free(q->data);
}

// Adicionar um elemento a uma fila.
void enqueue(Queue* q, char* value){
   // Se o vetor está cheio, vamos aumentar a sua capacidade.
   if(q->n == q->capacity){
       q->capacity *= 2;
       q->data = realloc(q->data, q->capacity*sizeof(char*));
   }

   // Adicione o valor no final da fila.

   // Atualize a quantidade de valores adicionados.

   // Atualize o final da fila.
   q->end++;
    if(q->end == q->capacity && q->first > 0){
       // Empurre os dados para o início do vetor.
       for(int i = 0; i < q->n; i++)
           strcpy(q->data[i] , q->data[q->first + i]);

       // Atualize o início e fim da fila.
       q->first = 0;
       q->end = q->n;
   }
   strcpy(q->data[q->end] ,value);
   q->n++;
}

char* dequeue(Queue* q){
    assert(q->n > 0);
    char* C = q->data[q->first];
    q->first++;
    q->n--;
    return C;
}

int main(){
	Queue Q;
	init_queue(&Q);
    char s[50];
    while(scanf(" %[^\n]",s)==1){
        enqueue(&Q,s);
    }

    while(Q.n>0){
        char* string = dequeue(&Q);
        puts(string);
    }
    free_queue(&Q);
}
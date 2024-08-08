#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    int first;
    int n;
    int capacity;
    char* data;
}Queue;

void init_queue(Queue* q){
    q->first = 0;
    q->n = 0;
    q->capacity = 1;
    q->data = malloc(sizeof(char));
}

void free_queue(Queue* q){
    free(q->data);
}

void enqueue(Queue* q, char value){
    if(q->n == q->capacity){
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity*sizeof(char));
    }
    int index = q->first + q->n;
    if(index == q->capacity){
        for(int i = 0; i < q->n; i++)
            q->data[i] = q->data[q->first + i];
        q->first = 0;
        index = q->n;
    }
    q->data[index] = value;
    q->n++;


}

char dequeue(Queue* q){
    assert(q->n > 0);
    char C = q->data[q->first];
    q->first++;
    q->n--;
    if(q->n < q->capacity/2){
        q->capacity= q->capacity/2;
        q->data= realloc(q->data,q->capacity*sizeof(char));
    }
    return C;
}


int main(){
    Queue Q;
    init_queue(&Q);
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    printf("%c ", dequeue(&Q) );
    enqueue(&Q, 'D');
    printf("%c ", dequeue(&Q) );
    enqueue(&Q, 'E');
    printf("%c ", dequeue(&Q) );
    enqueue(&Q, 'F');
    enqueue(&Q, 'G');
    enqueue(&Q, 'H');
    while(Q.n > 0)
        printf("%c ", dequeue(&Q) );
    
    free_queue(&Q);
}

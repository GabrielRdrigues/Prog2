#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
   int data;
   struct Node* next;
}Node;

typedef struct Queue{
    Node* head;
}Queue;

Node* make_node(int data, Node* next){
   Node* node = malloc(sizeof(Node));
   node->data = data;
   node->next = next;
   return node;
}

void free_list(Node* head){
   if(head){
       free_list(head->next);
       free(head);
   }
}

Node* push_front(Node* head, int c){
    Node* new_head = make_node(c,head);
    return new_head;
}

Node* pop_front(Node* head){
    if(head==NULL)
        return NULL;
    Node* new_head =  head->next;
    free(head);
    return new_head;
}

Node* back_node(Node* head){
    if(head==NULL)
        return NULL;
    Node* back=head;
    while(back->next!=NULL)
        back=back->next;
    return back;
}

Node* push_back(Node* head,int x){
    Node* back = make_node(x,NULL);
    if(head==NULL)
        return back;
    Node* ultimo_no= back_node(head);
    ultimo_no->next=back;
    return head;
}

void init_queue(Queue* Q){
    Q->head=NULL;
}

bool is_empty(Queue* Q){
    return Q->head==NULL;
}

void enqueue(Queue* Q,int valor){
    Q->head=push_back(Q->head,valor);
}

int dequeue(Queue* Q){
    assert(!is_empty(Q));
    int aux = Q->head->data;
    Q->head=pop_front(Q->head);
    return aux;
}

// Lista encadeada funciona como uma Fila
int main(){
    Queue Q;
    init_queue(&Q);
    enqueue(&Q,10);
    enqueue(&Q,15);
    enqueue(&Q,20);

    while(Q.head!=NULL){
        printf(" :%d\n", dequeue(&Q));
    }

    //free_list(head);
}


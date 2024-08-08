#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
   int data;
   struct Node* next;
}Node;

typedef struct Stack{
    Node* head;
}Stack;

Node* make_node(int data, Node* next){
   Node* node = malloc(sizeof(Node));
   node->data = data;
   node->next = next;
   return node;
}

/*void free_list(Node* head){
    if(head){
        free_list(head->next);
        free(head);
   }
}  */

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

void init_stack(Stack* stack){
    stack->head=NULL;
}

bool is_empty(Stack* stack){
    return stack->head==NULL;
}

int top(Stack* stack){
    assert(!is_empty(stack));
    return stack->head->data;
}

void push(Stack* stack,int value){
    stack->head=push_front(stack->head,value);
}

void pop(Stack* stack){
    stack->head=pop_front(stack->head);
}

void free_stack(Stack* stack){
    while(stack->head){
        pop(stack);
    }
}

// Lista encadeada como uma pilha
int main(){
    Stack stack;
    init_stack(&stack);
    push(&stack,10);
    push(&stack,15);
    push(&stack,50);

    while(!is_empty(&stack)){
        printf(":%d\n",top(&stack));
        pop(&stack);
    }

    
    //free_stack(&stack);
}


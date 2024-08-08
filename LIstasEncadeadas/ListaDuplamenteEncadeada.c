#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data[50];
    struct Node* next;
    struct Node* previous;
}Node;

Node* make_node(char* nome){
    Node* node = malloc(sizeof(Node));
    strcpy(node->data,nome);
    node->next=NULL;
    node->previous=NULL;
    return node;
}

Node* push_front(Node* head,char* nome){
    Node* new_head= make_node(nome);
    if(head==NULL)
        return new_head;
    new_head->next=head;
    head->previous=new_head;
    return new_head;
}

Node* pop_front(Node* head){
    if(head==NULL)
        return NULL;
    Node* new_head = head->next;
    if(new_head!=NULL)
        new_head->previous=NULL;
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

Node* push_back(Node* head,char* nome){
    Node* novo_item = make_node(nome);
    Node* back = back_node(head);
    if(back==NULL)
        return novo_item;
    back->next=novo_item;
    novo_item->previous=back;
    return head;
}

void push_after(Node* node,char* nome){
     if(node == NULL)
        return;

    Node* n = make_node(nome);
    n->next = node->next;
    n->previous = node;
    node->next = n;

    if(n->next != NULL)
       n->next->previous = n;

}

Node* find(Node* head, char* c){
    for(Node* n = head; n != NULL; n = n->next)
        if(strcmp(c , n->data)==0)
            return n;

    return NULL;
}

Node* remove_node(Node* head, Node* B){
    if(head == NULL || B == NULL)
        return head;
    if(B == head)
        return pop_front(head);

    Node* A = B->previous;
    Node* C = B->next;
    A->next = C;
    if(C != NULL)
    C->previous = A;
    free(B);
    return head;
}

int main(){
    Node* head = NULL;

    head=push_front(head,"Gabriel");
    head=push_front(head,"Julia");
    head=push_front(head,"Luana");
    head=push_front(head,"William");
    head=push_back(head,"Giovanna");
    Node* A = find(head,"Luana");
    push_after(A,"Matheus");
    head=remove_node(head,A);

    while(head){
        printf("%s\n",head->data);
        head=head->next;
    }

}

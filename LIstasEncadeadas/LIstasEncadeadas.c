#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node* next;
}Node;

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

void push_after(Node* node,int x){
    if(node!=NULL){
        Node* novo_no = make_node(x,NULL);
        novo_no->next=node->next;
        node->next=novo_no;
    }
}

Node* remove_item(Node* head, int x){
    if(head==NULL)
        return NULL;
    Node* p = head;
    Node* n = head->next;

    if(p->data==x){
        return pop_front(head);
    }

    while(n!=NULL && n->data!=x){
        p=n;
        n=n->next;
    }

    if(n!=NULL){
        p->next=n->next;
        free(n);
    }
    return head;

}

int main(){
    Node* head = NULL;
    head=push_front(head,15);
    head=push_front(head,20);
    head=push_front(head,35);
    head=pop_front(head);
    head=pop_front(head);
    head = push_front(head,99);
    head = push_front(head,23);
    push_after(head,14);
    remove_item(head,99);

    while(head){
        printf(" :%d\n",head->data);
        head = pop_front(head);
    }

    free_list(head);
}


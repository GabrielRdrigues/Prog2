#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct{
    int n;
    int capacity;
    char* data;
}Stack;

void init_stack(Stack* stack){
    stack->n = 0;
    stack->capacity = 1;
    stack->data = malloc(sizeof(char));
}

void free_stack(Stack* stack){
    free(stack->data);
}

bool is_empty(Stack* stack){
    return stack->n == 0;
}

char top(Stack* stack){
    assert(!is_empty(stack));
    return stack->data[stack->n - 1];
}

void push(Stack* stack, char value){
    if(stack->n == stack->capacity){
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity*sizeof(char));
    }
    stack->data[stack->n++] = value;
}

void pop(Stack* stack){
    assert(!is_empty(stack));
    stack->n--;
}

int main(){
    Stack s;
    init_stack(&s);

    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    push(&s, 'D');

    while(!is_empty(&s)){
        printf("%c ", top(&s));
        pop(&s);
    }
    free_stack(&s);
}


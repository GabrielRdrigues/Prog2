#include <stdio.h>
typedef struct Dados{
   int i;
   struct Dados* outro;
}Dados;

int main(){
    Dados a = {21,NULL};
    Dados b = {75,&a};
    Dados c= {49,&b};
    Dados* p=&c;
    a.outro=&c;
    
    printf("A:%d\n",p->outro->outro->i);
    printf("B:%d\n",p->outro->i);
    printf("C:%d\n",p->i);
}

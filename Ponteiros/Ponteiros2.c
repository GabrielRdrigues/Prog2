#include <stdio.h>

int main(){
    int A;
    int* Q;
    Q=&A;
    printf("\n");
    printf("%d\n",*Q);
    A=5;
    printf("%d\n",*Q); // Derreferenciar Q
}
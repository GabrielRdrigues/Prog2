#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    const char* item[6] = {"batata", "bola", "computador", "teclado", "mouse", "nada"};
    int n;
    srand(time(NULL));
    n = rand()%6; 
    printf("\n%s\n",item[n]);
    
    return 0;
}
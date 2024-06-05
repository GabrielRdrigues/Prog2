#include <stdio.h>

void altera(int* u,float* v){
    if(*u%2==0)
        *u=*u/2;
    else
        *v=*v*3.5;
}

int main(){
    int u=30;
    float v=6.9;
    altera(&u,&v);
    printf("%d %g\n",u,v);
    altera(&u,&v);
    printf("%d %g\n",u,v);
}
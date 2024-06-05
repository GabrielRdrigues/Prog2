#include <stdio.h>

typedef struct{
   float base;
   float altura;
}Retangulo;

float areaRetangulo(Retangulo* P){
    float area;
    area = P->base * P->altura;
    return area;
}

int main(){
   Retangulo r = {3.7, 5.8};
   //Retangulo* P = &r;
   float area = areaRetangulo(&r);
   printf("Área = %g\n", area);
}

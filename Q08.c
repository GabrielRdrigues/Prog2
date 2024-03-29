#include <stdio.h>
#include <math.h>

typedef struct{
   float x, y;
}Ponto;

typedef struct{
    Ponto P, Q, R;
}Triangulo;

float distancia(Ponto P1,Ponto P2){
    float X,Y;
    X= P1.x - P2.x;
    Y = P1.y-P2.y;
    return sqrt((X*X)+(Y*Y));
}

float areaTriangulo(Triangulo T){
    float a,b,c,p,area;
    a = distancia(T.P,T.Q);
    b = distancia(T.Q,T.R);
    c = distancia(T.R,T.P);
    p = (a+b+c)/2;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}

Triangulo maiorTriangulo(Triangulo T1, Triangulo T2){
    if(areaTriangulo(T1)> areaTriangulo(T2))
        return T1;
    return T2;
}

void imprimeTriangulo(Triangulo T){
    printf("(%f,%f)\n",T.P.x,T.P.y);
    printf("(%f,%f)\n",T.Q.x,T.Q.y);
    printf("(%f,%f)",T.R.x,T.R.y);
}

int main(){
   Triangulo T1 = {{0, 0}, {2, 3}, {5, 6}};
   Triangulo T2 = {{4, 5}, {3, 1}, {6, 3}};
  
   Triangulo maior = maiorTriangulo(T1, T2);
   puts("Maior triangulo:");
   imprimeTriangulo(maior);

}

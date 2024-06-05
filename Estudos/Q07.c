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

int main(){
   Triangulo T = {{1, 0}, {2, 3}, {5, 6}};
   float a = areaTriangulo(T);
   printf("area = %g\n", a);
}

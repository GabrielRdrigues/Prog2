/*Escreva uma função que calcula a distância entre dois pontos utilizando a estrutura 
definida abaixo:
*/
//https://stackoverflow.com/questions/10409032/why-am-i-getting-undefined-reference-to-sqrt-error-even-though-i-include-math

#include <stdio.h>
#include <math.h>

typedef struct{
    float x,y;
}Ponto;

float distancia(Ponto P1,Ponto P2){
    float X,Y;
    X= P1.x - P2.x;
    Y = P1.y-P2.y;
    return sqrt((X*X)+(Y*Y));
}

int main(){

    Ponto P1,P2;
    float dist; // Guarda a distância entre P1 e P2
    puts("Escreva as coordenadas de P1");
    scanf("%f %f",&P1.x, &P1.y);
    puts("Escreva as coordenadas de P2");
    scanf("%f %f",&P2.x, &P2.y);
    dist = distancia(P1,P2);
    printf("%f",dist);


}

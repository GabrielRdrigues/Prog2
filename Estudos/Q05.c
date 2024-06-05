/* Escreva um programa contendo o vetor abaixo, leia uma palavra e imprima todos os itens do vetor 
que tenham menos letras do que a palavra informada, depois todos os itens que tenham a mesma 
quantidade de letras, e depois todos os itens que tenham mais letras.*/

#include <stdio.h>
#include <string.h>

int main(){
     const char* nomes[] = { "galinha", "golfinho", "carpa", "tartaruga", "cavalo", "chita", 
     "mosquito", "elefante", "panda", "bode" };
     // Não posso trocar por exemplo o 'g' de 'galinha' por 'G', pois é CONST;
     char palavra[50]; int quantidade;
     scanf("%s",palavra);
     quantidade = strlen(palavra);
     printf("%d\n",quantidade);
     for(int i=0;i<10;i++){
        if(i==0)
            printf("menores: ");
        if(strlen(nomes[i])< quantidade)
            printf("%s ",nomes[i]);
     }puts("");
     for(int i=0;i<10;i++){
        if(i==0)
            printf("mesmo tamanho: ");
        if(strlen(nomes[i])== quantidade)
            printf("%s ",nomes[i]);
     }puts("");
     for(int i=0;i<10;i++){
        if(i==0)
            printf("maiores: ");
        if(strlen(nomes[i]) > quantidade)
            printf("%s ",nomes[i]);
     }puts("");

    return 0;
}
    // Erro de compilação V
    //  const char* const teste = "BOLA";
    //  puts(teste);
    //  teste = "GABRIEL";
    //  puts(teste);
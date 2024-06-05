/*Em um cinema, o valor da entrada inteira é R$20,00.
Podem pagar meia entrada:
- crianças de até 12 anos
- estudantes apresentando a carteirinha
Escreva um programa que pergunte a idade de uma pessoa e se ela possui
carteirinha de estudante (valor 0 se não tiver, qualquer outro valor se tiver), e
mostre qual deve ser o valor da entrada no cinema.*/
#include <stdio.h>
#include <string.h>

int main(){
    int idade,carteirinha;
    puts("Digite sua idade");
    scanf("%d",&idade);
    puts("Digite 0 se NÃO possuir a CARTEIRINHA\nDigite qualquer outro valor se POSSUIR");
    scanf("%d",&carteirinha);
    puts(idade <= 12 || carteirinha!=0? "O valor é R$10,00":"O valor é R$20,00");
    return 0;
}
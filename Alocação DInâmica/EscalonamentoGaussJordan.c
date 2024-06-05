#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void lerMatriz(int ROWS, int COLUNAS,float** matriz,FILE* file){
    
    // Verificar se o ponteiro para o arquivo é NULL, isto é, apontado para "nenhum lugar". Se sim, terminar o programa.
    assert(file);

    int linha=0; // Inicializando a variável linha
    // Enquanto não for o final do arquivo (a matriz não acabou), continuar lendo.
    while(!feof(file)){
        if(ferror(file)){ // O comando ferror verifica novamente se nesse iteração há erro no arquivo. Se sim, terminar o programa.
                printf("Error");
                exit(1);
                 }
        for(int i=0; i < COLUNAS;i++){ // Irá armazenar a leitura do arquivo em uma variável do programa. Isto é, estamos salvando a matriz do arquivo.
            if(fscanf(file, "%f",&matriz[linha][i])==EOF) // Se já estivermos no final do arquivo, daremos o comando "break", encerrando o FOR.
                break;
        }   
        linha++; // Passando para a próxima linha da matriz
        if(linha==ROWS) // se nosso contador de linhas chegou a última linha da matriz, iremos dar o comando "break" para sair do WHILE.
            break;
    }
    // Fim da Função
}

void printMatriz(float** matriz,int ROWS,int COLUNAS){
    // Dois FOR para percorrer toda a matriz e imprimir. A função recebe como paramêtro uma matriz e a quantidade de linhas e colunas
    for(int i=0;i<ROWS;i++){ // Percorre as linhas até ROWS(quantidade de linhas da matriz)
        for(int j=0;j<COLUNAS;j++) // Percore as colunas até COLUNAS(quantidade de colunas da matriz)
            printf("%g ",matriz[i][j]); // Imprime a matriz
        printf("\n");
     }
}

float** identidade(float** matriz,int ROWS,int COLUNAS){
    int i,j;
    int aux1=COLUNAS+1;
    int aux2=2*COLUNAS;
    for(i=0;i<ROWS;i++)
        for(j=aux1;j<=aux2;j++){
            if(i == j-aux1){
                matriz[i][j-1]=1;
            }else{
                matriz[i][j-1]=0;
            }
        }
    puts("");
    printMatriz(matriz,ROWS,2*COLUNAS);
    return matriz;
}

void escalonar(float** matriz,int ROWS_A,int COLUNAS_A){
    int j,i=0,n,k,m,l;
    int linha_pivo=0;
    
    for(j=0;j<COLUNAS_A;j++){ // Percorrer cada coluna da matriz
        

    /* Verificar se o pivô inicial é zero e existe algum número diferente de 
     0 abaixo OU se toda a coluna é  zero;*/

        while(linha_pivo+i<ROWS_A && matriz[linha_pivo+i][j]==0){ 
            i++;
        }
        // Verificar se as linhas ainda não terminaram e achamos um elemento não nulo.
        if(linha_pivo+i<ROWS_A){
            int aux= linha_pivo+i;
            // Vamos permutar a linha do pivô com a linha do elemento não nulo
            //  Caso o pivô já seja um elemento não nulo, iremos permutar a linha por ela pŕopria.
            for(k=0;k<2*COLUNAS_A;k++){ // PERMUTAÇÃO DE LINHAS
                double temp= matriz[linha_pivo][k];
                matriz[linha_pivo][k]=matriz[aux][k];
                matriz[aux][k]=temp;
            }
            for(m=linha_pivo+1;m<ROWS_A;m++){ // Operação elementar li ← li +klj , 
                double c= matriz[m][j] / matriz[linha_pivo][j]; // Calculando o valor do fator (seria o nosso "k")
                for(n=0;n<2*COLUNAS_A;n++){
                    matriz[m][n]+= -c * matriz[linha_pivo][n];    // aplicando a operação elementar em toda a linha        
                        }
            }
            linha_pivo++;
        }

        i=0; // Resetando nosso contador i para que seja utilizado na pŕoxima coluna

    }
    // Os dois FOR abaixo se trata de um mecanismo de arredondar números extremamente pŕoximos de 0 para 0.
    // Isto deve ser feito para evitar problemas lidando com frações que possam dar dizimas períodícas.
    // Por exemplo, caso algum número da matriz seja 0.0000000023456, aproximaremos para 0.
    // Se fizessemos na mão, o resultado daria 0 já que nós não dividimos frações (pois podem gerar erros), porém no computador há essas imprecisões
    // Lidar com números FLOAT pode ser perigoso, pois nem sempre eles podem ser devidamente convertidos para binário e pode acabar gerando esse problema.
    for(int i=0;i<ROWS_A;i++){
        for(int j=0;j<2*COLUNAS_A;j++)
            if(matriz[i][j]<=0.000001 && matriz[i][j]>=-0.000001)
                matriz[i][j]=0;  
     } 
    
    printMatriz(matriz,ROWS_A,2*COLUNAS_A); // Imprimir a matriz escalonada
}

void inversa(float** matriz,int ROWS_A,int COLUNAS_A){
    int j,i=0,n,k,m,l;
    int linha_pivo=ROWS_A-1;
    
    for(j=COLUNAS_A-1;j>=0;j--){ // Percorrer cada coluna da matriz
        

    /* Verificar se o pivô inicial é zero e existe algum número diferente de 
     0 abaixo OU se toda a coluna é  zero;*/

        while(linha_pivo-i>0 && matriz[linha_pivo-i][j]==0){ 
            i++;
        }
        // Verificar se as linhas ainda não terminaram e achamos um elemento não nulo.
        if(linha_pivo-i>0){
            int aux= linha_pivo-i;
            // Vamos permutar a linha do pivô com a linha do elemento não nulo
            //  Caso o pivô já seja um elemento não nulo, iremos permutar a linha por ela pŕopria.
            for(k=0;k<2*COLUNAS_A;k++){ // PERMUTAÇÃO DE LINHAS
                double temp= matriz[linha_pivo][k];
                matriz[linha_pivo][k]=matriz[aux][k];
                matriz[aux][k]=temp;
            }
            for(m=linha_pivo-1;m>=0;m--){ // Operação elementar li ← li +klj , 
                double c= matriz[m][j] / matriz[linha_pivo][j]; // Calculando o valor do fator (seria o nosso "k")
                for(n=0;n<2*COLUNAS_A;n++){
                    matriz[m][n]+= -c * matriz[linha_pivo][n];    // aplicando a operação elementar em toda a linha        
                        }
            }
            // Dividir a linha inteira pelo pivô
        }

        float pivo= matriz[linha_pivo][j];
        for(int p=0;p<2*COLUNAS_A;p++)
            matriz[linha_pivo][p]=matriz[linha_pivo][p]/pivo;
        linha_pivo--;
        i=0; // Resetando nosso contador i para que seja utilizado na pŕoxima coluna

    }
    // Os dois FOR abaixo se trata de um mecanismo de arredondar números extremamente pŕoximos de 0 para 0.
    // Isto deve ser feito para evitar problemas lidando com frações que possam dar dizimas períodícas.
    // Por exemplo, caso algum número da matriz seja 0.0000000023456, aproximaremos para 0.
    // Se fizessemos na mão, o resultado daria 0 já que nós não dividimos frações (pois podem gerar erros), porém no computador há essas imprecisões
    // Lidar com números FLOAT pode ser perigoso, pois nem sempre eles podem ser devidamente convertidos para binário e pode acabar gerando esse problema.
    for(int i=0;i<ROWS_A;i++){
        for(int j=0;j<2*COLUNAS_A;j++)
            if(matriz[i][j]<=0.000001 && matriz[i][j]>=-0.000001)
                matriz[i][j]=0;  
     } 
    

    printMatriz(matriz,ROWS_A,2*COLUNAS_A); // Imprimir a matriz escalonada
}

int main(){
    FILE* file; // Criação do ponteiro para o tipo arquivo (necessário para que seja possível ler um arquivo txt)
    int ROWS_A,COLUNAS_A; // Criação das variáveis
    //(ROWS_A = linhas da matriz, COLUNAS_A = colunas da matriz, 
    
    // Leitura das dimensões da matriz A
    puts("Linha da matriz A:");
    scanf("%d",&ROWS_A);
    puts("Coluna da matriz A:");
    scanf("%d",&COLUNAS_A);

    float** matriz1= malloc(ROWS_A*sizeof(float*));
    for(int i=0;i<ROWS_A;i++)
        matriz1[i]=malloc(2*COLUNAS_A*sizeof(float));
    
  
    // Abrindo o primeiro arquivo txt para ler
    file = fopen("matriz1.txt","r");
    lerMatriz(ROWS_A,COLUNAS_A,matriz1,file); // Chamando a função para ler o primeiro arquivo txt e salvar na variável matriz1
    fclose(file); // Fecha o arquivo
    matriz1=identidade(matriz1,ROWS_A,COLUNAS_A);


    puts("Escalonamento da matriz1:");
    // Chamando a função para escalonar a matriz. No seus parâmetros possui uma matriz, uma variável correspondente as linhas e outra para as colunas.
    escalonar(matriz1,ROWS_A,COLUNAS_A); 

    puts("Inversa da matriz:");
    inversa(matriz1,ROWS_A,COLUNAS_A);

    for(int i=0;i<ROWS_A;i++){
        free (matriz1[i]);
    }
    free (matriz1);
    
}
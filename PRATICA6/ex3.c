#include <stdio.h>
#include "pratica6.h"

void trianguloFloyd(int N){
    int linha = 0;
    int colunas = 0;
    int numero = 0;
    for(linha = 1; linha <= N; linha++){
        for(colunas = 1; colunas <= linha; colunas++){
            numero++;
            printf("%d", numero);
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int N= 0;
    printf("Digite o numero de linhas do seu triangulo de Floyd:\n");
    scanf("%d", &N);
    trianguloFloyd(N);
    return 0;
}
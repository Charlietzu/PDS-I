#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%i\n", vetor[i]);
    }
}

int somaVetor(int vetor[], int n){
    int resultado;
    int i = n - 1;
    if(i < 0){
        return 0;
    } else {
        resultado = vetor[i]+ somaVetor(vetor, n - 1);
    }
    return resultado;
}

int main(){
    srand(time(NULL));
    int n;
    int vetor[10];

    printf("Digite um numero inteiro:");
    scanf("%i", &n);

    for(int i = 0; i < n; i++){
        vetor[i] = 1+ rand()% 4;
    }
    
    imprimeVetor(vetor, n);

    printf("A soma dos valores do vetor eh %i\n", somaVetor(vetor, n));

    return 0;
}
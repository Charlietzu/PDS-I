#include <stdio.h>
#include <stdlib.h>

void alocaMatriz(int n){
    int i, j;
    float **p;
    /* alocando dinamicamente um vetor de n posicões
    de ponteiros para ponteiros 
    de pontos flutuantes */ 
    p = (float **) malloc(n * sizeof(float *));

    for(i = 0; i < n; i++){
        /* alocando para cada posição i do vetor de 
        ponteiros para ponteiros outro vetor de
        tamanho n de floats */
        p[i] = (float *) malloc(n * sizeof(float));
        for(j = 0; j < n; j++){
            // atribuindo 0.0 a cada item da matriz
            p[i][j] = 0.0;
            printf("%.1f ", p[i][j]);
        }
        printf("\n");
    }
}

int main(){
    alocaMatriz(4);
    return 0;
}
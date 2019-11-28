#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

double **le_matriz_simetrica(char *nome_arquivo, int tamanho){
    int i, j;
    FILE *fd = fopen(nome_arquivo, "r");
    
    if(!fd){
        abort();
    }

    //alocando um vetor de TAMANHO posições contendo cada posição outro ponteiro
    double **M = (double **)malloc((tamanho) * sizeof(double));
    if(M == NULL){
        abort();
    }

    for(i = 0; i < tamanho; i++){
        //alocando vetores para conter as colunas da matriz
        //Ponteiro para definir o tamanho das linhas (i + 1)
        //1
        //1 2
        //1 2 3
        //1 2 3 4
        M[i] = (double*)malloc((i + 1) * sizeof(double));
        if(M==NULL){
            abort();
        }
        for(j = 0; j <= i; j++){
            fscanf(fd, "%f", &M[i][j]);
        }
    }
    free(M);
    fclose(fd);

}
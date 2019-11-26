#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TAM 100

int main(){
    float m[MAX_TAM][MAX_TAM];
    int i, j, numLinhas, numColunas;

    FILE *arquivo;
    arquivo = fopen("numeros.txt", "r");

    if(arquivo == NULL){
        printf("\nErro ao ler arquivo!");
        return 0;
    }

    while(!feof(arquivo)){
        fscanf(arquivo, "%d %d", &numLinhas, &numColunas);
        for(i = 0; i < numLinhas; i++){
            for(j = 0; j < numColunas; j++){
                fscanf(arquivo, "%f", &m[i][j]);
            }
        }
    }
    for(i = 0; i < numLinhas; i++){
        for(j = 0; j < numColunas; j++){
            printf("%.1f ", m[i][j]);
        }
        printf("\n");
    }
    fclose(arquivo);
    return 0;
}
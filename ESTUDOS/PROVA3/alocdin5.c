#include <stdio.h>
#include <stdlib.h>



int main(){
    /* ponteiro (1 nível): cria um vetor
       int *p = (int *) malloc(5*sizeof(int)); */

    /* ponteiro para ponteiro (2 níveis): permite criar uma matriz
       int **m; */

    /* RESUMO: int* -> permite criar um array de int
               int** -> permite criar um array de int* */

    int **p; //2 níveis
    int i, j, n;

    //1º malloc -> cria as linhas da matriz
    //cria um array de ponteiros (int *)
    p = (int **)malloc(n * sizeof(int *));
    //for percorrendo cada array criado no 1º malloc
    for(i = 0; i < n; i++){
        //2º malloc -> cria as colunas da matriz
        //cria um array de int
        p[i] = (int *) malloc(n * sizeof(int));
        for(j = 0; j < n; j++){
            //lê a matriz de inteiros
            scanf("%d", &p[i][j]);
        }
    }
    //limpando a memória
    for(i = 0; i < n; i++){
        free(p[i]);
    }
    free(p);


    return 0;
}
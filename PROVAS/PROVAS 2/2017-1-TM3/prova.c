#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zeraMatriz(int M[][10], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            M[i][j] = 0;
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int initMatriz(int M[][10], int n){
    zeraMatriz(M, n);
    printf("\n");
    int cont = 0, i, j;
    while(cont <= n){
      /*  i = rand()%n;
        j = rand()%n;
        if(M[i][j] == 0){
            M[i][j] = 1;
            cont++;
        }*/
        M[rand()%n][rand()%n] = 1;
        cont++;
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    int M[10][10];
    initMatriz(M, 10);
    return 0;
}
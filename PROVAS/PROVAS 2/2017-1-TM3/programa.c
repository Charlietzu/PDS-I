#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zeraMatriz(int M[][10], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            M[i][j] = 0;
        }
    }
}

void initMatriz(int M[][10], int n){
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


typedef struct Jogador{
    int n;
    int id;
    int navios;
    int M[10][10];
}Jogador;

void initJogador(Jogador *j, int id){
    j->id = id;
    j->n = 0;
    j->navios = 10;
    initMatriz(j->M, 10);
}

void ataca(Jogador *j1, Jogador *j2){
    int i = rand()%9, j = rand()%9;
    if(j2->M[i][j] == 1){
        j2->M[i][j] == 0;
        j2->navios--;
    }
    j1->n++; 
}

int main(){
    srand(time(NULL));
    Jogador j1, j2;
    initJogador(&j1, 1);
    initJogador(&j2, 2);

    while(j1.navios > 0){
        ataca(&j1, &j2);
        if(j2.navios > 0){
            ataca(&j2, &j1);
        } else {
            printf("\n Vencedor: %d (%d ataques)", j1.id, j1.n);
            return 0;
        }
    }
    printf("\nVencedor: %d (%d ataques)", j2.id, j2.n);
    return 0;
}
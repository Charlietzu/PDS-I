#include <stdio.h>

/*
int enesimoFibonacci(int N){
    int pri_termoAnterior = 1;
    int seg_termoAnterior = 0;
    int termoAtual = 0;
    int iteracoes = 2;

    while(iteracoes < N){
        termoAtual = pri_termoAnterior + seg_termoAnterior;
        seg_termoAnterior = pri_termoAnterior;
        pri_termoAnterior = termoAtual;
        iteracoes++;
    }
    return termoAtual;
}
*/

void main() {
    int numero;

    scanf("%i", &numero);
    printf("%i", enesimoFibonacci(numero));
}
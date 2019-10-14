#include <stdio.h>

/*
int somaImpares(int N){
    int soma = 0;
    while(N > 0){
        if(N % 2 != 0){
            soma = soma + N; 
        }
        N--;
    }
    return soma;
}
*/

void main() {
    int numero;
    scanf("%i", &numero);
    printf("%i", somaImpares(numero));
}
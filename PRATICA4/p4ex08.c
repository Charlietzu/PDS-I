#include <stdio.h>

/*
double fatorial(int N){
    int fatorial = 1;
    while(N != 0){
        fatorial = fatorial * N;
        N--;
    }
    return (double) fatorial;
}
*/

void main() {
    int numero;
    scanf("%i", &numero);
    printf("%f", fatorial(numero));
}
#include <stdio.h>

int somaNumerosDiv3ou5(int N){
    int soma = 0;
    while (N > 0){
        if ((N % 3 == 0 && N % 5 == 0) || (N % 3 != 0 && N % 5 != 0)){
            N--;
        } else {
            soma = soma + N;
            N--;
        }
    }
    return soma;
}

void main(){
    int numero;
    scanf("%i", &numero);
    printf("%i", somaNumerosDiv3ou5(numero));
}
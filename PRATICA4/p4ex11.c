#include <stdio.h>

int numeroDivisores(int N){
    int denominador = N;
    int numDivisores = 0;

    while(denominador >= 1){
        if(N % denominador == 0){
            numDivisores++;
        }
        denominador--;
    }
    return numDivisores;
}

void main(){
    int numero;
    scanf("%i", &numero);
    printf("%i", numeroDivisores(numero));
}
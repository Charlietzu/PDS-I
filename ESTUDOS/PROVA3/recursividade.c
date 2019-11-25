#include <stdio.h>

int fatorial(int x){
    int resultado;

    if(x == 0){ //caso trivial vai parar o loop
        resultado = 1;
    } else {
        resultado = x * fatorial(x - 1);
    }
    return resultado;
}

int main(){

    int numero, resultado;

    printf("Digite um numero inteiro:");
    scanf("%i", &numero);

    resultado = fatorial(numero);

    printf("\nO fatorial eh\n%i", resultado);

    return 0;
}
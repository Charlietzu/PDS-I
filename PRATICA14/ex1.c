#include <stdio.h>
#include <math.h>

int somaNCubos(int n){
    int resultado = 0;

    if(n == 0){
        return 0;
    }else{
        resultado = pow(n,3) + somaNCubos(n - 1);
    }
    return resultado;
    
}

int main(){
    int numero, resultado;

    printf("Digite um numero inteiro:");
    scanf("%i", &numero);

    resultado = somaNCubos(numero);

    printf("\nA soma dos %i primeiros cubos eh %i", numero, resultado);

    return 0;
}
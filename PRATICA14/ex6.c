#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y){
    int resultado, contador = y;
    if(contador == 1){
        return x;
    } else {
        resultado = x * potencia(x, contador - 1);
        //3 (3) * 
        //3 (2) * 9 = 27
        //3 (1) * 3 = 9
        //3 (0) 
    }
    return resultado;
}

int main(){
    int x, y;

    printf("Digite uma base:\n");
    scanf("%i", &x);
    printf("Digite uma potencia:\n");
    scanf("%i", &y);

    printf("O resultado de %i elevado a %i eh %i\n", x, y, potencia(x, y));

    return 0;
}
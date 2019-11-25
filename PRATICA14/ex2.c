#include <stdio.h>

void imprimeSeqNaturais(int n){
    //3 3
    //2 2
    //1 1
    //0 0
    if(n == 0){
        printf("%i\n", n);
    } else {
        imprimeSeqNaturais(n - 1);
        printf("%i\n", n);
    }
    
}

int main(){
    int numero;

    printf("Digite um numero inteiro:");
    scanf("%i", &numero);

    printf("A sequencia de 0 ate %i eh\n", numero);
    imprimeSeqNaturais(numero);

    return 0;
}
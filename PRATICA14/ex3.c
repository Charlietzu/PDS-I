#include <stdio.h>

void imprimeSeqNaturais(int n){
    //3 3
    //2 2
    if(n == 0){
        printf("%i\n", n);
    } else {
        printf("%i\n", n);
        imprimeSeqNaturais(n - 1);
    }
    
}

int main(){
    int numero;

    printf("Digite um numero inteiro:");
    scanf("%i", &numero);

    printf("A sequencia de %i ate 0 eh\n", numero);
    imprimeSeqNaturais(numero);

    return 0;
}
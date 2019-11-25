#include <stdio.h>
#include <stdlib.h>

void criaVetor(int n){
    int vetor[100];
}

void retornaInvertido(int n, int tam){
    int i = n - 1;
    if(i == 0){
        printf("%c", str[0]);
    } else {
        printf("%c", str[i]);
        imprimeInvertido(str, n - 1);
    }

}

int main(){
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);

    int n  = tamanhoString(linha);
    imprimeInvertido(linha , n);

    return 0;
}
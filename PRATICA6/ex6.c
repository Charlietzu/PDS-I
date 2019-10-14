#include <stdio.h>
#include "pratica6.h"
int palindromo(char str[]){
    int n = 0;
    int i = 0;
    int tamanho = 0;
    for(n = 0; str[n] != '\0'; n++){
        tamanho++;
    }
    char palavraContrario[tamanho];
    int j = 0;
    i = tamanho - 1;
    for(i; i >= 0; i--){
        while(j <= tamanho){
            palavraContrario[j] = str[i];
            j++;
        }
        break;
    }
    if(str == palavraContrario){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
    if(palindromo(linha) == 1){
        printf("A palavra %s e um palindromo", linha);
    } else {
        printf("A palavra %s nao e um palindromo", linha);
    }
    return 0;
}
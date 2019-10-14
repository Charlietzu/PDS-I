#include <stdio.h>

int main(){
    int n = 0;
    int tamanho = 0;
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
    for(n = 0; linha[n] != '\0'; n++){
        tamanho++;
    }
    printf("%d", tamanho);
    return 0;
}
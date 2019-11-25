#include <stdio.h>
#include <stdlib.h>

int tamanhoString(char str[]){
    int n = 0;
    for(int i = 0; str[i] != '\0'; i++){
        n++;
    }
    return n;
}

void imprimeInvertido(char str[], int n){
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
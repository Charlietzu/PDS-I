#include <stdio.h>
#include "pratica6.h"
void converteString(char str[]){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
    }
}

int main(){
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
    converteString(linha);
    printf("%s", linha);
    
    return 0;
}
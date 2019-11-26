#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("string.txt", "a");

    if(file == NULL){
        printf("O arquivo não foi encontrado.");
        return 0;
    }
    
    char frase[] = "Segundo teste";
    fputs(frase, file);

    char caractere = '3';
    fputc(caractere, file);

    fclose(file);
    printf("\n");
    return 0;
}
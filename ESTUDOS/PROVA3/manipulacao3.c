#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("string.txt", "r");

    if(file == NULL){
        printf("O arquivo não foi encontrado.");
        return 0;
    }

    char frase[100];
    //fgets -> file get string (string, tamanho dela, ponteiro de arquivo)
    //lê uma frase até encontrar a quebra de linha, caso não seja usado o "!= NULL"
    //fscanf lê até encontrar um espaço
    while(fgets(frase, 100, file) != NULL){
        printf("%s", frase);
    }
    fclose(file);
    printf("\n");
    return 0;
}
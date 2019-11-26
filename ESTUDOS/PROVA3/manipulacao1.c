#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    /*  
        fopen("Local do arquivo(é necessário usar 2 contra-barras na linguagem C, caso
        seja inserido o endereço, ele pega o endereço do programa atual)", "letra-ação")
        Letras-ação mais comuns:
        r -> read/ler
        w -> write/escrever
        a -> append/alterar
        
        usar o "w" faz com que o arquivo seja criado caso não exista, e substitue todo o conteúdo
        do arquivo com o que for descrito no programa.
    */
    file = fopen("arquivo.txt", "w");
    //file printf = fprintf
    fprintf(file, "teste de escrita.");
    //fechar e salvar o arquivo
    fclose(file);

    return 0;
}
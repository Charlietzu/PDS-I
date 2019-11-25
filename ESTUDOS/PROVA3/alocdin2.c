#include <stdio.h>
#include <stdlib.h>

int main(){
    //malloc = memory allocation -> retorna um ponteiro do tipo void(aponta pra um endereço mas não sabe o tipo de dado deste endereço)
    //para isso é necessário utilizar um type casting (int *) -> ponteiro do tipo inteiro
    int *p = (int *) malloc(sizeof(int));

    *p = 1000;
    printf("%d", *p);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){   
    int *p = (int *) calloc(5, sizeof(int));
    //N elementos do tamanho int calloc(N, sizeof(int))
    //inicializa o bloco de memória com 0
    
    for(int i = 0; i < 5; i++){
        printf("Endereco de p%i = %p | Valor de p%i = %i\n", i, &p[i], i, p[i]);
    }

    return 0;
}
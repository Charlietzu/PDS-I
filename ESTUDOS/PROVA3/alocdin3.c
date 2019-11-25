#include <stdio.h>
#include <stdlib.h>

int main(){   
    int *p = (int *) malloc(sizeof(int));

    *p = 1000;
    //o ponteiro p continua apontando para o mesmo lugar, portanto podemos usar o free() antes do printf
    //somente desalocamos a memória
    free(p);
    printf("%d", *p);

    return 0;
}
#include <stdio.h>

void main() {
    int x = 0;
    //coloque seu código aqui:
    int *endereco_x;

    endereco_x = &x;
    *endereco_x = 3;
    
    printf("%d", x);
}

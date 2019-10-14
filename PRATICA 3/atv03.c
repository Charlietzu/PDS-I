#include <stdio.h>

void main() {
    float x,y;
    scanf("%f %f", &x, &y);
    //coloque seu código aqui:
    float aux;
    aux = x;
    x = y;
    y = aux;
        
    printf("\nx = %f\ny = %f", x, y);
}

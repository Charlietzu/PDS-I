#include <stdio.h>
#include <math.h>

/*
float calculaMedia(int x, int y, int z, int operacao){
    int mult = (x * y * z);
    if(operacao == 1) {
        //raiz cubica -> pow(x, 1.0/3.0)
        return pow(mult, 1.0 / 3.0);
    } else if(operacao == 2){
        return ((2 * y) + (3 * z) + x) / 6.0;
    } else if(operacao == 3){
        return 3 / ((1 / x) + (1 / y) + (1 / z));
    } else {
        return (x + y + z) / 3.0;
    }
}
*/

void main() {
    int x,y,z,operacao;
    scanf("%i %i %i %i", &x, &y, &z, &operacao);
    printf("%f", calculaMedia(x,y,z,operacao));
}
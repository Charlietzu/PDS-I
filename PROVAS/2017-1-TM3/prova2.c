#include <stdio.h>

float arredonda(float x){
    float pFracionaria = x - (int)x;
    if(pFracionaria < 0.25){
        return (int) x;
    } else if (pFracionaria >= 0.25 && pFracionaria < 0.75){
        return x - pFracionaria + 0.5;
    } else {
        return (int)x + 1;
    }
}

void arredondaNotas(float *endNota1, float *endNota2, float *endNota3){
    *endNota1 = arredonda(*endNota1);
    *endNota2 = arredonda(*endNota2);
    *endNota3 = arredonda(*endNota3);
}

void main(){
    float nota1, nota2, nota3;
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    arredondaNotas(&nota1, &nota2, &nota3);
    printf("\n%f %f %f", nota1, nota2, nota3);
}
#include <stdio.h>
#include "atv01.h"

float parteInteira(float x){
    return (int) x;
}

float parteFracionaria(float x){
    return x - (int) x;
}

float divInts(int x, int y){
    return (float) x / (float) y;
}

int main(){
    printf("parteInteira1 = %f\n", parteInteira(-3.142321));
    printf("parteFracionaria1 = %f\n", parteFracionaria(-3.142321));
    printf("divInts1 = %f\n", divInts(7,2));
    printf("parteInteira2 = %f\n", parteInteira(5.35));
    printf("parteFracionaria2 = %f\n", parteFracionaria(5.35));
    printf("divInts2 = %f\n", divInts(9,2));
    printf("parteInteira3 = %f\n", parteInteira(10.768));
    printf("parteFracionaria3 = %f\n", parteFracionaria(10.768));
    printf("divInts3 = %f\n", divInts(17,2));
    return 0;
}
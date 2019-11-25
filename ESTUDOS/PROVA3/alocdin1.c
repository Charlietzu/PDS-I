#include <stdio.h>
#include <stdlib.h>

struct x{
    int a;
    int b;
    int c;
}typedef x;

int main(){

    int vetor[10];
    x estrutura;

    printf("%li",sizeof(estrutura));

    return 0;
}
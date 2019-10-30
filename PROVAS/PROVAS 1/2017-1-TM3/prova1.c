#include <stdio.h>

int ints2Exceed(int a, int b){
    int qtdNum = 0;
    int soma = 0;
    while(soma < b){
        soma = soma + a;
        a++;
        qtdNum++;
    }
    return qtdNum;
}

void main() {
    int x, z;
    do {
        scanf("%i %i", &x, &z);
    }while(x >= z);
    printf("%d", ints2Exceed(x,z));
}
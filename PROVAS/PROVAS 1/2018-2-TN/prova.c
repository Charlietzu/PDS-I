#include <stdio.h>

int primosEntreSi(unsigned int x, unsigned int y){
    int numDivisor = 1;
    int qtdDivisores = 0;

    while(numDivisor != x && numDivisor != y){
        if(x % numDivisor == 0 && y % numDivisor == 0){
            qtdDivisores++;
        }
        numDivisor++;
    }
    if(qtdDivisores > 1){
        return 0;
    } else {
        return 1;
    }
}

int phi(unsigned int x){
    int numPrimo = 1;
    int qtdNum = 0;
    while(numPrimo < x){
        if(primosEntreSi(x, numPrimo) == 1){
            qtdNum++;
        }
        numPrimo++;
    }
    return qtdNum;
}

void maiorPhi(int *end_var1, int *end_var2){
    int phi1 = phi(*end_var1);
    int phi2 = phi(*end_var2);
    if(phi1 > phi2){
        *end_var2 = phi1;
    } else {
        *end_var1 = *end_var2;
        *end_var2 = phi2;
    }
}

void main(){
    int a, b;
    printf("\nDigite dois valores positivos");
    do {
        scanf("%d %d", &a, &b);
    } while(a <= 0 || b <= 0);
    maiorPhi(&a, &b);
    printf("\n o numero %d tem o maior phi: %d", a, b);
}
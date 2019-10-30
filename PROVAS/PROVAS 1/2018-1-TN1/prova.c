#include <stdio.h>

int ehPrimo(int N){
    int numDivisor = 1;
    int primo = 0;
    while(numDivisor <= N){
        if(numDivisor % N == 0){
            primo++;
        }
        numDivisor++;
    }
    if(primo > 2){
        return 0;
    } else {
        return 1;
    }
}

void proximoPrimo(int *end_n){
    ++*end_n;
    while(ehPrimo(*end_n) == 0){
        *end_n++;
    }
}

void decompoe(int N){
    int primo = 2;
    int numeroInicial = N;
    while(N != 1){
        if(N % primo == 0){
            N = N/primo;
            printf("%i\n", primo);
        } else {
            proximoPrimo(&primo);
        }
    }
    printf("%i\n", numeroInicial);
}

void main() {
    int x;
    do {
        scanf("%i", &x);
    } while (x <= 0);
    decompoe(x);
}
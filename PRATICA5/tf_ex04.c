#include <stdio.h>
#include "tf.h"

/*int hotpo(unsigned int N){
    if(N % 2 == 0){
        N = N/2;
    } else {
        N = (N *3) + 1;
    }
    return N;
}

int collatz(unsigned int N){
    int iteracao = 0;
    while(N != 1){
        N = hotpo(N);
        iteracao++;
    }
    return iteracao;
}

void leIntervalo(int *endmin, int *endmax){
    int min, max;
    do {
        scanf("%i %i", &min, &max);
    } while ((min < 0 && max < 0) && (min > max));
    *endmin = min;
    *endmax = max;
}*/

void main() {
    int a, b;
    leIntervalo(&a, &b);
    int c, max_n, max_c = 0;
    while(a <= b){
        c = collatz(a);
        if(c > max_c){
            max_c = c;
            max_n = a;
        }
        a++;
    }
    printf("\nnumero com a maior sequencia de Collatz: ");
    printf("%d (%d passos)", max_n, max_c);
}
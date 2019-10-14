#include <stdio.h>
#include "tf.h"

int hotpo(unsigned int N){
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
}

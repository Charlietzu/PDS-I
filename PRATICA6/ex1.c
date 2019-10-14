#include <stdio.h>
#include <math.h>
#include "pratica6.h"

float fatorial(float N){
    int fatorial = 1.0;
    int i = 0;
    for(i = N; i >= 1.0; i--){
        fatorial = fatorial * i;
    }
    return fatorial;
}

float euler(int N){
    float euler = 1.0;
    int i = 0;
    for(i = 1; i <= N; i++){
        if(euler < pow(10.0, -6.0)){
            return euler;
        }
        euler = euler + (1.0/fatorial(i));
    }
}

int main(){
    int N = 0;
    printf("Digite um numero:\n");
    scanf("%d", &N);
    printf("%f\n", euler(N));
    return 0;
}
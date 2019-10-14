#include <stdio.h>

int mmc(unsigned int x, unsigned int y){
    int varMMC = 1;
    int divisorAtual = 2;

    while(x != 1 || y != 1){
        if(x % divisorAtual == 0 || y % divisorAtual == 0){
            varMMC = varMMC * divisorAtual; //12
        }
        if(x % divisorAtual == 0) {
            x = x / divisorAtual; //3
        }
        if(y % divisorAtual == 0){
            y = y / divisorAtual; //1
        }  
        if(x % divisorAtual != 0 && y % divisorAtual != 0){
            divisorAtual++; //4
        } 
    }
    return varMMC;
}

int mdc(unsigned int x, unsigned int y){
    int divisorAtual = 1;
    int divisorComum = 1;
    while(divisorAtual <= x && divisorAtual <= y){
        if(x % divisorAtual == 0 && y % divisorAtual == 0){
            divisorComum = divisorAtual;
        }
        divisorAtual++;
    }
    return divisorComum;
}

void main() {
    int num1, num2;
    do {
        scanf("%i %i", &num1, &num2);
    } while(num1 <= 0 || num2 <= 0);

    printf("O MDC eh: %i\n", mdc(num1, num2));
    printf("O MMC eh: %i\n", mmc(num1, num2));

}
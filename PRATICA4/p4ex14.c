#include <stdio.h>

/*
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
*/
void main() {
    int num1, num2;
    scanf("%i %i", &num1, &num2);
    printf("%i", mmc(num1, num2));
}
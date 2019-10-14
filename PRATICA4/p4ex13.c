#include <stdio.h>
/*
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
*/
void main(){
    int num1, num2;
    scanf("%i %i", &num1, &num2);
    printf("%i", mdc(num1, num2));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int ehPotencia2(int n){
    if(n % 2 != 0){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    ehPotencia2(n/2);
}

void imp2Cont(int i, int n){
    if(i == n){
        printf("%d\n", n);
        return;
    }
    printf("%d\n", i);
    imp2Cont(i+1,n);
    printf("%d\n", i);

}

void trim(char **str){
    int n = tamString(*str);
    int ini = 0, fim = n-1, i;
    while((*str)[ini] == ' '){
        ini++;
    }
    while((*str)[fim] == ' '){
        fim--;
    }
    char *strAuxiliar = (char*) malloc((fim-ini+2)*sizeof(char));
    for(i = ini; i<=fim; i++){
        strAuxiliar[i - ini] = (*str)[i];
    }
    strAuxiliar[i-ini]= '\0';
    free(*str);
    *str = strAuxiliar;
}

int main(){

    imp2Cont(2,5);

    return 0;
}
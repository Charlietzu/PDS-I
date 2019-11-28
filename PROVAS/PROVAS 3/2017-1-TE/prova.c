#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int somaNaturais(int n){
    if(n == 1 || n == 0){
        return n;
    }
    return n + somaNaturais(n - 1);
}

int ehPotencia(int n){
    if(n % 2 != 0){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    ehPotencia(n/2);
}

int numEspacos(char *str){
    if(str[0] == '\0'){
        return 0;
    }
    if(str[0] == ' '){
        return 1 + numEspacos(str+1);
    }
    return 0 + numEspacos(str+1);
}

void cortaString(char **str, int ini, int fim){
    char **aux;
    *aux = *str;
    
}

int main(){
    printf("%d", ehPotencia(14));

    return 0;
}
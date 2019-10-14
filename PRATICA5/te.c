#include <stdio.h>
#include "te.h"

int ehPotencia2(int x){
    int resto;
    while (x != 1){
        resto = x % 2;
        if(resto == 0){
            x = x / 2;
        } else {
            return 0;
        }
    }
    return 1;
}

void ordena(int *end_var1, int *end_var2){
    int aux;
    if(*end_var1 > *end_var2){
        aux = *end_var1;
        *end_var1 = *end_var2;
        *end_var2 = aux;
    }
}
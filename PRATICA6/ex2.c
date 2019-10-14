#include <stdio.h>
#include "pratica6.h"

int calculaConceito(int nota){
    char conceito = ' ';
    switch(nota){
        case 0:
            conceito = 'F';
            break;
        case 1:
            conceito = 'F';
            break;
        case 2:
            conceito = 'F';
            break;
        case 3:
            conceito = 'F';
            break;
        case 4:
            conceito = 'F';
            break;
        case 5:
            conceito = 'E';
            break;
        case 6:
            conceito = 'D';
            break;
        case 7:
            conceito = 'C';
            break;
        case 8:
            conceito = 'B';
            break;
        case 9:
            conceito = 'A';
            break;
        case 10:
            conceito = 'A';
            break;
    }
    return conceito;
}

int main(){
    int nota = 0;
    printf("Digite sua nota:\n");
    scanf("%i", &nota);
    printf("\n%c", calculaConceito(nota));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 100;

    int *p1;
    int **p2;

    p1 = &var;
    p2 = &p1;

    printf("valor de var = %d\n", var);
    printf("valor de p1 (retorna o valor de var) = %d\n", *p1);
    printf("valor de p2 (retorna o valor de var) = %d\n", **p2);
    printf("\n");
    printf("endereco de var = %d\n", &var);
    printf("endereco de p1 = %d\n", &p1);
    printf("endereco de p2 = %d\n", &p2);
    printf("\n");
    printf("endereco de var = %d\n", &var);
    printf("p1 aponta para (retorna o endereco de var) = %d\n", p1);
    printf("p2 aponta para (retorna o endereco de p1) = %d\n", p2);
    printf("\n");
    printf("valor de var = %d\n", var);
    printf("valor de p1 (retorna o valor de var) = %d\n", *p1);
    printf("valor de p2 (retorna o endereco de p1) = %d\n", *p2);
    

    return 0;
}
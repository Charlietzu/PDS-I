#include <stdio.h>
#include <stdlib.h>
#define MAXCLIENTES 50
#define MAXPRODUTOS 100
#define MAXESTOQUE 3
#define MAXCOMPRAS 20

void letrasAusentes(char str[]){
    int i, j = 0, cont = 0;
    char alf[27];
    for(i = 97; i < 123; i++){
        alf[j] = i;
        j++;
    }

    for(i = 0; i <= 26; i++){
        cont = 0;
        for(j = 0; str[j] != '\0'; j++){
            if(alf[i] == str[j]){
                cont = 1;
                break;
            }
        }
        if(cont == 0)
            printf("\n%c", alf[i]);   
    }
    
}

typedef struct Produto{
    int id;
    int estoque;
    float preco;
}Produto;

float randFloat(int min, int max){
    return min + (max-min)*((float)rand()/RAND_MAX);
}

void initProduto(int min, int max){
    return min + (max-min) + ((float)rand()/RAND_MAX);
}

void initProduto(Produto *p, int cod){
    p->id = cod;
    p->estoque = rand()%MAXESTOQUE;
    p->preco = randFloat(1, 100);

}

int estoqueLoja(Produto p[], int n){
    int i, cont = 0;
    for(i = 0; i <= n; i++){
        cont += p[i].estoque;
    }
    return cont;
}

int main() {
    

    return 0;
}
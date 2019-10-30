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

int simulaCompra(Produto p[], int n){
    float total = 0;
    //variável para definir um produto específico
    int prod;
    //numero de produtos que o cliente irá comprar
    int numCompra = rand()%MAXCOMPRAS;
    //estoque total
    int estoqueTotal = estoqueLoja(p, n);
    while(numCompra > 0 && estoqueTotal > 0){
        //produto aleatório dentro dos n produtos diferentes que a loja vende
        int prod = rand()%n;
        if(p[prod].estoque > 0){
            p[prod].estoque--;
            numCompra--;
            estoqueTotal--;
            total = total + p[prod].preco;
        } //else {
           // printf("\nestoque produto %d acabou!", prod);
        //}
    }
    //if(numCompra == 0){
    //    printf("\nNão temos mais produtos");
    //}
    return total;
}

int main() {
    int i = 0, numProdutos = 0, numClientes = 0;
    Produto p[1000];
    for(i = 0; i < 1000; i++){
        initProduto(&p[i], i);
        //printf("produto %d -> / estoque: %d / preco: %f\n", p[i].id, p[i].estoque, p[i].preco);
    }
    numProdutos = 1+rand()%MAXPRODUTOS;
    numClientes = rand()%MAXCLIENTES;

    printf("Faturamento do dia: %d\n", simulaCompra(p, 1000));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Video{
    int id;
    int likes;
    int ndislikes;
    int views[10];
}Video;

void preencheVideo(Video *v1, int id){
    v1->id = id;
    v1->likes = rand();
    v1->ndislikes = rand();
    for(int i = 0; i <= 9; i++){
        v1->views[i] = rand() * exp(-i);
    }
}

int ehTrending(Video v){
    int i, trending = 0;
    for(i = 1; i <= 9; i++){
        if(v.views[i] > v.views[i-1]){
            trending = 1;
        } else {
            return trending;
        }
    }
    return trending;
}

void troca(Video v[], int i, int j){
    Video aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void afastaRuins(Video v[], int *n){
    int i;
    for(i = 0; i < *n; i++){
        if(((float)v[i].likes / v[i].ndislikes) < 1){
            troca(v, i, *n);
            i--;
            *n = *n - 1;
        }
    }
}

int main(){
    Video v;
    preencheVideo(&v, 1);
    for(int i = 0; i < 9; i++){
        printf("Quantidade de views na posicao %d -> %d\n", i, v.views[i]);
    }

    if(ehTrending(v) == 1){
        printf("O video eh trending");
    } else {
        printf("O video nao eh trending");
    }
    return 0;
}
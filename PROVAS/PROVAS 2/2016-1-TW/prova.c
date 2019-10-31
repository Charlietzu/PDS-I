#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAM 300
#define MAXMOV 10
#define MAXTIMER 10
#define MAXRAIO 10
#define NPLAYERS 20
#define MAXTAMNOME 20

typedef struct Bomb{
    int x;
    int y;
    int raio;
    int timer;
}Bomb;

typedef struct Bomber{
    int x;
    int y;
    int vivo;
    char nome[100];
    Bomb b;
}Bomber;

void preencheString(char *str, int maxtam){
    int i;
    for(i = 0; i < maxtam - 1; i++){
        str[i] = 97+rand()%26;
    }
    str[maxtam - 1] = '\0';
    printf("%s\n",str);
}

void preencheBomber(Bomber *p){
    p->x = rand()%TAM-1;
    p->y = rand()%TAM-1;
    preencheString(p->nome, MAXTAMNOME);
    p->b.timer = 1+rand()%MAXTIMER;
    p->vivo = 1;
}

int checkKill(Bomber *p, Bomb b){
    int eq1 = pow(p->x - b.x, 2);
    int eq2 = pow(p->y - b.y, 2);
    int d = sqrt(eq1 + eq2);
    if(d <= b.raio){
        p->vivo = 0;
        p->b.timer = 0;
        return 0;
    } else {
        p->vivo = 1;
        return 1;
    }
}

void moveBombers(Bomber p[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(p[i].vivo == 1){
            p[i].x += rand()%MAXMOV;
            p[i].y += rand()%MAXMOV;
        } 
    }
}

int checkAll(Bomber p[], int n){
    int i, contMorte = 0;
    for(i = 0; i < n; i++){
        if(checkKill(&p[i], p[i].b) == 0){
            contMorte++;
        }
    }
    return contMorte;
}

void checkBomb(Bomber *p){
    if(p->b.timer == 0){
        p->b.x == p->x;
        p->b.y == p->y;
        p->b.timer = 1+rand()%MAXTIMER;
        p->x = rand()%TAM;
        p->y = rand()%TAM;
    } else {
        p->b.timer--;
    }
}

int main(){
    srand(time(NULL));
    Bomber p[NPLAYERS];
    int alive = NPLAYERS, i;
    for(i = 0; i < NPLAYERS; i++){
        preencheBomber(&p[i]);
    }
    while(NPLAYERS > 1){
        moveBombers(&p, NPLAYERS);
       for(i = 0; i < NPLAYERS; i++){
           if(p[i].vivo == 1){
               checkBomb(&p[i]);
           }
           alive -= checkAll(&p[i], NPLAYERS);
       } 
    }

    for(i = 0; i < NPLAYERS; i++){
        if(p[i].vivo == 1){
            printf("\nwinner: %s:\n", p[i].nome);
            break;
        }
    }

    return 0;
}
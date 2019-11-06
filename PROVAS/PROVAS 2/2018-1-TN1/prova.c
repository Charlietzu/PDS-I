#include <stdio.h>
#define MAX_PALAVRAS 10

int tamStr(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int ehPalindromo(char s[]){
    int i, n = tamStr(s);
    for(i = 0; i < n/2; i++){
        if(s[i] != s[n - 1 - i]){
            return 0;
        }
    }
    return 1;
}

void lePalavra(char s[]){
    int i;
    do {
        scanf("%c", &s[i]);
        i++;
    }while(s[i-1] != '\n' && s[i-1] != ' ');  
    s[i - 1] = '\0';
}   

typedef struct Palavra{
    char palavra[100];
    int pali;
    int tam;
}Palavra;

void preenchePalavra(Palavra *p){
    p->palavra = lePalavra(p->palavra);
    p->tam = tamStr(p->palavra);
    p->pali = ehPalindromo(p->palavra);
}

float tamMedio(Palavra p[], int n){
    int i, soma = 0;
    for(i = 0; i < n; i++){
        soma += tamStr(p[i]);
    }
    return soma / n;
}

int main(){
    Palavra palavras[MAX_PALAVRAS];
    int i;

    for(i = 0; i < MAX_PALAVRAS; i++){
        preenchePalavra(&palavras[i]);
    }

    float media = tamMedio(p, MAX_PALAVRAS);
    for(i = 0; i < MAX_PALAVRAS; i++){
        if(tamStr(palavras[i]) > media && ehPalindromo(palavras[i]) == 1){
            printf("\n%s (%d)", palavras[i].palavra, palavras[i].tamanho);
        }
    }

    return 0;
}

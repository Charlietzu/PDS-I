#include <stdio.h>
#include <math.h>

float fatorial(float N){
    int fatorial = 1.0;
    int i = 0;
    for(i = N; i >= 1.0; i--){
        fatorial = fatorial * i;
    }
    return fatorial;
}

float euler(int N){
    float euler = 1.0;
    int i = 0;
    for(i = 1; i <= N; i++){
        if(euler < pow(10.0, -6.0)){
            return euler;
        }
        euler = euler + (1.0/fatorial(i));
    }
}

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

void trianguloFloyd(int N){
    int linha = 0;
    int colunas = 0;
    int numero = 0;
    for(linha = 1; linha <= N; linha++){
        for(colunas = 1; colunas <= linha; colunas++){
            numero++;
            printf("%d", numero);
            printf(" ");
        }
        printf("\n");
    }
}

void converteString(char str[]){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
    }
}

int palindromo(char str[]){
    int n = 0;
    int i = 0;
    int tamanho = 0;
    for(n = 0; str[n] != '\0'; n++){
        tamanho++;
    }
    char palavraContrario[tamanho];
    int j = 0;
    i = tamanho - 1;
    for(i; i >= 0; i--){
        while(j <= tamanho){
            palavraContrario[j] = str[i];
            j++;
        }
        break;
    }
    if(str == palavraContrario){
        return 1;
    } else {
        return 0;
    }
}
#include <stdio.h>

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
    int i = 0;
    do {
        scanf("%c", &s[i]);
        i++;
    }while(s[i] != '\n' && s[i] != ' ');
    s[i] = '\0';
}

int main(){
    char palavra[128] = "reviver";

    //printf("tamanho %d\n", tamStr(palavra));
    //printf("%d\n",ehPalindromo(palavra));
    lePalavra(palavra);
    printf("%s\n", palavra);
    return 0;
}
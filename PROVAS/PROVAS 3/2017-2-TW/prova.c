#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int tamString(char *str){
    //*str = str[0]
    if(*str == '\0'){
        return 0;
    }
    return 1 + tamString(str+1);
}

int somaDigitos(int n){
    if(n <= 9){
        return n;
    }
    return n % 10 + somaDigitos(n/10);
}

void geraPalindromo(char str[]){
    if(*str == '\0'){
        return;
    }
    printf("%c", *str);
    geraPalindromo(str+1);
    printf("%c", *str);
}

char* concatena(char *str1, char *str2){
    int tam1 = tamString(str1);
    int tam2 = tamString(str2);
    printf("%d\n", tam1);
    printf("%d\n", tam2);
    int tam3 = tam1 + tam2;
    char *str3 = (char*)malloc(tam3 * sizeof(char));
    int i;

    for(i = 0; i < tam3; i++){
        if(i < tam1){
            str3[i] = str1[i];
        } else {
            str3[i] = str2[i - tam1];
        }
    }

    str3[tam3] = '\0';
    free(str1);
    free(str2);
    return str3;
}

int main(){
    char str1[100] = "ca";
    char str2[100] = "io";

    char *str3 = concatena(str1, str2);
    printf("%s", str3);

    return 0;
}
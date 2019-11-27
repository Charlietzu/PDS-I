#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillStr(char **str){
    int tamanho = 1 + rand()%9;
    int i;
    *str = (char *)malloc(tamanho + 1 * sizeof(char));
    for(i = 0; i < tamanho - 1; i++){
        //*(str)[i] = 63 + rand()%27;
        *(str)[i] = 'A' + rand()%(1 + 'Z' - 'A');
        printf("%c", *(str)[i]);
    }
    *(str)[tamanho] = '\0';
}

int main(){
    srand(time(NULL));
    char *str[11];

    fillStr(str);

    return 0;
}
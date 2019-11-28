#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main(){
    FILE *arq;
    arq = fopen("asc2.txt", "w");

    int i;
    for(i = 0; i <= 127; i++){
        fprintf(arq, "%d %c\n", i, i);
    }
    fclose(arq);
    return 0;
}
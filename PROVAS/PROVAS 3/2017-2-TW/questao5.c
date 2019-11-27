#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int numEspacos(int n){
    if(n <= 9){
        return n;
    }
    return n % 10 + numEspacos(n/10);
}

int main(){
    FILE *arq, *arqw;
    int matricula, CPF;
    char buf[1000], *nome;
    //abre arquivo para leitura
    arq = fopen("func.dat", "r");

    //abre arquivo para escrita:
    arqw = fopen("out.dat", "w");

    while(!feof(arq)){
        fgets(buf, 1000, arq);
        matricula = atoi(strtok(buf, "|"));
        nome = strtok(NULL, "|");
        CPF = atoi(strtok(NULL, "|"));
        if(numEspacos(CPF) % 9 != 0){
            fprintf(arqw, "%d\n", matricula);
        }
    }
    fclose(arq);
    fclose(arqw);
    return 0;
}
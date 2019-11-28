#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int numEspacos(char *str){
    if(str[0] == '\0'){
        return 0;
    }
    if(str[0] == ' '){
        return 1 + numEspacos(str+1);
    }
    return 0 + numEspacos(str+1);
}

int main(){
    FILE *arq, *arqw;
    int matricula, numNomes;
    char buf[500], *nome;
    //abre arquivo para leitura
    arq = fopen("func.dat", "r");
    //abre arquivo para escrita
    arqw = fopen("out.dat", "w");

    while(!feof(arq)){
        fgets(buf, 500, arq);
        matricula = atoi(strtok(buf, "|"));
        nome = strtok(NULL, "|");
        numNomes = 1 + numEspacos(nome);
        fprintf(arqw, "%d | %d", matricula, numNomes);
    }
    fclose(arq);
    fclose(arqw);
}
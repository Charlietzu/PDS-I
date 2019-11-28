#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


int main(){
    FILE *arq;
    arq = fopen("alunos.txt", "r");

    char buf[1000];
    int matricula, nota;
    int maiorMatricula, maiorNota = -1;
    char *nome;

    while(!feof(arq)){
        fgets(buf, 1000, arq);
        matricula = atoi(strtok(buf, "#"));
        nome = strtok(NULL, "#");
        nota = atoi(strtok(NULL, "#"));
        if(nota > maiorNota){
            maiorNota = nota;
            maiorMatricula = matricula;
        }
    }
    printf("%d | %d", maiorMatricula, maiorNota);
    fclose(arq);

    return 0;
}
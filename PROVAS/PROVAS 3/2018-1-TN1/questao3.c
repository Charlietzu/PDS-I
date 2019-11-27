#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TAM 100

int main(){
    FILE *arquivo;
    arquivo = fopen("alunos.txt", "r");
    char buf[MAX_TAM];

    int matricula, nota;
    int maiorNota = -1, maiorMatricula = 0;
    char *nome;

    fgets(buf, MAX_TAM, arquivo);
    while(!feof(arquivo)){
        matricula = atoi(strtok(buf, "#"));
        nome = strtok(NULL, "#");
        nota = atoi(strtok(NULL, "#"));
        if(nota > maiorNota){
            maiorNota = nota;
            maiorMatricula = matricula;
        }
        fgets(buf, MAX_TAM, arquivo);
    }
    printf("%d %d", maiorMatricula, maiorNota);

    fclose(arquivo);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_TAM 100

int main()
{
    FILE *arquivoGAAL;
    FILE *arquivoAEDS;
    arquivoGAAL = fopen("GAAL.txt", "r");
    arquivoAEDS = fopen("AEDS.txt", "r");

    char registroGAAL[MAX_TAM];
    char registroAEDS[MAX_TAM];

    char op;
    int matricula;
    float nota1, nota2, notas = 2, media = 0;
    char *nome;

    do
    {
        printf("\nExibir a média das notas de cada aluno? (Y/N)");
        op = toupper(getche());
        if (op == 'Y')
        {
            printf("\nRegistro das notas de GAAL:\n");
            fgets(registroGAAL, MAX_TAM, arquivoGAAL);
            while(!feof(arquivoGAAL)){
                media = 0;
                matricula = atoi(strtok(registroGAAL, ","));
                nome = strtok(NULL, ",");
                nota1 = atof(strtok(NULL, ","));
                nota2 = atof(strtok(NULL, ","));
                media = (media + nota1 + nota2) / notas;
                printf("\n %d \t %s \t %.1f \t %.1f \t %.1f", matricula, nome, nota1, nota2, media);
                fgets(registroGAAL, MAX_TAM, arquivoGAAL);
            }
            fclose(arquivoGAAL);
            printf("\n");

            printf("\nRegistro das notas de AEDS:\n");
            fgets(registroAEDS, MAX_TAM, arquivoAEDS);
            while(!feof(arquivoAEDS)){
                media = 0;
                matricula = atoi(strtok(registroAEDS, ","));
                nome = strtok(NULL, ",");
                nota1 = atof(strtok(NULL, ","));
                nota2 = atof(strtok(NULL, ","));
                media = (media + nota1 + nota2) / notas;
                printf("\n %d \t %s \t %.1f \t %.1f \t %.1f", matricula, nome, nota1, nota2, media);
                fgets(registroAEDS, MAX_TAM, arquivoAEDS);
            }
            fclose(arquivoAEDS);
            printf("\n");
        }
        else if (op == 'N')
        {
            printf("\nRegistro das notas de GAAL:\n");
            fgets(registroGAAL, MAX_TAM, arquivoGAAL);
            while(!feof(arquivoGAAL)){
                matricula = atoi(strtok(registroGAAL, ","));
                nome = strtok(NULL, ",");
                nota1 = atof(strtok(NULL, ","));
                nota2 = atof(strtok(NULL, ","));
                printf("\n %d \t %s \t %.1f \t %.1f", matricula, nome, nota1, nota2);
                fgets(registroGAAL, MAX_TAM, arquivoGAAL);
            }
            fclose(arquivoGAAL);
            printf("\n");

            printf("\nRegistro das notas de AEDS:\n");
            fgets(registroAEDS, MAX_TAM, arquivoAEDS);
            while(!feof(arquivoAEDS)){
                matricula = atoi(strtok(registroAEDS, ","));
                nome = strtok(NULL, ",");
                nota1 = atof(strtok(NULL, ","));
                nota2 = atof(strtok(NULL, ","));
                printf("\n %d \t %s \t %.1f \t %.1f", matricula, nome, nota1, nota2);
                fgets(registroAEDS, MAX_TAM, arquivoAEDS);
            }
            fclose(arquivoAEDS);
            printf("\n");
        }

    } while ((op != 'Y') && (op != 'N'));
    return 0;
}
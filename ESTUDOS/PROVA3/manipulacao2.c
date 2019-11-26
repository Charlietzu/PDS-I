#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("numero.txt", "r");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto\n");
        return 0;
    }

    int num1, num2, num3;

    //file scanf = fscanf -> requer que o arquivo esteja formatado da forma exata
    fscanf(file, "%i %i %i", &num1, &num2,&num3);

    printf("%i %i %i", num1, num2,num3);
    fclose(file);

    return 0;
}
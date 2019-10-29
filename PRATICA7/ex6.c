#include <stdio.h>
#include <stdlib.h>

void uniaoVetores(){
    int x[59];
    int y[59];
    int z[117];
    int i = 0;

    for(i = 0; i <= 59; i++){
        x[i] = rand()%365;
        y[i] = rand()%365;
    }
    for(i = 0; i <= 59; i++){
        printf("x = %d\n", x[i]);
    }
    printf("\n");
    for(i = 0; i <= 59; i++){
        printf("y = %d\n", y[i]);
    }
    printf("\n");
    //pegar todos os itens dos vetores X e Y e juntar no vetor Z, eliminar as repetidas
    for(i = 0; i <= 59; i++){
        z[i] = x[i];
    }
    for(i = 59; i <= 117; i++){
        z[i] = y[i];
    }
    for(i = 0; i <= 117; i++){
        printf("z = %d\n", z[i]);
    }

}

int main(){
    uniaoVetores();
    return 0;
}
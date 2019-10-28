#include <stdio.h>

int main(void){
  /*
  //matriz[linhas][colunas]
  int matriz[3][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
  //matriz = matrizAlt (duas formas diferentes de representar a mesma matriz)
  int matrizAlt[3][3] = {1, 2, 3, 4, 5, 6, 7 , 8, 9};

  printf("%i\n", matrizAlt[0][1]);
  */

  int matriz[5][5] = {{1, 2, 3, 4, 5},
                      {6, 7, 8, 9, 10},
                      {11,12,13,14,15},
                      {16,17,18,19,20},
                      {21,22,23,24,25}};

  for(int m = 0; m < 5; m++){
    for(int n = 0; n < 5; n++){
      scanf("%i ",matriz[m][n]);
    }
    printf("\n");
  }

  return 0;
}

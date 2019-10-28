#include <stdio.h>
#include <stdlib.h>

float produtoEscalar(){
  int n = 0;
  int i = 0;
  float prodEscalar = 0;
  //gerar um valor aleatório de 1 a 100 para n
  do{
    n = rand()%100;
  }while(n == 0);

  float u[n];
  float v[n];

  //preencher o vetor u com n valores aleatórios de 0 a 10
  for(i = 0; i <= n; i++){
    u[i] = rand()%10;
  }
  //preencher o vetor v com n valores aleatórios de 0 a 10
  for(i = 0; i <= n; i++){
    v[i] = rand()%10;
  }
  //fazer o produto escalar
  for(i = 0; i <= n; i++){
    prodEscalar += u[i] * v[i];
  }
  return prodEscalar;
}

int main(){
  printf("%f",produtoEscalar());
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

float media(int n){
  float vetor[n];
  float media = 0;
  int i = 0;
  //gerar n número aleatoŕios para o vetor
  for(i = 0; i < n; i++){
    vetor[i] = rand()%100;
    printf("%f\n", vetor[i]);
  }
  //fazer a média entre todos os elementos
  for(i = 0; i < n; i++){
    media += vetor[i];
  }
  media = media / n;
  return media;
}

int main(){
  printf("A media e %f\n", media(3));
  return 0;
}

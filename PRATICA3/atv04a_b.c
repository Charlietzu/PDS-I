#include <stdio.h>
//SE EU DECLAREI UMA VARIAVEL COMO PONTEIRO, NÃO UTILIZANDO PREFIXOS, EU RETORNO O ENDEREÇO DELA, UTILIZAR O & É REDUNDÂNCIA
// COM O * EU RETORNO O CONTEUDO
//CASO SEJA UMA VARIAVEL NORMAL, O & RETORNA O ENDEREÇO, E NÃO PRECISA DE DE * POIS ELA JÁ TEM O CONTEÚDO NORMALMENTE
void troca(float *end_valor1, float *end_valor2){
    float aux;

    aux = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = aux;
}

void main() {
    float x,y;
    scanf("%f %f", &x, &y);

    troca(&x, &y);

    printf("\nx = %f\ny = %f", x, y);
}
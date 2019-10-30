#include <stdio.h>

int ddd(unsigned int number) {
    return number / 100000000;
}

int soma1SePar(unsigned int number) {
    return number | 1;
}

int parOuImpar(unsigned int number){
    return !(number & 1);
}

int main() {
    unsigned int num1;

    scanf("%u", &num1);

    printf("ddd (3134095858) == %d\n", ddd(3134095858));
    printf("soma1SePar == %d\n", soma1SePar(num1));
    printf("parOuImpar == %d\n", parOuImpar(num1));

    return 0;
}
#include <stdio.h>

unsigned long long fast_pow_2(int expoente){
    return 1 << expoente;
}

int main() {
	// unsigned long long possui 64 bits portanto 
    // so podemos armazentar um inteiro de 64-1 bits == 63 bits
    int expoente = 63;
	printf("exp == %llu\n", fast_pow_2(expoente));

    return 0;
}
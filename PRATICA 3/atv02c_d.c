#include <stdio.h>

void soma1(int *num){
    ++(*num);
}

int main(){
    int x = 0;
	int *endereco_x;
    
    endereco_x = &x;
    soma1(endereco_x);
    soma1(endereco_x);
    soma1(endereco_x);

	printf("%d", x);
    return 0;
}
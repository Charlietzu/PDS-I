#include <stdio.h>
#include "pratica4.h"

/*float pesoIdeal(float h, char sexo) {
	float pi;
	float multAltura;
	
	if (sexo == 'm'){
		multAltura = 72.7 * h;
		pi = multAltura - 58;
	} else {
		multAltura = 62.1 * h;
		pi = multAltura - 44.7;
	}
}*/

int main(){
	float peso = pesoIdeal(1.70, 'm');
	printf("O peso ideal deve ser: %f\n", peso);
	
	return 0;
}

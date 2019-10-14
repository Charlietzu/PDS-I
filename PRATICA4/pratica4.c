//L�gica das fun��es
#include <stdio.h>
#include <math.h>


float paraMetrosPorSegundo(float v){
	float m;
	return m = v / 3.6;
}

float areaCirculo (float raio){
	float pi = 3.141592;
	float a = pi * (raio * raio);
	return a;
}

int ehPar(int n){
	if(n % 2 == 0 ){
		return 1;
	} else {
		return 0;
	}
}

int ehDivisivelPor3ou5(int n){
	if ((n % 3 == 0 & n % 5 == 0) || (n % 3 != 0 & n % 5 != 0)){
		return 0;
	} else {
		return 1;
	}
}

float pesoIdeal(float h, char sexo) {
	float pi;
	float multAltura;
	
	if (sexo == 'm'){
		multAltura = 72.7 * h;
		pi = multAltura - 58;
	} else {
		multAltura = 62.1 * h;
		pi = multAltura - 44.7;
	}
}

int somaImpares(int N){
    int soma = 0;
    while(N > 0){
        if(N % 2 != 0){
            soma = soma + N; 
        }
        N--;
    }
    return soma;
}

double fatorial(int N){
    int fatorial = 1;
    while(N != 0){
        fatorial = fatorial * N;
        N--;
    }
    return (double) fatorial;
}

int somaNumerosDiv3ou5(int N){
    int soma = 0;
    while (N > 0){
        if ((N % 3 == 0 && N % 5 == 0) || (N % 3 != 0 && N % 5 != 0)){
            N--;
        } else {
            soma = soma + N;
            N--;
        }
    }
    return soma;
}

float calculaMedia(int x, int y, int z, int operacao){
    int mult = (x * y * z);
    if(operacao == 1) {
        //raiz cubica -> pow(x, 1.0/3.0)
        return pow(mult, 1.0 / 3.0);
    } else if(operacao == 2){
        return ((2 * y) + (3 * z) + x) / 6.0;
    } else if(operacao == 3){
        return 3 / ((1 / x) + (1 / y) + (1 / z));
    } else {
        return (x + y + z) / 3.0;
    }
}

int numeroDivisores(int N){
    int denominador = N;
    int numDivisores = 0;

    while(denominador >= 1){
        if(N % denominador == 0){
            numDivisores++;
        }
        denominador--;
    }
    return numDivisores;
}

int enesimoFibonacci(int N){
    int pri_termoAnterior = 1;
    int seg_termoAnterior = 0;
    int termoAtual = 0;
    int iteracoes = 2;

    while(iteracoes < N){
        termoAtual = pri_termoAnterior + seg_termoAnterior;
        seg_termoAnterior = pri_termoAnterior;
        pri_termoAnterior = termoAtual;
        iteracoes++;
    }
    return termoAtual;
}

int mdc(unsigned int x, unsigned int y){
    int divisorAtual = 1;
    int divisorComum = 1;
    while(divisorAtual <= x && divisorAtual <= y){
        if(x % divisorAtual == 0 && y % divisorAtual == 0){
            divisorComum = divisorAtual;
        }
        divisorAtual++;
    }
    return divisorComum;
}

int mmc(unsigned int x, unsigned int y){
    int varMMC = 1;
    int divisorAtual = 2;

    while(x != 1 || y != 1){
        if(x % divisorAtual == 0 || y % divisorAtual == 0){
            varMMC = varMMC * divisorAtual; //12
        }
        if(x % divisorAtual == 0) {
            x = x / divisorAtual; //3
        }
        if(y % divisorAtual == 0){
            y = y / divisorAtual; //1
        }  
        if(x % divisorAtual != 0 && y % divisorAtual != 0){
            divisorAtual++; //4
        } 
    }
    return varMMC;
}

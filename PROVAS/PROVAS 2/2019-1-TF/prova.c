#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMALI 100

float randFloat(float min, float max){
	return min + (max-min)*((float)rand()/RAND_MAX);
}

typedef struct Alimento{
	float carb;
	float prot;
	float gord;
	float kcal;
}Alimento;

void criaAlimento(Alimento *a){
	a->carb = randFloat(10.5, 25.0);
	a->prot = randFloat(0, 15.5);
	a->gord = randFloat(0, 10.5);
	a->kcal = (a->prot * 4) + (a->carb * 4) + (a->gord * 9);
}

void criaMenu(Alimento menu[], int n){
	int i;
	Alimento a;
	for(i = 0; i < n; i++){
		menu[i] = criaAlimento(&a);
	}
}

void criaDieta(int dieta[], int n){
	float r;
	int i, k;
	for(i = 0; i < n; i++){
		r = randFloat(0, 1);
		if(r < 0.3){
			k = 1+rand()%5;
			dieta[i] = k;
		} else {
			dieta[i] = 0;
		}
	}
}

float totalCalorias(int dieta[], Alimento menu[], int n){
	int i;
	float total = 0;
	for(i = 0; i < n; i++){
		total += menu[i].kcal * dieta[i];
	}
	return total;
}

int AlimentoMaisPop(int dietas[][NUMALI], int m){
	int i = 0, j = 0;
	int contItem = 0, maiorCont = 0, maiorInd = 0;
	//retornar o indice da coluna com mais linhas preenchidas
	for(j = 0; j < NUMALI; j++){	
		contItem = 0;
		for(i = 0; i < m; i++){
			if(dietas[i][j] > 0){
				contItem++;
				if(contItem >= maiorCont){
					maiorCont = contItem;
					maiorInd = j;
				}
			}
		}
	}	
	return maiorInd;
}

int main(){
	srand(time(NULL));
	Alimento menu[NUMALI];

	criaMenu(menu, NUMALI);

	//cria dietas para 10 pessoas:
	int i, diets[10][NUMALI];
	for(i = 0; i < 10; i++){
		criaDieta(diets[i], NUMALI);
		//qtd de calorias:
		printf("\nkcals de %d: ", i);
		printf("%f\n", totalCalorias(diets[i], menu, NUMALI));
	}

	printf("\nalimento mais usado:");
	prinft("%d\n", AlimentoMaisPop(diets, 10));

	return 0;
}


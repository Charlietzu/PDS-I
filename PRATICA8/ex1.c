#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeMatriz(int m, int n, int matriz[m][n]){
	int i = 0, j = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void identificaSequencia(int m, int n, int matriz[m][n]){
	
	int matrizAuxiliar[m][n];
	int i = 0, j = 0, contSeq = 1, contZeros = 0;

	//criação da matriz auxiliar
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			matrizAuxiliar[i][j] = 0;
		}
	}
	//verificar sequencias nas linhas
		//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(i = 0; i < m; i++){
		contSeq = 1;
		for(j = 1; j < n; j++){
			if(matriz[i][j] == matriz[i][j - 1]){
				contSeq++;
			} else {
				contSeq = 1;
			}
			if(contSeq >= 3){
				matrizAuxiliar[i][j - (contSeq - 2)] = 1;
				matrizAuxiliar[i][j - (contSeq - 1)] = 1;
				matrizAuxiliar[i][j] = 1;
			}
		}
	}
	
	//verificar sequencias nas colunas
		//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(j = 0; j < n; j++){
		for(i = 0; i < m; i++){
			if(matriz[i][j] == matriz[i - 1][j]){
				contSeq++;
			} else {
				contSeq = 1;
			}
			if(contSeq >= 3){
				matrizAuxiliar[i - (contSeq - 2)][j] = 1;
				matrizAuxiliar[i - (contSeq - 1)][j] = 1;
				matrizAuxiliar[i][j] = 1;
			}
		}
	}
	//trocar sequencias por 0
		//pegar todos os indices 1 na matriz auxiliar e trocar por 0 na matriz original
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(matrizAuxiliar[i][j] == 1){
				matriz[i][j] = 0;
				contZeros++;
			}
		}
	}
}

void sobeZeros(int m, int n, int matriz[m][n]){
	int i, j;

	for(j = 0; j < n; j++){
		for(i = m; i > 0; i--){
			if(matriz[i][j] == 0 && matriz[i - 1][j] != 0){
				matriz[i][j] = matriz[i - 1][j];
				matriz[i - 1][j] = 0;
				i = m;
			}
		}
	}
}

void geraMatriz(int m, int n, int k, int matriz[m][n]){
	int i = 0, j = 0;
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			do{
				matriz[i][j] = rand()%k+1;
			}while(matriz[i][j] == 0);
		}
	}

}

int main(){
	srand(time(NULL));
	
	int m = 5, n = 4, k = 3;
	int matriz[m][n];

	geraMatriz(m, n, k, matriz);
	imprimeMatriz(m, n, matriz);
	printf("\n");

	identificaSequencia(m, n, matriz);
	sobeZeros(m, n, matriz);

	imprimeMatriz(m, n, matriz);
	return 0;
}

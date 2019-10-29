#include <stdio.h>
#include <stdlib.h>

void identificaSequencia(int matriz[m][n], int m, int n){
	int i = 0, j = 0;
	int contSeqLinha = 0;
	int contSeqColuna = 0;
	
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			if(matriz[i][j] == matriz[i][j-1]){
				contSeqColuna++;
			}
			if(contSeqColuna == 3){
				printf("vc tem uma sequencia nas colunas");
			}
		}
		
		if(matriz[i][j] == matriz[i-1][j]){
			contSeqLinha++;
		}
		if(contSeqLinha == 3){
			printf("vc tem uma sequencia nas linhas");
		}
		contSeqColuna = 0;
	}
}

void geraMatriz(int m, int n, int k){
	int matriz[m][n];
	int i = 0, j = 0;
	
	//linha
	for(int i = 0; i < m; i++){
		//colunas
		for(int j = 0; j < n; j++){
			do{
				matriz[i][j] = rand()%k+1;
			}while(matriz[i][j] == 0);
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	identificaSequencia(matriz, m, n);
	
}




int main(){
	geraMatriz(5, 4, 3);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Guerreiro{
	int ataque;
	int defesa;
	int carisma;
	int pontos_vida;
	int id_jogador;
}guerreiro;

int rolaDado(){
	int dado;
	do {
		dado = rand()%6;
	}while(dado == 0);
	
	return dado;
}

int rolaDados(){
	int dado1 = rolaDado(), dado2 = rolaDado(), dado3 = rolaDado();
	int somaDados = 0;
	
	somaDados = dado1 + dado2 + dado3;
	return somaDados;
}

void criaGuerreiro(guerreiro g1){
	g1.ataque = rolaDado();
	g1.defesa = rolaDado();
	g1.carisma = rolaDado();
	g1.pontos_vida = rolaDados();
}

void bonusCarisma(guerreiro g1){
	if(g1.carisma == 3){
		g1.carisma = g1.carisma - 3;
	} else if(g1.carisma > 3 && g1.carisma <= 5){
		g1.carisma = g1.carisma - 2;
	} else if(g1.carisma > 5 && g1.carisma <= 7){
		g1.carisma = g1.carisma - 1;
	} else if(g1.carisma >= 14 && g1.carisma <= 15){
		g1.carisma = g1.carisma + 1;
	} else if(g1.carisma >= 16 && g1.carisma <= 17){
		g1.carisma = g1.carisma + 2;
	} else if(g1.carisma == 18){
		g1.carisma = g1.carisma + 3;
	}
	return g1.carisma;
}

int main(){
	
	guerreiro x;
	criaGuerreiro(x);
	
	printf("ataque: %i\n", x.ataque);
	printf("defesa: %i\n", x.defesa);
	printf("carisma:  %i\n", x.carisma);
	printf("pontos de vida: %i\n", x.pontos_vida);

	return 0;
}
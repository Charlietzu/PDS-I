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
	dado = rand()%6+1;
	return dado;
}

int rolaDados(){
	int dado1 = rolaDado(), dado2 = rolaDado(), dado3 = rolaDado();
	int somaDados = 0;
	
	somaDados = dado1 + dado2 + dado3;
	return somaDados;
}

void criaGuerreiro(guerreiro *g1, int id){
	g1->ataque = rolaDado();
	g1->defesa = rolaDado();
	g1->carisma = rolaDado();
	g1->pontos_vida = rolaDados();
	g1->id_jogador = id;
}

void bonusCarisma(guerreiro *g1){
	if(g1->carisma == 3){
		g1->carisma = g1->carisma - 3;
	} else if(g1->carisma > 3 && g1->carisma <= 5){
		g1->carisma = g1->carisma - 2;
	} else if(g1->carisma > 5 && g1->carisma <= 7){
		g1->carisma = g1->carisma - 1;
	} else if(g1->carisma >= 14 && g1->carisma <= 15){
		g1->carisma = g1->carisma + 1;
	} else if(g1->carisma >= 16 && g1->carisma <= 17){
		g1->carisma = g1->carisma + 2;
	} else if(g1->carisma == 18){
		g1->carisma = g1->carisma + 3;
	}
}

void ataca(guerreiro *g1, guerreiro *g2){
	int golpe, escudo, dano;
	golpe = g1->ataque + rolaDados() + g1->carisma;
	escudo = rolaDados() + g2->defesa + g2->carisma;
	dano = golpe - escudo;
	if (dano > 0){
		g2->pontos_vida -= dano;
	}
}

int main(){
	int i;
	guerreiro x;
	guerreiro y;

	criaGuerreiro(&x, 1);
	criaGuerreiro(&y, 2);
	
	bonusCarisma(&x);
	bonusCarisma(&y);
	
	for(i = 0; x.pontos_vida > 0 && y.pontos_vida > 0; i++){
		if(i % 2 == 0){
			ataca(&x, &y);
		} else {
			ataca(&y, &x);
		}
	}

	if(x.pontos_vida <= 0){
		printf("Quem ganhou foi o guerreiro: %d\n", x.id_jogador);
	}
	if(y.pontos_vida <= 0){
		printf("Quem ganhou foi o guerreiro: %d\n", y.id_jogador);
	}

	return 0;
}

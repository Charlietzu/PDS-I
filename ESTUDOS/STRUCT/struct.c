#include <stdio.h>

int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario agora;
	
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
	
	struct horario depois;
	depois.horas = agora.horas + 10;
	depois.minutos = agora.minutos;
	depois.segundos = agora.segundos;
	
	return 0;
}
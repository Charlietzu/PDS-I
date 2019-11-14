#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

#define LARGURA_DISPLAY 480
#define ALTURA_DISPLAY 640
#define FPS 60

#define N_COLS 6
#define N_LINHAS 9

#define N_TYPES 4

const int COL_W = LARGURA_DISPLAY/N_COLS;
const int LIN_W = ALTURA_DISPLAY/N_LINHAS;

typedef struct Candy{
	int type;
	int active;
	ALLEGRO_COLOR cor;
}Candy;

Candy M[N_LINHAS][N_COLS];

void initCandies(){
	int i, j;
	for(i = 0;i < N_LINHAS; i++){
		for(j = 0; j < N_COLS ; j++){
			M[i][j].type = rand()%4 + 1;
			M[i][j].active = 1;
			M[i][j].cor = al_map_rgb(rand()%256, rand()%256, rand()%256);
			printf("%d ", M[i][j].type);
		}
		printf("\n");
	}
    printf("\n");
}

int getXCoord(int col) {
	return col*COL_W;
}

int getYCoord(int lin){
	return lin*LIN_W;
}

void desenhaCandy(Candy c, int lin, int col){
	int x = getXCoord(col);
	int y = getYCoord(lin);
	
	if(c.type == 1){
		al_draw_filled_rectangle(x, y, x + COL_W, y + LIN_W, c.cor);
	}else if(c.type == 2){
		al_draw_filled_rounded_rectangle(x, y, x + COL_W, y + LIN_W, COL_W/3, LIN_W/3, c.cor);
	}else if(c.type == 3){
		al_draw_filled_ellipse(x + COL_W/2, y + LIN_W/2, COL_W/2, LIN_W/2, c.cor);
	}else if(c.type ==4){
		al_draw_filled_triangle(x+COL_W/2, y, 
								x, y+LIN_W, 
								x+COL_W, y+LIN_W, 
								c.cor);
	}
}

void draw_scenario(ALLEGRO_DISPLAY *display) {
	ALLEGRO_COLOR BKG_COLOR = al_map_rgb(0,0,0); 
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(BKG_COLOR);
    al_init_image_addon();
	
	int i, j;
	for(i = 0; i < N_LINHAS; i++){
		for(j=0; j < N_COLS; j++){
			desenhaCandy(M[i][j], i, j);
		}
	}
}

void getCell(int x, int y, int *lin, int *col){
	*lin = y/LIN_W;
	*col = x/COL_W;
}

void swap(int lin_src, int col_src, int lin_dst, int col_dst){
	Candy aux;
	aux = M[lin_src][col_src];
    int dist_col, dist_lin;
	if(M[lin_src][col_src].type != 0){
		if(((lin_dst==lin_src) || (col_dst==col_src)) && ((lin_dst==lin_src + 1 || col_dst==col_src + 1) || (lin_dst==lin_src - 1 || col_dst==col_src - 1))){
        	M[lin_src][col_src] = M[lin_dst][col_dst];
	    	M[lin_dst][col_dst] = aux;
    	}
	}
}

void criaMatrizAuxiliar(int matriz[N_LINHAS][N_COLS]){
	int i, j;
	for(i = 0; i < N_LINHAS; i++){
		for(j = 0; j < N_COLS; j++){
			matriz[i][j] = 0;
		}
	}
}

int identificaSequencia(){
	int matrizAuxiliar[N_LINHAS][N_COLS];
	criaMatrizAuxiliar(matrizAuxiliar);

	int i = 0, j = 0, contSeq = 1, sequencia = 0;
	//verificar sequencias nas linhas
	//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(i = 0; i < N_LINHAS; i++){
		contSeq = 1;
		for(j = 1; j < N_COLS; j++){
			if(M[i][j].type != 0){
				if(M[i][j].type == M[i][j - 1].type){
					contSeq++;
				} else {
					contSeq = 1;
				}
				if(contSeq >= 3){
					sequencia = 1;
					return sequencia;
				}	
			}   
		}
	}

	//verificar sequencias nas colunas
		//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(j = 0; j < N_COLS; j++){
		for(i = 0; i < N_LINHAS; i++){
			if(M[i][j].type != 0){
				if(M[i][j].type == M[i - 1][j].type){
					contSeq++;
				} else {
					contSeq = 1;
				}
				if(contSeq >= 3){
					sequencia = 1;
					return sequencia;
				}
			} 
		}
	}

	return sequencia;
}

void zeraSequencia(){
	
	int matrizAuxiliar[N_LINHAS][N_COLS];
	criaMatrizAuxiliar(matrizAuxiliar);

	int i = 0, j = 0, contSeq = 1;
	//verificar sequencias nas linhas
		//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(i = 0; i < N_LINHAS; i++){
		contSeq = 1;
		for(j = 1; j < N_COLS; j++){
			if(M[i][j].type != 0){
				if(M[i][j].type == M[i][j - 1].type){
					contSeq++;
				} else {
					contSeq = 1;
				}
				if(contSeq >= 3){
					for(contSeq = contSeq - 1; contSeq >= 0; contSeq--){
						matrizAuxiliar[i][j - contSeq] = 1;
					}
				}
			}	
		}
	}
	
	//verificar sequencias nas colunas
		//trocar os indices das sequencias encontradas e trocar por 1 na matriz auxiliar
	for(j = 0; j < N_COLS; j++){
		for(i = 0; i < N_LINHAS; i++){
			if(M[i][j].type != 0){
				if(M[i][j].type == M[i - 1][j].type){
					contSeq++;
				} else {
					contSeq = 1;
				}
				if(contSeq >= 3){
					for(contSeq = contSeq - 1; contSeq >= 0; contSeq--){
						matrizAuxiliar[i - contSeq][j] = 1;
					}
				}
			}	
		}
	}
	//trocar sequencias por 0
		//pegar todos os indices 1 na matriz auxiliar e trocar por 0 na matriz original
	for(i = 0; i < N_LINHAS; i++){
		for(j = 0; j < N_COLS; j++){
			if(matrizAuxiliar[i][j] == 1){
				M[i][j].type = 0;
			}
		}
	}
}

void sobeZeros(){
	int i, j;

	for(j = 0; j < N_COLS; j++){
		for(i = N_LINHAS; i > 0; i--){
			if(M[i][j].type == 0 && M[i - 1][j].type != 0){
				M[i][j].type = M[i - 1][j].type;
				M[i - 1][j].type = 0;
				i = N_LINHAS;
			}
		}
	}
}

void imprimeMatriz(){
	int i, j;
	for(i = 0; i < N_LINHAS; i++){
		for(j = 0; j < N_COLS; j++){
			printf("%d ", M[i][j].type);
		}
		printf("\n");
	}
	printf("\n");
}

int calculaPontuacao(int tamSequencia){
	int pontuacao = 0;
	pontuacao = pontuacao + pow(2, tamSequencia);
	return pontuacao;
}

int main(int argc, char **argv){

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;


	//----------------------- rotinas de inicializacao ---------------------------------------
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(LARGURA_DISPLAY, ALTURA_DISPLAY);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	if(!al_install_mouse())
		fprintf(stderr, "failed to initialize mouse!\n");   


	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	al_install_keyboard();
   //registra na fila de eventos que eu quero identificar quando a tela foi alterada
	al_register_event_source(event_queue, al_get_display_event_source(display));
   //registra na fila de eventos que eu quero identificar quando o tempo alterou de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra o teclado na fila de eventos:
	al_register_event_source(event_queue, al_get_keyboard_event_source());   
	//registra mouse na fila de eventos:
	al_register_event_source(event_queue, al_get_mouse_event_source());    
   //inicia o temporizador
	al_start_timer(timer);
	//inicializa o modulo allegro que carrega as fontes
    al_init_font_addon();
	//inicializa o modulo allegro que entende arquivos tff de fontes
    al_init_ttf_addon();
	
	ALLEGRO_FONT *size_32 = al_load_font("arial.ttf", 32, 1);

	int pontuacao = 0;
	char texto[20];

	//sprintf(texto, "Pontuacao: %d", pontuacao);
	//al_draw_text(size_32, al_map_rgb(255, 255, 255), 60, 700, 0, texto);

	//inicializa matriz de Candies
	do{
		initCandies();
		identificaSequencia();
	}while(identificaSequencia() == 1);

	int playing = 1;
	ALLEGRO_EVENT ev;
	
	int lin_src, col_src, lin_dst, col_dst, dist_col, dist_lin;
	
	//enquanto playing for verdadeiro, faca:
	while(playing) {	
	  //espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				playing = 0;
			}

		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			//printf("\nclicou em (%d, %d)", ev.mouse.x, ev.mouse.y);
			getCell(ev.mouse.x, ev.mouse.y, &lin_src, &col_src);
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			//printf("\nsoltou em (%d, %d)", ev.mouse.x, ev.mouse.y);
			getCell(ev.mouse.x, ev.mouse.y, &lin_dst, &col_dst);
            swap(lin_src, col_src, lin_dst, col_dst);
			do{
				zeraSequencia();
				imprimeMatriz();
				sobeZeros();
				identificaSequencia();
			}while(identificaSequencia() == 1);
		}		
	    //se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		else if(ev.type == ALLEGRO_EVENT_TIMER) {
		    draw_scenario(display);
			al_flip_display();		
		}
	    //se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}

	} 

	al_rest(1);

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

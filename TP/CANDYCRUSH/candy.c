#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdlib.h>
#include <math.h>

#define LARGURA_DISPLAY 480
#define ALTURA_DISPLAY 640
#define ALTURA_PLACAR 64
#define FPS 60

#define N_COLS 6
#define N_LINHAS 9

#define N_TYPES 4

const int LARGURA_CEL = (float) LARGURA_DISPLAY/N_COLS;
const int ALTURA_CEL = (float) (ALTURA_DISPLAY-ALTURA_PLACAR)/N_LINHAS;

int pontos=0, jogadas=10;
char minha_pontuacao[100], minhas_jogadas[100];

ALLEGRO_FONT *size_f;
ALLEGRO_BITMAP *telaFundo = NULL;


typedef struct Candy{
	int type;
	ALLEGRO_COLOR cor;
}Candy;

Candy M[N_LINHAS][N_COLS];

int registraRecorde(int pontuacao, int *recorde) {
	FILE *arq = fopen("recorde.txt", "r");
	*recorde = -1;
	if(arq != NULL) {
		fscanf(arq, "%d", recorde);
		fclose(arq);
	}
	if(*recorde < pontuacao ) {
		arq = fopen("recorde.txt", "w");
		fprintf(arq, "%d", pontuacao);
		fclose(arq);
		return 1;
	}
	return 0;
}

void initCandies(){
	int i, j;
	for(i = 0;i < N_LINHAS; i++){
		for(j = 0; j < N_COLS ; j++){
			M[i][j].type = rand()%4 + 1;
			M[i][j].cor = al_map_rgb(1+rand()%256, 1+rand()%256, 1+rand()%256);
			//printf("%d ", M[i][j].type);
		}
		//printf("\n");
	}
    //printf("\n");
}

int getXCoord(int col) {
	return col*LARGURA_CEL;
}

int getYCoord(int lin){
	return ALTURA_PLACAR + lin*ALTURA_CEL;
}

void desenhaCandy(Candy c, int lin, int col){
	int x = getXCoord(col);
	int y = getYCoord(lin);
	
	if(c.type == 1){
		al_draw_filled_rectangle(x, y, x + LARGURA_CEL, y + ALTURA_CEL, c.cor);
	}else if(c.type == 2){
		al_draw_filled_rounded_rectangle(x, y, x + LARGURA_CEL, y + ALTURA_CEL, LARGURA_CEL/3, ALTURA_CEL/3, c.cor);
	}else if(c.type == 3){
		al_draw_filled_ellipse(x + LARGURA_CEL/2, y + ALTURA_CEL/2, LARGURA_CEL/2, ALTURA_CEL/2, c.cor);
	}else if(c.type ==4){
		al_draw_filled_triangle(x+LARGURA_CEL/2, y, 
								x, y+ALTURA_CEL, 
								x+LARGURA_CEL, y+ALTURA_CEL, 
								c.cor);
	}
}

void draw_scenario(ALLEGRO_DISPLAY *display) {
	ALLEGRO_COLOR BKG_COLOR = al_map_rgb(0,0,0); 
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(BKG_COLOR);

	al_draw_bitmap(telaFundo, 0, 0, 0);

	sprintf(minha_pontuacao, "Pontuacao: %d", pontos);
	al_draw_text(size_f, al_map_rgb(255, 255, 255), LARGURA_DISPLAY - 200, ALTURA_PLACAR/4, 0, minha_pontuacao); 
	
	sprintf(minhas_jogadas, "Jogadas: %d", jogadas);
	al_draw_text(size_f, al_map_rgb(255, 255, 255), 10, ALTURA_PLACAR/4, 0, minhas_jogadas); 
	
	int i, j;
	for(i = 0; i < N_LINHAS; i++){
		for(j=0; j < N_COLS; j++){
			desenhaCandy(M[i][j], i, j);
		}
	}
}

void getCell(int x, int y, int *lin, int *col){
	*lin = (y-ALTURA_PLACAR)/ALTURA_CEL;
	*col = x/LARGURA_CEL;
}

void swap(int lin_src,int col_src,int lin_dst,int col_dst){
	Candy aux;
	aux = M[lin_src][col_src];
	int dist_col, dist_lin;
	if(M[lin_src][col_src].type != 0 || M[lin_dst][col_dst].type != 0){
		if(((lin_dst==lin_src) || (col_dst==col_src)) && ((lin_dst==lin_src + 1 || col_dst==col_src + 1) || (lin_dst==lin_src - 1 || col_dst==col_src - 1))){
        	M[lin_src][col_src] = M[lin_dst][col_dst];
	    	M[lin_dst][col_dst] = aux;
			jogadas--;
    	}
		
	}
	
}

int distancia(int lin1, int col1, int lin2, int col2) {
	return sqrt(pow(lin1-lin2, 2) + pow(col1-col2, 2));
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
	int i = 0, j = 0, contSeq = 1, sequencia = 0;
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
		for(i = N_LINHAS - 1; i > 0; i--){
			if(M[i][j].type == 0  && M[i - 1][j].type != 0){
				M[i][j].type = M[i - 1][j].type;
				M[i - 1][j].type = 0;
				i = N_LINHAS - 1;
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

int calculaPontuacao(){
	int i = 0, j = 0, contSeq = 1, sequencia = 0;

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
					sequencia += contSeq;
				}	
			}   
		}
	}

	for(j = 0; j < N_COLS; j++){
		for(i = 0; i < N_LINHAS; i++){
			if(M[i][j].type != 0){
				if(M[i][j].type == M[i - 1][j].type){
					contSeq++;
				} else {
					contSeq = 1;
				}
				if(contSeq >= 3){
					sequencia += contSeq;
				}
			} 
		}
	}

	return sequencia;
}

int main(int argc, char **argv){

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE *soundtrack = NULL;	
	ALLEGRO_SAMPLE *movimentacao = NULL;


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

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();
	//inicializa o modulo allegro que entende arquivos tff de fontes
	al_init_ttf_addon();
	
	size_f = al_load_font("arial.ttf", 24, 1);

	if(!al_init_image_addon()){
		fprintf(stderr, "failed to initialize images:\n");
		return -1;
	}

	telaFundo = al_load_bitmap("telafundo.png");
	if (!telaFundo) {
		fprintf(stderr, "failed to load background bitmap!\n");
		return -1;
	}

	if (!al_install_audio()) {
			fprintf(stderr, "failed to initialize audio!\n");
	        return -1;
	}
	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	soundtrack = al_load_sample("soundtrack.wav");
	if (!soundtrack) {
		fprintf(stderr, "audio clip move not loaded!\n");
		return -1;
	}

	movimentacao = al_load_sample("movimento.wav");
	if (!movimentacao) {
		fprintf(stderr, "audio clip move not loaded!\n");
		return -1;
	}

	if (!al_reserve_samples(3)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

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

	//inicializa matriz de Candies
	srand(time(NULL));
	do{
		initCandies();
		identificaSequencia();
	}while(identificaSequencia() == 1);

	int playing = 1, pts = 0;
	ALLEGRO_EVENT ev;
	al_play_sample(soundtrack, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	
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
			getCell(ev.mouse.x, ev.mouse.y, &lin_src, &col_src);
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			getCell(ev.mouse.x, ev.mouse.y, &lin_dst, &col_dst);
			if(distancia(lin_src, col_src, lin_dst, col_dst) > 0 && (M[lin_src][col_src].type != 0 || M[lin_dst][col_dst].type != 0)){
				swap(lin_src, col_src, lin_dst, col_dst);
				al_play_sample(movimentacao, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				
			}
			pts = 0;
			do{
				pts += calculaPontuacao();
				pontos += pts;
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

			if(jogadas == 0){
				playing = 0;
				al_destroy_sample(soundtrack);
			}
		}
	    //se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}

	} 

	al_rest(1);
	int recorde;
	al_clear_to_color(al_map_rgb(0,0,0));
	sprintf(minha_pontuacao, "Sua pontuacao: %d", pontos);
	al_draw_text(size_f, al_map_rgb(255, 255, 255), LARGURA_DISPLAY/3, ALTURA_DISPLAY/2, 0, minha_pontuacao);
	if(registraRecorde(pontos, &recorde)){
		al_draw_text(size_f, al_map_rgb(255, 255, 255), LARGURA_DISPLAY/3, 100+ALTURA_DISPLAY/2, 0, "Novo Recorde!");
	} else {
		sprintf(minha_pontuacao, "Recorde atual: %d", recorde);
		al_draw_text(size_f, al_map_rgb(255, 255, 255), LARGURA_DISPLAY/3, 100+ALTURA_DISPLAY/2, 0, minha_pontuacao);
	}

	al_flip_display();	
	al_rest(4);

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

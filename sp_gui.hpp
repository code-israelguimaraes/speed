
char PLANILHA[8][20][12]; //GUARDAR INFORMAÇÕES MATRIZ

int COLUNA=3;		//MAX:8
int LINHA=3;		//MAX:20
int LARGURA=12;		//MAX:12

int GUICOLOR_FG=8;
int GUICOLOR_BG=5;

int ID_COLUNA=0;
int ID_LINHA=0;

int CELULA_ATIVA=0;
int CELULA_CARACTER=0;
int CELULA_X=4;//MESMO VALOR DO MOUSE
int CELULA_Y=4;//MESMO VALOR DO MOUSE

void gui_coluna(int x,int y,int letraA){
		
	/*
	 * FUNÇÃO COLUNA
	 * 
	 * ESSA FUNÇÃO REPRESENTA A COLUNA QUE
	 * DE UMA PLANILHA,COMEÇANDO COM A LETRA A
	 * E INDO ATÉ A LETRA H
	 * 
	 * VARIAVEL USADA
	 * 
	 * LARGURA: REPRESENTA A LARGURA DA COLUNA QUE É UMA VARIAVEL GLOBAL
	 *
	 * */	
		
	for(int i=0;i<LARGURA;i++){
		
		sp_color(GUICOLOR_BG,0);
		gotoxy(x+i,y),printf("█");	
		
		if(i==(LARGURA/2)){
			sp_color(GUICOLOR_FG,GUICOLOR_BG);
			gotoxy(x+i,y),printf("%c",letraA);	
		}
		
	}
	
}

void gui_linha(int x,int y){
	
	/*
	 * FUNÇÃO LINHA
	 * 
	 * ESSA FUNÇÃO REPRESENTA A LINHA
	 * DE UMA PLANILHA,COMEÇANDO COM 1 INDO ATÉ 20
	 * 
	 * VARIAVEL USADA
	 * 
	 * LINHA: REPRESENTA QUANTIDADE DE LINHA DA PLANILHA,É UMA VARIAVEL GLOBAL
	 *
	 * */
	
	sp_color(GUICOLOR_FG,GUICOLOR_BG);
	
	for(int i=0;i<LINHA;i++){
		
		if(i<9){
			gotoxy(x,y+i),printf("  %i",i+1);
		}else{
			gotoxy(x,y+i),printf(" %i",i+1);
		}
		
	}
}

void gui_separador(int x,int y){
	
	sp_color(GUICOLOR_BG,0);
	gotoxy(x,y),printf("███");
	
	for(int i=0;i<(COLUNA*LARGURA)+4;i++){
		sp_color(GUICOLOR_BG,0);
		gotoxy(0+i,y-3),printf("█");		
	}
}

void sp_status(int x,int y){
	
	/*
	 * FUNÇÃO GUI
	 * 
	 * ESSA FUNÇÃO MOSTRA OS STATUS DE ALGUMAS 
	 * VARIAVEIS DA PLANILHA.
	 * 
	 * VARIAVEL USADA
	 * 
	 * ID_COLUNA: REPRESENTA A POSIÇÃO DA MATRIZ PLANILHA
	 * ID_LINHA:  REPRESENTA A POSIÇÃO DA MATRIZ PLANILHA
	 *
	 * */
	
	sp_color(GUICOLOR_FG,0);
	
	//EXIBE CONTEUDO DA MATRIZ GUARDADA
	for(int k=0;k<LARGURA;k++){
		gotoxy(x+k,y),printf(" ");
		gotoxy(x+k,y),printf("%c",PLANILHA[ID_COLUNA][ID_LINHA][k]);
	}
	
	//EXIBE COLUNA E LINHA PELO SEU ID
	sp_color(0,GUICOLOR_BG);
	for(int k=0;k<LARGURA;k++){
		gotoxy(x+k,y-2),printf(" ");
	}
	gotoxy(x,y-2),printf("%c%i",65+ID_COLUNA,ID_LINHA+1);
	
	
}

//INSERIR DADOS VISUAL FUNÇÃO
void sp_celula(char tecla,int x,int y){
		
	sp_color(GUICOLOR_FG,0);	
		
	//EXIBIR DADOS NA TELA
	gotoxy(x,y),printf("%c",toupper(tecla));	

	//PROCESSO DE INSERIR DADOS NA MATRIZ
	PLANILHA[ID_COLUNA][ID_LINHA][CELULA_CARACTER]=toupper(tecla);
	
}

void sp_gui(int x,int y){

	/*
	 * FUNÇÃO GUI
	 * 
	 * ESSA FUNÇÃO REPRESENTA GUI DA PLANILHA
	 * DE UMA PLANILHA.
	 * 
	 * VARIAVEL USADA
	 * 
	 * LETRA_A: REPRESENTA A PRIMEIRA LETRA DA COLUNA
	 * LARGURA: REPRESENTA A LARGURA DA COLUNA
	 * COLUNA:  REPRESENTA A QUANTIDADE DE COLUNAS
	 * LINHA:   REPRESENTA A QUANTIDADE DE LINHAS
	 *
	 * */

	//LETRA: A = 65
	int letraA=64;

	//SEPARADOR
	gui_separador(x,y);

	//COLUNA
	for(int i=0;i<(COLUNA*LARGURA);i++){
			
		if(i%LARGURA==0){
			letraA++;
			gui_coluna(4+x+i,y,letraA);
		}
			
	}
	
	//LINHA
	gui_linha(x,y+1);
	
	//STATUS PLANILHA
	sp_status(x,y-1);
	
	//CELULA
	sp_celula(tecla,CELULA_X+CELULA_CARACTER,CELULA_Y);
	
}

/*

 SEPARADOR

 INFORMAÇÃO ID COLUNA LINHA
 sp_color(GUICOLOR_FG,GUICOLOR_BG);
 gotoxy(0,0),printf("%c%i",65+ID_COLUNA,ID_LINHA+1);

*/

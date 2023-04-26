//VARIAVEIS GLOBAIS

char PLANILHA[8][20][12];

int SALVAR=0;

int COLUNA=8;	//MAX:8
int LINHA=20;	//MAX:20
int WIDTH=12;   //MAX:12

int GUICOLOR=7;

int ID_COLUNA=0;
int ID_LINHA=0;

int CELULA_ATIVAR=0;
int CELULA_CARACTER=0;
int CELULA_X=3;
int CELULA_Y=3;//original 2

void sp_guicoluna(int x,int y,int letraA){
	
	/*
	 * FUNÇÃO COLUNA
	 * 
	 * ESSA FUNÇÃO REPRESENTA A COLUNA QUE
	 * DE UMA PLANILHA,COMEÇANDO COM A LETRA A
	 * E INDO ATÉ A LETRA H
	 * 
	 * VARIAVEL USADA
	 * 
	 * WITH: REPRESENTA A LARGURA DA COLUNA QUE É UMA VARIAVEL GLOBAL
	 *
	 * */
	
	for(int i=0;i<WIDTH;i++){
	
		sp_color(GUICOLOR,0);
		if(i==0)gotoxy(x-2,y),printf("███");	
		gotoxy(x+i,y),printf("█");	
		gotoxy(x-2+i,y+LINHA+1),printf("███");	
	
		if(i==(WIDTH/2)){
			sp_color(0,GUICOLOR);
			gotoxy(x+i,y),printf("%c",letraA);		
		}
		
	}
}

void sp_guilinha(int x,int y){
	
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
	
	for(int j=0;j<LINHA;j++){
		sp_color(0,GUICOLOR);
		
		if(j>=0 && j<9){
			gotoxy(x,y+j),printf("%i ",j+1);//j=0,j+1
		}else{
			gotoxy(x,y+j),printf("%i",j+1);// j+0,j+1
		}
		
		
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
	 * ID_COLUNA:REPRESENTA A POSIÇÃO DA MATRIZ PLANILHA
	 * ID_LINHA:REPRESENTA A POSIÇÃO DA MATRIZ PLANILHA
	 *
	 * */
	
	sp_color(8,background+1);
	
	for(int k=0;k<WIDTH;k++){
	
		//MOVER NO EIXO X,A EXIBIÇÃO DA INFORMAÇÃO PARA VISUALIZAR O DADO
		//PORQUE SE A LINHA FOR MAIOR QUE 10,MOVE A INFORMAÇÃO A DIREITA 
		//ASSIM A INFORMAÇÃO FICA VISIVEL 
		//
		//EXEMPLO A5=INFORMACAO
		//EXEMPLO A11=INFO
		//
		if(ID_LINHA<10){
			gotoxy(2+x,y+LINHA+3),printf("%c%i=",toupper(97+ID_COLUNA),1+ID_LINHA);	
			gotoxy(2+2+x+k,y+LINHA+3),printf("%c",PLANILHA[ID_COLUNA][ID_LINHA][k]);	
		}else{
			gotoxy(2+x,y+LINHA+3),printf("%c%i=",toupper(97+ID_COLUNA),1+ID_LINHA);	
			gotoxy(3+2+x+k,y+LINHA+3),printf("%c",PLANILHA[ID_COLUNA][ID_LINHA][k]);
		}
	
	
	}
	
}

void sp_celula(int x,int y,char tecla){
		
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
	 * WITH:REPRESENTA A LARGURA DA COLUNA
	 * COLUNA:REPRESENTA A QUANTIDADE DE COLUNAS
	 * LINHA:REPRESENTA A QUANTIDADE DE LINHAS
	 *
	 * */

	//LETRA: A = 65
	int letraA=64;

	//COLUNA	
	for(int i=0;i<COLUNA*WIDTH;i++){
	
		if(i%WIDTH==0){
			letraA++;
			sp_guicoluna(x+i+3,y,letraA);
		}
	}
	
	//LINHA		
	sp_guilinha(x,y+1);//original x+2
	
	//STATUS PLANILHA
	sp_status(x,y);
	
	//CELULA
	gotoxy(11+x,y+LINHA+5),printf(" ");
	sp_celula(CELULA_X+CELULA_CARACTER,CELULA_Y,tecla);

//----------------------------------------------------------------------
}


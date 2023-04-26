/*	
 * 	AUTHOR: ISRAEL SOUSA GUIMARAES
 *  CREATION DATE 22/04/2023
 *  VERSION CGUI: 0.1	
 *  OPERATION SYSTEM: LINUX
 * 	WRITTER IN: C
 *  MODO: CONSOLE
 *  FONT: TERMINUS 
 *  SIZE: 13
 * -------------------------------------------------------------------
 * */

// VARIABLES SOFTWARE
char tecla;						// VARIABLE TO CAPTURE KEYBOARD
int start_software = 1;			// START SOFTWARE, BEING START = TRUE
int clocks = 0; 				// CLOCK VARIABLE FOR IN-GAME CONTROL			
int background = 4; 			// TERMINAL BACKGROUND COLOR (1 TO 16 COLORS)

//BIBLIOTECAS
#include "speed_in.h"
#include "speed_sys.h"
#include "speed_color.h"
#include "speed_graphics.h"
#include "speed_text.h"
#include "speed_song.h"

#include "speed_gui.h"
#include "speed_input.h"

//----------------------------------------------------------------------

int main(){

	//MY WINDOW TITLE
	system("echo '\033]0; S P E E D \007'");
	
	sp_fullscreen();			//FULLSCREEN
	sp_background(background); //BACKGROUND COLOR
	sp_clear();				   //CLEAR SCREEN
	
	//ABRIR ARQUIVO E GRAVAR
	
	/*
	 * INICIALIZA O ARQUIVO DA PLANILHA
	 * COM CARACTER X,MARCANDO E FAZENDO A
	 * DIVISÃO EXATA DE ESPAÇOS IGUAL A PLANILHA
	 * REPRESENTADA GRAFICAMENTE EM TEXTO
	 * 
	 * */
	
	FILE *tmp;
	tmp=fopen("planilha.txt","w");
	
	for(int linha=0;linha<LINHA;linha++){
        for(int coluna=0;coluna<COLUNA;coluna++){
			for(int k=1;k<WIDTH;k++){
				
				//* NA HORA DE GRAVAR DEVE-SE: [COLUNA][LINHA]
				//* NA HORA DE PERCORRER DEVE-SE: LINHA X COLUNA
							 
				PLANILHA[coluna][linha][k]=' ';
				fprintf(tmp,"%c",PLANILHA[coluna][linha][k]);
				
			}
            
        }
        if(COLUNA%COLUNA==0)fprintf(tmp,"\n");
    }
    
    fclose(tmp);

	while(start_software==1){

		// TURN OFF TERMINAL FUNCTION CURSOR OFF
		sp_curso(0);
		sp_echo(0);

		// ** YOUR CODE HERE BELOW **
		sp_gui(0,2);
		sp_mouse(tecla,MOUSE_X,MOUSE_Y);
		
		//--------------------------------------------------------------
		
		while(kbhit()){
		
			// KBHIT() = COMMAND FOR KEYBOARD DATA ENTRY
			tecla = getch();
			
			// LOGIC
			
			//TECLADO DIRECIONAL,MOVE CURSOR QUE É: ?
			if(tecla==key_right && ID_COLUNA!=COLUNA-1 || tecla==key_tab && ID_COLUNA!=COLUNA-1){
				MOUSE_X+=WIDTH;
				ID_COLUNA++;	
			}
			
			if(tecla==key_left && ID_COLUNA!=0){
				MOUSE_X-=WIDTH;
				ID_COLUNA--;	
			}
			
			if(tecla==key_up && ID_LINHA!=0){
				MOUSE_Y--;	
				ID_LINHA--;
			}
			
			if(tecla==key_down && ID_LINHA!=LINHA-1 || tecla==key_enter && ID_LINHA!=LINHA-1){
				MOUSE_Y++;	
				ID_LINHA++;
			}
			
			//DESATIVAR INPUT NA CELULA AO MUDAR DE COLUNA	
			if(tecla==key_up || tecla==key_down || tecla==key_left || tecla==key_right || tecla==key_enter || tecla==key_tab){
				
				CELULA_X=MOUSE_X;
				CELULA_Y=MOUSE_Y;
				
				CELULA_ATIVAR=0; 
				CELULA_CARACTER=0;
				
			}
			
			//TECLADO LETRAS: A-Z
			if(tecla>='a' && tecla<='z'){
				CELULA_ATIVAR=1;
				
				if(CELULA_CARACTER!=WIDTH-1){
					//CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
					//SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
					CELULA_CARACTER++;
				}
				
			}
			
			
			//TECLADO NUMEROS: 0-9
			if(tecla>='0' && tecla<='9'){
				CELULA_ATIVAR=1;	
				
				if(CELULA_CARACTER!=WIDTH-1){
					//CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
					//SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
					CELULA_CARACTER++;
				}
				
			}
			
			//TECLADO SIMBOLOS ESPECIAL: .
			if(tecla=='.'){
				CELULA_ATIVAR=1;	
				
				if(CELULA_CARACTER!=WIDTH-1){
					//CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
					//SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
					CELULA_CARACTER++;
				}
				
			}
			
			//TECLADO FUNCAO:APAGAR CELULA
			if(tecla==key_spacebar && CELULA_ATIVAR==0){
				for(int k=0;k<WIDTH;k++){
					gotoxy(MOUSE_X+k,MOUSE_Y),printf(" ");
					//NESSA MATRIZ É O UNICO CASO QUE INVERTEMOS 
					//A GRAVAÇÃO DA MATRIZ [COLUNA][LINHA],O ID
					
					//* NA HORA DE GRAVAR DEVE-SE: [COLUNA][LINHA]
					//* NA HORA DE PERCORRER DEVE-SE: LINHA X COLUNA
					
					PLANILHA[ID_COLUNA][ID_LINHA][k]=' ';
				}	
			}
			
		//--------------------------------------------------------------	
		}

		// GAME LOOPS (PUT ALL THE ANIMATION AND LOGIC FUNCTIONS BELOW KBHIT)
		srand(time(NULL));
		clocks++;
		if(clocks==100)clocks=0; //TIME CONTROL AT THE TERMINAL
		
		//--------------------------------------------------------------
		
		// ** CODE LOOP FUNCTIONS BELOW**
	
		/*SALVAR ARQUIVO A TODO MONENTO A CADA X SEGUNDOS EM LOOP*/
		
		if(clocks%100==0){
			
			SALVAR++;
			gotoxy(2,LINHA+6),printf("           ");
			
			if(SALVAR!=60){
				FILE *file;
				file=fopen("planilha.txt","w");
					
				for(int linha=0;linha<LINHA;linha++){
					for(int coluna=0;coluna<COLUNA;coluna++){
						for(int k=1;k<WIDTH;k++){
							
							/*
							 * GRAVAR DADO COM SIMBOLO # SE NÃO TIVER TEXTO NA CELULA 
							 * PARA PREENCHER O VAZIO
							 * 
							 * NA HORA DE GRAVAR DEVE-SE: [COLUNA][LINHA]
							 * NA HORA DE PERCORRER DEVE-SE: LINHA X COLUNA
							 * 
							 */
							 
							 //ORIGINAL: [j][i]
							if(PLANILHA[coluna][linha][k]!=isalpha(PLANILHA[coluna][linha][k])){
								fprintf(file,"%c",PLANILHA[coluna][linha][k]);
							}else{
								fprintf(file," ");
							}
								
						}
														
					}
					if(COLUNA%COLUNA==0)fprintf(file,"\n");
				}
				fclose(file);
			}
						
		}
		
		/*
		 * INTERVALO DE TEMPO ENTRE A MENSAGEM E ZERAR 
		 * A VARIAVEL PARA GRAVAR NOVA INFORMAÇÃO
	    */
		
		//MENSAGEM INTERVALO DE TEMPO DE 60 ATÉ 80
		if(SALVAR>60){	
			gotoxy(2,LINHA+6),printf("SALVANDO...");
		}
		
		//ZERAR VARIAVEL
		if(SALVAR==80)SALVAR=0;
		
		//--------------------------------------------------------------

	}
	
	// CONNECT TERMINAL FUNCTION
	sp_curso(1);
	sp_echo(1);
	
  return 0;

}

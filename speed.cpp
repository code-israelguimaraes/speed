// SOFTWARE VARIABLES
char tecla;						// VARIABLE TO CAPTURE KEYBOARD
int software_game = 1;			// START SOFTWARE , BEING START = TRUE			
int background = 0; 			// TERMINAL BACKGROUND COLOR (1 TO 16 COLORS)
int clocks = 0; 				// CLOCK VARIABLE FOR IN-GAME CONTROL

using namespace std;

//BIBLIOTECAS
#include "sp_in.hpp"
#include "sp_sys.hpp"
#include "sp_color.hpp"

//BIBLIOTECAS SOFTWARE
#include "sp_gui.hpp"
#include "sp_mouse.hpp"
#include "sp_celula.hpp"

#include "sp_saveload.hpp"

//----------------------------------------------------------------------

int main(){

	//MY WINDOW TITLE
	system("echo '\033]0;S P E E D \007'");
	
	sp_fullscreen();			  //FULLSCREEN
	sp_background(background);   //BACKGROUND COLOR
	sp_clear();				     //CLEAR SCREEN

	//ABRIR ARQUIVO E GRAVAR
	
	/*
	 * INICIALIZA O ARQUIVO DA PLANILHA
	 * COM CARACTER X,MARCANDO E FAZENDO A
	 * DIVISÃO EXATA DE ESPAÇOS IGUAL A PLANILHA
	 * REPRESENTADA GRAFICAMENTE EM TEXTO
	 * 
	 */

	FILE *tmp;
	tmp=fopen("speedtmp.txt","w");
	
	for(int linha=0;linha<LINHA;linha++){
        for(int coluna=0;coluna<COLUNA;coluna++){
			for(int k=1;k<LARGURA;k++){
				
				//* NA HORA DE GRAVAR    DEVE-SE: [COLUNA][LINHA]
				//* NA HORA DE PERCORRER DEVE-SE: [LINHA] [COLUNA]
							 
				PLANILHA[coluna][linha][k]='#';
				fprintf(tmp,"%c",PLANILHA[coluna][linha][k]);
			}
            
        }
        if(COLUNA%COLUNA==0)fprintf(tmp,"\n");
    }
    
    fclose(tmp);

	//------------------------------------------------------------------
	while(software_game==1){

		// TURN OFF TERMINAL FUNCTION CURSOR OFF
		sp_curso(0);
		sp_echo(0);

		// ** YOUR CODE HERE BELOW **
		sp_gui(0,3);
		sp_cursor(tecla,MOUSE_X,MOUSE_Y);
		
		//--------------------------------------------------------------
		
		while(kbhit()){
		
			// KBHIT() = COMMAND FOR KEYBOARD DATA ENTRY
			tecla = getch();
		
			// LOGIC
			
			//TECLADO DIRECIONAL,MOVE CURSOR QUE É: ?
			if(tecla==key_right and ID_COLUNA!=(COLUNA-1)){
				MOUSE_X+=LARGURA;
				ID_COLUNA++;	
			}
			
			//TECLADO DIRECIONAL,MOVE CURSOR QUE É: ?
			if(tecla==key_left and ID_COLUNA!=0){
				MOUSE_X-=LARGURA;
				ID_COLUNA--;	
			}
			
			//TECLADO DIRECIONAL,MOVE CURSOR QUE É: ?
			if(tecla==key_up and ID_LINHA!=0){
				MOUSE_Y--;	
				ID_LINHA--;
			}
			
			//TECLADO DIRECIONAL,MOVE CURSOR QUE É: ?
			if((tecla==key_down or tecla==key_enter) and ID_LINHA!=LINHA-1){
				MOUSE_Y++;	
				ID_LINHA++;
			}
			
			//----------------------------------------------------------
			
			//DESATIVAR INPUT NA CELULA AO MUDAR DE COLUNA OU LINHA
			if(tecla==key_up   or tecla==key_down or 
			   tecla==key_left or tecla==key_right or 
			   tecla==key_enter){
				
				/*
				
				CELULA_X E CELULA_Y REPRESENTA ISOLADO
				A POSICAO DA FUNÇÃO INSERIR CARACTER QUE ESTÁ EM SP_GUI.HPP
				COMO: SP_CELULA
				
				*/
				
				CELULA_X=MOUSE_X;
				CELULA_Y=MOUSE_Y;
				
				CELULA_ATIVA=0; 
				CELULA_CARACTER=0;
			}
			
			//----------------------------------------------------------
			
			//KEYBOARD A-Z , TOUPPER CAIXA ALTA
			if(tecla>='a' and tecla<='z'){
				
				/*
				CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
				SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
				*/
		
				CELULA_ATIVA=1;
				if(CELULA_CARACTER!=LARGURA-1){
					CELULA_CARACTER++;	
				}
				
			}
			
			//KEYBOARD 0-9
			if(tecla>='0' and tecla<='9'){
				
				/*
				CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
				SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
				*/
				
				CELULA_ATIVA=1;	
				
				if(CELULA_CARACTER!=LARGURA-1){
					CELULA_CARACTER++;
				}
				
			}
			
			//TECLADO SIMBOLOS ESPECIAL: .
			if(tecla=='.'){
				
				/*
				CONDIÇÃO LOGICA PARA CONTINUAR INSERIR CARACTER
				SE O NÚMERO DE CARACTER FOR MENOR QUE A LARGURA CELULA
				*/
				
				CELULA_ATIVA=1;	
				
				if(CELULA_CARACTER!=LARGURA-1){
					CELULA_CARACTER++;
				}
			}
			
			//----------------------------------------------------------
			
			/*  
			
			PONTO IMPORTANTE EM RELAÇÃO A EXIBIR E GRAVAR
			DADOS NA MATRIZ 
			  
			O USO DA MATRIZ PARA GRAVAÇÃO E EXIBIRÇÃO,SÃO
			DIFERENTES
			
			A GRAVAÇÃO DA MATRIZ [COLUNA][LINHA]
					
			NA HORA DE GRAVAR DEVE-SE:    [COLUNA][LINHA]
			NA HORA DE PERCORRER DEVE-SE: [LINHA] [COLUNA]
			
			*/
			
			//TECLADO FUNCAO:APAGAR CELULA
			if(tecla==key_spacebar and CELULA_ATIVA==0){
			
				//APAGAR DE FORMA VISUAL
				for(int k=0;k<LARGURA;k++){
					gotoxy(MOUSE_X+k,MOUSE_Y),printf(" ");	
				}	
				
				//APAGAR DENTRO DA MATRIZ
				for(int k=0;k<LARGURA;k++){
					PLANILHA[ID_COLUNA][ID_LINHA][k]=' ';
				}
				
			}
		//--------------------------------------------------------------	
		}
		
		// START LOOPS (PUT ALL THE ANIMATION AND LOGIC FUNCTIONS BELOW KBHIT)
		srand(time(NULL));
		clocks++;
		if(clocks==30)clocks=0; //TIME CONTROL AT THE TERMINAL
		
		//--------------------------------------------------------------
		
		// ** CODE LOOP FUNCTIONS BELOW**

		/*
		 SAVE AUTOMATICO,QUANDO USUARIO ESTIVER 
		 DENTRO DA CELULA E PRESSIONAR ENTER
		 
		 PARA QUE SEJA EFETUADO A GRAVAÇÃO DAS
		 INFORMAÇÕES DEVE-SE RESPEITAR UM TEMPO
		 NESSE CASO 30s 
 
		*/
		
		if(CELULA_ATIVA==1 and key_enter){
			if(clocks!=30)save();	
		}
		if(CELULA_ATIVA==0){
			gotoxy(COLUNA*LARGURA-3,LINHA+5),printf("        ");	
		}
		//--------------------------------------------------------------
	}
	
	
	// CONNECT TERMINAL FUNCTION
	sp_curso(1);
	sp_echo(1);
	
  return 0;

}

#include <stdlib.h>

void sp_fullscreen(){
	system("wmctrl -r :ACTIVE: -b toggle,maximized_vert,maximized_horz");		
}

void sp_curso(int off_on){
	
	if(off_on == 1)printf("\e[?25h");// CURSOR LIGADO
	
	if(off_on == 0)printf("\e[?25l");// CURSOR DESLIGADO
		
}

void sp_echo(int off_on){
	
	if(off_on == 1)system("stty echo");// ECHO DA TELA LIGADO
	
	if(off_on == 0)system("stty -echo");// ECHO DA TELA DESLIGADO	
	
}

void sp_clear(){
	
	system("clear"); // LIMPAR TELA

}


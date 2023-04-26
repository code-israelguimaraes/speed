//VARIAVEIS GLOBAIS

int MOUSE_COLOR=8;
int MOUSE_BGCOLOR=5;

int MOUSE_X=3;//original 3
int MOUSE_Y=3;//original 2

void sp_mouse(char tecla,int x,int y){
	
	if(CELULA_ATIVAR==0){
		sp_color(MOUSE_COLOR,MOUSE_BGCOLOR);
		gotoxy(x,y),printf("?");
		
		//LIMPAR CURSOR
		if(tecla==key_right || tecla==key_tab)gotoxy(MOUSE_X-WIDTH,MOUSE_Y),printf(" ");
		if(tecla==key_left)gotoxy(MOUSE_X+WIDTH,MOUSE_Y),printf(" ");
		if(tecla==key_up)gotoxy(MOUSE_X,MOUSE_Y+1),printf(" ");
		if(tecla==key_down || tecla==key_enter)gotoxy(MOUSE_X,MOUSE_Y-1),printf(" ");
	}else{
		sp_color(MOUSE_COLOR,MOUSE_BGCOLOR);
		gotoxy(x,y),printf(":");	
	}
	
}

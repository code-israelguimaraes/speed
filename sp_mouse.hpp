int MOUSE_X=4;
int MOUSE_Y=4;

void sp_cursor(char tecla,int x,int y){
	
	if(CELULA_ATIVA==0){
	
		sp_color(GUICOLOR_FG,0);
		gotoxy(x,y),printf("?");
		
		//LIMPAR CURSOR
		if(tecla==key_right)gotoxy(x-LARGURA,y),printf(" ");
		if(tecla==key_left)gotoxy(x+LARGURA,y),printf(" ");
		
		if(tecla==key_up)gotoxy(x,y+1),printf(" ");
		if(tecla==key_down or tecla==key_enter)gotoxy(x,y-1),printf(" ");
	}
	
	else{
		sp_color(GUICOLOR_FG,0);
		gotoxy(x,y),printf(":");	
	}
	
}

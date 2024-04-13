#include <fstream> // Para trabalhar com arquivos

void save(){
	
	ofstream file("speedtmp.txt");
	if(file.is_open()){
		
		for(int i=0;i<LINHA;i++){
			for(int j=0;j<COLUNA;j++){
				for(int k=0;k<LARGURA;k++){
					
					if(PLANILHA[i][j][k]!='\0'){	
						file<<PLANILHA[i][j][k];
					}else{
						file<<"#";	
					}
				}
			}
			if(COLUNA%COLUNA==0)file<<endl;	
		}
		
		file.close();
		
		//STATUS
		sp_color(GUICOLOR_FG,0);
		gotoxy(COLUNA*LARGURA-3,LINHA+5),printf("SALVO...");	
	}
	
}
	


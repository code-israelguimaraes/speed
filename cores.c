#include <stdio.h>
#include <stdlib.h>

#include  "/home/israelguimaraes/C/Games/Cgame/cgame_color.h"

int main(){

	system("clear");

	for(int i=0;i<256;i++){
		cgame_color(i);
		printf(" ██ %i\n",i);	
	}

	printf("\n\n");
	return 0;

}

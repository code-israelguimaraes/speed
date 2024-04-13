void sp_color(int num_fg,int num_bg){

	//FG
	switch(num_fg){
		case 1:
		printf("\e[0;90m");	
		break;
		
		case 2:
		printf("\e[0;91m");	
		break;
		
		case 3:
		printf("\e[0;92m");	
		break;
		
		case 4:
		printf("\e[0;93m");	
		break;
		
		case 5:
		printf("\e[0;94m");	
		break;
		
		case 6:
		printf("\e[0;95m");	
		break;
		
		case 7:
		printf("\e[0;96m");	
		break;
		
		case 8:
		printf("\e[0;97m");	
		break;
	}
	
	//BG
	switch(num_bg){
		case 1:
		printf("\e[0;100m");	
		break;
		
		case 2:
		printf("\e[0;101m");	
		break;
		
		case 3:
		printf("\e[0;102m");	
		break;
		
		case 4:
		printf("\e[0;103m");	
		break;
		
		case 5:
		printf("\e[0;104m");	
		break;
		
		case 6:
		printf("\e[0;105m");	
		break;
		
		case 7:
		printf("\e[0;106m");	
		break;
		
		case 8:
		printf("\e[0;107m");	
		break;
	}
	
}

void sp_background(int num_color){

	switch(num_color){

	case 1:
	system("echo '\e[0;41m'");	
	break;

	case 2:system("echo '\e[0;42m'");	
	break;

	case 3:system("echo '\e[0;43m'");	
	break;

	case 4:system("echo '\e[0;44m'");	
	break;

	case 5:system("echo '\e[0;45m'");	
	break;

	case 6:system("echo '\e[0;46m'");	
	break;
	
	case 7:system("echo '\e[0;47m'");	
	break;
	
	case 8:system("echo '\e[0;48m'");	
	break;
	
	case 9:system("echo '\e[0;100m'");	
	break;
	
	case 10:system("echo '\e[0;101m'");
	break;
	
	case 11:system("echo '\e[0;102m'");
	break;

	case 12:system("echo '\e[0;103m'");
	break;
	
	case 13:system("echo '\e[0;104m'");
	break;
	
	case 14:system("echo '\e[0;105m'");
	break;
	
	case 15:system("echo '\e[0;106m'");
	break;
	
	case 16:system("echo '\e[0;107m'");
	break;

	}
	
}

void sp_color(int num_color,int num_bgcolor){

	switch(num_color){

	case 1:
	printf("\033[0;30m");	
	break;

	case 2:
	printf("\033[0;31m");
	break;

	case 3:
	printf("\033[0;32m");
	break;

	case 4:
	printf("\033[0;33m");
	break;

	case 5:
	printf("\033[0;34m");	
	break;

	case 6:
	printf("\033[0;35m");
	break;
	
	case 7:
	printf("\033[0;36m");
	break;
	
	case 8:
	printf("\033[0;37m");
	break;
	
	case 9:
	printf("\033[1;90m");	
	break;
	
	case 10:
	printf("\033[1;91m");
	break;
	
	case 11:
	printf("\033[1;92m");
	break;

	case 12:
	printf("\033[1;93m");
	break;
	
	case 13:
	printf("\033[1;94m");
	break;
	
	case 14:
	printf("\033[1;95m");
	break;
	
	case 15:
	printf("\033[1;96m");
	break;
	
	case 16:
	printf("\033[1;97m");
	break;

	}
		
	switch(num_bgcolor){

	case 1:
	printf("\033[0;40m");	
	break;

	case 2:
	printf("\033[0;41m");
	break;

	case 3:
	printf("\033[0;42m");
	break;

	case 4:
	printf("\033[0;43m");
	break;

	case 5:
	printf("\033[0;44m");	
	break;

	case 6:
	printf("\033[0;45m");
	break;
	
	case 7:
	printf("\033[0;46m");
	break;
	
	case 8:
	printf("\033[0;47m");
	break;
	
	case 9:
	printf("\033[0;100m");	
	break;
	
	case 10:
	printf("\033[0;101m");
	break;
	
	case 11:
	printf("\033[0;102m");
	break;

	case 12:
	printf("\033[0;103m");
	break;
	
	case 13:
	printf("\033[0;104m");
	break;
	
	case 14:
	printf("\033[0;105m");
	break;
	
	case 15:
	printf("\033[0;106m");
	break;
	
	case 16:
	printf("\033[0;107m");
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

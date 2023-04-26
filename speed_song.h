
void sp_beep(char sound_intensity[],char sound_power[]){
	
	//INSTALL PLAY: SUDO APT-GET INSTALL PLAY
	char command[100];
	sprintf(command,"play -q -n synth %s sin %s>/dev/null 2>&1 &",sound_intensity,sound_power);
	system(command);
	
	
}

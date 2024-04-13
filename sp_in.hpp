#include <stdlib.h> // FUNCAO RAND
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <ctype.h>

/*KEYBOARD MAPPING*/

#define key_up 65 
#define key_down 66 
#define key_left 68
#define key_right 67
#define key_enter 10
#define key_spacebar 32
#define key_esc 27
#define key_tab 9

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
	
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */

void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {

  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
	
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
	
  return getch_(1);
}

int kbhit(void){
  
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

	return 0;  

}

void gotoxy(int x,int y){
	printf("%c[%d;%df",0x1B,y,x);
}

void cls_buffer(){
	printf("\033[2J");	
}

#include <ncurses.h>
#include "mv.h"
#include "dial.c"
#include "rooms.h"
#include "mwin.h"
#include <stdlib.h>

void InitCurses(){
	initscr();
  raw();
  cbreak();
  noecho(); 
	keypad(stdscr, TRUE);	
	curs_set(0);
  refresh();
}

int main(int argc, char *argv[]){

static int x; 
static int y;

int numberOfMainMenuChoices = sizeof(mainMenuChoices) / sizeof(char *);
int highlight = 1;
int currentChoice = 0;
int action = 0; /* 1. Start game
									 2. Keyboard control
									 3. Credits
									 4. Exit
								*/
InitCurses();
/*screen initialized*/
	
x = (getmaxx(stdscr) - MM_WIDTH) / 2; 
y = (getmaxy(stdscr) - MM_HEIGHT) / 2;
WINDOW *mainMenu = InitWin(y, x, MM_WIDTH, MM_HEIGHT);	

MainMenuAction(mainMenu, *mainMenuChoices, &numberOfMainMenuChoices, &highlight, &currentChoice, &action);
	do{	
	
	int Y = GetCenterY(stdscr);
	int X = GetCenterX(stdscr);
	
	switch (action){
		case 1:
			PrintMap(stdscr, 60, 30);
			StartMainGameLoop(stdscr, &Y, &X);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
	
		break;
	} while (1);
/*screen closed*/

  endwin();

  return 0;
  
}

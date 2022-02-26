#include <ncurses.h>
#include "mv.h"
#include "dial.c"
#include "rooms.h"
#include "mwin.h"

int main(int argc, char *argv[]){

static int x; 
static int y;

int currentChoice = 0;

WINDOW *mainMenu;
WINDOW *dialogWindow;
	initscr();
  raw();
  cbreak();
  noecho(); 
	keypad(stdscr, TRUE);	
	curs_set(0);
  refresh();
/*screen initialized*/
	
	x = (getmaxx(stdscr) - MM_WIDTH) / 2; 
	y = (getmaxy(stdscr) - MM_HEIGHT) / 2;
	mainMenu = newwin(MM_HEIGHT, MM_WIDTH, y, x);
	
	InitMainMenu(mainMenu, &currentChoice);
	
	int Y = GetCenterY(stdscr);
	int X = GetCenterX(stdscr);

	switch (currentChoice){
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
		
/*screen closed*/

  endwin();

  return 0;
  
}

#include <ncurses.h>
#include "mv.c"
#include "dial.c"
#include "rooms.h"
#include "mwin.c"

int main(){

  initscr();
  raw();
  cbreak();
  noecho(); 
  curs_set(0);
/*screen initialized*/
	//	PrintMap(stdscr, 60, 30);
	mainMenuGetAttrs();
	refresh();
	keypad(mainMenu, TRUE);
	renderWindow(mainMenu, highlight);
	setMenuWindowUp(mainMenu);	
/*main game loop*/
//	setCharacterMovementUp();
	/*screen closed*/
  refresh();
  endwin();

  return 0;
  
}

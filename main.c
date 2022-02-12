#include <ncurses.h>
#include "mv.h"
#include "dial.c"
#include "rooms.h"
#include "mwin.h"

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
	InitMainMenu();
/*main game loop*/
//	setCharacterMovementUp();
	/*screen closed*/
  refresh();
  endwin();

  return 0;
  
}

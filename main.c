#include <ncurses.h>
#include "mv.h"
#include "dial.c"
#include "rooms.h"
#include "mwin.h"

int main(int argc, char *argv[]){

WINDOW *mainMenu;
WINDOW *dialogWindow;

	initscr();
  raw();
  cbreak();
  noecho(); 
  curs_set(0);
  refresh();
/*screen initialized*/
	InitMainMenu(mainMenu);
/*screen closed*/

  endwin();

  return 0;
  
}

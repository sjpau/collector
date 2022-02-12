#include <ncurses.h>
#include "mv.h"
#include "dial.c"
#include "rooms.h"
#include "mwin.h"

int main(int argc, char *argv[]){

  //WINDOW* gameWindow;
  initscr();
  raw();
  //cbreak();
  noecho(); 
  //printw("TEST");
  refresh();
  //curs_set(0);
/*screen initialized*/
	//	PrintMap(stdscr, 60, 30);
	//mainMenuGetAttrs();
	//refresh();
	//InitMainMenu();
/*main game loop*/
//	setCharacterMovementUp();
	/*screen closed*/
  WINDOW* gameWindow = newwin(40, 80, 15, 15); 
  box(gameWindow, 0, 0); 
  wrefresh(gameWindow);
  PrintMap(gameWindow, 60, 30);

  getch();
  endwin();

  return 0;
  
}

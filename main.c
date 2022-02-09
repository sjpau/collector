#include <ncurses.h>
#include "mv.c"
#include "dial.c"
#include "rooms.h"


int main(){

  initscr();
  raw();
  cbreak();
  noecho(); 
  curs_set(0);
/*screen initialized*/
 /*  PrintSentence(sen); sentence is put for printing*/
  PrintMap(60, 30);
/*main game loop*/
  do {
	allowCharacterMovement();
 } while ((input != q) && (input != Q));

	/*screen closed*/
  getch();
  refresh();
  endwin();

  return 0;
  
}

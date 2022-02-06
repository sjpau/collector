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
 /*  print_sent(sen); sentence is put for printing*/
  PrintMap(60, 30);
/*main game loop*/
	int* input = (int*)malloc(10*sizeof(int));
  do {
    *input = getch();
    switch (*input){
      case w:
      case W:
        HeroMoveUp();
        break; 
      case s:
      case S:
        HeroMoveDown();
        break;
      case d:
      case D:
        HeroMoveRight();
        break;
      case a:
      case A:
        HeroMoveLeft();
        break;
    }
 } while ((*input != q) && (*input != Q));
	free(input);
	/*screen closed*/
  getch();
  refresh();
  endwin();

  return 0;
  
}

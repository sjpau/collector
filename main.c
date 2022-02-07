#include <ncurses.h>
#include "mv.c"
#include "dial.c"
#include "rooms.h"

/*keys*/
#define w         'w'
#define W         'W'
#define a         'a' 
#define A         'A'
#define s         's'
#define S         'S'
#define d         'd'
#define D         'D'
#define q         'q'
#define Q         'Q'

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
	int input;
  do {
    input = getch();
    switch (input){
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
 } while ((input != q) && (input != Q));

	/*screen closed*/
  getch();
  refresh();
  endwin();

  return 0;
  
}

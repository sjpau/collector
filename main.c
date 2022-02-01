#include <ncurses.h>
#include "mv.c"
#include "dial.c"
#include "rooms.c"

int main(){

  initscr();
  raw();
  cbreak();
  noecho(); 
  curs_set(0);
/*screen initialized*/
  print_sent(sen); /*sentence is put for printing*/
  print_map(60, 30);
/*main game loop*/
	int* input = (int*)malloc(10*sizeof(int));
  do {
    *input = getch();
    switch (*input){
      case w:
      case W:
        hero_move_up();
        break; 
      case s:
      case S:
        hero_move_down();
        break;
      case d:
      case D:
        hero_move_right();
        break;
      case a:
      case A:
        hero_move_left();
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

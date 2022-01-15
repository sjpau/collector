#include <stdlib.h>
#include <ncurses.h>
#include "mv.c"
#include "dial.c"

int main(){

  initscr();
  raw();
  cbreak();
  noecho(); 
  getmaxyx(stdscr, row, col);
  curs_set(0);
/*screen initialized*/
  print_sent(sen); /*sentence is put for printing*/
  print_map();
/*main game loop*/
	int input;
  bool key_was_preessed = false;
  do {
    input = getch();
    switch (input){
      case w:
      case W:
        hero_move_up();
        key_was_preessed = true;
        break; 
      case s:
      case S:
        hero_move_down();
        key_was_preessed = true;
        break;
      case d:
      case D:
        hero_move_right();
        key_was_preessed = true;
        break;
      case a:
      case A:
        hero_move_left();
        key_was_preessed = true;
        break;
      /*determines of the game has started*/
      if (key_was_preessed == true){
        mvaddch(((row - MX)/2 + 1), ((col - MY)/2 + 1), EMPTY);
        move(Y, X);
      }
    
    }
 } while ((input != q) && (input != Q));
/*screen closed*/
  getch();
  refresh();
  endwin();

  return 0;
  
}

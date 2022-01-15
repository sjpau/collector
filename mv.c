#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "map.c"

int allow_move_to(int y, int x){
  int check_cell; 
  check_cell = mvinch(y, x);
  return ((check_cell == EMPTY));
}


/*character movement*/
void hero_move_left(){
  if (allow_move_to(Y, X - 1)) {
    mvaddch(Y, X, EMPTY);
    X -= 1;
    mvaddch(Y, X, MVLEFT);
  }
}
void hero_move_right(){
  if (allow_move_to(Y, X + 1)){
    mvaddch(Y, X, EMPTY);
    X += 1;
    mvaddch(Y, X, MVRIGHT);
  }
}
void hero_move_up(){
  if (allow_move_to(Y - 1, X)){
    mvaddch(Y, X, EMPTY);
    Y -= 1;
    mvaddch(Y, X, MVUP);
  }
} 
void hero_move_down(){
  if (allow_move_to(Y + 1, X)){
    mvaddch(Y, X, EMPTY);
    Y += 1;
    mvaddch(Y, X, MVDOWN);
  }
}



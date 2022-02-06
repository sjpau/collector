#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "rooms.h"
#include "def.h"

static int Y;
static int X;

int CellIsEmpty(int y, int x){
  int check_cell; 
  check_cell = mvinch(y, x);
  return ((check_cell == EMPTY));
}


/*character movement*/
void HeroMoveLeft(){
  if (CellIsEmpty(Y, X - 1)) {
    mvaddch(Y, X, EMPTY);
    X -= 1;
    mvaddch(Y, X, MVLEFT);
  }
}
void HeroMoveRight(){
  if (CellIsEmpty(Y, X + 1)){
    mvaddch(Y, X, EMPTY);
    X += 1;
    mvaddch(Y, X, MVRIGHT);
  }
}
void HeroMoveUp(){
  if (CellIsEmpty(Y - 1, X)){
    mvaddch(Y, X, EMPTY);
    Y -= 1;
    mvaddch(Y, X, MVUP);
  }
} 
void HeroMoveDown(){
  if (CellIsEmpty(Y + 1, X)){
    mvaddch(Y, X, EMPTY);
    Y += 1;
    mvaddch(Y, X, MVDOWN);
  }
}



#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"

#define EMPTY     ' '
#define MVRIGHT   '3'  
#define MVLEFT    'E'
#define MVUP      'M'
#define MVDOWN    'W'

static int Y;
static int X;

int CellIsEmpty(int y, int x){
  int checkCell; 
  checkCell = mvinch(y, x);
  return ((checkCell == EMPTY));
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



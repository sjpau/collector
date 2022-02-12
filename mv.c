#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"
#include "mv.h"

static int Y;
static int X;
static int movementInput; 

int CellIsEmpty(int y, int x){
  int checkCell; 
  checkCell = mvinch(y, x);
  return ((checkCell == EMPTY));
}


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


void allowCharacterMovement(){
    movementInput = getch();
    switch (movementInput){
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
}

void setCharacterMovementUp(){
  do {
	allowCharacterMovement();
 } while ((movementInput != q) && (movementInput != Q));
}

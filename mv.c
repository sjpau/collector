#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"
#include "mv.h"
#include "rooms.h"

static int movementInput; 

int WCellIsEmpty(WINDOW *win, int y, int x){
  int checkCell; 
  checkCell = mvwinch(win, y, x);
  return ((checkCell == EMPTY));
}


void WHeroMoveLeft(WINDOW *win, int Y, int X){
  if (WCellIsEmpty(win, Y, X - 1)) {
    mvwaddch(win, Y, X, EMPTY);
    X -= 1;
    mvwaddch(win, Y, X, MVLEFT);
  }
}
void WHeroMoveRight(WINDOW *win, int Y, int X){
  if (WCellIsEmpty(win, Y, X + 1)){
    mvwaddch(win, Y, X, EMPTY);
    X += 1;
    mvwaddch(win, Y, X, MVRIGHT);
  }
}
void WHeroMoveUp(WINDOW *win, int Y, int X){
  if (WCellIsEmpty(win, Y - 1, X)){
    mvwaddch(win, Y, X, EMPTY);
    Y -= 1;
    mvwaddch(win, Y, X, MVUP);
  }
} 
void WHeroMoveDown(WINDOW *win, int Y, int X){
  if (WCellIsEmpty(win, Y + 1, X)){
    mvwaddch(win, Y, X, EMPTY);
    Y += 1;
    mvwaddch(win, Y, X, MVDOWN);
  }
}


void AllowWindowCharacterMovement(WINDOW *win, int Y, int X){
    movementInput = wgetch(win);
		wrefresh(win);
    switch (movementInput){
      case w:
      case W:
        WHeroMoveUp(win, Y, X);
        break; 
      case s:
      case S:
        WHeroMoveDown(win, Y, X);
        break;
      case d:
      case D:
        WHeroMoveRight(win, Y, X);
        break;
      case a:
      case A:
        WHeroMoveLeft(win, Y, X);
        break;
    }
}

void SetWindowCharacterMovementUp(WINDOW *win, int Y, int X){
  do {
	AllowWindowCharacterMovement(win, Y, X);
 } while ((movementInput != q) && (movementInput != Q));
}

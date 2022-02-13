#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"
#include "mv.h"

static int Y;
static int X;
static int movementInput; 

int WCellIsEmpty(WINDOW *win, int y, int x){
  int checkCell; 
  checkCell = mvwinch(win, y, x);
  return ((checkCell == EMPTY));
}


void WHeroMoveLeft(WINDOW *win){
  if (WCellIsEmpty(win, Y, X - 1)) {
    mvwaddch(win, Y, X, EMPTY);
    X -= 1;
    mvwaddch(win, Y, X, MVLEFT);
  }
}
void WHeroMoveRight(WINDOW *win){
  if (WCellIsEmpty(win, Y, X + 1)){
    mvwaddch(win, Y, X, EMPTY);
    X += 1;
    mvwaddch(win, Y, X, MVRIGHT);
  }
}
void WHeroMoveUp(WINDOW *win){
  if (WCellIsEmpty(win, Y - 1, X)){
    mvwaddch(win, Y, X, EMPTY);
    Y -= 1;
    mvwaddch(win, Y, X, MVUP);
  }
} 
void WHeroMoveDown(WINDOW *win){
  if (WCellIsEmpty(win, Y + 1, X)){
    mvwaddch(win, Y, X, EMPTY);
    Y += 1;
    mvwaddch(win, Y, X, MVDOWN);
  }
}


void AllowWindowCharacterMovement(WINDOW *win){
    movementInput = wgetch(win);
		mvwaddch(win, 13, 3, MVRIGHT);
		getyx(win,Y,X);
    switch (movementInput){
      case w:
      case W:
        WHeroMoveUp(win);
        break; 
      case s:
      case S:
        WHeroMoveDown(win);
        break;
      case d:
      case D:
        WHeroMoveRight(win);
        break;
      case a:
      case A:
        WHeroMoveLeft(win);
        break;
    }
}

void SetWindowCharacterMovementUp(WINDOW *win){
  do {
	AllowWindowCharacterMovement(win);
 } while ((movementInput != q) && (movementInput != Q));
}

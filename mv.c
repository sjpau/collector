#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"
#include "mv.h"
#include "rooms.h"

int movementInput;

int WCellIsEmpty(WINDOW *win, int y, int x){
  int checkCell; 
  checkCell = mvwinch(win, y, x);
  return ((checkCell == EMPTY));
}


void WHeroMoveLeft(WINDOW *win, int* Y, int* X){
  int x = *X - 1;
  if (WCellIsEmpty(win, *Y, x)) {
    mvwaddch(win, *Y, *X, EMPTY);
    (*X)--;
    mvwaddch(win, *Y, *X, MVLEFT);
  }
}
void WHeroMoveRight(WINDOW *win, int* Y, int* X){
  int x = *X + 1;
  if (WCellIsEmpty(win, *Y, x)){
    mvwaddch(win, *Y, *X, EMPTY);
    (*X)++;
    mvwaddch(win, *Y, *X, MVRIGHT);
  }
}
void WHeroMoveUp(WINDOW *win, int* Y, int* X){
  int y = *Y - 1;
  if (WCellIsEmpty(win, y, *X)){
    mvwaddch(win, *Y, *X, EMPTY);
    (*Y)--;
    mvwaddch(win, *Y, *X, MVUP);
  }
} 
void WHeroMoveDown(WINDOW *win, int* Y, int* X){
  int y = *Y + 1;
  if (WCellIsEmpty(win, y, *X)){
    mvwaddch(win, *Y, *X, EMPTY);
    (*Y)++;
    mvwaddch(win, *Y, *X, MVDOWN);
  }
}


void AllowWindowCharacterMovement(WINDOW *win, int* Y, int* X){

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

void SetWindowCharacterMovementUp(WINDOW *win, int* Y, int* X){
  do {
	AllowWindowCharacterMovement(win, Y, X);
 } while ((movementInput != q) && (movementInput != Q));
}

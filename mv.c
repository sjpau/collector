#include <stdlib.h>
#include <ncurses.h>
#include "rooms.h"

#define EMPTY     ' '
#define MVRIGHT   '3'  
#define MVLEFT    'E'
#define MVUP      'M'
#define MVDOWN    'W'

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


static int Y;
static int X;
static int input; 

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


void allowCharacterMovement(){
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
}

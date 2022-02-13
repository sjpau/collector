#ifndef MOVEMENT_HEADER
#define MOVEMENT_HEADER
#include <ncurses.h>

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

int WCellIsEmpty(WINDOW *win, int y, int x);
void WHeroMoveLeft(WINDOW *win);
void WHeroMoveRight(WINDOW *win);
void WHeroMoveUp(WINDOW *win);
void WHeroMoveDown(WINDOW *win);
void AllowWindowCharacterMovement(WINDOW *win);
void SetWindowCharacterMovementUp(WINDOW *win);

#endif

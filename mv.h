#ifndef MOVEMENT_HEADER
#define MOVEMENT_HEADER
#include <ncurses.h>
#include <stdbool.h>

#define EMPTY     ' '
#define MVRIGHT   '3'  
#define MVLEFT    'E'
#define MVUP      'M'
#define MVDOWN    'W'

/*keys*/
#define w        		 'w'
#define W            'W'
#define a        		 'a' 
#define A       		 'A'
#define s        		 's'
#define S      		   'S'
#define d       		 'd'
#define D        		 'D'
#define CRASH_GAME	 KEY_F(4)


int WCellIsEmpty(WINDOW *win, int y, int x);
void WHeroMoveLeft(WINDOW *win, int *Y, int *X);
void WHeroMoveRight(WINDOW *win, int *Y, int *X);
void WHeroMoveUp(WINDOW *win, int *Y, int *X);
void WHeroMoveDown(WINDOW *win, int *Y, int *X);
void AllowWindowCharacterMovement(WINDOW *win, int *Y, int *X);
void StartMainGameLoop(WINDOW *win, int *Y, int *X);

#endif

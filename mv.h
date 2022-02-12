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

int CellIsEmpty(int y, int x);
void HeroMoveLeft();
void HeroMoveRight();
void HeroMoveUp();
void HeroMoveDown();
void allowCharacterMovement();
void setCharacterMovementUp();

#endif

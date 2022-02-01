#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

int nanosleep(const struct timespec *req, struct timespec *rem);

/*keys*/
#define null_char '0'
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

/*symbol definitions*/
#define WALL      '#'
#define EMPTY     ' '
#define MVRIGHT   '3'  
#define MVLEFT    'E'
#define MVUP      'M'
#define MVDOWN    'W'

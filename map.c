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

/*map co-ords*/
#define MX 30
#define MY 60

/*window size*/
static int row; 
static int col;
/*variables*/
static char field[MX][MY]; 
static int Y; 
static int X;

void map(){ 
  /*fill in the dots*/
  for (int j = 0; j < MX; j++){ 
    for (int i = 0; i < MY; i++){
      field[j][i] = EMPTY;
    }
  }
  /*fill in the walls*/
  for (int y = 0; y < MY; y++){
    field[0][y] = WALL;
    field[MX-1][y] = WALL;
  }
  for (int x = 0; x < MX; x++){
    field[x][0] = WALL;
    field[x][MY-1] = WALL;
  }
} 

void print_map(){
  map();
  /*print out*/
  for (int j = 0; j < MX; j++){
    for (int i = 0; i<MY; i++){
       mvaddch((((row - MX)/2) + j) , (((col - MY)/2) + i), field[j][i]); /*formulas calculate the center of the screen*/
       nanosleep((const struct timespec[]){{0, 1000000L}}, NULL);
       refresh();
    }
  }
  /*starting position*/
  mvaddch(((row - MX)/2 + 1), ((col - MY)/2 + 1), MVDOWN);
  move(((row - MX)/2 + 1), ((col - MY)/2 + 1));
  getyx(stdscr,Y,X); /*assign coordinates of a starting position*/
  
}


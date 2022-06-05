#include <ncurses.h>
#include "mv.h"
#include "rooms.h"
#include <stdlib.h>

char *mainMenuChoices[] = {
	"Start game",
	"Keyboard controls",
	"Credits",
	"Exit",
};

void InitCurses(){
	initscr();
  raw();
  cbreak();
  noecho(); 
	keypad(stdscr, TRUE);	
	curs_set(0);
  refresh();
}

int main(int argc, char *argv[]){

static int x; 
static int y;

int numberOfMainMenuChoices = sizeof(mainMenuChoices) / sizeof(char *);
int highlight = 1;
int currentChoice = 0;
int action = 0; /* 1. Start game
									 2. Keyboard control
									 3. Credits
									 4. Exit
								*/
InitCurses();
/*screen initialized*/
	
	
	int Y = GetCenterY(stdscr);
	int X = GetCenterX(stdscr);
	
			PrintMap(stdscr, 60, 30);
			StartMainGameLoop(stdscr, &Y, &X);
	
/*screen closed*/

  endwin();

  return 0;
  
}

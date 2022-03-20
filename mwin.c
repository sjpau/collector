#include "mwin.h"
#include "rooms.h"
#include "mv.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>


WINDOW *InitWin(int y, int x, int width, int height){
	WINDOW *win;
	win = newwin(height, width, y, x);
	box(win, 0, 0);
	keypad(win, true);
	wrefresh(win);
	return win; 
}

void InitWinDefaultParams(struct winparams *p){
	/*set defaults here*/ 

}

void RenderMainMenuChoices(WINDOW *win, char *choices, int *noc, int *h){                                         
  int x, y, z;
  x = 5;
  y = 3;
  for (z = 0; z < *noc; ++z){
	  if (*h == z + 1){
 	  	wattron(win, A_REVERSE);
    	mvwprintw(win, y, x, "%s", &choices[z]);
    	wattroff(win, A_REVERSE);
      } else
   	  mvwprintw(win, y, x, "%s", &choices[z]);
  	++y;
}
}

void DeleteWindow(WINDOW *win){
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

void MainMenuAction(WINDOW *win, char *choices, int *noc, int *h, int *currentChoice, int *action){
	int menuInput;
	menuInput = wgetch(win);
	do{
		RenderMainMenuChoices(win, choices, noc, h);
		switch (menuInput){
			case w:
			case W:
			case KEY_UP:
				if (*h == 1)
					h = noc;
				else
					--*h;
				break;
			case s:
			case S:
			case KEY_DOWN:
				if (*h == *noc)
					*h = 1;
				else
					++*h;
				break;
			case 10:
				currentChoice = h; 
				break;
			default:
				refresh();
				break;
		}
		} while (currentChoice != h);
	DeleteWindow(win); /*Main menu choice is made*/

	switch (*currentChoice) {
		case 1:
			*action = 1;
			break;
		case 2:
			*action = 2;
			break;
		case 3:
			*action = 3; 
			break;
		case 4:
			*action = 4;
			break;
	}
}

#include <ncurses.h>
#include <stdlib.h>
#include "rooms.h"
#include "mwin.h"
#include "mv.h"


static int highlight = 1;

static char *mainMenuChoices[] = {
		"Start gaym",
		"Key bindings",
		"Credits",
		"Fuck out",
	};

static char *dialogWindowChoices[] = {
	"I'm in (Take the gig)",
	"Fuck off (Decline the gig)",
}; 

static int numOfDialogWindowChoices = sizeof(dialogWindowChoices) / sizeof(char *);
static int numOfMainMenuChoices = sizeof(mainMenuChoices) / sizeof(char *);


void RenderMainMenuChoices(WINDOW *win){

	
	int x, y, z;

	x = 5;
  y = 3;
	
	box(win, 0, 0);

	for (z = 0; z < numOfMainMenuChoices; ++z){
		if (highlight == z + 1){
			wattron(win, A_REVERSE);
			mvwprintw(win, y, x, "%s", mainMenuChoices[z]);
			wattroff(win, A_REVERSE);
		}
		else
			mvwprintw(win, y, x, "%s", mainMenuChoices[z]);
		++y;

	}
}

void SetUpMainMenu(WINDOW *win){


	int menuInput;
  bool exitMainMenu = false;
	int currentChoice = 0;
	
	int Y = GetCenterY(stdscr);
	int X = GetCenterX(stdscr);
	
	while (1){
	    menuInput = wgetch(win);
			switch (menuInput){
				case w:
				case W:
				case KEY_UP:
					if (highlight == 1)
						highlight = numOfMainMenuChoices;
					else
						--highlight;
					break;
				case s:
				case S:
				case KEY_DOWN:
					if (highlight == numOfMainMenuChoices)
						highlight = 1;
					else
						++highlight;
					break;
				case 10:
					currentChoice = highlight;
					switch(currentChoice){
						case 1:
						/*TODO: here map prints into new window and the game starts*/
							exitMainMenu = true;
		  				wrefresh(win);
							clear();
							delwin(win);	
							PrintMap(stdscr, 60, 30);
							StartMainGameLoop(stdscr, &Y, &X);
							break;
						case 2:
						/*TODO: loads window with explained default keybindings*/
							printf("%d", currentChoice);
							break;
						case 3:
						/*TODO: loads window with credits*/
							printf("%d", currentChoice);
							break;
						case 4:
							exitMainMenu = true;
							break;
					}
				default:
					refresh();
					break;
			}
			
			RenderMainMenuChoices(win);
		
		if (exitMainMenu == true){
			break;
			}	
		}
}	

void InitMainMenu(WINDOW *win){

	keypad(win, TRUE);
	RenderMainMenuChoices(win);
	SetUpMainMenu(win);	

}



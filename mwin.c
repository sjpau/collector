#include <ncurses.h>
#include <stdlib.h>
#include "rooms.h"
#include "mwin.h"
#include "mv.h"

#define MM_WIDTH  20
#define MM_HEIGHT 10

WINDOW *mainMenu;
WINDOW *dialogWindow;

static int winInitPosX = 0; 
static int winInitPosY = 0;
static int highlight = 1;
static int currentChoice = 0; 
int menuInput;

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

void renderWindow(WINDOW *win, int highlight){
	int x, y, z; 

	x = 5;
	y = 3;

	box(win, 0, 0);
	if (win == mainMenu){

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
		wrefresh(win);
	}
	else if (win == dialogWindow) {
		/*here will be inserted the dialog system*/
		for (z = 0; z < numOfDialogWindowChoices; ++z){
			if (highlight == z + 1){
				wattron(win, A_REVERSE);
				mvwprintw(win, y, x, "%s", dialogWindowChoices[z]);
				wattroff(win, A_REVERSE);
			}
			else
				mvwprintw(win, y, x, "%s", dialogWindowChoices[z]);
			++y;
		}
	}
}

void setMenuWindowUp(WINDOW *win){
	if (win == mainMenu){
		while(1){
			menuInput = wgetch(mainMenu);
			switch(menuInput){
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
					break;
				default:
					refresh();
					break;
			}
			renderWindow(mainMenu, highlight);
			if (currentChoice == 4){
				break;
			}
		}
	}
}

void mainMenuGetAttrs(){
	winInitPosX = (getmaxx(stdscr) - MM_WIDTH) / 2; 
	winInitPosY = (getmaxy(stdscr) - MM_HEIGHT) / 2;
	mainMenu = newwin(MM_HEIGHT, MM_WIDTH, winInitPosY, winInitPosX);
}

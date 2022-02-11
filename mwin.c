#include <ncurses.h>
#include <stdlib.h>
#include "rooms.h"

#define MM_WIDTH  20
#define MM_HEIGHT 10

WINDOW *mainMenu;
WINDOW *dialogWindow;

int winInitPosX = 0; 
int winInitPosY = 0;
int highlight = 1;
int currentChoice = 0; 
int menuInput;

char *mainMenuChoices[] = {
	"Start gaym",
	"Credits",
	"Fuck out",
};

char *dialogWindowChoices[] = {
	"I'm in (Take the gig)",
	"Fuck off (Decline the gig)",
}; 

int numOfDialogWindowChoices = sizeof(dialogWindowChoices) / sizeof(char *);
int numOfMainMenuChoices = sizeof(mainMenuChoices) / sizeof(char *);

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

/*TODO:include movement header and then change input chars*/
void setMenuWindowUp(WINDOW *win){
	if (win == mainMenu){
		while(1){
			menuInput = wgetch(mainMenu);
			switch(menuInput){
				case 'w':
				case 'W':
				case KEY_UP:
					if (highlight == 1)
						highlight = numOfMainMenuChoices;
					else
						--highlight;
				case 's':
				case 'S':
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
			if (currentChoice == 3){
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

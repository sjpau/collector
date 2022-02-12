#include <ncurses.h>
#include <stdlib.h>
#include "rooms.h"
#include "mwin.h"
#include "mv.h"

#define MM_WIDTH  20
#define MM_HEIGHT 10
#define GW_WIDTH 65
#define GW_HEIGHT 35

WINDOW *mainMenu;
WINDOW *dialogWindow;
WINDOW *gameplayWindow;



static int winInitPosX = 0; 
static int winInitPosY = 0;
static int currentChoice = 0; 
static bool exitMainMenu = false;
static int highlight = 1;
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

void mainMenuGetAttrs(){
	winInitPosX = (getmaxx(stdscr) - MM_WIDTH) / 2; 
	winInitPosY = (getmaxy(stdscr) - MM_HEIGHT) / 2;
	mainMenu = newwin(MM_HEIGHT, MM_WIDTH, winInitPosY, winInitPosX);
}

void gameplayWindowGetAttrs(){
	winInitPosX = (getmaxx(stdscr) - GW_WIDTH) / 2;
	winInitPosY = (getmaxy(stdscr) - GW_HEIGHT) / 2;
	gameplayWindow = newwin(GW_HEIGHT, GW_WIDTH, winInitPosY, winInitPosX);
}
void renderWindow(WINDOW *win, int highlight){
	int x, y, z; 


	box(win, 0, 0);
	if (win == mainMenu){

	x = 5;
	y = 3;
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
	else if (win == dialogWindow){
		/*here will be inserted the dialog system*/
	x = 5;
	y = 3;
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
	else if (win == gameplayWindow){
		x = 2;
		y = 2;
	}
}

void allowMainMenuChoices(){
	switch(currentChoice){
		case 1:
			/*TODO: here map prints into new window and the game starts*/
						printf("%d", currentChoice);
			exitMainMenu = true;
			gameplayWindowGetAttrs();
			refresh();
			setMenuWindowUp(gameplayWindow);
			PrintMap(gameplayWindow, 60, 30);
			setCharacterMovementUp();
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
}

void setMenuWindowUp(WINDOW *win){
	if (win == mainMenu){
		while (1){
			menuInput = wgetch(mainMenu);
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
					break;
				default:
					refresh();
					break;
			}
			renderWindow(mainMenu, highlight);
		  allowMainMenuChoices();
		if (exitMainMenu == true){
			break;
			}	
		}
	}
}

void InitMainMenu(){

	keypad(mainMenu, TRUE);
	renderWindow(mainMenu, highlight);
	setMenuWindowUp(mainMenu);	

}


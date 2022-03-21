#ifndef WINDOWS_HEADER
#define WINDOWS_HEADER
#include <ncurses.h>

#define MM_WIDTH  20
#define MM_HEIGHT 10
#define GW_WIDTH 65
#define GW_HEIGHT 35

struct winparams{
	int starty;
	int startx; 
	int width;
	int height;
};

WINDOW *InitWin(int y, int x, int width, int height);
void InitDefaultParams(struct winparams *p);
void RenderMainMenuChoices(WINDOW *win, char *choices[], int *noc, int *h);
void MainMenuAction(WINDOW *win, char *choices[], int *noc, int *h, int *currentChoice, int *action );
void DeleteWindow(WINDOW *win);

#endif

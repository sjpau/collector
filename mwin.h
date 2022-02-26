#ifndef WINDOWS_HEADER
#define WINDOWS_HEADER
#include <ncurses.h>

#define MM_WIDTH  20
#define MM_HEIGHT 10
#define GW_WIDTH 65
#define GW_HEIGHT 35

void RenderMainMenuChoices(WINDOW *win);
void SetUpMainMenu(WINDOW *win, int* currentChoice);
void InitMainMenu(WINDOW *win, int* currentChoice);
void InitMainMenuRecheck(WINDOW *win);

#endif

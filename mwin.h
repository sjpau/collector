#ifndef WINDOWS_HEADER
#define WINDOWS_HEADER
#include <ncurses.h>

void RenderMainMenuChoices(WINDOW *win);
void SetUpMainMenu(WINDOW *win);
void InitMainMenu(WINDOW *win);
void MainMenuGetAttrs(WINDOW* win, int y, int x);

#endif

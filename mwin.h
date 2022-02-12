#ifndef WINDOWS_HEADER
#define WINDOWS_HEADER
#include <ncurses.h>

void renderWindow(WINDOW *win, int highlight);

void setMenuWindowUp(WINDOW *win);

void mainMenuGetAttrs();

#endif

#include "rooms.h"
#include <ncurses.h>

/*symbol definitions*/
#define WALL      '#'

/*TODO: allow user to choose specific char symbol*/
void PrintHorizontal(int width, int stX, int stY, int edge, bool right) {
  if(right) {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(stY, stX++, WALL);
      refresh();
      napms(40);
    }
  } else {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(stY, stX--, WALL);
      refresh();
      napms(40);
    }
  } 
}

void PrintVertical(int height, int stX, int stY, int edge, bool up) {
  if(up) {
    for (int i = 0; i < height + edge; ++i) {
      mvaddch(stY--, stX, WALL);
      refresh();
      napms(40);
    }
  } else {
      for (int i = 0; i < height + edge; ++i) {
      mvaddch(stY++, stX, WALL);
      refresh();
      napms(40);
   }
  }
}

void PrintWall(char** mat, int rows, int columns, int startX, int startY) {
    int currentX = startX;
    int currentY = startY;

    for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns; j++) {
	    if (mat[i][j] == WALL) {
		    mvaddch(currentY, currentX + j, WALL);
	    }
	}
	currentX = startX;
	currentY++;
    }
}

void PrintMap(int width, int height) {
  int x;
  int y;
  
  /*allocate coordinates of the center*/
  getmaxyx(stdscr, y, x);
  int centerX = x/2;
  int centerY = y/2;

  /* should be removed after testing*/
  //mvaddch(centerY, centerX, '#');

  /*define the width and the height of squares*/
  int sqrWidth = width/2;
  int sqrHeight = height/2;

  /*selecting the starting point of drawing
   * in this case this point is bottom-right node of the map */
  int botRightX = centerX + sqrWidth + 1;
  int botRightY = centerY + sqrHeight + 1;

  /*calculating the top-right node of the map*/
  int topRightX = botRightX;
  int topRightY = botRightY - height - 2;

  /*calculating the top-left node of the map*/
  int topLeftX = botRightX - width - 2;
  int topLeftY = topRightY;

  /*calculation the bot-left node of the map*/
  int botLeftX = topLeftX;
  int botLeftY = botRightY; 
  /*Drawing edge walls*/
  PrintVertical(height, botRightX, botRightY, 3, true);
  PrintHorizontal(width, topRightX, topRightY, 3, false);
  PrintVertical(height, topLeftX, topLeftY, 3, false);
  PrintHorizontal(width, botLeftX, botLeftY, 3, true);
}

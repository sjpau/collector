#include "rooms.h"
#include "presets.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

/*symbol definitions*/
#define WALL      '#'

/*setting up drawing time interval*/
#define TINT      15

/*Prints Horizontal Wall*/
void PrintHorizontal(int width, int stX, int stY, int edge, bool right) {
  if(right) {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(stY, stX++, WALL); 
      refresh();
      napms(TINT);
    }
  } else {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(stY, stX--, WALL);
      refresh();
      napms(TINT);
    }
  } 
}

/*Prints Vertical Wall*/
void PrintVertical(int height, int stX, int stY, int edge, bool up) {
  if(up) {
    for (int i = 0; i < height + edge; ++i) {
      mvaddch(stY--, stX, WALL);
      refresh();
      napms(TINT);
    }
  } else {
      for (int i = 0; i < height + edge; ++i) {
      mvaddch(stY++, stX, WALL);
      refresh();
      napms(TINT);
   }
  }
}

/*This Function Prints Presets, see examples below in PrintMap and Read Documentation about AllocatePresets*/
void PrintWalls(int rows, int columns, char** mat, int startX, int startY) {
    int currentX = startX;
    int currentY = startY;

    for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns; j++) {
	    if (mat[i][j] == WALL) {
		    mvaddch(currentY, currentX + j, WALL);
		    refresh();
		    napms(TINT);
	    }
	}
	currentX = startX;
	currentY++;
    }
}

/*If you want to add your own preset, you must Allocate it using function AllocatePresets:
/-------------------------------------------------------------------------------------------------------
*size: Argument size represents the number of presets that should be allocated;
/-------------------------------------------------------------------------------------------------------
*mat: Argument mat is Matrix where this function allocates current Preset (in our example it is presets);
/-------------------------------------------------------------------------------------------------------
*firstD: Argument firstD represents a number of rows that your Preset contains 
    (in our example this argument remains the same for all presets and equals to 15);
/------------------------------------------------------------------------------------------------------- 
*secondD: Argument secondD represents a number of columns that your Preset contains
    (in our example this argument remains the same for all presets and equals to 30);
/-------------------------------------------------------------------------------------------------------
*preset: Argument preset represents current preset that you want to allocate
/-------------------------------------------------------------------------------------------------------
*index: Argument index represents a Matrix index that you will use to refer to your preset
/-------------------------------------------------------------------------------------------------------*/ 
void AllocatePresets(int size, char** mat[size], int firstD, int secondD, char preset[firstD][secondD], int index) {
   mat[index] = malloc(firstD * sizeof(char*));
   for (int i = 0; i < firstD; i++) {
	mat[index][i] = malloc(secondD * sizeof(char));
	for (int j = 0; j < secondD; j++) {
	    mat[index][i][j] = preset[i][j];
	}    
   }
}

/*Free Space after Allocating Matrix*/
void FreeSpace(int size, int firstD, char** mat[size]) {
    for (int matIt = 0; matIt < size; matIt++) {
	for (int i = 0; i < firstD; i++) {
	    free(mat[matIt][i]);
	}
	free(mat[matIt]);
    }
}	

/*Pseudo Random Index Generation*/
int RandomGeneration(int* banned, int max, int min) { 
    if(banned[3]) srand(time(0));
    int result = (rand()%(max - min + 1) + min);
    for(int i = 0; i < 3; i++) {
	if(result == banned[i]) {
	    banned[3] = 0;
	    result = RandomGeneration(banned, max, min);
	}
    }
    banned[3] = 1;
    return result; 
}

void PrintMap(int width, int height) {
  int edge = 3;
  int x;
  int y; 
  
  /*define the width and the height of squares*/
  int sqrWidth = width/2;
  int sqrHeight = height/2;
  
  /*allocate coordinates of the center*/
  getmaxyx(stdscr, y, x);
  int centerX = x/2;
  int centerY = y/2; 
  
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

  /*calculating the bot-left node of the map*/
  int botLeftX = topLeftX;
  int botLeftY = botRightY; 
  
  /*Drawing edge walls*/
  PrintVertical(height, botRightX, botRightY, edge, true);
  PrintHorizontal(width, topRightX, topRightY, edge, false);
  PrintVertical(height, topLeftX, topLeftY, edge, false);
  PrintHorizontal(width, botLeftX, botLeftY, edge, true);

  /*Allocating Matrix of Default Presets*/    
  int size = 10; 
  char** presets[size];
  
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN1, 0);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN2, 1);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN3, 2);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN4, 3);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN5, 4);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN6, 5);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN7, 6);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN8, 7);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN9, 8);
  AllocatePresets(size, presets, sqrHeight, sqrWidth, presetN10, 9);
  
  /*Organizing Random Presets Drawing*/
  /*Test version*/
  int index;
  int min = 0;
  int max = size - 1;
  int banned[4] = {-1, -1, -1, 1};

  index = RandomGeneration(banned, max, min);
  banned[0] = index;
  PrintWalls(sqrHeight, sqrWidth, presets[index], topLeftX + 1, topLeftY + 1);

  index = RandomGeneration(banned, max, min);
  banned[1] = index;
  PrintWalls(sqrHeight, sqrWidth, presets[index], centerX + 1, centerY +1);

  index = RandomGeneration(banned, max, min);
  banned[2] = index;
  PrintWalls(sqrHeight, sqrWidth, presets[index], topLeftX + 1, topLeftY + 1 + 16);

  index = RandomGeneration(banned, max, min);
  PrintWalls(sqrHeight, sqrWidth, presets[index], centerX + 1, centerY - 15);

  FreeSpace(size, sqrHeight, presets);
}

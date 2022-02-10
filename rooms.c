#include "rooms.h"
#include "presets.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WALL      '#'

#define PRINT_DELAY_MS      15

void PrintHorizontal(WINDOW* win, int width, int stX, int stY, int edge, bool right) {
  if (right) {
    for (int i = 0; i < width + edge; ++i) {
      mvwaddch(win, stY, stX++, WALL);
      refresh();
      napms(PRINT_DELAY_MS);
    }
  } else {
    for (int i = 0; i < width + edge; ++i) {
      mvwaddch(win, stY, stX--, WALL);
      refresh();
      napms(PRINT_DELAY_MS);
    }
  } 
}

void PrintVertical(WINDOW* win, int height, int stX, int stY, int edge, bool up) {
  if (up) {
    for (int i = 0; i < height + edge; ++i) {
      mvwaddch(win, stY--, stX, WALL);
      refresh();
      napms(PRINT_DELAY_MS);
    }
  } else {
      for (int i = 0; i < height + edge; ++i) {
      mvwaddch(win, stY++, stX, WALL);
      refresh();
      napms(PRINT_DELAY_MS);
    }
  }
}

int GetCenterX(WINDOW* win) {
    return getmaxx(win)/2;
}

int GetCenterY(WINDOW* win) {
    return getmaxy(win)/2;
}

/*This Function Prints Presets, see examples below in PrintMap and Read Documentation about AllocatePresets*/
void PrintWalls(WINDOW* win, int rows, int columns, char** mat, int startX, int startY) {
    int currentX = startX;
    int currentY = startY;

    for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns; j++) {
	    if (mat[i][j] == WALL) {
		    mvwaddch(win, currentY, currentX + j, WALL);
		    refresh();
		    napms(PRINT_DELAY_MS);
	    }
	}
	currentX = startX;
	currentY++;
    }
}

/*If you want to add your own preset, you must Allocate it using function AllocatePresets:
*mat: Argument mat is Matrix where this function allocates current Preset (in our example it is presets);
*/
void AllocatePresets(int numberOfPresets, char** mat[numberOfPresets], int rowsInPreset, int columnsInPreset, char currentPreset[rowsInPreset][columnsInPreset], int presetIndex) {
   mat[presetIndex] = malloc(rowsInPreset * sizeof(char*));
   for (int i = 0; i < rowsInPreset; i++) {
	mat[presetIndex][i] = malloc(columnsInPreset * sizeof(char));
	for (int j = 0; j < columnsInPreset; j++) {
	    mat[presetIndex][i][j] = currentPreset[i][j];
	}    
   }
}

void FreeSpace(int numberOfPresets, int rowsInPreset, char** mat[numberOfPresets]) {
    for (int matIt = 0; matIt < numberOfPresets; matIt++) {
	for (int i = 0; i < rowsInPreset; i++) {
	    free(mat[matIt][i]);
	}
	free(mat[matIt]);
    }
}	

int RandomGeneration(int* banned, int max, int min) { 
    if (banned[3]) srand(time(0));
    int result = (rand()%(max - min + 1) + min);
    for (int i = 0; i < 3; i++) {
	if (result == banned[i]) {
	    banned[3] = 0;
	    result = RandomGeneration(banned, max, min);
	}
    }
    banned[3] = 1;
    return result; 
}

void PrintMap(WINDOW* win, int width, int height) {
  int edge = 3;
  
  int sqrWidth = width/2;
  int sqrHeight = height/2;
  
  int centerX = GetCenterX(win);
  int centerY = GetCenterY(win); 
  
  int botRightX = centerX + sqrWidth + 1;
  int botRightY = centerY + sqrHeight + 1;

  int topRightX = botRightX;
  int topRightY = botRightY - height - 2;

  int topLeftX = botRightX - width - 2;
  int topLeftY = topRightY;

  int botLeftX = topLeftX;
  int botLeftY = botRightY; 
  
  PrintVertical(win, height, botRightX, botRightY, edge, true);
  PrintHorizontal(win, width, topRightX, topRightY, edge, false);
  PrintVertical(win, height, topLeftX, topLeftY, edge, false);
  PrintHorizontal(win, width, botLeftX, botLeftY, edge, true);

  int numberOfPresets = 10; 
  char** presets[numberOfPresets];
  
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN1, 0);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN2, 1);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN3, 2);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN4, 3);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN5, 4);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN6, 5);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN7, 6);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN8, 7);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN9, 8);
  AllocatePresets(numberOfPresets, presets, sqrHeight, sqrWidth, presetN10, 9);
  
  /*Organizing Random Presets Drawing*/
  /*Test version*/
  int presetIndex;
  int min = 0;
  int max = numberOfPresets - 1;
  int banned[4] = {-1, -1, -1, 1};

  presetIndex = RandomGeneration(banned, max, min);
  banned[0] = presetIndex;
  PrintWalls(win, sqrHeight, sqrWidth, presets[presetIndex], topLeftX + 1, topLeftY + 1);

  presetIndex = RandomGeneration(banned, max, min);
  banned[1] = presetIndex;
  PrintWalls(win, sqrHeight, sqrWidth, presets[presetIndex], centerX + 1, centerY +1);

  presetIndex = RandomGeneration(banned, max, min);
  banned[2] = presetIndex;
  PrintWalls(win, sqrHeight, sqrWidth, presets[presetIndex], topLeftX + 1, topLeftY + 1 + 16);

  presetIndex = RandomGeneration(banned, max, min);
  PrintWalls(win, sqrHeight, sqrWidth, presets[presetIndex], centerX + 1, centerY - 15);

  FreeSpace(numberOfPresets, sqrHeight, presets);
}

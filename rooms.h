#ifndef ROOMS_DEMO_H
#define ROOMS_DEMO_H
#include<stdbool.h>

/*To see what each fuction does, visit rooms.c*/

void PrintVertical(int height, int stX, int stY, int edge, bool up);

void PrintHorizontal(int width, int stX, int stY, int edge, bool right); 

void PrintWalls(int rows, int colunms, char** mat, int startX, int startY);

void PrintMap();

void AllocatePresets(int numberOfPresets, char** mat[numberOfPresets], int rowsInPreset, int columnsInPreset, char currentPreset[rowsInPreset][columnsInPreset], int presetIndex);

void FreeSpace(int numberOfPresets, int rowsInPreset, char** mat[numberOfPresets]);

int RandomGeneration(int* banned, int max, int min);
#endif

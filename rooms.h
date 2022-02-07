#ifndef ROOMS_DEMO_H
#define ROOMS_DEMO_H
#include<stdbool.h>

/*To see what each fuction does, visit rooms.c*/

void PrintVertical(int height, int stX, int stY, int edge, bool up);

void PrintHorizontal(int width, int stX, int stY, int edge, bool right); 

void PrintWalls(int rows, int colunms, char** mat, int startX, int startY);

void PrintMap();

void AllocatePresets(int size, char** mat[size], int firstD, int secondD, char preset[firstD][secondD], int index);

void FreeSpace(int size, int firstD, char** mat[size]);
#endif

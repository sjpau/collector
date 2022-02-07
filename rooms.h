#ifndef ROOMS_DEMO_H
#define ROOMS_DEMO_H
#include<stdbool.h>

void PrintVertical(int height, int stX, int stY, int edge, bool up);
void PrintHorizontal(int width, int stX, int stY, int edge, bool right); 
void PrintWall(int rows, int colunms, char mat[rows][colunms], int startX, int startY);
void PrintMap();

#endif

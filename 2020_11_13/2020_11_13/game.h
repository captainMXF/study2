#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define ROW 3
#define COL 3

void initboard(char arr[ROW][COL], int row, int col);
void displayboard(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col);
void computermove(char arr[ROW][COL], int row, int col);
char iswin(char arr[ROW][COL], int row, int col);
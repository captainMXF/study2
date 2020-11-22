#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void initboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}		
	}
}


void displayboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			if (j == col - 1)
			{
				printf("\n");
			}

		}
		
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
				if (j == col - 1)
				{
					printf("\n");
				}
			}
		}		
	}
}


void playermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	while (1)
	{
		printf("请输入要走的坐标\n");
		scanf("%d%d", &x, &y);
		if (1 <= x && x <= row && 1 <= y && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入：\n");
			}		
				
		}
		else
		{
			printf("坐标非法，请重新输入：\n");
		}
	}

}
void computermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

int isfull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; i < col; i++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}

	}
	return 1;

}


char iswin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			return arr[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (1 == isfull(arr, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}


}
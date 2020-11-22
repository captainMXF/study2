#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("**** 1.play   0.exit ****\n");
	printf("*************************\n");

}


void game()
{ 
	char ret = 0;
	char board[ROW][COL] = {0};
	initboard(board, ROW,COL);
	displayboard(board, ROW, COL);

	while (1)
	{
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}
void test()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			/*printf("三子棋\n");*/
			game();

			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}



int main()
{
	test();

	return 0;
}
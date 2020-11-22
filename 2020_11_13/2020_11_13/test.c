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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void test()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("�����룺\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			/*printf("������\n");*/
			game();

			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}



int main()
{
	test();

	return 0;
}
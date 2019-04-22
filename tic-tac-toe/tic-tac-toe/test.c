#include "game.h"

void menu()
{
	printf("******************\n");
	printf("****  1.play  ****\n");
	printf("****  0.exit  ****\n");
	printf("******************\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	ret = checkWin(board, ROW, COL);
	//玩游戏
	while(1)
	{
		//玩家玩
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = checkWin(board, ROW, COL);
		{
			if (ret == '*')
				break;
		}
		//电脑玩
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = checkWin(board, ROW, COL);
		if (ret == '#')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	if (ret == '#')
	{
		printf("电脑赢\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}

	
}
//测试游戏
void test()
{
	int choice;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("输入你的选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (choice);
}

int main()
{
	test();
	system("pause");
	return 0;
}
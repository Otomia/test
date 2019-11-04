//第一次下不被炸死
//周围没有雷时展开
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("****************\n");
	printf("****扫雷游戏****\n");
	printf("**** 1.play ****\n");
	printf("**** 0.exit ****\n");
	printf("****************\n");
}
void game()
{
	//使用两个数组实现扫雷，一个存放布置好的雷的信息，
	//一个存放排查出雷的信息

	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	InitBoard(mine, ROWS,COLS, '0');
	InitBoard(show, ROWS, COLS,'*');
	//布置雷
	SetMine(mine, ROW, COL);
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//第一次不被炸死
	FirstMine(mine, show, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//打印菜单
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
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
	system("pause");
	return 0;
 }
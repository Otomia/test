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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	ret = checkWin(board, ROW, COL);
	//����Ϸ
	while(1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = checkWin(board, ROW, COL);
		{
			if (ret == '*')
				break;
		}
		//������
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
		printf("���Ӯ\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}

	
}
//������Ϸ
void test()
{
	int choice;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("�������ѡ��");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ���������������\n");
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
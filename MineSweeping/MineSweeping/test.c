//��һ���²���ը��
//��Χû����ʱչ��
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("****************\n");
	printf("****ɨ����Ϸ****\n");
	printf("**** 1.play ****\n");
	printf("**** 0.exit ****\n");
	printf("****************\n");
}
void game()
{
	//ʹ����������ʵ��ɨ�ף�һ����Ų��úõ��׵���Ϣ��
	//һ������Ų���׵���Ϣ

	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��ʼ������
	InitBoard(mine, ROWS,COLS, '0');
	InitBoard(show, ROWS, COLS,'*');
	//������
	SetMine(mine, ROW, COL);
	//��ӡ����
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//��һ�β���ը��
	FirstMine(mine, show, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
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
	system("pause");
	return 0;
 }
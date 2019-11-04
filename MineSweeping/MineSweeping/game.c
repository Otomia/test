#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//ֻ��Ҫ��ӡһ��9x9������
{
	int i = 0;
	int j = 0;
	printf("-----------------------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)//��ֻ��Ҫ����9x9�ĸ�����
{
	int count = EASY_COUNT;//count������
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] = '0')//�жϴ�λ����û���ף�û���׾ͽ��±��Ϊ1��ÿ����һ���׾�Ҫcount--
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int x,int y)
{
	int count  = 0;
	count = GetMineCount(mine, x, y);
	if (count == 0)	
	{
		show[x][y] = ' ';
		if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
		{
			OpenMine(mine, show, row, col, x - 1, y);
		}
		if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == "*")
		{
			OpenMine(mine, show, row, col, x - 1, y + 1);
		}
		if (x > 0 && y + 1 <= col && show[x][y + 1] == "*")
		{
			OpenMine(mine, show, row, col, x, y + 1);
		}
		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == "*")
		{
			OpenMine(mine, show, row, col, x + 1, y + 1);
		}
		if (x + 1 <= row && y > 0 && show[x + 1][y] == "*")
		{
			OpenMine(mine, show, row, col, x + 1, y);
		}
		if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == "*")
		{
			OpenMine(mine, show, row, col, x + 1, y - 1);
		}
		if (x > 0 && y - 1 > 0 && show[x][y - 1] == "*")
		{
			OpenMine(mine, show, row, col, x, y - 1);
		}
		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == "*")
		{
			OpenMine(mine, show, row, col, x - 1, y - 1);
		}
		
	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
	
}

void FirstMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret =1;
	int count = 0;
	printf("����Ҫ�Ų������->");
	scanf("%d%d", &x, &y);
	if (mine[x][y] == '1')//�����һ�����������Ϊ��
	{
		mine[x][y] = '0';//�������Ϊ��0��
		count = GetMineCount(mine, x, y);//��ȡ��Χ�׵ĸ���
		show[x][y] = count + '0';
		while (ret)//�������λ������
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	}
	OpenMine(mine, show, row, col, x, y);
	DisplayBoard(show, row, col);
}
int IsWin(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����Ҫ�Ų�����꣺");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("��ը���ˣ�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
				if (IsWin(show, row, col) == EASY_COUNT)
				{
					break;
				}
			}
		}
		else
		{
			printf("��������Ƿ�\n");
		}
	}
	if (IsWin(show, row, col ) == EASY_COUNT)
	{
		printf("���׳ɹ���\n");
		DisplayBoard(mine, ROW, COL);
	}
}

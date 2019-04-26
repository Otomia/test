#define _CRT_SECURE_NO_WARNINGS 1
//1.5位运动员参加了10米跳水比赛，有人让他们预测比赛结果，
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛名次
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0 ;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a < 6; a++)
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)
					{
						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1)
						{
							if (a*b*c*d*e == 120)
							{
								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer !=  'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer = %c\n", killer);
		}
	}
	system("pause");
	return 0;
}

//打印杨辉三角
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100][100] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	printf("输入打印的杨辉三角的行数（1<n<100）:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;//每一行第一个值都为1
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);//输出数组元素
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
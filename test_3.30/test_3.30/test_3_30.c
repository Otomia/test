/* 
  ��ӡ100~200�������
*/

/*
  100��200֮���ż��������������������������֮�������֮��ѡ��������
  i������������i/2�������
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, t;
	printf("100-200�������У�\n");
	for (i = 101; i <= 200; i+=2)
	{
		t = i/2;
		for (j = 2; j <= t; j++)
		{
			if (i%j == 0)
				break;
		}
		if (j > t)
			printf("%d ", i);
	}
	system("pause");
	return 0;
}
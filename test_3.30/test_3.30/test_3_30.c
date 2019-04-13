/* 
  打印100~200间的素数
*/

/*
  100到200之间的偶数不可能是素数，所以在他们之间的质数之间选择素数，
  i不可能整除比i/2更大的数
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, t;
	printf("100-200的素数有：\n");
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
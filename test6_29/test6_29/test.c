#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x1 = 8;
	int x2 = 0;
	int x3 = 0;
	int sum1 = 0;
	int temp1  = (240 - x1) / 45;
	int temp2 = (240 - x2) / 45;
	while (scanf("%d%d", &x1, &x3)!= EOF)
	{
		for (x2 = 18; x2 <= 20; x2++)
		{
			sum1 = 5 * (10 + x1) + temp1 * x2 * 5 + 5*(x3-x1)+temp2*5*x2;
		}
		printf("sum1=%d\n", sum1);
		printf("temp1=%d\n", temp1);
		printf("temp2=%d\n", temp2);
	}
		
	

	
	system("pause");
	return 0;
}
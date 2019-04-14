//将数组A中的内容与数组B中内容进行交换。（数组一样大）
#include<stdio.h>
int main()
{
	int A[3] = { 4,7,8 };
	int B[3] = { 2,6,9 };
	int i, t;
	printf("数组A: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", A[i]);
	}
	printf(" 数组B: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", B[i]);
	}
	for (i = 0; i < 3; i++)
	{
		t = A[i];
		A[i] = B[i];
		B[i] = t;
	}
	printf("\n交换后\n");
	printf("数组A: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", A[i]);
	}
	printf(" 数组B: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}

//计算1/1-1/2+1/3-1/4+1/5....+1/99-1/100的值

#include<stdio.h>
int main()
{
	double sum1 = 0 , sum2 = 0;
	int i = 0;
	double sum;
	for (i = 1; i < 100; i += 2)
	{
		sum1 = sum1 + 1.0 / i;
	}
	for (i = 2; i <= 100; i += 2)
	{
		sum2 = sum2 + 1.0 / i;
	}
	sum = sum1 - sum2;
	printf("%f\n", sum);
	return 0;
}

//编写程序数一下1到100的所有整数中出现多少次数字9.
//i%10==9

#include<stdio.h>
int main()
{
	int count=0;
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
	}
	printf("1到100出现数字9的次数为：%d\n", count);
	return 0;
}
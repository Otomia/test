#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 2 * i ; j++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j <= 10 - 2 * i; j++)
			printf("*");
		printf("\n");

	}
	return 0;
}

#include<stdio.h>
int main()
{
	int a, b, c;
	int i = 0;
	for (i =100; i <= 999; i++)
	{
		a = (i / 100) % 10;//��ȡ��λ��
		b = (i / 10) % 10;//��ȡʮλ��
		c = i % 10;//��ȡ��λ��
		if ((a*a*a + b*b*b + c*c*c) == i)
			printf("%d ", i);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int i = 0;
	int sum = 0;
	int a, t = 0;
	printf("���������֣�");
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		t = t * 10 + a;
		sum = sum + t;
	}
	printf("%d ��ǰ5����ǣ�%d\n",a, sum);
	return 0;
}
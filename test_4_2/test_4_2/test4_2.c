//给定两个整型变量的值，将两个值的内容交换
#include<stdio.h>
int main()
{
	int a = 3, b = 5;
	int t;
	printf("原始值：a = %d, b = %d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("交换后：a = %d, b = %d\n", a, b);
	return 0;
}

//不允许创建临时变量，交换内容
#include<stdio.h>
int main()
{
	int a = 3, b = 5;
	printf("交换前：%d,%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换后：%d,%d\n", a, b);
	return 0;
}

//求10个整数中最大值
#include<stdio.h>
int main()
{
	int max=0;
	int i=0;
	int a[10] = {0};
	printf("请输入10个整数;");
	while (i < 10)
	{
		scanf("%d", &a[i]);
		i++;
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	printf("最大值为:%d\n", max);
	system("pause");
	return 0;
}

//将三个数从大到小输出
#include <stdio.h>
int main()
{
	int a, b, c, t;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("从大到小输出：%d %d %d", a, b, c);
	return 0;
}

//求两个数的最大公约数

#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
	int t, r;
	if (a < b)//确保是大数除小数
	{
		t = a;
		a = b;
		b = t;
	}
	while ((a%b) != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	printf("请输入两个数：");
	scanf("%d %d", &a, &b);
	printf("最大公约数为：%d\n", gcd(a, b));
	return 0;
}


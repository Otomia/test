#define _CRT_SECURE_NO_DEPRECATE
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
 
#include<stdio.h>
void print_mul(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%dx%d=%-2d  ", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int a = 0;
	printf("输入数字：");
	scanf("%d", &a);
	print_mul(a);
	return 0;
}

//2.使用函数实现两个数的交换。

#include<stdio.h>
void swap(int * x, int * y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
int main()
{
	int a, b;
	printf("输入两个数字：");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("交换后:a = %d,b = %d\n", a, b);
	return 0;
}

//3.实现一个函数判断year是不是润年。

#include<stdio.h>
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0))
		return 1;
	return 0;
}
int main()
{
	int year;
	int ret = 0;
	printf("输入年份：");
	scanf("%d", &year);
	ret = is_leap_year(year);
	if (ret == 1)
		printf("是闰年\n");
	else
		printf("不是闰年\n");
	system("pause");
	return 0;
}

//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

#include<stdio.h>
void init(int arr[], int len)
{
	int i = 0;
	for (i = 1; i <= len; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void empty(int arr[], int len)
{
	int i = 0;
	for (i = 1; i <= len; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
}
void reverse(int arr[], int len)
{
	int i = 0;
	int t = 0;
	for (i = 0; i <= len/2; i++)
	{
		t = arr[i];
		arr[i] = arr[len - i];
		arr[len - i] = t;
	}
	for (i = 0; i <= len; i++)
	{ 
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[10];
	int len = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	printf("输入10个整数：");
	init(arr, len);
	printf("逆置后的数组：");
	reverse(arr, len);
	printf("\n");
	printf("置空后的数组：");
	empty(arr, len);
	system("pause");
	return 0;
}

//5.实现一个函数，判断一个数是不是素数。

#include<stdio.h>
int is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= n / 2; i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;

}
int main()
{
	int a;
	int ret = 0;
	printf("输入一个数：");
	scanf("%d", &a);
	ret = is_prime(a);
	if (ret == 1)
		printf("是素数\n");
	else
		printf("不是素数\n");
	return 0;
}
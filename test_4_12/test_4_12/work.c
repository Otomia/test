#define _CRT_SECURE_NO_DEPRECATE
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
 
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
	printf("�������֣�");
	scanf("%d", &a);
	print_mul(a);
	return 0;
}

//2.ʹ�ú���ʵ���������Ľ�����

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
	printf("�����������֣�");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("������:a = %d,b = %d\n", a, b);
	return 0;
}

//3.ʵ��һ�������ж�year�ǲ������ꡣ

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
	printf("������ݣ�");
	scanf("%d", &year);
	ret = is_leap_year(year);
	if (ret == 1)
		printf("������\n");
	else
		printf("��������\n");
	system("pause");
	return 0;
}

//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

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
	printf("����10��������");
	init(arr, len);
	printf("���ú�����飺");
	reverse(arr, len);
	printf("\n");
	printf("�ÿպ�����飺");
	empty(arr, len);
	system("pause");
	return 0;
}

//5.ʵ��һ���������ж�һ�����ǲ���������

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
	printf("����һ������");
	scanf("%d", &a);
	ret = is_prime(a);
	if (ret == 1)
		printf("������\n");
	else
		printf("��������\n");
	return 0;
}
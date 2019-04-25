#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数返回二进制中1的个数
//比如：15 1111 4 个 1
//程序原型
//int count_one_bits(unsigned int value)
//{
//	//返回1的位数
//}
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value != 0)
//	{
//		if ((value & 1 ) == 1)
//		{
//			count++;
//		}
//		value = value >> 1;
//	}
//	return count;
//}
//int main()
//{
//	unsigned int value = 0;
//	int ret = 0;
//	printf("输入数字：");
//	scanf("%d", &value);
//	ret = count_one_bits(value);
//	printf("%d\n", ret);
//	return 0;
//}
//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列
//#include<stdio.h>
//int main()
//{
//	int value = 0;
//	int i = 0;
//	printf("输入数字：");
//	scanf("%d", &value);
//	printf("\n偶数序列：");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		if ((value >> i) & 1)
//		{
//			printf("1");
//		}
//		else
//		{
//			printf("0");
//		}
//	}
//	printf("\n");
//	printf("奇数序列：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		if ((value >> i) & 1)
//		{
//			printf("1");
//		}
//		else
//		{
//			printf("0");
//		}
//	}
//	printf("\n");
//	return 0;
//}

//输出一个整数的每一位
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int value = 0;
//	int i = 0;
//	printf("输入一个整数：");
//	scanf("%d", &value);
//	printf("整数的每一位为：");
//	for (i = 31; i >= 0; i--)
//	{
//		if ((value >> i) & 1)
//		{
//			printf("1");
//		}
//		else
//		{
//			printf("0");
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位（bit）不同？
//输入例子：
// 1999 2299 
//输出例子： 7
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int count = 0;
	int i = 0;
	printf("输入两个整数：");
	scanf("%d%d", &a, &b);
	for (i = 31; i >= 0; i--)
	{
		if (((a >> i) & 1) != ((b >> i) & 1))
		{
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
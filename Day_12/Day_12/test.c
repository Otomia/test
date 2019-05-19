#define _CRT_SECURE_NO_DEPRECATE
/*
1.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值value的二进制位模式从左到右翻转后的值。

如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int ret = 0;
	for (i = 0; i < 32; ++i)
	{
		ret = ret + ((value >> i) & 1)*pow(2, 31 - i);
	}
	return ret;
}
int main()
{
	unsigned int a = 0;
	unsigned int res = 0;
	printf("输入一个值->");
	scanf("%u", &a);
	res = reverse_bit(a);
	printf("翻转后的值为->%u\n",res);
	system("pause");
	return 0;
}

/*
2.不使用（a+b）/2这种方式，求两个数的平均值。
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int avg = 0;
	printf("输入两个数字：");
	scanf("%d%d", &a, &b);
	avg = (a&b) + (a^b) / 2;
	printf("平均值为：%d\n", avg); 
	system("pause");
	return 0;
}

/*
3.编程实现：
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
请找出这个数字。（使用位运算）
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; ++i)
	{
		arr[0] = arr[0] ^ arr[i];//数组中的每个数异或
	}
	printf("成单的数为：%d\n", arr[0]);
	return 0;
}

/*
4.
有一个字符数组的内容为:"student a am i",
请你将数组的内容改为"i am a student".
要求：
不能使用库函数。
只能开辟有限个空间（空间个数和字符串的长度无关）。

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void swap(char *left, char *right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse(char *arr)
{
	//整体逆置
	int len = strlen(arr);
	swap(arr, arr + len - 1);
	//每个单词的逆置
	while (*arr != '\0')//若arr不等于\0说明还没有到最后一个单词
	{
		char *start = arr;//单词的起始位置
		char *end = start;//单词的结束位置
		while ((*end != ' ') && (*end != '\0'))//连接符必须为&&
		{
			end++;//end指向空格位置的地址
		}
		swap(start, end - 1);
		//单词的起始位置为start，结束位置为空格前一个字符（end-1）
		if (*end != '\0')
			arr = end + 1;
		//当结束一个单词的逆置后，下一个单词的开始为空格后一个字符（end+1）
		else
			arr = end;

	}
}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);//完成整个过程的逆序,只传递这个数组过去，不用传数组的大小
	printf("%s\n", arr);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_DEPRECATE
/*
1.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
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
	printf("����һ��ֵ->");
	scanf("%u", &a);
	res = reverse_bit(a);
	printf("��ת���ֵΪ->%u\n",res);
	system("pause");
	return 0;
}

/*
2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int avg = 0;
	printf("�����������֣�");
	scanf("%d%d", &a, &b);
	avg = (a&b) + (a^b) / 2;
	printf("ƽ��ֵΪ��%d\n", avg); 
	system("pause");
	return 0;
}

/*
3.���ʵ�֣�
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
���ҳ�������֡���ʹ��λ���㣩
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; ++i)
	{
		arr[0] = arr[0] ^ arr[i];//�����е�ÿ�������
	}
	printf("�ɵ�����Ϊ��%d\n", arr[0]);
	return 0;
}

/*
4.
��һ���ַ����������Ϊ:"student a am i",
���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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
	//��������
	int len = strlen(arr);
	swap(arr, arr + len - 1);
	//ÿ�����ʵ�����
	while (*arr != '\0')//��arr������\0˵����û�е����һ������
	{
		char *start = arr;//���ʵ���ʼλ��
		char *end = start;//���ʵĽ���λ��
		while ((*end != ' ') && (*end != '\0'))//���ӷ�����Ϊ&&
		{
			end++;//endָ��ո�λ�õĵ�ַ
		}
		swap(start, end - 1);
		//���ʵ���ʼλ��Ϊstart������λ��Ϊ�ո�ǰһ���ַ���end-1��
		if (*end != '\0')
			arr = end + 1;
		//������һ�����ʵ����ú���һ�����ʵĿ�ʼΪ�ո��һ���ַ���end+1��
		else
			arr = end;

	}
}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);//����������̵�����,ֻ������������ȥ�����ô�����Ĵ�С
	printf("%s\n", arr);
	system("pause");
	return 0;
}
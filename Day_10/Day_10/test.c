#define _CRT_SECURE_NO_WARNINGS 1
//дһ���������ض�������1�ĸ���
//���磺15 1111 4 �� 1
//����ԭ��
//int count_one_bits(unsigned int value)
//{
//	//����1��λ��
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
//	printf("�������֣�");
//	scanf("%d", &value);
//	ret = count_one_bits(value);
//	printf("%d\n", ret);
//	return 0;
//}
//��ȡһ�������������������е�ż��λ������λ���ֱ��������������
//#include<stdio.h>
//int main()
//{
//	int value = 0;
//	int i = 0;
//	printf("�������֣�");
//	scanf("%d", &value);
//	printf("\nż�����У�");
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
//	printf("�������У�");
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

//���һ��������ÿһλ
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int value = 0;
//	int i = 0;
//	printf("����һ��������");
//	scanf("%d", &value);
//	printf("������ÿһλΪ��");
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

//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ��bit����ͬ��
//�������ӣ�
// 1999 2299 
//������ӣ� 7
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int count = 0;
	int i = 0;
	printf("��������������");
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
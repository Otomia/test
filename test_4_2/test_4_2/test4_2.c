//�����������ͱ�����ֵ��������ֵ�����ݽ���
#include<stdio.h>
int main()
{
	int a = 3, b = 5;
	int t;
	printf("ԭʼֵ��a = %d, b = %d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("������a = %d, b = %d\n", a, b);
	return 0;
}

//����������ʱ��������������
#include<stdio.h>
int main()
{
	int a = 3, b = 5;
	printf("����ǰ��%d,%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("������%d,%d\n", a, b);
	return 0;
}

//��10�����������ֵ
#include<stdio.h>
int main()
{
	int max=0;
	int i=0;
	int a[10] = {0};
	printf("������10������;");
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
	printf("���ֵΪ:%d\n", max);
	system("pause");
	return 0;
}

//���������Ӵ�С���
#include <stdio.h>
int main()
{
	int a, b, c, t;
	printf("����������������");
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
	printf("�Ӵ�С�����%d %d %d", a, b, c);
	return 0;
}

//�������������Լ��

#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
	int t, r;
	if (a < b)//ȷ���Ǵ�����С��
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
	printf("��������������");
	scanf("%d %d", &a, &b);
	printf("���Լ��Ϊ��%d\n", gcd(a, b));
	return 0;
}


//������A�е�����������B�����ݽ��н�����������һ����
#include<stdio.h>
int main()
{
	int A[3] = { 4,7,8 };
	int B[3] = { 2,6,9 };
	int i, t;
	printf("����A: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", A[i]);
	}
	printf(" ����B: ");
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
	printf("\n������\n");
	printf("����A: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", A[i]);
	}
	printf(" ����B: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}

//����1/1-1/2+1/3-1/4+1/5....+1/99-1/100��ֵ

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

//��д������һ��1��100�����������г��ֶ��ٴ�����9.
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
	printf("1��100��������9�Ĵ���Ϊ��%d\n", count);
	return 0;
}
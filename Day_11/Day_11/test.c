#define _CRT_SECURE_NO_WARNINGS 1
//1.5λ�˶�Ա�μ���10����ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ����������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0 ;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a < 6; a++)
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)
					{
						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1)
						{
							if (a*b*c*d*e == 120)
							{
								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer !=  'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer = %c\n", killer);
		}
	}
	system("pause");
	return 0;
}

//��ӡ�������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100][100] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	printf("�����ӡ��������ǵ�������1<n<100��:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;//ÿһ�е�һ��ֵ��Ϊ1
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);//�������Ԫ��
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
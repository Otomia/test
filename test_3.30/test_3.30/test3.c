/*
  ��ӡ1000-2000֮�������
*/

/*
  ����
  ��ͨ���꣺�ܱ�4���������ܱ�100����
  �������꣺�ܱ�400����
*/
#include<stdio.h>
int main()
{
	int n;
	printf("1000-2000��������:\n ");
	for (n = 1000; n <= 2000; n++)
	{
		if (n % 4 == 0 && n % 100 != 0)
			printf("%d ", n);
		else if (n % 400 == 0)
			printf("%d ", n);
	}

	system("pause");
	return 0;
}
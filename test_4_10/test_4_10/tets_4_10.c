#define _CRT_SECURE_NO_DEPRECATE
//��������Ϸ
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game()
{
	int random_num = rand() % 100 + 1;
	int input = 0;
	while (1)
	{
		printf("������µ����֣�");
		scanf("%d", &input);
		if (input < random_num)
		{
			printf("��С��\n");
		}
		else if (input > random_num)
		{
			printf("�´���\n");
		}
		else
		{
			printf("�¶��ˣ���ϲ�㣡\n");
			break;
		}

	}
}
void menu()
{
	printf("********************\n");
	printf("**** 1.play ****\n");
	printf("**** 0.exit ****\n");
	printf("********************\n");
}
int main()
{
	int  input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}

//�۰����
#include<stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right-left) / 2;
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;//û���ҵ�
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int key = 5;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int ret;
	ret = bin_search(arr, left, right, key);
	if (ret == -1)
		printf("û���ҵ�");
	else
		printf("�ҵ��ˣ��±�Ϊ��%d\n", ret);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("����������:");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			printf("�������!\n");
		}
	}
	if (i == 3)
		printf("���������������\n");
	return 0;
}

#include<stdio.h>
int main()
{
	int ch = 0;
	printf("������һ���ַ���");
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
			printf("%c", ch);
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + 32;
			printf("%c", ch);
		}
		else if (ch >= 0 && ch <= 9)
		{

		}
	}
	return 0;
}
//

#include<stdio.h>
void func1(char p[10])
{
	printf("3.%d\n", sizeof(p));
}

int main()
{
	char array[] = "abcdefg";
	char *p = "abcdefg";
	char b[10];
	printf("1.%d\n", sizeof(array));
	printf("2.%d\n", sizeof(p));
	func1(b[10]);
	printf("%d\n", sizeof(char[2]));
	system("pause");
	return 0;
}
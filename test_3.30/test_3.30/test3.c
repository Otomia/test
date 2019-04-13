/*
  打印1000-2000之间的闰年
*/

/*
  闰年
  普通闰年：能被4整除但不能被100整除
  世纪闰年：能被400整除
*/
#include<stdio.h>
int main()
{
	int n;
	printf("1000-2000的闰年有:\n ");
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
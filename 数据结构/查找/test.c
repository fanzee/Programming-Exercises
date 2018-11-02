#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	static int step = 0;
	scanf_s("%d", &num);
	if (num <= 1000)
	{
		while (num != 1)
		{
			if (num % 2 == 0)
			{
				num /= 2;
				step++;
			}
			else
			{
				num = (3 * num + 1)/ 2;
				step++;
			}
		}
		printf("%d", step);
	}
	system("pause");
	return 0;
}
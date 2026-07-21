#include <stdio.h>
#include<math.h>

int main()
{
	int i, j = 0, a = 7, n = 4, flag = 0, num;
	int arr[10001] = { 0, 2,3,5 }, sum[50] = {0};
	
	while (n <= 10000)
	{
		for (i = 2; i <= sqrt(a); i++)
		{
			if (a%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			flag = 0;
		}
		else
		{
			arr[n] = a;
			++n;
		}
		a += 2;
	}
	
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		for (i = 1; i <= num; i++)
		{
			sum[j] += arr[i];
		}
		++j;
	}
	
	for (i = 0; i < j; i++)
	{
		printf("%d\n",sum[i]);
	}

	return 0;
}

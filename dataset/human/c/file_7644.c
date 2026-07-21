#include <stdio.h>
int main(void)
{
	int num[10000],i;
	

	for (i = 0; i < 10000; i++)
	{
		scanf("%d", &num[i]);

		if (num[i]!=0)
		{
			printf("Case %d: %d\n", i + 1, num[i]);
		}

		else
		{
			break;
		}
	}

	return 0;
}

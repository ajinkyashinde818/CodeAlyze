#include<stdio.h>

int main(void)
{
	int  x[10000], y;
	int i = 0;
	while (1)
	{
		scanf("%d", &y);
		x[i] = y;
		i++;

		if (y == 0)
		{
			break;
		}
	}
		i = 0;
		while (x[i] != NULL)
		{
			printf("Case %d: %d\n", i + 1, x[i]);
			i++;
		}
	
	return 0;
}

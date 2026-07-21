#include<stdio.h>
int main()
{
	int x[10000],i,j=0;
	for (i = 0; i < 10000; i++)
	{
		scanf("%d", &x[i]);
		if (x[i] == 0)
		{
			break;
		}
		j++;
	}
	for (i = 0; i < j; i++)
	{
		printf("Case %d: %d\n", i+1, x[i]);
	}
	return 0;
}

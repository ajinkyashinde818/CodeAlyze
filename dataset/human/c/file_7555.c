#include<stdio.h>

int main()
{
	int s, i, x[10000];

	for (i = 0;; i++)
	{
		scanf("%d", &x[i]);
		s = i;
		if (x[i] == 0)break;
	}
	for (i = 0; i < s; i++)
	{
		printf("Case %d: %d\n", i + 1, x[i]);
	}

	return(0);

}

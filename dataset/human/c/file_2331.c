#include<stdio.h>
int main()
{
	int n, k, s;
	scanf("%d %d %d", &n, &k, &s);
	int i;
	if (k == 0)
	{
		if (s < 1000000000)
		{
			printf("%d", s + 1);
			for (i = 1; i < n; i++)
				printf(" %d", s + 1);
		}
		else
		{
			printf("1");
			for (i = 1; i < n; i++)
				printf(" 1");
		}
		printf("\n");
	}
	else
	{
		printf("%d", s);
		for (i = 1; i < k; i++)
			printf(" %d", s);
		if (s < 1000000000)
			for (i = k; i < n; i++)
				printf(" %d", s + 1);
		else
			for (i = k; i < n; i++)
				printf(" 1");
		printf("\n");
	}
	return 0;
}

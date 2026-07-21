#include <stdio.h>

int main(void)
{
	int n, d, x;
	scanf("%d%d%d", &n,&d,&x);
	int a[n];
	int i = 0;
	while (i < n)
	{
		scanf("%d", &a[i]);
		i++;
	}
	int j;
	int count = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < d)
		{
			if ((j * a[i]) + 1 <= d)
				count++;
			else
				break;
			j++;
		}
		i++;
	}
	printf("%d\n", count+x);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k;
	scanf("%d %d",&n, &k);
	int *h;
	h = (int *)malloc(sizeof(int)*(n));
	int i = 0;
	while (i < n)
	{
		scanf("%d",&h[i]);
		i++;
	}
	int sum = 0;
	i = 0;
	while (i < n)
	{
		if(h[i] >= k)
		{
			sum++;
		}
		i++;
	}
	printf("%d\n",sum);
	return (0);
}

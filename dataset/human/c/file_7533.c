#include <stdio.h>

int main(void)
{
	int i, j, a, b[10000];

	i = 0;

	scanf("%d", &a);
	
	while(a != 0)
	{
		b[i] = a;
		i++;
		scanf("%d", &a);
	}

	for(j=0;j<i;j++)
	{
		printf("Case %d: %d\n", j+1, b[j]);
	}

	return 0;
}

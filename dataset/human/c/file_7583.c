#include<stdio.h>

int main(void)
{
	int i = 1;
	int array[10000];
	while (1)
	{
		scanf("%d", &array[i]);
		if (array[i] == 0)break;
		i++;
	}
	
	for (int k = 1; k < i; k++)
	{
		printf("Case %d: %d\n", k, array[k]);
	}

	return 0;
}

#include <stdio.h>

int a[200000];

int main()
{
	long long int max = -20000000000;
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	int min = a[0];
	for(i = 1; i < n; i++)
	{
		max = max > a[i] - min ? max : a[i] - min;
		min = min < a[i] ? min : a[i];
	}
	printf("%d\n", max);
		
	return 0;
}

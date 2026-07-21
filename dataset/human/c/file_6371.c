#include <stdio.h>

int main(void)	{
	int i, j, n, max, min, a[200000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)	{
		scanf("%d", &a[i]);
	}
	max = -1000000000;
	min = a[0];
	
	for (i = 1; i < n; i++)  {
		if ( a[i] - min > max)
			max = a[i] - min;
		if (a[i] < min)
			min = a[i];
	} 
	printf("%d\n", max);
	return 0;	
}

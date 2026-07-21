#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[55];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int max, min;
	max = min = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > a[max])
			max = i;
		if (a[i] < a[min])
			min = i;
	}
	printf("%d\n", 2 * n - 2);
	if (a[max] + a[min] >= 0)
	{
		for (i = 0; i < n; i++)
			if (i != max)
				printf("%d %d\n", max + 1, i + 1);
		for (i = 0; i < n - 1; i++)
			printf("%d %d\n", i + 1, i + 2);
	}
	else
	{
		for (i = 0; i < n; i++)
			if (i != min)
				printf("%d %d\n", min + 1, i + 1);
		for (i = n - 1; i > 0; i--)
			printf("%d %d\n", i + 1, i);
	}
	return 0;
}

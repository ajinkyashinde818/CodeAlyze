#include<stdio.h>

int main(void)
{
	int n;
	int a[20], b[20], c[19];
	int sum = 0;
	scanf("%d", &n);

	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (size_t i = 0; i < n - 1; i++)
	{
		scanf("%d", &c[i]);
	}

	sum = b[0];
	for (size_t i = 1; i < n; i++)
	{
		sum += b[i];
		if (a[i - 1] + 1 == a[i])
		{
			sum += c[a[i - 1] - 1];
		}
	}

	printf("%d", sum);

	return 0;
}

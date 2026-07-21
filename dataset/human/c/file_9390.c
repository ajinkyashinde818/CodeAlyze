#include<stdio.h>
int main()
{
	int N, X, D;
	scanf("%d", &N);
	scanf("%d %d", &D, &X);
	int a[100] = {};
	int i;
	int sum = X;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		sum += 1 + (D - 1) / a[i];
	}

	printf("%d", sum);
	return 0;
}

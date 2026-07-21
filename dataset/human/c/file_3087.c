#include<stdio.h>
int main()
{
	int k, n;
	scanf("%d %d", &k, &n);
	int i;
	int a[200005];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int max = 0;
	for (i = 0; i < n; i++)
		if (max < (a[(i + 1) % n] - a[i] + k) % k)
			max = (a[(i + 1) % n] - a[i] + k) % k;
	printf("%d\n", k - max);
	return 0;
}

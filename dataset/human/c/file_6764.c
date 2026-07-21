#include<stdio.h>
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a[200005];
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int min, mid, max;
	min = 0;
	max = 0;
	for (i = 0; i < n; i++)
		if (max < a[i])
			max = a[i];
	int cnt;
	while (max - min > 1)
	{
		mid = (max + min) / 2;
		cnt = 0;
		for (i = 0; i < n; i++)
			if ((a[i] + mid - 1) / mid > 0)
				cnt += (a[i] + mid - 1) / mid - 1;
		if (cnt > k)
			min = mid;
		else
			max = mid;
	}
	printf("%d\n", max);
	return 0;
}

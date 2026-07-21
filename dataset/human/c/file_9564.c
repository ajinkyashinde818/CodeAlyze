#include<stdio.h>
#include<stdlib.h>
int a[101];
int b[101];
int main()
{
	int i, j = 1;
	int n, d, x, ans = 0;
	scanf("%d", &n);
	scanf("%d%d", &d, &x);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		int j = 1;
		while (a[i] * j + 1 <= d)
			j++;
		b[i] = j;
			
	}
	for (i = 0; i < n; i++)
		ans += b[i];
	ans = ans + x;
	printf("%d", ans);
	return 0;
}

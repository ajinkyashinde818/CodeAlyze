#include <stdio.h>
#include <stdlib.h>
#define MAXN 21

int main()
{
	int n, prev_dish, score = 0;
	scanf("%d", &n);
	int a[MAXN], b[MAXN], c[MAXN];
	for (int i = 1; i <= n;i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n;i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n - 1;i++)
		scanf("%d", &c[i]);
	score += b[a[1]];
	prev_dish = a[1];
	for (int i = 2; i <= n; i++)
	{
		score += b[a[i]];
		if (prev_dish + 1 == a[i])
			score += c[a[i - 1]];
		prev_dish = a[i];
	}
	printf("%d", score);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int acs(const void *a, const void *b) { return *(int *)a - *(int *)b; } /* 1,2,3,4.. */
int des(const void *a, const void *b) { return *(int *)b - *(int *)a; } /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main(void)
{
	int n, a[21], b[21], c[21];
	scanf("%d", &n);

	int i, j, k;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n - 1; i++)
		scanf("%d", &c[i]);
	c[19] = 0;

	int prev, now, sum = 0;
	prev = -2;
	for (i = 0; i < n; i++)
	{
		now = a[i] - 1;
		if (now == prev + 1)
			sum += c[prev];
		sum += b[now];
		prev = now;
	}
	printf("%d\n", sum);

	return 0;
}

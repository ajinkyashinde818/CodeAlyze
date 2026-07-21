#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;

int	desc(const void *a, const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;
	if (*B > *A) return 1;
	if (*B < *A) return -1;
	return 0;
}

// long deside(long *a, int n)
// {
// 	int i = 0;
// 	int max = a[0];
// 	while (i < n)
// 	{
// 		if (max < a[i])
// 		{
// 			max = a[i];
// 			a[i] = -1;
// 		}
// 		i++;
// 	}
// 	return max;
// }

// long deside2(long *a, int n)
// {
// 	int i = n - 1;
// 	int min = a[0];
// 	while (i > 0)
// 	{
// 		if (min > a[i] && a[i] != -1)
// 		{
// 			min = a[i];
// 			a[i] = -1;
// 		}
// 		i--;
// 	}
// 	return min;
// }

int main()
{
	int N;
	scanf("%d", &N);
	int n = N*3;
	long a[n];
	// long b[N + 1][4];
	int i = 0;
	while (i < n)
	{
		scanf("%ld", &a[i]);
		i++;
	}
	qsort(a, sizeof a / sizeof *a , sizeof *a, desc);
	i = 0;
	int cnt = 0;
	long ans = 0;
	while (i < n)
	{
		if (i % 2)
		{
			ans += a[i];
			cnt++;
		}
		if (cnt == N)
			break;
		i++;
	}
	printf("%ld", ans);
	return (0);
}

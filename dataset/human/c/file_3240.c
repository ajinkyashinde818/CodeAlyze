#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	int k, n, min = INT_MAX;
	int arr[200000] = {
		0,
	};
	scanf("%d %d", &k, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int dist = arr[i + 1] - arr[i];
		min = (k - dist < min) ? k - dist : min;
	}

	min = (arr[n - 1] - arr[0] < min) ? arr[n - 1] - arr[0] : min;

	printf("%d", min);
	return 0;
}

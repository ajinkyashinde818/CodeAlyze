#include <stdio.h>          // printf(), scanf()
#include <string.h>         // memset()
#include <stdbool.h>

#define MAX_N 120409
#define MAX_SQRT_N 347
#define MAX_P 11400

int p;
bool f[MAX_N + 1];
int primes[MAX_P];

int
main(int argc, char **argv)
{
	int n;
	int i, j;

	memset(f, 0xff, sizeof(f));
	p = 0;
	for (i = 2; i <= MAX_N; ++i)
	{
		if (f[i])
		{
			primes[p++] = i;
			if (i <= MAX_SQRT_N)
			{
				for (j = i + i; j <= MAX_N; j += i)
					f[j] = false;
			}
		}
	}

	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		int sum = 0;
		for (i = 0; i < n; ++i)
			sum += primes[i];

		printf("%d\n", sum);
	}

	return 0;
}

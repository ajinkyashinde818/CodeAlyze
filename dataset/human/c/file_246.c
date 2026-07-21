#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, void **argv)
{
	int N;
	long long A[100000];
	unsigned long long sum = 0;
	int count = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		if( A[i] < 0 ) count++;
	}

	if( count % 2 == 0 )
	{
		for (int i = 0; i < N; i++)
		{
			unsigned long long abs;
			abs = A[i] >= 0 ? A[i] : -A[i];
			sum += abs;
		}
	}
	else
	{
		unsigned long long min = 1 * 1000 * 1000 * 1000;

		for (int i = 0; i < N; i++)
		{
			unsigned long long abs;
			abs = A[i] >= 0 ? A[i] : A[i] * -1;
			sum += abs;
			min = min > abs ? abs : min;
		}

		sum -= min * 2;
	}

	printf("%lld\n", sum);

	return 0;
}

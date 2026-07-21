#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))

#define INF 1000000000

void swap(long long int* a, long long int* b)
{
	long long int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	long long int A, B;

	scanf("%lld%lld", &A, &B);

	if (A > B)
		swap(&A, &B);

	for (long long int i = A; i <= A*B; i += A)
	{
		if (i%B == 0)
		{
			printf("%lld\n", i);
			return 0;
		}
	}
}

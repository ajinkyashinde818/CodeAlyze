#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))

#define INF 1000000000


int main()
{
	long long int N;

	scanf("%lld", &N);

	long long int M = N;

	long long int num=5;
	long long int tmp = 0;

	if (N % 2 == 0)
	{
		while (N >= num)
		{
			tmp += (N / num) / 2;
			num *= 5;
		}
		printf("%lld", tmp);

	}
	else
		printf("0\n");
}

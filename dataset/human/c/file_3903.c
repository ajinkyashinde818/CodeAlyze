#include<stdio.h>
#include<math.h>

int euclid(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return euclid(b, a%b);
}

int main()
{
	int A, B, K;

	scanf("%d %d %d", &A, &B, &K);

	int gcd = euclid(A, B);
	int counter = 0;
	int i;

	for ( i = 1; i <= gcd; i++)
	{
		if (gcd%i == 0)
		{
			counter++;
			if (counter == K)
			{
				printf("%d", gcd / i);
				return 0;
			}
		}
	}
	return 0;
}

#include <stdio.h>

int	main()
{
	int	N;
	int	D, X, A;
	int	i, n, sum, a;

	scanf("%d\n%d %d\n", &N, &D, &X);
	i = 0;
	sum = 0;
	while (i < N)
	{
		scanf("%d\n", &A);
		n = 0;
		a = A;
		while (a <= D || n == 0)
		{
			n++;
			a = n * A + 1;
			sum++;
		}
		i++;
	}
	sum += X;
	printf("%d\n", sum);
	return (0);
}

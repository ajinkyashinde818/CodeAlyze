#include <stdio.h>

void	swap(int *A, int *B)
{
	int		save;

	save = *A;
	*A = *B;
	*B = save;
}

int		main()
{
	int		A, B;
	int		save, nb, rest;
	double	ans;

	scanf("%d %d\n", &A, &B);
	if (A > B)
		swap(&A, &B);
	nb = B;
	rest = A;
	while (nb % rest)
	{
		save = rest;
		rest = nb % rest;
		nb = save;
	}
	ans = (double)A * (double)B / (double)rest;
	printf("%.0f\n", ans);
	return (0);
}

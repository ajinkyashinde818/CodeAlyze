#include <stdio.h>

int	main(void)
{
	int	D[210];
	int	N, i, j, flag = 0;

	scanf("%d", &N);
	for (i = 0; i < 2 * N; i++)
		scanf("%d", &D[i]);
	for (i = 0; i < 2 * (N - 2); i += 2)
	{
		if (D[i] == D[i + 1] && D[i + 2] == D[i + 3] && D[i + 4] == D[i + 5])
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}

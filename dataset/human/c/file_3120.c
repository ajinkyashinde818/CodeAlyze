#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int		A, K, N;
	int		*meter;
	int		sum, dis, max, num, i;

	i = 0;
	sum = 0;
	max = 0;
	dis = 0;
	scanf("%d %d\n", &K, &N);
	meter = (int *)malloc(sizeof(int) * (N + 3));
	while (i <= N)
	{
		if (i < N)
			scanf("%d ", &meter[i]);
		else
			meter[i] = K;
		if (i)
			dis = meter[i] - meter[i - 1];
		if (i == N && meter[0])
			dis += meter[0];
		if (dis >= max)
		{
			max = dis;
			num = i;
		}
		sum += dis;
		i++;
	}
	sum -= max;
	printf("%d\n", sum);
	return (0);
}

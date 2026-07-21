#include <stdio.h>

int	min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

int	main(void)
{
	int			step_num;
	int			broken;
	int			steps[100001] = {};
	long		dp[100001] = {};
	const long	MOD = 1000000007;

	scanf("%d %d", &step_num, &broken);
	for (int i = 0; i < broken; i++)
	{
		int broken_i;
		scanf("%d", &broken_i);
		steps[broken_i] = 1;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= step_num; i++)
	{
		if (!steps[i - 1])
		{
			dp[i] += dp[i - 1];
		}
		if (!steps[i - 2])
		{
			dp[i] += dp[i - 2];
		}
		dp[i] %= MOD;
	}
	printf("%ld\n", dp[step_num]);
	return (0);
}

#include <stdio.h>

int	D, G;
int	p[11] = {0};
int	c[11] = {0};

void	culc_min(int state[11], int score, int *num, int temp)
{
	int	i, j;
	int	now_score;
	int	now_num;

	if (score >= G)
	{
		if (temp < *num)
		{
			*num = temp;
		}
		return ;
	}
	for (i = 0; i < D; i++)
	{
		if (state[i] == 1)
			continue ;
		state[i]++;
		now_score = score;
		now_num = temp;
		for (j = 0; j < p[i] - 1; j++)
		{
			now_score += (i + 1) * 100;
			now_num++;
			if (now_score >= G)
			{
				culc_min(state, now_score, num, now_num);
			}
		}
		now_score += (i + 1) * 100 + c[i];
		now_num++;
		culc_min(state, now_score, num, now_num);
		state[i]--;
	}
}

int		main(void)
{
	int	state[11] = {0};
	int	score = 0;
	int	num = 10000;
	int	i;

	//入力
	scanf("%d%d", &D, &G);
	for (i = 0; i < D; i++)
	{
		scanf("%d%d", &p[i], &c[i]);
	}
	//処理
	culc_min(state, score, &num, 0);
	printf("%d\n", num);
	return (0);
}

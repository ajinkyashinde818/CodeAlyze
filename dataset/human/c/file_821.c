#include<stdio.h>
int main()
{
	int d, g;
	scanf("%d %d", &d, &g);
	int i, j;
	int p[11], c[11];
	for (i = 0; i < d; i++)
		scanf("%d %d", &p[i], &c[i]);
	int ans = 1000000009;
	int max = 1;
	for (i = 0; i < d; i++)
		max *= 2;
	int q, count, s;
	int v[11], pp[11];
	for (i = 0; i < max; i++)
	{
		q = i;
		s = 0;
		count = 0;
		for (j = 0; j < d; j++)
		{
			v[j] = q % 2;
			q /= 2;
		}
		for (j = 0; j < d; j++)
			pp[j] = 0;
		for (j = 0; j < d; j++)
		{
			if (v[j] == 1)
			{
				s += 100 * (j + 1) * p[j] + c[j];
				count += p[j];
			}
		}
		while (s < g)
		{
			q = 0;
			for (j = d - 1; j >= 0; j--)
			{
				if (v[j] == 0 && pp[j] < p[j])
				{
					s += 100 * (j + 1);
					pp[j]++;
					count++;
					q++;
					break;
				}
			}
			if (q == 0)
				break;
		}
		if (ans > count)
			ans = count;
	}
	printf("%d\n", ans);
	return 0;
}

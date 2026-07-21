#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<complex>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<queue>

int main()
{
	int d, g, p[10], c[10], min{}, sum{}, sum_table[10]{};
	scanf("%d%d", &d, &g);
	g /= 100;
	for (int i = 0; i < d; i++)
	{
		scanf("%d%d", p + i, c + i);
		c[i] /= 100;
	}
	for (int i = 0; i < d; i++)
	{
		sum_table[i] = p[i] * (i + 1) + c[i];
	}
	for (int i = d - 1; i >= 0; i--)
	{
		sum += sum_table[i];
		min += p[i];
		if (sum >= g) break;
	}
	for (int i = 0; i < (1 << d); i++)
	{
		int count{};
		sum = 0;
		bool all_added[10]{};
		for (int j = 0; j < d; j++)
		{
			all_added[j] = i & (1 << j);
			if (all_added[j])
			{
				sum += sum_table[j];
				count += p[j];
			}
		}
		if (count >= min) continue;
		if (sum < g)
		{
			for (int j = d - 1; j >= 0; j--)
			{
				if (all_added[j]) continue;
				if (sum + (p[j] - 1) * (j + 1) < g)
				{
					count = min + 1;
				}
				else
				{
					count += (g - sum + j) / (j + 1);
				}
				break;
			}
		}
		if (count > min) continue;
		min = count;
	}
	printf("%d\n", min);

	return 0;
}

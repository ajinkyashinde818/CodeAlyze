#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_table[1000];
int prime_top;
int table[1121][15];

int init()
{
	prime_table[0] = 2;
	prime_table[1] = 3;
	prime_top = 2;

	for (int i = 4; i < 1121; i++)
	{
		for (int j = 0; j < prime_top; j++)
		{
			if (i % prime_table[j] == 0)
				goto POINT_1;
		}
		prime_table[prime_top] = i;
		prime_top++;
	POINT_1:
		continue;
	}

	table[0][0] = 1;
	for (int i = 0; i < prime_top; i++)
	{
		for (int j = 13; j >= 0; j--)
		{
			for (int k = 0; k <= 1120 - prime_table[i]; k++)
			{
				table[k + prime_table[i]][j + 1] += table[k][j];
			}
		}
	}
}

int main()
{
	init();
	for (int in1, in2, out1; (scanf("%d %d", &in1, &in2)) && in1 != 0; printf("%d\n", out1))
	{
		out1 = table[in1][in2];
	}
}

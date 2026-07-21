#include <stdio.h>

int main(int argc, char *argv[])
{
    int		n, i;
    int		min_val, val;
    int		max_profit, profit;

    max_profit = 0x80000000;
    min_val = 0x7fffffff;

    scanf("%d\n", &n);
    for(i = 0; i < n; i++)
    {
	scanf("%d\n", &val);
	profit = val - min_val;

	if (profit > max_profit)
	{
	    max_profit = profit;
	}

	if (val < min_val)
	{
	    min_val = val;
	}
    }

    printf("%d\n", max_profit);

    return 0;
}

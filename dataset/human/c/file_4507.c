#include <stdio.h>

int	main(void)
{
	int	n, d1, d2;
	int	flg = 0;
	int	max = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &d1, &d2);
		if (d1 == d2)
			flg++;
		else
		{
			if (max < flg)
				max = flg;
			flg = 0;
		}
	}
	if (max < flg)
		max = flg;
	if (3 <= max)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

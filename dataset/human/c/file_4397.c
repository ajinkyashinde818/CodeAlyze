#include <stdio.h>

int	main(void)
{
	int	n;
	int	count = 0, flag = 0;
	int	d1[100];
	int	d2[100];

	scanf("%i", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%i", &d1[i]);
		scanf("%i", &d2[i]);
		if (d1[i] == d2[i])
		{
			count++;
			if (count == 3)
				flag = 1;
		}
		else
			count = 0;
	}

	if (flag == 1)
		printf("Yes\n");
	else
		printf("No\n");

	return (0);
}

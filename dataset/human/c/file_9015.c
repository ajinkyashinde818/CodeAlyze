#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

int
main(int argc, char **argv)
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		int count = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;

			count++;
		}

		printf("%d\n", count);
	}

	return 0;
}

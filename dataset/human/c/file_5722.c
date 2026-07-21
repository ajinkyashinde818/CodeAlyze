#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;

	if (scanf("%d\n", &n) == EOF)
		return -1;

	if (n < 2)
		return -1;

	int count = n;

	if (scanf("%d\n", &n) == EOF)
		return -1;

	int maxdiff = -2147483648;
	int minvalue = n;

	for (int i = 0; i < count - 1; i++)
	{
		if (scanf("%d", &n) == EOF)
			return -1;

		maxdiff = fmax(maxdiff, n - minvalue);
		minvalue = fmin(minvalue, n);
	}

	printf("%d\n", maxdiff);

	return 0;
}

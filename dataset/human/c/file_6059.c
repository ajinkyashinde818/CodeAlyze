#include <stdio.h>

int main()
{
	int a, b, c, n, i, min, pre, cur;

	scanf("%d", &n);

	scanf("%d", &min);
	scanf("%d", &pre);

	a = pre - min;
	if (min > pre) min = pre;

	for (i = 2; i < n; i++)
	{
		scanf("%d", &cur);
		b = cur - pre;
		c = cur - min;

		if (b > c) { if (a < b) a = b; }
		else if (a < c) a = c;

		if (min > cur) min = cur;

		pre = cur;
	}

	printf("%d\n", a);
	return 0;
}

// AOJ 2753: Lie with Mean Value
// 2017.10.9 bal4u@uu

#include <stdio.h>

int main()
{
	int n, m, i, k;

	scanf("%d%d", &n, &m);
	for (k = n/2+1, i = 0; i < k; i++) {
		if (i > 0) putchar(' ');
		putchar('0');
	}
	for (; i < n; i++) printf(" %d", m);
	putchar('\n');
	return 0;
}

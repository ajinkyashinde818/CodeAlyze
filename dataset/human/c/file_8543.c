// AOJ 2340: Carpenters' Language
// 2017.11.13 bal4u@uu

#include <stdio.h>

int main()
{
	int q, p, n;
	long long l, r;
	char b[5];

	l = r = 0;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%s%d", &p, b, &n);
		if (*b == '(') l += n;
		else           r += n;
		puts(l == r ? "Yes" : "No");
	}
	return 0;
}

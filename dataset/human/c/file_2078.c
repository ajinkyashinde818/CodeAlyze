// AOJ 2177: Champernowne Constant
// 2017.11.5 bal4u@uu

#include <stdio.h>
#include <string.h>

long long len[10];
int ten[10] = {1};

char *putint(char *p, int n)
{
	char *q;
	static char tmp[13] = {0};

	q = tmp; while (n >= 10) {
		*++q = '0' + (n % 10);
		n /= 10;
	}
	*p++ = n + '0';
	while (*q) *p++ = *q--;
	return p;
}

int main()
{
	int n, k, i, j, num;
	long long nine;
	char buf[200], *p, *top;

	for (nine = 9, i = 1; i < 10; i++, nine *= 10) len[i] = i*nine, ten[i] = ten[i-1]*10;
	for (i = 1; i < 10; i++) len[i] += len[i-1];

	while (scanf("%d%d", &n, &k) && n > 0) {
		for (i = 1; len[i] < n; i++);
		j = n - (int)len[i-1] - 1;
		num = ten[i-1] + j / i;
		top = buf + j % i;
		p = putint(buf, num);
		while (p-top < k) p = putint(p, ++num);
		*(top+k) = 0;
		puts(top);
	}
	return 0;
}

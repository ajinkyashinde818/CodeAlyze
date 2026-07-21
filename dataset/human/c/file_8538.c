#include <stdio.h>

int big = 0;
unsigned int small = 0;

const unsigned int BASE = 2147483648;


void sub(unsigned int a)
{
	if (big < 0) {
		if (small + a > BASE) {
			big--;
			small = small + a - BASE;
		} else {
			small += a;
		}
	} else {
		if (small >= a) {
			small -= a;
		} else {
			big--;
			small = small + BASE - a;
		}
	}
}


void add(unsigned int a)
{
	if (big >= 0) {
		if (a + small >= BASE) {
			big++;
			small = (a + small) - BASE;
		} else {
			small += a;
		}
	} else {
		if (a + small >= BASE) {
			small = a + small - BASE;
			big++;
		} else {
			small += a;
		}
	}
}
int isZero()
{
	return small == 0 && big == 0;
}

int main()
{
	int i;
	int q;
	int p, n;
	char c;

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d %c %d", &p, &c, &n);
		if (c == '(') {
			add(n);
		} else {
			sub(n);
		}

		if (isZero()) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}

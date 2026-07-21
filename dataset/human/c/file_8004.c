#include <stdio.h>
#include <stdlib.h>

#define MOD_BY 1000000007

int add(int a, int b) {
	return a + b - MOD_BY * (a + b >= MOD_BY);
}

int mul(int a, int b) {
	int r = 0;
	while (b > 0) {
		if (b & 1) r = add(r, a);
		a = add(a, a);
		b >>= 1;
	}
	return r;
}

int pou(int a, int b) {
	int r = 1;
	while (b > 0) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int inv(int a) {
	return pou(a, MOD_BY - 2);
}

int dexibu(int a, int b) {
	return mul(a, inv(b));
}

int kaizyou_cache_max = 0;
int* kaizyou_cache = NULL;

int kaizyou(int a) {
	if (a > kaizyou_cache_max) {
		int i;
		kaizyou_cache = realloc(kaizyou_cache, sizeof(int) * (a + 1));
		if (kaizyou_cache == NULL) exit(2);
		for (i = kaizyou_cache_max + 1; i <= a; i++) {
			kaizyou_cache[i] = mul(kaizyou_cache[i - 1], i);
		}
		kaizyou_cache_max = a;
	}
	return kaizyou_cache[a];
}

int main(void) {
	int X, Y;
	int a, b;
	kaizyou_cache = malloc(sizeof(int));
	if (kaizyou_cache == NULL) return 2;
	kaizyou_cache[0] = 1;
	if (scanf("%d%d", &X, &Y) != 2) return 1;
	a = 2 * X - Y;
	b = 2 * Y - X;
	if (a < 0 || b < 0 || a % 3 != 0 || b % 3 != 0) {
		puts("0");
		return 0;
	}
	a /= 3;
	b /= 3;
	printf("%d\n", dexibu(kaizyou(a + b), mul(kaizyou(a), kaizyou(b))));
	return 0;
}

/*

    a + 2 * b = X
2 * a +     b = Y

b = (2 * X - Y) / 3
a = (2 * Y - X) / 3

*/

/*

999999 333333

*/

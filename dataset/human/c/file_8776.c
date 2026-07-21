// AOJ 3129 Contest T-shirts
// 2020.1.16 bal4u

#include <stdio.h>

#define gc() getchar_unlocked()

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

#define MIN(a,b) ((a)<=(b)?(a):(b))

int main()
{
	int M, N, a0;
	
	M = in(), N = in();
	if (M == 2) {
		a0 = 1;
		int s1 = 0, s2 = 0;
		while (N--) {
			int a = in();
			if (a == a0) ++s1; else ++s2;
			a0 = 3 - a0;
		}
		printf("%d\n", MIN(s1, s2));
	} else {
		a0 = 0;
		int s = 0, f = 0;
		while (N--) {
			int a = in();
			if (!f) {
				if (a == a0) ++s, f = 1;
			} else f = 0;
			a0 = a;
		}
		printf("%d\n", s);
	}
	return 0;
}

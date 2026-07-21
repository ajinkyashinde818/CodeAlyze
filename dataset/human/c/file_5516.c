#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define N 104730
int main() {
	unsigned long long i, j, cnt = 0, p[N] = { 0 }, sum = 0, n;
	for (i = 2; i <= (unsigned long long)sqrt((double)N); ++i) if (!p[i]) for (j = 2; j*i < N; ++j) p[i*j] = 1;
		while (scanf("%lld", &n), n != 0) {
		for (i = 2; i < N&&cnt < n; ++i) if (!p[i]) ++cnt, sum += i;
		printf("%lld\n", sum),cnt = sum = 0;
	}
	return 0;
}

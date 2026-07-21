// ABC 150-D
// 2020.1.11 bal4u

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in() {   // 非負整数の入力
	int n = 0; int c;
	c = gc();
//	do c = gc();
//	while (isspace(c));
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

int a[100005];
int N, M;

int cmp(const void *u, const void *v) { return *(int *)v - *(int *)u; }

// 配列 a 、個数 n　、　リターン値はユニーク化した配列の長さ（個数）
int uniq(int *a, int n)
{
	int i, j;
	
//	if (n == 0) return 0;
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && a[j] == a[i]) j++;
		if (j < n) if (++i != j) a[i] = a[j];
	}
	return i+1;
}

int check(int X) {
	int i;
	for (i = 1; i < N; ++i) {
		if ((X-(a[i]>>1)) % a[i]) return 0;
	}
	return 1;
}

int main()
{
	int i, ans;
	
	N = in(), M = in();
	for (i = 0; i < N; ++i) a[i] = in();
	qsort(a, N, sizeof(a[0]), cmp);
	N = uniq(a, N);
//	printf("N=%d, a[0]=%d, a[1]=%d\n", N, a[0], a[1]);
	
	ans = 0;
	for (i = 0; ; i += a[0]) {
		int X = i + (a[0]>>1);
		if (X > M) break;
		if (check(X)) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}

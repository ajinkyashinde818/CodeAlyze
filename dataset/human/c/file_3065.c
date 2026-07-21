// ABC 160-C
// 2020.3.28 bal4u

#include <stdio.h>

#define gc() getchar_unlocked()
int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

int A[200005]; int N;
int main()
{
	int i, K, t, ans;

	K = in(), N = in();
	ans = 0;
	A[0] = in();
	for (i = 1; i < N; ++i) {
		A[i] = in();
		if (A[i]-A[i-1] > ans) ans = A[i]-A[i-1];
	}
	if (K-A[N-1]+A[0] > ans) ans = K-A[N-1]+A[0];
	printf("%d\n", K-ans);
	return 0;
}

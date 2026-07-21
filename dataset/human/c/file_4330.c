// AtCoder ABC129: C - Typical Stairs
// 2019.9.4 bal4u

#include <stdio.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

#define MOD 1000000007
int N;
char f[100005];
int dp[100005];

int main()
{
	int i, M;
	
	N = in(), M = in();
	memset(f, 1, N+1);
	while (M--) f[in()] = 0;
		
	dp[0] = 1; if (f[1]) dp[1] = 1;
	for (i = 2; i <= N; i++) if (f[i]) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	printf("%d\n", dp[N]);
	return 0;
}

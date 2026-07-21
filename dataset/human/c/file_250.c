// AtCoder ABC125: D - Flipping Signs
// 2019.9.9 bal4u

#include <stdio.h>

typedef long long ll;

#if 1
int getchar_unlocked(void);
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in() {  // 整数の入力
	int n = 0, c = gc();
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

#define INF 0x7fffffff

int main()
{
	int i, minus, mi, A, N; ll ans;
	
	N = in(); 
	minus = 0, ans = 0, mi = INF;
	for (i = 0; i < N; i++) {
		A = in();
		if (A < 0) minus++, A = -A;
		if (A < mi) mi = A;
		ans += A;
	}
	if (minus & 1) ans -= 2*mi;
	printf("%lld\n", ans);
	return 0;
}

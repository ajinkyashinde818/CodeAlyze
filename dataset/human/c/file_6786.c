#include <stdio.h>
#include <math.h>
typedef long long LL;
typedef long double Lf;
#define in (void)scanf
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define MOD 1000000007
int n, k, a[200009];
LL check(int x) {
	LL ret = 0;
	rep(i, n)ret += (LL)ceill((Lf)a[i] / (Lf)x) - 1;
	return ret;
}

int main(void) {
	in("%d%d", &n, &k);
	rep(i, n)in("%d", &a[i]);
	int p = 0, q = MOD / 2, r = MOD, ans = n;
	while (r - p > 1) {
		if (check(q) <= (LL)k) r = q;
		else p = q;
		q = (p + r) / 2;
	}
	if (check(r) <= k)ans = r;
	if (check(q) <= k)ans = q;
	if (check(p) <= k)ans = p;
	printf("%d\n", ans ? ans : 1);
	return 0;
}

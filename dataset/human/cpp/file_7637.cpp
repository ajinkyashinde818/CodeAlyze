#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MaxN = 2e5;

LL n, m, a[MaxN + 5], sum, k, l[MaxN + 5], r[MaxN + 5];

int main() {
	scanf("%lld", &n);
	for(LL i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	l[1] = a[1];
	for(LL i = 2; i <= n; i++)
		l[i] += l[i - 1] + a[i];
	r[n] = a[n];
	for(LL i = n - 1; i > 0; i--)
		r[i] += r[i + 1] + a[i];
	LL m = (1ll << 60);
	for(LL i = 1; i < n; i++)
		m = min(abs(l[i] - r[i + 1]), m);
	printf("%lld\n", m);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 2e5 + 7;
const ll Inf = 2e14 + 7;
int n;
int a[maxx];
ll sumk[maxx];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sumk[i] = sumk[i - 1] + a[i];
	}
	ll ans = Inf;
	for(int i = 1; i < n; i++) {
		ll tmp = sumk[n] - sumk[i];
		ll dd = abs(sumk[i] - tmp);
		ans = min(ans, dd);
	}
	printf("%lld\n", ans);
}

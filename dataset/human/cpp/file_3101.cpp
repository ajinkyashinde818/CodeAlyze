#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
int n;
ll a[maxx];
ll dd[maxx];
ll ans;

int main() {
	scanf("%d", &n);
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		dd[i] = abs(a[i]);
		ans += dd[i];
		if(a[i] < 0) tot++;
	}
	sort(dd + 1, dd + n + 1);
	if(tot & 1) ans -= dd[1] * 2;
	printf("%lld\n", ans);
	return 0;
}

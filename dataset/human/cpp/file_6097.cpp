#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;

ll n, c, a[N], b[N], sum[N], ans;

void solve () {
	for(ll i=1;i<=n;i++) {
		sum[i] = sum[i-1] + b[i];
	}
	ll cur = sum[n] - 2 * (c - a[1]), mx = 0;
	for(ll i=1;i<=n;i++) {
		cur += 2 * (a[i+1] - a[i]) - b[i];
		mx = max(mx, sum[i] - a[i]);
		ans = max(ans, cur+mx);
	}
}

int main()
{
	scanf("%lld%lld",&n,&c);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
	}
	a[n+1] = c;
	solve();
	reverse(a+1, a+1+n);
	reverse(b+1, b+1+n);
	for(ll i=1;i<=n;i++) a[i] = c - a[i];
	solve();
	printf("%lld\n",ans);
}

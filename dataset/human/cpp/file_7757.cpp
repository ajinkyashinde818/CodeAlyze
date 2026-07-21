#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
typedef long long ll;

int c[maxn];
ll p[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", c+i);
		p[i] = p[i-1] + c[i];
	}
	
	ll res = (ll)1e18;
	for(int i = 1; i < n; ++i) {
		ll l = p[i];
		ll r = p[n] - p[i];
		ll nw = abs(l - r);
		res = min(res, nw);
	}
	printf("%lld\n", res);
}

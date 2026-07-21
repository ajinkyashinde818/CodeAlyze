#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll c;
ll X[Maxn], V[Maxn];
ll dp[Maxn];

ll Get(int koef1, int koef2)
{
	ll val = 0;
	for (int i = n - 1; i >= 0; i--) {
		val += V[i];
		dp[i] = val - koef1 * (c - X[i]);
	}
	ll cur = 0;
	ll mx = 0;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i] + mx);
		cur += V[i];
		mx = max(mx, cur - koef2 * X[i]);
	}
	res = max(res, mx);
	return res;
}

int main()
{
	scanf("%d %lld", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &X[i], &V[i]);
	printf("%lld\n", max(Get(2, 1), Get(1, 2)));
	return 0;
}

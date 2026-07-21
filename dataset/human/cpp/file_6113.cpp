#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll L, ans;
int a[maxn];
ll x[maxn], presum[maxn], pre[maxn], sufsum[maxn], suf[maxn];
int main()
{
	scanf("%d%lld", &n, &L);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%d", &x[i], &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		presum[i] = presum[i - 1] + a[i];
		pre[i] = max(pre[i - 1], presum[i] - 2 * x[i]);
	}
	for(int i = n; i; --i)
	{
		sufsum[i] = sufsum[i + 1] + a[i];
		suf[i] = max(suf[i + 1], sufsum[i] - 2 * (L - x[i]));
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, presum[i] - x[i] + suf[i + 1]);
	for(int i = n; i; --i)
		ans = max(ans, sufsum[i] - (L - x[i]) + pre[i - 1]);
	printf("%lld\n", ans);
	return 0;
}

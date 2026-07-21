#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

const lli maxn = lli(1e5)+5;

lli x[maxn], v[maxn], suff[maxn], pref[maxn];

int main(void)
{
	lli n, c;
	scanf("%lld%lld", &n, &c);
	for(lli i = 1;i <= n;i++) scanf("%lld%lld", &x[i], &v[i]);

	lli vsum = 0, res = 0;
	for(lli i = 1;i <= n;i++)
	{
		vsum += v[i];
		pref[i] = vsum-x[i];
		pref[i] = max(pref[i], pref[i-1]);
		res = max(res, pref[i]);
	}

	vsum = 0;
	for(lli i = n;i > 0;i--)
	{
		vsum += v[i];
		suff[i] = vsum-(c-x[i]);
		suff[i] = max(suff[i], suff[i+1]);
		res = max(res, suff[i]);
		res = max(res, suff[i]-(c-x[i])+pref[i-1]);
	}

	for(lli i = 1;i <= n;i++) res = max(res, pref[i]-x[i]+suff[i+1]);

	printf("%lld\n", res);
}

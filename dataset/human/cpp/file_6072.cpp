#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<long,long> ll;

ll arr[100003];
long pref1[100003], pref2[100003], pref3[100003], pref4[100003];
long mx1[100003], mx2[100003], mx3[100003], mx4[100003];

const long SMALL = -1e18;

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);
	int n; long c; 
	scanf("%d %lld", &n, &c);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &arr[i].fi, &arr[i].se);
	}
	sort(arr, arr+n);
	for(int i = 0; i <= n+1; i++)
		mx1[i] = mx2[i] = mx3[i] = mx4[i] = SMALL;

	for(int i = 1; i <= n; i++)
	{
		pref1[i] = pref1[i-1] + arr[i].se;
		pref3[i] = pref3[i-1] + arr[i].se;
	}
	for(int i = 1; i <= n; i++)
	{
		pref1[i] -= arr[i].fi;
		pref3[i] -= 2*arr[i].fi;
		mx1[i] = max(mx1[i-1], pref1[i]);
		mx3[i] = max(mx3[i-1], pref3[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		pref2[i] = pref2[i+1] + arr[i].se;
		pref4[i] = pref4[i+1] + arr[i].se;
	}
	for(int i = n; i >= 1; i--)
	{
		pref2[i] -= c-arr[i].fi;
		pref4[i] -= 2*(c-arr[i].fi);
		mx2[i] = max(mx2[i+1], pref2[i]);
		mx4[i] = max(mx4[i+1], pref4[i]);
	}
	// for(int i = 1; i <= n; i++) printf("%lld ", pref1[i]); printf("\n");
	// for(int i = 1; i <= n; i++) printf("%lld ", pref2[i]); printf("\n");
	// for(int i = 1; i <= n; i++) printf("%lld ", pref3[i]); printf("\n");
	// for(int i = 1; i <= n; i++) printf("%lld ", pref4[i]); printf("\n");

	long res = 0;
	res = max(res, mx1[n]);
	res = max(res, mx2[1]);
	for(int i = 1; i < n; i++)
	{
		res = max(res, mx1[i]+mx4[i+1]);
		res = max(res, mx2[i+1]+mx3[i]);
	}
	printf("%lld\n", res);
}

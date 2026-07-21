#include "omp.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <random>
#include <bitset>
#include <unordered_set>
#include <cassert>
#include <list>
#include <functional>


using namespace std;

typedef long long ll;
typedef long double ld;


const int sze = 1 << 15, INF = 1e9 + 10;
const ll MOD = 1e15;


signed main()
{
	ll n, c;
	cin >> n >> c;

	vector<ll> positions(n), prices(n);
	for (int i = 0; i < n; ++i)
	{
		ll a, b;
		cin >> a >> b;
		positions[i] = a;
		prices[i] = b;
	}

	vector<ll> dp1(n), dp2(n);
	vector<ll> pref(n), suf(n);

	for (int i = 0; i < n; ++i)
	{
		dp1[i] = i ? (dp1[i - 1] - positions[i] + positions[i - 1] + prices[i]) : prices[i] - positions[i];
		dp1[i] %= MOD;
	}

	for (int i = n - 1; i >= 0; --i)
	{
		dp2[i] = (i + 1 == n) ? prices[i] - c + positions[i] : (dp2[i + 1] - positions[i + 1] + positions[i] + prices[i]);
		dp2[i] %= MOD;
	}

	ll ans = 0;

	suf[n - 1] = dp2[n - 1];
	for (int j = n - 2; j >= 0; j--)
		suf[j] = max(suf[j + 1], dp2[j]);

	pref[0] = dp1[0];
	for (int i = 1; i < n; ++i)
		pref[i] = max(pref[i - 1], dp1[i]);

	for (int i = 0; i < n; ++i)
		ans = max(ans, max(dp1[i], dp2[i]));
	
	for (int i = 0; i + 1 < n; ++i)
	{
		ll mx = suf[i + 1];
		ans = max(ans, dp1[i] + mx - positions[i]);
	}
	
	for (int j = n - 1; j; j--)
	{
		ll mx = pref[j - 1];
		ans = max(ans, dp2[j] + mx - (c - positions[j]));
	}

	cout << ans;
	return 0;
}

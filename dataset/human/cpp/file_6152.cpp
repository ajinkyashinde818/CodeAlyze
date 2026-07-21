#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

int main()
{
	ll n, c;
	cin >> n >> c;
	
	vector<ll> x(n), y(n), v(n);
	REP (i, n)
	{
		cin >> x[i] >> v[i];
		y[i] = c - x[i];
	}
	
	ll res = 0;
	{
		vector<ll> mx(n);
		ll tmx = 0, cc = 0;
		REP (i, n)
		{
			cc += v[n - i - 1];
			mx[n - i - 1] = tmx;
			tmx = max(tmx, cc - y[n - i - 1] * 2);
		}
		cc = 0;
		REP (i, n)
		{
			cc += v[i];
			res = max(res, cc - x[i] + mx[i]);
		}
	}
	{
		vector<ll> mx(n);
		ll tmx = 0, cc = 0;
		REP (i, n)
		{
			cc += v[i];
			mx[i] = tmx;
			tmx = max(tmx, cc - x[i] * 2);
		}
		cc = 0;
		REP (i, n)
		{
			cc += v[n - i - 1];
			res = max(res, cc - y[n - i - 1] + mx[n - i - 1]);
		}
	}
	
	cout << res << endl;

	return 0;
}

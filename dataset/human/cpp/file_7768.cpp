#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n; cin >> n;
	vector<ll> sum(n + 1, 0);
	rep(i, n)
	{
		ll a; cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	ll res = 1e18;
	for (int i = 1; i < n; ++i)
	{
		ll snu = sum[i];
		ll ara = sum[n] - sum[i];
		res = min(res, abs(snu - ara));
	}
	cout << res << endl;
}

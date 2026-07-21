#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<stdio.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)

const ll INF = 1LL << 60;

typedef pair<ll, double> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
	return firstElof.second < secondElof.second;
}

bool IsPrime(ll num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

signed main() {
	ll ans = 0;

	ll n, r;

	cin >> n >> r;

	if (n < 10) {
		ans = r + (100 * (10 - n));
	}
	else {
		ans = r;
	}
	cout << ans;
}

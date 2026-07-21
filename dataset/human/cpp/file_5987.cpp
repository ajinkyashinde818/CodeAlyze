#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define fr first
#define sc second




int main() {
	ll n, c, x[100010], y[100010], ans = 0, ruir[100010] = { 0 }, ruil[100010] = { 0 }, sumr[100010] = { 0 }, suml[100010] = { 0 }, ml[100010] = { 0 }, mr[100010] = { 0 };
	cin >> n >> c;
	x[n + 1] = c;
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1;i <= n;i++) {
		ruir[i] = ruir[i - 1] + y[i];
	}

	for (int i = n;i > 0;i--) {
		ruil[i] = ruil[i + 1] + y[i];
	}

	for (int i = n;i > 0;i--) {
		ml[i] = max(ml[i + 1], ruil[i] - (c - x[i]));
	}

	for (int i = 1;i <= n;i++) {
		ll res = ruir[i] + ml[i + 1];
		ans = max(ans, res - x[i]*2);
	}


	for (int i = 1;i <= n;i++) {
		mr[i] = max(mr[i - 1], ruir[i] - x[i]);
	}

	for (int i = n;i > 0;i--) {
		ll res = ruil[i] - (c - x[i]) * 2;
		ans = max(ans, res + mr[i - 1]);
	}


	ll sum = 0, mm = 0;
	for (int i = 1;i <= n;i++) {
		sum = sum + (y[i] - (x[i] - x[i - 1]));
		mm = max(mm, sum);
	}
	ans = max(ans, mm);
	sum = 0, mm = 0;

	for (int i = n;i >= 1;i--) {
		sum = sum + (y[i] - (x[i + 1] - x[i]));
		mm = max(mm, sum);
	}

	ans = max(mm, ans);
	cout << ans << endl;
}

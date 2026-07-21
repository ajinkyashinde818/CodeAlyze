#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <functional>

using namespace std;
using ll = long long;
using ld = double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>; //(x, y, dx, dy)
const ll INF = 1e17;
const ld eps = 1e-10;
const ll MOD = 1e9 + 7;

const double pi = acos(-1.0);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	cin >> N;
	vector<ll> a(N);
	ll mini = INF;
	ll sum = 0;
	for (int i = 0;i < N;i++) {
		cin >> a[i];
		mini = min(mini, abs(a[i]));
		sum += abs(a[i]);
	}
	ll ans = sum - mini * 2;
	bool now = false;
	for (int i = 0;i < N;i++) {
		int f = (now + (a[i] < 0)) % 2;
		now = f;
	}
	if (!now)
		ans = sum;
	cout << ans << endl;
	return 0;
}

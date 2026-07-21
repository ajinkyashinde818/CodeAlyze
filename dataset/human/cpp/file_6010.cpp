#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
*/

const int N = 100100;
ll a[N];
ll b[N];
ll c[N];
ll d[N];
ll ans = 0;
int n;
ll C;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &C);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += b[i];
		ans = max(ans, sum - a[i]);
		c[i] = sum - 2 * a[i];
	}
	sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += b[i];
		ans = max(ans, sum - (C - a[i]));
		d[i] = sum - 2 * (C - a[i]);
	}
	for (int i = 1; i < n; i++)
		c[i] = max(c[i], c[i - 1]);
	for (int i = n - 2; i >= 0; i--)
		d[i] = max(d[i], d[i + 1]);

	sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += b[i];
		ans = max(ans, sum - a[i] + d[i + 1]);
	}
	sum = 0;
	for (int i = n - 1; i > 0; i--) {
		sum += b[i];
		ans = max(ans, sum - (C - a[i]) + c[i - 1]);
	}
	printf("%lld\n", ans);

	return 0;
}

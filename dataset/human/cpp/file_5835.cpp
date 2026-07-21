#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int n;
	ll c;
	cin >> n >> c;
	vector <ll> x(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> v[i];
		v[i] += v[i - 1];
	}
	ll ans = 0;
	vector <ll> pre(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = v[i] - x[i];
		ans = max(ans, pre[i]);
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = v[n] - v[i - 1] - (c - x[i]);
		ans = max(ans, suf[i]);
	}
	vector <ll> premx(n + 1), sufmx(n + 2);
	for (int i = 1; i <= n; i++) {
		premx[i] = max(pre[i], premx[i - 1]);
	}
	for (int i = n; i >= 1; i--) {
		sufmx[i] = max(suf[i], sufmx[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, pre[i] - x[i] + sufmx[i + 1]);
		ans = max(ans, suf[n - i + 1] - (c - x[n - i + 1]) + premx[n - i]); 
	}
	cout << ans;
}

#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

/*bool isprime(int p) {
	if (p == 1) return false;
	for (int i = 2; i < p; i++) {
		if (p % i == 0) return false;
	}
	return true;
}*/
/*ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/
/*ll keta(ll n) {
	ll res = 0;
	while (n >= 1) {
		res += n % 10; n /= 10;
	}
	return res;
}*/
/*ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}
ll nCk(ll n, ll k) {
	ll a = 1, b = 1;
	for (int h = n - k + 1; h <= n; h++) { a *= h; a %= mod; }
	for (int h = 1; h <= k; h++) { b *= h; b %= mod; }
	return a * modpow(b, mod - 2) % mod;
}*/
//printf("%.10f\n", n);

signed main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n; cin >> n;
	vector<ll> a(n), b(n); map<ll, ll> m;
	rep(i, n) { cin >> a[i]; m[a[i]]++; }
	rep(i, n) { cin >> b[i]; m[b[i]]++; }

	rep(i, n + 2) {
		if (m[i] > n) { cout << "No\n"; return 0; }
	}

	reverse(all(b));
	rep(i, n) {
		if (a[i] == b[i]) {
			rep(j, n) {
				if (a[j] != a[i] && b[j] != b[i]) { swap(b[j], b[i]); break; }
				if (a[n - j - 1] != a[i] && b[n - j - 1] != b[i]) { swap(b[n - j - 1], b[i]); break; }
			}
		}
	}
	cout << "Yes" << endl;
	rep(i, n) {
		if (i == 0) { cout << b[i]; }
		else { cout << ' ' << b[i]; }
	}
	cout << endl;
	return 0;
}

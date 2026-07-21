#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }
ll mod = 1000000007;
ll modsize;

ll modinv(ll a) {
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = ans * a%mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ans;
}

vector<ll> fac(modsize + 5);
vector<ll> inv(modsize + 5);
vector<ll> facinv(modsize + 5);

void modcalc() {
	fac[0] = fac[1] = 1; inv[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i < modsize; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll modcomb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll modperm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k] % mod;
}

ll modhom(ll n, ll k) {
	if (n < 0 || k < 0) return 0;
	if (n == 0 && k == 0) return 1;
	return modcomb(n + k - 1, k);
}

template<class T>
class segtree {
	int n;
	vector<T> data;
	T def;
	function<T(T, T)> operation;
	function<T(T, T)> update;
	T _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return def;
		if (a <= l && r <= b) return data[k];
		T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
		T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
		return operation(c1, c2);
	}
public:
	segtree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
		:def(_def), operation(_operation), update(_update) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		data = vector<T>(2 * n - 1, def);
	}
	void change(int i, T x) {
		i += n - 1;
		data[i] = update(data[i], x);
		while (i > 0) {
			i = (i - 1) / 2;
			data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}
	T query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}
	T operator[](int i) {
		return data[i + n - 1];
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	modcalc();

	int n, r;
	cin >> n >> r;
	if (n >= 10) cout << r << endl;
	else cout << r + 100 * (10 - n) << endl;
}

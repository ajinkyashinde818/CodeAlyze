#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int  INF =  1e9;
const ll LINF = 1e18;
const ll MOD = 1e9+7;
const int SIZE = 100;

template<class T>
inline T gcd(T a, T b){return b ? gcd(b, a % b) : a;}

template<class T>
inline T lcm(T a, T b){return a / gcd(a, b) * b;}
 
ll fac[SIZE], inv[SIZE], facinv[SIZE];
void make() {
	fac[0] = fac[1] = 1; inv[1] = 1; facinv[0] = facinv[1] = 1;
	for (ll i = 2; i < SIZE; i++) {
		fac[i] = (fac[i-1] * i) % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		facinv[i] = facinv[i-1] * inv[i] % MOD;
	}
}
ll combi(ll a, ll b) {
	if (a < b) return 0;
	return fac[a] * (facinv[b] * facinv[a-b] % MOD) % MOD;
}

int main() {
	ll n;
	scanf ("%lld",&n);
	vector<ll> a(n);
	ll asum = 0;
	for (ll i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		asum += a[i];
	}
	ll x = a[0]; ll y = asum - a[0];
	ll ans = abs(x-y);
	for (ll i = 1; i < n-1; i++) {
		x += a[i]; y -= a[i];
		ans = min(ans, abs(x-y));
	}
	
	cout << ans << endl;
	return 0;
}

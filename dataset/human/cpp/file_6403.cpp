#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include <random>
#include <list>
#include <numeric>



#define rep(i,p,q) for(ll i = p;i < q;i++)
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<ll> query;
vector<ll> ans;
vector<ll> visited;

const ll MAX = 510000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//2019 C
int main(void) {
	ll n;
	string s;
	cin >> n >> s;
	vector<ll> d = vector<ll>(2 * n);
	//0 = L,1 = R
	d[0] = 0;
	d[2 * n - 1] = 1;
	rep(i, 0, 2 * n - 2) {
		if (s[i] == s[i + 1]) {
			d[i + 1] = d[i] ^ 1;
		}
		else {
			d[i + 1] = d[i];
		}
	}
	if (s[0] != 'B' || s[2 * n - 1] != 'B') cout << 0 << endl;
	else {
		ll ans = 1;
		bool can = true;
		ll lCount = 0;
		rep(i, 0, d.size()) {
			if (lCount < 0) {
				can = false;
				break;
			}
			if (d[i] == 1) {
				ans = (ans * lCount) % MOD;
				//ans %= MOD;
				lCount--;
			}
			else {
				lCount++;
			}
		}
		rep(i, 2, n + 1) {
			ans *= i;
			ans %= MOD;
		}
		if (lCount != 0) cout << 0 << endl;
		else cout << ans << endl;			
		
		
	}
}

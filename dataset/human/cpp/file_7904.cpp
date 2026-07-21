#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using P = pair<int, int>;

constexpr int INF = 1e9;
constexpr ll INFLL = 1e18;
constexpr int MOD = 1e9 + 7;
const ld PI = acosl(-1);

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(n) n.begin(),n.end()

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//cout << fixed << setprecision(6);
	ll n; cin >> n;
	vll a(1, 0);
	rep(i, n) {
		ll t; cin >> t;
		t += a.back();
		a.push_back(t);
	}

	ll ans = INFLL;
	for(int i = 1; i < a.size()-1; i++){
		ll x = a[i];
		ll y = a.back() - x;
		ans = min(ans, abs(x-y));
	}

	cout << ans << endl;
	return 0;
}

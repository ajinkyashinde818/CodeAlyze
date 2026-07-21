#include <bits/stdc++.h>
using namespace std;
using ll =long long;
using vl=vector<ll>;
using vb=vector<bool>;
using vs=vector<string>;
using vvl=vector<vl>;
using pll=pair<ll,ll>;
const ll oo =0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })
int main(){ cin.sync_with_stdio(0);
	ll N; cin >> N;

	ll open = 0;
	ll res = 1;
	const ll MOD = 1e9 + 7;
	FOR(i, 0, 2*N) {
		char c; cin >> c;
		ll val = c == 'B';

		if (open % 2 == val) {
			// r
			if (open <= 0) {
				res = 0;
				break;
			} else {
				res = (res * open) % MOD;
				open --;
			}
		} else {
			// l
			open ++;
		}
	}

	if (open != 0) res = 0;


	FOR(i, 2, N+1) {
		res = (res * i) % MOD;
	}

	cout << res << endl;
} //cin.tie(0) bei schnellem Wechseln

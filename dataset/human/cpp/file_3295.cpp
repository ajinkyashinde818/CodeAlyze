#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

ll mi(ll a, ll b){
	return a < b ? a : b;
}

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, neg = 0;
	ll res = 0, m = 1E10, tmp;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> tmp;
		if ( tmp < 0LL ){
			neg++;
			tmp *= (ll) -1LL;
			res += tmp;
			m = mi(tmp, m);
		}else{
			res += tmp;
			m = mi(tmp, m);
		}
	}
	if ( neg & 1 )
		res -= 2LL * m;

	cout << res << "\n";

	return 0;
}

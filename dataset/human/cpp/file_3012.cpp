#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli,lli> pll;
typedef vector<lli> vcL;

bool cmp(lli x, lli y) {
	return abs(x) < abs(y);
}

void solve() {
	int n = 1;
	cin >> n;
	lli s[ n+5 ];
	for (int i = 0; i < n; ++i) cin >> s[i];
	
	sort( s, s+n, cmp );
	
	lli neg = 0, sum = 0;
	
	for (int i = 0; i < n; ++i) {
		if ( s[i] < 0 ) neg++ ;
		sum += abs( s[i] );
	}
	
	if ( neg&1 ) {
		sum -= abs( s[0]*2 );
	}
	
	cout << sum << '\n';
}

int main() {
	int t = 1;
//	cin >> t;
	while ( t-- ) {
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
static constexpr int MOD = 1000000007;

int64_t cnt[ 26 ];

int main() {
	ios_base::sync_with_stdio( false );
	cin.tie( nullptr );
	int n; cin >> n;
	string ss; cin >> ss;
	for ( auto c : ss )
		cnt[ c - 'a' ]++;
	int64_t ans = 1;
	for ( int i = 0 ; i < 26 ; ++ i )
		ans = ans * ( cnt[ i ] + 1 ) % MOD;
	ans += MOD - 1;
	cout << ans % MOD << '\n';
	return 0;
}

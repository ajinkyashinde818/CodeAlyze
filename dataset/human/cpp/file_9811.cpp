#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
const int MOD = 1e9+7;
int _w;

int n, cnt[26];
char s[N];

int main() {
	_w = scanf( "%d", &n );
	_w = scanf( "%s", s+1 );
	for( int i = 1; i <= n; ++i )
		++cnt[s[i] - 'a'];
	int ans = 1;
	for( int i = 0; i < 26; ++i )
		ans = int(1LL * ans * (cnt[i] + 1) % MOD);
	ans = (ans - 1 + MOD) % MOD;
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int N;
string S;
map<char, int> seen;
const int MOD = 1e9+7;

void solve()
{
	for(auto c : S) seen[c]++;
	ll ans = 1;
	for(auto it=seen.begin(); it!= seen.end(); ++it){
		ans = (ans * (it->second+1)) % MOD;
	}
	if(!ans) cout << 0 << endl;
	else cout << ans - 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> S;
	solve();
	return 0;
}

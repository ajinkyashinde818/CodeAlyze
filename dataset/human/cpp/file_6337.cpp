#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int BIG = 1e9 + 555;
const int maxN = 2e5 + 55;

int n;
int f[maxN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cin >> s;

	for(int i = 0; i < n + n; i++){
		if(s[i] == 'B'){
			f[i] = 1;
		}	else {
			f[i] = 0;
		}
	}

	ll bal = 0;
	
	if(f[0] != 1){
		cout << "0\n";
		return 0;
	}
	
	ll ans = 1;
	for(int i = 0; i < n + n; i++){
		if((bal % 2) != f[i]){
			bal++;
		} else {
			ans = (ans * bal) % MOD;
			bal--;
		}

		if(bal < 0 || bal > n){
			cout << "0\n";
			return 0;
		}
	}

	if(bal != 0){
		cout << "0\n";
		return 0;
	}

	for(int i = 1; i <= n; i++){
		ans = (ans * i) % MOD;
	}

	cout << ans << '\n';

	return 0;
}

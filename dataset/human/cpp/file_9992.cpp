#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;


const ll mod = 1000000007;
ll num[26], tot = 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string S;
	int N;
	cin >> N >> S;
	for (int i = 0; i < S.size(); ++i){
		num[S[i]-'a']++;
	}
	for (int i = 0; i < 26; ++i){
		tot *= (num[i]+1);
		tot %= mod;
	}
	cout << tot-1 << '\n';
	cout << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}

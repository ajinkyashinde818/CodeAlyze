#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_N = 200005;
const ll MAX_M = 100000;
ll ans[MAX_N];
ll e[MAX_M];

int main() {
	ll n, m;
	cin >> n >> m;
	map<ll,ll> mp;
	stack<ll> q;
	vector<bool> b(n+5, false);
	for(int i=0;i<m;i++) {
		cin >> e[i];
	}
	ll itr = 0;
	for(int i=m-1;i>=0;i--) {
		ll tmp = e[i];
		if(mp[e[i]]==0) {
			ans[itr++] = e[i];
		}
		mp[e[i]]++;
		b[e[i]] = true;
	}
	for(int i=1;i<=n;i++) {
		if(b[i] == false) ans[itr++] = i;
	}
	for(int i=0;i<n;i++) {
		cout << ans[i] << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MN = 100100;
vvi g;
map<int,int> mo;
bitset<MN> bs;
void dfs(int u) {
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(!bs[v]) {bs.set(v);dfs(v);}
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vi wa[2];
	for(int id=0;id<2;id++) {
		int xo = 0;
		for(int i=0;i<n;i++) {
			int t;
			cin >> t;
			xo ^= t;
			wa[id].push_back(t);
		}
		wa[id].push_back(xo);
	}
	vi wb[2];
	wb[0] = wa[0];
	sort(wb[0].begin(),wb[0].end());
	wb[1] = wa[1];
	sort(wb[1].begin(),wb[1].end());
	bool poss = true;
	for(int i=0;i<wb[0].size();i++) {
		if(wb[0][i] != wb[1][i]) {
			poss = false;break;
		}
	}
	if(!poss) {
		cout << -1 << '\n';
		return 0;
	}
	int ct = 0;
	int no = 0;
	for(int i=0;i<wa[0].size();i++) {
		if(i < n && wa[0][i] == wa[1][i]) {continue;}
		no++;
		for(int id=0;id<2;id++) {
			int u = wa[id][i];
			if(!mo.count(u)) {
				mo[u] = ct;
				wa[id][i] = ct;
				ct++;
			} else {
				wa[id][i] = mo[u];
			}
		}
	}
	g.assign(mo.size(),vi());
	for(int i=0;i<wa[0].size();i++) {
		int a = wa[0][i];
		int b = wa[1][i];
		if(i < n && a == b) {continue;}
		g[a].push_back(b);
	}
	int num = 0;
	for(int i=0;i<g.size();i++) {
		if(!bs[i]) {
			bs.set(i);
			num++;
			dfs(i);
		}
	}
	cout << no+num-2 << '\n';
}

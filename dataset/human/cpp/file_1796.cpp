#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> b(n+1, 0);
	for(int i=0; i<m; ++i){
		int t;
		cin >> t;
		a.push_back(t);
		b[t] = i+1;
	}
	vector<pair<int, int>> c;
	for(int i=1; i<=n; ++i)
		if(b[i] > 0)
			c.push_back(make_pair(m-b[i]+1, i));
	sort(c.begin(), c.end());
	for(int i=0; i<c.size(); ++i)
		cout << c[i].second << "\n";
	for(int i=1; i<=n; ++i)
		if(b[i] == 0) cout << i << "\n";
}

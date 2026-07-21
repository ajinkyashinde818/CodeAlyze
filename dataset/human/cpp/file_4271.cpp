#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int par[100010],sz[100010];
void init(int n){
	for(int i=0;i<n;i++){
		par[i] = i; sz[i] = 1;
	}
}

int find(int x){
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	sz[x] += sz[y]; par[y] = x;
}

bool same(int x, int y){
	return find(x)==find(y);
}

map<int,int> mp;
vector<int> v;
int zatu(){
	int now = 0;
	for(auto x:mp){
		v.push_back(x.first);
		now++;
	}
	for(int i=0;i<now;i++){
		mp[v[i]] = i;
	}
	return now;
}

vector<int> c,d;
int a[100010],b[100010];
bool flag[100010];
int ans = 0;
int main(){
	int i,n,x = 0;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		c.push_back(a[i]); x ^= a[i];
	}
	a[n] = x; c.push_back(x);
	x = 0;
	for(i=0;i<n;i++){
		cin >> b[i];
		d.push_back(b[i]);x ^= b[i];
	}
	b[n] = x; d.push_back(x);
	sort(c.begin(),c.end()); sort(d.begin(),d.end());
	for(i=0;i<=n;i++){
		if(c[i]!=d[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){
			ans++;
			mp[a[i]]++;
		}
	}
	mp[a[n]]++;
	if(ans==0){
		cout << 0 << endl;
		return 0;
	}
	ans++;
	int mx = zatu();
	init(mx);
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){
			unite(mp[a[i]],mp[b[i]]);
		}
	}
	for(i=0;i<mx;i++){
		if(par[i]==i) ans++;
	}
	cout << ans - 2 << endl;
}

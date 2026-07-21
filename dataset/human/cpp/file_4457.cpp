#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;

LL n,m,k,tot;
LL a[500005],b[500005],c[500005],d[500005];
LL vis[500005] = {0};
string s;
map <LL,LL> mp;

LL fa[500005];
LL getf(LL x){
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}
void unionn(LL x,LL y){
	x = getf(x); y = getf(y);
	if(x == y) return;
	tot --; fa[x] = y;
}

int main(){
	cin >> n;
	for(LL i = 1;i <= n;i ++){ cin >> a[i]; c[i] = a[i]; a[n + 1] ^= a[i]; }
	for(LL i = 1;i <= n;i ++){ cin >> b[i]; d[i] = b[i]; b[n + 1] ^= b[i]; }
	n ++; c[n] = a[n]; d[n] = b[n];
	sort(c + 1,c + 1 + n); sort(d + 1,d + 1 + n);
	for(LL i = 1;i <= n;i ++){
		if(c[i] != d[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	tot = 0;
	for(LL i = 1;i < n;i ++){
		if(a[i] != b[i]){
			if(mp.find(a[i]) == mp.end()) mp[a[i]] = ++ tot;
			if(mp.find(b[i]) == mp.end()) mp[b[i]] = ++ tot;
		}
	}
	if(mp.find(a[n]) == mp.end()) mp[a[n]] = ++ tot;
	if(mp.find(b[n]) == mp.end()) mp[b[n]] = ++ tot;
	for(LL i = 1;i <= n;i ++){
		a[i] = mp[a[i]];
		b[i] = mp[b[i]];
	}
	
//	for(LL i = 1;i <= n;i ++) cout << a[i] << (i == n ? '\n' : ' ');
//	for(LL i = 1;i <= n;i ++) cout << b[i] << (i == n ? '\n' : ' ');
	
	LL tmp = 0;
	for(LL i = 1;i <= tot;i ++) fa[i] = i;
	for(LL i = 1;i < n;i ++){
		if(a[i] != b[i]){
			tot ++; tmp = 1;
			unionn(a[i],b[i]);
			vis[a[i]] = 1; vis[b[i]] = 1;
		}
	}
	unionn(a[n],b[n]);
	tot --;
//	if(!tmp) tot = 0;
	cout << tot << endl;
	return 0;
}

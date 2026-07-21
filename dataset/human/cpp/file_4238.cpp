#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
vector<int> g[100002];
bool used[100002];
int ct;
void dfs(int x){
	used[x]=1;
	for(auto y:g[x]){
		if(!used[y]) dfs(y);
	}
}
int main()
{
	int n; cin>>n;
	int a[100002], b[100002], as[100002], bs[100002], s=0;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin>>a[i]; as[i]=a[i];
		s^=a[i];
	}
	as[n]=a[n]=s;
	sort(as, as+n+1);
	s=0;
	int ans=0;
	for(int i=0; i<n; i++){
		cin>>b[i]; bs[i]=b[i];
		s^=b[i];
		if(a[i]!=b[i]) mp[b[i]]=0, ans++;
	}
	bs[n]=b[n]=s;
	mp[a[n]]=mp[b[n]]=0;
	sort(bs, bs+n+1);
	for(int i=0; i<=n; i++){
		if(as[i]!=bs[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	int c=0;
	for(auto& p:mp){
		p.second=c; c++;
	}
	for(int i=0; i<n; i++){
		int x=mp[a[i]], y=mp[b[i]];
		g[x].push_back(y); g[y].push_back(x);
	}
	for(int i=0; i<c; i++){
		if(!used[i]){
			dfs(i); ct++;
		}
	}
	ans+=(ct-1);
	cout<<ans<<endl;
	return 0;
}

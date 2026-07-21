#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int maxn=2e5+7;
vi G[maxn];
int fa[maxn];
int sz[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(y!=x)
	{
		fa[y]=x;
		sz[x]+=sz[y];
	}
}
int main()
{
	for(int i=0;i<maxn;i++) sz[i]=1,fa[i]=i;
	int n;
	cin>>n;
	vi a(n),b(n);
	vi all;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		all.push_back(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		all.push_back(b[i]);
	}
	int x=0;
	for(int i=0;i<n;i++) x^=a[i];
	all.push_back(x);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	auto getid=[&](int x){
		return lower_bound(all.begin(),all.end(),x)-all.begin();
	};
	map<int,int> cnt;
	for(auto u:b) cnt[u]++;
	int dif=0;
	for(auto u:a)
		cnt[u]--;
	cnt[x]--;
	for(auto u:cnt)
		dif+=abs(u.second);
	if(dif>1){
		cout<<-1<<'\n';
		return 0;
	}
	int tar=-1;
	for(auto u:cnt) if(u.second) tar=u.first;
	for(auto &u:a) u=getid(u);
	for(auto &u:b) u=getid(u);
	Union(getid(tar),getid(x));
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i]) ans++;
		Union(a[i],b[i]);
	}
	for(int i=0;i<maxn;i++)
	{
		if(Find(i)==i&&sz[Find(i)]!=1)
			ans++;
	}
	if(sz[Find(getid(x))]!=1) ans--;
	cout<<ans<<'\n';
}

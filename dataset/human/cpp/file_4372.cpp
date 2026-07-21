#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
const int N=200100;
int n,fa[N],a[N],b[N],c[N],d[N],cnt,ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],a[0]^=a[i];
	for(int i=1;i<=n;++i)cin>>b[i],b[0]^=b[i];
	for(int i=0;i<=n;++i)c[i]=a[i],d[i]=b[i];
	sort(c,c+n+1);sort(d,d+n+1);
	for(int i=0;i<=n;++i)if(c[i]!=d[i]){
		cout<<-1<<'\n';
		return 0;
	}
	if(!mp.count(a[0]))mp[a[0]]=++cnt,fa[cnt]=cnt;
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i]){
			if(!mp.count(a[i]))mp[a[i]]=++cnt,fa[cnt]=cnt;
			if(!mp.count(b[i]))mp[b[i]]=++cnt,fa[cnt]=cnt;
			int u=mp[a[i]],v=mp[b[i]];
			fa[find(u)]=find(v);
			++ans;
		}
	for(int i=1;i<=cnt;++i)ans+=fa[i]==i;
	cout<<(ans-1)<<'\n';
	return 0;
}

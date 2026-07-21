#include<cstdio>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e5;
int n,a[N+2],b[N+1];
int cnt,mp[N*2+2];
vector<int>e[N*2+2];
bool vis[N*2+2];
int res;
int read()
{
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) {
		c=getchar();
	}
	while(isdigit(c)) {
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
bool contain(int x[],int y[])
{
	static int buc[N*2+2];
	for(int i=1;i<=n+1;++i) {
		++buc[x[i]];
	}
	for(int i=1;i<=n;++i) {
		if(--buc[y[i]]<0) {
			return false;
		}
	}
	return true;
}
void dfs(int u)
{
	vis[u]=true;
	for(int v:e[u]) {
		if(!vis[v]) {
			dfs(v);
		}
	}
	return;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) {
		a[i]=read();
		a[n+1]^=a[i],mp[i]=a[i];
	}
	for(int i=1;i<=n;++i) {
		b[i]=read();
		mp[n+i]=b[i];
	}
	mp[n*2+1]=a[n+1];
	sort(mp+1,mp+n*2+2);
	cnt=unique(mp+1,mp+n*2+2)-mp-1;
	for(int i=1;i<=n;++i) {
		a[i]=lower_bound(mp+1,mp+cnt+1,a[i])-mp;
		b[i]=lower_bound(mp+1,mp+cnt+1,b[i])-mp;
	}
	a[n+1]=lower_bound(mp+1,mp+cnt+1,a[n+1])-mp;
	if(!contain(a,b)) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i) {
		if(a[i]==b[i]) {
			continue;
		}
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
		++res;
	}
	for(int i=1;i<=cnt;++i) {
		if(!e[i].empty()&&!vis[i]) {
			dfs(i);
			++res;
		}
	}
	if(!e[a[n+1]].empty()) {
		--res;
	}
	printf("%d\n",res);
	return 0;
}

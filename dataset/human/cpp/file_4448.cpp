#include<bits/stdc++.h>
using namespace std;
inline char nchar() {
	static const int bufl=1<<20;
	static char buf[bufl],*a=NULL,*b=NULL;
	return a==b && (b=(a=buf)+fread(buf,1,bufl,stdin),a==b)?EOF:*a++;
}
inline int read() {
	int x=0,f=1;
	char c=nchar();
	for (;!isdigit(c);c=nchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=nchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=2e5+10;
int n,a[maxn],b[maxn],tot=0;
unordered_map<int,int> id;
bool same() {
	static int a[maxn],b[maxn];
	copy(::a,::a+n+1,a);
	copy(::b,::b+n+1,b);
	sort(a,a+n+1),sort(b,b+n+1);
	return equal(a,a+n+1,b);
}
namespace graph {
	vector<int> g[maxn];
	bool vis[maxn];
	inline void add(int x,int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int dfs(int x) {
		if (!vis[x]) vis[x]=true; else return 0;
		int ret(1);
		for (const int &v:g[x]) ret+=dfs(v);
		return ret;
	}
	int count() {
		int ret(0);
		for (int i=1;i<=tot;++i) if (!vis[i]) {
			int tmp(dfs(i));
			if (tmp==1) vis[i]=false; else ++ret;
		}
		return ret;
	}
}
inline int add_node(int x) {
	int &p=id[x];
	if (!p) p=++tot;
	return p;
}
int main() {
	n=read();
	for (int i=1;i<=n;++i) a[0]^=(a[i]=read());
	for (int i=1;i<=n;++i) b[0]^=(b[i]=read());
	if (!same()) return puts("-1"),0;
	if (equal(a,a+n+1,b)) return puts("0"),0;
	int ans=0;
	for (int i=1;i<=n;++i) {
		int x=add_node(a[i]),y=add_node(b[i]);
		if (x!=y) graph::add(x,y),++ans;
	}
	int p=graph::count();
	int x=add_node(a[0]),y=add_node(b[0]);
	ans=ans+p+(!graph::vis[x])+(x!=y && !graph::vis[y])-1;
	printf("%d\n",ans);
	return 0;
}

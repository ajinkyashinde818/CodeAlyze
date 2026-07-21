#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mxsiz=10;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
int ans=0x3f3f3f3f;
int n,f[maxn],g[maxn];
inline void dfs(int x){
	if(x>mxsiz||x>ans)return;
	int yh=0;
	for(register int i=1;i<=n;++i){
		if(f[i]^g[i])break;
		if(i==n){
			ans=x;
			return;
		}
	}
	for(register int i=1;i<=n;++i)yh^=f[i];
	for(register int i=1;i<=n;++i){
		int tmp=f[i];
		f[i]=yh;
		dfs(x+1);
		f[i]=tmp;
	}
}
int a[maxn],b[maxn],cnt,tot;
map<int,int>mp;
int fst[maxn],lst[maxn<<1],to[maxn<<1],e;
int cl[maxn],num[maxn],d[maxn];
inline void add(int x,int y){
	to[++e]=y,lst[e]=fst[x],fst[x]=e;
}
inline void dfs(int x,int c){
	cl[x]=c;
	for(register int i=fst[x];i;i=lst[i])if(!cl[to[i]])dfs(to[i],c);
}
inline void solve(){
	for(register int i=1;i<=n;++i)a[i]=f[i],a[0]^=f[i],b[i]=g[i],b[0]^=g[i];
	f[0]=a[0],g[0]=b[0],sort(a,a+n+1),sort(b,b+n+1);
	for(register int i=0;i<=n;++i)if(a[i]^b[i])return;
	ans=0,f[n+1]=f[0],g[n+1]=g[0],++n;
	for(register int i=1;i<=n;++i){
		if(!mp[f[i]])mp[f[i]]=++cnt;
		a[i]=mp[f[i]];
		if(!mp[g[i]])mp[g[i]]=++cnt;
		b[i]=mp[g[i]];
	};
	for(register int i=1;i<=n;++i){
		if(a[i]^b[i])add(a[i],b[i]),add(b[i],a[i]),++d[a[i]],++d[b[i]];		
	}
	for(register int i=1;i<=n;++i)d[i]/=2;
	for(register int i=1;i<=n;++i)if(!cl[a[i]]&&a[i]!=b[i])++tot,dfs(a[i],tot);
	for(register int i=1;i<=n;++i)num[cl[i]]+=d[i];
	for(register int i=1;i<=tot;++i){
		if(num[i]<=1)continue;
		ans+=num[i];
		if(i^cl[a[n]])++ans;
		else if(a[n]!=b[n])--ans;
	}
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)f[i]=read();
	for(register int i=1;i<=n;++i)g[i]=read();
	if(n<=5)dfs(0);
	else solve();
	if(ans==0x3f3f3f3f)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

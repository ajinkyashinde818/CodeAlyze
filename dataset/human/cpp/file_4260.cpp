/*
  code by RyeCatcher
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype> 
#include <utility>
#include <queue>
#include <vector>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#define DEBUG freopen("dat.in","r",stdin);freopen("wa.out","w",stdout);
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define ri register int
#define ll long long
#define ull unsigned long long
#define SIZE 1<<22
using std::min;
using std::max;
using std::priority_queue;
using std::queue;
using std::vector;
using std::pair;
using namespace __gnu_pbds;
inline char gc(){
    static char buf[SIZE],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
template <class T>inline void read(T &x){
    x=0;int ne=0;char c;
    while((c=gc())>'9'||c<'0')ne=c=='-';x=c-48;
    while((c=gc())>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48;x=ne?-x:x;return ;
}
gp_hash_table <int,int> g;
const int maxn=100005;
const int inf=0x7fffffff;
int f[maxn],tot=0;
int a[maxn],b[maxn],c[maxn],d[maxn],n;
int fa[maxn<<1],size[maxn<<1];
bool vis[maxn<<1];
int get(int x){return (fa[x]==x)?fa[x]:(fa[x]=get(fa[x]));}
inline void merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y){
		//size[x]++;
		return ;
	}
	if(size[x]<size[y]){
		size[y]+=size[x];
		fa[x]=y;
	}
	else{
		size[x]+=size[y];
		fa[y]=x;
	}
	return ;
}
ll ans=0;
int main(){
	int x,pre_sum=0;
	read(n);
	for(ri i=1;i<=n;i++){
		read(x);
		pre_sum^=x;
		if(!g[x]){
			g[x]=++tot;
			vis[tot]=0,size[tot]=0,fa[tot]=tot;
			f[tot]=x;
		}
		c[i]=a[i]=g[x];
	}
	if(!g[pre_sum]){
		g[pre_sum]=++tot,f[tot]=g[pre_sum];
		vis[tot]=0,size[tot]=0,fa[tot]=tot;
	}
	//printf("--%d--\n",pre_sum);
	a[n+1]=c[n+1]=g[pre_sum];
	pre_sum=0;
	for(ri i=1;i<=n;i++){
		read(x);
		pre_sum^=x;
		if(!g[x]){
			g[x]=++tot;
			vis[tot]=0,size[tot]=0,fa[tot]=tot;
			f[tot]=x;
		}
		d[i]=b[i]=g[x];
		if(a[i]!=b[i])size[a[i]]++;
	}
	if(!g[pre_sum]){
		g[pre_sum]=++tot,f[tot]=g[pre_sum];
		vis[tot]=0,size[tot]=1,fa[tot]=tot;
	}
	//printf("--%d--\n",pre_sum);
	b[n+1]=d[n+1]=g[pre_sum];
	n++;	
	std::sort(c+1,c+1+n);std::sort(d+1,d+1+n);
	//printf("%d\n",n);
	for(ri i=1;i<=n;i++){
		if(c[i]!=d[i]){puts("-1");exit(0);}
		if(a[i]!=b[i]){
			//printf("%d %d\n",a[i],b[i]);
			merge(a[i],b[i]);
		}
	}
	int cnt=0;
	x=get(a[n]);
	if(size[x]==0){
		//vis[get(a[n])]=1;
		ans=0,cnt=1;
		//puts("sss");
	}
	for(ri i=1;i<n;i++){
		x=get(a[i]);
		//printf("%d %d %d\n",i,a[i],f[a[i]]);
		if(!vis[x]){
			if(size[x]==0)continue;
			cnt++,vis[x]=1;
			ans+=size[x];
			//printf("%d %d %d %d\n",f[i],i,x,size[x]);
		}
	}
	printf("%lld\n",ans+cnt-1);
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>

using namespace std;
typedef long long LL;

const int maxn = 200005;
map<int,int> h;
int n,a[maxn],b[maxn],c[maxn],d[maxn],tot,ans,p[maxn]; 
int findp(int t) {return p[t]?p[t]=findp(p[t]):t;}
void merge(int u,int v) {u=findp(u);v=findp(v);u!=v?p[u]=v:0;}
int main()
{
	#ifdef Amberframe
		freopen("agc016d.in","r",stdin);
		freopen("agc016d.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[0]^=a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),b[0]^=b[i];
	for (int i=0;i<=n;i++) c[i]=a[i],d[i]=b[i];
	sort(c,c+n+1);sort(d,d+n+1);
	for (int i=0;i<=n;i++) if (c[i]!=d[i]) {puts("-1");return 0;}
	for (int i=1;i<=n;i++)
	if (a[i]!=b[i]) {
		(!h[a[i]])?h[a[i]]=++tot:0;
		(!h[b[i]])?h[b[i]]=++tot:0;
		merge(h[a[i]],h[b[i]]);++ans;
	}
	!h[a[0]]?++ans:0;
	for (int i=1;i<=tot;i++) ans+=(p[i]==0);
	printf("%d",ans?ans-1:ans);
	return 0;
}

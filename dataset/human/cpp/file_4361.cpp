#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN = 100003;
int n,a[MaxN],b[MaxN];
int t1[MaxN],t2[MaxN];

int fa[MaxN],rk[MaxN];
bool vis[MaxN];
int getfa(int x) {
	if (x!=fa[x]) fa[x]=getfa(fa[x]);
	return fa[x];
}
void uni(int a,int b) {
	a=getfa(a),b=getfa(b);
	if (a!=b) {
		if (rk[a]<rk[b]) {
			fa[a]=b;
			rk[b]+=rk[a];
		} else {
			fa[b]=a;
			rk[a]+=rk[b];
		}
	}
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i) scanf("%d",b+i);
	for (int i=0;i<=n;++i) a[0]^=a[i],b[0]^=b[i];
	for (int i=0;i<=n;++i) t1[i]=a[i],t2[i]=b[i];
	sort(t1,t1+n+1),sort(t2,t2+n+1);
	for (int i=0;i<=n;++i)
		if (t1[i]!=t2[i]) {
			puts("-1");
			return 0;
		}
	int* ed=unique(t1,t1+n+1);
	for (int i=0;i<=n;++i) a[i]=lower_bound(t1,ed,a[i])-t1,b[i]=lower_bound(t1,ed,b[i])-t1;
	for (int i=0;i<=n;++i) fa[i]=i,rk[i]=1;
	int ans=0;
	for (int i=1;i<=n;++i) if (a[i]!=b[i]) {
		uni(a[i],b[i]);
		ans++;
	}
	for (int i=0;i<=n;++i) if (getfa(i)==i && rk[i]>=2) ans++;
	if (rk[getfa(a[0])]>=2) ans--;
	printf("%d\n",ans);
	return 0;
}

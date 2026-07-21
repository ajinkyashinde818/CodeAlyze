#include <algorithm>
#include <cstdio>
using namespace std;
const int N=100005;
int a[N],b[N],c[N*2],fa[N];
bool u[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	int n,m=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[0]^=a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),b[0]^=b[i];
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i]) a[++m]=a[i],b[m]=b[i];
	n=m;
	for (int i=0;i<=n;i++) c[i]=a[i],c[n+1+i]=b[i];
	sort(c,c+n+1);
	sort(c+n+1,c+n+n+2);
	for (int i=0;i<=n;i++)
		if (c[i]!=c[n+1+i]){
			printf("-1\n");
			return 0;
		}
	m=unique(c,c+n+1)-c-1;
	for (int i=0;i<=m;i++) fa[i]=i;
	for (int i=0;i<=n;i++){
		a[i]=lower_bound(c,c+m+1,a[i])-c;
		b[i]=lower_bound(c,c+m+1,b[i])-c;
		fa[find(a[i])]=find(b[i]);
	}
	int ans=n;
	for (int i=0;i<=m;i++)
		if (find(i)==i) ans++;
	printf("%d\n",ans-1);
}

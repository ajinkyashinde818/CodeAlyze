#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100010],b[100010],c[100010],d[100010],fa[100010];

int find(int x)
{
    if (x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void merge(int x,int y) {fa[find(x)]=find(y);}

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    a[n+1]=0;for (int i=1;i<=n;i++) a[n+1]^=a[i];
    b[n+1]=0;for (int i=1;i<=n;i++) b[n+1]^=b[i];
    int l=0;
    for (int i=1;i<=n+1;i++) if (a[i]!=b[i]||i==n+1) {c[++l]=a[i];d[l]=b[i];}
    sort(c+1,c+l+1);sort(d+1,d+l+1);
    for (int i=1;i<=l;i++) if (c[i]!=d[i]) {puts("-1");return 0;}
    int ans=0;
    for (int i=1;i<=n;i++) ans+=(a[i]!=b[i]);
    int m=0;for (int i=1;i<=l;i++) if (i==1||c[i]!=c[i-1]) c[++m]=c[i];
    for (int i=1;i<=m;i++) fa[i]=i;
    for (int i=1;i<=n;i++) if (a[i]!=b[i]) merge(lower_bound(c+1,c+m+1,a[i])-c,lower_bound(c+1,c+m+1,b[i])-c);
    for (int i=1;i<=m;i++) if (fa[i]==i) ans++;
    printf("%d\n",ans-1);
    return 0;
}

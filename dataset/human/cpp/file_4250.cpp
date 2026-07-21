#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,ans,a[200005],b[200005],c[200005],d[200005],p[200005],fa[200005];
int find(int x)
{
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[n+1]^=a[i];
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]),b[n+1]^=b[i];
    for (int i=1;i<=n+1;i++)
        c[i]=a[i],d[i]=b[i];
    sort(a+1,a+n+2),sort(b+1,b+n+2);
    for (int i=1;i<=n+1;i++)
        if (a[i]!=b[i]) {printf("-1\n");return 0;}

    for (int i=1;i<=n+1;i++)
        if (c[i]!=d[i] || i==n+1) p[++m]=c[i],p[++m]=d[i],ans+=(i<=n);
    if (ans==0) {printf("0\n");return 0;}
    sort(p+1,p+m+1),m=unique(p+1,p+m+1)-p-1;

    for (int i=1;i<=m;i++) fa[i]=i;
    for (int i=1;i<=n+1;i++)
        if (c[i]!=d[i])
        {
            c[i]=lower_bound(p+1,p+m+1,c[i])-p,d[i]=lower_bound(p+1,p+m+1,d[i])-p;
            fa[find(c[i])]=find(d[i]);
        }


    /*
    for (int i=1;i<=n+1;i++)
        p[++m]=c[i],p[++m]=d[i];
    sort(p+1,p+m+1),m=unique(p+1,p+m+1)-p-1;

    for (int i=1;i<=m;i++) fa[i]=i;
    for (int i=1;i<=n+1;i++)
        c[i]=lower_bound(p+1,p+m+1,c[i])-p,d[i]=lower_bound(p+1,p+m+1,d[i])-p;
    for (int i=1;i<=n+1;i++)
        if (c[i]!=d[i] || i==n+1)
            fa[find(c[i])]=find(d[i]),ans+=(i<=n);
        else ans--;
    if (ans==0) {printf("0\n");return 0;}
    */
    for (int i=1;i<=m;i++)
        if (find(i)==i) ans++;
    printf("%d\n",ans-1);
    return 0;
}

#include <stdio.h>
int a[25],b[25],c[25];

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<n;i++)  scanf("%d",&c[i]);
    int ans=b[a[1]];
    for (int i=2;i<=n;i++)
    {
        ans+=b[a[i]];
        if ( a[i]==(a[i-1]+1) ) ans+=c[a[i-1]];
    }
    printf("%d\n",ans);
}

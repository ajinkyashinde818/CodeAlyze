#include <stdio.h>

#define mmod 1000000007
int f[100010];
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++) f[i]=1;
    for (int i=0;i<m;i++)
    {
        int tt;scanf("%d",&tt);
        f[tt]=-1;
    }

    for (int i=2;i<=n;i++)
    {
        if (f[i]==-1) continue;
        f[i]=0;
        if (f[i-1]!=-1) f[i]+=f[i-1],f[i]%=mmod;
        if (f[i-2]!=-1) f[i]+=f[i-2],f[i]%=mmod;
    }
    printf("%d\n",f[n]);

}

#include<cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char a[51][51],b[51][51];
    for (int i=1;i<=n;i++)
    {
        scanf("\n");
        for (int j=1;j<=n;j++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    for (int i=1;i<=m;i++)
    {
        scanf("\n");
        for (int j=1;j<=m;j++)
        {
            scanf("%c",&b[i][j]);
        }
    }
    for (int x=1;x<=n-m+1;x++)
    {
        for (int y=1;y<=n-m+1;y++)
        {
            bool ok=true;
            for (int i=1;i<=m;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    if (b[i][j]!=a[x+i-1][y+j-1])
                    {
                        ok=false;
                    }
                }
            }
            if (ok)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

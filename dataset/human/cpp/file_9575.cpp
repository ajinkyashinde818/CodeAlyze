#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[55][55],b[55][55];
int main()
{
    int n,m,flag1=0,flag2=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<m;i++)
    scanf("%s",b[i]);
    for(int i=0;i<=n-m;i++)
        for(int j=0;j<=n-m;j++)
    {
        flag1=0;
        for(int k=0;k<m;k++)
                for(int l=0;l<m;l++)
            {
                if(a[i+k][j+l]!=b[k][l]) {flag1=1;break;}
            }

        if(flag1==0)
        {
            flag2=1;
            break;
        }
    }
    if(flag2) puts("Yes");
    else puts("No");
    return 0;
}

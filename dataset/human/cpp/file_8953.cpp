#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

char a[55][55],b[55][55];
int n,m;

bool judge(int x,int y)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[x+i][y+j] != b[i][j])
                return false;
        }
    }
    return true;
}
int main(void)
{
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        for(i=0;i<m;i++)
            scanf("%s",b[i]);
        int f = 0;
        for(i=0;i<n-m+1;i++)
        {
            for(j=0;j<n-m+1;j++)
            {
                if(judge(i,j))
                {
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                break;
        }
        if(f == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

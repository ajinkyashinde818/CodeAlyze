#include<stdio.h>
int n,m,x;
struct node
{
    int c;
    int a[100];
}q[100];
int ans[100];
int minn1=10000000000;
void dfs(int index,int minn2)
{
    if(index==n)
    {
        if(minn2<minn1)
        {
            int flag=0;
            for(int i=0;i<m;i++)
            {
                if(ans[i]<x)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                minn1=minn2;
            }
        }
        return;
    }
     for(int i=0;i<m;i++)
    {
        ans[i]+=q[index].a[i];
    }
    dfs(index+1,minn2+q[index].c);
     for(int i=0;i<m;i++)
    {
        ans[i]-=q[index].a[i];
    }
    dfs(index+1,minn2);

}
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i].c);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&q[i].a[j]);
        }
    }
    dfs(0,0);
    if(minn1==1410065408)
    {
        printf("-1\n");
    }
    else
    printf("%d\n",minn1);
}

#include<stdio.h>
int main()
{
    int n,k,s;
    scanf("%d%d%d",&n,&k,&s);
    if(n==k)
    {
        for(int i=1;i<=n;i++)
        {   if(i!=n)
            printf("%d ",s);
            else
            printf("%d",s);
        }
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            printf("%d ",s);
        }
        for(int i=1;i<=n-k;i++)
        {
            if(s==1000000000)
            {
            if(i!=n-k)
            printf("%d ",s-1);
            else
            printf("%d",s-1);
            }
            else
            {
            if(i!=n-k)
            printf("%d ",s+1);
            else
            printf("%d",s+1);
            }
        }
    }
    return 0;
}

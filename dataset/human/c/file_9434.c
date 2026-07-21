#include<stdio.h>
int main()
{
    int n,d,x,a[100],i,t,ans;
    scanf("%d %d %d",&n,&d,&x);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ans=x;
    for(i=0;i<n;i++)
    {
        t=0;int k=0;
        while(a[i]*t+1<=d)
        {
            k++;
            t++;
        }
        ans=ans+k;
    }
    printf("%d\n",ans);
    return 0;
}

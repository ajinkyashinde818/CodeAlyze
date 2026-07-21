#include<stdio.h>
#include<stdlib.h>

int main()
{
    int k,n,a[200005],d,i,max;
    scanf("%d %d",&k,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=-1;
    for(i=1;i<=n-1;i++)
    {
        d=a[i+1]-a[i];
        if(d>max)
        {
            max=d;
        }
    }
    d=k-a[n]+a[1];
    if(d>max)
    {
        max=d;
    }
    printf("%d\n",k-max);
}

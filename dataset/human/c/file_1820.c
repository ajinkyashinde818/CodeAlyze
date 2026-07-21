#include<stdio.h>
int main()
{
    int n,a[100],b[100],c[100],i,p,t,s,f;
    scanf("%d",&n);
    s=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<(n-1);i++)
    {
        scanf("%d",&c[i]);
    }
    for(i=0;i<n;i++)
    {
        p=i-1;
        if(i==0||a[i]!=a[p]+1)
        {
            t=a[i]-1;
            s=s+b[t];
        }
        else
        {
            t=a[i]-1;
            f=a[i]-2;
            s=s+b[t]+c[f];
        }
    }
    printf("%d\n",s);
    return 0;
}

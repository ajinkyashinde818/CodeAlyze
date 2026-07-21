#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,a[21],b[21],c[21],i,x,sum=0,pre=0;
    scanf("%d",&n);
    for(i=0;i<n+1;i++) a[i]=b[i]=c[i]=0;
    for(i=1;i<n+1;i++) scanf("%d",&a[i]);
    for(i=1;i<n+1;i++) scanf("%d",&b[i]);
    for(i=1;i<n;i++) scanf("%d",&c[i]);
    for(i=1;i<n+1;i++)
    {
        sum+=b[a[i]];
        if(pre+1==a[i]) sum+=c[pre];
        pre=a[i];
    }
    printf("%d",sum);
    return 0;
}

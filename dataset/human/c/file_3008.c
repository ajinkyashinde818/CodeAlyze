#include <stdio.h>
#include<stdlib.h>
int main()
{
    int k,n,i,max,t;
    int a[200000];
    scanf("%d %d",&k,&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    max=a[1]-a[0];
    for(i=2;i<n;i++)
    {
        if(max<(a[i]-a[i-1]))
            max=a[i]-a[i-1];
    }
    t=k-a[n-1]+a[0];
    if(t>max)
        max=t;
    printf("%d",k-max);
}

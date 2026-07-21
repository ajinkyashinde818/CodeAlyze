#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,sum=0,i,a[22]={0},b[22]={0},c[22]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<n;i++)
        scanf("%d",&c[i]);
    for(i=0;i<n;i++)
    {
        sum+=b[a[i]];
        if(a[i]+1==a[i+1])
        sum += c[a[i]];
    }
    printf("%d\n",sum);
 return 0;
}

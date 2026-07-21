#include<stdio.h>
#include<string.h>
long long a,b,i,srx,sry;
long long zzh;
long long max(long long x,long long y)
{
    if(x>y)
    return x;
    return y;
}
long long min(long long x,long long y)
{
    if(x>y)
    return y;
    return x;
}
int main()
{
    scanf("%d%d",&srx,&sry);
    a=max(sry,srx);
    b=min(srx,sry);
    long long r;
    while(b>0)
    {r=a%b;
    a=b;
    b=r;}
    zzh=srx*sry/a;
    printf("%lld",zzh);
    return 0;
}

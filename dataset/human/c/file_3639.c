#include<stdio.h>
int main (void)
{
    long long a,b,t;
    int i,j;
    long long k;
    scanf("%lld%lld",&a,&b);
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    for(i=1;;i++)
    {
        k=a*i;
        if(k%b==0)
            break;
    }
    printf("%lld\n",k);
}

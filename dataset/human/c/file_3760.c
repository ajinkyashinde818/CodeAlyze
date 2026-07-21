#include<stdio.h>
#include<math.h>
int main()
{
    long long int a,b,c,temp,gcd;
    int i;
    scanf("%lld%lld",&a,&b);
    c=a*b;
    if(a>b)
        temp=b;
    else
        temp=a;
    for(i=1;i<=temp;i++)
    {
        if(a%i==0 && b%i==0)
        {
        gcd=i;
        }

    }
    printf("%lld",(c/gcd));
    return 0;
}

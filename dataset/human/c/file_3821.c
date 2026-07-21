#include<stdio.h>

int main()
{
    long long int gcd,lsd,a,b,t,mul;
    scanf("%lld%lld",&a,&b);
    mul=a*b;
    if(a==0)gcd=b;
    else if(b==0)gcd=a;
    else{
        while(b!=0){
            t=a%b;
            a=b;
            b=t;
            if(t==0)break;
        }
        gcd=a;

    }
    lsd=mul/gcd;

    printf("%lld",lsd);
}

#include<stdio.h>
int main(void)
{
    long long n,item,a,b,i,temp;


    scanf("%lld %lld",&a,&b);
    item=a*b;
    if(a<b)  {
        temp=a;
        a=b;
        b=temp;
    }
    for(i=b; i>0; i--) {
        if (a % i == 0 && b % i == 0) {

            break;
        }
    }
    n=item/i;
    printf("%lld",n);
    return 0;
}

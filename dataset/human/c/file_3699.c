#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    long long int a,b,ans;
    scanf("%lld %lld",&a,&b);
    long long int a1=a,b1=b,gcd,lcm;
    while((a1%=b1)&&(b1%=a1));
    gcd = a1+b1;
    lcm = a*b/gcd;
  printf("%lld\n",lcm);
  return 0;
}

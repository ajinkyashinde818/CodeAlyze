#include<stdio.h>
long long gcd(long long x,long long y)
{
    return x?gcd(y%x,x):y;
}
int main()
{
	long long  x,y,a;
	scanf("%lld %lld",&x,&y);
	a=x/gcd(x,y)*y;
	printf("%lld",a);
	return 0;
}

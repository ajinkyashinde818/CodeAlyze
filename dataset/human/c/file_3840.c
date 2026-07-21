#include<stdio.h>

int gcd(long long int a,long long int b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}

int main()
{
	long long int a,b,k;
	scanf("%lld%lld",&a,&b);
	k=gcd(a,b);
	printf("%lld\n",(a*b)/k);
	return 0;
}

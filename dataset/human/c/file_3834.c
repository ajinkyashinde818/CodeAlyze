#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int main(void)
{
	long long int a;
	long long int b;
	scanf("%lld %lld",&a,&b);
	long long int g = gcd(a,b);
	long long int ans =  (a*b)/g;
	printf("%lld\n",ans);
	return 0;
}

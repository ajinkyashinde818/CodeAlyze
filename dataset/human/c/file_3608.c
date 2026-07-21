#include <stdio.h>
long long gcd(long long m,long long n) {
    if(m*n==0)
        return (m==0?n:m);
    if(m>n)
        return gcd(m%n,n);
    else if(m<n)
        return gcd(n%m,m);
}
int main()
{
	long long m,n;
	long long a,b;
	scanf("%lld%lld",&m,&n);
	b=m*n;
	a=b/(gcd(m,n));
	printf("%lld",a);
}

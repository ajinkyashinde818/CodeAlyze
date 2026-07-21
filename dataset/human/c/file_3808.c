#include <stdio.h>
#include <stdlib.h>

long long  divv(long long m,long long n)
{
	long long x;
	long long a, b;
	a = m;
	b = n;
	if (a > b)
	{
		x = a%b;
	}
	else
	{
		x = a;
		a = b;
		b = x;
		x = a%b;
	}
	while (x != 0)
	{
		a = b;
		b = x;
		x = a%b;
	}
	return b;
}

int main()
{
    long long a1,b1,d1;
    scanf("%lld %lld",&a1,&b1);
    d1=divv(a1,b1);
    printf("%lld",(a1/d1)*b1);
}

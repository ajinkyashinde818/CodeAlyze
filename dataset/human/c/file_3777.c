#include<stdio.h>

long gcd(long a,long b)
{
	long r =1;
	while(r !=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	
	return a;
}

int main(void)
{
	long a;
	long b;
	
	scanf("%ld%ld",&a,&b);
	printf("%ld",a*b/gcd(a,b));
	return 0;
}

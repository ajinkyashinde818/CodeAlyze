#include <stdio.h>
int Gcd(int a, int b)
{
	if(a<b)
	{
		int t = a;
		a = b;
		b = t; 
	}
	if(a%b==0) return b;
	return Gcd(b, a%b);
}
int main()
{
	long long int a, b;
	scanf("%lld%lld", &a, &b);
	long long int multi = a*b;
	printf("%lld\n", multi/Gcd(a, b));
	return 0;
}

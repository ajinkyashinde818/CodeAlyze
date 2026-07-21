#include <stdio.h> 
long long int gcd(long long int a, long long int b) 
{ 
	if (a == 0) 
	return b; 
	if (b == 0) 
	return a; 
	if (a == b) 
		return a; 
	if (a > b) 
		return gcd(a-b, b); 
	return gcd(a, b-a); 
} 
int main() 
{ 
	long long int a,b,c;
	scanf("%lld%lld",&a,&b);
	c=gcd(a, b);
	c=(a*b)/c;
	printf("%lld\n",c);
	return 0; 
}

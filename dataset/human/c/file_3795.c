#include<stdio.h>

long long int gcd(long long int a, long long int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);      
} 

int main()
{
	long long int a,b;
    scanf("%lld%lld",&a,&b);
  	long long int t=gcd(a,b);
  	long long int u=(a*b)/t;
  	printf("%lld\n",u);
  	return 0;
}

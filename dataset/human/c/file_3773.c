#include<stdio.h>
long long gcd(long long a,long long b)
{
	if(a==b)return a;
	else if(a==0)return b;
	else if(b==0)return a;
	else
		return gcd(b,a%b);
}
int main()
{
	long long a,b;
	scanf("%Ld %Ld",&a,&b);
	printf("%Ld\n",(a/gcd(a,b))*b);
	return 0;
}

#include<stdio.h>

int gcd(long long a,long long b)
{
	if (b==0) return a;
	else return gcd(b,a%b); 
}

int main()
{
	long long x,y,num;
	scanf("%lld%lld",&x,&y);
	num=gcd(x,y); 
	long long ans;
	ans=(x*y)/num;
	printf("%lld",ans);
	return 0;
}

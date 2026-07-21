#include<stdio.h>
int main()
{
	long long int gcd(long long int a,long long int b);
	long long int a,b,gc,p,ans;
	scanf("%lld %lld",&a,&b);
	p=a*b;
	if(a>b)
	{
		gc=gcd(a,b);
	}
	else
	gc=gcd(b,a);
	ans=p/gc;
	printf("%lld",ans);
}
long long int gcd(long long int a,long long int b)
{
	long long int t;
	t=a%b;
	if(t!=0)
	return gcd(b,t);
	else
	return b;
}

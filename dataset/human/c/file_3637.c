#include<stdio.h>
int main()
{
	int i;
	long long m,n,a,b,temp;
	scanf("%lld%lld",&m,&n);
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	a=m;
	b=n;
	while(m%n!=0)
	{
		temp=m;
		m=n;
		n=temp%n;
	}
	printf("%lld",(a*b)/n);
}

#include<stdio.h>
int main()
{
	long long a,b,i,j,max,k,l,r;
	scanf("%lld%lld",&a,&b);
	if(a<=b) max=a,a=b,b=max; k=a,l=b;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}

			printf("%lld",k*l/a);
	
 }

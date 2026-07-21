#include<stdio.h>
int main()
{
	long int a,b,c,d,sum1,sum2;
	scanf("%lld %lld %lld %lld ",&a,&b,&c,&d);
	sum1 = a*b;
	sum2= c*d;
	if(sum1>sum2)
		printf("%lld",sum1);
	else
		printf("%lld",sum2);
}

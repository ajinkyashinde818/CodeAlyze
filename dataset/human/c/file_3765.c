#include<stdio.h>
int main()
{
    long long a1,b1,t,a,b,c,d;
	scanf("%lld %lld",&a1,&b1);
	if(a1>b1)
	{
	    t=a1;
	    a1=b1;
	    b1=t;
	}
	a=a1;
	b=b1;
	d=a%b;
	a=b;
	b=d;
	while(d!=0)
	{
		d=a%b;
		a=b;
		b=d;
	} 
	printf("%lld\n",a1*b1/a);
    return 0;
}

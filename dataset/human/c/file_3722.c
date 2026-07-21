#include<stdio.h>
int main()
{
	long long a,b,c=0,d=0,e;
	scanf("%lld %lld",&a,&b);
	c=a*b;
	if(a<b){
		e=a;
		a=b;
		b=e;
	}
	d=a%b;
	while(d!=0){
		a=b;
		b=d;
		d=a%b;
	}
	printf("%lld\n",c/b);
	return 0;
}

#include<stdio.h>
int main()
{
	long long int a,b,t,m,n;
	long long int x; 
	scanf("%lld%lld",&a,&b);
	m=a;
	n=b;
	    if(a<b)
	{
		t=a;a=b;b=t;
	 } 
	 while(a%b)
	 {
	 	t=b;
	 	b=a%b;
	 	a=t;
	 }
	 x=m*n/b;
	 printf("%lld",x);  
	return 0;
}

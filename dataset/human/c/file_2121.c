#include<stdio.h>
		
int main(void)
{
	long long n;
	scanf("%lld",&n);
	long long a=10,b=0;
	
	if(n%2==1){
		printf("0");
		return 0;
		}
	else
	{
		while(a<=n){
			b+=n/a;
			a*=5;
		}
	}
	printf("%lld",b);
	return 0;
}

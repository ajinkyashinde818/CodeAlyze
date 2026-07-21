#include<stdio.h>

int main(void)
{
	long long int x,quo;
	int rem;
	scanf("%lld", &x);
	

	quo = x / 11; 
	rem = x % 11;

	if (rem>6) printf("%lld",(quo+1) * 2);
	else if (rem == 0)printf("%lld", quo  * 2);
	else printf("%lld",quo * 2 + 1);
	
	return 0;
}

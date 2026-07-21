#include <stdio.h>

int main(void)
{
	long long int x,ans=1,a,b;
	scanf("%lld",&x);

	a=x/11; b=x%11;
	
	if(b>6)	
		ans++;
	if(b==0)
		ans=0;
	if(a>0)
		ans+=a*2;

	printf("%lld\n",ans);
	return 0;
}

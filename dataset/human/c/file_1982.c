#include <stdio.h>

int main()
{
	int a,b,c;
	scanf ("%d %d %d",&a,&b,&c);

	long long ans = 0;
	if (b >= c) ans = b + c;
	else{
		ans += b * 2;
		c -= b;
		if (c > a) ans += a + 1;
		else ans += c;
	}
	printf ("%lld\n",ans);

	return 0;
}

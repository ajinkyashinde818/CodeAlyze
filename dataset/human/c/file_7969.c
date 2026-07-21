#include <stdio.h>

long long x, y;
long long a, b;
long long xx = 1, yy = 1, zz;

long long ff(long long h, long long g)
{
	long long rr = 1;
	
	while(g > 0)
	{
		if(g % 2 == 1)
		{
			rr *= h;
			rr %= 1000000007;
		}
		
		h *= h;
		h %= 1000000007;
		g /= 2;
	}
	
	return rr;
}

int main(void)
{
	scanf("%lld %lld", &a, &b);
	
	if((a + b) % 3 != 0)
	{
		printf("0");
		return 0;
	}
	
	y = (2 * a - b) / 3;
	x = (2 * b - a) / 3;
	
	if(x < 0 || y < 0)
	{
		printf("0");
		return 0;
	}
	
	for(int i = 1 ; i <= x + y ; i++)
	{
		xx = (xx * i) % 1000000007;
	}
	
	for(int i = 1 ; i <= x ; i++)
	{
		yy = (yy * i) % 1000000007;
	}
	
	for(int i = 1 ; i <= y ; i++)
	{
		yy = (yy * i) % 1000000007;
	}
	
	zz = ff(yy, 1000000005);
	
	printf("%lld", (zz * xx) % 1000000007);
	return 0;
}

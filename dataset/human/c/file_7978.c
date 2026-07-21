#include <stdio.h>
#define M 1000000007
typedef long long LL;

LL qpow(LL x, int y)
{
	if(!y) return 1;
	LL t = qpow(x, y >> 1);
	t = t * t % M;
	if(y & 1) t = t * x % M;
	return t;
}

int main()
{		
	int x, y, a, b, c, t, i, j;
	LL f1 = 1, f2 = 1;
		
	scanf("%d%d", &x, &y);
	c = x + y;
	if(c % 3){
		puts("0");
		return 0;
	}
	c /= 3;
	b = x - c, a = y - c;
	if(b < 0 || a < 0){
		puts("0");
		return 0;
	}
	if(a < b) t = a;
	else t = b;
	for(i = 1, j = c; i <= t; i++, j--){
		f1 = f1 * (LL)j % M;
		f2 = f2 * (LL)i % M;
	}
	printf("%lld\n", f1 * qpow(f2, M - 2) % M);
		
	return 0;
}

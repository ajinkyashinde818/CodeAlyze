#include <stdio.h>
#define N 100001
typedef long long LL;

int a[N];

int read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	int x = c - 48;
	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;
	return x;
}

LL gcd(LL x, LL y)
{
	LL t;
	while(y){
		t = x;
		x = y;
		y = t % y;
	}
	return x;
}

LL lcm(LL l, LL x)
{
	return l / gcd(l, x) * x;
}

int main()
{		
	int n, m, i, x, b, f = 1, y;
	LL l, ans;
	
	n = read(), m = read();
	x = read(), b = 1;
	while(x % 2 == 0) x >>= 1, b <<= 1;
	a[0] = x;
	for(i = 1; i < n; i++){
		x = read();
		if(!f) continue;
		if(x % b) f = 0;
		else if((y = x / b) % 2 == 0) f = 0;
		a[i] = y;
	}
	if(!f){
		puts("0");
		return 0;
	}
	m /= (b / 2), ans = m;
	for(i = 1, l = a[0]; i < n; i++){
		l = lcm(l, (LL)a[i]);
		if(l > m) break;
	}
	ans /= l;
	ans = (ans + 1) >> 1;
	printf("%lld\n", ans);
			
	return 0;
}

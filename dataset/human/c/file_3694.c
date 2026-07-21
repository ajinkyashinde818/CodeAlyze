#include<stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void) {

	unsigned long long int a, b, r, tmp;
	unsigned long long int gd;
	unsigned long long int  res;
	
	scanf("%lld %lld", &a, &b);

	/* 自然数 a > b を確認・入替 */
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	

	gd = gcd(a, b);

	res = a*b/gd;

	printf("%lld", res);

	return 0;
}
